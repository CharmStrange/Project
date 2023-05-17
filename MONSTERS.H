#ifndef MONSTERS_H
# define MONSTERS_H

# include <stdio.h>
# include <stdlib.h>
//# include <time.h>

# define level_1 1
# define level_2 2
# define level_3 3
# define level_0 0
# define SIZE 15

typedef unsigned int LV;

typedef struct {
    char name[31];
    LV level;
    float attack;
    unsigned int speed;
    float defense;
}Monster;
//
Monster Monster_LV1[SIZE]={
    // 0~14
    {"Rat", level_1, 2.0, 7, 0},
    {"Giant Worm", level_1, 0.0, 1, 0},
    {"Venom Spider", level_1, 9.0, 0, 0},
    {"Centipede", level_1, 6.0, 8, 1},
    {"Ladybugs", level_1, 1.0, 1, 1},
    {"\"Bad-Positron\"", level_1, 5.0, 5, 2},
    {"\"Bad-Negatron\"", level_1, 5.0, 5, 2},
    {"Light of Metal", level_1, 3.0, 10, 10},
    {"Abandoned Mop", level_1, 2.0, 0, 0},
    {"Ghoul", level_1, 3.0, 3, 4},
    {"Broken Blade", level_1, 3.0, 0, 0},
    {"Wasp", level_1, 5.0, 7, 3},
    {"Spirit of Water", level_1, 3.0, 3, 3},
    {"Spirit of Fire", level_1, 3.0, 3, 3},
    {"Spirit of Wind", level_1, 3.0, 3, 3}
};

Monster Monster_LV2[SIZE]={
    // 0~14
    {"Metalic Blade", level_2, 6.0, 7, 3},
    {"\'Movement of Things\'", level_2, 1.0, 1, 1   },
    {"Dragonfly", level_2, 1.0, 10, 4},
    {"Monkey", level_2, 6.0, 7, 5},
    {"Dragon Gecko", level_2, 5.0, 8, 1},
    {"\'The Unknown\'", level_2, 3.0, 3, 3},
    {"Poisonous Dust", level_2, 7.0, 0, 0},
    {"Crazy Dog", level_2, 7.0, 8, 5},
    {"Moving Doll", level_2, 0.0, 10, 0},
    {"Giant Cockroach", level_2, 3.0, 10, 4},
    {"Parts of Thunder", level_2, 6.0, 11, 0},
    {"Mysterious Magic Stick", level_2, 2.0, 20, 0},
    {"Visible Radio Waves", level_2, 3.0, 3, 3},
    {"Smart Snail", level_2, 2.0, 1, 3},
    {"Land Shrimp", level_2, 2.0, 3, 6}
};

Monster Monster_LV3[SIZE]={
    // 0~14
    {"Giant Chaco Frog", level_3, 6.0, 3, 8},
    {"Spoiled Plankton", level_3, 10.0, 1, 0},
    {"Veteran Cat", level_3, 9.0, 9, 8},
    {"Aggressive Rat", level_3, 7.0, 5, 3},
    {"Screaming Cicada", level_3, 4.0, 5, 2},
    {"\"Diabolic-Positron\"", level_3, 10.0, 10, 10},
    {"\"Diabolic-Negatron\"", level_3, 10.0, 10, 10},
    {"Countless Radiation", level_3, 7.0, 0, 20},
    {"\'Two Eyes\'", level_3, 22.0, 1, 0},
    {"Smart Zombie", level_3, 6.0, 13, 12},
    {"Teared Old Page", level_3, 1.0, 100, 0},
    {"Contaminated Butterfly", level_3, 9.0, 12, 0},
    {"Omega Spirit of Water", level_3, 30.0, 30, 30},
    {"Omega Spirit of Fire", level_3, 30.0, 30, 30},
    {"Omega Spirit of Wind", level_3, 30.0, 30, 30}
};

