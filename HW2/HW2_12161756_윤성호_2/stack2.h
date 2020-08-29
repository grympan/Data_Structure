#ifndef STACK2_H
#define STACK2_H

// 12161756 ����ȣ
// ���� stack.h���� �߰��� �κ�(�Ʒ� 3��)
int getOpNum(char);   // token�� �޾� �׿� �´� ���ڸ� ��ȯ�ϴ� �Լ�
bool confirm(char*);  // ����ǥ��� �迭�� �޾� �ǿ����ڼ� > �����ڼ��϶� true�� �����ϴ� �Լ�
void convert(char*);  // ����ǥ��� �迭�� �޾� ����ǥ������� ����ϴ� �Լ�

#include <iostream>
#include <string>
using namespace std;

// 12161756 ����ȣ
// ����ó�� class
class RuntimeException{
private:
	string errorMsg;
public:
	RuntimeException(const string & err){
		errorMsg = err;
	}
	string getMessage() const{
		return errorMsg;
	}
};

inline std::ostream& operator<<(std::ostream& out, const RuntimeException& e){
	return out << e.getMessage();
}

class StackEmpty : public RuntimeException{
public:
	StackEmpty(const string& err) :RuntimeException(err){}
};

class StackFull : public RuntimeException{
public:
	StackFull(const string& err) :RuntimeException(err){}
};

// 12161756 ����ȣ
// ArrayStack class
template <typename E>
class ArrayStack {
	enum { DEF_CAPACITY = 100 };
public:
	ArrayStack(int cap = DEF_CAPACITY);      // �⺻ �뷮�� 100���� �ϴ� ������
	~ArrayStack();
	int size() const;                        // ������ �󸶸�ŭ ���ִ��� �˷��ִ� �Լ�
	bool empty() const;                      // ������ ������� True or False�� ��ȯ�ϴ� �Լ�
	const E& top() const throw(StackEmpty);  // �ֻ��� ���Ҹ� �˷��ִ� top
	void push(const E& e) throw(StackFull);  // ���� ���� ���� �ֻ����� ä��� push
	void pop() throw(StackEmpty);            // �ֻ��� ���Ҹ� �����ϴ� pop

	int input(E str);
	int getStrSize(E str);
	void print(E str);
private:
	E* S;
	int capacity;
	int t;
};

template <typename E> void ArrayStack<E>::print(E str){
	cout << str;
}

template <typename E> int ArrayStack<E>::input(E str)
{
	for (int i = 0; i < getStrSize(str); i++)
	{
		if (str[i] == "("){
			push(str[i]);
		}

		else if (str[i] == ")"){
			while (top() != "("){
				print(top());
				pop();
			}
			print(top()); pop();
		}

		else if (str[i] == "+" || "-"){

		}
	}
}

template <typename E> int ArrayStack<E>::getStrSize(E str)
{
	int size = 0;
	while (str[size] != NULL){
		size++;
	}
	return size;
}

template <typename E> ArrayStack<E>::ArrayStack(int cap)
	:S(new E[cap]), capacity(cap), t(-1){}

template <typename E> ArrayStack<E>::~ArrayStack(){
	delete[] S;
}

template <typename E> int ArrayStack<E>::size() const{
	return (t + 1);
}

template <typename E> bool ArrayStack<E>::empty() const{
	return (t < 0);
}

template <typename E>
const E& ArrayStack<E>::top() const throw(StackEmpty){
	try{
		if (empty())
			throw StackEmpty("���� : �� ���ÿ��� top�� �����Ͽ����ϴ�.");
	}
	catch (StackEmpty &e){
		cout << e.getMessage() << endl;
	}
	return S[t];
}

template <typename E>
void ArrayStack<E>::push(const E& e) throw(StackFull){
	try{
		if (size() == capacity)
			throw StackFull("���� : Ǯ ���ÿ��� push�� �����Ͽ����ϴ�.");
	}
	catch (StackFull &e){
		cout << e.getMessage() << endl;
	}
	S[++t] = e;
}

template <typename E>
void ArrayStack<E>::pop() throw(StackEmpty){
	try{
		if (empty())
			throw StackEmpty("���� : �� ���ÿ��� pop�� �����Ͽ����ϴ�.");
	}
	catch (StackEmpty &e){
		cout << e.getMessage() << endl;
	}
	--t;
}
#endif