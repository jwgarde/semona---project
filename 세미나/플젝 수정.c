#define _CRT_SECURE_NO_WARNINGS 
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_RESET    "\x1b[0m"
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>
void gotoxy(int x, int y) {
	//x, y 좌표 설정
	COORD pos = { x,y };
	//커서 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int member_insert_ui_2() {
	int x = 20;
	int y = 3;
	printf("┏");
	for (int i = 0; i < 60; i++)
	{
		printf("━");
	}
	printf("┓");
	for (int i = 0; i < 46; i++) {
		y += 1;
		gotoxy(x, y);
		printf("┃                                                            ┃\n");
		if (i == 2) {
			gotoxy(x, y);
			printf("┣");
			for (int i = 0; i < 30; i++) {
				printf(" ━");
			}
			printf("┫");
		}
	}
	gotoxy(x, y + 1);
	printf("┗");
	for (int i = 0; i < 60; i++)
	{
		printf("━");
	}
	printf("┛");
}
int member_insert_ui() {
	int x = 20;
	int y = 3;
	printf("┏");
	for (int i = 0; i < 60; i++)
	{
		printf("━");
	}
	printf("┓");
	for (int i = 0; i < 45; i++) {
		y += 1;
		gotoxy(x, y);
		printf("┃                                                            ┃\n");
		if (i == 1) {
			gotoxy(x, y);
			printf("┣");
			for (int i = 0; i < 30; i++) {
				printf(" ━");
			}
			printf("┫");
		}
		else if (i == 5) {
			gotoxy(x, y);
			printf("┣");
			for (int i = 0; i < 30; i++) {
				printf(" ━");
			}
			printf("┫");
		}
	}
	gotoxy(x, y + 1);
	printf("┗");
	for (int i = 0; i < 60; i++)
	{
		printf("━");
	}
	printf("┛");
}
int seat_ui() {
	printf("\n\n\n\t   ");
	printf("┏");
	for (int i = 0; i < 80; i++)
	{
		printf("━");
	}
	printf("┓\n");
	for (int i = 0; i < 45; i++) {

		printf("           ┃                                                                                ┃\n");

	}
	printf("\t   ┗");
	for (int i = 0; i < 80; i++)
	{
		printf("━");
	}
	printf("┛");
}
int	seat_usufruct_ui() {
	printf("\t┏");
	for (int i = 0; i < 46; i++)
	{
		printf("━");
	}
	printf("┓\n");
	printf("\t┃\t\t                 \t       ┃\n");
	printf("\t┗");
	for (int i = 0; i < 46; i++)
	{
		printf("━");
	}
	printf("┛");
	printf("\n\n\t    ");
	printf("┏");
	for (int i = 0; i < 38; i++)
	{
		printf("━");
	}
	printf("┓\n");
	for (int i = 0; i < 10; i++) {
		if (i == 4) {
			printf("\t    ┃                                      ┃\n");
		}
		else if (i == 8) {
			printf("\t    ┃                                      ┃\n");
		}
		else {
			printf("\t    ┃\t\t\t                   ┃\n");
		}
	}
	printf("\t    ┗");
	for (int i = 0; i < 38; i++)
	{
		printf("━");
	}
	printf("┛");
}
int seat_check_2(int check) {
	FILE* chair_seat;
	chair_seat = fopen("seat.txt", "r");
	typedef struct {
		char user_name[20];
		int seat_num;
		int year;
		int mon;
		int day;
		int hour;
		int min;
	}seat;
	seat user_seat[100];
	int count = 0;
	for (int i = 0; i < 100; i++) {
		strcpy(user_seat[i].user_name, "");
		user_seat[i].seat_num = 0;
		user_seat[i].year = 0;
		user_seat[i].mon = 0;
		user_seat[i].day = 0;
		user_seat[i].hour = 0;
		user_seat[i].min = 0;
		fscanf(chair_seat, "%s %d %d/%d/%d/%d/%d", user_seat[i].user_name, &user_seat[i].seat_num, &user_seat[i].year, &user_seat[i].mon, &user_seat[i].day, &user_seat[i].hour, &user_seat[i].min);
	}
	fclose(chair_seat);
	for (int i = 0; i < 100; i++) {
		if (strcmp(user_seat[i].user_name, "") != 0) {
			if (user_seat[i].seat_num == check) {
				count = 1;
				break;
			}
		}
	}
	return count;
}
int seat_see() {
	int seat[11][12] = {
	{50,1,2,3,4,5,6,7,8,9,10,50},{11,50,50,50,50,50,50,50,50,50,50,12},{13,50,50,50,50,50,50,50,50,50,50,14},
	{15,50,50,50,50,50,50,50,50,50,50,16},{17,50,50,31,32,33,34,35,50,50,50,18},{19,50,50,50,50,50,50,50,50,50,50,20},
	{21,50,50,36,37,38,39,40,50,50,50,22},{23,50,50,50,50,50,50,50,50,50,50,24},{25,50,50,50,50,50,50,50,50,50,50,26},
	{27,50,50,50,50,50,50,50,50,50,50,28},{29,50,50,50,50,50,50,50,50,50,50,30}
	};
	int check = 0;
	int x = 16;
	int y = 5;
	for (int i = 0; i < 11; i++) {
		x = 16;
		gotoxy(x, y);
		for (int j = 0; j < 12; j++) {
			
			if (seat[i][j] != 50) {
				check = seat_check_2(seat[i][j]);
				gotoxy(x, y);
				if (check == 1) {
					printf(ANSI_COLOR_YELLOW);
					printf("┌");
					for (int i = 0; i < 3; i++)
					{
						printf("-");
					}
					printf("┐");
					gotoxy(x, y + 1);
					printf("ㅣ%02dㅣ", seat[i][j]);
					gotoxy(x, y + 2);
					printf("└");
					for (int i = 0; i < 3; i++)
					{
						printf("-");
					}
					printf("┘"ANSI_COLOR_RESET);
				}
				else {
					printf("┌");
					for (int i = 0; i < 3; i++)
					{
						printf("-");
					}
					printf("┐");
					gotoxy(x, y + 1);
					printf("ㅣ%02dㅣ", seat[i][j]);
					gotoxy(x, y + 2);
					printf("└");
					for (int i = 0; i < 3; i++)
					{
						printf("-");
					}
					printf("┘");
				}
			}
			else {
				if (i == 4 || i == 6) {
					printf("");
				} 
				else {
					printf(" ");
				}
			}
			x += 6;
		}
		y += 4;
		
	}
	

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
int membership(){//회원가입 함수//
	int num = 0;
	int count = 0;
	int sec = 0;
	int person_count = 0;
	typedef struct {
		char user_name[20];
		char phone_num[20];
		char password[20];
	}user;

	typedef struct {
		char user_name[20];
		int seat_num;
		int year;
		int mon;
		int day;
		int hour;
		int min;
	}seat;
	user all[100];
	seat user_seat[100];
	FILE* member;
	FILE* chair_seat;
	member = fopen("member.txt", "r");
	for (int i = 0; i < 100; i++) {
		strcpy(all[i].user_name, "");
		strcpy(all[i].phone_num, "");
		strcpy(all[i].password, "");
		strcpy(user_seat[i].user_name, "");
		fscanf(member, "%s %s %s ", all[i].user_name, all[i].phone_num, all[i].password);
	}
	char name[20] = "";
	char phone_num[20] = "";
	char password[20] = "";

	while (1) {
		system("cls");
		gotoxy(20, 3);
		member_insert_ui_2();
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
			for (int k = 0; k < 100; k++) {
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
			for (int i = 0; i < 100; i++) {
				if (strcmp(all[i].user_name, "") == 0) {
					strcpy(all[i].user_name, name);
					strcpy(all[i].phone_num, phone_num);
					strcpy(all[i].password, password);
					strcpy(user_seat[i].user_name, name);
					user_seat[i].year = 0;
					user_seat[i].seat_num = 0;
					user_seat[i].mon = 0;
					user_seat[i].day = 0;
					user_seat[i].hour = 0;
					user_seat[i].min = 0;
					member = fopen("member.txt", "a");
					chair_seat = fopen("seat.txt", "a");
					fprintf(member, "\n%s %s %s ", all[i].user_name, all[i].phone_num, all[i].password);
					fprintf(chair_seat, "\n%s %d %d/%d/%d/%d/%d", user_seat[i].user_name, user_seat[i].seat_num, user_seat[i].year, user_seat[i].mon, user_seat[i].day, user_seat[i].hour, user_seat[i].min);
					fclose(member);
					fclose(chair_seat);
					break;
				}

			}

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
int password_find() { //비밀번호 찾는 함수//
	FILE* member;
	int num = 0;
	int count = 0;
	int sec = 0;
	int person_count = 0;
	typedef struct {
		char user_name[20];
		char phone_num[20];
		char password[20];
	}user;
	user all[100];
	member = fopen("member.txt", "r");
	for (int i = 0; i < 100; i++) {
		strcpy(all[i].user_name, "");
		strcpy(all[i].phone_num, "");
		strcpy(all[i].password, "");
		fscanf(member, "%s %s %s", all[i].user_name, all[i].phone_num, all[i].password);
	}
	char name[20] = "";
	char phone_num[20] = "";
	char password[20] = "";
	while (1) {
		system("cls");
		gotoxy(20, 3);
		member_insert_ui_2();
		gotoxy(45, 4);
		printf("비밀번호 찾기");
		gotoxy(30, 17);
		printf("이름 : ");
		gotoxy(30, 27);
		printf("전화번호(11자리) 입력 : ");
		gotoxy(37, 17);
		scanf("%s",name);
		getchar();
		gotoxy(54, 27);
		scanf("%s", phone_num);

		for (int i = 0; i < 100; i++) {
			if (strcmp(name, all[i].user_name) == 0 && strcmp(phone_num, all[i].phone_num) == 0) {
				gotoxy(40, 43);
				printf("비밀번호는 %s입니다", all[i].password);
				count = 0;
				Sleep(1000);
				break;
			}
			else {
				count = 1;
			}
		}
		if (count == 1) {
			gotoxy(43, 43);
			printf("찾을 수 없습니다");
			Sleep(3000);
			system("cls");
			system("cls");
			gotoxy(20, 3);
			member_insert_ui();
			gotoxy(45, 4);
			printf("비밀번호 찾기");
			gotoxy(47, 7);
			printf("메뉴입력:");
			gotoxy(46, 20);
			printf("1.다시시도");
			gotoxy(46, 30);
			printf("2.돌아가기");
			gotoxy(56, 7);
			scanf("%d", &num);
			if (num == 1) {
				Sleep(1000);
				continue;
			}
			if (num == 2) {
				Sleep(1000);
				break;
			}
		}
		break;
	}
}
int append_time(int index, int year, int mon, int day, int hour, int min) { // 인덱스 연 월 일 시 분 가져와서 인덱스에 맞는 사용자 찾아서 날짜에 맞게 시간 추가 후 종료 기간 파일에 입력
	FILE* chair_seat;
	chair_seat = fopen("seat.txt", "r");
	typedef struct {
		char user_name[20];
		int seat_num;
		int year;
		int mon;
		int day;
		int hour;
		int min;
	}seat;
	seat user_seat[100];
	for (int i = 0; i < 100; i++) {
		strcpy(user_seat[i].user_name, "");
		user_seat[i].seat_num = 0;
		user_seat[i].year = 0;
		user_seat[i].mon = 0;
		user_seat[i].day = 0;
		user_seat[i].hour = 0;
		user_seat[i].min = 0;
		fscanf(chair_seat, "%s %d %d/%d/%d/%d/%d", user_seat[i].user_name, &user_seat[i].seat_num, &user_seat[i].year, &user_seat[i].mon, &user_seat[i].day, &user_seat[i].hour, &user_seat[i].min);
	}
	fclose(chair_seat);
	user_seat[index].year = year;
	user_seat[index].mon = mon;
	user_seat[index].day = day;
	user_seat[index].hour = hour;
	user_seat[index].min = min;
	chair_seat = fopen("seat.txt", "w");	
	for (int i = 0; i < 100; i++) {
		if (strcmp(user_seat[i].user_name, "") != 0) {
			fprintf(chair_seat, "\n%s %d %d/%d/%d/%d/%d", user_seat[i].user_name, user_seat[i].seat_num, user_seat[i].year, user_seat[i].mon, user_seat[i].day, user_seat[i].hour, user_seat[i].min);
		}
	}
	fclose(chair_seat);
	gotoxy(42, 45);
	printf("결제가 완료되었습니다");
	Sleep(1000);
}
int period_usufruct_time(char* choice_price,int index){//기간제 이용가능 날짜 계산하는 함수 
	int year = 0;
	int mon = 0;
	int day = 0;
	int hour = 0;
	int min = 0;
	int pay = 0;
	FILE* sales_check;
	FILE* chair_seat;
	chair_seat = fopen("seat.txt", "r");
	typedef struct {
		char user_name[20];
		int seat_num;
		int year;
		int mon;
		int day;
		int hour;
		int min;
	}seat;
	seat user_seat[100];
	for (int i = 0; i < 100; i++) {
		strcpy(user_seat[i].user_name, "");
		user_seat[i].seat_num = 0;
		user_seat[i].year = 0;
		user_seat[i].mon = 0;
		user_seat[i].day = 0;
		user_seat[i].hour = 0;
		user_seat[i].min = 0;
		fscanf(chair_seat, "%s %d %d/%d/%d/%d/%d", user_seat[i].user_name, &user_seat[i].seat_num, &user_seat[i].year, &user_seat[i].mon, &user_seat[i].day, &user_seat[i].hour, &user_seat[i].min);
	}
	fclose(chair_seat);
	time_t timer;
	struct tm* t;
	timer = time(NULL); 
	t = localtime(&timer);
	if (user_seat[index].year != 0) {
		year = user_seat[index].year;
		mon = user_seat[index].mon;
		day = user_seat[index].day;
		hour = user_seat[index].hour;
		min = user_seat[index].min;
		if (strcmp(choice_price, "7d") == 0) {
			day += 7;
			pay = 30000;
		}
		else if (strcmp(choice_price, "14d") == 0) {
			day += 14;
			pay = 50000;
		}
		else if (strcmp(choice_price, "30d") == 0) {
			day += 30;
			pay = 90000;
		}

	}
	if (user_seat[index].year == 0) {
		year = t->tm_year + 1900;
		mon = t->tm_mon + 1;
		day = t->tm_mday;
		hour = t->tm_hour;
		min = t->tm_min;
		if (strcmp(choice_price, "7d") == 0) {
			day += 7;
			pay = 30000;
		}
		else if (strcmp(choice_price, "14d") == 0) {
			day += 14;
			pay = 50000;
		}
		else if (strcmp(choice_price, "30d") == 0) {
			day += 30;
			pay = 90000;
		}

	}
	if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12) {
		if (day > 31) {
			day -= 31;
			mon += 1;
		}
	}
	if (mon == 4 || mon == 6 || mon == 9 || mon == 11) {
		if (day > 30) {
			day -= 30;
			mon += 1;
		}
	}
	if (mon == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			if (day > 29) {
				day -= 29;
				mon += 1;
			}
		}
		else {
			if (day > 28) {
				day -= 28;
				mon += 1;
			}
		}
	}
	if (mon > 12) {
		year += 1;
		mon = 1;
	}
	sales_check = fopen("sales_check.txt", "a");
	fprintf(sales_check, "\n%s %d/%d/%d/%d/%d %d",user_seat[index], t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min,pay);
	fclose(sales_check);

	append_time(index, year, mon, day, hour, min);
}
int time_usufruct_time(char* choice_price,int index){ //시간제 이용가능 날짜 계산하는 함수
	int year = 0;
	int mon = 0;
	int day = 0;
	int hour = 0;
	int min = 0;
	int pay = 0;
	FILE* sales_check;
	FILE* chair_seat;
	chair_seat = fopen("seat.txt", "r");
	typedef struct {
		char user_name[20];
		int seat_num;
		int year;
		int mon;
		int day;
		int hour;
		int min;
	}seat;
	seat user_seat[100];
	for (int i = 0; i < 100; i++) {
		strcpy(user_seat[i].user_name, "");
		user_seat[i].seat_num = 0;
		user_seat[i].year = 0;
		user_seat[i].mon = 0;
		user_seat[i].day = 0;
		user_seat[i].hour = 0;
		user_seat[i].min = 0;
		fscanf(chair_seat, "%s %d %d/%d/%d/%d/%d", user_seat[i].user_name, &user_seat[i].seat_num, &user_seat[i].year, &user_seat[i].mon, &user_seat[i].day, &user_seat[i].hour, &user_seat[i].min);
	}
	fclose(chair_seat);
	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);
	if (user_seat[index].year == 0) {
		year = t->tm_year + 1900;
		mon = t->tm_mon + 1;
		day = t->tm_mday;
		min = t->tm_min;
		if (strcmp(choice_price, "1t") == 0) {
			hour = t->tm_hour + 1;
			pay = 2000;
		}
		else if (strcmp(choice_price, "3t") == 0) {
			hour = t->tm_hour + 3;
			pay = 3000;
		}
		else if (strcmp(choice_price, "6t") == 0) {
			hour = t->tm_hour + 6;
			pay = 6000;
		}
	}
	if(user_seat[index].year != 0) {
		year = user_seat[index].year;
		mon = user_seat[index].mon;
		day = user_seat[index].day;
		hour = user_seat[index].hour;
		min = user_seat[index].min; 
		if (strcmp(choice_price, "1t") == 0) {
			hour += 1;
			pay = 2000;
		}
		else if (strcmp(choice_price, "3t") == 0) {
			hour += 3;
			pay = 3000;
		}
		else if (strcmp(choice_price, "6t") == 0) {
			hour += 6;
			pay = 6000;
		}
	}
	if (hour >= 24) {
		hour -= 24;
		day += 1;
	}
	if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 ||mon ==10 || mon == 12) {
		if (day > 31) {
			day -= 31;
			mon += 1;
		}
	}
	if (mon == 4 || mon == 6 || mon == 9 || mon == 11) {
		if (day > 30) {
			day -= 30;
			mon += 1;
		}
	}
	if (mon == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			if (day > 29) {
				day -= 29;
				mon += 1;
			}
		}
		else {
			if (day > 28) {
				day -= 28;
				mon += 1;
			}
		}
	}
	if (mon > 12) {
		year += 1;
		mon = 1;
	}
	sales_check = fopen("sales_check.txt", "a");
	fprintf(sales_check, "\n%s %d/%d/%d/%d/%d %d", user_seat[index], t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, pay);
	fclose(sales_check);
	append_time(index, year, mon, day, hour, min);
}
int seat_usufruct(int index){//이용권 구매 함수//
	Sleep(1000);
	system("cls");
	char phone_num[11] = "";
	char choice_price[10] = "";
	while (1) {
		system("cls");
		gotoxy(20, 3);
		member_insert_ui();
		gotoxy(45, 7);
		printf("요금입력:");
		gotoxy(47, 4);
		printf("이용권 구매");
		gotoxy(49, 18);
		printf("기간제");
		gotoxy(35, 21);
		printf("7d:30000원  14d:50000원  30d:90000원");
		gotoxy(49, 30);
		printf("시간제");
		gotoxy(35, 33);
		printf("1t:2000원    3t:3000원    6t:6000원");
		gotoxy(54, 7);
		scanf("%s",choice_price);;
		if (strcmp(choice_price, "7d") == 0 || strcmp(choice_price, "14d") == 0 || strcmp(choice_price, "30d") == 0) {
			period_usufruct_time(choice_price, index);
		}	
		else if (strcmp(choice_price, "1t") == 0 || strcmp(choice_price, "3t") == 0 || strcmp(choice_price, "6t") == 0) {
			time_usufruct_time(choice_price, index);
		}
		else {
			gotoxy(43, 45);
			printf("다시 입력해주세요");
			Sleep(1000);
			continue;
		}
		break;
	}
}
int enter(int index, int seat_num) { //입실하는 함수
	char choice[10] = "";
	FILE* chair_seat;
	chair_seat = fopen("seat.txt", "r");
	typedef struct {
		char user_name[20];
		int seat_num;
		int year;
		int mon;
		int day;
		int hour;
		int min;
	}seat;
	seat user_seat[100];
	for (int i = 0; i < 100; i++) {
		strcpy(user_seat[i].user_name, "");
		user_seat[i].seat_num = 0;
		user_seat[i].year = 0;
		user_seat[i].mon = 0;
		user_seat[i].day = 0;
		user_seat[i].hour = 0;
		user_seat[i].min = 0;
		fscanf(chair_seat, "%s %d %d/%d/%d/%d/%d", user_seat[i].user_name, &user_seat[i].seat_num, &user_seat[i].year, &user_seat[i].mon, &user_seat[i].day, &user_seat[i].hour, &user_seat[i].min);
	}
	fclose(chair_seat);
	if (user_seat[index].year == 0) {
		gotoxy(20, 3);
		member_insert_ui_2();
		gotoxy(49, 4);
		printf("입실");
		gotoxy(35, 17);
		printf("회원 이름 : %s", user_seat[index].user_name);
		gotoxy(35, 25);
		printf("이용권 종료 일자 : 이용권이 없습니다");
		gotoxy(40, 38);
		printf("이용권을 구매해주세요");
		Sleep(1000);
		login_success(index);
	}
	else {
		while (1) {
			system("cls");
			gotoxy(20, 3);
			member_insert_ui();
			gotoxy(49, 4);
			printf("입실");
			gotoxy(35, 20);
			printf("회원 이름 : %s", user_seat[index].user_name);
			gotoxy(35, 28);
			printf("이용권 종료 일자 : %d/%d/%d/%d/%d", user_seat[index].year, user_seat[index].mon, user_seat[index].day, user_seat[index].hour, user_seat[index].min);
			gotoxy(35, 36);
			printf("좌석번호 : %d", seat_num);
			gotoxy(37, 7);
			printf("입실하시겠습니까?(y or n) : ");
			gotoxy(65,7);
			scanf("%s",choice);
			if (strcmp(choice,"y")==0) {
				user_seat[index].seat_num = seat_num;
				chair_seat = fopen("seat.txt", "w");
				for (int i = 0; i < 100; i++) {
					if (strcmp(user_seat[i].user_name, "") != 0) {
						fprintf(chair_seat, "\n%s %d %d/%d/%d/%d/%d", user_seat[i].user_name, user_seat[i].seat_num, user_seat[i].year, user_seat[i].mon, user_seat[i].day, user_seat[i].hour, user_seat[i].min);
					}
				}
				fclose(chair_seat);
				gotoxy(40, 42);
				printf("입실이 완료되었습니다");
				Sleep(1000);
				break;
			}
			else if (strcmp(choice, "n") == 0) {
				login_success(index);
			}
			else {
				gotoxy(43, 42);
				printf("다시 입력해주세요");
				Sleep(1000);
				continue;
			}
		}
	}
}
int user_seat_check(int index) { //이미 이용중인 좌석이 있는지 확인하는 함수
	char choice[10] = "";
	FILE* chair_seat;
	chair_seat = fopen("seat.txt", "r");
	typedef struct {
		char user_name[20];
		int seat_num;
		int year;
		int mon;
		int day;
		int hour;
		int min;
	}seat;
	seat user_seat[100];
	for (int i = 0; i < 100; i++) {
		strcpy(user_seat[i].user_name, "");
		user_seat[i].seat_num = 0;
		user_seat[i].year = 0;
		user_seat[i].mon = 0;
		user_seat[i].day = 0;
		user_seat[i].hour = 0;
		user_seat[i].min = 0;
		fscanf(chair_seat, "%s %d %d/%d/%d/%d/%d", user_seat[i].user_name, &user_seat[i].seat_num, &user_seat[i].year, &user_seat[i].mon, &user_seat[i].day, &user_seat[i].hour, &user_seat[i].min);
	}
	fclose(chair_seat);
	if (user_seat[index].seat_num != 0) {
		while (1) {
			system("cls");
			gotoxy(20, 3);
			member_insert_ui();
			gotoxy(47, 4);
			printf("좌석변경");
			gotoxy(35, 20);
			printf("회원 이름 : %s", user_seat[index].user_name);
			gotoxy(35, 28);
			printf("이용권 종료 일자 : %d/%d/%d/%d/%d", user_seat[index].year, user_seat[index].mon, user_seat[index].day, user_seat[index].hour, user_seat[index].min);
			gotoxy(35, 36);
			printf("좌석 : %d번", user_seat[index].seat_num);
			gotoxy(32, 7);
			printf("좌석을 변경하시겠습니까?(y or n) : ");
			scanf("%s", choice);
			if (strcmp(choice, "n") == 0) {
				system("cls");
				login_success(index);
			}
			else if (strcmp(choice, "y") == 0) {
				system("cls");
				break;
			}
			else {
				gotoxy(43, 42);
				printf("다시 입력해주세요");
				Sleep(3000);
				continue;
			}
		}
	}
}
int seat_same_check(int seat_num) {
	FILE* chair_seat;
	chair_seat = fopen("seat.txt", "r");
	typedef struct {
		char user_name[20];
		int seat_num;
		int year;
		int mon;
		int day;
		int hour;
		int min;
	}seat;
	seat user_seat[100];
	int count = 0;
	for (int i = 0; i < 100; i++) {
		strcpy(user_seat[i].user_name, "");
		user_seat[i].seat_num = 0;
		user_seat[i].year = 0;
		user_seat[i].mon = 0;
		user_seat[i].day = 0;
		user_seat[i].hour = 0;
		user_seat[i].min = 0;
		fscanf(chair_seat, "%s %d %d/%d/%d/%d/%d", user_seat[i].user_name, &user_seat[i].seat_num, &user_seat[i].year, &user_seat[i].mon, &user_seat[i].day, &user_seat[i].hour, &user_seat[i].min);
	}
	fclose(chair_seat);
	for (int i = 0; i < 100; i++) {
		if (user_seat[i].seat_num == seat_num) {
			count = 1;
		}
	}
	return count;

}
int seat_choice(int index) {
	int seat_num = 0;
	int count = 0;
	
	user_seat_check(index);
	system("cls");
		seat_ui();
		seat_see();
		gotoxy(96, 3);
		manager_insert_ui();
		gotoxy(124, 4);
		printf("좌석선택");
		gotoxy(114, 7);
		printf("원하시는 좌석입력 : ");
		while (1) {
		gotoxy(22, 4);
		printf("");
		gotoxy(134, 7);
		printf("   ");
		gotoxy(134, 7);
		scanf("%d", &seat_num);
		if (seat_num > 0 && seat_num < 41) {
			count = seat_same_check(seat_num);
			if (count == 1) {
				gotoxy(117, 27);
				printf("이용중인 좌석입니다.");
				Sleep(1000);
				gotoxy(117, 27);
				printf("                                   ");
				continue;
			}
			else {
				gotoxy(113, 27);
				printf("좌석 선택이 완료 되었습니다");
				Sleep(1000);
				system("cls");
				enter(index, seat_num);
				break;

			}
		}
		else {
			gotoxy(116, 27);
			printf("다시 입력해주세요");
			Sleep(500);
			gotoxy(115, 27);
			printf("                                     ");
			continue;
		}
	}
}
int period_see(int index) {//로그인 했을때 이용권 종료일자 보여주는 함수
	FILE* chair_seat;
	chair_seat = fopen("seat.txt", "r");
	typedef struct {
		char user_name[20];
		int seat_num;
		int year;
		int mon;
		int day;
		int hour;
		int min;
	}seat;
	seat user_seat[100];
	for (int i = 0; i < 100; i++) {
		strcpy(user_seat[i].user_name, "");
		user_seat[i].seat_num = 0;
		user_seat[i].year = 0;
		user_seat[i].mon = 0;
		user_seat[i].day = 0;
		user_seat[i].hour = 0;
		user_seat[i].min = 0;
		fscanf(chair_seat, "%s %d %d/%d/%d/%d/%d", user_seat[i].user_name, &user_seat[i].seat_num, &user_seat[i].year, &user_seat[i].mon, &user_seat[i].day, &user_seat[i].hour, &user_seat[i].min);
	}
	fclose(chair_seat);
	gotoxy(35, 20);
	printf("회원 이름 :     %s\n\n", user_seat[index].user_name);
	if (user_seat[index].year == 0) {
		gotoxy(35, 28);
		printf("이용권 종료일자:이용권이 없습니다");
	}
	else {
		gotoxy(35, 28);
		printf("이용권 종료일자 : %d/%d/%d/%d:%d", user_seat[index].year, user_seat[index].mon, user_seat[index].day, user_seat[index].hour, user_seat[index].min);
	}
	if (user_seat[index].seat_num == 0) {
		gotoxy(35, 36);
		printf("좌석 : 이용중인 좌석이 없습니다");
	}
	else {
		gotoxy(35, 36);
		printf("좌석 : %d번", user_seat[index].seat_num);
	}
}
int remove_seat(int index) { //퇴실
	char choice[10] = "";
	FILE* chair_seat;
	chair_seat = fopen("seat.txt", "r");
	typedef struct {
		char user_name[20];
		int seat_num;
		int year;
		int mon;
		int day;
		int hour;
		int min;
	}seat;
	seat user_seat[100];
	int count = 0;
	for (int i = 0; i < 100; i++) {
		strcpy(user_seat[i].user_name, "");
		user_seat[i].seat_num = 0;
		user_seat[i].year = 0;
		user_seat[i].mon = 0;
		user_seat[i].day = 0;
		user_seat[i].hour = 0;
		user_seat[i].min = 0;
		fscanf(chair_seat, "%s %d %d/%d/%d/%d/%d", user_seat[i].user_name, &user_seat[i].seat_num, &user_seat[i].year, &user_seat[i].mon, &user_seat[i].day, &user_seat[i].hour, &user_seat[i].min);
	}
	fclose(chair_seat);
	if (user_seat[index].seat_num != 0) {
		while (1) {
			system("cls");
			gotoxy(20, 3);
			member_insert_ui();
			gotoxy(49, 4);
			printf("퇴실");
			gotoxy(35, 20);
			printf("회원 이름 : %s", user_seat[index].user_name);
			gotoxy(35, 28);
			printf("이용권 종료 일자 : %d/%d/%d/%d/%d", user_seat[index].year, user_seat[index].mon, user_seat[index].day, user_seat[index].hour, user_seat[index].min);
			gotoxy(35, 36);
			printf("좌석 : %d번", user_seat[index].seat_num);
			gotoxy(37, 7);
			printf("퇴실하시겠습니까??(y or n) : ");
			gotoxy(65, 7);
			scanf("%s",choice);
			if (strcmp(choice, "y") == 0) {
				user_seat[index].seat_num = 0;
				chair_seat = fopen("seat.txt", "w");
				for (int i = 0; i < 100; i++) {
					if (strcmp(user_seat[i].user_name, "") != 0) {
						fprintf(chair_seat, "\n%s %d %d/%d/%d/%d/%d", user_seat[i].user_name, user_seat[i].seat_num, user_seat[i].year, user_seat[i].mon, user_seat[i].day, user_seat[i].hour, user_seat[i].min);
					}
				}
				fclose(chair_seat);
				gotoxy(37, 42);
				printf("퇴실처리가 완료되었습니다");
				Sleep(2000);
				member_start();
				break;
			}
			else if (strcmp(choice, "n") == 0) {
				Sleep(2000);
				break;
			}
			else {
				gotoxy(43, 42);
				printf("다시 입력해주세요");
				Sleep(2000);
				continue;
			}
		}
		
	}
	else {
		system("cls");
		gotoxy(20, 3);
		member_insert_ui();
		gotoxy(49, 4);
		printf("퇴실");
		gotoxy(35, 20);
		printf("회원 이름 : %s", user_seat[index].user_name);
		gotoxy(35, 28);
		printf("이용권 종료 일자 : %d/%d/%d/%d/%d", user_seat[index].year, user_seat[index].mon, user_seat[index].day, user_seat[index].hour, user_seat[index].min);
		gotoxy(35, 36);
		printf("좌석 : %d번", user_seat[index].seat_num);
		gotoxy(38, 7);
		printf("이용중이신 좌석이 없습니다");
		Sleep(2000);
	}
}
int login_success(int index){ //로그인 성공시//
	int num = 0;
	while (1) {
		system("cls");
		gotoxy(20, 3);
		member_insert_ui();
		gotoxy(45, 7);
		printf("메뉴입력:");
		period_see(index);
		gotoxy(25, 4);
		printf("1.좌석 이용권 구매  2. 자리선택  3.퇴실  4.로그아웃 ");
		gotoxy(54, 7);
		scanf("%d",&num);
		if (num == 1) {
			seat_usufruct(index);
			continue;
		}
		else if (num == 2) {
			seat_choice(index);
			break;
		}
		else if (num == 3) {
			remove_seat(index);
		}
		else if (num == 4) {
			Sleep(1000);
			member_start();
			break;
		}
	}
} 
int login() { // 로그인 하는 함수
	FILE* member;
	int num = 0;
	int count = 0;
	member = fopen("member.txt", "r");
	typedef struct {
		char user_name[20];
		char phone_num[20];
		char password[20];

	}user;
	user all[100];
	for (int i = 0; i < 100; i++) {
		strcpy(all[i].user_name, "");
		strcpy(all[i].phone_num, "");
		strcpy(all[i].password, "");
		fscanf(member, "%s %s %s", all[i].user_name, all[i].phone_num, all[i].password);

	}
	char name[20] = "";
	char phone_num[20] = "";
	char password[20] = "";
	char choice_price[10] = "";
	int index = 0;
	while (1) {
		system("cls");
		gotoxy(20, 3);
		member_insert_ui_2();
		gotoxy(49, 4);
		printf("로그인");
		gotoxy(30, 17);
		printf("전화번호(11자리) 입력 : ");
		gotoxy(30, 27);
		printf("비밀번호(4자리) 입력 : ");
		gotoxy(54, 17);
		scanf("%s", phone_num);
		gotoxy(53, 27);
		for (int k = 0; k < 4; k++) {
			
			password[k] = _getch();
			printf("*");
		}
		for (int i = 0; i < 100; i++) {
			if (strcmp(phone_num, all[i].phone_num) == 0 && strcmp(password, all[i].password) == 0) {
				count = 1;
				index = i;
				break;
			}
			else {
				count = 2;
			}
		}
		if (count == 1) {
			Sleep(1000);
			gotoxy(45, 45);
			printf("로그인 성공 !!");
			Sleep(1000);
			login_success(index);
			break;
		}
		else {
			gotoxy(35, 45);
			printf("일치하는 전화번호 혹은 비밀번호를 \n");
			gotoxy(43, 46);
			printf("찾을수 없습니다.");
			Sleep(1000);
			system("cls");
			gotoxy(20, 3);
			member_insert_ui();
			gotoxy(48, 4);
			printf("로그인");
			gotoxy(47, 7);
			printf("메뉴입력:");
			gotoxy(46, 20);
			printf("1.다시시도");
			gotoxy(46, 30);
			printf("2.돌아가기");
			gotoxy(56, 7);
			scanf("%d", &num);
			if (num == 1) {
				Sleep(1000);
				continue;
			}
			if (num == 2) {
				Sleep(1000);
				break;
			}
		}
	}
} 
int shelf_life_check(int year, int mon, int day, int hour, int min) {//이용권 종료일자랑 현재시간이랑 비교 해서 지나면 1 안 지났으면 0

	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);
	if (t->tm_year+1900 > year) {
		return 1;
	}
	else if (t->tm_year+1900 == year) {
		if (t->tm_mon + 1 < mon) {
			return 0;
		}
		else if (t->tm_mon + 1 == mon) {
			if (t->tm_mday < day) {
				return 0;
			}
			else if(t->tm_mday == day){
				if (t->tm_hour < hour) {
					return 0;
				}
				else if (t->tm_hour == hour) {
					if (t->tm_min < min) {
						return 0;
					}
					else {
						return 1;
					}
				}
				else {
					return 1;
				}
			}
			else {
				return 1;
			}
		}
		else {
			return 1;
		}
	}
	else if (t->tm_year + 1900 < year) {
		return 0;
	}
}
int time_remove() { // 이용권 사용 기간이이 지났으면 0으로 초기화 하는 함수 
	int result = 0;
	FILE* chair_seat;
	chair_seat = fopen("seat.txt", "r");
	typedef struct {
		char user_name[20];
		int seat_num;
		int year;
		int mon;
		int day;
		int hour;
		int min;
	}seat;
	seat user_seat[100];
	for (int i = 0; i < 100; i++) {
		strcpy(user_seat[i].user_name, "");
		user_seat[i].seat_num = 0;
		user_seat[i].year = 0;
		user_seat[i].mon = 0;
		user_seat[i].day = 0;
		user_seat[i].hour = 0;
		user_seat[i].min = 0;
		fscanf(chair_seat, "%s %d %d/%d/%d/%d/%d", user_seat[i].user_name, &user_seat[i].seat_num, &user_seat[i].year, &user_seat[i].mon, &user_seat[i].day, &user_seat[i].hour, &user_seat[i].min);
		if (strcmp(user_seat[i].user_name, "") != 0) {
			if(user_seat[i].year != 0) {
				result = shelf_life_check(user_seat[i].year, user_seat[i].mon, user_seat[i].day, user_seat[i].hour, user_seat[i].min);
				if (result == 1) {
					user_seat[i].year = 0;
					user_seat[i].mon = 0;
					user_seat[i].day = 0;
					user_seat[i].hour = 0;
					user_seat[i].min = 0;
					user_seat[i].seat_num = 0;

				}
				
			}
		}
	
	}
	fclose(chair_seat);
	chair_seat = fopen("seat.txt", "w");
	for (int i = 0; i < 100; i++) {
		if (strcmp(user_seat[i].user_name, "") != 0) {
			fprintf(chair_seat, "\n%s %d %d/%d/%d/%d/%d", user_seat[i].user_name, user_seat[i].seat_num, user_seat[i].year, user_seat[i].mon, user_seat[i].day, user_seat[i].hour, user_seat[i].min);
		}
	}
	fclose(chair_seat);
}
int member_start() { //회원 초기화면  
	int num = 0;
	while (1) {
		time_remove();
		system("cls");
		gotoxy(20, 3);
		member_insert_ui();
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
		scanf("%d",&num);
		if (num == 1) {
			system("cls");
			Sleep(1000);
			membership();
			continue;
		}
		else if (num == 2) {
			system("cls");
			Sleep(1000);
			login();
			continue;
		}
		else if (num == 3) {
			system("cls");
			Sleep(1000);
			password_find();
			continue;
		}
		else if (num == 4) {
			system("cls");
			Sleep(1000);
			manager_login();
		}
		else if(num == 5){
			system("cls");
			Sleep(1000);
			break;
		}

	}
}
//관리자
int manger_insert_ui_1() {
	int x = 85;
	int y = 3;
	gotoxy(x, y);
	printf("┏");
	for (int i = 0; i < 60; i++)
	{
		printf("━");
	}
	printf("┓");
	for (int i = 0; i < 45; i++) {
		y += 1;
		gotoxy(x, y);
		printf("┃                                                            ┃\n");
		if (i == 1) {
			gotoxy(x, y);
			printf("┣");
			for (int i = 0; i < 30; i++) {
				printf(" ━");
			}
			printf("┫");
		}
		else if (i == 5) {
			gotoxy(x, y);
			printf("┣");
			for (int i = 0; i < 30; i++) {
				printf(" ━");
			}
			printf("┫");
		}
	}
	gotoxy(x, y + 1);
	printf("┗");
	for (int i = 0; i < 60; i++)
	{
		printf("━");
	}
	printf("┛");
}
int manager_login() {
	int num = 0;
	char id[20] = "01073555364";
	char id_2[20] = "";
	char password_2[20] = "";
	char password[20] = "5364";
	while (1) {
		gotoxy(22, 4);
		printf("");
		system("cls");
		gotoxy(20, 3);
		member_insert_ui();
		gotoxy(37, 4);
		printf("1.관리자 로그인");
		gotoxy(55, 4);
		printf("2.돌아가기");
		gotoxy(45, 7);
		printf("메뉴입력:");
		gotoxy(54, 7);
		scanf("%d", &num);
		if (num == 1) {
			gotoxy(30, 17);
			printf("전화번호(11자리) 입력 : ");
			gotoxy(30, 27);
			printf("비밀번호(4자리) 입력 : ");
			gotoxy(54, 17);
			scanf("%s", id_2);
			gotoxy(53, 27);
			for (int k = 0; k < 4; k++) {

				password_2[k] = _getch();
				printf("*");
			}
			if (strcmp(id, id_2) == 0) {
				if (strcmp(password, password_2) == 0) {
					gotoxy(45, 45);
					printf("로그인 성공 !!");
					Sleep(1000);
					manager();
					break;
				}
				else {
					gotoxy(30, 45);
					printf("전화번호 혹은 비밀번호가 일치하지 않습니다.");
					Sleep(1500);
					continue;
				}
			}
			else {
				gotoxy(30, 45);
				printf("전화번호 혹은 비밀번호가 일치하지 않습니다.");
				Sleep(1500);
				continue;
			}
		}
		else if (num == 2) {
			break;
		}
	}

}
int manager_insert_ui() {
	int x = 96;
	int y = 3;
	printf("┏");
	for (int i = 0; i < 60; i++)
	{
		printf("━");
	}
	printf("┓");
	for (int i = 0; i < 45; i++) {
		y += 1;
		gotoxy(x, y);
		printf("┃                                                            ┃\n");
		if (i == 1) {
			gotoxy(x, y);
			printf("┣");
			for (int i = 0; i < 30; i++) {
				printf(" ━");
			}
			printf("┫");
		}
		else if (i == 5) {
			gotoxy(x, y);
			printf("┣");
			for (int i = 0; i < 30; i++) {
				printf(" ━");
			}
			printf("┫");
		}
	}
	gotoxy(x, y + 1);
	printf("┗");
	for (int i = 0; i < 60; i++)
	{
		printf("━");
	}
	printf("┛");
}
int manager_remove_seat() {
	int num = 0;
	int seat_num = 0;
	char name[20] = "";
	int year = 0;
	int mon = 0;
	int day = 0;
	int hour = 0;
	int min = 0;
	char choice[2] = "";
	FILE* chair_seat;
	chair_seat = fopen("seat.txt", "r");
	typedef struct {
		char user_name[20];
		int seat_num;
		int year;
		int mon;
		int day;
		int hour;
		int min;
	}seat;
	seat user_seat[100];
	for (int i = 0; i < 100; i++) {
		strcpy(user_seat[i].user_name, "");
		user_seat[i].seat_num = 0;
		user_seat[i].year = 0;
		user_seat[i].mon = 0;
		user_seat[i].day = 0;
		user_seat[i].hour = 0;
		user_seat[i].min = 0;
		fscanf(chair_seat, "%s %d %d/%d/%d/%d/%d", user_seat[i].user_name, &user_seat[i].seat_num, &user_seat[i].year, &user_seat[i].mon, &user_seat[i].day, &user_seat[i].hour, &user_seat[i].min);
	}
	fclose(chair_seat);
	while (1) {
		system("cls");
		seat_ui();
		seat_see();
		gotoxy(96, 3);
		manager_insert_ui();
		gotoxy(115, 4);
		printf("1.좌석 확인");
		gotoxy(128, 4);
		printf("2.돌아가기");
		gotoxy(120, 7);
		printf("메뉴입력:");
		scanf("%d",&num);		
		if (num == 1) {
			num = -1;
			gotoxy(101, 15);
			printf("좌석번호 입력 : ");
			scanf("%d",&seat_num);
			if (seat_num < 0 || seat_num > 40) {
				gotoxy(116, 27);
				printf("다시 입력해주세요");
				Sleep(500);
				gotoxy(115, 27);
				printf("                                     ");
				continue;
			}
			for (int i = 0; i < 100; i++) {
				if (seat_num == user_seat[i].seat_num) {
					strcpy(name, user_seat[i].user_name);
					year = user_seat[i].year;
					mon = user_seat[i].mon;
					day = user_seat[i].day;
					hour = user_seat[i].hour;
					min = user_seat[i].min;
					num = i;
					break;
					
				}
			}
			if (num < 0) {
				gotoxy(118, 25);
				printf("비어있는 좌석입니다");
				Sleep(2000);
				continue;
			}
			else {
				gotoxy(101, 20);
				printf("회원이름 : %s", name);
				gotoxy(101, 25);
				printf("이용권 종료일자 : %d년 %d월 %d일 %d시 %d분", year, mon, day, hour, min);
				gotoxy(110, 40);
				printf("강제 퇴실을 시키시겠습니까?(y/n) : ");
				scanf("%s", choice);

				if (strcmp(choice, "y") == 0) {
					user_seat[num].seat_num = 0;
					chair_seat = fopen("seat.txt", "w");
					for (int i = 0; i < 100; i++) {
						if (strcmp(user_seat[i].user_name, "") != 0) {
							fprintf(chair_seat, "\n%s %d %d/%d/%d/%d/%d", user_seat[i].user_name, user_seat[i].seat_num, user_seat[i].year, user_seat[i].mon, user_seat[i].day, user_seat[i].hour, user_seat[i].min);
						}
					}
					fclose(chair_seat);
					gotoxy(117, 45);
					printf("퇴실이 완료되었습니다");
					Sleep(2000);
					continue;
					
				}
				else if (strcmp(choice, "n") == 0) {
					Sleep(2000);
					system("cls");
					continue;
				}
			}
		}
		else if (num == 2) {
			break;
		}
	}
}
int member_mange() {
	time_remove();
	FILE* member;
	member = fopen("member.txt", "r");
	typedef struct {
		char user_name[20];
		char phone_num[20];
		char password[20];

	}user;
	user all[100];
	for (int i = 0; i < 100; i++) {
		strcpy(all[i].user_name, "");
		strcpy(all[i].phone_num, "");
		strcpy(all[i].password, "");
		fscanf(member, "%s %s %s", all[i].user_name, all[i].phone_num, all[i].password);

	}
	fclose(member);
	FILE* chair_seat;
	chair_seat = fopen("seat.txt", "r");
	typedef struct {
		char user_name[20];
		int seat_num;
		int year;
		int mon;
		int day;
		int hour;
		int min;
	}seat;
	seat user_seat[100];
	int x = 27;
	int y = 14;
	for (int i = 0; i < 100; i++) {
		strcpy(user_seat[i].user_name, "");
		user_seat[i].seat_num = 0;
		user_seat[i].year = 0;
		user_seat[i].mon = 0;
		user_seat[i].day = 0;
		user_seat[i].hour = 0;
		user_seat[i].min = 0;
		fscanf(chair_seat, "%s %d %d/%d/%d/%d/%d", user_seat[i].user_name, &user_seat[i].seat_num, &user_seat[i].year, &user_seat[i].mon, &user_seat[i].day, &user_seat[i].hour, &user_seat[i].min);
	}
	fclose(chair_seat);
	char choice[5] = "";
	int count = 0;
	char phone_num[20] = "";
	int index = -1;
	int len = 0;
	char name[20] = "";
	char password[20] = "";
	gotoxy(20, 3);
	member_insert_ui();
	gotoxy(27, 4);
	printf("1.수정 및 탈퇴    2.돌아가기     페이지 이동(B/N)");
	gotoxy(47, 7);
	printf("메뉴입력:");
	gotoxy(27, 11);
	printf("이름");
	gotoxy(40, 11);
	printf("전화번호");
	gotoxy(55, 11);
	printf("비밀번호");
	gotoxy(70, 11);
	printf("좌석번호");
	for (int i = 0; i < 100; i++) {
		if (strcmp(user_seat[i].user_name, "") == 0) {
			strcpy(user_seat[i].user_name, user_seat[i + 1].user_name);
			strcpy(all[i].phone_num, all[i + 1].phone_num);
			strcpy(all[i].user_name, all[i + 1].user_name);
			strcpy(all[i].password, all[i + 1].password);
			user_seat[i].seat_num = user_seat[i + 1].seat_num;
			user_seat[i].year = user_seat[i + 1].year;
			user_seat[i].mon = user_seat[i + 1].mon;
			user_seat[i].day = user_seat[i + 1].day;
			user_seat[i].hour = user_seat[i + 1].hour;
			user_seat[i].min = user_seat[i + 1].min;
			strcpy(user_seat[i + 1].user_name, "");
			strcpy(all[i + 1].phone_num, "");
			strcpy(all[i + 1].user_name, "");
			strcpy(all[i + 1].password, "");
			user_seat[i+ 1].seat_num = 0;
			user_seat[i + 1].year = 0;
			user_seat[i + 1].mon = 0;
			user_seat[i + 1].day = 0;
			user_seat[i + 1].hour = 0;
			user_seat[i + 1].min = 0;
		}
		if (strcmp(all[i].user_name, "") != 0) {
			gotoxy(x, y);
			printf("%s", all[i].user_name);
			gotoxy(x + 12, y);
			printf("%s", all[i].phone_num);
			gotoxy(x + 30, y);
			printf("%s", all[i].password);
			if (user_seat[i].seat_num == 0) {
				gotoxy(x + 46, y);
				printf("X");
			}
			else {
				gotoxy(x + 46, y);
				printf("%d", user_seat[i].seat_num);
			}
			y += 3;
		}
		if (i == 10 || i == 21 || i == 32 || i == 43 || i == 54 || i == 65 || i == 76 || i == 87 || i == 98) {
			while (1) {
				gotoxy(22, 4);
				printf("");
				gotoxy(57, 7);
				printf(" ");
				gotoxy(56,7);
				scanf("%s", choice);
				Sleep(500);
				gotoxy(56, 7);
				printf(" ");
				if (strcmp(choice,"2")==0) {
					count = 1;
					break;
				}
				else if(strcmp(choice, "N") == 0) {
					if (strcmp(all[i+1].user_name, "") == 0 && strcmp(all[i + 2].user_name, "") == 0) {
						gotoxy(44, 47);
						printf("페이지가 없습니다");
						Sleep(1000);
						gotoxy(44, 47);
						printf("                    ");
						continue;
					}
					else {
						y = 14;
						while (1) {
							gotoxy(x, y);
							printf("                                                  ");
							if (y == 50) {
								x = 27;
								y = 14;
								break;
							}
							else {
								y += 3;
							}
						}
					}
				}
				else if (strcmp(choice, "B") == 0) {
					if (i == 10) {
						gotoxy(44, 47);
						printf("페이지가 없습니다");
						Sleep(1000);
						gotoxy(44, 47);
						printf("                    ");
						continue;
					}
					else {
						y = 14;
						while (1) {
							gotoxy(x, y);
							printf("                                                  ");
							if (y == 50) {
								x = 27;
								y = 14;
								break;
							}
							else {
								y += 3;
							}
						}
						i -= 22;
					}
				}
				else if (strcmp(choice, "1") == 0) {
					manger_insert_ui_1();
					gotoxy(100, 4);
					printf("1.수정      2.탈퇴      3.돌아가기");
					gotoxy(112, 7);
					printf("메뉴입력:");
					while (1) {
						gotoxy(22, 4);
						printf("");
						x = 87;
						y = 12;
						while (1) {
							gotoxy(x, y);
							printf("                                                  ");
							if (y == 40) {
								x = 27;
								y = 14;
								break;
							}
							else {
								y += 1;
							}
						}
						gotoxy(121, 7);
						printf("  ");
						gotoxy(121, 7);
						scanf("%s", choice);
						if (strcmp("2", choice) == 0) {
							gotoxy(98, 14);
							printf("탈퇴시킬 회원의 전화번호를 입력하세요");
							gotoxy(108, 16);
							printf(">>");
							gotoxy(111, 16);
							scanf("%s", phone_num);
							for (int k = 0; k < 100; k++) {
								if (strcmp(all[k].phone_num, phone_num) == 0) {
									index = k;
									break;
								}
							}
							gotoxy(108, 16);
							printf("                 ");
							gotoxy(98, 14);
							printf("                                                ");
							if (index >= 0) {
								gotoxy(90, 13);
								printf("회원이름 :        %s", all[index].user_name);
								gotoxy(90, 17);
								printf("전화번호 :        %s", all[index].phone_num);
								gotoxy(90, 21);
								printf("비밀번호 :        %s", all[index].password);
								gotoxy(90, 25);
								printf("이용권 종료일자 : %d/%d/%d/%d/%d", user_seat[index].year, user_seat[index].mon, user_seat[index].day, user_seat[index].hour, user_seat[index].min);
								if (user_seat[index].seat_num != 0) {
									gotoxy(90, 29);
									printf("죄석번호 :        %d", user_seat[index].seat_num);
								}
								else {
									gotoxy(90, 29);
									printf("죄석번호 :        이용중인 좌석이 없습니다");
								}
								gotoxy(104, 37);
								printf("탈퇴시키겠습니까?(y or n)");
								gotoxy(112, 39);
								printf(">>");
								scanf("%s", choice);
								if (strcmp(choice, "y") == 0) {
									strcpy(all[index].user_name,"");
									strcpy(user_seat[index].user_name,"");
									chair_seat = fopen("seat.txt", "w");
									member = fopen("member.txt", "w");
									for (int j = 0; j < 100; j++) {
										if (strcmp(user_seat[j].user_name,"") != 0) {
											fprintf(chair_seat, "\n%s %d %d/%d/%d/%d/%d", user_seat[j].user_name, user_seat[j].seat_num, user_seat[j].year, user_seat[j].mon, user_seat[j].day, user_seat[j].hour, user_seat[j].min);
											fprintf(member, "\n%s %s %s ", all[j].user_name, all[j].phone_num, all[j].password);
										}
									}
									fclose(chair_seat);
									fclose(member);
									gotoxy(104, 37);
									printf("                                         ");
									gotoxy(112, 39);
									printf("                ");
									gotoxy(106, 37);
									printf("탈퇴가 완료 되었습니다");
									index = -1;
									i = -1;
									Sleep(1000);
									
									break;
								}
								else if(strcmp(choice, "n") == 0) {
									i = -1;
									index = -1;
									break;
								}
							}
							else {
								gotoxy(100, 25);
								printf("일치 하는 회원을 찾을 수 없습니다");
								Sleep(1000);
								gotoxy(100, 25);
								printf("                                          ");
								continue;
							}
						}
						else if (strcmp("1", choice) == 0) {
							
							gotoxy(100, 4);
							printf("                                          ");
							gotoxy(98, 4);
							printf("1.이름       2.전화번호       3.비밀번호");
							gotoxy(100, 7);
							printf("수정하실 메뉴입력 예) 1,2  : ");
							while (1) {
								gotoxy(22, 4);
								printf("");
								x = 87;
								y = 12;
								while (1) {
									gotoxy(x, y);
									printf("                                                  ");
									if (y == 40) {
										x = 27;
										y = 14;
										break;
									}
									else {
										y += 1;
									}
								}
								gotoxy(98, 14);
								printf("수정하실 회원의 전화번호를 입력하세요");
								gotoxy(108, 16);
								printf(">>");
								gotoxy(111, 16);
								scanf("%s", phone_num);
								for (int k = 0; k < 100; k++) {
									if (strcmp(all[k].phone_num, phone_num) == 0) {
										index = k;
										strcpy(name, all[index].user_name);
										strcpy(phone_num, all[index].phone_num);
										strcpy(password, all[index].password);
										break;
									}
								}
								if(index == -1){
									gotoxy(100, 25);
									printf("일치 하는 회원을 찾을 수 없습니다");
									Sleep(1000);
									gotoxy(100, 25);
									printf("                                          ");
									continue;
								}
								else {
									break;
								}
							}
							gotoxy(108, 16);
							printf("                 ");
							gotoxy(98, 14);
							printf("                                                ");
							if (index >= 0) {
								gotoxy(90, 16);
								printf("회원이름 :        %s", all[index].user_name);
								gotoxy(90, 24);
								printf("전화번호 :        %s", all[index].phone_num);
								gotoxy(90, 32);
								printf("비밀번호 :        %s", all[index].password);
								gotoxy(130, 7);
								scanf("%s", choice);
								len = strlen(choice);
								for (int m = 0; m < len; m++) {
									if (choice[m] == '1') {
										gotoxy(98, 16);
										printf("                   ");
										gotoxy(107, 16);
										scanf("%s", name);
									}
									else if (choice[m] == '2') {
										gotoxy(98, 24);
										printf("                           ");
										gotoxy(107, 24);
										scanf("%s", phone_num);

									}
									else if (choice[m] == '3') {
										gotoxy(98, 32);
										printf("                   ");
										gotoxy(107, 32);
										scanf("%s", password);
									}
								}
								gotoxy(104, 37);
								printf("저장하시겠습니까? (y or n)");
								gotoxy(112, 39);
								printf(">>");
								while (1) {
									gotoxy(115, 39);
									printf("   ");
									gotoxy(116, 39);
									scanf("%s", choice);
									if (strcmp(choice, "y") == 0) {
										strcpy(all[index].user_name, name);
										strcpy(user_seat[index].user_name, name);
										strcpy(all[index].phone_num, phone_num);
										strcpy(all[index].password, password);
										chair_seat = fopen("seat.txt", "w");
										member = fopen("member.txt", "w");
										for (int j = 0; j < 100; j++) {
											if (strcmp(user_seat[j].user_name, "") != 0) {
												fprintf(chair_seat, "\n%s %d %d/%d/%d/%d/%d", user_seat[j].user_name, user_seat[j].seat_num, user_seat[j].year, user_seat[j].mon, user_seat[j].day, user_seat[j].hour, user_seat[j].min);
												fprintf(member, "\n%s %s %s ", all[j].user_name, all[j].phone_num, all[j].password);
											}
										}
										fclose(chair_seat);
										fclose(member);
										gotoxy(104, 37);
										printf("                                         ");
										gotoxy(112, 39);
										printf("                ");
										gotoxy(106, 37);
										printf("저장이 완료되었습니다");
										index = -1;
										i = -1;
										Sleep(1000);
										
										break;

									}
									else if (strcmp(choice, "n") == 0) {
										i = -1;
										index = -1;
										break;
									}
									else {
										continue;
									}
								}
								
								break;

							}
					
						}
						else if (strcmp("3", choice) == 0) {
								gotoxy(22, 4);
								printf("");
								x = 85;
								y = 3;
								while (1) {
									gotoxy(x, y);
									printf("                                                                       ");
									if (y == 60) {
										x = 27;
										y = 14;
										break;
									}
									else {
										y += 1;
									}
								}
								i = -1;
								break;
						}
					}
					x = 85;
					y = 3;
					while (1) {
						gotoxy(x, y);
						printf("                                                                       ");
						if (y == 60) {
							x = 27;
							y = 14;
							break;
						}
						else {
							y += 1;
						}
					}
					y = 14;
					while (1) {
						gotoxy(x, y);
						printf("                                                  ");
						if (y == 50) {
							x = 27;
							y = 14;
							break;
						}
						else {
							y += 3;
						}
					}
				}
				else {
					continue;
				 }
				break;
			}
		}
		if (count == 1) {
			break;
		}
	}
}
int sales_check() {

}
int sales() {
	int num = 0;
	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);
	gotoxy(20, 3);
	member_insert_ui();
	gotoxy(23, 4);
	printf("1.일매출  2.월매출  3.연매출  4.특정일자 매출  5.돌아가기 ");
	gotoxy(47, 7);
	printf("메뉴입력:");
	while (1) {
		gotoxy(57, 7);
		printf(" ");
		gotoxy(57, 7);
		scanf("%d", &num);
		if (num == 1) {
			
		}
	}
	Sleep(300000000);

}
int manager() {
	while (1) {
		system("cls");
		Sleep(1000);
		int num = 0;
		time_remove();
		gotoxy(20, 3);
		member_insert_ui();
		gotoxy(46, 4);
		printf("관리자 모드");
		gotoxy(47, 7);
		printf("메뉴입력:");
		gotoxy(47, 17);
		printf("1.좌석관리");
		gotoxy(47, 24);
		printf("2.회원관리");
		gotoxy(47, 31);
		printf("3.매출관리");
		gotoxy(47, 38);
		printf("4.돌아가기");
		gotoxy(56, 7);
		scanf("%d", &num);

		if (num == 1) {
			system("cls");
			Sleep(1000);
			manager_remove_seat();
		}
		else if (num == 2) {
			system("cls");
			Sleep(1000);
			member_mange();
			
		}
		else  if (num == 3) {
			system("cls");
			Sleep(1000); 
			sales();
		}
		else if (num == 4) {
			system("cls");
			Sleep(1000);
			break;

		}
	}
}
int main(void) {
	int num = 0;
	while (1) {
		member_start();
		}
}