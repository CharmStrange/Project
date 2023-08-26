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
