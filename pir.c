/*
 * pir.c
 *
 *  Created on: 2022年5月26日
 *      Author: ZhouXin
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "pir.h"

//! 初始化Fields数组
#define PIR_INIT_FIELDS() \
	do{\
		ADD_ELEMENT(pir_sensitivity);\
		ADD_ELEMENT(pir_enable);\
	  }while(0)

//static set get函数实现
SETTER_GETTER_FUNCTION(Pir, int, pir_sensitivity)
SETTER_GETTER_FUNCTION(Pir, int, pir_enable)
//API
CSET_GET_FUNCTION(Pir, PIR_INIT_FIELDS)
