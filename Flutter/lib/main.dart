import 'package:flutter/material.dart';
import 'package:fl_chart/fl_chart.dart';
import 'dart:math' as math;

void main() => runApp(const BalancingApp());

// --- [Models] ---
class GameEntity {
  String name;
  Map<String, double> stats;
  GameEntity({required this.name, required this.stats});
}

// --- [Main App] ---
class BalancingApp extends StatelessWidget {
  const BalancingApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        useMaterial3: true,
        primaryColor: const Color(0xFF1B5E20),
        scaffoldBackgroundColor: const Color(0xFFF1F3F1),
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
  // 전역 데이터 관리
  late GameEntity player;
  late GameEntity monster;

  @override
  void initState() {
    super.initState();
    player = GameEntity(name: "PLAYER", stats: {
      "hp": 1500, "atk": 150, "def": 50, "crit_rate": 20.0,
      "Hit": 100, "Evasion": 15, "Luck": 10
    });
    monster = GameEntity(name: "BOSS", stats: {
      "hp": 3000, "atk": 120, "def": 70, "crit_rate": 10.0,
      "Hit": 90, "Evasion": 5, "Luck": 5
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("BATTLE BALANCE STUDIO",
            style: TextStyle(fontWeight: FontWeight.w900, color: Colors.white, fontSize: 13)),
        backgroundColor: const Color(0xFF1B5E20),
        iconTheme: const IconThemeData(color: Colors.white),
      ),
      drawer: _buildCompactDrawer(),
      body: BattleSimulator(player: player, monster: monster),
    );
  }

  // --- [Drawer UI] ---
  Widget _buildCompactDrawer() {
    return Drawer(
      width: MediaQuery.of(context).size.width * 0.85,
      child: Column(
        children: [
          Container(
            height: 120, width: double.infinity, color: const Color(0xFF1B5E20),
            padding: const EdgeInsets.all(20), alignment: Alignment.bottomLeft,
            child: const Text("ADVANCED PARAMS", style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold)),
          ),
          Expanded(
            child: ListView(
              padding: const EdgeInsets.all(12),
              children: [
                _buildStatGrid(player, "Player Detailed", Colors.green),
                const SizedBox(height: 20),
                _buildStatGrid(monster, "Boss Detailed", Colors.red),
              ],
            ),
          ),
          Padding(
            padding: const EdgeInsets.all(16.0),
            child: ElevatedButton(
              onPressed: () => Navigator.pop(context),
              style: ElevatedButton.styleFrom(backgroundColor: const Color(0xFF1B5E20), minimumSize: const Size(double.infinity, 45)),
              child: const Text("APPLY & CLOSE", style: TextStyle(color: Colors.white)),
            ),
          )
        ],
      ),
    );
  }

  Widget _buildStatGrid(GameEntity entity, String title, Color color) {
    final keys = ["hp", "atk", "def", "crit_rate", "Hit", "Evasion", "Luck"];
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Text(title, style: TextStyle(fontSize: 11, fontWeight: FontWeight.bold, color: color)),
        const SizedBox(height: 8),
        GridView.builder(
          shrinkWrap: true, physics: const NeverScrollableScrollPhysics(),
          gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(crossAxisCount: 2, childAspectRatio: 3.5, crossAxisSpacing: 5, mainAxisSpacing: 5),
          itemCount: keys.length,
          itemBuilder: (context, i) {
            String k = keys[i];
            return Container(
              padding: const EdgeInsets.symmetric(horizontal: 8),
              decoration: BoxDecoration(color: Colors.grey[100], borderRadius: BorderRadius.circular(5)),
              child: Row(
                children: [
                  Text(k, style: const TextStyle(fontSize: 9)),
                  const Spacer(),
                  SizedBox(width: 40, child: TextFormField(
                    initialValue: entity.stats[k].toString(),
                    style: const TextStyle(fontSize: 10, fontWeight: FontWeight.bold),
                    onChanged: (v) => entity.stats[k] = double.tryParse(v) ?? 0,
                    decoration: const InputDecoration(isDense: true, border: InputBorder.none),
                  )),
                ],
              ),
            );
          },
        )
      ],
    );
  }
}

