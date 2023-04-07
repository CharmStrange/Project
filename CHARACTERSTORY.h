#ifndef CHARACTERSTORY_H
# define CHARACTERSTORY_H

# include <stdio.h>

# define _CRT_SECURE_NO_WARNINGS
# define MAX 2500

// 스토리 파일 보여주는 함수
void Warhammer_Story(void){
    FILE* fp = fopen("Warhammer.txt", "r");  
    char buffer[MAX] = { 0, };
    fread(buffer, 1, MAX, fp); 
    printf("\n%s", buffer);
    fclose(fp); 
}

void Warspear_Story(void){
    FILE* fp = fopen("Warspear.txt", "r");  
    char buffer[MAX] = { 0, };
    fread(buffer, 1, MAX, fp); 
    printf("\n%s", buffer);
    fclose(fp); 
}

void Warblade_Story(void){
    FILE* fp = fopen("Warblade.txt", "r"); 
    char buffer[MAX] = { 0, };
    fread(buffer, 1, MAX, fp); 
    printf("\n%s", buffer);
    fclose(fp); 
}

void Darkmagician_Story(void){
    FILE* fp = fopen("Darkmagician.txt", "r");  
    char buffer[MAX] = { 0, };
    fread(buffer, 1, MAX, fp); 
    printf("\n%s", buffer);
    fclose(fp); 
}

void Holymagician_Story(void){
    FILE* fp = fopen("Holymagician.txt", "r");  
    char buffer[MAX] = { 0, };
    fread(buffer, 1, MAX, fp); 
    printf("\n%s", buffer);
    fclose(fp); 
}

void Elementalmagician_Story(void){
    FILE* fp = fopen("Elementalmagician.txt", "r");  
    char buffer[MAX] = { 0, };
    fread(buffer, 1, MAX, fp); 
    printf("\n%s", buffer);
    fclose(fp); 
}

void ThiefStory(void){
    FILE* fp = fopen("Thief.txt", "r"); 
    char buffer[MAX] = { 0, };
    fread(buffer, 1, MAX, fp); 
    printf("\n%s", buffer);
    fclose(fp); 
}

void MafiaStory(void){
    FILE* fp = fopen("Mafia.txt", "r");  
    char buffer[MAX] = { 0, };
    fread(buffer, 1, MAX, fp); 
    printf("\n%s", buffer);
    fclose(fp);
}

#endif