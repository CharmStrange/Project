<div align="center">

![image](https://github.com/CharmStrange/Project/assets/105769152/d9bc6ae2-c15f-4973-b791-36fbc13618ab)

</div>

---

I announce this, not every file has same rows' length and size. Reason is, some of recorded players have no texts on website, but data. Source Code will delete them automatically.

```
CREATE TABLE IF NOT EXISTS player_data
                 (Rank TEXT, Name TEXT, Tribe TEXT, Points TEXT, Villages TEXT,
                 Avg_Points_Per_Village TEXT, Tribe_Changes TEXT, Conquers TEXT,
                 Join_Date TEXT, Best_Rank TEXT, Most_Points TEXT, Most_Villages TEXT,
                 OD_Rank TEXT, OD_Attack_Rank TEXT, OD_Defense_Rank TEXT,
                 Profile TEXT, Player_Other_Worlds TEXT, Player_Past_Worlds TEXT,
                 Profile_Views TEXT)
```

```
def insert_data(player_data):
    conn = sqlite3.connect('player_data.db')
    c = conn.cursor()

    try:
        c.execute('''INSERT INTO player_data VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)''',
                  (player_data.get('Rank:', ''), player_data.get('Name:', ''), player_data.get('Tribe:', ''),
                   player_data.get('Points:', ''), player_data.get('Villages:', ''),
                   player_data.get('Average points per village:', ''), player_data.get('Tribe Changes:', ''),
                   player_data.get('Conquers:', ''), player_data.get('Join date:', ''),
                   player_data.get('Best Rank:', ''), player_data.get('Most Points:', ''),
                   player_data.get('Most Villages:', ''), player_data.get('OD Rank:', ''),
                   player_data.get('OD Attack Rank:', ''), player_data.get('OD Defense Rank:', ''),
                   player_data.get('Profile:', ''), player_data.get("Player's other worlds:", ''),
                   player_data.get("Player's past worlds:", ''), player_data.get('Profile views:', '')))
    except KeyError as e:
        pass
    else:
        conn.commit()
    finally:
        conn.close()
```
