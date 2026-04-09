// lib/models/game_entity.dart
class GameEntity {
  String name;
  // 유연한 확장을 위해 변수 이름을 키값으로 관리합니다.
  Map<String, double> stats;

  GameEntity({
    required this.name,
    required this.stats,
  });

  // 깊은 복사를 위한 메서드
  GameEntity copy() => GameEntity(
    name: name,
    stats: Map<String, double>.from(stats),
  );
}