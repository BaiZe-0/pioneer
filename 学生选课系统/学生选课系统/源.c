/*写程序时要学会加注释，在某些地方加注释可以增强代码可读性,方便别人和自己以后阅读^_^*/
#pragma warning(disable:4996);
typedef struct
{
	int course_number;		//课程编号
	char course_name[129];	//课程名称
	int course_hours;		//学时
	int course_people;		//限选人数
} Course;
typedef struct
{
	int student_number;		//学号
	char student_name[129]; //姓名
	int course_number;		//课程编号
} Student;


#include<stdio.h>
#define N 5	//一共录入的课程数
#define M 14 //选课信息数组长度




void main()
{
	Course course[N];	//用来存放所有课程信息的结构数组 
	Student student[M];
//菜单起始
	while (1)
	{
		printf("************************系统菜单功能项****************************\n");
		printf("**	1课程信息录入	2课程信息显示	3追加选课信息		**\n");
		printf("**	4查询课程	5查询选课信息	6修改课程信息		**\n");
		printf("**	7删除选课信息	8统计		9退出系统		**\n");
		printf("******************************************************************\n");
		printf("输入序号选择功能\n");
		int choice;
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			fun1(course);
			break;
		case 2:
			fun2(course);
			break;
		case 3:
			fun3(student,course);
			break;
		case 4:
			fun4(course);
			break;
		case 5:
			fun5(student);
			break;
		case 6:
			fun6(course);
			break;
		case 7:
			fun7(student);
			break;
		case 8:
			fun8(student);
			break;
		case 9:
			goto lam;
		default:
			printf("\n 对不起，您的选择有误，请重新输入！！！\n");
		}
	}
	lam:;
}