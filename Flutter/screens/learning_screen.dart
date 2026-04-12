import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import '../providers/theme_provider.dart';
import 'study_screen.dart';

class LearningScreen extends StatefulWidget {
  // HomeScreen에서 넘겨주는 인자들을 받을 수 있도록 수정
  final String levelDisplay;
  final String levelKey;

  const LearningScreen({
    super.key,
    required this.levelDisplay,
    required this.levelKey,
  });

  @override
  State<LearningScreen> createState() => _LearningScreenState();
}

class _LearningScreenState extends State<LearningScreen> {
  // 초기 카드 개수 10개
  final List<int> _days = List.generate(10, (index) => index + 1);

  void _addDay() {
    setState(() {
      _days.add(_days.isEmpty ? 1 : _days.last + 1);
    });
  }

  void _removeDay() {
    if (_days.isNotEmpty) {
      setState(() {
        _days.removeLast();
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    final themeProvider = Provider.of<ThemeProvider>(context);
    final bool isDark = themeProvider.isDarkMode;
    final Color contentColor = isDark ? Colors.white : const Color(0xFF0056B3);

    return Scaffold(
      appBar: AppBar(
        // 전달받은 레벨 이름을 제목으로 사용
        title: Text('${widget.levelDisplay} 学習'),
        leading: IconButton(
          icon: const Icon(Icons.arrow_back_ios_new),
          onPressed: () => Navigator.pop(context),
        ),
        actions: [
          IconButton(icon: const Icon(Icons.remove), onPressed: _removeDay),
          IconButton(icon: const Icon(Icons.add), onPressed: _addDay),
        ],
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: GridView.builder(
          gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
            crossAxisCount: 3,
            crossAxisSpacing: 12,
            mainAxisSpacing: 12,
            childAspectRatio: 1.0,
          ),
          itemCount: _days.length,
          itemBuilder: (context, index) {
            return DayCard(
              dayNumber: _days[index],
              onTap: () {
                // StudyScreen으로 이동할 때 레벨 키와 DAY 번호를 함께 전달
                Navigator.push(
                  context,
                  MaterialPageRoute(
                    builder: (context) => StudyScreen(
                      day: _days[index],
                      level: widget.levelKey, // "beginner" 등의 키 전달
                    ),
                  ),
                );
              },
            );
          },
        ),
      ),
    );
  }
}

// DayCard 객체 (각진 디자인 유지)
class DayCard extends StatelessWidget {
  final int dayNumber;
  final VoidCallback onTap;

  const DayCard({
    super.key,
    required this.dayNumber,
    required this.onTap,
  });

  @override
  Widget build(BuildContext context) {
    final themeProvider = Provider.of<ThemeProvider>(context);
    final bool isDark = themeProvider.isDarkMode;

    final Color contentColor = isDark ? Colors.white : const Color(0xFF0056B3);
    final Color cardBgColor = isDark ? const Color(0xFF1E1E1E) : Colors.white;

    return GestureDetector(
      onTap: onTap,
      child: Container(
        decoration: BoxDecoration(
          color: cardBgColor,
          border: Border.all(color: contentColor, width: 2),
          borderRadius: BorderRadius.zero,
        ),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text(
              'DAY',
              style: TextStyle(
                color: contentColor,
                fontSize: 14,
              ),
            ),
            Text(
              '$dayNumber',
              style: TextStyle(
                color: contentColor,
                fontSize: 28,
                fontWeight: FontWeight.bold, // FontWeight.black 대신 사용
              ),
            ),
          ],
        ),
      ),
    );
  }
}