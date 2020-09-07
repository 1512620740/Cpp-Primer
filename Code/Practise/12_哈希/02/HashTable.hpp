#include<iostream>
#include<vector>

using namespace std;

/*
 * ��ɢ�У�ָ������ + ������
 */

// �º���
template<class K>
struct KeyOfValue
{
	const K& operator()(const K& key)
	{
		return key;
	}
};

template<class V>
struct HashNode
{
	V _value;
	HashNode<V>* _next;

	HashNode(const V& value)
		:_value(value)
		,_next(nullptr)
	{}
};

// ǰ������
template<class K, class V, class keyOfValue, class HashFun>
class HashTable;

template<class K, class V, class keyOfValue, class HashFun>
struct HashIterator
{
	typedef HashNode<V> Node;
	typedef HashTable<K, V, keyOfValue, HashFun> _HashTable;
	typedef HashIterator<K, V, keyOfValue, HashFun> Self;

	Node* _node;
	_HashTable* _ht;

	HashIterator( Node* node,  _HashTable* ht)
		:_node(node)
		,_ht(ht)
	{}

	V& operator*() const 
	{
		return _node->_value;
	}

	V* operator->() const
	{
		return &_node->_value;
	}

	bool operator!=(const Self& it) const
	{
		return _node != it._node;
	}

	Self& operator++()  
	{
		// ��� _node._next ����
		if (_node->_next != nullptr)
		{
			_node = _node->_next;
		}
		// �ڹ�ϣ�������Ѱ�ҷǿ�����
		else
		{
			keyOfValue kov;
			HashFun hf;

			int idx = hf(kov(_node->_value)) % _ht->_table.size();

			idx++;
			for (; idx < _ht->_table.size(); idx++)
			{
				if (_ht->_table[idx])
				{
					_node = _ht->_table[idx];
					break;
				}
			}
			// ��ϣ���ѱ�����
			if (idx == _ht->_table.size())
			 _node = nullptr;

			return *this;
		}
	}
};

struct StrToInt
{
	size_t operator()(const string& str)
	{
		size_t hash = 0;
		for (const auto& ch : str)
		{
			hash = hash * 131 + ch;
		}

		return hash;
	}
};

template<class V>
struct KeyIsInt
{
	size_t operator()(const V& val)
	{
		return val;
	}
};

template<class K, class V, class keyOfValue, class HashFun>
class HashTable
{

public:
	// �� HashIterator ����Ϊ HashTable ����Ԫ��
	template<class K, class V, class keyOfValue, class HashFun>
	friend struct HashIterator;

	typedef HashNode<V> Node;
	typedef HashTable<K, V, keyOfValue, HashFun> Self;
	typedef HashIterator<K, V, keyOfValue, HashFun> Iterator;

	Iterator begin()
	{
		for (int i = 0; i < _table.size(); i++)
		{
			if (_table[i])
				return Iterator(_table[i], this);
		}
		return Iterator(nullptr, this);
	}

	Iterator end()
	{
		return Iterator(nullptr, this);
	}
	
	pair<Iterator, bool> insert(const V& value)
	{
		// 1. �������
		checkCapacity();

		// 2. �ɹ�ϣ��������λ��
		//      1) kov ���� key ֵ
		//      2) hf �� key ֵת��Ϊ����
		keyOfValue kov;
		HashFun hf;

		int idx = hf(kov(value)) % _table.size();

		// 3. �鿴 key �Ƿ��Ѿ�����
		Node* cur = _table[idx];
		while (cur)
		{
			// key �Ѿ�����
			if (hf(kov(value)) == hf(kov(cur->_value)))
				return make_pair(Iterator(cur, this), false);
			cur = cur->_next;
		}

		// 4. ���룺ͷ��
		Node* node = new Node(value);
		node->_next = _table[idx];
		_table[idx] = node;
		_size++;

		return make_pair(Iterator(node, this), true);
	}

	// ��ȡ�������е�����
	size_t getNewSize()
	{
		const int PRIMECOUNT = 28;
		const size_t primeList[PRIMECOUNT] =
		{ 53ul, 97ul, 193ul, 389ul, 769ul, 1543ul,
			3079ul, 6151ul, 12289ul, 24593ul, 49157ul,
			98317ul, 196613ul, 393241ul, 786433ul, 1572869ul,
			3145739ul, 6291469ul, 12582917ul, 25165843ul, 50331653ul,
			100663319ul, 201326611ul, 402653189ul, 805306457ul,
			1610612741ul,3221225473ul, 4294967291ul,
		};

		for (int i = 0; i < PRIMECOUNT; i++)
		{
			if (primeList[i] > _size)
				return primeList[i];
		}
		
		return primeList[PRIMECOUNT - 1];
	}

	void checkCapacity()
	{
		keyOfValue kov;
		HashFun hf;

		// ���˳���Ĵ�С�͵�ǰԪ�ظ�����ͬ������Ҫ����
		if (_size == _table.size())
		{			
			vector<Node*> newTable;
			
			//newTable.resize((_size == 0) ? 5 : 2 * _size);
			
			// ʹ����������Ϊ���ݺ�����Ĵ�С���������Լ��ٹ�ϣ��ͻ
			size_t newSize = getNewSize();
			newTable.resize(newSize);

			// ת�ƾɱ��еĽڵ�
			for (int i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{
					// �����µ�λ��
					int idx = hf(kov(cur->_value)) % newTable.size();
					// ������һ���ڵ�
					Node* next = cur->_next;
					// ͷ��
					cur->_next = newTable[idx];
					newTable[idx] = cur;
					// ������һ���ڵ�
					cur = next;
				}
				_table[i] = nullptr;
			}
			swap(_table, newTable);
		}
	}

	Node* find(const K& key)
	{
		if (_table.size() == 0) return nullptr;
		
		int idx = key % _table.size();
		
		keyOfValue kov;
		HashFun hf;

		Node* cur = _table[idx];

		while (cur)
		{
			if (hf(kov(cur->_value)) == key)
				return cur;
			cur = cur->_next;
		}

		return nullptr;
	}

	bool erase(const K& key)
	{
		if (_table.size() == 0) return false;
		
		HashFun hf;
		int idx = hf(key) % _table.size();
		keyOfValue kov;
		Node* cur = _table[idx];
		Node* parent = cur;

		while (cur)
		{
			if (hf(kov(cur->_value)) == key)
			{
				// Ŀ��ڵ�Ϊ��ͷ
				if (cur == _table[idx])
				{
					_table[idx] = cur->_next;
				}
				else
				{
					parent->_next = cur->_next;
				}

				delete cur;
				--_size;
				return true;
			}

			parent = cur;
			cur = cur->_next;
		}
		return false;
	}

private:
	vector<HashNode<V>*> _table;
	size_t _size = 0;
};



//int main(void)
//{
//	HashTable<int, int, KeyOfValue<int>> ht;
//
//	ht.insert(4);
//	ht.insert(3);
//	ht.insert(2);
//	ht.insert(1);
//	ht.insert(6);
//	ht.insert(11);
//
//	HashNode<int>* p = ht.find(11);
//
//	p = ht.find(12);
//
//	ht.erase(1);
//
//	return 0;
//}