#pragma warning(disable:4996);
typedef struct
{
	int course_number1;		//�γ̱��
	char course_name[128];	//�γ�����
	int course_hours;		//ѧʱ
	int course_people;		//��ѡ����
} Course;
typedef struct
{
	int student_number;		//ѧ��
	char student_name[128]; //����
	int course_number2;		//�γ̱��
} Student;
#define N 5	//һ��¼��Ŀγ���
#define M 14 //ѡ����Ϣ���鳤��
#include<stdio.h>
#include <string.h> 


void fun1(Course * course)		
{
	
	printf("�ֱ�����ÿ�ſγ̵���Ϣ�������γ̱�ţ������ظ������γ����ơ�ѧʱ��16~80������ѡ������0~150�����ÿո������������һ�ź󰴻س�\n");
	for (int i = 0; i < N; i++)
	{
		printf("�����%d�ſγ���Ϣ:\n", i + 1);
		scanf("%d%s%d%d", &course[i].course_number1, &course[i].course_name, &course[i].course_hours, &course[i].course_people);
		if (i >= 1)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (course[i].course_number1 == course[j].course_number1)
				{
					printf("�γ̱���ظ������������%d�ſγ̱�ţ�\n", i + 1);
					scanf("%d", &course[i].course_number1);
					j = i;	//��ͷ��ʼ�Ƚ�
				}
			}
		}
		while (course[i].course_hours < 16 || course[i].course_hours>80)
		{
			printf("����ѧʱ�������������%d�ſγ�ѧʱ,Ҫ����16~80֮��\n" ,i+1);
			scanf("%d", &course[i].course_hours);
		}
		while (course[i].course_people < 0 || course[i].course_people>150)
		{
			printf("������ѡ�����������������%d�ſγ���ѡ������Ҫ����0~150֮��\n",i+1);
			scanf("%d", &course[i].course_people);
		}
	}
	
}
void fun2(Course * course)
{
	printf("��ʾ��������Ϊ���γ̱�š��γ����ơ�ѧʱ����ѡ����\n");
	for (int i = 0; i < N; i++)
	{
		printf("%d %s %d %d\n", course[i].course_number1, course[i].course_name, course[i].course_hours, course[i].course_people);
	}
}
void fun3(Student * student,Course * course)
{
	int sum[N] = { 0 };
	printf("�ֱ�����ѧ�š��������γ̱�ţ��ÿո������������󰴻س�\n");
	for (int i = 0; i < M; i++)
	{
		printf("�����%d��ѡ����Ϣ:\n", i + 1);
		scanf("%d%s%d",&student[i].student_number,&student[i].student_name,&student[i].course_number2 );
		if (i >= 1)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (student[i].course_number2 == student[j].course_number2&&student[i].student_number == student[j].student_number)
				{
					printf("ѧ�źͿγ̱��ͬʱ�ظ������������%d��ѡ����Ϣ,��������ѧ�š��������γ̱�ţ�\n", i + 1);
					scanf("%d%s%d", &student[i].student_number, &student[i].student_name, &student[i].course_number2);
					j = i;	//��ͷ��ʼ�Ƚ�
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
				printf("���Ϊ%d�Ŀγ̳����޶�������������ѡ�γ̱�ţ�\n", course[k].course_number1);
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
	printf("����Ҫ��ѯ�Ŀγ����ƣ�\n");
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
			printf("����ؿγ���Ϣ\n");
}
void fun5(Student * student)
{
	printf("����ѧ�ţ�\n");
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
		printf("�����ѧ����Ϣ\n");
	
}
void fun6(Course * course)
{
	printf("����γ̱�ţ�\n");
	int kcbh;
	scanf("%d",&kcbh);
	int i;
	int temp=0;
	for (i = 0; i < N; i++)
		if (kcbh == course[i].course_number1)
			break;
		else
			temp++;
	if (temp == N)		printf("û�иÿγ�\n");
	printf("�����Ϊ%d�Ŀγ̵�ѧʱ����ѡ�����ֱ��޸�Ϊ�����ո�����\n", course[i].course_number1);
	scanf("%d %d", &course[i].course_hours, &course[i].course_people);
}
void fun7(Student * student)
{
	printf("����ѧ�ţ�\n");
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
		printf("�����ѧ����Ϣ\n");
	for (int i = 0; i < M; i++)
	{
		printf("%d %s %d\n", student[i].student_number, student[i].student_name, student[i].course_number2);
	}
}
void fun8(Student * student)
{
	printf("����γ̱�ţ�\n");
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
	if (temp == M)		printf("û�иÿγ�\n");
	printf("������Ϊ%d\n", M - temp);
}

