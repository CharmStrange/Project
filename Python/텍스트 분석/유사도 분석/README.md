# 텍스트 유사도 분석

텍스트 유사도 분석을 하기 위한 방법으로 레벤슈타인 알고리즘과 N-Grams 모델이 있다.

> ## [레벤슈타인 알고리즘](Levenshtein.py)
> 서로 다른 문자열들이 같아지기 위해 필요한 조작의 수를 계산한다. 이는 문자열간 차이를 수치화한 것이다.
>```Python
># 테스트
>print(calc_distance("가나다라", "가마바라"))
>
> >>> 2
>```
>```Python
>samples = ["삼성역", "역삼역", "삼양역", "천마산역", "장암역"]
>base = samples[0]
>r = sorted(samples, key=lambda n : calc_distance(base, n))
>for n in r :
>    print(calc_distance(base, n), n)
>
> >>>
>0 삼성역
>1 삼양역
>2 역삼역
>2 장암역
>3 천마산역
>```

> ## N-Grams 모델
>
>
>





