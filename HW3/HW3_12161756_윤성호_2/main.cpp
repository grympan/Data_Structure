// 12161756 ����ȣ
#include "list2.h"

int main() {
	cout << "12161756 ����ȣ" << endl;

	char s1[] = "( )(( )){([( )])}";
	char s2[] = "((( )(( )){([( )])}";
	char s3[] = ")(( )){([( )])}";
	char s4[] = "({[ ])}";
	char s5[] = "(";

	cout << "1-(2) ���� ���" << endl;
	getMsg(parCheck(s1));       // correct
	getMsg(parCheck(s2));       // incorrect
	getMsg(parCheck(s3));       // incorrect
	getMsg(parCheck(s4));       // incorrect
	getMsg(parCheck(s5));       // incorrect

	cout << '\n' << "2 ���� ���" << endl;
	getMsg(STLparCheck(s1));    // correct
	getMsg(STLparCheck(s2));    // incorrect
	getMsg(STLparCheck(s3));    // incorrect
	getMsg(STLparCheck(s4));    // incorrect
	getMsg(STLparCheck(s5));    // incorrect
	
	system("pause");
	return 0;
}