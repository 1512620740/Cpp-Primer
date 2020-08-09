#pragma once
#include<iostream>
#include<utility>

using namespace std;

enum Color
{
	RED,
	BLACK,
};

template<class Value>
struct RBNode
{
	typedef RBNode<Value>* Ptr_RBNode;

	Value _data;
	Color _color;
	Ptr_RBNode _left;
	Ptr_RBNode _right;
	Ptr_RBNode _parent;

	RBNode(const Value& data = Value())
		:_data(data)
		,_color(RED) // �ڵ���ɫĬ�ϳ�ʼ��Ϊ red
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
	{}
};

template<class Value>
struct RBIterator
{
	typedef RBNode<Value> Node;
	typedef RBIterator Self;

	Node* _node;

	RBIterator(Node* node)
		:_node(node)
	{}

	Value& operator*()
	{
		return _node->_data;
	}

	Value* operator->()
	{
		return &_node->_data;
	}

	bool operator==(const Self& it)
	{
		return _node == it._node;
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	Self& operator++()
	{
		// �����ǰ�ڵ����ҽڵ�
		if (_node->_right)
		{
			_node = _node->_right;
			// �� _node ��Ϊ���ҽڵ�
			while (_node->_left)
				_node = _node->_left;
		}
		// ���ϻ��ݣ������ǰ�ڵ�Ϊ���ڵ���ҽڵ㣬�������ϻ���
		else
		{
			Node* parent = _node->_parent;
			while (_node == parent->_right)
			{
				_node = parent;
				parent = parent->_parent;
			}
			// �� parent Ϊ _header ,_node Ϊ�������ĸ��ڵ�ʱ��
			// һ�����˳������ while ѭ��,��ʱӦ�ý� _node ��Ϊ _header
			// ��� _node ���ڸ��ڵ����࣬ҲӦ�õ���ִ��һ�Σ��� _node ָ����һ�η��ʵĽڵ�
			/*_node = parent;*/
			// �����д����һ�����⣬���������ֻ��һ���ڵ㡣_header->right == _node
			// _node ���ߵ� _header, parent �ߵ� _node ��ʱ�˳�ѭ��
			// _node �ٱ���ֵΪ _node , ���Ե������ı���������ѭ��
			if (_node->_right != parent)
				_node = parent;
		}

		return *this;
	}
};

// KeyOfValue �º�������������ȡ value ��Ӧ�� key
// V �� pair ����
template<class K, class V, class KeyOfValue>
class RBTree
{
public:
	typedef RBNode<V> Node;
	typedef RBIterator<V> iterator;

private:
	Node* _header;
	KeyOfValue kov;

public:
	iterator begin()
	{
		return iterator(_header->_left);
	}

	iterator end()
	{
		return iterator(_header);
	}
	
	RBTree()
		:_header(new Node)
	{
		_header->_left = _header->_right = _header;
	}

	pair<iterator, bool> insert(const V& data)
	{
		cout << "���� " << data.first << "  :";

		if (_header->_parent == nullptr)
		{
			Node* node = new Node(data);

			node->_color = BLACK;
			_header->_parent = node;
			node->_parent = _header;

			_header->_left = node;
			_header->_right = node;

			return make_pair(iterator(node), true);
		}

		Node* cur = _header->_parent;
		Node* parent = nullptr;

		// ����
		while (cur)
		{
			parent = cur;
			if (kov(data) == kov(cur->_data))
				return make_pair(iterator(cur), false);
			else if (kov(data) > kov(cur->_data))
				cur = cur->_right;
			else 
				cur = cur->_left;
		}
		cur = new Node(data);

		// ����
		if (kov(parent->_data) > kov(data))
			parent->_left = cur;
		else
			parent->_right = cur;

		cur->_parent = parent;
		
		// ����һ�·���ʱ�²���Ľڵ��ָ��
		Node* ret = cur;
		
		// �������޸���ɫ ��ת
		while(cur != _header->_parent && cur->_parent->_color == RED)
		{ 
			Node* p = cur->_parent;
			Node* pp = p->_parent;
			
			// 1. ����λ�����游�ڵ����������
			if (pp->_left == p)
			{
				Node* u = pp->_right;
				// ���һ���������ڵ� ������Ϊ��
				if (u && u->_color == RED)
				{
					u->_color = p->_color = BLACK;
					pp->_color = RED;
					
					// �������ϲ鿴�游�ڵ�ĸ��ڵ��Ƿ�Ϊ��ɫ
					cur = pp;

				}								
				// �������ڵ� ������ �� ������Ϊ��
				else
				{
					// ��� ����cur �� p ���Ҳ࣬˫��
					if (cur == p->_right)
					{
						// �Ƚ���������ת��Ϊ��һ�����
						_rotateL(p);
						swap(cur, p);
					}
					
					// ��� ����cur �� p ����࣬����
					// ����
					_rotateR(pp);
					p->_color = BLACK;
					pp->_color = RED;
					

					// ��ʱ p Ϊ�����������ĸ����� p Ϊ��ɫ �����Խ�������
					break;
				}
			}

			// 2. ����λ�����游�ڵ����������
			else
			{
				Node* u = pp->_left;
				// �������ڵ� ������Ϊ��
				if (u && u->_color == RED)
				{
					u->_color = p->_color = BLACK;
					pp->_color = RED;

					// �������ϲ鿴�游�ڵ�ĸ��ڵ��Ƿ�Ϊ��ɫ
					cur = pp;

				}
				// �������ڵ� ������ �� ������Ϊ��
				else
				{
					if (cur == p->_left)
					{
						// �Ƚ���������ת��Ϊ��һ�����
						_rotateR(p);
						swap(cur, p);

					}

					// ����
					_rotateL(pp);
					p->_color = BLACK;
					pp->_color = RED;

					// ��ʱ p Ϊ�����������ĸ����� p Ϊ��ɫ �����Խ�������
					break;
				}
			}
			
		}	
		// ������Ϊ��
		_header->_parent->_color = BLACK;
		_header->_left = _leftMost();
		_header->_right = _rightMost();

		return make_pair(iterator(ret), true);
	}

