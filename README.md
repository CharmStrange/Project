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

먼저 기반 정보들을 **헤더 파일**로 만들어준 뒤 시작 메인 파일에서 불러와 사용한다.

- [<캐릭터 정보와 게임 정보 헤더 파일>](CHARACTERINFO.h)

- [<캐릭터 이름 제작 헤더 파일>](NAME.H)

- [<캐릭터 스토리 정보 헤더 파일>](CHARACTERSTORY.h)

메인 파일
<pre>
#include <stdio.h>
#include "CHARACTERINFO.h"
#include "NAME.h"
#include "CHARACTERSTORY.H"

attribute Character;

void Init(void){
    char ch;
    char bl;
    
    printf("---------------------------------------------------------------------------------------\nAt first, choose, name your character(you can name your character Random-name or Custom-name).\nThen Read some information of game rule, ... whatever\n");
    printf("\nType alphabet to choose\n[a] : War Hammer\n[b] : War Spear\n[c] : War Blade\n[d] : Dark Magician\n[e] : Holy Magician\n[f] : Elemental_magician\n[g] : Thief\n[h] : Mafia\n:");
    scanf("%s", &ch);
    
    switch(ch){
        case 'a':
            Character=War_hammer;
            InformationShow(Character);
            break;

        case 'b':
            Character=War_spear;
            InformationShow(Character);
            break; 

        case 'c':
            Character=War_blade;
            InformationShow(Character);
            break;

        case 'd':
            Character=Dark_magician;
            InformationShow(Character);
            break;

        case 'e':
            Character=Holy_magician;
            InformationShow(Character);
            break;   

        case 'f':
            Character=Elemental_magician;
            InformationShow(Character);
            break; 

        case 'g':
            Character=Thief;
            InformationShow(Character);
            break;  

        case 'h':
            Character=Mafia;
            InformationShow(Character);
            break;        
    }
    
    printf("\n\nDefault Character name is Random-name.\nBut you can choose.\nRandom-name or Custom-name?\nType [T] for Random-name or [F] for Custom-name :");
    scanf("%s", &bl);
    switch(bl){
        case 'T':
            RandomName();
            printf("(%s)", Character.name);
            break;

        case 'F':
            CustomName();
            printf("(%s)", Character.name);
            break;

        default:
            printf("Default is Random-name.");
            RandomName();
            printf("(%s)", Character.name);
            break;
    }
}

void Begin(void){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
 
    printf("Time : [%d-%d-%d %d:%d:%d]\n---------------------------------------------------------------------------------------", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("\nThis is text Role Playing Game(RPG). Make your own character and start the game.\n");
}

void On(void){
    int type;
    printf("\n1. Game Start \n2. Information \n3. Exit");
    printf("\n\nType Number : ");
    scanf("%d", &type);
    
    switch(type){
        case 1:
            Init();
            break;
        case 2:
            Information();
            break;
        case 3:
        printf("program exit...");
            exit(0);
            break;
        default:
        printf("You typed wrong number. Game will be started.");
        Init();
    }
}

int main(){
    Begin();
    On();
    return 0;
}
</pre>
