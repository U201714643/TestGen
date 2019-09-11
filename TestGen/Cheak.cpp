#include "pch.h"
#include "mylib.h"
#include <iostream>

//�����жϽ��
#define NotInt 0
#define IsInt 1

int IntCheak(double x);				//���Ŀ�긡�����Ƿ�Ϊ����

int Cheak(char * Expression, int ResultMin, int ResultMax) {	//�����ʽ�Ƿ�����޷�������Ϊ������������Χ��
	double Sum = ExpSum(Expression);	//����
	if (Sum == FERROR)
		return ERROR;	//����0
	if (Sum  < ResultMin || Sum > ResultMax)
		return ERROR;	//���������Χ
	if (IntCheak(Sum) == NotInt)
		return ERROR;	//�����Ϊ����
	return OK;
}

int ResultCheak(int *num, int *op) {	//����Ƿ���ڲ�����ģ��޷�������Ϊ������������Χ�����
	return OK;
}

int IntCheak(double x) {	//���Ŀ�긡�����Ƿ�Ϊ����
	if ((x - (int)x) == 0)
		return IsInt;		//������ȼ�Ϊ����
	return NotInt;
}