// 12161756 ����ȣ
#pragma once
#include <iostream>
using namespace std;
template <typename T> class BST;

template <typename T>
class Node {                    // ����� ���� left & right child�� �����ϴ� Node Ŭ����
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
		if (search(root, n->val) == NULL) {    // insert�� ���� ���� Ʈ���� ���� ���� ����
			Node<T>* stNode = root;
			Node<T>* parent = stNode;

			while (stNode != NULL) {           // ���� node�� Null���� �ƴ� ���� ����
				parent = stNode;               // parent�� stNode�� ����

				if (n->val < parent->val)      // insert ��� < parent, left child�� �̵�
					stNode = stNode->left;
				else                           // insert ��� > parent, right child�� �̵�
					stNode = stNode->right;
			}                                  // while �� �Ϸ�, ���� parent : external node

			if (n->val < parent->val)          // insert ��� < parent,
				parent->left = n;              // parent�� left child�� insert�� ��� ����

			else                               // insert ��� > parent,
				parent->right = n;             // parent�� right child�� insert�� ��� ����
		}
	}

	Node<T>* search(Node<T>* stNode, T v) {
		if (stNode == NULL)                    // ���� node = NULL,
			return NULL;                       // NULL ����

		else if (v == stNode->val)             // search ��� = ���� node,
			return stNode;                     // ���� node ����

		else if (v < stNode->val)              // search ��� < ���� node, 
			search(stNode->left, v);           // ���� node�� left child�� search

		else                                   // search ��� > ���� node,
			search(stNode->right, v);          // ���� node�� right child�� search
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