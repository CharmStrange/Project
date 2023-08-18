# 자연어 처리 툴 KoNLPy(한국어) 

가장 먼저 텍스트 파일에서 많이 사용된 명사를 출력하는 코드이다.

#### [필요한 텍스트 파일](Pan.txt)

#### <[파이썬 파일](konlpy.py)>

```Python
from konlpy.tag import Twitter

# utf-8 인코딩으로 파일을 열고 글자를 읽기
with open("Pan.txt", "r", encoding="utf-8") as fp:
    lines = fp.read().split("\n")

# 텍스트 한 줄씩 처리
word_dic = {}
for line in lines:
    malist = twitter.pos(line)

    for word in malist:
        if word[1] == "Noun":  # 명사 체크
            if word[0] not in word_dic:
                word_dic[word[0]] = 0
            word_dic[word[0]] += 1  # 카운트

# 많이 사용된 명사 출력
keys = sorted(word_dic.items(), key=lambda x: x[1], reverse=True)
for word, count in keys[:50]:
    print("{0}({1})\n".format(word, count), end="")
print()
```

<img width="430" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/4e9a8c5f-6420-4eb0-94b0-6681107fb201">
