// 12161756 윤성호
#include "list1.h"

int main() {
	cout << "12161756 윤성호" << endl;
	DLinkedList ex;
	
	for (int i = 1; i <= 5; i++) {
		ex.addBack(i);
	}
	// 초기 순서 : 1, 2, 3, 4, 5

	cout << "front() 결과 : " << ex.front() << endl;   // 1
	cout << "back()  결과 : " << ex.back() << endl;    // 5
	
	ex.removeBack();   // 5 제거
	ex.removeFront();  // 1 제거

	cout << endl;
	cout << "2. removeBack과 removeFront 한 번씩 실행한 후" << endl;
	cout << "front() 결과 : " << ex.front() << endl;   // 2
	cout << "back()  결과 : " << ex.back() << endl;    // 4

	// 최종 순서 : 2, 3, 4
	
	system("pause");
	return 0;
}