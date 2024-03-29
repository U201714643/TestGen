﻿#include "pch.h"
#include "mylib.h"
#include <iostream>

int main()
{
	Initial();	//初始化包括重置种子等
	/*
	ExpressionNode Exp[EXPNUM] = { 0 };	//用于存放将要生成的表达式
	LeftGen(Exp, 20);*/
	ExpressionNode Exp[EXPNUM] = { 0 };	//用于存放将要生成的表达式
	ExpressionList Arguement;	//生成参数
	Arguement.EqualsNum = 50;
	Arguement.KuoHao = TRUE;
	Arguement.Repeat = FLASE;
	Arguement.NumMax = 100;
	Arguement.NumMin = 0;
	Arguement.OpCount = 3;
	Arguement.OpTypeMax = 3;
	Arguement.OpTypeMin = 0;
	Arguement.ResultMax = 100;
	Arguement.ResultMin = 0;
	TestGen(Exp, &Arguement);
	int j = 0;
	for (int i = 0; i < Arguement.EqualsNum; i++) {
		if (Exp[i].Value == 0)
			j++;
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
