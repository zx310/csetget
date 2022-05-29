/*
 * main.c
 *
 *  Created on: 2022年5月26日
 *      Author: ZhouXin
 */
#include <stdio.h>
#include "siren.h"
#include "pir.h"
int main()
{
	Siren stu;
	Siren_csetget_init();
	int timeout = 100;
	char* filename = "zhouxin";
	Siren_set("timeout", &stu, &timeout, sizeof(timeout));
	Siren_set("filename", &stu, filename, strlen(filename));
	printf("set timeout: %d\n", stu.timeout);
	printf("set filename: %s\n", stu.filename);
	int timeout2;
	char* filename1;
	Siren_get("timeout", &stu, &timeout2);
	Siren_get("filename", &stu, filename1);
	printf("get timeout: %d\n", timeout2);
	printf("get filename: %s\n", filename1);
	printf("end\n");
}
