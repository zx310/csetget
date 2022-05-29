/*
 * multi2one.h
 *
 *  Created on: 2022年5月25日
 *      Author: ZhouXin
 */

#ifndef CSETGET_H_
#define CSETGET_H_

//! 转字符串工具
#define STR(x)  #x

/**
 * @fn void (*)(void*, void*, int)
 * @brief
 * 			结构体元素，set函数指针声明
 * @param ptr   结构体指针
 * @param in	设置的数据指针
 * @param size	设置的数据大小
 */
typedef	void (*SetFunc)(void *ptr, void* in, int size);
/**
 * @fn void (*)(void*, void*, int)
 * @brief
 * 			结构体元素，get函数指针声明
 * @param ptr   结构体指针
 * @param out	获取的数据传入该数据指针
 */
typedef void (*GetFunc)(void *ptr, void* out);

/**
 * @struct
 * @brief
 * 		结构体每个元素对应的set get函数
 */
typedef struct SetGetParam
{
	char* name;  //结构体元素匹配字符串，默认是与元素名称一样
	SetFunc set_func; //set函数
	GetFunc get_func; //get函数
	struct SetGetParam* next;
}SetGetParam_s;

/**
 * @def SETTER_GETTER_API
 * @brief
 * 		 set和get函数声明宏定义, 后面三个函数会声明多次，但是没有影响
 */
#define SETTER_GETTER_DEFINITION(STRUCT_NAME)	\
	void STRUCT_NAME##_csetget_init();\
	void STRUCT_NAME##_set(char* name, STRUCT_NAME* ptr, void* value, int size);\
	void STRUCT_NAME##_get(char* name, STRUCT_NAME* ptr, void* out);\

/**
 * @def SETTER_GETTER
 * @brief
 * 	  set和get函数具体实现宏定义，使代码更简洁
 *    支持set_##name和set_##index, set##index不太好使用，无法通过函数名知道这个函数是设置哪个元素的参数.
 */
#define SETTER_GETTER_FUNCTION(STRUCT_NAME, argType, name)\
	static void set_##name(STRUCT_NAME *ptr, void* in, int size) {memcpy(&ptr->name, in, size);}\
	static void get_##name(STRUCT_NAME *ptr, void* out)          {memcpy(out, &ptr->name, sizeof(ptr->name));}


/**
 * @def CSET_FUNCTION
 * @brief
 *		set函数实现宏定义
 */
#define  CSET_GET_FUNCTION(STRUCT_NAME, INIT) \
	static SetGetParam_s* Fields=NULL;\
	static void printf_element()\
		{\
		    SetGetParam_s* next_element = Fields;\
		   for (; next_element; next_element = next_element->next)\
		   {\
				   printf("%s\n", next_element->name);\
		   }\
		}\
	static void add_element(char* name, void* set_func, void* get_func)\
	{\
		SetGetParam_s* new_element = (SetGetParam_s*)malloc(sizeof(SetGetParam_s));\
		new_element->name = name;\
		new_element->set_func = set_func;\
		new_element->get_func = get_func;\
	    SetGetParam_s** next_element = NULL;\
	   for (next_element = &Fields;;next_element = &(*next_element)->next)\
	   {\
		   if (!*next_element) {\
			   new_element->next = NULL;\
			   *next_element = new_element;\
			   break;\
		   }\
	   }\
	}\
	void STRUCT_NAME##_csetget_init()\
	{\
		INIT();\
		printf_element();\
	}\
	void STRUCT_NAME##_set(char* name, STRUCT_NAME* ptr, void* value, int size)\
	{\
		SetGetParam_s* next_element = Fields;\
		for (; next_element; next_element = next_element->next) {\
			if(strncmp(next_element->name, name, strlen(next_element->name)) == 0){\
				next_element->set_func(ptr, value, size);\
				break;\
			}\
		}\
	} \
	void STRUCT_NAME##_get(char* name, STRUCT_NAME* ptr, void* out)\
		{\
		SetGetParam_s* next_element = Fields;\
		for (; next_element; next_element = next_element->next) {\
			if(strncmp(next_element->name, name, strlen(next_element->name)) == 0){\
				next_element->get_func(ptr, out);\
				break;\
			}\
		}\
		}

//! 用于初始化Fields各个参数
#define SET_NAME(name)	 STR(name)
#define SET_FUNC(index)  set_##index
#define GET_FUNC(index)  get_##index
#define ADD_ELEMENT(name) add_element(SET_NAME(name), SET_FUNC(name), GET_FUNC(name))

#endif /* CSETGET_SIREN_H_ */
