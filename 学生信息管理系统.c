#include<stdio.h>
#include<string.h>
#define STARS "*****************"
#define MAX 50
void menu(void);//菜单
void typein(void);//输入
void display(void);//读取
void save(void);//保存
void search(void);//查询
void exit(void);//退出
void deletedata(void);//删除
void deletedate_number(void);//删除-学号检索
void deletedate_name(void);//删除-姓名检索
void name_search(void);//查询-姓名
void phone_search(void);//查询-手机号码
void number_search(void);//查询-成绩
void age_search(void);//查询-年龄
void score1_search(void);//查询-高数
void score2_search(void);//查询-英语
void score3_search(void);//查询-C语言
void score4_search(void);//查询-体育
void score5_search(void);//查询-课设
void revise(void);//编辑
void rank(void);//排序
void rank_number(void);//排序-学号
void rank_course1(void);//排序-高等数学
void rank_course2(void);//排序-英语
void rank_course3(void);//排序-C语言
void rank_course4(void);//排序-体育
void rank_course5(void);//拍学-课程设计
void revise_number(void);//编辑-学号查询
void revise_name(void);//编辑-姓名查询
int revise_number_choice(void);//编辑-学号查询-选择功能
int revise_name_choice(void);//编辑-姓名查询-选择功能
int count = 0;
int main()
{
	printf("\n%s%s\n", STARS, STARS);
	printf("       欢迎使用学生信息管理系统\n");
	printf("       制作人：殷建平 李文涛\n");
	menu();
	return 0;
}
typedef struct
{
	long int number;
	char name[20];
	char sex[10];
	int  age;
	char phone[20];
	int score1;//MATH
	int score2;//ENGLISH
	int score3;//C LANGUAGE
	int score4;//PE
	int score5;//COURESE PROJECT
}STUDENT;
STUDENT student[MAX];
void menu(void)
{
	int choice;
	printf("\n%s%s\n", STARS, STARS);
	printf("       请输入数字选择功能：\n");
	printf("       1)学生信息录入\n");//完成
	printf("       2)保存学生信息\n");//完成
	printf("       3)显示学生信息\n");//完成
	printf("       4)编辑学生信息\n");//完成
	printf("       5)删除学生信息\n");//完成
	printf("       6)学生信息排序\n");//完成
	printf("       7)查找学生信息\n");//完成
	printf("       8)退出系统\n");//完成
	printf("%s%s\n", STARS, STARS);
	printf("请输入数字选择");
	scanf("%d", &choice);
	getchar();//防止输入错误导致程序死循环
	switch (choice)
	{
	case 1: 
		typein();     
		menu(); 
		break;
	case 2: 
		save();        
		menu();
		break;
	case 3:
		display();    
		menu(); 
		break;
	case 4: 
		revise();     
		menu(); 
		break;
	case 5: 
		deletedata();
		menu();
		break;
	case 6: 
		rank();
		menu();
		break;
	case 7: 
		search();    
		menu(); 
		break;
	case 8: 
		exit(); 
		return; 
	default:
		printf("输入错误！请重新输入\n");
		menu();
	}
}
void typein(void)
{
	printf("输入学号");
	scanf("%ld", &student[count].number);
	printf("输入姓名");
	scanf("%s", &student[count].name);
	printf("输入性别");
	scanf("%s", &student[count].sex);
	printf("输入年龄");
	scanf("%d", &student[count].age);
	getchar();//防止输入错误导致程序死循环
	printf("输入手机号码");
	scanf("%s", &student[count].phone);
	getchar();
	printf("输入高等数学成绩");
	scanf("%d", &student[count].score1);
	getchar();
	printf("输入英语成绩");
	scanf("%d", &student[count].score2);
	getchar();
	printf("输入C语言成绩");
	scanf("%d", &student[count].score3);
	getchar();
	printf("输入体育成绩");
	scanf("%d", &student[count].score4);
	getchar();
	printf("输入课程设计成绩");
	scanf("%d", &student[count].score5);
	getchar();
	count++;
}
void display()
{
	int i;

	FILE *fp;
	fp = fopen("D:\\student.txt", "r+");
	if (fp == NULL)
		printf("打开文件失败!");
	else
	{
		i = 0;
		while (!feof(fp))
		{
			fread(&student[i], sizeof(STUDENT), 1, fp);
			i++;
			count++;
		}
		count--;
		printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
		for (i = 0; i<count; i++)
		{
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
		}
	}
}
void save()
{
	int i = 0; FILE *fp;
	fp = fopen("D:\\student.txt", "w+");
	for (i = 0; i<count; i++)
		if (fwrite(&student[i], sizeof(STUDENT), 1, fp) != 1)
			printf("无法操作文件!\n");
	printf("你已经成功保存文件!"); fclose(fp);
}
void search(void)
{
	printf("\n%s%s\n", STARS, STARS);
	printf("       请输入数字选择查询方式：\n");
	printf("       1)学号查询\n");
	printf("       2)姓名查询\n");
	printf("       3)年龄查询\n");
	printf("       4)手机号码查询\n");
	printf("       5)数学成绩查询\n");
	printf("       6)英语成绩查询\n");
	printf("       7)C语言成绩查询\n");
	printf("       8)体育成绩查询\n");
	printf("       9)课程设计成绩查询\n");
	printf("       10)返回上一级菜单\n");
	printf("%s%s\n", STARS, STARS);
	printf("请输入数字选择");
	int n;
	scanf("%d", &n);
	getchar();
	switch (n)
	{
	case 1: number_search();  break;
	case 2: name_search();  break;
	case 3: age_search(); break;
	case 4: phone_search(); break;
	case 5: score1_search(); break;
	case 6: score2_search(); break;
	case 7: score3_search(); break;
	case 8: score4_search(); break;
	case 9: score5_search(); break;
	case 10: break;
	default:
	    {
		printf("输入错误！请重新输入\n");
		search();
	    }
	}
}
void name_search()
{
	char name[20];
	int match = 0;
	printf("请输入查询的姓名");
	scanf("%s", &name);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (strcmp(student[i].name, name) == 0)
		{
			match++;
			printf("\n%s%s\n", STARS, STARS);
			printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			printf("\n%s%s\n", STARS, STARS);
		}
	if (match == 0)
		printf("错误！无法查找到匹配数据");
}
void phone_search()
{
	char phone[20];
	int match = 0;
	printf("请输入查询的手机号码");
	scanf("%s", &phone);
	getchar();
	int i;
	for (i = 0; i <= count; i++)
		if (strcmp(student[i].phone, phone) == 0)
		{
			match++;
			printf("\n%s%s\n", STARS, STARS);
			printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			printf("\n%s%s\n", STARS, STARS);
		}
	if (match == 0)
		printf("错误！无法查找到匹配数据");
}
void number_search()
	{
		long int number;
		int match = 0;
		printf("请输入查询的学号");
		scanf("%ld", &number);
		getchar();
		int i;
		for (i = 0; i <= count; i++)
			if (student[i].number == number)
			{
				match++;
				printf("\n%s%s\n", STARS, STARS);
				printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
				printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
					student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
				printf("\n%s%s\n", STARS, STARS);
			}
		if (match==0)
		printf("错误！无法查找到匹配数据");
	}
