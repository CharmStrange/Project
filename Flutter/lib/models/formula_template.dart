// lib/models/formula_template.dart
class FormulaTemplate {
  final String label;
  final String formula;
  final String description;

  FormulaTemplate({required this.label, required this.formula, required this.description});
}

final List<FormulaTemplate> rpgTemplates = [
  FormulaTemplate(
    label: "표준 감쇄식",
    formula: "(a_atk * a_atk) / (a_atk + d_def)",
    description: "방어력이 높을수록 데미지가 완만하게 감소합니다.",
  ),
  FormulaTemplate(
    label: "고전 차감식",
    formula: "a_atk - d_def",
    description: "공격력에서 방어력을 그대로 뺍니다. (최소 1)",
  ),
  FormulaTemplate(
    label: "비율 관통식",
    formula: "a_atk * (1 - (d_def / (d_def + 100)))",
    description: "방어력을 뎀감률(%)로 변환하여 계산합니다.",
  ),
];