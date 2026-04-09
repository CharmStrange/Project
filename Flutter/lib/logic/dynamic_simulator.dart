// lib/logic/dynamic_simulator.dart
import 'package:math_expressions/math_expressions.dart';
import '../models/game_entity.dart';

class DynamicSimulator {
  static double calculateCustomDamage(String formula, GameEntity attacker, GameEntity defender) {
    try {
      Parser p = Parser();
      Expression exp = p.parse(formula);
      ContextModel cm = ContextModel();

      // 공격자 스탯 바인딩 (변수명 앞에 'a_'를 붙임)
      attacker.stats.forEach((key, value) => cm.bindVariable(Variable('a_$key'), Number(value)));
      // 방어자 스탯 바인딩 (변수명 앞에 'd_'를 붙임)
      defender.stats.forEach((key, value) => cm.bindVariable(Variable('d_$key'), Number(value)));

      return exp.evaluate(EvaluationType.REAL, cm);
    } catch (e) {
      return 0.0; // 수식 오류 시 0 반환
    }
  }
}