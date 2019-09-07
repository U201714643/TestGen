#include "pch.h"
#include "mylib.h"
#include <iostream>

//С��1/100/100������Ϊ���
#define MaxDelta 1e-7

int Div0(int x, int op, int y);		//����Ƿ���ڳ���0������
int ResultCheak(int *num, int *op);	//����Ƿ���ڲ�����ģ��޷�������Ϊ������������Χ�����

int CheakRationality(int *num, int *op) {	//�����ʽ�Ƿ����
	//-----����Ƿ���ڳ���0������-----
	if (Div0(num[0], op[0], num[1]) == ERROR)	
		return ERROR;
	if (Div0(num[1], op[1], num[2]) == ERROR)
		return ERROR;
	//-----����Ƿ���ڲ�����ģ��޷�������Ϊ������������Χ�����-----
	if (ResultCheak(num, op) == ERROR)
		return ERROR;
	return OK;
}

int Div0(int x, int op, int y) {		//����Ƿ���ڳ���0������
	if (op != OpDiv)
		return OK;		//ֻ�г������ܳ���
	if (y == 0)
		return ERROR;	//����0������
	return OK;			//���򲻻����
}

int ResultCheak(int *num, int *op) {	//����Ƿ���ڲ�����ģ��޷�������Ϊ������������Χ�����
	double DoubleResult = FloatSum(num, op);	//�Ը�������ʾ�Ľ��
	double IntResult = (double)IntSum(num, op);//�ڽ����������������µĽ��
	if (DoubleResult < 0)	//������С��0
		return ERROR;		//�˴�����ʹ�ø��������бȽ�
	if (IntResult > 100)	//���������100
		return ERROR;		//�˴�����ʹ��������
	if (IntResult - DoubleResult > MaxDelta || IntResult - DoubleResult < -MaxDelta)
		return ERROR;		//��ֵ��Ϊ0�����ڸ��������ԣ������ϸ�Ϊ0���������Ϊ0
	return OK;
}