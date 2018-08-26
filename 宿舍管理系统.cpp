#include"stdio.h"

#include"stdlib.h"

#include"string.h"

#include"conio.h"

#define PAGE 3

#define MAX 1000

#define N 5

int k = 0;

/*结构体*/

typedef struct

{
	int num;/*学号*/

	char name[20];/*姓名*/

	char sex[5];/*性别*/

	int age;/*年龄*/

	char studentclass[20];/*班级*/

	int dorm;/*宿舍号*/

}STUDENTS;



int read_file(STUDENTS stu[])

{
	FILE *fp;

	int i = 0;

	if ((fp = fopen("stu.txt", "rt")) == NULL)

	{
		printf("\n\n*****库存文件不存在！请创");

		return 0;

	}

	while (feof(fp) != 1)

	{

		fread(&stu[i], sizeof(STUDENTS), 1, fp);

		if (stu[i].num == 0)

			break;

		else

			i++;

	}

	fclose(fp);

	return i;

}

void save_file(STUDENTS stu[], int sum)

{
	FILE*fp;

	int i;

	if ((fp = fopen("stu.txt", "wb")) == NULL)

	{
		printf("写文件错误!\n");

		return;

	}

	for (i = 0; i<sum; i++)

		if (fwrite(&stu[i], sizeof(STUDENTS), 1, fp) != 1)

			printf("写文件错误!\n");

	fclose(fp);

}





/*创建*/

int input(STUDENTS stu[])

{
	int i, x;

	for (i = 0; i<1000; i++)

	{

		system("cls");

		printf("\n\n                 录入学生信息  (最多%d个)\n", MAX);

		printf("-----------------------------\n");



		printf("\n                     第%d个学生", k + 1);

		printf("\n 请输入学生的学号:");

		scanf("%d", &stu[k].num);

		printf("\n 请输入学生的姓名:");

		scanf("%s", stu[k].name);

		printf("\n 请输入学生的性别:");

		scanf("%s", stu[k].sex);

		printf("\n 请输入学生的年龄:");

		scanf("%d", &stu[k].age);

		printf("\n 请输入学生的班级:");

		scanf("%s", stu[k].studentclass);

		printf("\n 请输入学生的宿舍号:");

		scanf("%d", &stu[k++].dorm);

		printf("\n 请按1键返回菜单或按0键继续创建");

		scanf("%d", &x);

		if (x)

			break;

	}



	return k;

}





/*删除*/

void deletel(STUDENTS stu[])

{
	system("cls");

	char Stuname2[20];

	int i, j;

	printf("请输入学生姓名：");

	scanf("%s", Stuname2);

	printf("\n");

	for (i = 0; i<k; i++)

		if (strcmp(stu[i].name, Stuname2) == 0)

			for (j = 0; j<20; j++)

				stu[i].name[j] = stu[i + 1].name[j];
	k--;




	printf("删除成功\n");

	printf("按任意键加回车返回主菜单!");

	scanf("%d", &i);

	getchar();

}


/*查询*/

void inquire(STUDENTS stu[])

{
	int i;

	int num;

	system("cls");

	printf("     \n\n请输入您要查找的学生的学号");

	scanf("%d", &num);

	for (i = 0; i<k; i++)

		if (num == stu[i].num)

			printf("\n\n\n学号：%d,姓名：%s,性别：%s,年龄：%d,班级：%s,宿舍号: %d\n", stu[i].num, stu[i].name,

				stu[i].sex, stu[i].age, stu[i].studentclass, stu[i].dorm);

	printf("按任意键加回车返回主菜单!");

	scanf("%d", &i);

	getchar();

}





/*修改*/

void change(STUDENTS stu[])

