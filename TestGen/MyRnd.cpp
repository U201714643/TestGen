#include "pch.h"
#include "mylib.h"
#include <iostream>

int MyRnd(int min, int max) {	//����λ��[min,max]֮�������
	int length = max - min + 1;	//ע�����䳤����Ҫ��1
	return rand() % length + min;	//������ȡ���ټ�����㼴Ϊ��Χ�������
}