void age_search()
	{
		int age;
		int match = 0;
		printf("请输入查询的年龄");
		scanf("%d", &age);
		getchar();
		int i;
		for (i = 0; i <= count; i++)
			if (student[i].age == age)
			{
				match++;
				printf("\n%s%s\n", STARS, STARS);
				printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
				printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
					student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
				printf("\n%s%s\n", STARS, STARS);
			}
		if (match == 0)
			printf("错误！无法查找到匹配数据");
	}
void score1_search()
	{
		int score1;
		int match = 0;
		printf("请输入查询的高等数学成绩");
		scanf("%d", &score1);
		getchar();
		int i;
		for (i = 0; i <= count; i++)
			if (student[i].score1 == score1)
			{
				match++;
				printf("\n%s%s\n", STARS, STARS);
				printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
				printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
					student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
				printf("\n%s%s\n", STARS, STARS);
			}
		if (match == 0)
			printf("错误！无法查找到匹配数据");
	}
void score2_search()
	{
		int score2;
		int match = 0;
		printf("请输入查询的英语成绩");
		scanf("%d", &score2);
		getchar();
		int i;
		for (i = 0; i <= count; i++)
		{
			match++;
			printf("\n%s%s\n", STARS, STARS);
			printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
			printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
				student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
			printf("\n%s%s\n", STARS, STARS);
		}
		if (match == 0)
			printf("错误！无法查找到匹配数据");
	}
