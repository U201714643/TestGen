#pragma once
#define OK 0	//����
#define ERROR 1	//����

const char OpTxet[][4] = { "��","��","��","��" };		//������ʾ���������ע����Щ���������ֽڣ����Բ���ֱ����char������
const int OpAdd = 0, OpSub = 1, OpMpl = 2, OpDiv = 3;	//�������ţ��ֱ��Ӧ"��","��","��","��"
const int OpMin = 0, OpMax = 3;		//�������ŵ������Сֵ

void Initial();								//��ʼ������
int MyRnd(int min, int max);				//����λ��[min,max]֮�������
int CheakRationality(int *num, int *op);	//�����ʽ�Ƿ����
int IntSum(int *num, int *op);				//�Ա��ʽ����������ֵ
double FloatSum(int *num, int *op);			//�Ա��ʽ���и�������ֵ