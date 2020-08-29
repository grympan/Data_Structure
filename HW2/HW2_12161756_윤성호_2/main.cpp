// 12161756 윤성호
#include "stack2.h"
#include <stdlib.h>

int main()
{
	cout << "12161756 윤성호" << endl;
	char ex1[] = "A*B*C";
	char ex2[] = "((A+(B*C))-(D/E))";
	char ex3[] = "-A+B-C+D";
	char ex4[] = "A*-B+C";
	char ex5[] = "(A+B)*D+E/(F+A*D)+C";
	char ex6[] = "A&&B||C||!(E>F)";
	char ex7[] = "!(A&&!((B<C)||(C>D)))||(C<E)";

	cout << "1) "; convert(ex1);
	cout << "2) "; convert(ex2);
	cout << "3) "; convert(ex3);
	cout << "4) "; convert(ex4);
	cout << "5) "; convert(ex5);
	cout << "6) "; convert(ex6);
	cout << "7) "; convert(ex7);

	char ex[100];
	cout << endl << "중위표기식을 입력하세요 : ";
	cin >> ex;
	cout << "후위표기식 : "; convert(ex);

	system("pause");
	return 0;
}