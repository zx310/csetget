/*
 * siren .c
 *
 *  Created on: 2022年5月26日
 *      Author: ZhouXin
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "siren.h"

//! 初始化Fields数组
#define SIREN_INIT_FIELDS()\
	do{\
		ADD_ELEMENT(timeout);\
		ADD_ELEMENT(filename);\
		ADD_ELEMENT(repeat);\
		ADD_ELEMENT(siren_vol);\
	}while(0)

SETTER_GETTER_FUNCTION(Siren, int, timeout)
SETTER_GETTER_FUNCTION(Siren, char*, filename)
SETTER_GETTER_FUNCTION(Siren, int, repeat)
SETTER_GETTER_FUNCTION(Siren, int, siren_vol)

CSET_GET_FUNCTION(Siren, SIREN_INIT_FIELDS)
