import 'package:flutter/material.dart';
import 'package:math_expressions/math_expressions.dart';
import 'package:fl_chart/fl_chart.dart';

void main() => runApp(const BalancingApp());

// --- [Models] ---
class GameEntity {
  String name;
  Map<String, double> stats;
  GameEntity({required this.name, required this.stats});
}

class FormulaTemplate {
  final String label;
  final String formula;
  FormulaTemplate({required this.label, required this.formula});
}

// --- [Main App Structure] ---
class BalancingApp extends StatelessWidget {
  const BalancingApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        useMaterial3: true,
        primaryColor: const Color(0xFF1B5E20),
        scaffoldBackgroundColor: const Color(0xFFF8FAF8),
      ),
      home: const MainNavigationScreen(),
    );
  }
}

class MainNavigationScreen extends StatefulWidget {
  const MainNavigationScreen({super.key});

  @override
  State<MainNavigationScreen> createState() => _MainNavigationScreenState();
}

class _MainNavigationScreenState extends State<MainNavigationScreen> {
  int _selectedIndex = 0;

  final List<Map<String, dynamic>> _menuItems = [
    {'title': 'Simulator', 'icon': Icons.analytics_outlined},
    {'title': 'Data Management', 'icon': Icons.storage_rounded},
    {'title': 'Global Settings', 'icon': Icons.settings_suggest_outlined},
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(_menuItems[_selectedIndex]['title'].toString().toUpperCase(),
            style: const TextStyle(fontWeight: FontWeight.w900, color: Colors.white, fontSize: 14, letterSpacing: 1.2)),
        backgroundColor: const Color(0xFF1B5E20),
        iconTheme: const IconThemeData(color: Colors.white),
        elevation: 0,
      ),
      drawer: _buildSideDrawer(),
      body: _selectedIndex == 0
          ? const SimulatorPage()
          : Center(child: Text("${_menuItems[_selectedIndex]['title']} Page Coming Soon")),
    );
  }

  Widget _buildSideDrawer() {
    return Drawer(
      backgroundColor: Colors.white,
      shape: const RoundedRectangleBorder(borderRadius: BorderRadius.zero),
      child: Column(
        children: [
          Container(
            padding: const EdgeInsets.only(top: 60, bottom: 30, left: 24),
            width: double.infinity,
            color: const Color(0xFF1B5E20),
            child: const Text("STUDIO v1.3", style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold, fontSize: 20)),
          ),
          Expanded(
            child: ListView.builder(
              itemCount: _menuItems.length,
              itemBuilder: (context, index) {
                bool isSelected = _selectedIndex == index;
                return ListTile(
                  leading: Icon(_menuItems[index]['icon'] as IconData, color: isSelected ? const Color(0xFF1B5E20) : Colors.grey),
                  title: Text(_menuItems[index]['title'].toString(), style: TextStyle(color: isSelected ? const Color(0xFF1B5E20) : Colors.black87)),
                  selected: isSelected,
                  onTap: () {
                    setState(() => _selectedIndex = index);
                    Navigator.pop(context);
                  },
                );
              },
            ),
          ),
        ],
      ),
    );
  }
}

// --- [Page: Simulator] ---
class SimulatorPage extends StatefulWidget {
  const SimulatorPage({super.key});

  @override
  State<SimulatorPage> createState() => _SimulatorPageState();
}

class _SimulatorPageState extends State<SimulatorPage> with SingleTickerProviderStateMixin {
  late TextEditingController _formulaController;
  late AnimationController _animController;

  final player = GameEntity(name: "PLAYER", stats: {
    "atk": 120, "def": 45, "hp": 1200, "int": 30, "agi": 25, "crit_rate": 15.0
  });
  final monster = GameEntity(name: "BOSS", stats: {
    "atk": 80, "def": 60, "hp": 5000, "int": 10, "agi": 10, "crit_rate": 5.0
  });

  final List<FormulaTemplate> templates = [
    FormulaTemplate(label: "기본식", formula: "a_atk - d_def"),
    FormulaTemplate(label: "가중식", formula: "(a_atk * 1.5) + (a_int * 0.8) - d_def"),
    FormulaTemplate(label: "치명타식", formula: "a_atk * (1 + a_crit_rate/100) - d_def"),
  ];

