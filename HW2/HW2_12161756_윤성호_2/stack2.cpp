// 12161756 ����ȣ
// ��ȯ �Լ� ������
#include "stack2.h"

int getOpNum(char A)
{
	// ��ȯ�� :           1    2    3    4    5    6    7    8    9   10   11
	char op[] = { NULL, '(', ')', '!', '*', '/', '+', '-', '>', '<', '&', '|' };
	int i;

	for (i = 1; i < 12; i++)
		if (op[i] == A)
			return i;                                       // A�� �������̸� �׿� ���� ����(1~11)�� ����
	return 0;                                               // A�� �ǿ������̸� 0�� ����
}

bool confirm(char* In){
	int i = 0, opNum = 0, countAnd = 0, countAtor = 0;
	char token = NULL;

	for (token = In[i++]; token != NULL; token = In[i++]){
		opNum = getOpNum(token);
		if (opNum == 0)
			countAnd++;
		else if (opNum >= 4 && opNum <= 9)                  // �����ڼ� ��꿡�� (, ), !�� �����Ͽ����ϴ�.
			countAtor++;
		else if (opNum >= 10){
			countAtor++;
			i++;
		}
		else
			continue;
	}

	return (countAnd > countAtor);                          // �ǿ����ڼ� > �����ڼ��϶� true ����
}

// 12161756 ����ȣ
void convert(char* In)
{
	if (confirm(In) == true){                                              // �ǿ����ڼ� > �����ڼ��϶� �������� ��ȯ ����
		ArrayStack<char> A;
		char Po[100];                                                      // ����ǥ����� ���� �迭 ����
		char token = NULL;
		int opNum = 0, i = 0, n = 0;

		// ��ȯ�� :    { N  (  )  !  *  /  +  -  >  <  &  | }
		int topPr[] = { 0, 0, 7, 6, 5, 5, 4, 4, 3, 3, 2, 1 };              // �������� �켱������ ����ִ� �迭
		int nowPr[] = { 0, 8, 7, 6, 5, 5, 4, 4, 3, 3, 2, 1 };              // ���ڰ� Ŭ���� �켱������ ���� ������ �Ͽ����ϴ�.

		A.push(NULL);
		for (token = In[i++]; token != NULL; token = In[i++]){
			opNum = getOpNum(token);

			if (opNum == 0)                                                // token�� �ǿ������̸� print
				Po[n++] = token;

			else if (token == ')'){                                        // token�� ')'�̸� top�� '('�� ���ö�����
				for (; A.top() != '('; A.pop())                            // [top�� print�� �� pop] ����Ŭ �ݺ�
					Po[n++] = A.top();

				A.pop();                                                   // ��ħ�� '('�� pop
			}

			else if (token == '&' || token == '|'){
				for (; topPr[getOpNum(A.top())] >= nowPr[opNum]; A.pop())  // ���� token���� ���� �켱���� �����ڸ� ����������
					Po[n++] = A.top();                                     // [top�� print�� �� pop] ����Ŭ �ݺ�

				A.push(token); A.push(token);                              // ��ħ�� ���� token�� 2�� ���� push
				i++;                                                       // �� ĭ �ǳ� �ٱ�
			}

			else{
				for (; topPr[getOpNum(A.top())] >= nowPr[opNum]; A.pop())  // ���� token���� ���� �켱���� �����ڸ� ����������
					Po[n++] = A.top();                                     // [top�� print�� �� pop] ����Ŭ �ݺ�

				A.push(token);                                             // ��ħ�� token�� push
			}
		}

		while (A.empty() == false){                                        // stack�� �����ִ� �����ڵ��� ��� print
			Po[n++] = A.top();
			A.pop();
		}

		cout << Po << endl;                                                // ���� ����ǥ����� ���
	}

	else                                                                   // �����ڼ� >= �ǿ����ڼ��϶� ���� �޽��� ���
		cout << "���� : �����ڼ� >= �����ڼ�." << endl;
}