#define _CRT_SECURE_NO_WARNINGS 
#define ANSI_COLOR_YELLOW   "\x1b[33m"
#define ANSI_COLOR_RESET    "\x1b[0m"
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>
typedef struct {
	int year;
	int year2;
	int mon;
	int mon2;
	int day;
	int day2;
}choice_sales;
choice_sales c_s;
int sales_num = 0;
int count_check = 0;
int pay = 0;
int pay_2 = 0;
char c_choice_[3] = "";
typedef struct {
	char user_name[20];
	char phone_num[20];
	char password[20];
}user;
user all[100];
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
typedef struct {
	char name[20];
	int year;
	int mon;
	int day;
	int pay;
}Sales;
 Sales total_sales[100];
void gotoxy(int x, int y);
void file_read();
void file_write();
void sales_file_reaad();
int sales();
int member_insert_ui();
int year_pay_ui();
//ui
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
int main(void) {
	file_read();
	member_start();
}
int shelf_life_check(int year, int mon, int day, int hour, int min) {//이용권 종료일자랑 현재시간이랑 비교 해서 지나면 1 안 지났으면 0

	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);
	if (t->tm_year + 1900 > year) {
		return 1;
	}
	else if (t->tm_year + 1900 == year) {
		if (t->tm_mon + 1 < mon) {
			return 0;
		}
		else if (t->tm_mon + 1 == mon) {
			if (t->tm_mday < day) {
				return 0;
			}
			else if (t->tm_mday == day) {
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
	for (int i = 0; i < count_check; i++) {
		if (user_seat[i].year != 0) {
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
		file_write();
}
int remove_seat(int index) { //퇴실
	char choice[10] = "";
	int count = 0;
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
			scanf("%s", choice);
			if (strcmp(choice, "y") == 0) {
				user_seat[index].seat_num = 0;
				file_write();
				gotoxy(37, 42);
				printf("퇴실처리가 완료되었습니다");
				Sleep(2000);
				return 1;
			}
			else if (strcmp(choice, "n") == 0) {
				Sleep(2000);
				return -1;
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
int seat_same_check(int seat_num) {
	int count = 0;
	for (int i = 0; i < count_check; i++) {
		if (user_seat[i].seat_num == seat_num) {
			count = 1;
		}
	}
	return count;

}
int seat_check_2(int check) {
	int count = 0;
	for (int i = 0; i < count_check; i++) {
			if (user_seat[i].seat_num == check) {
				count = 1;
				break;
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
int append_time(int index, int year, int mon, int day, int hour, int min) { // 인덱스 연 월 일 시 분 가져와서 인덱스에 맞는 사용자 찾아서 날짜에 맞게 시간 추가 후 종료 기간 파일에 입력
	user_seat[index].year = year;
	user_seat[index].mon = mon;
	user_seat[index].day = day;
	user_seat[index].hour = hour;
	user_seat[index].min = min;
	file_write();
	gotoxy(42, 45);
	printf("결제가 완료되었습니다");
	Sleep(1000);
}
int period_usufruct_time(char* choice_price, int index) {//기간제 이용가능 날짜 계산하는 함수 
	int year = 0;
	int mon = 0;
	int day = 0;
	int hour = 0;
	int min = 0;
	int pay = 0;
	FILE* sales_check;
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
	fprintf(sales_check, "%s %d/%d/%d %d\n", user_seat[index], t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, pay);
	fclose(sales_check);

	append_time(index, year, mon, day, hour, min);
}
int time_usufruct_time(char* choice_price, int index) { //시간제 이용가능 날짜 계산하는 함수
	int year = 0;
	int mon = 0;
	int day = 0;
	int hour = 0;
	int min = 0;
	int pay = 0;
	FILE* sales_check;
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
	if (user_seat[index].year != 0) {
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
	fprintf(sales_check, "%s %d/%d/%d %d\n", user_seat[index], t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, pay);
	fclose(sales_check);
	append_time(index, year, mon, day, hour, min);
}
int seat_usufruct(int index) {//이용권 구매 함수//
	int x = 27;
	int y = 15;
	char phone_num[11] = "";
	char choice_price[10] = "";
	int num = 0;
	system("cls");
	gotoxy(20, 3);
	member_insert_ui();
	gotoxy(49, 18);
	printf("기간제");
	gotoxy(35, 21);
	printf("7d:30000원  14d:50000원  30d:90000원");
	gotoxy(49, 30);
	printf("시간제");
	gotoxy(35, 33);
	printf("1t:2000원    3t:3000원    6t:6000원");
	while (1) {
		gotoxy(35,4);
		printf("1.이용권 구매      2.돌아가기");
		gotoxy(45, 7);
		printf("메뉴입력 : ");
		gotoxy(56, 7);
		scanf("%d", &num);
		gotoxy(56, 7);
		printf("    ");
		if (num == 1) {
			gotoxy(35, 4);
			printf("                                     ");
			gotoxy(47, 4);
			printf("이용권 구매");
			gotoxy(45, 7);
			printf("요금입력 : ");
			while (1) {
				gotoxy(56, 7);
				scanf("%s", choice_price);
				gotoxy(56, 7);
				printf("    ");
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
					gotoxy(43, 45);
					printf("                   ");
					continue;
				}
				break;
			}
			break;
		}
		else if (num == 2) {
			return;
		}

	}
}
int period_see(int index) {//로그인 했을때 이용권 종료일자 보여주는 함수
	gotoxy(35, 20);
	printf("회원 이름 :     %s\n\n", user_seat[index].user_name);
	if (user_seat[index].year == 0) {
		gotoxy(35, 28);
		printf("이용권 종료일자:이용권이 없습니다");
	}
	else {
		gotoxy(35, 28);
		printf("이용권 종료일자 : %d/%d/%d/%02d:%02d", user_seat[index].year, user_seat[index].mon, user_seat[index].day, user_seat[index].hour, user_seat[index].min);
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
void file_write() {
	FILE* chair_seat;
	FILE* member;
	chair_seat = fopen("seat.txt", "w");
	member = fopen("member.txt", "w");
	for (int i = 0; i < count_check; i++) {
			fprintf(member, "%s %s %s\n", all[i].user_name, all[i].phone_num, all[i].password);
			fprintf(chair_seat, "%s %d %d/%d/%d/%d/%d\n", user_seat[i].user_name, user_seat[i].seat_num, user_seat[i].year, user_seat[i].mon, user_seat[i].day, user_seat[i].hour, user_seat[i].min);

	}
	fclose(chair_seat);
	fclose(member);
}
void file_append(){
	FILE* member;
	FILE* chair_seat;
	member = fopen("member.txt", "a");
	chair_seat = fopen("seat.txt", "a");
	fprintf(member, "%s %s %s\n", all[count_check].user_name, all[count_check].phone_num, all[count_check].password);
	fprintf(chair_seat, "%s %d %d/%d/%d/%d/%d\n", user_seat[count_check].user_name, user_seat[count_check].seat_num, user_seat[count_check].year, user_seat[count_check].mon, user_seat[count_check].day, user_seat[count_check].hour, user_seat[count_check].min);
	fclose(member);
	fclose(chair_seat);
}
void file_read() {
	int seat_count_check = 0;
	char c;
	FILE* member = fopen("member.txt", "r");
	FILE* chair_seat = fopen("seat.txt", "r");
	if (member == NULL && chair_seat == NULL) {
		return 0;
	}
	else {
		while (c = fgetc(chair_seat)!=EOF){

			fseek(chair_seat, -1, SEEK_CUR);
			if (feof(member) != 0 && feof(chair_seat) != 0) {
				break;
			}
			fscanf(member, "%s %s %s\n", all[count_check].user_name, all[count_check].phone_num, all[count_check].password);
			fscanf(chair_seat, "%s %d %d/%d/%d/%d/%d\n", user_seat[count_check].user_name, &user_seat[count_check].seat_num, &user_seat[count_check].year, &user_seat[count_check].mon, &user_seat[count_check].day, &user_seat[count_check].hour, &user_seat[count_check].min);
			count_check++;
		}
	}
	fclose(member);
	fclose(chair_seat);
}
int member_start() { //회원 초기화면  
	int num = 0;
	while (1) {
		time_remove();
		system("cls");
		Sleep(1000);
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
		scanf("%d", &num);
		gotoxy(54, 7);
		printf(" ");
		if (num == 1) {
			Sleep(1000);
			membership();
			continue;
		}
		else if (num == 2) {
			Sleep(1000);
			login();
			continue;
		}
		else if (num == 3) {
			Sleep(1000);
			password_find();
			continue;
		}
		else if (num == 4) {
			Sleep(1000);
			manager_login();
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
	int choice = 0;
	int count = 0;
	char name[20] = "";
	char phone_num[20] = "";
	char password[20] = "";
	system("cls");
	gotoxy(20, 3);
	member_insert_ui();
	gotoxy(36, 4);
	printf("  1.회원가입       2.돌아가기");
	gotoxy(45, 7);
	printf("메뉴입력:");
	while (1) {
		gotoxy(54, 7);
		scanf("%d", &choice);
		gotoxy(54, 7);
		printf(" ");
		if (choice == 1) {
			gotoxy(36, 4);
			printf("                                       ");
			gotoxy(48, 4);
			printf("회원가입");
			gotoxy(30, 12);
			printf("이름 입력 : ");
			gotoxy(30, 20);
			printf("전화번호(11자리) 입력 : ");
			gotoxy(30, 30);
			printf("비밀번호(4자리) 입력 : ");
			while (1) {
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
						Sleep(2000);
						break;
					}
					else if (count == 0) {
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
						count_check++;
						gotoxy(35, 45);
						printf("회원가입이 완료 되었습니다!!!");
						Sleep(1000);
						break;
					}
				}
				else {
					gotoxy(38, 45);
					printf("형식이 올바르지 않습니다 ");
					Sleep(1000);
					gotoxy(38, 45);
					printf("                                ");
					gotoxy(42, 12);
					printf("        ");
					gotoxy(53, 20);
					printf("                 ");
					gotoxy(52, 30);
					printf("           ");
					continue;

				}
			}
			break;
		}
		else if (choice == 2) {
			break;
		}
		else {
			continue;
		}
	}
}
int password_find() { //비밀번호 찾는 함수//
	FILE* member;
	int num = 0;
	int count = 0;
	char name[20] = "";
	char phone_num[20] = "";
	char password[20] = "";
	system("cls");
	gotoxy(20, 3);
	member_insert_ui();
	gotoxy(45, 7);
	printf("메뉴입력:");
	while (1) {
		gotoxy(33, 4);
		printf(" 1.비밀번호 찾기       2.돌아가기");
		gotoxy(54, 7);
		scanf("%d", &num);
		gotoxy(54, 7);
		printf(" ");
		if (num == 1) {
			gotoxy(32, 4);
			printf("                                       ");
			gotoxy(45, 4);
			printf("비밀번호 찾기");
			gotoxy(30, 17);
			printf("이름 : ");
			gotoxy(30, 27);
			printf("전화번호(11자리) 입력 : ");
			gotoxy(37, 17);
			scanf("%s", name);
			getchar();
			gotoxy(54, 27);
			scanf("%s", phone_num);
			for (int i = 0; i < count_check; i++) {
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
				Sleep(1000);
				gotoxy(30, 17);
				printf("                                    ");
				gotoxy(30, 27);
				printf("                                       ");
				gotoxy(43, 43);
				printf("                         ");
				continue;
			}
			break;
		}
		else if (num == 2) {
			break;
		}

	}
}
int login() { // 로그인 하는 함수
	int num = 0;
	int count = 0;
	char name[20] = "";
	char phone_num[20] = "";
	char password[20] = "";
	char choice_price[10] = "";
	int index = 0;
	system("cls");
	gotoxy(20, 3);
	member_insert_ui();
	gotoxy(22, 4);
	printf("");
	gotoxy(47, 7);
	printf("메뉴입력:");
	while (1) {
		gotoxy(38, 4);
		printf("1.로그인        2.돌아가기");
		gotoxy(56, 7);
		scanf("%d", &num);
		gotoxy(56, 7);
		printf(" ");
		if (num == 1) {
			gotoxy(38, 4);
			printf("                                 ");
			gotoxy(48, 4);
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
			for (int i = 0; i < count_check; i++) {
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
				Sleep(500);
				login_success(index);
				break;
			}
			else {
				gotoxy(35, 45);
				printf("일치하는 전화번호 혹은 비밀번호를");
				gotoxy(43, 46);
				printf("찾을수 없습니다.");
				Sleep(1000);
				gotoxy(30, 17);
				printf("                                                 ");
				gotoxy(30, 27);
				printf("                                                 ");
				gotoxy(35, 45);
				printf("                                        ");
				gotoxy(43, 46);
				printf("                       ");
;				continue;
			}
		}
		else if (num == 2) {
			Sleep(1000);
			return;
		}
	}
}
int login_success(int index) { //로그인 성공시//
	int check = 0;
	int num = 0;
	while (1) {
		time_remove();
		system("cls");
		gotoxy(20, 3);
		member_insert_ui();
		gotoxy(45, 7);
		printf("메뉴입력:");
		period_see(index);
		gotoxy(25, 4);
		printf("1.좌석 이용권 구매  2. 자리선택  3.퇴실  4.로그아웃 ");
		gotoxy(54, 7);
		scanf("%d", &num);
		if (num == 1) {
			seat_usufruct(index);
			continue;
		}
		else if (num == 2) {

			check = seat_choice(index);
			printf("%d", check);
			if (check == -1) {
				continue;
			}
			else if(check == 1) {
				return;
			}
		}
		else if (num == 3) {
		  check = remove_seat(index);
		  if (check == 1) {
			  return;
		  }
		  else {
			  continue;
		  }
		}
		else if (num == 4) {
			Sleep(1000);
			break;
		}
	}
}
int user_seat_check(int index) { //이미 이용중인 좌석이 있는지 확인하는 함수
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
			scanf("%s", c_choice_);
			if (strcmp(c_choice_, "n") == 0) {
				system("cls");
				return;
			}
			else if (strcmp(c_choice_, "y") == 0) {
				system("cls");
				return;
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
int seat_choice(int index) {
	int num = 0;
	int seat_num = 0;
	int count = 0;
	int count_ch = 0;
	user_seat_check(index);
	if (strcmp(c_choice_, "n") == 0) {
		return-1;
	}
	else {
		again:
		system("cls");
		seat_ui();
		seat_see();
		gotoxy(96, 3);
		manager_insert_ui();
		gotoxy(115, 4);
		printf("1.좌석선택       2.돌아가기");
		gotoxy(123, 7);
		printf("메뉴입력 : ");
		while (1) {
			gotoxy(135, 7);
			scanf("%d", &num);
			gotoxy(135, 7);
			printf(" ");
			if (num == 1) {
				gotoxy(115, 4);
				printf("                                  ");
				gotoxy(125, 4);
				printf("좌석선택");
				gotoxy(117, 7);
				printf("원하시는 좌석을 입력 : ");
				while (1) {
					gotoxy(22, 4);
					printf("");
					gotoxy(140, 7);
					printf("  ");
					gotoxy(140, 7);
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
							count_ch = enter(index, seat_num);
							if (count_ch == -1) {
								goto again;
							}
							else {
								break;
							}
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
				break;
			}
			else if (num == 2) {
				return -1;
			}
		}
		return;
	}
}
int enter(int index, int seat_num) { //입실하는 함수
	char choice[10] = "";
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
		Sleep(2000);
		return 0;
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
			gotoxy(65, 7);
			scanf("%s", choice);
			if (strcmp(choice, "y") == 0) {
				user_seat[index].seat_num = seat_num;
				file_write();
				gotoxy(40, 42);
				printf("입실이 완료되었습니다");
				Sleep(1000);
				return 1;
			}
			else if (strcmp(choice, "n") == 0) {
				return -1;
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
//관리자//
int year_pay_ui() {
	char choice[3];
	int count = 0;
	int x = 31;
	int y = 25;
	int pay_count = 100;
	int year = 0;
	int year_pay = 0;
	int block_num = 0;
	int y3 = 26;
	gotoxy(45, 17);
	printf("연매출 통계표 ");
	gotoxy(45, 19);
	printf("단위 : 십만");
	gotoxy(x, y);
	for (int i = 7; i < 19; i++) {
		gotoxy(x, y);
		printf("┃");
		if (i > 8) {
			gotoxy(x - 3, y);
			printf("%d", pay_count);
			pay_count -= 10;
		}
		if (i == 18) {
			gotoxy(x, y + 1);
			printf("┗");
			for (int k = 0; k < 40; k++) {
				printf("━");
			}
		}
		y += 1;
	}
	year = total_sales[0].year;
	x = 37;
	y = 36;
	int x2 = 36;
	int y2 = 38;
	for (int i = 0; i < sales_num; i++) {

		if (total_sales[i].year == year) {
			year_pay += total_sales[i].pay;
		}
		if (i == sales_num - 1 || total_sales[i].year != year) {

			block_num = year_pay / 100000;
			Sleep(1000);
			for (int m = 0; m < block_num; m++) {
				gotoxy(x, y);
				printf("□");
				y -= 1;
				if (m == 9) {
					break;
				}
			}
			block_num = 0;
			y = 36;
			gotoxy(x2, y2);
			printf("%d", year);
			if (total_sales[i].year != year) {
				year_pay = 0;
				year = total_sales[i].year;
				x += 7;
				x2 += 7;
				count += 1;
				i--;
			}
		}
		if (count == 4) {
			gotoxy(33, 42);
			printf("다음연도 통계를 보시겠습니까?(y,n)");
			gotoxy(43, 44);
			printf("입력 >> ");
			while (1) {
				gotoxy(50, 44);
				scanf("%s", choice);
				gotoxy(50, 44);
				printf(" ");
				if (strcmp(choice, "y") == 0) {
					x = 37;
					y = 36;
					x2 = 36;
					y2 = 38;
					count = 0;
					while (1) {
						gotoxy(37, y3);
						printf("                                            ");
						y3++;
						if (y3 == 37) {
							y3 = 26;
							break;
						}
					}
					gotoxy(36, 38);
					printf("                                            ");
					break;
				}
				else if (strcmp(choice, "n") == 0) {
					break;
				}
			}
			if (strcmp(choice, "n") == 0) {
				break;
			}
		}
	}
	Sleep(3000);
}
int pay_(int num) {
	pay = 0;
	pay_2 = 0;
	int year = 0;
	int mon = 0;
	int day = 0;
	time_t timer;
	struct tm* t;
	timer = time(NULL);
	t = localtime(&timer);
	for (int i = 0; i < sales_num; i++) {
		if (num == 1) {
			if (total_sales[i].year == t->tm_year + 1900 && total_sales[i].mon == t->tm_mon + 1 && total_sales[i].day == t->tm_mday) {
				pay += total_sales[i].pay;
			}
			if (total_sales[i].year == t->tm_year + 1900 && total_sales[i].mon == t->tm_mon + 1) {
				pay_2 += total_sales[i].pay;
			}
			if (i == sales_num - 1) {
				day = t->tm_mday;
				pay_2 = pay_2 / day;
			}
		}
		else if (num == 2) {
			if (total_sales[i].year == t->tm_year + 1900 && total_sales[i].mon == t->tm_mon + 1) {
				pay += total_sales[i].pay;
			}
			if (total_sales[i].year == t->tm_year + 1900) {
				if (total_sales[i].mon < t->tm_mon + 1 || total_sales[i].mon == t->tm_mon + 1) {
					pay_2 += total_sales[i].pay;
				}
			}
			if (i == sales_num - 1) {
				mon = t->tm_mon + 1;
				pay_2 = pay_2 / mon;
			}
		}
		else if (num == 3) {
			if (total_sales[i].year == t->tm_year + 1900) {
				pay += total_sales[i].pay;
			}
		}
		else if (num == 4) {
			if (total_sales[i].year > c_s.year) {
				if (total_sales[i].year < c_s.year2) {
					pay += total_sales[i].pay;
				}
				else if (total_sales[i].year == c_s.year2) {
					if (total_sales[i].mon < c_s.mon2) {
						pay += total_sales[i].pay;
					}
					else if (total_sales[i].mon == c_s.mon2) {
						if (total_sales[i].day <= c_s.day2) {
							pay += total_sales[i].pay;
						}
					}
				}
			}
			else if (total_sales[i].year == c_s.year) {
				if (total_sales[i].mon > c_s.mon) {
					if (total_sales[i].year < c_s.year2) {
						pay += total_sales[i].pay;
					}
					else if (total_sales[i].year == c_s.year2) {
						if (total_sales[i].mon < c_s.mon2) {
							pay += total_sales[i].pay;
						}
						else if (total_sales[i].mon == c_s.mon2) {
							if (total_sales[i].day <= c_s.day2) {
								pay += total_sales[i].pay;
							}
						}
					}
				}
				else if (total_sales[i].mon == c_s.mon) {
					if (total_sales[i].day == c_s.day) {
						pay += total_sales[i].pay;
					}
					else if (total_sales[i].day > c_s.day) {
						if (total_sales[i].year < c_s.year2) {
							pay += total_sales[i].pay;
						}
						else if (total_sales[i].year == c_s.year2) {
							if (total_sales[i].mon < c_s.mon2) {
								pay += total_sales[i].pay;
							}
							else if (total_sales[i].mon == c_s.mon2) {
								if (total_sales[i].day <= c_s.day2) {
									pay += total_sales[i].pay;
								}
							}
						}
					}
				}
			}
		}
	}
}
void sales_file_reaad(){
	sales_num = 0;
	char c;
	FILE* sales_check = fopen("sales_check.txt", "r");
	if (sales_check == NULL) {
		return 0;
	}
	else {
		while (c = fgetc(sales_check) != EOF) {
			fseek(sales_check, -1, SEEK_CUR);
			if ((feof(sales_check)) != 0) {
				break;
			}
			fscanf(sales_check, "%s %d/%d/%d %d\n", total_sales[sales_num].name, &total_sales[sales_num].year, &total_sales[sales_num].mon, &total_sales[sales_num].day, &total_sales[sales_num].pay);
			sales_num++;
		}
	}
	printf("%d", sales_num);
	fclose(sales_check);

}
int sales() {
	sales_file_reaad();
	int num = 0;
	int num2 = 0;
	int x = 25;
	int y = 15;
	char choice[3];
	gotoxy(20, 3);
	member_insert_ui();
	while (1) {
		gotoxy(23, 4);
		printf("                                                   ");
		gotoxy(23, 4);
		printf("1.일매출  2.월매출  3.연매출  4.특정일자 매출  5.돌아가기 ");
		gotoxy(47, 7);
		printf("메뉴입력:");
		scanf("%d", &num);
		gotoxy(56, 7);
		printf("  ");
		if (num == 1) {
			pay_(num);
			gotoxy(23, 4);
			printf("                                                          ");
			gotoxy(25, 4);
			printf("  1.오늘 매출    2.이번달 평균 일매출     3.돌아가기");
			while (1) {
				gotoxy(22, 4);
				printf("");
				gotoxy(57, 7);
				scanf("%d", &num);
				gotoxy(56, 7);
				printf("   ");
				if (num == 1) {
					gotoxy(40, 25);
					printf(ANSI_COLOR_YELLOW);
					printf("오늘 매출 금액 :  %d원입니다", pay);
					Sleep(2000);
					gotoxy(40, 25);
					printf("                                       ");
					printf(ANSI_COLOR_RESET);
				}
				else if (num == 2) {
					printf(ANSI_COLOR_YELLOW);
					gotoxy(33, 25);
					printf("이번달 평균 일매출 금액  : %d원입니다", pay_2);
					Sleep(2000);
					gotoxy(33, 25);
					printf("                                         ");
					printf(ANSI_COLOR_RESET);
				}
				else if (num == 3) {
					break;
				}
				else {
					continue;
				}
			}
		}
		else if (num == 2) {
			pay_(num);
			gotoxy(23, 4);
			printf("                                                          ");
			gotoxy(23, 4);
			printf("  1.이번달 매출    2.이번년도 평균 월매출     3.돌아가기");
			while (1) {
				gotoxy(22, 4);
				printf("");
				gotoxy(57, 7);
				scanf("%d", &num);
				gotoxy(56, 7);
				printf("   ");
				if (num == 1) {
					gotoxy(36, 25);
					printf(ANSI_COLOR_YELLOW);
					printf("이번달 매출 금액 :  %d원입니다", pay);
					Sleep(2000);
					gotoxy(36, 25);
					printf("                                       ");
					printf(ANSI_COLOR_RESET);
				}
				else if (num == 2) {
					printf(ANSI_COLOR_YELLOW);
					gotoxy(30, 25);
					printf("이번년도 평균 월매출 금액  : %d원입니다", pay_2);
					Sleep(2000);
					gotoxy(30, 25);
					printf("                                           ");
					printf(ANSI_COLOR_RESET);
				}
				else if (num == 3) {
					break;
				}
				else {
					continue;
				}
			}
		}
		else if (num == 3) {
			pay_(num);
			gotoxy(23, 4);
			printf("                                                          ");
			gotoxy(23, 4);
			printf("  1.이번년도 매출    2.연매출 통계     3.돌아가기");
			while (1) {
				while (1) {
					gotoxy(x, y);
					printf("                                                       ");
					if (y == 47) {
						x = 25;
						y = 15;
						break;
					}
					else {
						y += 1;
					}
				}
				printf(ANSI_COLOR_RESET);
				gotoxy(22, 4);
				printf("");
				gotoxy(57, 7);
				scanf("%d", &num);
				gotoxy(56, 7);
				printf("   ");
				if (num == 1) {
					gotoxy(36, 25);
					printf(ANSI_COLOR_YELLOW);
					printf("이번년도 매출 금액 :  %d원입니다", pay);
					Sleep(3000);
				}
				else if (num == 2) { 
					printf(ANSI_COLOR_YELLOW);
					year_pay_ui(); 
					Sleep(1000);
				}
				else if (num == 3) {
					break;
				}
				else {
					continue;
				}
			}
		}
		else if (num == 4) {
			gotoxy(23, 4);
			printf("                                                         ");
			while (1) {
				gotoxy(30, 4);
				printf("  1.특정일자 매출 확인    2.돌아가기");
				gotoxy(56, 7);
				scanf("%d", &num2);
				gotoxy(56, 7);
				printf("   ");
				if (num2 == 1) {
					while (1) {
						printf(ANSI_COLOR_YELLOW);
						gotoxy(36, 15);
						printf("시작일자와 종료일자를 입력해주세요");
						gotoxy(26, 25);
						printf("시작일자 : 0000 / 00 / 00");
						gotoxy(26, 30);
						printf("종료일자 : 0000 / 00 / 00");
						gotoxy(37, 25);
						printf("    ");
						gotoxy(37, 25);
						scanf("%d", &c_s.year);
						gotoxy(44, 25);
						printf("  ");
						gotoxy(44, 25);
						scanf("%d", &c_s.mon);
						gotoxy(49, 25);
						printf("  ");
						gotoxy(49, 25);
						scanf("%d", &c_s.day);
						gotoxy(37, 30);
						printf("    ");
						gotoxy(37, 30);
						scanf("%d", &c_s.year2);
						gotoxy(44, 30);
						printf("  ");
						gotoxy(44, 30);
						scanf("%d", &c_s.mon2);
						gotoxy(49, 30);
						printf("  ");
						gotoxy(49, 30);
						scanf("%d", &c_s.day2);
						if (c_s.year > c_s.year2) {
							gotoxy(40, 40);
							printf("날짜를 확인해주세요");
							Sleep(1000);
							gotoxy(40, 40);
							printf("                            ");
							continue;
						}
						else if (c_s.year == c_s.year2) {
							if (c_s.mon > c_s.mon2) {
								gotoxy(40, 40);
								printf("날짜를 확인해주세요");
								Sleep(1000);
								gotoxy(40, 40);
								printf("                            ");
								continue;
							}
							else if (c_s.mon == c_s.mon2) {
								if (c_s.day > c_s.day2) {
									gotoxy(40, 40);
									printf("날짜를 확인해주세요");
									Sleep(1000);
									gotoxy(40, 40);
									printf("                            ");
									continue;
								}
							}
						}
						gotoxy(35, 38);
						printf("%d/%d/%d ~ %d/%d/%d까지의 매출을", c_s.year, c_s.mon, c_s.day, c_s.year2, c_s.mon2, c_s.day2);
						gotoxy(40, 40);
						printf("확인하시겠습니까 ? (y / n)");
						gotoxy(47, 42);
						printf("입력 >> ");
						while (1) {
							gotoxy(55, 42);
							scanf("%s", choice);
							gotoxy(55, 42);
							printf("  ");
							if (strcmp(choice, "y") == 0) {
								pay_(num);
								gotoxy(35, 38);
								printf("                                           ");
								gotoxy(40, 40);
								printf("                                     ");
								gotoxy(47, 42);
								printf("             ");
								gotoxy(28, 44);
								printf("%d/%d/%d ~ %d/%d/%d까지의 매출 금액 : %d원", c_s.year, c_s.mon, c_s.day, c_s.year2, c_s.mon2, c_s.day2, pay);
								Sleep(3000);
								gotoxy(28, 44);
								printf("                                                   ");
								break;
							}
							else if (strcmp(choice, "n") == 0) {
								Sleep(3000);
								break;
							}
						}
						gotoxy(35, 38);
						printf("                                            ");
						gotoxy(40, 40);
						printf("                                    ");
						gotoxy(47, 42);
						printf("             ");
						gotoxy(35, 40);
						printf("다른날짜의 매출을 조회하시겠습니까?(y/n)");
						gotoxy(47, 42);
						printf("입력 >> ");
						while (1) {
							gotoxy(55, 42);
							printf("  ");
							gotoxy(55, 42);
							scanf("%s", choice);
							if (strcmp(choice, "y") == 0) {
								break;
							}
							else if (strcmp(choice, "n") == 0) {
								break;
							}
						}
						if (strcmp(choice, "y") == 0) {
							gotoxy(35, 40);
							printf("                                         ");
							gotoxy(47, 42);
							printf("           ");
							continue;
						}
						gotoxy(35, 40);
						printf("                                         ");
						gotoxy(47, 42);
						printf("          ");
						break;
					}
				}
				else if(num2 == 2) {
					break;
				}
				while (1) {
					gotoxy(x, y);
					printf("                                                       ");
					if (y == 47) {
						x = 25;
						y = 15;
						break;
					}
					else {
						y += 1;
					}
				}
				printf(ANSI_COLOR_RESET);
			}
		}

		else if (num == 5) {
			break;
		}
	}

}
int gap_remove(){
	for (int i = 0; i < count_check; i++) {
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
			user_seat[i + 1].seat_num = 0;
			user_seat[i + 1].year = 0;
			user_seat[i + 1].mon = 0;
			user_seat[i + 1].day = 0;
			user_seat[i + 1].hour = 0;
			user_seat[i + 1].min = 0;
		}
	}
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
		scanf("%d", &num);
		if (num == 1) {
			num = -1;
			gotoxy(101, 15);
			printf("좌석번호 입력 : ");
			scanf("%d", &seat_num);
			if (seat_num < 0 || seat_num > 40) {
				gotoxy(116, 27);
				printf("다시 입력해주세요");
				Sleep(500);
				gotoxy(115, 27);
				printf("                                     ");
				continue;
			}
			for (int i = 0; i < count_check; i++) {
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
					file_write();
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
	int x = 27;
	int y = 14;
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
	for (int i = 0; i < count_check; i++) {
			gap_remove();
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

		if (i == 10 || i == 21 || i == 32 || i == 43 || i == 54 || i == 65 || i == 76 || i == 87 || i == 98 || i == count_check -1 ) {
			while (1) {
				gotoxy(22, 4);
				printf("");
				gotoxy(57, 7);
				printf(" ");
				gotoxy(56, 7);
				scanf("%s", choice);
				Sleep(500);
				gotoxy(56, 7);
				printf(" ");
				if (strcmp(choice, "2") == 0) {
					count = 1;
					break;
				}
				else if (strcmp(choice, "N") == 0) {
					if (i == count_check - 1) {
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
					if (i <= 10) {
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
						i = (i - (i % 11)-12);
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
							for (int k = 0; k < count_check; k++) {
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
									strcpy(all[index].user_name, "");
									strcpy(user_seat[index].user_name, "");
									gotoxy(104, 37);
									printf("                                         ");
									gotoxy(112, 39);
									printf("                ");
									gotoxy(106, 37);
									printf("탈퇴가 완료 되었습니다");
									gap_remove();
									file_write();
									count_check--;
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
								for (int k = 0; k < count_check; k++) {
									if (strcmp(all[k].phone_num, phone_num) == 0) {
										index = k;
										strcpy(name, all[index].user_name);
										strcpy(phone_num, all[index].phone_num);
										strcpy(password, all[index].password);
										break;
									}
								}
								if (index == -1) {
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

										gotoxy(104, 37);
										printf("                                         ");
										gotoxy(112, 39);
										printf("                ");
										gotoxy(106, 37);
										printf("저장이 완료되었습니다");
										file_write();
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


