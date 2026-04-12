import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'providers/theme_provider.dart';
import 'screens/home_screen.dart';

void main() {
  runApp(
    ChangeNotifierProvider(
      create: (_) => ThemeProvider(),
      child: const KoreanLearningApp(),
    ),
  );
}

class KoreanLearningApp extends StatelessWidget {
  const KoreanLearningApp({super.key});

  @override
  Widget build(BuildContext context) {
    final themeProvider = Provider.of<ThemeProvider>(context);

    return MaterialApp(
      title: 'Learning Korean',
      debugShowCheckedModeBanner: false,
      themeMode: themeProvider.themeMode, // 현재 상태에 따른 테마 적용

      // main.dart의 theme 및 darkTheme 부분 수정
      theme: ThemeData(
        brightness: Brightness.light,
        scaffoldBackgroundColor: Colors.white,
        cardColor: Colors.white, // 라이트 모드 카드 배경
        primaryColor: const Color(0xFF0056B3),
        appBarTheme: const AppBarTheme(
          backgroundColor: Colors.white,
          foregroundColor: Color(0xFF0056B3),
          elevation: 0,
        ),
        textTheme: const TextTheme(
          bodyLarge: TextStyle(color: Color(0xFF0056B3)), // 라이트 모드 기본 글자색
        ),
      ),

      darkTheme: ThemeData(
        brightness: Brightness.dark,
        scaffoldBackgroundColor: const Color(0xFF121212),
        cardColor: const Color(0xFF1E1E1E), // 다크 모드 카드 배경 (약간 밝은 검은색)
        primaryColor: Colors.white,
        appBarTheme: const AppBarTheme(
          backgroundColor: Color(0xFF1E1E1E),
          foregroundColor: Colors.white,
          elevation: 0,
        ),
        textTheme: const TextTheme(
          bodyLarge: TextStyle(color: Colors.white), // 다크 모드 기본 글자색
        ),
      ),
      home: const HomeScreen(),
    );
  }
}