// --- [Battle Simulator Logic & UI] ---
class BattleSimulator extends StatefulWidget {
  final GameEntity player;
  final GameEntity monster;
  const BattleSimulator({super.key, required this.player, required this.monster});

  @override
  State<BattleSimulator> createState() => _BattleSimulatorState();
}

class _BattleSimulatorState extends State<BattleSimulator> with SingleTickerProviderStateMixin {
  late double pCurHp;
  late double mCurHp;
  bool isSimulating = false;
  String currentTurn = "READY";
  List<String> battleLogs = [];
  List<FlSpot> damageHistory = [];

  @override
  void initState() {
    super.initState();
    _resetBattle();
  }

  void _resetBattle() {
    setState(() {
      pCurHp = widget.player.stats['hp']!;
      mCurHp = widget.monster.stats['hp']!;
      battleLogs = ["전투 시뮬레이션 대기 중..."];
      damageHistory = [];
      currentTurn = "READY";
      isSimulating = false;
    });
  }

  Future<void> _startAutoBattle() async {
    if (isSimulating) return;
    _resetBattle();
    setState(() => isSimulating = true);

    while (pCurHp > 0 && mCurHp > 0 && isSimulating) {
      // Player Turn
      setState(() => currentTurn = "PLAYER");
      await Future.delayed(const Duration(milliseconds: 600));
      _attack(widget.player, widget.monster, true);
      if (mCurHp <= 0) break;

      // Monster Turn
      setState(() => currentTurn = "MONSTER");
      await Future.delayed(const Duration(milliseconds: 600));
      _attack(widget.monster, widget.player, false);

      await Future.delayed(const Duration(milliseconds: 400));
    }

    setState(() {
      isSimulating = false;
      currentTurn = "FINISHED";
      battleLogs.insert(0, pCurHp > 0 ? "★ PLAYER VICTORIOUS" : "☠ PLAYER DEFEATED");
    });
  }

