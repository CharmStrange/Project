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

- [<캐릭터 정보와 게임 정보 헤더 파일>](CHARACTERINFO.h)

- [<캐릭터 이름 제작 헤더 파일>](NAME.H)

- [<캐릭터 스토리 정보 헤더 파일>](CHARACTERSTORY.h)

- [[캐릭터 별 스토리 파일]](CharacterStory.zip)

- [*메인 파일*](MAIN.c)


## 1. Main
<img width="445" alt="image" src="https://user-images.githubusercontent.com/105769152/230700799-cf61ddb2-f479-4206-9971-f4e27daf887b.png">
메인 함수를 실행하면 위와 같이 출력된다. 여기서 1, 2, 3 을 입력해 어떤 진행을 할 지 고를 수 있다. 

**1** 은 **게임 시작**, **2** 는 **게임 정보**, **3** 은 **게임 종료** 



<img width="484" alt="image" src="https://user-images.githubusercontent.com/105769152/230700971-2c09ebb4-927a-4dbd-8698-d8ea6d406f2e.png">

1 을 입력하여 게임 시작을 하게되면 캐릭터의 직업을 고를 수 있게 해 두었고 **a** 부터 **h** 까지의 알파벳 하나를 입력하여 직업을 결정한다. 그럼 자동으로 결정된 직업의 정보가 출력된다.



<img width="280" alt="image" src="https://user-images.githubusercontent.com/105769152/230701036-02535537-9041-48bf-9f71-3393ffca39dd.png">

그 후 캐릭터의 이름을 정하는 과정이 진행되며 이때 **무작위**로 이름을 정할지, **사용자 설정**으로 이름을 정할지 선택 가능하게 만들었다. 무작위로 이름을 정했을 때 생성되는 무작위 이름은 총 25 가지이며 사용자 설정으로 이름을 정할 땐 최대 20자 까지 입력이 가능하게끔 해 두었다. 

**T** 를 입력하면 무작위 생성, **F** 를 입력하면 사용자 설정 생성이며 그 이외의 값을 입력했을 경우 그냥 무작위 생성이 진행된다. 



<img width="279" alt="image" src="https://user-images.githubusercontent.com/105769152/230701269-16dbc4d7-4989-47ca-9403-515beb9184b6.png">

*T를 입력했을 때*



<img width="281" alt="image" src="https://user-images.githubusercontent.com/105769152/230701328-f8bc1477-a6a5-4c15-a658-9ab0b57ba68d.png">

*F를 입력했을 때(또는 그 이외의 값 입력시)*


# 
<img width="485" alt="image" src="https://user-images.githubusercontent.com/105769152/230701416-9d4cdd35-9e04-4bfc-b2b0-0106ceeaf518.png">

*( 처음에 2 를 입력시 출력되는 게임 정보 )*



<img width="445" alt="image" src="https://user-images.githubusercontent.com/105769152/230701588-7ee81ec7-bb0b-4d3f-8c36-b28abb1f8037.png">

*( 처음에 3 을 입력시 게임 종료 )*
