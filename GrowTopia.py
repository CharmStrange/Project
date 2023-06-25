import os
import requests
from bs4 import BeautifulSoup
import codecs
import pandas as pd

# 현재 파일이 위치한 디렉토리 경로 가져오기
current_dir = os.path.dirname(os.path.abspath(__file__))
filename = os.path.join(current_dir, "data.txt")

base_url = "https://www.growtopiagame.com/forums/forum/marketplace/buying-selling"

# 페이지 범위 설정
start_page = 1
end_page = 1

buy_keywords = ["buy"]
sell_keywords = ["sell"]

# 데이터 저장을 위한 리스트 초기화
buy_data = []
sell_data = []

# 데이터 수집 자동화 과정!
with codecs.open(filename, "w", encoding="utf-8") as file:
    for page in range(start_page, end_page + 1):
        url = f"{base_url}/page{page}"
        
        # 웹 페이지 요청
        response = requests.get(url)
        html_content = response.text

        # HTML 파싱
        soup = BeautifulSoup(html_content, "html.parser")

        # class 속성이 "a.topic-title.js-topic-title"인 요소 추출
        elements = soup.find_all("a", class_="topic-title js-topic-title")

        # 추출된 데이터 저장 및 키워드 분류
        for element in elements:
            data = element.get_text(strip=True)
            file.write(data + "\n")

            lower_data = data.lower()
            if any(keyword in lower_data for keyword in buy_keywords):
                buy_data.append(data)
            if any(keyword in lower_data for keyword in sell_keywords):
                sell_data.append(data)

print(f"데이터가 {filename} 파일에 저장되었습니다.")

# Buy 데이터 테이블 생성
buy_table = pd.DataFrame(buy_data, columns=["Buy"])

# Sell 데이터 테이블 생성
sell_table = pd.DataFrame(sell_data, columns=["Sell"])

# Buy 테이블 출력
print("Buy 키워드 데이터:")
print(buy_table)

# Sell 테이블 출력
print("Sell 키워드 데이터:")
print(sell_table)
