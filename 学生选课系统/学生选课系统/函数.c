#pragma warning(disable:4996);
typedef struct
{
	int course_number1;		//课程编号
	char course_name[128];	//课程名称
	int course_hours;		//学时
	int course_people;		//限选人数
} Course;
typedef struct
{
	int student_number;		//学号
	char student_name[128]; //姓名
	int course_number2;		//课程编号
} Student;
#define N 5	//一共录入的课程数
#define M 14 //选课信息数组长度
#include<stdio.h>
#include <string.h> 


void fun1(Course * course)		
{
	
	printf("分别输入每门课程的信息包括：课程编号（不能重复）、课程名称、学时（16~80）、限选人数（0~150）。用空格隔开，输入完一门后按回车\n");
	for (int i = 0; i < N; i++)
	{
		printf("输入第%d门课程信息:\n", i + 1);
		scanf("%d%s%d%d", &course[i].course_number1, &course[i].course_name, &course[i].course_hours, &course[i].course_people);
		if (i >= 1)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (course[i].course_number1 == course[j].course_number1)
				{
					printf("课程编号重复，重新输入第%d门课程编号：\n", i + 1);
					scanf("%d", &course[i].course_number1);
					j = i;	//从头开始比较
				}
			}
		}
		while (course[i].course_hours < 16 || course[i].course_hours>80)
		{
			printf("输入学时有误，重新输入第%d门课程学时,要求在16~80之间\n" ,i+1);
			scanf("%d", &course[i].course_hours);
		}
		while (course[i].course_people < 0 || course[i].course_people>150)
		{
			printf("输入限选人数有误，重新输入第%d门课程限选人数，要求在0~150之间\n",i+1);
			scanf("%d", &course[i].course_people);
		}
	}
	
}
void fun2(Course * course)
{
	printf("显示内容依次为：课程编号、课程名称、学时、限选人数\n");
	for (int i = 0; i < N; i++)
	{
		printf("%d %s %d %d\n", course[i].course_number1, course[i].course_name, course[i].course_hours, course[i].course_people);
	}
}
void fun3(Student * student,Course * course)
{
	int sum[N] = { 0 };
	printf("分别输入学号、姓名、课程编号，用空格隔开，输入完后按回车\n");
	for (int i = 0; i < M; i++)
	{
		printf("输入第%d项选课信息:\n", i + 1);
		scanf("%d%s%d",&student[i].student_number,&student[i].student_name,&student[i].course_number2 );
		if (i >= 1)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (student[i].course_number2 == student[j].course_number2&&student[i].student_number == student[j].student_number)
				{
					printf("学号和课程编号同时重复，重新输入第%d项选课信息,依次输入学号、姓名、课程编号：\n", i + 1);
					scanf("%d%s%d", &student[i].student_number, &student[i].student_name, &student[i].course_number2);
					j = i;	//从头开始比较
				}
			}
		}

		int k;
		while (1)
		{
			for (k = 0; k < N; k++)
			{
				if (student[i].course_number2 == course[k].course_number1)
					break;
			}
			sum[k]=sum[k]+1;
			
			if (sum[k] > course[k].course_people)
			{
				printf("编号为%d的课程超过限定人数，更改所选课程编号：\n", course[k].course_number1);
				scanf("%d", &student[i].course_number2);
			}
			else
				break;
		}

	}
	for (int l = 0; l < M; l++)
		printf("%d %s %d\n", student[l].student_number, student[l].student_name, student[l].course_number2);

}
void fun4(Course * course)
{
	printf("输入要查询的课程名称：\n");
	char mingzi[128];
	scanf("%s", mingzi);
	
		int temp = 0;
		for (int i = 0; i < N; i++)
		{
			if (strstr(course[i].course_name, mingzi) != NULL)
			{
				temp++;
				printf("%d %s %d %d\n", course[i].course_number1, course[i].course_name, course[i].course_hours, course[i].course_people);
			}
		}
		if (temp == 0)
			printf("无相关课程信息\n");
}
void fun5(Student * student)
{
	printf("输入学号：\n");
	int xuehao;
	scanf("%d", &xuehao);
	int temp = 0;
	for (int i = 0; i < M; i++)
	{
		if (xuehao==student[i].student_number)
		{
			temp++;
			printf("%d %s %d\n", student[i].student_number, student[i].student_name, student[i].course_number2);
		}
	}
	if (temp == 0)
		printf("无相关学生信息\n");
	
}
void fun6(Course * course)
{
	printf("输入课程编号：\n");
	int kcbh;
	scanf("%d",&kcbh);
	int i;
	int temp=0;
	for (i = 0; i < N; i++)
		if (kcbh == course[i].course_number1)
			break;
		else
			temp++;
	if (temp == N)		printf("没有该课程\n");
	printf("将编号为%d的课程的学时、限选人数分别修改为：（空格间隔）\n", course[i].course_number1);
	scanf("%d %d", &course[i].course_hours, &course[i].course_people);
}
void fun7(Student * student)
{
	printf("输入学号：\n");
	int xuehao;
	scanf("%d", &xuehao);
	int temp = 0;
	for (int i = 0; i < M; i++)
	{
		if (xuehao == student[i].student_number)
		{
			temp++;
			memset(&student[i],NULL, sizeof(Student));
		}
	}
	if (temp == 0)
		printf("无相关学生信息\n");
	for (int i = 0; i < M; i++)
	{
		printf("%d %s %d\n", student[i].student_number, student[i].student_name, student[i].course_number2);
	}
}
void fun8(Student * student)
{
	printf("输入课程编号：\n");
	int bianhao;
	scanf("%d",& bianhao);
	int i;
	int temp = 0;
	for (i = 0; i < M; i++)
	{
		if (bianhao == student[i].course_number2)
			printf("%d %s\n", student[i].student_number, student[i].student_name);
		else
			temp++;
	}
	if (temp == M)		printf("没有该课程\n");
	printf("总人数为%d\n", M - temp);
}