  double _lastResult = 0;
  List<FlSpot> _damageHistory = [];
  final List<String> _battleLogs = [];

  @override
  void initState() {
    super.initState();
    _formulaController = TextEditingController(text: templates[1].formula);
    _animController = AnimationController(vsync: this, duration: const Duration(milliseconds: 400));
  }

  @override
  void dispose() {
    _formulaController.dispose();
    _animController.dispose();
    super.dispose();
  }

  void _clearGraph() {
    setState(() {
      _damageHistory = [];
      _battleLogs.insert(0, "[SYS] Graph data cleared.");
    });
  }

  void _runSimulation() {
    try {
      Parser p = Parser();
      Expression exp = p.parse(_formulaController.text);
      ContextModel cm = ContextModel();
      player.stats.forEach((k, v) => cm.bindVariable(Variable('a_$k'), Number(v)));
      monster.stats.forEach((k, v) => cm.bindVariable(Variable('d_$k'), Number(v)));

      double result = exp.evaluate(EvaluationType.REAL, cm);
      setState(() {
        _lastResult = result < 0 ? 0 : result;
        if (_damageHistory.length > 20) _damageHistory.removeAt(0);
        _damageHistory.add(FlSpot(_damageHistory.length.toDouble(), _lastResult));
        _battleLogs.insert(0, "[SIM] ${_lastResult.toStringAsFixed(1)} Dmg dealt.");
        _animController.forward(from: 0);
      });
    } catch (e) {
      setState(() => _lastResult = -1.0);
    }
  }

