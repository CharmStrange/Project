import 'dart:convert';
import 'package:flutter/services.dart';
import '../models/word.dart';

class DataService {
  static Future<List<Word>> loadWords(String level, int day) async {
    try {
      // 1. 전체 JSON 파일 로드
      final String response = await rootBundle.loadString('assets/data/korean_words.json');
      final Map<String, dynamic> fullData = json.decode(response);

      // 2. 레벨 확인 (beginner, intermediate 등)
      if (!fullData.containsKey(level)) return [];

      // 3. 해당 레벨 내의 특정 DAY 데이터 추출
      // JSON의 키를 문자열 "1", "2" 등으로 설정했으므로 day.toString() 사용
      final List<dynamic>? dayData = fullData[level][day.toString()];

      if (dayData == null) return [];

      // 4. Word 객체 리스트로 변환하여 반환
      return dayData.map((item) => Word.fromJson(item)).toList();
    } catch (e) {
      print("Error loading JSON: $e");
      return [];
    }
  }
}