	void print()
	{
		_inOrderTraversal(_header->_parent);
	}

	bool isRBTree()
	{
		Node* root = _header->_parent;
		Node* cur = root;
		int blackCount = 0;

		if (root == nullptr) return true;

		// 1. ���ڵ��Ƿ�Ϊ��
		if (root->_color != BLACK) return false;

		// �ȱ���һ��·���������ɫ�ڵ�ĸ���
		while (cur)
		{
			if (cur->_color == BLACK) 
				blackCount++;
			cur = cur->_left;
		}
		
		int curCount = 0;

		return _isRBTree(root, blackCount, curCount);
	}

private:

	void _rotateR(Node* parent)
	{
		Node* pp = parent->_parent; // grandparent
		Node* p = parent;           // parent
		Node* sL = parent->_left;   // left son of parent
		Node* sLR = sL->_right;     // right son of sL ��һ������

		// �޸� pp �ĺ��ӽڵ㣬�� sL �ĸ��ڵ�
		// p ���������ĸ�
		if (p == _header->_parent)
		{
			_header->_parent = sL;
			sL->_parent = _header;
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
	}

	void _rotateL(Node* parent)
	{
		Node* pp = parent->_parent; // grandparent
		Node* p = parent;           // parent
		Node* sR = parent->_right;   // right son of parent
		Node* sRL = sR->_left;     // left son of sR ��һ������

		// �޸� pp �ĺ��ӽڵ㣬�� sR �ĸ��ڵ�
		// p ���������ĸ�
		if (p == _header->_parent)
		{
			_header->_parent = sR;
			sR->_parent = _header;
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
	}

	Node* _leftMost()
	{
		Node* cur = _header->_parent;
		while (cur && cur->_left)
			cur = cur->_left;
		return cur;
	}

	Node* _rightMost()
	{
		Node* cur = _header->_parent;
		while (cur && cur->_right)
			cur = cur->_right;
		return cur;
	}

	void _inOrderTraversal(Node* root)
	{
		if (root)
		{
			_inOrderTraversal(root->_left);
			cout << "key: " << root->_data.first << " ";
			if (root->_color == RED)
				cout << "��ɫ" << endl;
			else
				cout << "��ɫ" << endl;
			_inOrderTraversal(root->_right);
		}
	}

	bool _isRBTree(Node* root, const int blackCount, int curCount)
	{
		// һ��·��������, ��ɫ�ڵ���������׼ֵ��ͬ�����Ǻ����
		if (root == nullptr)
		{
			return (curCount == blackCount) ? true : false;
		}

		if (root->_color == BLACK)
			curCount++;

		// �жϺ�ɫ�ڵ��Ƿ�����
		Node* parent = root->_parent;

		if (parent && parent->_color == RED && root->_color == RED)
		{
			cout << "��ɫ�ڵ��ظ�" << endl;
			return false;
		}

		return _isRBTree(root->_left, blackCount, curCount)
			&& _isRBTree(root->_right, blackCount, curCount);
	}
};
