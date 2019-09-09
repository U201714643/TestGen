#include "pch.h"
#include "mylib.h"
#include <iostream>

//�����жϽ��
#define NotInt 0
#define IsInt 1

int IntCheak(double x);				//���Ŀ�긡�����Ƿ�Ϊ����
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
	return OK;
}

int IntCheak(double x) {	//���Ŀ�긡�����Ƿ�Ϊ����
	if ((x - (int)x) == 0)
		return IsInt;		//������ȼ�Ϊ����
	return NotInt;
}