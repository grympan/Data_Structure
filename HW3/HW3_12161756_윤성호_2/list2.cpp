// 12161756 윤성호
#include "list2.h"

bool parCheck(char* str) {
	DLinkedStack s1;                 // DLinkedStack s1 생성
	string s = str;                  // 넘겨 받은 char형 문자열을 string으로 변환
	int length = s.length();         // 변환한 string의 길이 저장

	for(int i = 0; i < length; i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			s1.push(str[i]);
		}                            // 괄호 종류 관계없이 여는 괄호면 push

		else if (str[i] == ')') {
			if (s1.empty())
				return false;        // 닫는 소괄호이면서, stack이 비어있다면 false

			else {
				if (s1.top() == '(')
					s1.pop();        // 닫는 소괄호이면서, top이 여는 소괄호면 pop
				else
					return false;    // 닫는 소괄호이지만,
			}                        // top이 여는 소괄호가 아니면 false
		}

		else if (str[i] == '}') {    // 하단의 중괄호, 대괄호 또한
			if (s1.empty())          // 위의 소괄호 코드와 동일하게 구성하였습니다.
				return false;

			else {
				if (s1.top() == '{')
					s1.pop();
				else
					return false;
			}
		}

		else if (str[i] == ']') {
			if (s1.empty())
				return false;

			else {
				if (s1.top() == '[')
					s1.pop();
				else
					return false;
			}
		}
	}                  // 문자열 길이만큼 for구문 탐색 완료

	if (s1.empty())
		return true;   // for구문이 완료됐을때, stack이 비어있다면 true
	
	else
		return false;  // 완료됐는데 stack에 남은 괄호가 있다면 false
}

bool STLparCheck(char* str) {
	list <char> s2;                     // char형 list s2 생성
	string s = str;                     // 넘겨 받은 char형 문자열을 string으로 변환
	int length = s.length();            // 변환한 string의 길이 저장

	for (int i = 0; i < length; i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			s2.push_front(str[i]);
		}                               // 괄호 종류 관계없이 여는 괄호면 push_front

		else if (str[i] == ')') {
			if (s2.empty())
				return false;           // 닫는 소괄호이면서, stack이 비어있다면 false

			else {
				if (s2.front() == '(')
					s2.pop_front();     // 닫는 소괄호이면서, front가 여는 소괄호면 pop_front
				else
					return false;       // 닫는 소괄호이지만,
			}                           // front가 여는 소괄호가 아니면 false
		}

		else if (str[i] == '}') {       // 하단의 중괄호, 대괄호 또한
			if (s2.empty())             // 위의 소괄호 코드와 동일하게 구성하였습니다.
				return false;

			else {
				if (s2.front() == '{')
					s2.pop_front();
				else
					return false;
			}
		}

		else if (str[i] == ']') {
			if (s2.empty())
				return false;

			else {
				if (s2.front() == '[')
					s2.pop_front();
				else
					return false;
			}
		}
	}                  // 문자열 길이만큼 for구문 탐색 완료

	if (s2.empty())
		return true;   // for구문이 완료됐을때, stack이 비어있다면 true

	else
		return false;  // 완료됐는데 stack에 남은 괄호가 있다면 false
}

void getMsg(bool TorF) {
	if (TorF == true) {
		cout << "correct" << endl;    // 넘겨받은 값이 true면 "correct" 출력
	}

	else
		cout << "incorrect" << endl;  // 넘겨받은 값이 false면 "incorrect" 출력
}


DLinkedStack::DLinkedStack() {
	header = new DNode;
	trailer = new DNode;
	header->next = trailer;
	trailer->prev = header;
}

DLinkedStack::~DLinkedStack() {
	while (!empty()) pop();
	delete header;
	delete trailer;
}

bool DLinkedStack::empty() const {
	return (header->next == trailer);
}

const Elem& DLinkedStack::top() const {
	return header->next->elem;
}

void DLinkedStack::push(const Elem& e) {
	add(header->next, e);
}

void DLinkedStack::pop() {
	remove(header->next);
}

void DLinkedStack::remove(DNode* v) {
	DNode* u = v->prev;
	DNode* w = v->next;
	u->next = w;
	w->prev = u;
	delete v;
}

void DLinkedStack::add(DNode* v, const Elem& e) {
	DNode* u = new DNode; u->elem = e;
	u->next = v;
	u->prev = v->prev;
	u->prev->next = v->prev = u;
}