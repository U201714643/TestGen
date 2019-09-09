#include "pch.h"
#include "mylib.h"
#include <iostream>

//整数判断结果
#define NotInt 0
#define IsInt 1

int IntCheak(double x);				//检测目标浮点数是否为整数
int Div0(int x, int op, int y);		//检测是否存在除以0的现象
int ResultCheak(int *num, int *op);	//检测是否存在不合理的（无法整除、为负数、超出范围）结果

int CheakRationality(int *num, int *op) {	//检测表达式是否合理
	//-----检测是否存在除以0的现象-----
	if (Div0(num[0], op[0], num[1]) == ERROR)	
		return ERROR;
	if (Div0(num[1], op[1], num[2]) == ERROR)
		return ERROR;
	//-----检测是否存在不合理的（无法整除、为负数、超出范围）结果-----
	if (ResultCheak(num, op) == ERROR)
		return ERROR;
	return OK;
}

int Div0(int x, int op, int y) {		//检测是否存在除以0的现象
	if (op != OpDiv)
		return OK;		//只有除法可能出错
	if (y == 0)
		return ERROR;	//除以0即出错
	return OK;			//否则不会出错
}

int ResultCheak(int *num, int *op) {	//检测是否存在不合理的（无法整除、为负数、超出范围）结果
	return OK;
}

int IntCheak(double x) {	//检测目标浮点数是否为整数
	if ((x - (int)x) == 0)
		return IsInt;		//二者相等即为整数
	return NotInt;
}