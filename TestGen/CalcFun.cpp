#include "pch.h"
#include "calcFun.h"

void removeSpace(char *strs) {
	char *spacer = NULL;

	while ((spacer = strchr(strs, ' ')) != NULL) {
		while (*spacer != '\0') {
			*spacer = *(spacer + 1);
			spacer++;
		}
	}
}

//�Ƿ��������(��������)
int inOp(char inchar) {
	int isOp = 0;
	char ops[] = "+-*/()#";

	if (strchr(ops, inchar)) {
		isOp = 1;
	}

	return isOp;
}

//���ʽ�����Ƿ�ƥ����ȷ
int expressionValid(char *press) {
	int valid = 1,
		lbra = 0,
		rbra = 0;
	size_t pos = 0,
		plen = 0;

	//����ո�
	removeSpace(press);
	plen = strlen(press);

	//��������Ƿ���ȷ
	for (; pos < plen; ++pos) {
		if (press[pos] == '(') {
			lbra++;
		}
		if (press[pos] == ')') {
			rbra++;
		}
	}
	if (lbra != rbra) {
		valid = 0;
	}

	return valid;
}

//��������ȼ��ж�
int priorityCal(char prev, char next) {
	int priority = 0;

	if (next == '#') {
		priority = 1;
	}
	else {
		switch (prev) {
		case '+': case '-':
			if (next == '+' || next == '-' || next == ')') {
				priority = 1;
			}
			else if (next == '*' || next == '/' || next == '(') {
				priority = -1;
			}
			break;
		case '*': case '/':
			if (next == '+' || next == '-' || next == '*' || next == '/' || next == ')') {
				priority = 1;
			}
			else if (next == '(') {
				priority = -1;
			}
			break;
		case '(':
			if (next == ')') {
				priority = 0;
			}
			else {
				priority = -1;
			}
			break;
		case ')':
			priority = -1;
			break;
		}
	}

	return priority;
}

//��ʼ��ջ
void initStack(CharOp **so, onChose type) {
	if (*so == NULL) {
		*so = (CharOp*)malloc(sizeof(CharOp));
	}

	(*so)->cp = type;
	if (type == Op) {
		(*so)->onW.ops = NULL;
	}
	else {
		(*so)->onW.nums = NULL;
	}
	(*so)->curPos = 0;
	(*so)->length = 0;
}

//ջ�Ƿ�Ϊ��
int emptyStack(CharOp *so) {
	int empty = 0;

	if (so->length == 0 || so->curPos == 0) {
		empty = 1;
	}

	return empty;
}

//ջ��������
void addStackSize(CharOp *so) {
	if (so->curPos == so->length) {//ջ��,�������ռ�
		int newlen = 0;

		if (so->cp == Op) {
			if (so->onW.ops == NULL) {
				newlen = 1;
				so->onW.ops = (char*)malloc(sizeof(char));
			}
			else {
				newlen = so->length + so->length / 2 + 1;
				char *result = (char*)realloc(so->onW.ops, newlen * sizeof(char));
			}
			assert(so->onW.ops);
		}
		else {
			if (so->onW.nums == NULL) {
				newlen = 1;
				so->onW.nums = (int*)malloc(sizeof(int));
			}
			else {
				newlen = so->length + so->length / 2 + 1;
				int *result = (int*)realloc(so->onW.nums, newlen * sizeof(int));
			}
			assert(so->onW.nums);
		}
		so->length = newlen;
	}
}

//��ջ
void enStack(CharOp *so, void *inc) {
	addStackSize(so);
	if (so->cp == Op) {
		so->onW.ops[so->curPos++] = *(char*)inc;
	}
	else {
		so->onW.nums[so->curPos++] = *(int*)inc;
	}
}

//��ջ
void deStack(CharOp *so, void *gc) {
	if (so->curPos) {
		if (so->cp == Op) {
			char op = so->onW.ops[--so->curPos];
			if (gc) {
				char *rt = (char*)gc;
				*rt = op;
			}
		}
		else {
			int num = so->onW.nums[--so->curPos];
			if (gc) {
				int *rt = (int*)gc;
				*rt = num;
			}
		}
	}
}

//��ȡջ��Ԫ��
void* getTop(CharOp *so) {
	if (so->length) {
		if (so->cp == Op) {
			return so->onW.ops + so->curPos - 1;
		}
		else {
			return so->onW.nums + so->curPos - 1;
		}
	}
	else {
		return NULL;
	}
}