// ��ϣ������̽��

#include<iostream>
#include<vector>

using namespace std;

enum State
{
	EXIST,
	EMPTY,
	DELETE,
};

template<class K, class V>
struct HashNode
{
	pair<K, V> _value;
	// ����״̬
	State _state;

	HashNode(const pair<K, V>& value = pair<K, V>())
		:_value(value)
		,_state(EMPTY)
	{}
};


template<class K, class V>
class HashTable
{
public:
	HashTable(size_t size = 10)
		:_size(0)
	{
		_table.resize(size);
	}

	// 1. ����
	bool insert(const pair<K, V>& value)
	{
		checkCapacity();

		int idx = value.first % _table.size();

		while (_table[idx]._state == EXIST)
		{
			// Ԫ���Ѿ�����,����ʧ��
			if (_table[idx]._value.first == value.first)
				return false;
			idx++;
			if (idx == _table.size()) 
				idx = 0;
		}
		// �ҵ��˺��ʵ�λ��
		_table[idx]._value = value;
		_table[idx]._state = EXIST;
		++_size;
		
		return true;
	}
	// 2. ����
	HashNode<K, V>* find(const K& key)
	{
		int idx = key % _table.size();
		// ���ղ��ҽ���
		while (_table[idx]._state != EMPTY)
		{
			// ֻ��״̬Ϊ���ڵ�������Ч
			if (_table[idx]._state == EXIST && _table[idx]._value.first == key)
				return &_table[idx];
			idx++;
			if (idx == _table.size())
				idx = 0;
		}
		return nullptr;
	}
	// 3. ɾ��
	bool erase(const K& key)
	{
		HashNode<K, V>* tar = find(key);

		if (tar == nullptr) return false;

		// ֻ�޸�״̬
		tar->_state = DELETE;
		_size--;

		return true;
	}
	// 4. �������������
	void checkCapacity()
	{
		// ��������Ϊ 0.7 ������Ҫ����
		if (_size * 10 / _table.size() >= 7)
		{
			HashTable ht(2 * _table.size());
			// ����Ԫ���ڹ�ϣ���е�λ��
			for (int i = 0; i < _table.size(); i++)
			{
				if (_table[i]._state == EXIST)
					ht.insert(_table[i]._value);
			}
			// �����Ƴ�ǰ ��ʱ���� ht ��������������� vector �����ԭ���� _table ��Դ  
			swap(ht._table, _table);
		}
	}

private:
	vector<HashNode<K, V>> _table;
	// �Ѿ�ʹ�õĿռ�
	size_t _size;
};

int main(void)
{
	HashTable<int, int> ht;

	ht.insert(make_pair(1, 1));
	ht.insert(make_pair(3, 3));
	ht.insert(make_pair(4, 4));
	ht.insert(make_pair(5, 5));
	ht.insert(make_pair(7, 7));

	HashNode<int, int>* p1 =  ht.find(7);
	HashNode<int, int>* p2 = ht.find(8);
	
//	ht.erase(1);

	ht.insert(make_pair(8, 8));
	ht.insert(make_pair(9, 9));
	ht.insert(make_pair(10, 10));


	return 0;
}


