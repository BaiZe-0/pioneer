/*д����ʱҪѧ���ע�ͣ���ĳЩ�ط���ע�Ϳ�����ǿ����ɶ���,������˺��Լ��Ժ��Ķ�^_^*/
#pragma warning(disable:4996);
typedef struct
{
	int course_number;		//�γ̱��
	char course_name[129];	//�γ�����
	int course_hours;		//ѧʱ
	int course_people;		//��ѡ����
} Course;
typedef struct
{
	int student_number;		//ѧ��
	char student_name[129]; //����
	int course_number;		//�γ̱��
} Student;


#include<stdio.h>
#define N 5	//һ��¼��Ŀγ���
#define M 14 //ѡ����Ϣ���鳤��




void main()
{
	Course course[N];	//����������пγ���Ϣ�Ľṹ���� 
	Student student[M];
//�˵���ʼ
	while (1)
	{
		printf("************************ϵͳ�˵�������****************************\n");
		printf("**	1�γ���Ϣ¼��	2�γ���Ϣ��ʾ	3׷��ѡ����Ϣ		**\n");
		printf("**	4��ѯ�γ�	5��ѯѡ����Ϣ	6�޸Ŀγ���Ϣ		**\n");
		printf("**	7ɾ��ѡ����Ϣ	8ͳ��		9�˳�ϵͳ		**\n");
		printf("******************************************************************\n");
		printf("�������ѡ����\n");
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
			printf("\n �Բ�������ѡ���������������룡����\n");
		}
	}
	lam:;
}