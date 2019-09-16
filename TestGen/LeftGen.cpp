#include "pch.h"
#include "mylib.h"
#include <iostream>

//���ڽ̲��������ƣ���Щ�������ǹ̶��ģ���ֱ�����Ϊ����
#define ChuShuMax 9
#define ChuShuMin 2

const int StrLenMax = strlen("89/9") + 1;	//���ɵ��ַ�������󳤶�

int LeftGen(ExpressionNode * Address, int Num) {	//���ɴ������ĳ�����ʽ
	for (int i = 0; i < Num; i++) {
		//-------������ʽ����-------
		int ChuShu = MyRnd(ChuShuMin, ChuShuMax);	//�����ɳ���������ͱ����˳���0������
		int BeiChuShu = MyRnd(ChuShu + 1, ChuShu * 9);	//���ݳ������������������������ٱȳ�����1������֤�����1~9֮��
		//-------������ʽ�ַ���-------
		sprintf_s(Address[i].Expression, StrLenMax, "%d/%d", BeiChuShu, ChuShu);
		//-------������ʽ�Ƿ���������������Ƿ��ظ�-------
		while (BeiChuShu % ChuShu == 0 || RepeatCheak(Address, i) == ERROR) {
			//-------��������������-------
			ChuShu = MyRnd(ChuShuMin, ChuShuMax);	
			BeiChuShu = MyRnd(ChuShu + 1, ChuShu * 9);
			//-------�����ٴ������ַ���-------
			sprintf_s(Address[i].Expression, StrLenMax, "%d/%d", BeiChuShu, ChuShu);
		}
		//-------���ɽ��-------
		Address[i].Left = BeiChuShu % ChuShu;	//����
		Address[i].Value = BeiChuShu / ChuShu;	//��
	}
	return 0;
}