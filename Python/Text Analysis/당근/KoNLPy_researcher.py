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
stop_words = ['판매', '기', '용', '인치', '상품', '갤럭시', '삼성', '프로', '미니', '세트', '세대', '단', '정리', '정품', '사이즈', '애플', '블랙', '화이트', '일괄', '급', '급처', '제품', '나이키', '신세계', '선물', '울트라', '아기', '밍', '게이', '맥스', '호']

# 불용어 제외하고 명사 카운트
filtered_nouns = [noun for noun in all_nouns if noun not in stop_words]
top_nouns = Counter(filtered_nouns).most_common(10)

# 딕셔너리 형태
dict_top_nouns = dict(top_nouns)
top_nouns_list = list(dict_top_nouns.keys())[:10]

# 결과 출력
print("가장 많이 사용된 명사:\n")
for noun, count in top_nouns:
    print(f"{noun}: {count}회")
