"""
Herbs_Data = [
    [24, 15, 36, 8, 25, 12, 15],
    [33, 10, 3, 30, 22, 36, 9],
    [15, 25, 35, 6, 20, 13, 15],
    [18, 20, 26, 14, 40, 28, 7],
    [6, 13, 16, 16, 25, 19, 6],
    [17, 20, 11, 20, 27, 14, 9]
]

Herbs_Seeds_Data = [
    [18, 25, 24, 36, 17, 6, 15],
    [14, 22, 21, 11, 17, 30, 10],
    [22, 21, 10, 13, 11, 19, 12],
    [31, 14, 15, 6, 3, 19, 12],
    [24, 40, 23, 16, 6, 22, 17],
    [13, 6, 24, 35, 8, 15, 27]
]
"""
import numpy as np
from statistics import *

size = 5000

# Herbs_Data 데이터셋의 분포를 따르는 새로운 데이터셋을 생성, Herbs_Seeds_Data 사용해도 됨
vec_0 = [vec[0] for vec in Herbs_Data]; vec_0_mean = mean(vec_0); vec_0_std = stdev(vec_0)
vec_1 = [vec[1] for vec in Herbs_Data]; vec_1_mean = mean(vec_1); vec_1_std = stdev(vec_1)
vec_2 = [vec[2] for vec in Herbs_Data]; vec_2_mean = mean(vec_2); vec_2_std = stdev(vec_2)
vec_3 = [vec[3] for vec in Herbs_Data]; vec_3_mean = mean(vec_3); vec_3_std = stdev(vec_3)
vec_4 = [vec[4] for vec in Herbs_Data]; vec_4_mean = mean(vec_4); vec_4_std = stdev(vec_4)
vec_5 = [vec[5] for vec in Herbs_Data]; vec_5_mean = mean(vec_5); vec_5_std = stdev(vec_5)
vec_6 = [vec[6] for vec in Herbs_Data]; vec_6_mean = mean(vec_6); vec_6_std = stdev(vec_6)

# 생성할 데이터의 개수는 100으로 설정함
ele_0 = np.random.normal(vec_0_mean, vec_0_std, size)
eles_0 = [round(round_ele_0) for round_ele_0 in ele_0]

ele_1 = np.random.normal(vec_1_mean, vec_1_std, size)
eles_1 = [round(round_ele_1) for round_ele_1 in ele_1]

ele_2 = np.random.normal(vec_2_mean, vec_2_std, size)
eles_2 = [round(round_ele_2) for round_ele_2 in ele_2]

ele_3 = np.random.normal(vec_3_mean, vec_3_std, size)
eles_3 = [round(round_ele_3) for round_ele_3 in ele_3]

ele_4 = np.random.normal(vec_4_mean, vec_4_std, size)
eles_4 = [round(round_ele_4) for round_ele_4 in ele_4]

ele_5 = np.random.normal(vec_5_mean, vec_5_std, size)
eles_5 = [round(round_ele_5) for round_ele_5 in ele_5]

ele_6 = np.random.normal(vec_6_mean, vec_6_std, size)
eles_6 = [round(round_ele_6) for round_ele_6 in ele_6]

for i in range(size) :
    new_vector = [eles_0[i], eles_1[i], eles_2[i], eles_3[i], eles_4[i], eles_5[i], eles_6[i]]
    Herbs_Data.append(new_vector)
    
for vec in Herbs_Data:
    for i in range(len(vec)):
        if vec[i] < 0:
            vec[i] = 0

Herbs_Data

""" Herbs_Seeds_Data 데이터셋의 분포를 따르는 새로운 데이터셋을 생성
vec_0 = [vec[0] for vec in Herbs_Seeds_Data]; vec_0_mean = mean(vec_0); vec_0_std = stdev(vec_0)
vec_1 = [vec[1] for vec in Herbs_Seeds_Data]; vec_1_mean = mean(vec_1); vec_1_std = stdev(vec_1)
vec_2 = [vec[2] for vec in Herbs_Seeds_Data]; vec_2_mean = mean(vec_2); vec_2_std = stdev(vec_2)
vec_3 = [vec[3] for vec in Herbs_Seeds_Data]; vec_3_mean = mean(vec_3); vec_3_std = stdev(vec_3)
vec_4 = [vec[4] for vec in Herbs_Seeds_Data]; vec_4_mean = mean(vec_4); vec_4_std = stdev(vec_4)
vec_5 = [vec[5] for vec in Herbs_Seeds_Data]; vec_5_mean = mean(vec_5); vec_5_std = stdev(vec_5)
vec_6 = [vec[6] for vec in Herbs_Seeds_Data]; vec_6_mean = mean(vec_6); vec_6_std = stdev(vec_6)

ele_0 = np.random.normal(vec_0_mean, vec_0_std, size)
eles_0 = [round(round_ele_0) for round_ele_0 in ele_0]

ele_1 = np.random.normal(vec_1_mean, vec_1_std, size)
eles_1 = [round(round_ele_1) for round_ele_1 in ele_1]

ele_2 = np.random.normal(vec_2_mean, vec_2_std, size)
eles_2 = [round(round_ele_2) for round_ele_2 in ele_2]

ele_3 = np.random.normal(vec_3_mean, vec_3_std, size)
eles_3 = [round(round_ele_3) for round_ele_3 in ele_3]

ele_4 = np.random.normal(vec_4_mean, vec_4_std, size)
eles_4 = [round(round_ele_4) for round_ele_4 in ele_4]

ele_5 = np.random.normal(vec_5_mean, vec_5_std, size)
eles_5 = [round(round_ele_5) for round_ele_5 in ele_5]

ele_6 = np.random.normal(vec_6_mean, vec_6_std, size)
eles_6 = [round(round_ele_6) for round_ele_6 in ele_6]

for i in range(size) :
    new_vector = [eles_0[i], eles_1[i], eles_2[i], eles_3[i], eles_4[i], eles_5[i], eles_6[i]]
    Herbs_Seeds_Data.append(new_vector)
    
for vec in Herbs_Seeds_Data:
    for i in range(len(vec)):
        if vec[i] < 0:
            vec[i] = 0

Herbs_Seeds_Data 
"""

Index = ['Herb_Bag_' + str(i) for i in range(1,len(Herbs_Data)+1)]

import pandas as pd

Herbs_df = pd.DataFrame(Herbs_Data, columns=Herbs, index=Index)
Herb_Seeds_df = pd.DataFrame(Herbs_Seeds_Data, columns=Herb_Seeds, index=Index)

Herbs_df.to_csv("Herbs_df.csv")
Herb_Seeds_df.to_csv("Herb_Seeds_df.csv")
