// template���� ���� stack.cpp����
// header�� �����Ͽ����ϴ�.

#ifndef STACK_H
#define STACK_H

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

private:
	E* S;
	int capacity;
	int t;
};

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