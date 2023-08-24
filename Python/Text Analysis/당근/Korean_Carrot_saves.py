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
