import requests
import re
import os
from bs4 import BeautifulSoup
import sqlite3
from pyspark.sql import SparkSession

regions = {
    "서울특별시": "https://www.daangn.com/region/%EC%84%9C%EC%9A%B8%ED%8A%B9%EB%B3%84%EC%8B%9C",
    "부산광역시": "https://www.daangn.com/region/%EB%B6%80%EC%82%B0%EA%B4%91%EC%97%AD%EC%8B%9C",
    "대구광역시": "https://www.daangn.com/region/%EB%8C%80%EA%B5%AC%EA%B4%91%EC%97%AD%EC%8B%9C",
    "인천광역시": "https://www.daangn.com/region/%EC%9D%B8%EC%B2%9C%EA%B4%91%EC%97%AD%EC%8B%9C",
    "광주광역시": "https://www.daangn.com/region/%EA%B4%91%EC%A3%BC%EA%B4%91%EC%97%AD%EC%8B%9C",
    "대전광역시": "https://www.daangn.com/region/%EB%8C%80%EC%A0%84%EA%B4%91%EC%97%AD%EC%8B%9C",
    "울산광역시": "https://www.daangn.com/region/%EC%9A%B8%EC%82%B0%EA%B4%91%EC%97%AD%EC%8B%9C",
    "세종특별자치시": "https://www.daangn.com/region/%EC%84%B8%EC%A2%85%ED%8A%B9%EB%B3%84%EC%9E%90%EC%B9%98%EC%8B%9C",
    "경기도": "https://www.daangn.com/region/%EA%B2%BD%EA%B8%B0%EB%8F%84",
    "강원특별자치도": "https://www.daangn.com/region/%EA%B0%95%EC%9B%90%ED%8A%B9%EB%B3%84%EC%9E%90%EC%B9%98%EB%8F%84",
    "충청북도": "https://www.daangn.com/region/%EC%B6%A9%EC%B2%AD%EB%B6%81%EB%8F%84",
    "충청남도": "https://www.daangn.com/region/%EC%B6%A9%EC%B2%AD%EB%82%A8%EB%8F%84",
    "전라북도": "https://www.daangn.com/region/%EC%A0%84%EB%9D%BC%EB%B6%81%EB%8F%84",
    "전라남도": "https://www.daangn.com/region/%EC%A0%84%EB%9D%BC%EB%82%A8%EB%8F%84",
    "경상북도": "https://www.daangn.com/region/%EA%B2%BD%EC%83%81%EB%B6%81%EB%8F%84",
    "경상남도": "https://www.daangn.com/region/%EA%B2%BD%EC%83%81%EB%82%A8%EB%8F%84",
    "제주특별자치도": "https://www.daangn.com/region/%EC%A0%9C%EC%A3%BC%ED%8A%B9%EB%B3%84%EC%9E%90%EC%B9%98%EB%8F%84"
}

spark = SparkSession.builder.appName("proto").config("spark.some.config.option", "some-value").getOrCreate()

titles = []
prices = []
for region, url in regions.items():
  response = requests.get(url)
  html_content = response.text
  soup = BeautifulSoup(html_content, "html.parser")
  card_title_elements = soup.find_all(class_="card-title")
  card_price_elements = soup.find_all(class_="card-price")

  for element in card_title_elements:
    titles.append(element.get_text(strip=True))

  for element in card_price_elements:
    text = element.get_text(strip=True)
    text = re.sub(r'[^0-9]', '', text)
    prices.append(text)


rdd_titles = spark.sparkContext.parallelize(titles)
rdd_prices = spark.sparkContext.parallelize(prices)

rdd_titles.saveAsTextFile("rdd_titles")
rdd_prices.saveAsTextFile("rdd_prices")

db_file = 'CarrotText_WHOLE.db'

def create_table():
    conn = sqlite3.connect('CarrotText_WHOLE.db')
    c = conn.cursor()

    c.execute('''CREATE TABLE IF NOT EXISTS CarrotTextWHOLE
                 (Title TEXT, Price TEXT)''')

    conn.commit()
    conn.close()

def create_database():
    if not os.path.exists(db_file):
        create_table()

def add_new_data(title, price):
    conn = sqlite3.connect(db_file)
    c = conn.cursor()

    try:
        c.execute('''INSERT INTO CarrotTextWHOLE (Title, Price) VALUES (?, ?)''', (title, price))
    except sqlite3.Error as e:
        print("Error occurred:", e)
    finally:
        conn.commit()
        conn.close()

def insert_rdd_to_db(rdd_titles, rdd_prices):
    titles = rdd_titles.collect()
    prices = rdd_prices.collect()

    for title, price in zip(titles, prices):
        add_new_data(title, price)

create_database()

rdd_titles = spark.sparkContext.parallelize(titles)
rdd_prices = spark.sparkContext.parallelize(prices)

insert_rdd_to_db(rdd_titles, rdd_prices)
