//预计编程时间：45分钟
//实际编程时间：1小时19分钟(主要花时间解决了运算符和结果比例显然不平均的问题)
#include "pch.h"
#include "mylib.h"
#include <iostream>

int ma2in()
{
	Initial();	//初始化包括重置种子等
	for (int i = 0; i < 300; i++) {	//生成300个算式
		int num[3], op[2];			//随机生成的[0,100]内整数和运算符
		for (int j = 0; j < 3; j++) {
			num[j] = MyRnd(0, 100);	//随机生成[0,100]内整数
		}
		for (int j = 0; j < 2; j++) {
			op[j] = MyRnd(OpMin, OpMax);//随机生成运算符
		}
		while (CheakRationality(num, op) == ERROR) {
			for (int j = 0; j < 3; j++) {
				num[j] = MyRnd(1, 100);	//为避免改变运算符号的分布频率，当出现不合理的表达式时应仅仅重新生成数据而不改变运算符
				//同时为了避免出现过多的0，修改了重新赋值的下限
			}
		}
		printf("第%d题：%d%s%d%s%d＝%d\n", i + 1 , num[0], OpTxet[op[0]], num[1], OpTxet[op[1]], num[2], IntSum(num, op));	//显示生成的结果
	}
	return 0;
}
