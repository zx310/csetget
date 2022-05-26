#ifndef CSETGET_H_
#define CSETGET_H_

//! 转字符串工具
#define STR(x)  #x

#define AGE		age
#define NAME	name
#define SEX		sex
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

//! setter callback function defination
//! set函数类型定义
typedef  void (*SetFunc)(Student_s *ptr, void* in, int size);
typedef  void (*GetFunc)(Student_s *ptr, void* out);

typedef struct
{
	//! The string for each element is stored here
	//! 每个元素对应的字符串存放在这里
	char* name;
	//! The set function for each element is stored here
	//! 每个元素对应的set函数存放在这里
	SetFunc set_func;
	//! The get function for each element is stored here
	//! 每个元素对应的get函数存放在这里
	GetFunc get_func;
}SetParam_s;

//! Setter and Getter Macro definition， Make your code cleaner
//! set_##name and set_##index are supported. set_ #index is not easy to use,
//! you can't tell from the function name which element the function sets as an argument.
//! set和get函数宏定义，使代码更简洁
//! 支持set_##name和set_##index, set##index不太好使用，无法通过函数名知道这个函数是设置哪个元素的参数.
#define SETTER_GETTER(argType, name, index)\
	void    set_##name(Student_s *ptr, void* in, int size)  {memcpy(&ptr->name, in, size);}\
	void    set_##index(Student_s *ptr, void* in, int size) {memcpy(&ptr->name, in, size);}\
	argType get_##name(Student_s *ptr)				   	    {return ptr->name;}\
	void 	get_##index(Student_s *ptr, void* out)		    {memcpy(out, &ptr->name, sizeof(ptr->name));}

//! Parameters used to initialize Fields
//! 用于初始化Fields各个参数
#define SET_NAME(name)	 STR(name)
#define SET_FUNC(index)  set_##index
#define GET_FUNC(index)  get_##index
#define INIT_SET_FIELD(name, index) init_fields(SET_NAME(name), SET_FUNC(index), GET_FUNC(index), index)

//! ------------------------------------PORT------------------------------------
//! 移植需要修改如下代码
//! set get函数原型
SETTER_GETTER(int, AGE, 0)
SETTER_GETTER(char*, NAME, 1)
SETTER_GETTER(int, SEX, 2)
SETTER_GETTER(int, CLASS, 3)
SETTER_GETTER(float, MARK, 4)
SETTER_GETTER(char*, ALIAS, 5)

//! 初始化Fields数组
#define INIT_FIELDS()\
	do{\
		INIT_SET_FIELD(AGE, 0);\
		INIT_SET_FIELD(NAME, 1);\
		INIT_SET_FIELD(SEX, 2);\
		INIT_SET_FIELD(CLASS, 3);\
		INIT_SET_FIELD(MARK, 4);\
		INIT_SET_FIELD(ALIAS, 5);\
	}while(0)

//! ------------------------------------PORT------------------------------------
//! ------------------------------------API-------------------------------------
//! set API 可供外部调用
#define SET(name, index, arg, v, size)  set_##index(arg, v, size)
#define SET2(index, arg, v, size)  set_##index(arg, v, size)
//! get API 可供外部调用
#define GET(name, arg)  get_##name(arg)
#define GET2(index, arg, out)  get_##index(arg, out)

/**
 * @fn void set(char*, Student_s*, void*, int)
 * @brief
 * 			API 用于外部调用设置结构体元素数据
 * @param name		外部协议支持的 字符串，必须与Fields元素同名
 * @param stu		需要修改元素的结构体指针
 * @param value		数据指针
 * @param size		数据大小，结构用sizeof后传入，字符串用strlen后传入
 */
void set(char* name, Student_s* ptr, void* value, int size);
/**
 * @fn void get(char*, Student_s*, void*)
 * @brief
 * 		API, 用于外部调用获取结构体元素数据
 * @param name		外部协议支持的 字符串，必须与Fields元素同名
 * @param stu		需要修改元素的结构体指针
 * @param value		数据指针
 */
void get(char* name, Student_s* ptr, void* out);
//! ------------------------------------API-------------------------------------
#endif /* CSETGET_H_ */
