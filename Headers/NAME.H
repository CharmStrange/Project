#ifndef NAME_H
# define NAME_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define ARRAYSIZE 5 

// 랜덤한 이름으로 캐릭터 생성하기
void RandomName(void){
    const char *NameSpace_1[ARRAYSIZE];
    NameSpace_1[0]="Naive";
    NameSpace_1[1]="Clumsy";
    NameSpace_1[2]="Master";
    NameSpace_1[3]="Mysterious";
    NameSpace_1[4]="Fascinating";
   
    const char *NameSpace_2[ARRAYSIZE];
    NameSpace_2[0]="James";
    NameSpace_2[1]="Jack";
    NameSpace_2[2]="Wu";
    NameSpace_2[3]="Lilia";
    NameSpace_2[4]="Chritine";
   
    printf("Welcome, %s %s", NameSpace_1[(rand()%6)-1], NameSpace_2[(rand()%6)-1]);
}

// 직접 입력받은 이름으로 캐릭터 생성하기
void CustomName(void){
    char NameSpace[21];
    
    printf("\nType Your Name(Max 20) : ");
    scanf("%s", NameSpace);
    
    printf("\nWelcome, %s", NameSpace);
}

#endif
