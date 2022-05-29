/*
 * siren .h
 *
 *  Created on: 2022年5月26日
 *      Author: ZhouXin
 */

#ifndef SIREN_H_
#define SIREN_H_
#include <string.h>
#include "csetget.h"

#define SIREN_FIELDS_NUMBER	(4)

typedef struct
{
	int timeout;
	char filename[16];
	int repeat;
	int siren_vol;
}Siren;

//! set get直接调用API
SETTER_GETTER_DEFINITION(Siren);

#endif /* SIREN_H_ */
