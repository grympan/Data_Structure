// 12161756 윤성호
#include "stack.h"

int main(){
	cout << "12161756 윤성호" << endl;
	ArrayStack<int> A;                 // '*' : 스택 최상위 원소
	A.push(7);                         // A =[7*]
	A.push(13);                        // A =[7, 13*]
	cout << A.top() << endl; A.pop();  // A =[7*], output : 13
	A.push(9);                         // A =[7, 9*]
	cout << A.top() << endl;           // A =[7, 9*], output : 9
	cout << A.top() << endl; A.pop();  // A =[7*], output : 9

	ArrayStack<string> B(10);
	B.push("Bob");                     // B =[Bob*]
	B.push("Alice");                   // B =[Bob, Alice*]
	cout << B.top() << endl; B.pop();  // B =[Bob*], output : Alice
	B.push("Eve");                     // B =[Bob, Eve*]

	// 여기까지 현재 상태 : A =[7*], B =[Bob, Eve*], B의 capacity : 10

	A.pop();                           // A =[]
	A.top();                           // top 예외 발생 (empty 상태에서 top)
	A.pop();                           // pop 예외 발생 (empty 상태에서 pop)

	B.push("C"); B.push("D"); B.push("E"); B.push("F");  // B =[Bob, Eve, C, D, E, F*]
	B.push("G"); B.push("H"); B.push("I"); B.push("J");  // B =[Bob, Eve, C, D, ... , I, J*], 10번째 원소 : J
	B.push("K");                                         // push 예외 발생 (full인 상태에서 push)
}
