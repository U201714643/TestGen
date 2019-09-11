#include "pch.h"
#include "mylib.h"
#include <iostream>

//�����жϽ��
#define NotInt 0
#define IsInt 1

int IntCheak(double x);				//���Ŀ�긡�����Ƿ�Ϊ����

int AnsCheak(char * Expression, int ResultMin, int ResultMax) {	//�����ʽ�Ƿ�����޷�������Ϊ������������Χ��
	double Sum = ExpSum(Expression);	//����
	if (Sum == FERROR)
		return ERROR;	//����0
	if (Sum  < ResultMin || Sum > ResultMax)
		return ERROR;	//���������Χ
	if (Sum == 0 && MyRnd(1, 10) != 2)
		return ERROR;	//����ֵΪ0��ʽ��
	if (IntCheak(Sum) == NotInt)
		return ERROR;	//�����Ϊ����
	return OK;
}

int KuoHaoCheak(int NumLeft, int NumRight, int OpCount, NumNode * num) {	//��������Ƿ����
	if (NumLeft >= NumRight)
		return ERROR;	//�����ű���������������Ҳ�
	if ((num[NumLeft].KuoHao > 0) || (num[NumRight].KuoHao < 0))
		return ERROR;	//ͬһ�����ֲ���ͬʱ���������Ű�Χ
	if (NumLeft == 0 && NumRight == OpCount)
		return ERROR;	//���Ų���ֱ�Ӱ���������ʽ
	if (num[NumLeft].KuoHao == -num[NumRight].KuoHao && num[NumLeft].KuoHao < 0)	//�������޴�����
		return ERROR;	//���ܳ���˫������
	return OK;
}

int RepeatCheak(ExpressionNode * Address, int Num) {	//�����ʽ�Ƿ��ظ�
	for (int i = 0; i < Num; i++) {
		if (strcmp(Address[i].Expression, Address[Num].Expression) == 0) {
			return ERROR;	//�ַ�����ȣ������ظ�
		}
	}
	return OK;
}

int IntCheak(double x) {	//���Ŀ�긡�����Ƿ�Ϊ����
	if ((x - (int)x) == 0)
		return IsInt;		//������ȼ�Ϊ����
	return NotInt;
}