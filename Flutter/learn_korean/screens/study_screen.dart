import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import '../models/word.dart';
import '../providers/theme_provider.dart';
import '../services/data_service.dart'; // 데이터 로드 서비스 가정

class StudyScreen extends StatefulWidget {
  final int day;
  final String level; // 레벨 정보를 받도록 추가

  const StudyScreen({
    super.key,
    required this.day,
    this.level = 'beginner', // 기본값 설정
  });

  @override
  State<StudyScreen> createState() => _StudyScreenState();
}

class _StudyScreenState extends State<StudyScreen> {
  late Future<List<Word>> _wordFuture;

  @override
  void initState() {
    super.initState();
    // 1. 페이지 진입 시점에 JSON 데이터 로드 프로세스 시작
    _wordFuture = DataService.loadWords(widget.level, widget.day);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('DAY ${widget.day}'),
        leading: IconButton(
          icon: const Icon(Icons.arrow_back_ios_new),
          onPressed: () => Navigator.pop(context),
        ),
      ),
      body: FutureBuilder<List<Word>>(
        future: _wordFuture,
        builder: (context, snapshot) {
          // 데이터 로딩 중일 때
          if (snapshot.connectionState == ConnectionState.waiting) {
            return const Center(
              child: CircularProgressIndicator(color: Color(0xFF0056B3)),
            );
          }
          // 에러가 발생했을 때
          else if (snapshot.hasError) {
            return Center(
              child: Text(
                '데이터를 불러오는 중 오류가 발생했습니다.\n${snapshot.error}',
                textAlign: TextAlign.center,
              ),
            );
          }
          // 데이터 로딩이 완료되었을 때
          else if (snapshot.hasData) {
            final words = snapshot.data!;

            return ListView.builder(
              padding: const EdgeInsets.all(16),
              itemCount: words.length,
              itemBuilder: (context, index) {
                // 각 단어 객체의 상태를 유지하며 카드 렌더링
                return WordCard(word: words[index]);
              },
            );
          }
          // 데이터가 비어있을 때
          else {
            return const Center(child: Text('해당 날짜의 데이터가 없습니다.'));
          }
        },
      ),
    );
  }
}

// 개별 단어 카드 객체
class WordCard extends StatefulWidget {
  final Word word;
  const WordCard({super.key, required this.word});

  @override
  State<WordCard> createState() => _WordCardState();
}

class _WordCardState extends State<WordCard> {
  bool _isFavorite = false; // 즐겨찾기 모양 확인용

  @override
  Widget build(BuildContext context) {
    final themeProvider = Provider.of<ThemeProvider>(context);
    final bool isDark = themeProvider.isDarkMode;

    final Color contentColor = isDark ? Colors.white : const Color(0xFF0056B3);
    final Color cardBgColor = isDark ? const Color(0xFF1E1E1E) : Colors.white;

    return Container(
      margin: const EdgeInsets.only(bottom: 20),
      padding: const EdgeInsets.all(16),
      decoration: BoxDecoration(
        color: cardBgColor,
        border: Border.all(color: contentColor, width: 2),
        borderRadius: BorderRadius.zero, // 각진 디자인 고수
      ),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          // 상단 배지 및 버튼들
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              Row(
                children: [
                  Container(
                    padding: const EdgeInsets.symmetric(horizontal: 6, vertical: 2),
                    color: contentColor,
                    child: Text(
                      widget.word.kanji,
                      style: TextStyle(
                        color: cardBgColor,
                        fontSize: 12,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                  ),
                  const SizedBox(width: 8),
                  Text(
                    widget.word.pronunciation,
                    style: TextStyle(
                      color: contentColor.withOpacity(0.7),
                      fontSize: 12,
                    ),
                  ),
                ],
              ),
              Row(
                children: [
                  GestureDetector(
                    onTap: () => setState(() => _isFavorite = !_isFavorite),
                    child: Icon(
                      _isFavorite ? Icons.bookmark : Icons.bookmark_border,
                      color: contentColor,
                      size: 20,
                    ),
                  ),
                  const SizedBox(width: 12),
                  GestureDetector(
                    onTap: () => setState(() {
                      widget.word.isExpanded = !widget.word.isExpanded;
                    }),
                    child: Icon(
                      widget.word.isExpanded
                          ? Icons.keyboard_arrow_up
                          : Icons.keyboard_arrow_down,
                      color: contentColor,
                      size: 24,
                    ),
                  ),
                ],
              ),
            ],
          ),
          const SizedBox(height: 8),

          // 단어 및 뜻
          Row(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              Text(
                widget.word.word,
                style: TextStyle(
                  color: contentColor,
                  fontSize: 26,
                  fontWeight: FontWeight.bold,
                ),
              ),
              Text(
                widget.word.meaning,
                style: TextStyle(
                  color: isDark ? Colors.white70 : Colors.black87,
                  fontSize: 18,
                  fontWeight: FontWeight.w500,
                ),
              ),
            ],
          ),

          // 예문 섹션 (펼치기 상태일 때만 출력)
          if (widget.word.isExpanded) ...[
            const SizedBox(height: 16),
            Container(height: 1, color: contentColor.withOpacity(0.2)),
            const SizedBox(height: 16),
            Row(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Text(
                  '例',
                  style: TextStyle(
                    color: contentColor,
                    fontWeight: FontWeight.bold,
                    fontSize: 14,
                  ),
                ),
                const SizedBox(width: 12),
                Expanded(
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Text(
                        widget.word.exampleKr,
                        style: TextStyle(
                          color: isDark ? Colors.white : Colors.black,
                          fontSize: 15,
                          height: 1.4,
                        ),
                      ),
                      const SizedBox(height: 4),
                      Text(
                        widget.word.exampleJp,
                        style: TextStyle(
                          color: isDark ? Colors.white54 : Colors.black54,
                          fontSize: 13,
                        ),
                      ),
                    ],
                  ),
                ),
              ],
            ),
          ],
        ],
      ),
    );
  }
}