  @override
  Widget build(BuildContext context) {
    return SingleChildScrollView(
      padding: const EdgeInsets.all(20),
      child: Column(
        children: [
          _buildVisualSection(),
          const SizedBox(height: 20),
          _buildFormulaCard(),
          const SizedBox(height: 20),
          Row(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Expanded(child: _buildStatCard(player, const Color(0xFF1B5E20))),
              const SizedBox(width: 12),
              Expanded(child: _buildStatCard(monster, const Color(0xFFC62828))),
            ],
          ),
          const SizedBox(height: 24),
          _buildActionButton(),
          const SizedBox(height: 20),
          _buildLogArea(),
        ],
      ),
    );
  }

  Widget _buildVisualSection() {
    return Container(
      height: 200,
      padding: const EdgeInsets.all(16),
      decoration: BoxDecoration(
          color: Colors.white,
          borderRadius: BorderRadius.circular(20),
          boxShadow: [BoxShadow(color: Colors.black.withOpacity(0.02), blurRadius: 10)]
      ),
      child: Stack(
        children: [
          Row(
            children: [
              Expanded(
                flex: 1,
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    const Text("LIVE DAMAGE", style: TextStyle(fontSize: 10, fontWeight: FontWeight.bold, color: Colors.grey)),
                    ScaleTransition(
                      scale: CurvedAnimation(parent: _animController, curve: Curves.easeOutBack),
                      child: Text(
                          _lastResult < 0 ? "ERR" : _lastResult.toStringAsFixed(0),
                          style: const TextStyle(fontSize: 34, fontWeight: FontWeight.w900, color: Color(0xFF1B5E20))
                      ),
                    ),
                  ],
                ),
              ),
              Expanded(
                flex: 2,
                child: Padding(
                  padding: const EdgeInsets.only(top: 20, right: 10),
                  child: LineChart(LineChartData(
                    gridData: const FlGridData(show: false),
                    titlesData: const FlTitlesData(show: false),
                    borderData: FlBorderData(show: false),
                    lineBarsData: [
                      LineChartBarData(
                          spots: _damageHistory.isEmpty ? [const FlSpot(0, 0)] : _damageHistory,
                          isCurved: true,
                          color: const Color(0xFF1B5E20),
                          barWidth: 3,
                          dotData: const FlDotData(show: false),
                          belowBarData: BarAreaData(show: true, color: const Color(0xFF1B5E20).withOpacity(0.1))
                      )
                    ],
                  )),
                ),
              ),
            ],
          ),
          Positioned(
            right: 0, top: 0,
            child: IconButton(
              icon: const Icon(Icons.refresh, size: 20, color: Colors.grey),
              onPressed: _clearGraph,
              tooltip: "Clear Graph",
            ),
          )
        ],
      ),
    );
  }

  Widget _buildFormulaCard() {
    return Container(
      padding: const EdgeInsets.all(16),
      decoration: BoxDecoration(color: Colors.white, borderRadius: BorderRadius.circular(16)),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          const Text("BATTLE FORMULA", style: TextStyle(fontSize: 10, fontWeight: FontWeight.bold, color: Colors.grey)),
          const SizedBox(height: 12),
          SingleChildScrollView(
            scrollDirection: Axis.horizontal,
            child: Row(
              children: templates.map((t) => Padding(
                padding: const EdgeInsets.only(right: 8),
                child: ChoiceChip(
                  label: Text(t.label, style: TextStyle(fontSize: 11, color: _formulaController.text == t.formula ? Colors.white : Colors.black87)),
                  selected: _formulaController.text == t.formula,
                  onSelected: (val) => setState(() => _formulaController.text = t.formula),
                  selectedColor: const Color(0xFF1B5E20),
                  backgroundColor: Colors.grey[100],
                  side: BorderSide.none,
                  showCheckmark: false,
                  shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(8)),
                ),
              )).toList(),
            ),
          ),
          const SizedBox(height: 12),
          TextField(
            controller: _formulaController,
            style: const TextStyle(fontFamily: 'monospace', fontSize: 13, color: Color(0xFF1B5E20), fontWeight: FontWeight.bold),
            decoration: InputDecoration(
                filled: true,
                fillColor: const Color(0xFFF1F5F1),
                border: OutlineInputBorder(borderRadius: BorderRadius.circular(12), borderSide: BorderSide.none),
                contentPadding: const EdgeInsets.symmetric(horizontal: 12, vertical: 10)
            ),
          ),
        ],
      ),
    );
  }

  Widget _buildStatCard(GameEntity entity, Color color) {
    return Container(
      padding: const EdgeInsets.all(16),
      decoration: BoxDecoration(color: Colors.white, borderRadius: BorderRadius.circular(16)),
      child: Column(
        children: [
          Text(entity.name, style: TextStyle(fontWeight: FontWeight.bold, color: color)),
          const Divider(),
          ...entity.stats.keys.map((key) => Padding(
            padding: const EdgeInsets.symmetric(vertical: 4),
            child: Row(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              children: [
                Text(key.toUpperCase(), style: const TextStyle(fontSize: 9, color: Colors.grey)),
                SizedBox(
                  width: 48,
                  child: TextFormField(
                    initialValue: entity.stats[key].toString(),
                    style: const TextStyle(fontSize: 12, fontWeight: FontWeight.bold),
                    onChanged: (v) => entity.stats[key] = double.tryParse(v) ?? 0,
                    decoration: InputDecoration(
                        isDense: true,
                        suffixText: key.contains("rate") ? "%" : null,
                        suffixStyle: const TextStyle(fontSize: 10),
                        contentPadding: const EdgeInsets.symmetric(vertical: 8)
                    ),
                  ),
                ),
              ],
            ),
          )),
        ],
      ),
    );
  }

  Widget _buildActionButton() {
    return ElevatedButton(
      onPressed: _runSimulation,
      style: ElevatedButton.styleFrom(
        backgroundColor: const Color(0xFF1B5E20),
        minimumSize: const Size(double.infinity, 56),
        shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(16)),
      ),
      child: const Text("RUN SIMULATION", style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold)),
    );
  }

  Widget _buildLogArea() {
    return Container(
      height: 120,
      width: double.infinity,
      padding: const EdgeInsets.all(12),
      decoration: BoxDecoration(color: Colors.white, borderRadius: BorderRadius.circular(12)),
      child: ListView.builder(
        itemCount: _battleLogs.length,
        itemBuilder: (context, index) => Text(_battleLogs[index], style: const TextStyle(fontSize: 11, fontFamily: 'monospace')),
      ),
    );
  }
}