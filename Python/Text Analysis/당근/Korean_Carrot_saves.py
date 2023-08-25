import requests
from bs4 import BeautifulSoup

# regions 변수 필요

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
