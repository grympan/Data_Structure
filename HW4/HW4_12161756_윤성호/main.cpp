// 12161756 윤성호
#include "tree.h"

int main() {
	cout << "12161756 윤성호" << endl;

	BST<int> exBST(55);                 // 55의 root를 가진 tree 객체 생성
	exBST.insert(new Node<int>(17));    // 17 insert
	exBST.insert(new Node<int>(13));
	exBST.insert(new Node<int>(76));
	exBST.insert(new Node<int>(19));
	exBST.insert(new Node<int>(61));
	exBST.insert(new Node<int>(43));
	exBST.insert(new Node<int>(18));
	exBST.insert(new Node<int>(65));
	exBST.insert(new Node<int>(89));
	exBST.insert(new Node<int>(10));    // ~10 insert

	cout << "<insert 순서>" << endl;
	cout << "55(R) 17 13 76 19 61 43 18 65 89 10" << endl << endl;
	
	cout << "<preorder>" << endl;
	exBST.preorder(exBST.getRoot());    // preorder 출력
	cout << endl << endl;               // 55 17 13 10 19 18 43 76 61 65 89

	cout << "<inorder>" << endl;
	exBST.inorder(exBST.getRoot());     // inorder 출력
	cout << endl << endl;               // 10 13 17 18 19 43 55 61 65 76 89

	cout << "<postorder>" << endl;
	exBST.postorder(exBST.getRoot());   // postorder 출력
	cout << endl;                       // 10 13 18 43 19 17 65 61 89 76 55

	system("pause");
	return 0;
};