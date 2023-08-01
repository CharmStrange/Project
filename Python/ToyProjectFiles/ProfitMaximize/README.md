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