Monster Monster_Special[SIZE]={
    // 0~14
    {"Shadow", level_0, 0, 0, 0}, // characters
    {"Afterimage of Time", level_0, 0, 0, 0}, 
    {"Abstarct Fear", level_0, 0, 0, 0},
    {"Unknown Member", level_0, 0, 0, 0},
    {"Light", level_0, 0, 0, 0}, // positron, negatron
    {"Call of \'High Being\'", level_0, 0, 0, 0},
    {"Head", level_0, 0, 0, 0}, // eyes
    {"Echo of Invisible", level_0, 0, 0, 0},
    {"Radiation Substance", level_0, 0, 0, 0}, //
    {"Friendly Dog", level_0, 0, 0, 0},
    {"Swarm of Rats", level_0, 0, 0, 0},
    {"A Clown", level_0, 0, 0, 0},
    {"Memory of Place", level_0, 0, 0, 0},
    {"Fog", level_0, 0, 0, 0},
    {"A Shabby Door", level_0, 0, 0, 0}
};
//
void Trial1(Monster Monster){ // eleiminate
    int r1=rand()%10;
    int r2=rand()%10;
    if(Monster.level==0) {printf("\nBut you could not attack %s. Because you overwhelmed by <%s>. %s passed you silently.\n", Monster.name, Monster.name, Monster.name);}
    else if ( (Monster.level + Monster.attack + Monster.speed + Monster.defense/r1) > r2 ) {printf("\nYou attacked %s! But it was too strong. %s ran away.\n", Monster.name, Monster.name);}
    else {printf("\nYou attacked %s! And you annulled %s.\n", Monster.name, Monster.name);}
} 

void Trial2(Monster Monster){ // favor
    int n;
    n=rand()%3;
    
    switch(n) {
        case 0:
            printf("\n%s did not want to be friend! %s disappeared.\n", Monster.name, Monster.name);
            break;
        case 1:
            printf("\n%s ignored you! You felt not good. %s disappeared.\n", Monster.name, Monster.name);
            break;
        case 2:
            printf("\n%s was benevolent! You and %s became friend.", Monster.name, Monster.name);
            //
            break;
        
    }
}

void Trial3(Monster Monster){ // not to see
    int n;
    n=rand()%3;
    
    switch(n) {
        case 0:
            printf("\nYou tried to ignore %s. But %s followed you and you hid. It was successful.\n", Monster.name, Monster.name);
            break;
        case 1:
            printf("\nYou tried to ignore %s. %s ignored you, too.\n", Monster.name, Monster.name);
            break;
        case 2:
            printf("\n%s watched you endlessly. You felt creepy and avoided the gaze.\n", Monster.name);
            break;
        
    }
} 

void Trial4(Monster Monster){ // run
    printf("\nYou successfully ran away from %s.\n", Monster.name);
} 

