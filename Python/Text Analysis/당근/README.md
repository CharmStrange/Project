# 당근마켓 아이템 분석

각 [지역](regions.py)별로 많이 올라오는 아이템에 대해 알아본다.

- [웹 크롤러](Korean_Carrot_saves.py)
- [텍스트 분석기](KoNLPy_researcher.py)
---
먼저, 각 지역별로 올라오는 아이템만 추출해 텍스트 파일로 저장한다. 지역별로 파일을 저장하려면 `list.txt` 파일명을 바꿔주든가 저장 경로를 다르게 설정해야 한다. 텍스트 파일명이 같으면 신규 데이터가 기존 데이터 위에 덮여 쓰여 기존 데이터가 사라지기 때문이다.
```Python
import requests
from bs4 import BeautifulSoup

# GET 요청으로 웹 페이지 내용 가져오기
response = requests.get(제주특별자치도)
html_content = response.text

# BeautifulSoup을 사용하여 HTML 파싱
soup = BeautifulSoup(html_content, "html.parser")

# class가 "card-title"인 요소들 찾기
card_title_elements = soup.find_all(class_="card-title")

# 결과 출력 및 저장
output_file = "list.txt"
with open(output_file, "w", encoding="utf-8") as f:
    for element in card_title_elements:
        title = element.get_text(strip=True)
        print(title)
        f.write(title + "\n")
```
(*2023년 8월 24일 기준*)코드의 실행 결과는 다음과 같다.
<img width="633" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/c5fbd7ad-302f-41de-b68f-ef810456b2c4">

출력된 결과에 대해, 가장 많이 올라온 아이템을 알아보려면 [KoNLPy](https://konlpy.org/ko/latest/index.html)를 사용한다.
```Python
from konlpy.tag import Okt
from collections import Counter

# 저장된 제목을 불러오기
input_file = "list.txt"
with open(input_file, "r", encoding="utf-8") as f:
    titles = f.readlines()

# 형태소 분석기 초기화
okt = Okt()

# 모든 제목에서 명사 추출
nouns = []
for title in titles:
    nouns.extend(okt.nouns(title))

# 가장 많이 나온 상위 명사 10개 추출
top_nouns = Counter(nouns).most_common(10)

# 결과 출력
print("가장 많이 사용된 명사:")
for noun, count in top_nouns:
    print(f"{noun}: {count}회")
```
위 코드의 실행 결과는 다음과 같다.

<img width="300" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/23446be6-eee7-45d3-803e-1b84244fa469">
