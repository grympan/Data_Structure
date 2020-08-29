// 12161756 윤성호
#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;
typedef char Elem;

bool parCheck(char* str);      // DLinkedStack으로 구현한 괄호 검사 함수
bool STLparCheck(char* str);   // STL로 구현한 괄호 검사 함수
void getMsg(bool TorF);        // 괄호 검사 함수 결과를 메시지로 출력하는 함수

class DNode {
private:
	Elem elem;
	DNode* prev;
	DNode* next;
	friend class DLinkedStack;
};

class DLinkedStack{            // DLinkedlist에서 Stack에 활용될 수 있는 함수만 뽑아
public:                        // 이름만 Stack 함수명에 맞게 바꿔준 클래스
	DLinkedStack();
	~DLinkedStack();
	bool empty() const;
	const Elem& top() const;
	void push(const Elem& e);
	void pop();

private:
	DNode* header;
	DNode* trailer;

protected:
	void add(DNode* v, const Elem& e);
	void remove(DNode* v);
};