void score3_search()
	{
		int score3;
		int match = 0;
		printf("请输入查询的C语言成绩");
		scanf("%d", &score3);
		getchar();
		int i;
		for (i = 0; i <= count; i++)
			if (student[i].score3 == score3)
			{
				match++;
				printf("\n%s%s\n", STARS, STARS);
				printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
				printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
					student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
				printf("\n%s%s\n", STARS, STARS);
			}
		if (match == 0)
			printf("错误！无法查找到匹配数据");
	}
void score4_search()
	{
		int score4;
		int match = 0;
		printf("请输入查询的体育成绩");
		scanf("%d", &score4);
		getchar();
		int i;
		for (i = 0; i <= count; i++)
			if (student[i].score4 == score4)
			{
				match++;
				printf("\n%s%s\n", STARS, STARS);
				printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
				printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
					student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
				printf("\n%s%s\n", STARS, STARS);
			}
		if (match == 0)
			printf("错误！无法查找到匹配数据");
	}
void score5_search()
	{
		int score5;
		int match = 0;
		printf("请输入查询的课程设计成绩");
		scanf("%d", &score5);
		getchar();
		int i;
		for (i = 0; i <= count; i++)
			if (student[i].score5 == score5)
			{
				match++;
				printf("\n%s%s\n", STARS, STARS);
				printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
				printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
					student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
				printf("\n%s%s\n", STARS, STARS);
			}
		if (match == 0)
			printf("错误！无法查找到匹配数据");
	}
void revise()
	{
		int choice;
		printf("\n%s%s\n", STARS, STARS);
		printf("       请输入数字选择功能\n");
		printf("       1)输入学号查找编辑对象\n");
		printf("       2)输入姓名查找编辑对象\n");
		printf("       3)返回上一级菜单\n");
		printf("\n%s%s\n", STARS, STARS);
		printf("请输入数字选择");
		scanf("%d", &choice);
		getchar();
		switch (choice)
		{
		case 1: revise_number(); break;
		case 2: revise_name(); break;
		case 3:menu(); break;
		default:
		    {
			printf("输入错误！请重新输入\n");
			revise();
		    }
		}
	}
