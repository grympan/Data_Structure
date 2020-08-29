// 12161756 윤성호
#pragma once
#include <iostream>
using namespace std;
template <typename T> class BST;

template <typename T>
class Node {                    // 노드의 값과 left & right child를 지정하는 Node 클래스
	friend class BST<T>;
private:
	T val;
	Node* left;
	Node* right;
public:
	Node(T v = 0, Node* l = NULL, Node* r = NULL) {
		this->val = v;
		this->left = l;
		this->right = r;
	}
};

template <typename T>
class BST {
private:
	Node<T>* root;
public:
	BST(T val = 0) {
		root = new Node<T>(val);
	}

	Node<T>* getRoot() {
		return root;
	}

	void visit(Node<T>* stNode) {
		cout << stNode->val << " ";
	}

	void insert(Node<T> * n) {
		if (search(root, n->val) == NULL) {    // insert될 값이 현재 트리에 없을 때만 진행
			Node<T>* stNode = root;
			Node<T>* parent = stNode;

			while (stNode != NULL) {           // 기준 node가 Null값이 아닐 동안 진행
				parent = stNode;               // parent에 stNode를 대입

				if (n->val < parent->val)      // insert 대상 < parent, left child로 이동
					stNode = stNode->left;
				else                           // insert 대상 > parent, right child로 이동
					stNode = stNode->right;
			}                                  // while 문 완료, 현재 parent : external node

			if (n->val < parent->val)          // insert 대상 < parent,
				parent->left = n;              // parent의 left child로 insert될 노드 지정

			else                               // insert 대상 > parent,
				parent->right = n;             // parent의 right child로 insert될 노드 지정
		}
	}

	Node<T>* search(Node<T>* stNode, T v) {
		if (stNode == NULL)                    // 기준 node = NULL,
			return NULL;                       // NULL 리턴

		else if (v == stNode->val)             // search 대상 = 기준 node,
			return stNode;                     // 기준 node 리턴

		else if (v < stNode->val)              // search 대상 < 기준 node, 
			search(stNode->left, v);           // 기준 node의 left child를 search

		else                                   // search 대상 > 기준 node,
			search(stNode->right, v);          // 기준 node의 right child를 search
	}

	void preorder(Node<T> * stNode) {           // Root -> Left -> Right
		if (stNode != NULL) {
			visit(stNode);
			preorder(stNode->left);
			preorder(stNode->right);
		}
	}

	void inorder(Node<T> * stNode) {            // Left -> Root -> Right
		if (stNode != NULL) {
			inorder(stNode->left);
			visit(stNode);
			inorder(stNode->right);
		}
	}

	void postorder(Node<T> * stNode) {          // Left -> Right -> Root
		if (stNode != NULL) {
			postorder(stNode->left);
			postorder(stNode->right);
			visit(stNode);
		}
	}
};