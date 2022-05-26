#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "multi2one.h"

//! The set function that holds the corresponding string
//! 用于存放对应字符串的set函数
static SetParam_s Fields[FIELDS_NUMBER];

/**
 * 	@fn void init_fields(char*, set_func, int)
 * @brief
 * 		初始化Fields
 * @param name	初始化的字符串传入值
 * @param func	初始化set函数传入值
 * @param index 初始化数组下标，从0开始
 */
static void init_fields(char* name, SetFunc set_func, GetFunc get_func, int index)
{
	if(index >= FIELDS_NUMBER)
	{
		return;
	}
	Fields[index].name = name;
	Fields[index].set_func = set_func;
	Fields[index].get_func = get_func;
}
/**
 * @fn void set(char*, Student_s*, void*, int)
 * @brief
 * 			API 用于外部调用设置结构体元素数据
 * @param name		外部协议支持的 字符串，必须与Fields元素同名
 * @param stu		需要修改元素的结构体指针
 * @param value		数据指针
 * @param size		数据大小，结构用sizeof后传入，字符串用strlen后传入
 */
void set(char* name, Student_s* ptr, void* value, int size)
{
	for(int i = 0; i < FIELDS_NUMBER; i++)
	{
		if(strncmp(Fields[i].name, name, strlen(Fields[i].name)) == 0)
		{
			if(NULL != Fields[i].set_func)
			{
				Fields[i].set_func(ptr, value, size);
			}
		}
	}
}
/**
 * @fn void get(char*, Student_s*, void*)
 * @brief
 * 		API, 用于外部调用获取结构体元素数据
 * @param name		外部协议支持的 字符串，必须与Fields元素同名
 * @param stu		需要修改元素的结构体指针
 * @param value		数据指针
 */
void get(char* name, Student_s* ptr, void* out)
{
	for(int i = 0; i < FIELDS_NUMBER; i++)
	{
		if(strncmp(Fields[i].name, name, strlen(Fields[i].name)) == 0)
		{
			if(NULL != Fields[i].get_func)
			{
				Fields[i].get_func(ptr, out);
			}
		}
	}
}

int main(void)
{
	Student_s zhouxin = {0};

	INIT_FIELDS();
	for(int i = 0; i < FIELDS_NUMBER; i++)
	{
		printf("FiledsStr[%d]:%s\n", i, Fields[i].name);
	}
	printf("age:%d\n",zhouxin.age);
	printf("name:%s\n",zhouxin.name);
	printf("sex:%d\n",zhouxin.sex);
	printf("class:%d\n",zhouxin.class);
	printf("mark:%0.1f\n",zhouxin.mark);
	printf("alias:%s\n",zhouxin.alias);

	int age1 = 100;
	char* name1 = "zhoudaxin";
	char* alias1 = "haha";
	set(STR(age), &zhouxin, &age1, sizeof(age1));
	set("name", &zhouxin, name1, strlen(name1));
	set("alias", &zhouxin, alias1, strlen(alias1));
	printf("set age:%d\n",zhouxin.age);
	printf("set name:%s\n",zhouxin.name);
	printf("set alias:%s\n",zhouxin.alias);

	int age2;
	char name2[16];
	char alias2[16];
	memset(name2, '\0', sizeof(name2));
	memset(alias2, '\0', sizeof(alias2));
	get("age", &zhouxin, &age2);
	get("name", &zhouxin, name2);
	get("alias", &zhouxin, alias2);
	printf("get age:%d\n",age2);
	printf("get name:%s\n",name2);
	printf("get alias:%s\n",alias2);

	return EXIT_SUCCESS;
}