{
	int num, i, choice;

	system("cls");

	printf("\n\n\n      请输入您要修改的学生的学号");

	scanf("%d", &num);

	for (i = 0; i<k; i++)

	{
		if (num == stu[i].num)

			printf("\n学号：%d,姓名：%s,性别：%s,年龄：%d,班级：%s,宿舍号: %d\n", stu[i].num, stu[i].name,

				stu[i].sex, stu[i].age, stu[i].studentclass, stu[i].dorm);



		printf("\n\n\n     ********请输入您想要修改的数据********\n\n");

		printf("                1. 学号\n\n");

		printf("                2. 姓名\n\n");

		printf("                3. 性别\n\n");

		printf("                4. 年龄\n\n");

		printf("                5. 班级\n\n");

		printf("                6. 宿舍号\n\n");

		printf("                 请选择（1-6）:");

		scanf("%d", &choice);

		switch (choice)

		{
		case 1: {

			printf("\n   请输入你改的新学号");

			scanf("%d", &stu[i].num);

			break;

		}

		case 2: {

			printf("\n   请输入你改的新姓名");

			scanf("%s", stu[i].name);

			break;

		}

		case 3: {

			printf("\n   请输入你改的新性别");

			scanf("%s", stu[i].sex);

			break;

		}

		case 4: {

			printf("\n   请输入你改的新年龄");

			scanf("%d", &stu[i].age);

			break;

		}

		case 5: {

			printf("\n   请输入你改的新班级");

			scanf("%s", stu[i].studentclass);

			break;

		}

		case 6: {

			printf("\n   请输入你改的新宿舍");

			scanf("%d", &stu[i].dorm);

			break;

		}

		}



		printf("学号：%d,姓名：%s,性别：%s,年龄：%d,班级：%s,宿舍号: %d\n", stu[i].num, stu[i].name,

			stu[i].sex, stu[i].age, stu[i].studentclass, stu[i].dorm);

		printf("按任意键加回车返回主菜单!");

		scanf("%d", &i);

		break;

	}

}

/*开始页面*/ 
void pagedis()

{

	printf(" \n\n\n                   **********************************\n");

	printf("                   *                                *\n");

	printf("                   *                                *\n");

	printf("                   *                                *\n");

	printf("                   *  欢迎进入学生宿舍信息管理系统  *\n");

	printf("                   *                                *\n");

	printf("                   *                                *\n");

	printf("                   *                                *\n");

	printf("                   **********************************\n");



}

void check()

{

	char userName[5];
	char userPWD[5];

	int i, sum;



	for (i = 1; i < 4; i++)

	{

		printf("   用户名和密码均为123\n\n");

		printf("\n       请输入您的用户名:");

		gets(userName);



		printf("\n       请输入您的密码:");

		gets(userPWD);



		if ((strcmp(userName, "123") == 0) && (strcmp(userPWD, "123") == 0))

		{

			printf("用户名和密码正确，显示主菜单");

			return;

		}

		else

		{

			if (i < 3)

			{

				printf("用户名或密码错误，提示用户重新输入");

				printf("用户名或密码错误，请重新输入!");

			}

			else

			{

				printf("连续3次输错用户名或密码，退出系统。");

				printf("您已连续3次将用户名或密码输错，系统将退出!");

				exit(1);

			}

		}

	}

}

void menu()

{

	STUDENTS stu[20];

	int choice, k, sum;

	sum = read_file(stu);

	if (sum == 0)

	{
		printf("首先录入基本库存信息！按回车后进入*****\n");

		getch();

		sum = input(stu);

	}



	do

	{
		system("cls");

		printf("\n\n\n               ********学生信息管理系统********\n\n");

		printf("                      1. 创建学生信息\n\n");

		printf("                      2. 查询学生信息\n\n");

		printf("                      3. 修改学生信息\n\n");

		printf("                      4. 删除学生信息\n\n");

		printf("                      0. 退出系统\n\n");

		printf("                       请选择（0-6）:");

		scanf("%d", &choice);

		switch (choice)

		{

		case 1: k = input(stu); break;/*创建学生信息*/

		case 2: inquire(stu); break;/*查询学生信息*/

		case 3: change(stu); break;/*修改学生信息*/

		case 4: deletel(stu); break;/*删除学生信息*/

		case 0: break;

		}

	} while (choice != 0);

	save_file(stu, sum);

}

int main()

{





	int i, sum;

	pagedis();

	check();

	menu();
}


