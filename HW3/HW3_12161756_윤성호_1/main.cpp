// 12161756 ����ȣ
#include "list1.h"

int main() {
	cout << "12161756 ����ȣ" << endl;
	DLinkedList ex;
	
	for (int i = 1; i <= 5; i++) {
		ex.addBack(i);
	}
	// �ʱ� ���� : 1, 2, 3, 4, 5

	cout << "front() ��� : " << ex.front() << endl;   // 1
	cout << "back()  ��� : " << ex.back() << endl;    // 5
	
	ex.removeBack();   // 5 ����
	ex.removeFront();  // 1 ����

	cout << endl;
	cout << "2. removeBack�� removeFront �� ���� ������ ��" << endl;
	cout << "front() ��� : " << ex.front() << endl;   // 2
	cout << "back()  ��� : " << ex.back() << endl;    // 4

	// ���� ���� : 2, 3, 4
	
	system("pause");
	return 0;
}