#include<stdio.h>
#include<Windows.h>
#include <conio.h> //_getch�� ���ԵǾ��ִ� ���

int main(void) {
    int c;

   
        c = _getch(); //�Է°� input
        printf("�Է� �� : %d\n", c); //�Է°� ���

    return 0;
}