void RandomSimulate(){ //srand(time(NULL)); 하고 rand()%3 으로 0 1 2 switch
    int n, m;
    int i;
    char j;
    n=rand()%4; 
    m=rand()%3;
    i=rand()%15;
    switch(n){
        case 0:
            printf("\n---------------------------------------------------------------------------------------");
            printf("\nYou found %s. ", Monster_LV1[i].name);
            switch(m){
                case 0:
                    printf("You tried to approach %s, but it ran away.\n", Monster_LV1[i].name);
                    break;
                case 1:
                    printf("You sensed something strange and left the place.\n");
                    break;
                case 2:
                    printf("It approaches you. What are you going to do?\n[a] : Eliminate it.\n[b] : Be friendly with favor.\n[c] : Pretend not to see\n[d] : Runaway\n");
                    scanf("%s", &j);
                    switch(j){
                         case 'a':
                            printf("\nYou tried to eliminate it.\n");
                            Trial1(Monster_LV1[i]);
                            break;

                         case 'b':
                            printf("\nYou tried to get favor of it.\n");  
                            Trial2(Monster_LV1[i]);
                            break; 

                         case 'c':
                            printf("\nYou tried to pretend not to see.\n");
                            Trial3(Monster_LV1[i]);
                            break;

                         case 'd':
                            printf("\nYou tried to run.\n");
                            Trial4(Monster_LV1[i]);
                            break;
                        
                        default:
                            printf("\nYou did not see anything. You left the place.\n");
                            break;
                    }
                    break;
            }
            printf("\n---------------------------------------------------------------------------------------");
            //Monster_LV1[i];
            break;

        case 1:
            printf("\n---------------------------------------------------------------------------------------");
            printf("\nYou found %s. ", Monster_LV2[i].name);
            switch(m){
                case 0:
                    printf("You tried to approach %s, but it ran away.\n", Monster_LV2[i].name);
                    break;
                case 1:
                    printf("You sensed something strange and left the place.\n");
                    break;
                case 2:
                    printf("It approaches you. What are you going to do?\n[a] : Eliminate it.\n[b] : Be friendly with favor.\n[c] : Pretend not to see\n[d]:Runaway\n");
                    scanf("%s", &j);
                    switch(j){
                         case 'a':
                            printf("\nYou tried to eliminate it.\n");
                            Trial1(Monster_LV2[i]);
                            break;

                         case 'b':
                            printf("\nYou tried to get favor of it.\n");  
                            Trial2(Monster_LV2[i]);
                            break; 

                         case 'c':
                            printf("\nYou tried to pretend not to see.\n");
                            Trial3(Monster_LV2[i]);
                            break;

                         case 'd':
                            printf("\nYou tried to run.\n");
                            Trial4(Monster_LV2[i]);
                            break;
                        
                        default:
                            printf("\nYou did not see anything. You left the place.\n");
                            break;
                    }
                    break;
            }
            printf("\n---------------------------------------------------------------------------------------");
            //Monster_LV2[i];
            break;

        case 2:
            printf("\n---------------------------------------------------------------------------------------");
            printf("\nYou found %s. ", Monster_LV3[i].name);
            switch(m){
                case 0:
                    printf("You tried to approach %s, but it ran away.\n", Monster_LV3[i].name);
                    break;
                case 1:
                    printf("You sensed something strange and left the place.\n");
                    break;
                case 2:
                    printf("It approaches you. What are you going to do?\n[a] : Eliminate it.\n[b] : Be friendly with favor.\n[c] : Pretend not to see\n[d]:Runaway\n");
                    scanf("%s", &j);
                    switch(j){
                         case 'a':
                            printf("\nYou tried to eliminate it.\n");
                            Trial1(Monster_LV3[i]);
                            break;

                         case 'b':
                            printf("\nYou tried to get favor of it.\n");  
                            Trial2(Monster_LV3[i]);
                            break; 

                         case 'c':
                            printf("\nYou tried to pretend not to see.\n");
                            Trial3(Monster_LV3[i]);
                            break;

                         case 'd':
                            printf("\nYou tried to run.\n");
                            Trial4(Monster_LV3[i]);
                            break;
                        
                        default:
                            printf("\nYou did not see anything. You left the place.\n");
                            break;
                    }
                    break;
            }
            printf("\n---------------------------------------------------------------------------------------");
            //Monster_LV3[i];
            break;
        // n 이 4인 경우
        default:
            printf("\n---------------------------------------------------------------------------------------");
            printf("\nYou found %s. ", Monster_Special[i].name);
            switch(m){
                case 0:
                    printf("You tried to approach %s, but it ran away.\n", Monster_Special[i].name);
                    break;
                case 1:
                    printf("You sensed something strange and left the place.\n");
                    break;
                case 2:
                    printf("It approaches you. What are you going to do?\n[a] : Eliminate it.\n[b] : Be friendly with favor.\n[c] : Pretend not to see\n[d] : Runaway\n");
                    scanf("%s", &j);
                    switch(j){
                         case 'a':
                            printf("\nYou tried to eliminate it.\n");
                            Trial1(Monster_Special[i]);
                            break;

                         case 'b':
                            printf("\nYou tried to get favor of it.\n");  
                            Trial2(Monster_Special[i]);
                            break; 

                         case 'c':
                            printf("\nYou tried to pretend not to see.\n");
                            Trial3(Monster_Special[i]);
                            break;

                         case 'd':
                            printf("\nYou tried to run.\n");
                            Trial4(Monster_Special[i]);
                            break;
                        
                        default:
                            printf("\nYou did not see anything. You left the place.\n");
                            break;
                    }
                    break;
            }
            printf("\n---------------------------------------------------------------------------------------");
            //Monster_Special[i];
            break;
            
    }
}

#endif