class Word {
  final String kanji;       // 한자 (일본어 학습자용)
  final String word;        // 한국어 단어
  final String pronunciation; // 가타카나 발음
  final String meaning;     // 일본어 뜻
  final String exampleKr;   // 한국어 예문
  final String exampleJp;   // 일본어 예문 해석

  bool isExpanded; // 접힘 상태 저장용 필드 추가

  Word({
    required this.kanji,
    required this.word,
    required this.pronunciation,
    required this.meaning,
    required this.exampleKr,
    required this.exampleJp,

    this.isExpanded = false, // 기본값은 펼침 상태
  });
  // JSON 데이터를 객체로 변환하는 factory 생성자
  factory Word.fromJson(Map<String, dynamic> json) {
    return Word(
      kanji: json['kanji'],
      word: json['word'],
      pronunciation: json['pronunciation'],
      meaning: json['meaning'],
      exampleKr: json['exampleKr'],
      exampleJp: json['exampleJp'],
    );
  }
}