/*用于结构体代码测试*/
#include <stdio.h>
#include <string.h>

struct Student_Info
{
	char no[9];		//学号
	char name[20];	//姓名
	char sex;		//性别
	unsigned int age;
	unsigned int classno; 
	float grade; 
};
struct Student_Info stu[5];

float search_grade(char stunum[])
{
	int i;
	
	for(i = 0; i < 5; i++)
	{
		if(strcmp(stunum,stu[i].no)==0)//判断两个字符串是否相等 
		{
			return stu[i].grade;
		}
	}
	return -1;
}

int main(void)
{	
	float in_grade = 0;
	char ch;
	
	strcpy(stu[0].no,"20020306");
	strcpy(stu[0].name,"lzjtu");
	stu[0].sex = 'M';
	stu[0].age = 40;
	stu[0].classno = 1;
	stu[0].grade = 90;
	
	printf("请输入第2个学生的学号：");
	scanf("%s",stu[1].no); 
	printf("请输入第2个学生的姓名：");
	scanf("%s",stu[1].name); 
	printf("请输入第2个学生的性别：");
	scanf("%s",&stu[1].sex); 
	printf("请输入第2个学生的年龄：");
	scanf("%d",&stu[1].age); 
	printf("请输入第2个学生的班级：");
	scanf("%d",&stu[1].classno); 
	printf("请输入第2个学生的分数：");
	scanf("%f",&stu[1].grade); 
	
	in_grade = search_grade(stu[1].no);
	printf("学号为%s学生的成绩为:%.2f\n",stu[1].no,in_grade);
	return 0;
}