void rank(void)
{
	printf("\n%s%s\n", STARS, STARS);
	printf("       请输入数字选择排序方式\n");
	printf("       1)根据学号进行排序\n");
	printf("       2)根据高等数学成绩排序\n");
	printf("       3)根据英语成绩排序\n");
	printf("       4)根据C语言成绩排序\n");
	printf("       5)根据体育成绩进行排序\n");
	printf("       6)根据课程设计成绩进行排序\n");
	printf("       7)返回上一级菜单\n");
	printf("%s%s\n", STARS, STARS);
	printf("请输入数字选择");
	int t;
	scanf("%d", &t);
	getchar();
	switch (t)
	{
	case 1:
		rank_number();
		break;
	case 2:
		rank_course1();
		break;
	case 3:
		rank_course2();
		break;
	case 4:
		rank_course3();
		break;
	case 5:
		rank_course4();
		break;
	case 6:
		rank_course5();
		break;
	case 7:
		menu();
		break;
	default:
		printf("输入错误！请重新输入\n");
		rank();
	}
}
void rank_number(void)
{
	int i, j;
	STUDENT t;
	for (j = 0; j<count - 1; j++)
		for (i = j + 1; i<count; i++)
			if (student[i].number<student[j].number)
			{
				t = student[i];
				student[i] = student[j];
				student[j] = t;
			}
	printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
	for (i = 0; i<count; i++)
	{
		printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
			student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
	}
}
void rank_course1(void)
{
	int i, j;
	STUDENT t;
	for (j = 0; j<count - 1; j++)
		for (i = j + 1; i<count; i++)
			if (student[i].score1<student[j].score1)
			{
				t = student[i];
				student[i] = student[j];
				student[j] = t;
			}
	printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
	for (i = 0; i<count; i++)
	{
		printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
			student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
	}
}
void rank_course2(void)
{
	int i, j;
	STUDENT t;
	for (j = 0; j<count - 1; j++)
		for (i = j + 1; i<count; i++)
			if (student[i].score2<student[j].score2)
			{
				t = student[i];
				student[i] = student[j];
				student[j] = t;
			}
	printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
	for (i = 0; i<count; i++)
	{
		printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
			student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
	}
}
void rank_course3(void)
{
	int i, j;
	STUDENT t;
	for (j = 0; j<count - 1; j++)
		for (i = j + 1; i<count; i++)
			if (student[i].score3<student[j].score3)
			{
				t = student[i];
				student[i] = student[j];
				student[j] = t;
			}
	printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
	for (i = 0; i<count; i++)
	{
		printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
			student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
	}
}
void rank_course4(void)
{
	int i, j;
	STUDENT t;
	for (j = 0; j<count - 1; j++)
		for (i = j + 1; i<count; i++)
			if (student[i].score4<student[j].score4)
			{
				t = student[i];
				student[i] = student[j];
				student[j] = t;
			}
	printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
	for (i = 0; i<count; i++)
	{
		printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
			student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
	}
}
void rank_course5(void)
{
	int i, j;
	STUDENT t;
	for (j = 0; j<count - 1; j++)
		for (i = j + 1; i<count; i++)
			if (student[i].score5<student[j].score5)
			{
				t = student[i];
				student[i] = student[j];
				student[j] = t;
			}
	printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
	for (i = 0; i<count; i++)
	{
		printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
			student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
	}
}
void revise_number(void)
	{
		long int number;
		int match = 0;
		int n;
		printf("请输入查询的学号");
		scanf("%ld", &number);
		getchar();
		int i;
		for (i = 0; i <= count; i++)
			if (student[i].number == number)
			{
				match++;
				printf("\n%s%s\n", STARS, STARS);
				printf("查找到的学生信息");
				printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
				printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
					student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
				n=revise_number_choice();
				switch (n)
				{
				case 0: revise();  break;
				case 1:
					printf("修改后的姓名为");
					scanf("%s", &student[i].name);
					break;
				case 2:
					printf("修改后的性别为");
					scanf("%s", &student[i].sex);
					break;
				case 3:
					printf("修改后的年龄为");
					scanf("%d", &student[i].age);
					break;
				case 4:
					printf("修改后的手机号码为");
					scanf("%s", &student[i].phone);
					break;
				case 5:
					printf("修改后的高等数学成绩为");
					scanf("%d", &student[i].score1);
					break;
				case 6:
					printf("修改后的英语成绩为");
					scanf("%d", &student[i].score2);
					break;
				case 7:
					printf("修改后的C语言成绩为");
					scanf("%d", &student[i].score3);
					break;
				case 8:
					printf("修改后的体育成绩为");
					scanf("%d", &student[i].score4);
					break;
				case 9:
					printf("修改后的课程设计为");
					scanf("%d", &student[i].score5);
					break;
				default:
				{
					printf("输入错误！请重新输入\n");
					revise_number_choice();
				}
				}
			}
			
		if (match == 0)
		{
			printf("错误！无法查找到匹配数据");
			revise();
		}
	}
int revise_number_choice(void)
	{
		printf("\n%s%s\n", STARS, STARS);
		printf("       输入数字选择要更改的内容\n");
		printf("       0)放弃修改并返回上一级菜单\n");
		printf("       1)修改姓名\n");
		printf("       2)修改性别\n");
		printf("       3)修改年龄\n");
		printf("       4)修改手机号码\n");
		printf("       5)修改高等数学成绩\n");
		printf("       6)修改英语成绩\n");
		printf("       7)修改C语言成绩\n");
		printf("       8)修改体育成绩\n");
		printf("       9)修改课程设计成绩\n");
		printf("\n%s%s\n", STARS, STARS);
		int t;
		scanf("%d", &t);
		getchar();
		return t;
	}
