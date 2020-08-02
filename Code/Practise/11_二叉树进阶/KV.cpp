#include<iostream>
#include<string>

using namespace std;

template<class K, class V>
struct BSTNode
{
	K _key;
	V _val;
	BSTNode<K, V>* _left;
	BSTNode<K, V>* _right;

	BSTNode(const K& key = K(), const V& val = V())
		:_val(val)
		,_key(key)
		, _left(nullptr)
		, _right(nullptr)
	{}
};

template<class K, class V>
class BSTree
{
	typedef BSTNode<K, V> Node;
public:
	// ����
	Node* search(const K& key)
	{
		Node* cur = _root;

		while (cur != nullptr)
		{
			if (key == cur->_key)
				return cur;
			else if (key > cur->_key)
				cur = cur->_right;
			else
				cur = cur->_left;
		}
		return nullptr;
	}

	// ���룺�����Ԫ���Ѿ����ڣ������κβ���
	//		 �����λ��Ϊ����Ϊ 0 �� 1 �Ľڵ�
	bool insert(const K& key, const V& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(key, val);
			return true;
		}

		Node* cur = _root;
		Node* parent = cur;
		while (cur != nullptr)
		{
			parent = cur;
			if (key == cur->_key)
				return false;
			else if (key < cur->_key)
				cur = cur->_left;
			else
				cur = cur->_right;
		}

		cur = new Node(key, val);
		if (key < parent->_key)
			parent->_left = cur;
		else
			parent->_right = cur;
		return true;
	}

	// ɾ������Ϊ 2 �Ľڵ� -> �����������ҽڵ������������ڵ� -> 
	// �滻��ɾ���ڵ㣨ֵ�滻��-> ɾ���ڶ����еĽڵ㣨��Ϊ 0 �� 1��
	bool erase(const K& key)
	{
		Node* cur = _root;
		Node* parent = cur;

		while (cur)
		{
			if (cur->_key == key)
				break;
			else if (key < cur->_key) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				parent = cur;
				cur = cur->_right;
			}
		}

		if (cur == nullptr)
			return false;

		// 1. ��ɾ���Ľڵ�ΪҶ��
		if (cur->_left == nullptr && cur->_right == nullptr)
		{
			if (_root == cur)
			{
				_root == nullptr;
			}
			else {
				if (parent->_left == cur)
					parent->_left = nullptr;
				else
					parent->_right = nullptr;
			}
			delete cur;

			return true;
		}
		// 2.��ɾ���Ľڵ�������Ϊ��
		else if (cur->_left == nullptr)
		{
			if (_root == cur)
			{
				_root = _root->_right;
			}
			else
			{
				if (parent->_left == cur)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
			delete cur;

			return true;
		}
		// 3.��ɾ���Ľڵ�������Ϊ��
		else if (cur->_right == nullptr)
		{
			if (_root == cur)
			{
				_root = _root->_left;
			}
			else
			{
				if (parent->_left == cur)
					parent->_left = cur->_left;
				else
					parent->_right = cur->_left;
			}
			delete cur;

			return true;
		}
		// 4.��ɾ���Ľڵ��Ϊ 2
		else
		{
			Node* del = cur->_left;
			Node* pDel = cur;
			// �ҵ������������ҽڵ㣨�����������ֵ��
			while (del->_right)
			{
				pDel = del;
				del = del->_right;
			}
			// �滻����Ҫ��ɾ���Ľڵ��ԭ��Ҫɾ���Ľڵ��ֵ
			cur->_val = del->_val;

			// �޸ı�ɾ���Ľڵ�ĸ��ڵ��ָ����
			if (pDel == cur)
				pDel->_left = del->_left;
			else
				pDel->_right = del->_left;

			// �ͷŽڵ�
			delete del;

			return true;
		}

	}

	void print()
	{
		cout << "�������" << endl;
		inOrderTraversal(_root);
		cout << endl;
	}

	BSTree()
		:_root(nullptr)
	{}

	BSTree(const BSTree& copy)
	{
		_root = CopyTreePro(copy._root);
	}

	// �ִ�д��
	BSTree<K, V>& operator=(BSTree<K, V> tmp)
	{
		swap(_root, tmp._root);
		return *this;
	}


	~BSTree()
	{
		Destory(_root);
		_root = nullptr;
	}

private:
	Node* _root = nullptr;

	void inOrderTraversal(Node* node)
	{
		if (node)
		{
			inOrderTraversal(node->_left);
			cout << node->_key << " " << node->_val << " ";
			inOrderTraversal(node->_right);
		}
	}

	void Destory(Node* root)
	{
		if (root)
		{
			Destory(root->_left);
			Destory(root->_right);
			delete root;
		}
	}

	void CopyTree(const Node* root)
	{
		if (root)
		{
			insert(root->_key, root->_val);
			CopyTree(root->_left);
			CopyTree(root->_right);
		}
	}

	Node* CopyTreePro(const Node* root)
	{
		if (root)
		{
			Node* cur = new Node(root->_key, root->_val);
			cur->_left = CopyTreePro(root->_left);
			cur->_right = CopyTreePro(root->_right);
			return cur;
		}
		return nullptr;
	}
};

int main(void)
{
	BSTree<int, string> bst;

	bst.insert(0, "zero");
	bst.insert(1, "one");
	bst.insert(2, "two");
	bst.insert(0, "zero2");
	bst.insert(3, "zero");
	bst.print();

	bst.erase(2);
	bst.print();
}