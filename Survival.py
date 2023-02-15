# 100개의 개체, 100개의 음식 
# 개선 필요?
import numpy as np

# 딕셔너리 key 는 개체 번호, value 가 능력치, 능력치는 작을수록 불리
{init:0 for init in list([human for human in np.arange(1,101).reshape(100)])} # 딕셔너리
# 음식의 값
[food for food in np.random.rand(100)] # 리스트

print({init:0 for init in list([human for human in np.arange(1,101).reshape(100)])}) 
print(np.random.choice([food for food in np.random.rand(100)], 100, replace=False)) # 1차원 배열, 벡터

# 딕션너리의 각 value 와 리스트의 각 음식 값을 매치해 더해주기
#아래 문장이 문제, TypeError: cannot unpack non-iterable numpy.float64 object
[[value+food for value in np.random.choice([food for food in np.random.rand(100)], 100, replace=False)] for value in list(({init:0 for init in list([human for human in np.arange(1,101).reshape(100)])}).values())]

#[a for a in ({init:0 for init in list([human for human in np.arange(1,101).reshape(100)])}).values()]

#[[value+food for value, food in np.random.choice([food for food in np.random.rand(100)], 100, replace=False)] for value in list(({init:0 for init in list([human for human in np.arange(1,101).reshape(100)])}).values())]
np.array(np.random.choice([food for food in np.random.rand(100)], 100, replace=False))
np.array(list(({init:0 for init in list([human for human in np.arange(1,101).reshape(100)])}).values()))

# TypeError: cannot unpack non-iterable numpy.float64 object
# 배열 구조 변경으로 해결? 안됨
#[[value+food for value, food in np.array(np.random.choice([food for food in np.random.rand(100)], 100, replace=False)).reshape(100)] for value in np.array(list(({init:0 for init in list([human for human in np.arange(1,101).reshape(100)])}).values())).reshape(100)]

# float 형 말고 그냥 정수로 해보면?
# cannot unpack non-iterable numpy.int64 object 해결 안됨됨
#np.random.choice([food for food in np.random.randint(1,3,size=100)], 100, replace=False)
#list(({init:0 for init in list([human for human in np.arange(1,101).reshape(100)])}).values())
#[[value+food for value, food in np.random.choice([food for food in np.random.randint(1,3,size=100)], 100, replace=False)] for value in list(({init:0 for init in list([human for human in np.arange(1,101).reshape(100)])}).values())]

# numpy 사용하지 않고?
import random as rd

type(np.random.choice([food for food in np.random.randint(1,3,size=100)], 100, replace=False))

########################################################################################################################################################################################################################################################################

# 각 개체의 초기 능력치에 랜덤한 음식 값을 더함(음식을 먹음), 이걸 다시 각 개체의 능력치로 저장
humans=list(({init:0 for init in list([human for human in np.arange(1,101).reshape(100)])}).values())
foods=[food for food in np.random.rand(100)]
humans[0]+foods[0] # 0번 인덱스
