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
见siren.c和pir.c及main.c
```
