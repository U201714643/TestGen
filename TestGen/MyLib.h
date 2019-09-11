#pragma once
#define OK 0		//����
#define ERROR -1	//����
#define FERROR -1.0f//����(��������ʽ)
#define OVERFLOW -2	//���
#define FLASE 0		//Ϊ��
#define TRUE 1		//Ϊ��
#define EXPLEN 120	//���ʽ��󳤶�
#define EXPNUM 256	//���ʽ�����Ŀ
#define TRYMAX 32	//����Դ���

typedef struct NumNode {	//���ɱ��ʽʱ���ڸ����ֽṹ
	int Num;	//��������
	int KuoHao;	//�������Ž�������0�����ţ�����Ϊ�Ҳ����ţ�����Ϊ�������
};

typedef struct ExpressionNode {	//���ɵı��ʽ
	char Expression[EXPLEN];	//���ʽ
	int Value;		//������
	int Left;		//�����������ڴ���������������Ϊ0
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
	int Repeat;		//�Ƿ������ظ�
};

const char OpTxet[4] = { '+','-','*','//' };		//������ʾ���������'//'������š�/��
const int OpAdd = 0, OpSub = 1, OpMpl = 2, OpDiv = 3;	//�������ţ��ֱ��Ӧ"��","��","��","��"

#define Clear(x) memset(x, 0, sizeof(x))	//�����ռ���0

void Initial();						//��ʼ������
int MyRnd(int min, int max);		//����λ��[min,max]֮�������
double ExpSum(char * Expression);	//�Ա��ʽ���и�������ֵ
int RepeatCheak(ExpressionNode * Address, int Num);				//�����ʽ�Ƿ��ظ�
int AnsCheak(char * Expression, int ResultMin, int ResultMax);	//�����ʽ�Ƿ�����޷�������Ϊ������������Χ��������ֵ
int TestGen(ExpressionNode * Address, ExpressionList * Arguements);	//���ɱ��ʽ
int KuoHaoCheak(int NumLeft, int NumRight, int OpCount, NumNode * num);	//��������Ƿ����
