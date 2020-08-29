// 12161756 ����ȣ
#include "list2.h"

bool parCheck(char* str) {
	DLinkedStack s1;                 // DLinkedStack s1 ����
	string s = str;                  // �Ѱ� ���� char�� ���ڿ��� string���� ��ȯ
	int length = s.length();         // ��ȯ�� string�� ���� ����

	for(int i = 0; i < length; i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			s1.push(str[i]);
		}                            // ��ȣ ���� ������� ���� ��ȣ�� push

		else if (str[i] == ')') {
			if (s1.empty())
				return false;        // �ݴ� �Ұ�ȣ�̸鼭, stack�� ����ִٸ� false

			else {
				if (s1.top() == '(')
					s1.pop();        // �ݴ� �Ұ�ȣ�̸鼭, top�� ���� �Ұ�ȣ�� pop
				else
					return false;    // �ݴ� �Ұ�ȣ������,
			}                        // top�� ���� �Ұ�ȣ�� �ƴϸ� false
		}

		else if (str[i] == '}') {    // �ϴ��� �߰�ȣ, ���ȣ ����
			if (s1.empty())          // ���� �Ұ�ȣ �ڵ�� �����ϰ� �����Ͽ����ϴ�.
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
	}                  // ���ڿ� ���̸�ŭ for���� Ž�� �Ϸ�

	if (s1.empty())
		return true;   // for������ �Ϸ������, stack�� ����ִٸ� true
	
	else
		return false;  // �Ϸ�ƴµ� stack�� ���� ��ȣ�� �ִٸ� false
}

bool STLparCheck(char* str) {
	list <char> s2;                     // char�� list s2 ����
	string s = str;                     // �Ѱ� ���� char�� ���ڿ��� string���� ��ȯ
	int length = s.length();            // ��ȯ�� string�� ���� ����

	for (int i = 0; i < length; i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			s2.push_front(str[i]);
		}                               // ��ȣ ���� ������� ���� ��ȣ�� push_front

		else if (str[i] == ')') {
			if (s2.empty())
				return false;           // �ݴ� �Ұ�ȣ�̸鼭, stack�� ����ִٸ� false

			else {
				if (s2.front() == '(')
					s2.pop_front();     // �ݴ� �Ұ�ȣ�̸鼭, front�� ���� �Ұ�ȣ�� pop_front
				else
					return false;       // �ݴ� �Ұ�ȣ������,
			}                           // front�� ���� �Ұ�ȣ�� �ƴϸ� false
		}

		else if (str[i] == '}') {       // �ϴ��� �߰�ȣ, ���ȣ ����
			if (s2.empty())             // ���� �Ұ�ȣ �ڵ�� �����ϰ� �����Ͽ����ϴ�.
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
	}                  // ���ڿ� ���̸�ŭ for���� Ž�� �Ϸ�

	if (s2.empty())
		return true;   // for������ �Ϸ������, stack�� ����ִٸ� true

	else
		return false;  // �Ϸ�ƴµ� stack�� ���� ��ȣ�� �ִٸ� false
}

void getMsg(bool TorF) {
	if (TorF == true) {
		cout << "correct" << endl;    // �Ѱܹ��� ���� true�� "correct" ���
	}

	else
		cout << "incorrect" << endl;  // �Ѱܹ��� ���� false�� "incorrect" ���
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