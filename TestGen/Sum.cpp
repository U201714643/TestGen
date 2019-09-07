#include "pch.h"
#include "mylib.h"
#include <iostream>

int IntSum(int *num, int *op) {		//�Ա��ʽ����������ֵ
	if (op[0] == OpAdd) {			//��Բ�ͬ�������ֱ�Ӽ��㼴��
		if (op[1] == OpAdd) 
			return num[0] + num[1] + num[2];
		else if (op[1] == OpSub)
			return num[0] + num[1] - num[2];
		else if (op[1] == OpMpl)
			return num[0] + num[1] * num[2];
		else //ֻʣ�³�����
			return num[0] + num[1] / num[2];
	}
	else if (op[0] == OpSub) {		//��Բ�ͬ�������ֱ�Ӽ��㼴��
		if (op[1] == OpAdd)
			return num[0] - num[1] + num[2];
		else if (op[1] == OpSub)
			return num[0] - num[1] - num[2];
		else if (op[1] == OpMpl)
			return num[0] - num[1] * num[2];
		else //ֻʣ�³�����
			return num[0] - num[1] / num[2];
	}
	else if (op[0] == OpMpl) {		//��Բ�ͬ�������ֱ�Ӽ��㼴��
		if (op[1] == OpAdd)
			return num[0] * num[1] + num[2];
		else if (op[1] == OpSub)
			return num[0] * num[1] - num[2];
		else if (op[1] == OpMpl)
			return num[0] * num[1] * num[2];
		else //ֻʣ�³�����
			return num[0] * num[1] / num[2];
	}
	else  {		//ֻʣ�³�����
		if (op[1] == OpAdd)
			return num[0] / num[1] + num[2];
		else if (op[1] == OpSub)
			return num[0] / num[1] - num[2];
		else if (op[1] == OpMpl)
			return num[0] / num[1] * num[2];
		else //ֻʣ�³�����
			return num[0] / num[1] / num[2];
	}
}

double FloatSum(int *num, int *op) {	//�Ա��ʽ���и�������ֵ
	double DoubleNum[3];
	for (int i = 0; i < 3; i++) {		//�Ƚ�����������ת��
		DoubleNum[i] = (double)num[i];
	}
	if (op[0] == OpAdd) {			//��Բ�ͬ�������ֱ�Ӽ��㼴��
		if (op[1] == OpAdd)
			return DoubleNum[0] + DoubleNum[1] + DoubleNum[2];
		else if (op[1] == OpSub)
			return DoubleNum[0] + DoubleNum[1] - DoubleNum[2];
		else if (op[1] == OpMpl)
			return DoubleNum[0] + DoubleNum[1] * DoubleNum[2];
		else //ֻʣ�³�����
			return DoubleNum[0] + DoubleNum[1] / DoubleNum[2];
	}
	else if (op[0] == OpSub) {		//��Բ�ͬ�������ֱ�Ӽ��㼴��
		if (op[1] == OpAdd)
			return DoubleNum[0] - DoubleNum[1] + DoubleNum[2];
		else if (op[1] == OpSub)
			return DoubleNum[0] - DoubleNum[1] - DoubleNum[2];
		else if (op[1] == OpMpl)
			return DoubleNum[0] - DoubleNum[1] * DoubleNum[2];
		else //ֻʣ�³�����
			return DoubleNum[0] - DoubleNum[1] / DoubleNum[2];
	}
	else if (op[0] == OpMpl) {		//��Բ�ͬ�������ֱ�Ӽ��㼴��
		if (op[1] == OpAdd)
			return DoubleNum[0] * DoubleNum[1] + DoubleNum[2];
		else if (op[1] == OpSub)
			return DoubleNum[0] * DoubleNum[1] - DoubleNum[2];
		else if (op[1] == OpMpl)
			return DoubleNum[0] * DoubleNum[1] * DoubleNum[2];
		else //ֻʣ�³�����
			return DoubleNum[0] * DoubleNum[1] / DoubleNum[2];
	}
	else {		//ֻʣ�³�����
		if (op[1] == OpAdd)
			return DoubleNum[0] / DoubleNum[1] + DoubleNum[2];
		else if (op[1] == OpSub)
			return DoubleNum[0] / DoubleNum[1] - DoubleNum[2];
		else if (op[1] == OpMpl)
			return DoubleNum[0] / DoubleNum[1] * DoubleNum[2];
		else //ֻʣ�³�����
			return DoubleNum[0] / DoubleNum[1] / DoubleNum[2];
	}
}