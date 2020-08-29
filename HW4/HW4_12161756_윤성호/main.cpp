// 12161756 ����ȣ
#include "tree.h"

int main() {
	cout << "12161756 ����ȣ" << endl;

	BST<int> exBST(55);                 // 55�� root�� ���� tree ��ü ����
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

	cout << "<insert ����>" << endl;
	cout << "55(R) 17 13 76 19 61 43 18 65 89 10" << endl << endl;
	
	cout << "<preorder>" << endl;
	exBST.preorder(exBST.getRoot());    // preorder ���
	cout << endl << endl;               // 55 17 13 10 19 18 43 76 61 65 89

	cout << "<inorder>" << endl;
	exBST.inorder(exBST.getRoot());     // inorder ���
	cout << endl << endl;               // 10 13 17 18 19 43 55 61 65 76 89

	cout << "<postorder>" << endl;
	exBST.postorder(exBST.getRoot());   // postorder ���
	cout << endl;                       // 10 13 18 43 19 17 65 61 89 76 55

	system("pause");
	return 0;
};