#ifndef CHARACTERINFO_H
# define CHARACTERINFO_H

# include<stdio.h>
# include <string.h>

# define SIZE 20

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
    24,
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

void Information(void){
    printf("# # # # #\nGame Information\n");
    printf("[...]\n"); // 자세한 설명 추가

    printf("\nRole Information");
    printf("\nWarHammer is a powerful character who wields a mighty hammer as his weapon.\nHis incredible strength makes him a formidable opponent in any battle.\nGet ready to crush your enemies with WarHammer's signature hammer and dominate the game.");
    printf("\n# # #\nWarSpear is a nimble character who utilizes a deadly spear as his weapon.\nHis lightning-fast movements make him a difficult target to hit, and his precise strikes with the spear can take down even the most evasive opponents.\nTake on any challenge with WarSpear's lethal spear by your side in the game.");
    printf("\n# # #\nWarBlade is a balanced and powerful character who wields a deadly blade as his weapon.\nHis impressive physical strength, agility, and precision with the blade make him a formidable opponent in any battle.\nWith WarBlade's razor-sharp blade and well-rounded skills, you can take on any challenge and emerge victorious in the game.");
    printf("\n# # #\nDark Magician is a mean and clever character who specializes in dark magic as his weapon.\nHis devious strategies and dark powers make him a formidable opponent in any battle.\nWith Dark Magician's mastery of the dark arts, you can defeat even the toughest opponents in the game.\nBut beware, for his powers may come with a price.");
    printf("\n# # #\nHoly Magician is a smart and lucky character who specializes in holy magic as his weapon.\nHis quick thinking and powerful spells make him a valuable asset in any battle.\nWith Holy Magician's mastery of holy magic, you can turn the tide of any battle and emerge victorious in the game.\nBut be careful not to underestimate his opponents, for luck can only take you so far.");
    printf("\n# # #\nElemental Magician is a strategic and precise character who specializes in natural elemental magic as his weapon.\nHis mastery of the elements and precise spellcasting make him a valuable asset in any battle.\nWith Elemental Magician's ability to harness the power of nature, you can outmaneuver and overpower your opponents in the game.\nBut be sure to use his powers wisely, for the elements can be unpredictable and dangerous in the wrong hands.");
    printf("\n# # #\nThief is a strategic and smart character who specializes in using various tools as his weapons.\nHis nimble movements and quick reflexes make him a formidable opponent in any battle.\nWith Thief' s mastery of various tools and strategic thinking, you can outsmart and outmaneuver your opponents in the game.\nBut beware, for his opponents might have tricks up their sleeves too.");
    printf("\n# # #\nMafia is a dark and dangerous character who specializes in using firearms as his weapons.\nHis strength and agility make him a formidable opponent in any battle.\nWith Mafia's mastery of firearms and combat, you can take on even the toughest opponents in the game.\nBut be warned, for Mafia's ruthlessness and cunning make him a dangerous enemy to cross.\n\n");
    
    printf("Build Information\n");
    printf("[...]\n# # # # #"); // 자세한 설명 추가
}

#endif