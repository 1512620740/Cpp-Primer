#pragma once
#include<iostream>

using namespace std;

template<class T>
struct AVLNode
{
	AVLNode<T>* _left;
	AVLNode<T>* _right;
	AVLNode<T>* _parent;
	T _data;
	int _bf;

	AVLNode(T data)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_data(data)
		,_bf(0)
	{}
};

template<class T>
class AVLTree
{
	typedef AVLNode<T> Node;
public:
	AVLTree()
		:_root(nullptr)
	{}

	bool insert(const T& data)
	{
		Node* node = new Node(data);
		if (_root == nullptr)
		{
			_root = node;
			return true;
		}

		Node* cur = _root;
		Node* parent = _root;
		while (cur)
		{
			parent = cur;
			if (cur->_data < data)
			{
				cur = cur->_right;
			}
			else if (cur->_data > data)
			{
				cur = cur->_left;
			}
			else 
			{
				delete node;
				return false;
			}
		}
		if (parent->_data < data)
			parent->_right = node;
		else
			parent->_left = node;
		
		node->_parent = parent;
		
		cur = node;
		// ����ƽ������ + ����
		while (parent)
		{
			if (parent->_left == cur)
				--parent->_bf;
			else
				++parent->_bf;

			// �ж��Ƿ���Ҫ�������ϸ������Ƚڵ�

			// ����������߶�û�б仯������Ҫ����
			if (parent->_bf == 0)
				break;
			// ��������
			else if (parent->_bf == -1 || parent->_bf == 1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// ����
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					cout << "���� " << data << " �������� " << endl;
					_rotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					cout << "���� " << data << " �������� " << endl;
					_rotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					cout << "���� " << data << " ���� ������ " << endl;
					_rotateLR(parent);
				}
				else
				{
					cout << "���� " << data << " ���� ������ " << endl;
					_rotateRL(parent);
				}
				break;
			}
		}
		return true;
	}

	bool isAVLT()
	{
		return _isAVLT(_root);
	}


	void print()
	{
		_inordertraversal(_root);
		cout << endl;
	}

private:
	Node* _root;
	
	/*
	 * ���� �ҵ���
	 * 1. �ı�ڵ��ָ�򣨸��������������ӣ������ӣ�
	 * 2. �ı�ƽ������
	 */
	void _rotateR(Node* parent)
	{
		Node* pp = parent->_parent; // grandparent
		Node* p = parent;           // parent
		Node* sL = parent->_left;   // left son of parent
		Node* sLR = sL->_right;     // right son of sL ��һ������

		// �޸� pp �ĺ��ӽڵ㣬�� sL �ĸ��ڵ�
		// p ���������ĸ�
		if (pp == nullptr)
		{
			_root = sL;
			sL->_parent = nullptr;
		}
		// p ���滹�����Ƚڵ�
		else
		{
			if (pp->_left == p)
			{
				pp->_left = sL;
			}
			else
			{
				pp->_right = sL;
			}
			sL->_parent = pp;
		}

		// �޸� p �ĸ��ڵ� �� sL ���ӽڵ�
		sL->_right = p;
		p->_parent = sL;

		// �޸� p ���ӽڵ� �� sLR �ĸ��ڵ�
		p->_left = sLR;
		// ��� sLR ���ڣ��ı����ĸ��׽ڵ�
		if (sLR)
		{
			sLR->_parent = p;
		}
		// ����ƽ������
		p->_bf = sL->_bf = 0;
	}

	/*
	 * ���� ����
	 * 1. �ı�ڵ��ָ�򣨸��������������ӣ������ӣ�
	 * 2. �ı�ƽ������
	 */
	void _rotateL(Node* parent)
	{
		Node* pp = parent->_parent; // grandparent
		Node* p = parent;           // parent
		Node* sR = parent->_right;   // right son of parent
		Node* sRL = sR->_left;     // left son of sR ��һ������

		// �޸� pp �ĺ��ӽڵ㣬�� sR �ĸ��ڵ�
		// p ���������ĸ�
		if (pp == nullptr)
		{
			_root = sR;
			sR->_parent = nullptr;
		}
		// p ���滹�����Ƚڵ�
		else
		{
			if (pp->_left == p)
			{
				pp->_left = sR;
			}
			else
			{
				pp->_right = sR;
			}
			sR->_parent = pp;
		}

		// �޸� p �ĸ��ڵ� �� sR ���ӽڵ�
		sR->_left = p;
		p->_parent = sR;

		// �޸� p ���ӽڵ� �� sRL �ĸ��ڵ�
		p->_right = sRL;
		// ��� sRL ���ڣ��ı����ĸ��׽ڵ�
		if (sRL)
		{
			sRL->_parent = p;
		}
		// ����ƽ������
		p->_bf = sR->_bf = 0;
	}
	
	/*
	 * ���� ���� + �ҵ���
	 * 1. �ı�ڵ��ָ�򣨸��������������ӣ������ӣ�
	 * 2. �ı�ƽ������
	 */
	void _rotateLR(Node* parent)
	{
		Node* fir = parent->_left;
		Node* sec = parent;

		int bf = fir->_right->_bf;

		_rotateL(fir);
		_rotateR(sec);

		if (bf == -1)
			sec->_bf = 1;
		else if(bf == 1)
			fir->_bf = -1;
	}

	/*
	 * ���� �ҵ��� + ����
	 * 1. �ı�ڵ��ָ�򣨸��������������ӣ������ӣ� �������ӣ�
	 * 2. �ı�ƽ������
	 */
	void _rotateRL(Node* parent)
	{
		Node* fir = parent->_right;
		Node* sec = parent;

		int bf = fir->_left->_bf;

		_rotateR(fir);
		_rotateL(sec);

		if (bf == -1)
			fir->_bf = 1;
		else if(bf == 1)
			sec->_bf = -1;
	}

	void _inordertraversal(Node* root)
	{
		if (root)
		{
			_inordertraversal(root->_left);
			cout << root->_data << " ";
			_inordertraversal(root->_right);
		}
	}

	bool _isAVLT(Node* root)
	{
		if (root == nullptr)
			return true;

		// ���������߶Ȳ��ƽ���������
		int subL = _Height(root->_left);
		int subR = _Height(root->_right);
		if (root->_bf != subR - subL)
		{
			cout << "�ڵ㣺" << root->_data << "bf �쳣��" << root->_bf << " != " << subR - subL;
			return false;
		}

		return abs(root->_bf) <= 1 &&
			_isAVLT(root->_left) &&
			_isAVLT(root->_right);
	}

	int _Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int left = _Height(root->_left);
		int right = _Height(root->_right);

		return left > right ? left + 1 : right + 1;
	}
};



