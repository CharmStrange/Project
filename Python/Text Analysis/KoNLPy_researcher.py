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
