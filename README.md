# Python(Numpy) Data Simulation
- - -
### 주어진 환경에서 100개의 개체들의 생존율 시뮬레이팅
- 기초 틀
<pre>
# 100개의 개체, 100개의 음식 
# 개선 필요?
import numpy as np

# 딕셔너리 key 는 개체 번호, value 가 능력치, 능력치는 작을수록 불리
{init:0 for init in list([human for human in np.arange(1,101).reshape(100)])} # 딕셔너리
# 음식의 값
[food for food in np.random.rand(100)] # 리스트
</pre>

<pre>
# 각 개체의 초기 능력치에 랜덤한 음식 값을 더함(음식을 먹음), 이걸 다시 각 개체의 능력치로 저장
humans=list(({init:0 for init in list([human for human in np.arange(1,101).reshape(100)])}).values())
foods=[food for food in np.random.rand(100)]

# 첫 번째 개체
humans[0]+foods[0] # 0번 인덱스
</pre>
<img width="213" alt="image" src="https://user-images.githubusercontent.com/105769152/220830559-0ecce8fa-8021-4bdf-9dab-8570ecda5e8b.png">
humans 변수는 개체들의 능력치(시작은 모두 0), foods 변수는 랜덤한 수
