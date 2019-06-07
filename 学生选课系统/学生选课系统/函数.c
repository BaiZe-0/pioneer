#pragma warning(disable:4996);
typedef struct
{
	int course_number;		//课程编号
	char course_name[128];	//课程名称
	int course_hours;		//学时
	int course_people;		//限选人数
} Course;
typedef struct
{
	int student_number;		//学号
	char student_name[128]; //姓名
	int course_number;		//课程编号
} Student;
#define N 2	//一共录入的课程数
#include<stdio.h>

void fun1(Course * course)		
{
	
	printf("分别输入每门课程的信息包括：课程编号（不能重复）、课程名称、学时（16~80）、限选人数（0~150）。用空格隔开，输入完一门后按回车\n");
	for (int i = 0; i < N; i++)
	{
		printf("输入第%d门课程信息:\n", i + 1);
		scanf("%d%s%d%d", &course[i].course_number, &course[i].course_name, &course[i].course_hours, &course[i].course_people);
		if (i >= 1)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (course[i].course_number == course[j].course_number)
				{
					printf("课程编号重复，重新输入第%d门课程编号：\n", i + 1);
					scanf("%d", &course[i].course_number);
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