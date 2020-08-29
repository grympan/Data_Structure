// 12161756 ����ȣ
#include "stack.h"

int main(){
	cout << "12161756 ����ȣ" << endl;
	ArrayStack<int> A;                 // '*' : ���� �ֻ��� ����
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

	// ������� ���� ���� : A =[7*], B =[Bob, Eve*], B�� capacity : 10

	A.pop();                           // A =[]
	A.top();                           // top ���� �߻� (empty ���¿��� top)
	A.pop();                           // pop ���� �߻� (empty ���¿��� pop)

	B.push("C"); B.push("D"); B.push("E"); B.push("F");  // B =[Bob, Eve, C, D, E, F*]
	B.push("G"); B.push("H"); B.push("I"); B.push("J");  // B =[Bob, Eve, C, D, ... , I, J*], 10��° ���� : J
	B.push("K");                                         // push ���� �߻� (full�� ���¿��� push)
}
