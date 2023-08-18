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
    print("{0}({1})".format(word, count), end="")
print()
