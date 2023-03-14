#define _CRT_SECURE_NO_WARNINGS 
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_RESET    "\x1b[0m"
#define SIZE 100
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>
int count_check = 0;
typedef struct {
	char user_name[20];
	char phone_num[20];
	char password[20];
}user;
user all[SIZE];
typedef struct {
	char user_name[20];
	int seat_num;
	int year;
	int mon;
	int day;
	int hour;
	int min;
}seat;
seat user_seat[SIZE];
void gotoxy(int x, int y);
int login();
int shelf_life_check(int year, int mon, int day, int hour, int min);
int time_remove();
int member_start();
int manger_insert_ui_1();
int manager_login();
int manager_insert_ui();
int manager_remove_seat();
int member_mange();
int sales_check();
int sales();
int manager();
int member_insert_ui_2();
int member_insert_ui();
int seat_ui();
int	seat_usufruct_ui();
int seat_check_2(int check);
int seat_see();
int id_pass_check(char* phone_num, char* password);
int membership();
int password_find();
int append_time(int index, int year, int mon, int day, int hour, int min);
int period_usufruct_time(char* choice_price, int index);
int time_usufruct_time(char* choice_price, int index);
int seat_usufruct(int index);
int enter(int index, int seat_num);
int user_seat_check(int index);
int seat_same_check(int seat_num);
int seat_choice(int index);
int period_see(int index);
int remove_seat(int index);
int login_success(int index);
void member_file_read();
void file_append();

int main(void) {
	member_start();
}
int id_pass_check(char* phone_num, char* password) { //유효한 전화번호인지 또는 비밀번호인지 확인하는 함수//

	int phone_len = 0;
	int password_len = 0;
	phone_len = strlen(phone_num);
	password_len = strlen(password);
	if (phone_len == 11) {
		if (password_len == 4) {
			return 1;
		}
		else {
			return 2;
		}
	}
	else {
		return 2;
	}
}
void gotoxy(int x, int y) {
	//x, y 좌표 설정
	COORD pos = { x,y };
	//커서 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void file_append() {
	FILE* member;
	FILE* chair_seat;
	member = fopen("member.txt", "a");
	chair_seat = fopen("seat.txt", "a");
	fprintf(member, "\n%s %s %s ", all[count_check].user_name, all[count_check].phone_num, all[count_check].password);
	fprintf(chair_seat, "\n%s %d %d/%d/%d/%d/%d", user_seat[count_check].user_name, user_seat[count_check].seat_num, user_seat[count_check].year, user_seat[count_check].mon, user_seat[count_check].day, user_seat[count_check].hour, user_seat[count_check].min);
	fclose(member);
	fclose(chair_seat);
}
void member_file_read() {
	FILE* member;
	if (member == NULL)
		return 0;
	while (1) {
		fscanf(member, "%s %s %s ", all[count_check].user_name, all[count_check].phone_num, all[count_check].password);
		if (feof(member) != 0);
		break;
		count_check++;
	}
	fclose(member);
}
int member_start() { //회원 초기화면  
	int num = 0;
	while (1) {
		member_file_read();
		system("cls");
		gotoxy(20, 3);
		gotoxy(42, 4);
		printf("스터디카페 프로그램");
		gotoxy(45, 7);
		printf("메뉴입력:");
		gotoxy(45, 18);
		printf("1.회원가입");
		gotoxy(45, 23);
		printf("2.로그인");
		gotoxy(45, 28);
		printf("3.비밀번호 찾기");
		gotoxy(45, 33);
		printf("4.관리자 모드");
		gotoxy(54, 7);
		scanf("%d", &num);
		if (num == 1) {
			system("cls");
			Sleep(1000);
			membership();
			continue;
		}
		else if (num == 2) {
			system("cls");
			Sleep(1000);
	
			continue;
		}
		else if (num == 3) {
			system("cls");
			Sleep(1000);
		
			continue;
		}
		else if (num == 4) {
			system("cls");
			Sleep(1000);
		}
		else if (num == 5) {
			system("cls");
			Sleep(1000);
			break;
		}

	}
}
int membership() {//회원가입 함수//
	int num = 0;
	int count = 0;
	char name[20] = "";
	char phone_num[20] = "";
	char password[20] = "";
	while (1) {
		system("cls");
		gotoxy(20, 3);
		gotoxy(48, 5);
		printf("회원가입");
		gotoxy(30, 12);
		printf("이름 입력 : ");
		gotoxy(30, 20);
		printf("전화번호(11자리) 입력 : ");
		gotoxy(30, 30);
		printf("비밀번호(4자리) 입력 : ");
		gotoxy(42, 12);
		scanf("%s", name);
		gotoxy(53, 20);
		scanf("%s", phone_num);
		gotoxy(52, 30);
		scanf("%s", password);
		num = id_pass_check(phone_num, password);
		if (num == 1) {
			for (int k = 0; k < count_check; k++) {
				if (strcmp(all[k].phone_num, phone_num) == 0) {
					count = 1;
					break;
				}
			}
			if (count == 1) {
				gotoxy(38, 45);
				printf("이미 가입된 전화번호입니다");
				Sleep(1000);
				break;
			}
			strcpy(all[count_check].user_name, name);
			strcpy(all[count_check].phone_num, phone_num);
			strcpy(all[count_check].password, password);
			strcpy(user_seat[count_check].user_name, name);
			user_seat[count_check].year = 0;
			user_seat[count_check].seat_num = 0;
			user_seat[count_check].mon = 0;
			user_seat[count_check].day = 0;
			user_seat[count_check].hour = 0;
			user_seat[count_check].min = 0;
			file_append();
			break;
		}
		else {
			gotoxy(38, 45);
			printf("형식이 올바르지 않습니다 ");
			Sleep(1000);
			continue;
		}
		gotoxy(35, 45);
		printf("회원가입이 완료 되었습니다!!!");
		Sleep(1000);
		break;
	}

}



