import numpy as np
import random 

# 기존 데이터셋
PackData = [
  ####
]

num_features = 8

# 기존 데이터셋 각 열의 평균과 표준 편차 계산
mean_values = [sum(col) / len(col) for col in zip(*PackData)]
std_values = [((sum((x - mean) ** 2 for x in col) / len(col)) ** 0.5) for col, mean in zip(zip(*PackData), mean_values)]

# 새로운 데이터 생성
new_data = [random.normalvariate(mean, std) for mean, std in zip(mean_values, std_values)]

index = [1, 2, 3, 7]
filtered_new_data = [new_data[i] for i in index]
print(filtered_new_data)
