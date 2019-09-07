#include "pch.h"
#include "mylib.h"
#include <iostream>

int IntSum(int *num, int *op) {		//对表达式进行整数求值
	if (op[0] == OpAdd) {			//针对不同的运算符直接计算即可
		if (op[1] == OpAdd) 
			return num[0] + num[1] + num[2];
		else if (op[1] == OpSub)
			return num[0] + num[1] - num[2];
		else if (op[1] == OpMpl)
			return num[0] + num[1] * num[2];
		else //只剩下除法了
			return num[0] + num[1] / num[2];
	}
	else if (op[0] == OpSub) {		//针对不同的运算符直接计算即可
		if (op[1] == OpAdd)
			return num[0] - num[1] + num[2];
		else if (op[1] == OpSub)
			return num[0] - num[1] - num[2];
		else if (op[1] == OpMpl)
			return num[0] - num[1] * num[2];
		else //只剩下除法了
			return num[0] - num[1] / num[2];
	}
	else if (op[0] == OpMpl) {		//针对不同的运算符直接计算即可
		if (op[1] == OpAdd)
			return num[0] * num[1] + num[2];
		else if (op[1] == OpSub)
			return num[0] * num[1] - num[2];
		else if (op[1] == OpMpl)
			return num[0] * num[1] * num[2];
		else //只剩下除法了
			return num[0] * num[1] / num[2];
	}
	else  {		//只剩下除法了
		if (op[1] == OpAdd)
			return num[0] / num[1] + num[2];
		else if (op[1] == OpSub)
			return num[0] / num[1] - num[2];
		else if (op[1] == OpMpl)
			return num[0] / num[1] * num[2];
		else //只剩下除法了
			return num[0] / num[1] / num[2];
	}
}

double FloatSum(int *num, int *op) {	//对表达式进行浮点数求值
	double DoubleNum[3];
	for (int i = 0; i < 3; i++) {		//先进行数据类型转换
		DoubleNum[i] = (double)num[i];
	}
	if (op[0] == OpAdd) {			//针对不同的运算符直接计算即可
		if (op[1] == OpAdd)
			return DoubleNum[0] + DoubleNum[1] + DoubleNum[2];
		else if (op[1] == OpSub)
			return DoubleNum[0] + DoubleNum[1] - DoubleNum[2];
		else if (op[1] == OpMpl)
			return DoubleNum[0] + DoubleNum[1] * DoubleNum[2];
		else //只剩下除法了
			return DoubleNum[0] + DoubleNum[1] / DoubleNum[2];
	}
	else if (op[0] == OpSub) {		//针对不同的运算符直接计算即可
		if (op[1] == OpAdd)
			return DoubleNum[0] - DoubleNum[1] + DoubleNum[2];
		else if (op[1] == OpSub)
			return DoubleNum[0] - DoubleNum[1] - DoubleNum[2];
		else if (op[1] == OpMpl)
			return DoubleNum[0] - DoubleNum[1] * DoubleNum[2];
		else //只剩下除法了
			return DoubleNum[0] - DoubleNum[1] / DoubleNum[2];
	}
	else if (op[0] == OpMpl) {		//针对不同的运算符直接计算即可
		if (op[1] == OpAdd)
			return DoubleNum[0] * DoubleNum[1] + DoubleNum[2];
		else if (op[1] == OpSub)
			return DoubleNum[0] * DoubleNum[1] - DoubleNum[2];
		else if (op[1] == OpMpl)
			return DoubleNum[0] * DoubleNum[1] * DoubleNum[2];
		else //只剩下除法了
			return DoubleNum[0] * DoubleNum[1] / DoubleNum[2];
	}
	else {		//只剩下除法了
		if (op[1] == OpAdd)
			return DoubleNum[0] / DoubleNum[1] + DoubleNum[2];
		else if (op[1] == OpSub)
			return DoubleNum[0] / DoubleNum[1] - DoubleNum[2];
		else if (op[1] == OpMpl)
			return DoubleNum[0] / DoubleNum[1] * DoubleNum[2];
		else //只剩下除法了
			return DoubleNum[0] / DoubleNum[1] / DoubleNum[2];
	}
}