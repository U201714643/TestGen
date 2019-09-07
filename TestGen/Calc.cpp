#include "pch.h"
#include <stdio.h>
#include <string.h>
#include "calcFun.h"

//计算
int calcExpress(int numa, char op, int numb);
//计算划分
void realCalc(CharOp *opss, CharOp *numss, int *num1, int *num2, int *calNum, char topChar);
//获取子串
void getPartStr(char *vals, int start, int end, char **rt);
//字符串转换为整形
void parttoi(char *vals, int *result, size_t *start, size_t len);
//表达式计算
void expressCalculation(char *content);

int IntSum2(char *content) { //开始计算
	expressCalculation(content);	
	return 0;
}

void realCalc(CharOp *opss, CharOp *numss, int *num1, int *num2, int *calNum, char topChar) {
	deStack(numss, num2);
	deStack(numss, num1);
	deStack(opss, &topChar);
	*calNum = calcExpress(*num1, topChar, *num2);
	enStack(numss, calNum);
}

int calcExpress(int numa, char op, int numb) {
	int result = 0;

	switch (op) {
	case '+':
		result = numa + numb;
		break;
	case '-':
		result = numa - numb;
		break;
	case '*':
		result = numa * numb;
		break;
	case '/':
		result = numa / numb;
		break;
	}

	return result;
}

void getPartStr(char *vals, int start, int end, char **rt) {
	int st = 0, nlen = end - start;
	*rt = (char*)malloc((nlen + 1) * sizeof(char));

	if (*rt) {
		for (int s = start; s < end; ++s, st++) {
			(*rt)[st] = vals[s];
		}
		(*rt)[st] = '\0';
	}
}

void parttoi(char *vals, int *result, size_t *start, size_t len) {
	size_t st = *start,
		slen = 0;
	char *part = NULL;

	for (; st < len && isdigit(vals[st]); ++st, ++slen);
	getPartStr(vals, *start, st, &part);
	*result = atoi(part);
	*start += slen;
}

void expressCalculation(char *content) {
	if (expressionValid(content)) {
		size_t start = 0,
			nlen = strlen(content);
		CharOp *opss = NULL, *numss = NULL;

		initStack(&opss, Op);
		initStack(&numss, Num);
		while (start < nlen) {
			if (!inOp(content[start])) {//不为操作符
				int num = 0;
				parttoi(content, &num, &start, nlen);
				enStack(numss, &num);
			}
			else {
				if (emptyStack(opss)) {
					enStack(opss, &content[start]);
				}
				else {
					char topChar = *(char*)getTop(opss);
					int num1 = 0, num2 = 0, calNum = 0;
					switch (priorityCal(topChar, content[start])) {
					case -1:
						enStack(opss, &content[start]);
						break;
					case 0:
						deStack(opss, NULL);
						break;
					case 1:
						realCalc(opss, numss, &num1, &num2, &calNum, topChar);
						if (content[start] == '#') {
							realCalc(opss, numss, &num1, &num2, &calNum, topChar);
						}
						else if (content[start] == ')') {
							deStack(opss, NULL);
						}
						else {
							enStack(opss, &content[start]);
						}
						break;
					}
				}
				start++;
			}
		}

		if (emptyStack(opss)) {
			int result = 0;
			deStack(numss, &result);
			printf("the result of (%s) is %d\n", content, result);
		}
		else {
			printf("%s is wrong!\n", content);
		}
	}
	else {
		printf("%s is wrong!\n", content);
	}
}