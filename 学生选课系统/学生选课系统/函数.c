#pragma warning(disable:4996);
typedef struct
{
	int course_number;		//�γ̱��
	char course_name[128];	//�γ�����
	int course_hours;		//ѧʱ
	int course_people;		//��ѡ����
} Course;
typedef struct
{
	int student_number;		//ѧ��
	char student_name[128]; //����
	int course_number;		//�γ̱��
} Student;
#define N 2	//һ��¼��Ŀγ���
#include<stdio.h>

void fun1(Course * course)		
{
	
	printf("�ֱ�����ÿ�ſγ̵���Ϣ�������γ̱�ţ������ظ������γ����ơ�ѧʱ��16~80������ѡ������0~150�����ÿո������������һ�ź󰴻س�\n");
	for (int i = 0; i < N; i++)
	{
		printf("�����%d�ſγ���Ϣ:\n", i + 1);
		scanf("%d%s%d%d", &course[i].course_number, &course[i].course_name, &course[i].course_hours, &course[i].course_people);
		if (i >= 1)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (course[i].course_number == course[j].course_number)
				{
					printf("�γ̱���ظ������������%d�ſγ̱�ţ�\n", i + 1);
					scanf("%d", &course[i].course_number);
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