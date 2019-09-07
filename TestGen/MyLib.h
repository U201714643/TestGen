#pragma once
#define OK 0	//正常
#define ERROR 1	//错误

const char OpTxet[][4] = { "＋","﹣","×","÷" };		//用于显示的运算符，注意这些符号是两字节，所以不能直接用char型数组
const int OpAdd = 0, OpSub = 1, OpMpl = 2, OpDiv = 3;	//运算符编号，分别对应"＋","﹣","×","÷"
const int OpMin = 0, OpMax = 3;		//运算符编号的最大、最小值

void Initial();								//初始化函数
int MyRnd(int min, int max);				//生成位于[min,max]之间的整数
int CheakRationality(int *num, int *op);	//检测表达式是否合理
int IntSum(int *num, int *op);				//对表达式进行整数求值
double FloatSum(int *num, int *op);			//对表达式进行浮点数求值