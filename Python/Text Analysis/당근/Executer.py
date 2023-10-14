import sqlite3

conn = sqlite3.connect('Carrot.db')
cursor = conn.cursor()

# 테이블 생성
cursor.execute('''
    CREATE TABLE Carrot (
        Day INTEGER PRIMARY KEY,
        TOP1 TEXT,
        TOP2 TEXT,
        TOP3 TEXT,
        TOP4 TEXT,
        TOP5 TEXT,
        TOP6 TEXT,
        TOP7 TEXT,
        TOP8 TEXT,
        TOP9 TEXT,
        TOP10 TEXT
    )
''')

# 데이터 보관
cursor.execute('''
    INSERT INTO Carrot (TOP1, TOP2, TOP3, TOP4, TOP5, TOP6, TOP7, TOP8, TOP9, TOP10)
    VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
''', top_nouns_list)

conn.commit()
conn.close()
