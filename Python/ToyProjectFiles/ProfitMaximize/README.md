# 수익 최대화 가정 모델

> ### 수익 최대화 가정 모델을 제작하기 위해, 가장 먼저 1 batch 당 기대되는 내용물의 수를 구해야 한다. 
>
><img width="267" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/90dc3d09-3690-41cc-bf2b-196b2a52aecf">
>
>```Python
># 1 batch 당 전체 내용물 개수는 200, 1 batch 당 기대되는 내용물 수 구하기
>GRASS = (10.64/100) * 200
>DOOR = (11.74/100) * 200
>WOOD = (14.17/100) * 200
>GLASS = (10.92/100) * 200
>
>print(f"Grass Seed : {GRASS} \nDoor Seed: {DOOR} \nWood Block Seed : {WOOD} \nGlass Pane Seed : {GLASS} \n")
>```
>```Python
> >>> Grass Seed : 21.28 
> >>> Door Seed : 23.48 
> >>> Wood Block Seed : 28.34 
> >>> Glass Pane Seed : 21.84 
>```
> (데이터셋의 크기가 더욱 컸다면, 이들 모두 25 근처로 수렴했을 것)

> ### 다음으로 각 내용물의 시세를 고려해 얼마 만큼의 **Restock**(재고 보충)이 필요한지를 batch 단위로 정의한다.
> 
> 각 내용물이 판매되는 최소 개수를 기준으로 정리하면, `Grass Seed`의 경우 최소 200개이며 이는 10 batch, `Door Seed`의 경우 최소 100개이며 이는 5 batch, `Wood Block Seed`의 경우 최소 200개이며 이는 10 batch, `Glass Pane Seed`의 경우 최소 100개이며 이는 5 batch이다.
> ```Python
>Grass Seed : 200 per 1 [10 batch]
>
>Door Seed : 100 per 1 [5 batch]
>
>Wood Block Seed : 200 per 1 [10 batch]
>
>Glass Pane Seed : 100 per 1 [5 batch]
> ```
> 여기에 내용물의 나머지까지 고려하면 다음과 같은 결과가 나온다. 나머지 또한 다음의 **Restock**에 포함되니 고려할 수 밖에 없다.
> ```Python
>print((GRASS * 10) % 200)
>print((DOOR * 5) % 100)
>print((WOOD * 10) % 200)
>print((GLASS * 5) % 100)
>
> >>> 12.800000000000011
> >>> 17.400000000000006
> >>> 83.39999999999998
> >>> 9.200000000000003
> ```

