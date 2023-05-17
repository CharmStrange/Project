#include <stdio.h>
#include "CHARACTERINFO.H"
#include "NAME.H"
#include "CHARACTERSTORY.H"
#include "MONSTERS.H"

attribute Character;

void Init(void){
    char ch;
    char bl;
    
    printf("---------------------------------------------------------------------------------------\nAt first, choose, name your character(you can name your character Random-name or Custom-name).\nThen Read some information of game rule, ... whatever\n");
    printf("\nType alphabet to choose\n[a] : War Hammer\n[b] : War Spear\n[c] : War Blade\n[d] : Dark Magician\n[e] : Holy Magician\n[f] : Elemental_magician\n[g] : Thief\n[h] : Mafia\n:");
    scanf("%s", &ch);
    printf("\n---------------------------------------------------------------------------------------");
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
        
        default:
            printf("\nYou typed wrong number. Default is War Hammer.\n");
            Character=War_hammer;  
            InformationShow(Character);
            break;  
    }
    
    printf("\n\nDefault Character name is Random-name.\n\nBut you can choose.\n\nRandom-name or Custom-name?\n\nType [T] for Random-name or [F] for Custom-name :");
    scanf("%s", &bl);
    switch(bl){
        case 'T':
            RandomName();
            printf("(%s)\n", Character.name);
            break;

        case 'F':
            CustomName();
            printf("(%s)\n", Character.name);
            break;

        default:
            printf("Default is Random-name.");
            RandomName();
            printf("(%s)\n", Character.name);
            break;
    }
}

void Begin(void){
    srand(time(NULL));
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
            Story_Show();
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
