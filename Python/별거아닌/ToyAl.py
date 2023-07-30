# 선행 판단 알고리즘 / a와 b 중 어느 것이 먼저 기록되었느냐 / 선입선출?
# https://wikidocs.net/28
from logging.config import dictConfig
import logging as l

dictConfig({'version': 1,'formatters': {'default': {'format': '[%(asctime)s] %(message)s',}}
            ,'handlers': {'file': {'level': 'DEBUG','class': 'logging.FileHandler','filename': 'log.txt','formatter': 'default',},}
            ,'root': {'level': 'DEBUG','handlers': ['file']}})

def myfunc(text):
    return l.debug(text)

def logcheck():
    file=open("log.txt", 'r')
    texts=file.readlines()[0:]
    for i in texts:
      print(i)
    file.close()

# 새로운 데이터 입력
def Type():
    data=input("데이터 입력:")
    myfunc(data)

# V는 문자열, V가 포함된 문장을 출력
def Judgment(V):
    # 새로운 파일 작성과 리스트 생성
    file1=open("log.txt", 'r')
    file2=open("time.txt", 'w')
    for line in file1:
        if V in line:
            file2.write(line)
    file1.close()
    file2.close()
    file2=open("time.txt", 'r')
    print([text.split('\n')[0] for text in file2.readlines()[0:]], '\n')
    file2.close()

    # 메인 부분
    file2=open("time.txt", 'r')
    print("선행 판단(순서대로 선입)")
    for i, j in enumerate([text.split('\n')[0] for text in file2.readlines()[0:]]):
        print("인덱스 {}번 원소 : {}".format(i, j))
    file2.close()
