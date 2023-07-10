# 실전 데이터 분석 

### [1차 데이터 회귀 분석](https://github.com/CharmStrange/Snippet/blob/main/Python/READMES/README_GrowTopia_STAT.md)에 이어, 판매 물품과 관련된 데이터 분석을 해 보려 한다. 이는 재고 보충을 더욱 효율적으로 할 수 있게 도와줄 것이며 판매량과 직접적인 연관이 있기 때문에 수익 최대화에 도움이 될 것이다.
---

## 1. 분석할 대상 정의, 데이터 구하기.
> <img width="200" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/4cacda11-b826-40cb-bc20-fa01179ea1e6">
>
> <img width="434" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/aea88d6d-1276-459d-b2a9-cb5c5d563ae9">
>
> 분석할 대상은 ***Basic Splicing Kit***, 1개 팩이 아닌 20개 팩을 Batch 단위 : *Purchase_n* 로 정하였고 팩의 내용물 시퀀스는 알파벳 순으로 정렬했다. 그것을 코드로 기록해 본 결과는 다음과 같다.
>```python
>import pandas as pd
>
>Columns = ['Cave Column Seed', 'Door Seed', 'Glass Pane Seed', 'Grass Seed', 'Lava Rock Seed', 'Martian >Tree Seed', 'Sign Seed', 'Wood Block Seed']
>Index = ['Purchase_' + str(i) for i in range(1,26)]
>
>PackData = [
>    [13, 23, 27, 18, 33, 36, 28, 22], # Purchase_1
>    [22, 30, 28, 26, 22, 22, 27, 23], # Purchase_2
>    [26, 24, 24, 24, 23, 27, 31, 21], # Purchase_3
>    [28, 23, 23, 19, 24, 28, 24, 31], # Purchase_4
>    [23, 33, 24, 30, 27, 26, 16, 21], # Purchase_5
>    [30, 27, 19, 17, 26, 27, 23, 31], # Purchase_6
>    [22, 25, 24, 23, 27, 30, 27, 22], # Purchase_7
>    [30, 24, 25, 16, 33, 20, 23, 29], # Purchase_8
>    [23, 27, 25, 22, 24, 30, 19, 30], # Purchase_9
>    [19, 28, 25, 28, 25, 25, 23, 27], # Purchase_10
>    [24, 17, 27, 27, 21, 36, 28, 20], # Purchase_11
>    [31, 14, 29, 28, 22, 24, 29, 23], # Purchase_12
>    [29, 22, 22, 25, 16, 31, 24, 31], # Purchase_13
>    [21, 27, 17, 21, 24, 31, 28, 31], # Purchase_14
>    [23, 22, 24, 24, 24, 35, 30, 18], # Purchase_15
>    [22, 30, 29, 26, 26, 20, 24, 23], # Purchase_16
>    [23, 24, 32, 22, 27, 28, 25, 19], # Purchase_17
>    [21, 29, 31, 19, 30, 15, 28, 27], # Purchase_18
>    [27, 16, 23, 27, 25, 30, 23, 29], # Purchase_19
>    [24, 20, 24, 24, 24, 31, 26, 27], # Purchase_20
>    [25, 28, 22, 20, 28, 24, 27, 26], # Purchase_21
>    [15, 26, 22, 26, 32, 25, 30, 24], # Purchase_22
>    [24, 23, 33, 27, 25, 19, 21, 28], # Purchase_23
>    [32, 23, 21, 22, 24, 28, 23, 27], # Purchase_24
>    [20, 25, 27, 24, 28, 24, 28, 24], # Purchase_25
>]
>```
><img width="790" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/3ea46a01-3976-4920-948d-2efc1b1d44ae">


>
