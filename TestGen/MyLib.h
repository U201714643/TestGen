#pragma once
#define OK 0		//正常
#define ERROR -1	//错误
#define OVERFLOW -2	//溢出
#define FLASE 0		//为假
#define TRUE 1		//为真
#define EXPLEN 120	//表达式最大长度

typedef struct NumNode {	//生成表达式时基于该数字结构
	int Num;	//数字自身
	int KuoHao;	//左右括号结合情况：0无括号，正数为右侧括号，负数为左侧括号
};

typedef struct ExpressionNode {	//生成的表达式
	char Expression[EXPLEN];	//表达式
	int result;		//计算结果
	int left;		//余数，仅用于带余数除法，否则为0
};

typedef struct ExpressionList {	//生成表达式使用的参数表
	int EqualsNum;	//生成的表达式数目
	int OpCount;	//操作符数目
	int OpTypeMin;	//操作符种类范围
	int OpTypeMax;	//操作符种类范围
	int NumMin;		//操作数范围
	int NumMax;		//操作数范围
	int ResultMin;	//结果范围
	int ResultMax;	//结果范围
	int KuoHao;		//是否允许括号
};

const char OpTxet[][4] = { "＋","﹣","×","÷" };	//用于显示的运算符，注意这些符号是两字节，所以不能直接用char型数组
const char OpTxetN[4] = { '+','-','*','//' };		//用于显示的运算符，'//'代表除号“/”
const int OpAdd = 0, OpSub = 1, OpMpl = 2, OpDiv = 3;	//运算符编号，分别对应"＋","﹣","×","÷"
const int OpMin = 0, OpMax = 3;		//运算符编号的最大、最小值

void Initial();								//初始化函数
int MyRnd(int min, int max);				//生成位于[min,max]之间的整数
int CheakRationality(int *num, int *op);	//检测表达式是否合理
int IntSum(int *num, int *op);				//对表达式进行整数求值
double FloatSum(int *num, int *op);			//对表达式进行浮点数求值
double ExpSum(char * Expression);			//对表达式进行整数求值