  void _attack(GameEntity attacker, GameEntity defender, bool isPlayerAttacking) {
    double atk = attacker.stats['atk']!;
    double def = defender.stats['def']!;
    double crit = attacker.stats['crit_rate']!;

    bool isCrit = math.Random().nextDouble() * 100 <= crit;
    double dmg = (atk - def) * (isCrit ? 1.5 : 1.0);
    if (dmg < 1) dmg = 1;

    setState(() {
      if (isPlayerAttacking) {
        mCurHp = math.max(0, mCurHp - dmg);
        // 그래프 데이터 갱신 (직선화 방지: 최신 20개 유지)
        if (damageHistory.length >= 20) damageHistory.removeAt(0);
        List<FlSpot> updated = [];
        for (int i = 0; i < damageHistory.length; i++) {
          updated.add(FlSpot(i.toDouble(), damageHistory[i].y));
        }
        damageHistory = updated;
        damageHistory.add(FlSpot(damageHistory.length.toDouble(), dmg));

        battleLogs.insert(0, "[P -> M] ${dmg.toStringAsFixed(1)} ${isCrit ? 'CRITICAL!' : ''}");
      } else {
        pCurHp = math.max(0, pCurHp - dmg);
        battleLogs.insert(0, "[M -> P] ${dmg.toStringAsFixed(1)} ${isCrit ? 'CRITICAL!' : ''}");
      }
    });
  }

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        _buildBattleField(),
        _buildGraphView(),
        Padding(
          padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 10),
          child: Row(
            children: [
              Expanded(
                child: ElevatedButton(
                  onPressed: isSimulating ? () => setState(() => isSimulating = false) : _startAutoBattle,
                  style: ElevatedButton.styleFrom(
                      backgroundColor: isSimulating ? Colors.orange : const Color(0xFF1B5E20),
                      minimumSize: const Size(0, 50), shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(12))
                  ),
                  child: Text(isSimulating ? "STOP" : "START AUTO BATTLE", style: const TextStyle(color: Colors.white, fontWeight: FontWeight.bold)),
                ),
              ),
              const SizedBox(width: 10),
              IconButton(onPressed: _resetBattle, icon: const Icon(Icons.refresh), style: IconButton.styleFrom(backgroundColor: Colors.white)),
            ],
          ),
        ),
        Expanded(child: _buildLogArea()),
      ],
    );
  }

  Widget _buildBattleField() {
    return Container(
      padding: const EdgeInsets.all(20), color: Colors.white,
      child: Row(
        mainAxisAlignment: MainAxisAlignment.spaceAround,
        children: [
          _buildUnitUI("PLAYER", pCurHp, widget.player.stats['hp']!, Colors.green, currentTurn == "PLAYER"),
          const Text("VS", style: TextStyle(fontWeight: FontWeight.w900, color: Colors.grey)),
          _buildUnitUI("BOSS", mCurHp, widget.monster.stats['hp']!, Colors.red, currentTurn == "MONSTER"),
        ],
      ),
    );
  }

  Widget _buildUnitUI(String name, double cur, double max, Color color, bool isActive) {
    double ratio = (cur / max).clamp(0, 1.0);
    return AnimatedContainer(
      duration: const Duration(milliseconds: 300),
      padding: const EdgeInsets.all(15),
      decoration: BoxDecoration(
        color: isActive ? color.withOpacity(0.05) : Colors.transparent,
        borderRadius: BorderRadius.circular(15),
        border: Border.all(color: isActive ? color : Colors.grey[200]!, width: 2),
      ),
      child: Column(
        children: [
          Text(name, style: TextStyle(fontWeight: FontWeight.bold, color: color, fontSize: 12)),
          const SizedBox(height: 10),
          Stack(
            children: [
              Container(width: 100, height: 10, decoration: BoxDecoration(color: Colors.grey[200], borderRadius: BorderRadius.circular(5))),
              AnimatedContainer(
                duration: const Duration(milliseconds: 400),
                width: 100 * ratio, height: 10,
                decoration: BoxDecoration(color: color, borderRadius: BorderRadius.circular(5)),
              ),
            ],
          ),
          const SizedBox(height: 5),
          Text("${cur.toStringAsFixed(0)} / ${max.toStringAsFixed(0)}", style: const TextStyle(fontSize: 10, fontWeight: FontWeight.bold)),
        ],
      ),
    );
  }

  Widget _buildGraphView() {
    return Container(
      height: 120, width: double.infinity, padding: const EdgeInsets.all(15), color: Colors.white,
      child: LineChart(LineChartData(
        gridData: const FlGridData(show: false), titlesData: const FlTitlesData(show: false),
        borderData: FlBorderData(show: false),
        lineBarsData: [
          LineChartBarData(
            spots: damageHistory.isEmpty ? [const FlSpot(0, 0)] : damageHistory,
            isCurved: true, color: const Color(0xFF1B5E20), barWidth: 2, dotData: const FlDotData(show: false),
            belowBarData: BarAreaData(show: true, color: const Color(0xFF1B5E20).withOpacity(0.1)),
          )
        ],
      )),
    );
  }

  Widget _buildLogArea() {
    return Container(
      width: double.infinity, color: const Color(0xFF1A1A1A),
      child: ListView.builder(
        padding: const EdgeInsets.all(15),
        itemCount: battleLogs.length,
        itemBuilder: (context, i) => Text(
            battleLogs[i],
            style: TextStyle(
                color: battleLogs[i].contains("P ->") ? Colors.greenAccent : (battleLogs[i].contains("M ->") ? Colors.redAccent : Colors.white60),
                fontSize: 11, fontFamily: 'monospace'
            )
        ),
      ),
    );
  }
}
