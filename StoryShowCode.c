#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#define MAX 2000
// 현재 시각과 게임 시작시 출력되는 문구 제작
void Begin(void){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
 
    printf("%d-%d-%d %d:%d:%d\n", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("\nThis is TEXT Role Playing Game.");
}
// 스토리 파일 보여주는 함수
void StoryFile(void){
    FILE* fp = fopen("Story.txt", "r");  //test파일을 r(읽기) 모드로 열기
    char buffer[MAX] = { 0, };

    fread(buffer, 1, MAX, fp); //전체 읽기
    printf("\n%s", buffer);

    fclose(fp); //파일 포인터 닫기
}

int main(void){
    //Begin();
    StoryFile();
    
    return 0;
}