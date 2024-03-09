import requests
from bs4 import BeautifulSoup
import re

URL = "https://www.twstats.com/"
response = requests.get(URL)

if response.status_code == 200:
    soup = BeautifulSoup(response.text, 'html.parser')
    td_elements = soup.find_all('td') 
    
    World_URLs = [] 
    
    for td in td_elements:
        a_element = td.find('a')  
        if a_element:
            href = a_element.get('href')
            if href.startswith('/e'):
                World_URLs.append(href)
            #print("Text:", a_element.text)
            #print("Href:", href)
            #print()
    
else:
    print(response.status_code)

World_URLs = World_URLs[1:12] # filtered inactive worlds

active_worlds = []
for world in World_URLs:
    active_worlds.append(world)

active_worlds = [active_worlds[i].replace('index.php', '') for i in range(11)]

list_for_player = []

for url in active_worlds:
    active_players = []
    copied_url = url
    response = requests.get("https://www.twstats.com/" + copied_url)
    
    if response.status_code == 200:
        soup = BeautifulSoup(response.text, 'html.parser')
        td_elements = soup.find_all('td') 
    
        for td in td_elements:
            a_element = td.find('a')
            if a_element:
                href = a_element.get('href')
                if href.startswith('index.php?page=player&'):
                    #print("Text:", a_element.text)
                    #print("Href:", href)
                    active_players.append(href)
                    #print()
    
    else:
        print(response.status_code)
        
    list_for_player.append(active_players)

for list in list_for_numpy:
    for string in list:
        string = string.replace('index.php', '')

ultimate_player_infos = []
for world in World_URLs:
    for urls in list_for_numpy:
        for player_url in urls:
            #response = requests.get("https://www.twstats.com/" + world + player_url)
            #print("https://www.twstats.com" + world + player_url.replace('index.php', ''))
            ultimate_player_infos.append("https://www.twstats.com" + world + player_url.replace('index.php', ''))

columns = []
data = []

for gogogogo in ultimate_player_infos_c:
    tmp_1 = []
    tmp_2 = []
    response = requests.get(gogogogo)

    if response.status_code == 200:
        soup = BeautifulSoup(response.text, 'html.parser')
    
        th_left_tags = soup.find_all('th', class_='left')
        td_tags = soup.find_all('td')
    
        for tag in th_left_tags:
            tmp_1.append(tag.text)
        columns.append(tmp_1)
    
        for tag in td_tags:
            tmp_2.append(tag.text)
        data.append(tmp_2)
    else:
        print("Error:", response.status_code)

results = []
for index in range(len(columns)):
    Player_Data = dict(zip(columns[index], data[index][15:]))
    results.append(Player_Data)

len(results)

import sqlite3

def create_table():
    conn = sqlite3.connect('player_data.db')
    c = conn.cursor()

    c.execute('''CREATE TABLE IF NOT EXISTS player_data
                 (Rank TEXT, Name TEXT, Tribe TEXT, Points TEXT, Villages TEXT,
                 Avg_Points_Per_Village TEXT, Tribe_Changes TEXT, Conquers TEXT,
                 Join_Date TEXT, Best_Rank TEXT, Most_Points TEXT, Most_Villages TEXT,
                 OD_Rank TEXT, OD_Attack_Rank TEXT, OD_Defense_Rank TEXT,
                 Profile TEXT, Player_Other_Worlds TEXT, Player_Past_Worlds TEXT,
                 Profile_Views TEXT)''')
    
    conn.commit()
    conn.close()

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

create_table()

for index in results: 
    insert_data(index)
