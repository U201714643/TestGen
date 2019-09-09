#include "pch.h"
#include "mylib.h"
#include <iostream>

int LengthOfInt(int x);		//整数的十进制长度

int TestGen(ExpressionNode * Address, ExpressionList * Arguements)	//地址调用、提高效率
{	//生成表达式
	int SprintfLengthMax = LengthOfInt(Arguements->NumMax) + 1;	//会生成的最大整数长度
	for (int i = 0; i < Arguements->EqualsNum; i++) {	//生成算式的数目
		NumNode * num;	//用于存放数字
		int * op;		//用于存放操作符
		//---------空间分配---------
		if ((num = (NumNode *)malloc(sizeof(NumNode)*(Arguements->OpCount + 2))) == NULL) {
			//数字数应比操作符数（不含括号）多1
			exit(OVERFLOW);		//空间不足，退出
		}
		if ((op = (int *)malloc(sizeof(int)*(Arguements->OpCount + 1))) == NULL) {
			exit(OVERFLOW);		//空间不足，退出
		}
		//---------生成操作符和操作数---------
		for (int j = 0; j < Arguements->OpCount + 1; j++) {
			num[j].Num = MyRnd(Arguements->NumMin, Arguements->NumMax);	//随机生成[NumMin,NumMax]内整数
			num[j].KuoHao = 0;	//最初显然无括号
		}
		for (int j = 0; j < Arguements->OpCount; j++) {
			op[j] = MyRnd(Arguements->OpTypeMin, Arguements->OpTypeMax);//随机生成运算符
		}
		//---------生成括号---------
		if (Arguements->KuoHao == TRUE) {
			int KuoHaoNum = MyRnd(1, Arguements->OpCount / 2 + 1);	//括号数目
			for (int j = 0; j < KuoHaoNum; j++) {
				int NumLeft = MyRnd(0, Arguements->OpCount);	//添加左括号的位置
				int NumRight = MyRnd(0, Arguements->OpCount);	//添加右括号的位置
				if ((NumLeft >= NumRight) || (num[NumLeft].KuoHao > 0) || (num[NumRight].KuoHao < 0)) {
					j--;	//不能为同一个数同时添加左、右括号,左括号还必须位于右括号的左侧（一次生成中）
					continue;
				}
				num[NumLeft].KuoHao--;	//添加左括号
				num[NumRight].KuoHao++;	//添加右括号
			}
		}
		//---------生成字符串形式的表达式---------
		char *t = Address[i].Expression;	//获得字符串首地址
		for (int j = 0; j < Arguements->OpCount + 1; j++) {
			int step = 0;	//记录sprinf函数造成的指针移动
			//---------生成左侧括号---------
			while (num[j].KuoHao < 0) {
				*t = '(';
				num[j].KuoHao++;//更新标记
				t++;	//移动指针	
			}
			//---------生成数字---------
			step = sprintf_s(t, SprintfLengthMax, "%d", num[j].Num);
			t += step;	//移动指针	
			//---------生成右侧括号---------
			while (num[j].KuoHao > 0) {
				*t = ')';
				num[j].KuoHao--;//更新标记
				t++;	//移动指针	
			}
			//---------生成算符---------
			if (j != Arguements->OpCount) {	//最后无需生成算符
				*t = OpTxetN[op[j]];
				t++;	//移动指针
			}
			*t = 0;	//封闭字符串
		}
		i++;
		i--;
	}
	return 0;
}

int LengthOfInt(int x) {		//整数的十进制长度
	int l = 0;
	while (x) {
		//每次减少一个十进制位
		x = x / 10;
		l++;
	}
	return l;
}