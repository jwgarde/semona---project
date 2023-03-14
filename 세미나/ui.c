#include<stdio.h>
#include<Windows.h>
#include <conio.h> //_getch가 포함되어있는 헤더

int main(void) {
    int c;

   
        c = _getch(); //입력값 input
        printf("입력 값 : %d\n", c); //입력값 출력

    return 0;
}