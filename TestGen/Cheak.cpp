#include "pch.h"
#include "mylib.h"
#include <iostream>

//小于1/100/100即可视为误差
#define MaxDelta 1e-7

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
	double DoubleResult = FloatSum(num, op);	//以浮点数表示的结果
	double IntResult = (double)IntSum(num, op);//在仅仅保留整数部分下的结果
	if (DoubleResult < 0)	//不允许小于0
		return ERROR;		//此处宜于使用浮点数进行比较
	if (IntResult > 100)	//不允许大于100
		return ERROR;		//此处宜于使用整型数
	if (IntResult - DoubleResult > MaxDelta || IntResult - DoubleResult < -MaxDelta)
		return ERROR;		//差值不为0（对于浮点数而言，不会严格为0）即结果不为0
	return OK;
}