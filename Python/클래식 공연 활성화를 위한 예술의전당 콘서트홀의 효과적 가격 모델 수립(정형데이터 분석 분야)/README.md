# 데이터 분석 이전의 전처리 과정들(맡은 부분만 기록)
- ### [데이터셋의 결측치 해결](#데이터셋의-결측치-해결) 
- ### [팀원과 아이디어 제시 회의 후 결정된 아이디어를 실제 구현](#아이디어-구현)
- ### [최종 아이디어 구체화 및 흐름 작성](#최종-아이디어-구현)
---
 ### 1. 데이터셋의 결측치 해결 <a name="데이터셋의-결측치-해결"></a>
 전체 데이터셋의 결측치는 정말 많았지만, 그 중에서도 `성별` 필드와 `나이` 필드의 결측치가 약 67%나 비어 있었다. 다른 필드면 몰라도 성별과 나이는 대부분의 데이터셋에서 중요한 역할을 하는데, 이게 이렇게나 비어 있다니. 그래서 얼른 해결해야 했다. 결측치를 해결하기 위해서 여러 방법을 사용할 수 있었지만 교수님이 아이디어를 제공해 주셔서 그것을 바탕으로 문제 해결을 진행하게 되었다. 

 먼저 교수님이 제시해 주신 아이디어는, 각 필드의 이해를 바탕으로 `성별`과 `나이` 필드와 관련된 새로운 필드를 새로 만드는 것이었다. 그래서 그것까진 진행을 완료했다. 그러나 그 다음이 막막했다. *DROP ALL*이나 *평균값*, *중앙값*, *새로운 값* 등으로 채우는 방법은 좋아 보이지 않아서 회귀 분석을 통해 결측치를 처리하기로 결정했다.

 분산 분석을 통해 새로 만든 필드가 유의미한 영향을 주고 있다고 판단했고, 그를 통해 상관 관계가 서로 높은 필드만 골라내 결측치까지 고려한 회귀 분석을 해 주는 XGBoost 기반 모델을 만들어 이 문제를 해결했다.
---
 ### 2. 팀원과 아이디어 제시 회의 후 결정된 아이디어를 실제 구현 <a name="아이디어-구현"></a>
 제시된 의견 중 최종 결정된 의견 : 
 ```
 💡 좌석 럭키드로우 시스템 도입 : 콘서트홀의 남는 좌석에 한해서 프리미엄 좌석에 앉을 수 있는 기회를 제공.
 가격은 일반석보다 조금 높게 설정.
```
 3층을 1등급으로, 2층을 2등급, 1층을 3등급으로 정한다고 가정. 등급이 높은 좌석일수록 공연이 진행되는 모습과 소리를 더욱 잘 들을 수 있게 된다. 콘서트홀의 전체 좌석은 2505개, 하나의 공연에서 사람들이 선점하지 않은 좌석에 대해, 추가 비용을 지불하여 더 좋은 등급의 좌석에 앉을 수 있는 기회를 제공하는 상품을 판매.
 
---
 ### 3. 최종 아이디어 구체화 및 흐름 작성 <a name="최종-아이디어-구현"></a>
``` Python
# 콘서트홀의 층별 좌석 비율
floor_1_ratio = 60.199600798403196 / 100
floor_2_ratio = 22.674650698602793 / 100
floor_3_ratio = 17.12574850299401 / 100

# 콘서트홀의 전체 좌석 수
total_seats = 2505

# 각 층의 좌석 수 계산
seats_floor_1 = floor_1_ratio * total_seats
seats_floor_2 = floor_2_ratio * total_seats
seats_floor_3 = floor_3_ratio * total_seats

""""""
# 등급별 추가 비용 설정 (1등급, 2등급, 3등급)
additional_cost_1st_grade = 0  # 1등급은 추가 비용이 없음
additional_cost_2nd_grade = 1  # 2등급은 1만원 추가 비용
additional_cost_3rd_grade = 2  # 3등급은 2만원 추가 비용
""""""

# 등급별 좌석 수 계산
seats_1st_grade = seats_floor_3
seats_2nd_grade = seats_floor_2
seats_3rd_grade = seats_floor_1

# 등급별 추가 비용 총액 계산
total_cost_1st_grade = seats_1st_grade * additional_cost_1st_grade
total_cost_2nd_grade = seats_2nd_grade * additional_cost_2nd_grade
total_cost_3rd_grade = seats_3rd_grade * additional_cost_3rd_grade

# 결과 출력
print(f"1등급 좌석 수: {round(seats_1st_grade)}석")
print(f"2등급 좌석 수: {round(seats_2nd_grade)}석")
print(f"3등급 좌석 수: {round(seats_3rd_grade)}석")
print()
print(f"1등급 추가 비용 총액: {round(total_cost_1st_grade)}만원")
print(f"2등급 추가 비용 총액: {round(total_cost_2nd_grade)}만원")
print(f"3등급 추가 비용 총액: {round(total_cost_3rd_grade)}만원")
```
