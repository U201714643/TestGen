#include "pch.h"
#include "mylib.h"
#include <iostream>

int MyRnd(int min, int max) {	//生成位于[min,max]之间的整数
	int length = max - min + 1;	//注意区间长度需要加1
	return rand() % length + min;	//区间内取数再加上起点即为范围内随机数
}