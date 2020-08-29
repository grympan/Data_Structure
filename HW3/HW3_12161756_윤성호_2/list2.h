// 12161756 ����ȣ
#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;
typedef char Elem;

bool parCheck(char* str);      // DLinkedStack���� ������ ��ȣ �˻� �Լ�
bool STLparCheck(char* str);   // STL�� ������ ��ȣ �˻� �Լ�
void getMsg(bool TorF);        // ��ȣ �˻� �Լ� ����� �޽����� ����ϴ� �Լ�

class DNode {
private:
	Elem elem;
	DNode* prev;
	DNode* next;
	friend class DLinkedStack;
};

class DLinkedStack{            // DLinkedlist���� Stack�� Ȱ��� �� �ִ� �Լ��� �̾�
public:                        // �̸��� Stack �Լ��� �°� �ٲ��� Ŭ����
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