# 당근마켓 아이템 분석

각 [지역](regions.py)별로 많이 올라오는 아이템에 대해 알아본다.

- [웹 크롤러](https://github.com/CharmStrange/Project/blob/%EC%A0%9C%EC%9E%91_%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%A8/Web%20Crawl/CarrotCrawler.exe)
- [웹 크롤러 소스 코드](Korean_Carrot_saves.py)
- [텍스트 분석기](KoNLPy_researcher.py)
---
먼저, 각 지역별로 올라오는 아이템만 추출해 텍스트 파일로 저장한다. 
```Python
import requests
from bs4 import BeautifulSoup

# 변수들을 딕셔너리에 저장
regions = {
    ...
}

# 반복문을 통한 웹 크롤링 및 결과 저장
for region, url in regions.items():
    response = requests.get(url)
    html_content = response.text
    soup = BeautifulSoup(html_content, "html.parser")
    card_title_elements = soup.find_all(class_="card-title")
    output_file = f"list_{region}.txt"
    
    with open(output_file, "w", encoding="utf-8") as f:
        for element in card_title_elements:
            title = element.get_text(strip=True)
            print(title)
            f.write(title + "\n")
```
(*2023년 8월 25일 기준*)코드의 실행(23초) 결과는 다음과 같다.

<img width="263" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/dcb102d6-cb11-458f-8b7a-99319afe2168">

출력된 결과에 대해, 가장 많이 올라온 아이템을 알아보려면 [KoNLPy](https://konlpy.org/ko/latest/index.html)를 사용한다.
```Python
from konlpy.tag import Okt
from collections import Counter

# 저장된 제목 파일 목록
region_files = [f"list_{region}.txt" for region in regions.keys()]

# 형태소 분석기 초기화
okt = Okt()

# 모든 제목에서 명사 추출
all_nouns = []

for region_file in region_files:
    with open(region_file, "r", encoding="utf-8") as f:
        titles = f.readlines()

    region_nouns = []

    for title in titles:
        region_nouns.extend(okt.nouns(title))

    all_nouns.extend(region_nouns)

# 불용어 설정
stop_words = [...]

# 불용어 제외하고 명사 카운트
filtered_nouns = [noun for noun in all_nouns if noun not in stop_words]
top_nouns = Counter(filtered_nouns).most_common(10)

# 결과 출력
print("가장 많이 사용된 명사:\n")
for noun, count in top_nouns: 
    print(f"{noun}: {count}회")
```
위 코드의 실행(2초) 결과는 다음과 같다.

<img width="221" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/aca94fe1-fa8b-4e84-a397-3c590d1157b8">


전체 지역별로 많이 올라온 아이템들의 카테고리를 한 눈에 확인할 수 있다.

---

데이터 수집 기간 : ~

> 매일 텍스트 추출을 해 본 결과 아이폰이 압도적으로 많이 올라온다. 

> 추석 시즌이 되니 기름, 스팸 등이 많이 올라온다.

> 날이 슬슬 추워지니 패딩, 조끼 등의 아이템이 올라온다.

---

데이터 수집 과정을 자동화 파이프라인으로 만들어야겠다. 지금 매일 코드 돌리며 데이터 작성하는게 귀찮아졌다.

```Python
import sqlite3

conn = sqlite3.connect('CarrotText.db')
cursor = conn.cursor()

# 데이터 보관
cursor.execute('''
    INSERT INTO Carrot (TOP1, TOP2, TOP3, TOP4, TOP5, TOP6, TOP7, TOP8, TOP9, TOP10)
    VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
''', top_nouns_list)

conn.commit()
conn.close()
```
일단 텍스트 분석기가 내놓은 결과를 가지고 데이터베이스 파일에 데이터를 보관하는 프로토타입 코드를 작성해 봤다. [기존 DB](https://github.com/CharmStrange/Project/tree/main/DB%20files/Text%20Analysis-%EB%8B%B9%EA%B7%BC) 구조와 동일하게 저장된다.

<img width="336" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/20e6fc7b-ed52-4843-b443-c1af9e392915">

<img width="336" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/04432c30-00ec-4737-91a5-f90a6b8f747a">

코드를 실행하면 기존 데이터베이스에 자동으로 새 데이터가 추가된다. (CoLab 환경에 기존 데이터베이스 파일을 업로드해야 된다)

---

아예 이것까지 자동화 해버리고 싶은데, 어떻게 하면 좋을까?
- CoLab 말고 로컬 환경에서 `cron` 같은거 설정해서 해 보기 / 그러려면 리눅스를 써야겠네...
- 하는 김에 Git(Hub) Commit 자동화도 해 보고...