void revise_name(void)
	{
		char name[20];
		int match = 0;
		int n;
		printf("请输入查询的姓名");
		scanf("%s", &name);
		getchar();
		int i;
		for (i = 0; i <= count; i++)
			if (strcmp(student[i].name,name) == 0)
			{
				match++;
				printf("\n%s%s\n", STARS, STARS);
				printf("查找到的学生信息");
				printf("\n学号\t\t姓名\t性别\t年龄\t手机号码\t高等数学成绩   英语成绩   C语言成绩   体育成绩   课程设计成绩\n");
				printf("\n%ld\t%s %s\t%d\t%s\t     %d          %d         %d           %d          %d ", student[i].number, student[i].name, student[i].sex, student[i].age, student[i].phone,
					student[i].score1, student[i].score2, student[i].score3, student[i].score4, student[i].score5);
				n = revise_name_choice();
				switch (n)
				{
				case 0: revise();  break;
				case 1:
					printf("修改后的学号为");
					scanf("%ld", &student[i].number);
					break;
				case 2:
					printf("修改后的性别为");
					scanf("%s", &student[i].sex);
					break;
				case 3:
					printf("修改后的年龄为");
					scanf("%d", &student[i].age);
					break;
				case 4:
					printf("修改后的手机号码为");
					scanf("%s", &student[i].phone);
					break;
				case 5:
					printf("修改后的高等数学成绩为");
					scanf("%d", &student[i].score1);
					break;
				case 6:
					printf("修改后的英语成绩为");
					scanf("%d", &student[i].score2);
					break;
				case 7:
					printf("修改后的C语言成绩为");
					scanf("%d", &student[i].score3);
					break;
				case 8:
					printf("修改后的体育成绩为");
					scanf("%d", &student[i].score4);
					break;
				case 9:
					printf("修改后的课程设计为");
					scanf("%d", &student[i].score5);
					break;
				default:
					printf("输入错误！请重新输入\n");
					revise_number_choice();
				}
			}
		if (match == 0)
		{
			printf("错误！无法查找到匹配数据");
			revise();
		}
	}
int revise_name_choice(void)
	{
		printf("\n%s%s\n", STARS, STARS);
		printf("       输入数字选择要更改的内容\n");
		printf("       0)放弃修改并返回上一级菜单\n");
		printf("       1)修改学号\n");
		printf("       2)修改性别\n");
		printf("       3)修改年龄\n");
		printf("       4)修改手机号码\n");
		printf("       5)修改高等数学成绩\n");
		printf("       6)修改英语成绩\n");
		printf("       7)修改C语言成绩\n");
		printf("       8)修改体育成绩\n");
		printf("       9)修改课程设计成绩\n");
		printf("\n%s%s\n", STARS, STARS);
		int t;
		scanf("%d", &t);
		getchar();
		return t;
	}
void deletedata(void)
	{
	printf("\n%s%s\n", STARS, STARS);
	printf("       输入数字选择功能\n");
	printf("       1)输入学号选择删除条目\n");
	printf("       2)输入姓名选择删除条目\n");
	printf("       3)取消删除返回上一级菜单");
	printf("\n%s%s\n", STARS, STARS);
	printf("请输入数字选择");
	int t;
	scanf("%d", &t);
	getchar();
	switch (t)
	{
	case 1:
		deletedate_number();
		break;
	case 2:
		deletedate_name();
		break;
	case 3:	
		menu();
		break;
	default:
		printf("输入错误！请重新输入\n");
		deletedata();
	}
	}
void deletedate_number(void)
{
	printf("请输入学生学号");
	long int number;
	int match = 0;
	int i,j;
	scanf("%ld", &number);
	for (i = 0; i <= count; i++)
		if (student[i].number == number)
		{
			for (j = i; j < count; j++)
				student[j] = student[j + 1];
			printf("已成功删除！");
			match++;
			break;
		}
	if (match == 0)
	{
		printf("错误！无法查找到匹配数据");
		deletedata();
	}
}
void deletedate_name(void)
{
	printf("请输入学生姓名");
	char name[20];
	int match = 0;
	scanf("%s", &name);
	int i, j;
	for (i = 0; i <= count; i++)
		if (strcmp(student[i].name, name) == 0)
		{
			for (j = i; j < count; j++)
				student[j] = student[j + 1];
			printf("已成功删除！");
			match++;
			break;
		}
	if (match == 0)
	{
		printf("错误！无法查找到匹配数据");
		deletedata();
	}
}
void exit()
{
	int choice;
	printf("\n%s%s\n", STARS, STARS);
	printf("确定要退出本系统么？\n");
	printf("       请输入数字决定是否退出\n");
	printf("       1)确认退出\n");
	printf("       2)返回上一级菜单\n");
	printf("\n%s%s\n", STARS, STARS);
	printf("请输入数字选择");
	scanf("%d", &choice);
	getchar();
	switch (choice)
	{
	case 1: {printf("感谢您的使用！再见！"); break; break; }
	case 2: menu(); break;
	default:
	{
		printf("输入错误！请重新输入\n");
		exit();
	}
	}
}
