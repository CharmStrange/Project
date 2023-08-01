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
> ->[데이터셋](https://github.com/CharmStrange/Project/blob/main/Python/ToyProjectFiles/PackAnalysis/PackData.py)<- 을 기반으로, 1 batch 당 내용물의 평균 수를 구한 뒤 모델의 파라미터에 넣어준다.
> ```Python
># 시세 변수
>High = 50
>Middle = 100
>Middle_Low = 150
>Low = 200
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
>        print(f"Grass Seed : {GR_r}\n")
>        print(f"Door Seed : {D_r}\n")
>        print(f"Wood Block Seed : {W_r}\n")
>        print(f"Glass Pane Seed : {GL_r}\n")
> ```
> ```Python
> test = ProfitMaximizer(18, 27, 22, 25)
> test.Fit(11)
> test.remain(9)
> ```
> <img width="294" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/d1d9ec41-94ed-4a7f-833f-e95121165f5f">
>
> 현재 나머지를 구하는 메소드의 추가 수정이 필요한 상태이다.
