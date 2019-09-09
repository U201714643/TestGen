#pragma once
#define OK 0		//����
#define ERROR -1	//����
#define OVERFLOW -2	//���
#define FLASE 0		//Ϊ��
#define TRUE 1		//Ϊ��
#define EXPLEN 120	//���ʽ��󳤶�

typedef struct NumNode {	//���ɱ��ʽʱ���ڸ����ֽṹ
	int Num;	//��������
	int KuoHao;	//�������Ž�������0�����ţ�����Ϊ�Ҳ����ţ�����Ϊ�������
};

typedef struct ExpressionNode {	//���ɵı��ʽ
	char Expression[EXPLEN];	//���ʽ
	int result;		//������
	int left;		//�����������ڴ���������������Ϊ0
};

typedef struct ExpressionList {	//���ɱ��ʽʹ�õĲ�����
	int EqualsNum;	//���ɵı��ʽ��Ŀ
	int OpCount;	//��������Ŀ
	int OpTypeMin;	//���������෶Χ
	int OpTypeMax;	//���������෶Χ
	int NumMin;		//��������Χ
	int NumMax;		//��������Χ
	int ResultMin;	//�����Χ
	int ResultMax;	//�����Χ
	int KuoHao;		//�Ƿ���������
};

const char OpTxet[][4] = { "��","��","��","��" };	//������ʾ���������ע����Щ���������ֽڣ����Բ���ֱ����char������
const char OpTxetN[4] = { '+','-','*','//' };		//������ʾ���������'//'������š�/��
const int OpAdd = 0, OpSub = 1, OpMpl = 2, OpDiv = 3;	//�������ţ��ֱ��Ӧ"��","��","��","��"
const int OpMin = 0, OpMax = 3;		//�������ŵ������Сֵ

void Initial();								//��ʼ������
int MyRnd(int min, int max);				//����λ��[min,max]֮�������
int CheakRationality(int *num, int *op);	//�����ʽ�Ƿ����
int IntSum(int *num, int *op);				//�Ա��ʽ����������ֵ
double FloatSum(int *num, int *op);			//�Ա��ʽ���и�������ֵ
double ExpSum(char * Expression);			//�Ա��ʽ����������ֵ