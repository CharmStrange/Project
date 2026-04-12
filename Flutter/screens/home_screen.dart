import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import '../providers/theme_provider.dart';
import 'learning_screen.dart';

class HomeScreen extends StatelessWidget {
  const HomeScreen({super.key});

  @override
  Widget build(BuildContext context) {
    // 레벨 표시 이름과 JSON에서 사용할 Key 값을 매핑합니다.
    final List<Map<String, String>> levelData = [
      {'title': '初級', 'key': 'beginner'},
      {'title': '中級', 'key': 'intermediate'},
      {'title': '上級', 'key': 'advanced'},
      {'title': '高級', 'key': 'expert'},
    ];

    final themeProvider = Provider.of<ThemeProvider>(context);
    final bool isDark = themeProvider.isDarkMode;

    // 테마에 따른 공통 색상 설정
    final Color contentColor = isDark ? Colors.white : const Color(0xFF0056B3);
    final Color appBarColor = isDark ? const Color(0xFF1E1E1E) : Colors.white;

    return Scaffold(
      appBar: AppBar(
        backgroundColor: appBarColor,
        title: Text(
          'LEVEL SELECT',
          style: TextStyle(
            color: contentColor,
            fontWeight: FontWeight.bold,
            letterSpacing: 1.5,
          ),
        ),
        centerTitle: true,
        actions: [
          IconButton(
            icon: Icon(
              isDark ? Icons.light_mode : Icons.dark_mode,
              color: contentColor,
            ),
            onPressed: () => themeProvider.toggleTheme(),
          ),
        ],
      ),
      body: Padding(
        padding: const EdgeInsets.all(20.0),
        child: GridView.builder(
          // 각진 사각형 배치를 위한 설정
          gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
            crossAxisCount: 2,       // 2열 배치
            crossAxisSpacing: 20,    // 가로 간격
            mainAxisSpacing: 20,     // 세로 간격
            childAspectRatio: 1.1,   // 카드 비율
          ),
          itemCount: levelData.length,
          itemBuilder: (context, index) {
            final String title = levelData[index]['title']!;
            final String levelKey = levelData[index]['key']!;

            return GestureDetector(
              onTap: () {
                // 선택한 레벨의 정보를 가지고 학습 화면(LearningScreen)으로 이동
                Navigator.push(
                  context,
                  MaterialPageRoute(
                    builder: (context) => LearningScreen(
                      levelDisplay: title,
                      levelKey: levelKey,
                    ),
                  ),
                );
              },
              child: Container(
                decoration: BoxDecoration(
                  color: isDark ? const Color(0xFF1E1E1E) : Colors.white,
                  border: Border.all(color: contentColor, width: 2.5),
                  borderRadius: BorderRadius.zero, // 각진 디자인 유지
                  boxShadow: isDark
                      ? []
                      : [
                    BoxShadow(
                      color: contentColor.withOpacity(0.1),
                      offset: const Offset(4, 4),
                      blurRadius: 0, // 깔끔한 각진 그림자 효과
                    )
                  ],
                ),
                child: Center(
                  child: Column(
                    mainAxisAlignment: MainAxisAlignment.center,
                    children: [
                      Text(
                        title,
                        // 수정 후
                        style: TextStyle(
                          color: contentColor,
                          fontSize: 22,
                          fontWeight: FontWeight.w900, // 가장 두꺼운 두께
                        ),
                      ),
                      const SizedBox(height: 8),
                      Container(
                        width: 40,
                        height: 2,
                        color: contentColor.withOpacity(0.5),
                      ),
                    ],
                  ),
                ),
              ),
            );
          },
        ),
      ),
    );
  }
}