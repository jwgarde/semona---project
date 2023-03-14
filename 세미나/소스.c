#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<Windows.h>
#include<time.h>

int change_hour(char* choice_price) {
	int sec = 0;
	if (strcmp(choice_price, "1t") == 0) {
		sec = 3600;
		return sec;
	}
	if (strcmp(choice_price, "3t") == 0) {
		sec = 10800;
		return sec;
	}
	if (strcmp(choice_price, "6t") == 0) {
		sec = 21600;
		return sec;
	}
	if (strcmp(choice_price, "7d") == 0) {
		sec = 626400;
		return sec;
	}
	if (strcmp(choice_price, "14d") == 0) {
		sec = 1209600;
		return sec;
	}
	if (strcmp(choice_price, "30d") == 0) {
		sec = 2592000;
		return sec;
	}
}
int id_pass_check(char *phone_num, char *password) { //유효한 전화번호인지 또는 비밀번호인지 확인하는 함수

	int phone_len = 0;
	int password_len = 0;
	phone_len = strlen(phone_num);
	password_len = strlen(password);
	if (phone_len == 11){
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


int main(void) {
	//char seat[4][10][2][3] = {
		//{{"a1","o"},{"a2","o"},{"a3","o"},{"a4","o"},{"a5","o"},{"a6","o"},{"a7","o"},{"a8","o"},{"a9","o"},{"a10","o"}},
		//{{"b1","o"},{"b2","o"},{"b3","o"},{"b4","o"},{"b5","o"},{"b6","o"},{"b7","o"},{"b8","o"},{"b9","o"},{"b10","o"}},
		//{{"c1","o"},{"c2","o"},{"c3","o"},{"c4","o"},{"c5","o"},{"c6","o"},{"c7","o"},{"c8","o"},{"c9","o"},{"c10","o"}},
		//{{"d1","o"},{"d2","o"},{"d3","o"},{"d4","o"},{"d5","o"},{"d6","o"},{"d7","o"},{"d8","o"},{"d9","o"},{"d10","o"}},
	//};
	int seat[13][12] = {
		{50,1,2,3,4,5,6,7,8,9,10,50},{11,50,50,50,50,50,50,50,50,50,50,12},{13,50,50,50,50,50,50,50,50,50,50,14},
		{15,50,50,50,50,50,50,50,50,50,50,16},{17,50,50,31,32,33,34,35,50,50,50,18},{19,50,50,50,50,50,50,50,50,50,50,20},
		{21,50,50,36,37,38,39,40,50,50,50,22},{23,50,50,50,50,50,50,50,50,50,50,24},{25,50,50,50,50,50,50,50,50,50,50,26},
		{27,50,50,50,50,50,50,50,50,50,50,28},{29,50,50,50,50,50,50,50,50,50,50,30}
	};

	FILE *member;		
	int num = 0; 
	int count = 0;
	int sec = 0;
	int person_count = 0;
	member = fopen("member.txt", "r");
	typedef struct {
		char user_name[20];
		char phone_num[20];
		char password[20];
		int time;
	}user;
	user all[20];	
	for (int i = 0; i < 20; i++) {
		strcpy(all[i].user_name, "");
		strcpy(all[i].phone_num, "");
		strcpy(all[i].password, "");
		fscanf(member, "%s %s %s %d", all[i].user_name, all[i].phone_num, all[i].password,&all[i].time);
		
	}
	char name[20] = "";
	char phone_num[20] = "";
	char password[20] = "";
	char choice_price[3] = "";
	while (1) {
		printf("\n1.회원\n2.관리자\n");
		scanf("%d", &num);
		if (num == 1) {
			while (1) {
				system("cls");
				printf("\n\n1.로그인\n2.회원가입\n3.비밀번호 찾기\n");
				scanf("%d", &num);
				if (num == 2) {
					while (1) {
						system("cls");
						printf("이름 >>");
						scanf("%s", name);
						printf("전화번호>>");
						scanf("%s", phone_num);
						printf("비밀번호 4자리>>");
						scanf("%s", password);
						num = id_pass_check(phone_num, password);
						if (num == 1) {
							for (int k = 0; k < 20; k++) {
								if (strcmp(all[k].phone_num, phone_num) == 0) {
									count = 1;
									break;
								}
							}
							if (count == 1) {
								printf("이미 가입된 전화번호입니다");
								Sleep(3000);
								break; 
							}
							for (int i = 0; i < 20; i++) {
								if (strcmp(all[i].user_name, "") == 0) {
									strcpy(all[i].user_name, name);
									strcpy(all[i].phone_num, phone_num);
									strcpy(all[i].password, password);
									all[i].time = 0;
									member = fopen("member.txt", "a");
									fprintf(member, "\n%s %s %s %d", all[i].user_name, all[i].phone_num, all[i].password,all[i].time);
									fclose(member);
									break;
								}
								
							}

						}
						else {
							printf("전화번호 혹은 비밀번호를 형식에 맞게 입력 ");
							Sleep(3000);
							continue;
						}
						printf("회원가입이 완료 되었습니다!!!\n");
						Sleep(3000);
						break;
					}
					continue;
				}
				if (num == 1) {

					while (1) {
						system("cls");
						printf("\n");
						printf("전화번호 입력 >>");
						scanf("%s", phone_num);
						printf("비밀번호 입력>>");
						for (int k = 0; k < 4; k++) {
							password[k] = _getch();
							printf("*");
						}
						for (int i = 0; i < 20; i++) {
							if (strcmp(phone_num, all[i].phone_num) == 0 && strcmp(password, all[i].password) == 0) {
								count = 1;
								break;
							}
							else {
								count = 2;
							}
						}  
						if (count == 1) {
							for (int i = 0; i < 20; i++) {
								if (strcmp(all[i].user_name, "") != 0) {
									person_count += 1;
								}
							}
							
							
							Sleep(2000);
							printf("\n로그인 성공 !!\n");
							Sleep(3000);
							system("cls");
							while (1) {
								//for (int i = 0; i < 4; i++) {
									//for (int k = 0; k < 10; k++) {
										//printf("%s %s\t", seat[i][k][0], seat[i][k][1]);
									//}
									//printf("\n\n");
								//}
								printf("\n\n1.좌석 이용권 구매\n2.입실\n3.퇴실");
								scanf("%d",&num);
								if (num == 1) {
									Sleep(2000);
									system("cls");
									printf("\t\t기간제\n");
									printf("7d:30000원\t14d:50000\t30d:90000");
									printf("\n\n\n\n\t\t시간제\n");
									printf("1t:2000원\t3t:3000원\t6t:6000원");
									printf("\n\n\n\t요금입력 >>");
									scanf("%s", choice_price);
									if (choice_price[1] == 't') {
										sec = change_hour(choice_price);
										member = fopen("member.txt", "w");
										for (int i = 0; i < person_count; i++) {
											if (strcmp(all[i].phone_num, phone_num) == 0) {
												all[i].time += sec;
											}
											fprintf(member, "\n%s %s %s %d", all[i].user_name, all[i].phone_num, all[i].password, all[i].time);
										}
									}
									//else if (choice_price[1] == 'd' || choice_price[2] == 'd') {

									//}
									fclose(member);
									system("cls");
									printf("충전이 완료되었습니다");
									Sleep(2000);
									system("cls");			
								}

							}
						}
						else {
							printf("\n일치하는 전화번호 혹은 비밀번호를 찾을 수 없습니다\n\n");
							Sleep(3000);
							system("cls");
							printf("1.계속 시도\n2.돌아가기\n>>");
							scanf("%d",&num);
							if (num == 1) {
								Sleep(3000);
								continue;
							}
							if (num == 2) {
								Sleep(3000);
								break;
							}
						}
					}
				}
				if (num == 3) {
					while (1) {
						system("cls");
						printf("이름을 입력해주세요>>");
						scanf("%s",name);
						printf("전화번호를 입력해주세요>>");
						scanf("%s",phone_num);
						for (int i = 0; i < 20; i++) {
							if (strcmp(name, all[i].user_name) == 0 && strcmp(phone_num, all[i].phone_num) == 0) {
								printf("비밀번호는 %s입니다", all[i].password);
								count = 0;
								Sleep(3000);
								break;
							}
							else {
								count = 1;
							}
						}
						if (count == 1) {
							printf("찾을 수 없습니다\n");
							Sleep(3000);
							system("cls");
							printf("1.계속 시도\n2.돌아가기\n>>");
							scanf("%d", &num);
							if (num == 1) {
								Sleep(3000);
								continue;
							}
							if (num == 2) {
								Sleep(3000);
								break;
							}
						}
						break;
					}
				}
			}
		}
	}
}