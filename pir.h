/*
 * pir.h
 *
 *  Created on: 2022年5月26日
 *      Author: ZhouXin
 */

#ifndef PIR_H_
#define PIR_H_
#include <string.h>
#include "csetget.h"

#define PIR_FIELDS_NUMBER	(2)

typedef struct
{
	int pir_sensitivity;
	int pir_enable;
}Pir;

//! set get直接调用API
SETTER_GETTER_DEFINITION(Pir);

#endif /* PIR_H_ */
