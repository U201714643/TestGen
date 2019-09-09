#include "pch.h"
#include "mylib.h"
#include <iostream>

int TestGen(ExpressionNode * Address, ExpressionList * Arguements)
{	//生成表达式的主体函数
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
				if (NumLeft == NumRight) {
					j--;	//不能为同一个数同时添加左、右括号
					continue;
				}
				if (num[NumLeft].KuoHao > 0) {
					j--;	//不能为同一个数同时添加左、右括号
					continue;
				}
				if (num[NumRight].KuoHao < 0) {
					j--;	//不能为同一个数同时添加左、右括号
					continue;
				}
			}
		}
	}
	return 0;
}
