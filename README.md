# csetget
实现通过结构体元素相同名字的字符串修改或者获取结构体元素的数据
# example code:
```
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
```
