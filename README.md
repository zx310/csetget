# csetget
实现通过结构体元素相同名字的字符串修改或者获取结构体元素的数据
例如有学生结构体，学生结构体包含年龄、姓名、性别、班级、成绩、外号
声明如下：
```
#define AGE	age
#define NAME	name
#define SEX	sex
#define CLASS   class
#define MARK	mark
#define ALIAS	alias
#define FIELDS_NUMBER	(6)
typedef struct
{
	int AGE;
	char NAME[16];
	int SEX;
	int CLASS;
	float MARK;
	char alias[16];
}Student_s;
```
假设有一个学生叫zhouxin，那么就需要提供API 供外部调用获取他的各种信息，一般地，例如MQTT推送topic要获取姓名，mqtt payload包含"name"字符串，如果可以直接通过这个"name"字符串获取到学生的name，那么就很完美了。csetget就是为了实现这一功能而实现。可以通过字符串name获取到实际的name，通过字符串age获取到实际的age，等等。
# 注意
结构体目前不支持char*的元素，建议使用char数组。
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
