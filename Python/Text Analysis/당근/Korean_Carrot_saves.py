import requests
from bs4 import BeautifulSoup

# regions 변수 필요

# 반복문을 통한 웹 크롤링 및 결과 저장
for region, url in regions.items():
    response = requests.get(url)
    response.encoding = 'utf-8' 
    html_content = response.text
    soup = BeautifulSoup(html_content, "html.parser")
    card_title_elements = soup.find_all(class_="_1b153uwk _1b153uwj _588sy41w _588sy41b")
    output_file = f"list_{region}.txt"

    with open(output_file, "w", encoding="utf-8") as f:
        for element in card_title_elements:
            title = element.get_text(strip=True)
            f.write(title + "\n")