> ### [데이터셋](https://github.com/CharmStrange/Project/blob/main/Python/ToyProjectFiles/PackAnalysis/PackData.py)을 활용한 수익 최대화 모델 구조를 정의한다.
>
> ->[데이터셋](https://github.com/CharmStrange/Project/blob/main/Python/ToyProjectFiles/PackAnalysis/PackData.py)<- 을 기반으로, 1 batch 당 내용물의 수를 구한 뒤 모델의 파라미터에 넣어주어야 한다.
> ```Python
># 시세 변수 : 시세 변동이 있을 수 있으므로 상황에 따라 값을 바꾸기 위해 필요
>High = 50
>Middle = 100
>Middle_Low = 150
>Low = 200
> remainsContainer = [ [], [], [], [] ]
>
>class ProfitMaximizer:
>
>    def __init__(self, GR, D, W, GL) : # GR, D, W, GL 에 1 batch 에서 기대되는 내용물 수 넣기 
>        self.GR = GR
>        self.D = D
>        self.W = W
>        self.GL = GL
>
>    def Fit(self, batch_size) :
>        if ((self.GR * batch_size) // Low) : print("Profitable : Grass Seed\n") 
>        else : print("Non-Profitable : Grass Seed\n")
>
>        if ((self.D * batch_size) // Middle) : print("Profitable : Door Seed\n") 
>        else : print("Non-Profitable : Door Seed\n")
>
>        if ((self.W * batch_size) // Low) : print("Profitable : Wood Block Seed\n") 
>        else : print("Non-Profitable : Wood Seed\n")
>
>        if ((self.GL * batch_size) // Middle) : print("Profitable : Glass Pane Seed\n") 
>        else : print("Non-Profitable : Glass Pane Seed\n")
>
>    def remain(self, batch_size) :
>        GR_r = (self.GR * batch_size) % Low
>        D_r = (self.D * batch_size) % Middle
>        W_r = (self.W * batch_size) % Low
>        GL_r = (self.GL * batch_size) % Middle
>
>        if ((self.GR * batch_size) // Low) : print(f"Grass Seed : {GR_r}\n"); remainsContainer[0].append(GR_r);
>        else : print("No remains!\n")
>
>        if ((self.D * batch_size) // Middle) : print(f"Door Seed : {D_r}\n"); remainsContainer[1].append(D_r);
>        else : print("No remains!\n")
>
>        if ((self.W * batch_size) // Low) : print(f"Wood Block Seed : {W_r}\n"); remainsContainer[2].append(W_r);
>        else : print("No remains!\n")
>
>        if ((self.GL * batch_size) // Middle) : print(f"Glass Pane Seed : {GL_r}\n"); remainsContainer[3].append(GL_r);
>        else : print("No remains!\n")
>
>        print("Total remains : ", remainsContainer[0], remainsContainer[1], remainsContainer[2], remainsContainer[3], "\n")
> 
>    def MeanCmp(self) :
>        meancmp_GR = means[0] - self.GR
>        meancmp_D = means[1] - self.D
>        meancmp_W = means[2] - self.W
>        meancmp_GL = means[3] - self.GL
>
>        print(f"Difference between the mean of Grass Seeds and {self.GR} : {meancmp_GR}")
>        print(f"Square of the difference between the mean of Grass Seeds and {self.GR} : {meancmp_GR**2}\n")
>
>        print(f"Difference between the mean of Door Seeds and {self.D} : {meancmp_D}")
>        print(f"Square of the difference between the mean of Door Seeds and {self.D} : {meancmp_D**2}\n")
>
>        print(f"Difference between the mean of Wood Block Seeds and {self.W} : {meancmp_W}")
>        print(f"Square of the difference between the mean of Wood Block Seeds and {self.W} : {meancmp_W**2}\n")
>
>        print(f"Difference between the mean of Grass Seeds and {self.GL} : {meancmp_GL}")
>        print(f"Square of the difference between the mean of Glass Pane Seeds and {self.GL} : {meancmp_GL**2}\n")
> ```
> ```Python
> test = ProfitMaximizer(18, 27, 22, 25)
> test.Fit(5)
> test.remain(5)
> test.MeanCmp()
> ```
> <img width="464" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/536f8667-7ad1-42d7-add5-6c6e49b3133e">
>
> <img width="775" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/b2200dc3-9c82-4ba9-acac-6ff6e508b71c">


> ### [Data Maker](DataMaker.py)로 테스트를 진행해 본다.
> 
> 아래 코드는 [기존 데이터셋](https://github.com/CharmStrange/Project/blob/main/Python/ToyProjectFiles/PackAnalysis/PackData.py)을 바탕으로 새로운 데이터를 만들어주는 코드의 주요 알고리즘이며 결과를 바탕으로 모델을 테스트해본다.
> ```Python
> # 기존 데이터셋 각 열의 평균과 표준 편차 계산
> mean_values = [sum(col) / len(col) for col in zip(*PackData)]
> std_values = [((sum((x - mean) ** 2 for x in col) / len(col)) ** 0.5) for col, mean in zip(zip(*PackData), mean_values)]
>
> # 새로운 데이터 생성
> new_data = [random.normalvariate(mean, std) for mean, std in zip(mean_values, std_values)]
> ```
> 위 코드를 사용해 생성한 데이터셋의 분포를 확인하기 위해 상자 도표를 그린다.
> ```Python
># 생성된 데이터의 분포를 확인
> import matplotlib.pyplot as plt
>import seaborn as sns
>
> Data = [...]
> 
># 관심 있는 항목의 인덱스
>item_indices = [0, 1, 2, 3]  # [Door Seed, Glass Pane Seed, Grass Seed, Wood Seed]
>
># 관심 있는 항목의 이름
>item_names = ['Door Seed', 'Glass Pane Seed', 'Grass Seed', 'Wood Seed']
>
># 관심 있는 항목의 데이터 추출
>item_data = [[data_point[i] for data_point in Data] for i in item_indices]
>
># 데이터 분포 시각화
>plt.figure(figsize=(10, 6))
>sns.boxplot(data=item_data)
>plt.xticks(ticks=range(len(item_names)), labels=item_names)
>plt.title('Data Distribution for Specific Items')
>plt.ylabel('Values')
>plt.show()
> ```
> <img width="598" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/0b14af7c-d0fb-4270-a918-edfa7fee36c6">
>
>
> ```Python
># 필요한 아이템만 추출, 나머지 아이템은 특정 시기나 경우에 수요가 있으므로 일단 둠
>index = [1, 2, 3, 7]
>filtered_new_data = [new_data[i] for i in index] 
>
> test = ProfitMaximizer(filtered_new_data[2], filtered_new_data[0], filtered_new_data[3], filtered_new_data[1])
> test.Fit(9)
> test.remain(9)
> ```
> 테스트 시, 파라미터에 값을 전달할 때 2, 0, 3, 1 순으로 주어야 올바른 결과가 나온다(데이터셋은 알파벳 순으로 정렬, 가공한 데이터는 수요 순으로 정렬되었기 때문에 순서가 다르기 때문). 
>
> <img width="440" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/bd9ce7d0-92dc-48f7-bf50-132708871473">

> ### 최종적으로 제작된 모델은 다음과 같다.
> 사용자는 자신이 투자한, 이익을 얻을 수 있는 최소 비용만큼의 `batch size`(기본적으로 1이 기준) 와, `batch size`에 해당하는 각 내용물 `Grass Seed`, `Door Seed`, `Wood Block Seed`, `Glass Pane Seed`의 개수를 알아야 한다.
> 
> ```Python
> First_Pack = ProfitMaximizer(10, 28, 15, 25)
> ```
> 위와 같은 경우 각 내용물의 개수가 10, 28, 15, 25 이며 `First_Pack` 객체는 한 번의 재고 보충을 의미한다고 이해할 수 있으며, `batch size`를 어떻게 정의하느냐에 따라, 재고 보충과 수익 계산을 다르게 할 수 있다. 또 클래스의 메소드를 통해 부수적인 계산도 할 수 있다.
> ```Python
> test_data = [element for pack in test_Data for element in pack]
>
>test_Pack_1 = ProfitMaximizer(test_data[0], test_data[1], test_data[2], test_data[3])
>test_Pack_1.Fit(8)
>
>test_Pack_2 = ProfitMaximizer(test[5], test_data[6], test_data[7], test_data[8])
>test_Pack_2.Fit(8)
>
>test_Pack_3 = ProfitMaximizer(test[9], test_data[10], test_data[11], test_data[12])
>test_Pack_3.Fit(8)
>
>test_Pack_4 = ProfitMaximizer(test[13], test_data[14], test_data[15], test_data[16])
>test_Pack_4.Fit(8)
>
>test_Pack_5 = ProfitMaximizer(test[17], test_data[18], test_data[19], test_data[20])
>test_Pack_5.Fit(8)
> ```
>
> ([test_Data 변수](Data.py))
>
> <img width="725" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/6b900d44-e896-4d2c-a7ab-429231cd2186">
