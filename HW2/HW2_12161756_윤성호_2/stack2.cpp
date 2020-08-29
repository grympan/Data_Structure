// 12161756 윤성호
// 변환 함수 구현부
#include "stack2.h"

int getOpNum(char A)
{
	// 변환값 :           1    2    3    4    5    6    7    8    9   10   11
	char op[] = { NULL, '(', ')', '!', '*', '/', '+', '-', '>', '<', '&', '|' };
	int i;

	for (i = 1; i < 12; i++)
		if (op[i] == A)
			return i;                                       // A가 연산자이면 그에 따른 숫자(1~11)를 리턴
	return 0;                                               // A가 피연산자이면 0을 리턴
}

bool confirm(char* In){
	int i = 0, opNum = 0, countAnd = 0, countAtor = 0;
	char token = NULL;

	for (token = In[i++]; token != NULL; token = In[i++]){
		opNum = getOpNum(token);
		if (opNum == 0)
			countAnd++;
		else if (opNum >= 4 && opNum <= 9)                  // 연산자수 계산에서 (, ), !는 제외하였습니다.
			countAtor++;
		else if (opNum >= 10){
			countAtor++;
			i++;
		}
		else
			continue;
	}

	return (countAnd > countAtor);                          // 피연산자수 > 연산자수일때 true 리턴
}

// 12161756 윤성호
void convert(char* In)
{
	if (confirm(In) == true){                                              // 피연산자수 > 연산자수일때 본격적인 변환 시작
		ArrayStack<char> A;
		char Po[100];                                                      // 후위표기식을 담을 배열 선언
		char token = NULL;
		int opNum = 0, i = 0, n = 0;

		// 변환값 :    { N  (  )  !  *  /  +  -  >  <  &  | }
		int topPr[] = { 0, 0, 7, 6, 5, 5, 4, 4, 3, 3, 2, 1 };              // 연산자의 우선순위를 담고있는 배열
		int nowPr[] = { 0, 8, 7, 6, 5, 5, 4, 4, 3, 3, 2, 1 };              // 숫자가 클수록 우선순위가 높은 것으로 하였습니다.

		A.push(NULL);
		for (token = In[i++]; token != NULL; token = In[i++]){
			opNum = getOpNum(token);

			if (opNum == 0)                                                // token이 피연산자이면 print
				Po[n++] = token;

			else if (token == ')'){                                        // token이 ')'이면 top이 '('가 나올때까지
				for (; A.top() != '('; A.pop())                            // [top을 print한 후 pop] 사이클 반복
					Po[n++] = A.top();

				A.pop();                                                   // 마침내 '('을 pop
			}

			else if (token == '&' || token == '|'){
				for (; topPr[getOpNum(A.top())] >= nowPr[opNum]; A.pop())  // 현재 token보다 낮은 우선순위 연산자를 만날때까지
					Po[n++] = A.top();                                     // [top을 print한 후 pop] 사이클 반복

				A.push(token); A.push(token);                              // 마침내 같은 token을 2번 연속 push
				i++;                                                       // 한 칸 건너 뛰기
			}

			else{
				for (; topPr[getOpNum(A.top())] >= nowPr[opNum]; A.pop())  // 현재 token보다 낮은 우선순위 연산자를 만날때까지
					Po[n++] = A.top();                                     // [top을 print한 후 pop] 사이클 반복

				A.push(token);                                             // 마침내 token을 push
			}
		}

		while (A.empty() == false){                                        // stack내 남아있는 연산자들을 모두 print
			Po[n++] = A.top();
			A.pop();
		}

		cout << Po << endl;                                                // 최종 후위표기식을 출력
	}

	else                                                                   // 연산자수 >= 피연산자수일때 오류 메시지 출력
		cout << "오류 : 연산자수 >= 연산자수." << endl;
}