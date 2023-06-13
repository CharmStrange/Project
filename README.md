# C Game Making(Text based RPG)
텍스트 기반 고전 Role-Playing-Game 을 좋아하는 편인데, 특히 명령 프롬프트 창과 같은 터미널 배경에서 플레이하는게 좋았다. 그래서 그 느낌을 살려볼 수 있게 C 언어로 제작을 해 보기로 했다. 
- - -
### [ 진행 과정도 ]
- ① *게임의 시작 부분과 기반 정보들 제작.*
- ② *게임의 진행 구조와 스토리 제작.*
- ③ *게임의 마무리 부분과 엔딩 제작.*
- ④ *코드 다듬기 및 최적화의 마무리 작업.*
- - -
### ① *게임의 시작 부분과 기반 정보들 제작하기.*

먼저 기반 정보들을 **헤더 파일**로 만들어준 뒤 시작 **메인 파일**에서 불러와 사용한다.

- [<캐릭터 정보와 게임 정보 헤더 파일>](Headers/CHARACTERINFO.H)

- [<캐릭터 이름 제작 헤더 파일>](Headers/NAME.H)

- [<캐릭터 스토리 정보 헤더 파일>](Headers/CHARACTERSTORY.H)

- [<엔티티, 이벤트 헤더 파일>](Headers/MONSTERS.H)

- [*메인 파일*](MAIN.c)


## 1. Main
<img width="445" alt="image" src="https://user-images.githubusercontent.com/105769152/230700799-cf61ddb2-f479-4206-9971-f4e27daf887b.png">
메인 함수를 실행하면 위와 같이 출력된다. 여기서 1, 2, 3 을 입력해 어떤 진행을 할 지 고를 수 있다. 

**1** 은 **게임 시작**, **2** 는 **게임 정보**, **3** 은 **게임 종료** 



<img width="484" alt="image" src="https://user-images.githubusercontent.com/105769152/230700971-2c09ebb4-927a-4dbd-8698-d8ea6d406f2e.png">

1 을 입력하여 게임 시작을 하게되면 캐릭터의 직업을 고를 수 있게 해 두었고 **a** 부터 **h** 까지의 알파벳 하나를 입력하여 직업을 결정한다. 그럼 자동으로 결정된 직업의 정보가 출력된다.



<img width="483" alt="image" src="https://user-images.githubusercontent.com/105769152/230922096-71aafa5c-2322-4751-aaed-dbe22c81e95a.png">

그 후 캐릭터의 이름을 정하는 과정이 진행되며 이때 **무작위**로 이름을 정할지, **사용자 설정**으로 이름을 정할지 선택 가능하게 만들었다. 무작위로 이름을 정했을 때 생성되는 무작위 이름은 총 25 가지이며 사용자 설정으로 이름을 정할 땐 최대 20자 까지 입력이 가능하게끔 해 두었다. 

**T** 를 입력하면 무작위 생성, **F** 를 입력하면 사용자 설정 생성이며 그 이외의 값을 입력했을 경우 그냥 무작위 생성이 진행된다. 



<img width="283" alt="image" src="https://user-images.githubusercontent.com/105769152/230922231-2336f58a-673e-4dae-8144-9f7a714cd21c.png">

*T를 입력했을 때*



<img width="283" alt="image" src="https://user-images.githubusercontent.com/105769152/230922396-699c2a9b-3043-4551-87c1-0585d94b48b0.png">

*F를 입력했을 때(또는 그 이외의 값 입력시)*


# 
<img width="485" alt="image" src="https://user-images.githubusercontent.com/105769152/230701416-9d4cdd35-9e04-4bfc-b2b0-0106ceeaf518.png">
<img width="294" alt="image" src="https://user-images.githubusercontent.com/105769152/230922512-fe15cfa6-64d8-4b40-8355-9a28ba9e75c2.png">
<img width="488" alt="image" src="https://user-images.githubusercontent.com/105769152/230922608-82a21d9a-92ee-4b63-a169-8a39dd0e654c.png">


*( 처음에 2 를 입력시 출력되는 게임 정보와 캐릭터(또는 직업)별  )*



<img width="445" alt="image" src="https://user-images.githubusercontent.com/105769152/230701588-7ee81ec7-bb0b-4d3f-8c36-b28abb1f8037.png">

*( 처음에 3 을 입력시 게임 종료 )*
