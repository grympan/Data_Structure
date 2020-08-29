// template으로 인해 stack.cpp없이
// header에 구현하였습니다.

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
using namespace std;

// 12161756 윤성호
// 예외처리 class
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

// 12161756 윤성호
// ArrayStack class
template <typename E>
class ArrayStack {
	enum { DEF_CAPACITY = 100 };
public:
	ArrayStack(int cap = DEF_CAPACITY);      // 기본 용량을 100으로 하는 생성자
	~ArrayStack();
	int size() const;                        // 스택이 얼마만큼 차있는지 알려주는 함수
	bool empty() const;                      // 스택이 비었는지 True or False로 반환하는 함수
	const E& top() const throw(StackEmpty);  // 최상위 원소를 알려주는 top
	void push(const E& e) throw(StackFull);  // 받은 값을 스택 최상위에 채우는 push
	void pop() throw(StackEmpty);            // 최상위 원소를 삭제하는 pop

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
			throw StackEmpty("오류 : 빈 스택에서 top을 실행하였습니다.");
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
			throw StackFull("오류 : 풀 스택에서 push를 실행하였습니다.");
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
			throw StackEmpty("오류 : 빈 스택에서 pop을 실행하였습니다.");
	}
	catch (StackEmpty &e){
		cout << e.getMessage() << endl;
	}
	--t;
}
#endif