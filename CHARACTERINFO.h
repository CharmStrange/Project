#ifndef CHARACTERINFO_H
# define CHARACTERINFO_H

#include<stdio.h>
#include <string.h>

#define SIZE 20

typedef unsigned int LV;
typedef struct {
    char name[SIZE];
    LV level;
    float attack;
    unsigned int speed;
    float defense;
    int intelligence;
    int luck;
}attribute;

attribute War_hammer = {
    "WarHammer",
    1,
    23.0,
    19,
    32.0,
    8,
    7
};

attribute War_spear = {
    "WarSpear",
    1,
    26.0,
    21,
    16.0,
    10,
    7
};

attribute War_blade = {
    "WarBlade",
    1,
    24.0,
    20,
    21.0,
    9,
    6
};

attribute Dark_magician = {
    "Dark Magician",
    1,
    28.0,
    4,
    5.0,
    33,
    13
};

attribute Holy_magician = {
    "Holy Magician",
    1,
    18.0,
    7,
    6.0,
    29,
    20
};

attribute Elemental_magician = {
    "Elemental Magician",
    1,
    25.0,
    6,
    7.0,
    32,
    14
};

attribute Thief = {
    "Thief",
    1,
    8.0,
    32,
    6.0,
    25,
    28
};

attribute Mafia = {
    "Mafia",
    1,
    23.0,
    20,
    20.0,
    21,
    15
};

void InformationShow(attribute character){
    printf("\nCharacter Class : %s\n", character.name);
    printf("Level of Character : %d\n", character.level);
    printf("Attack Power of Character: %f\n", character.attack);
    printf("Speed of Character: %d\n", character.speed);
    printf("Defense Capability of Character: %f\n", character.defense);
    printf("intelligence of Character: %d\n", character.intelligence);
    printf("Luckness of Character : %d\n", character.luck);
}

#endif