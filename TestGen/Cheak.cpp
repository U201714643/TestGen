#include "pch.h"
#include "mylib.h"
#include <iostream>

//整数判断结果
#define NotInt 0
#define IsInt 1

int IntCheak(double x);				//检测目标浮点数是否为整数

int Cheak(char * Expression, int ResultMin, int ResultMax) {	//检测表达式是否合理（无法整除、为负数、超出范围）
	double Sum = ExpSum(Expression);	//计算
	if (Sum == FERROR)
		return ERROR;	//除以0
	if (Sum  < ResultMin || Sum > ResultMax)
		return ERROR;	//结果超出范围
	if (IntCheak(Sum) == NotInt)
		return ERROR;	//结果不为整数
	return OK;
}

int ResultCheak(int *num, int *op) {	//检测是否存在不合理的（无法整除、为负数、超出范围）结果
	return OK;
}

int IntCheak(double x) {	//检测目标浮点数是否为整数
	if ((x - (int)x) == 0)
		return IsInt;		//二者相等即为整数
	return NotInt;
}