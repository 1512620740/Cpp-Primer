#include"HashTable.hpp"

template<class K, class V, class HashFun = KeyIsInt<int>>
class UnorderedMap
{
	// ˽�У����ڴ�����ʹ��
	struct MapKeyOfValue
	{
		const K& operator()(const pair<K, V>& val)
		{
			return val.first;
		}
	};
public:
	// ����һ��Ҫ���� typename
	typedef typename HashTable<K, pair<K, V>, MapKeyOfValue, HashFun>::Iterator iterator;

	pair<iterator, bool> insert(const pair<K, V>& val)
	{
		return _hashTable.insert(val);
	}

	V& operator[](const K& key)
	{
		// ���ȳ��Բ���
		pair<iterator, bool> ret = _hashTable.insert(make_pair(key, V()));
		
		// ->second �൱�� &_node->_value->second
		return ret.first->second;
	}
	
	iterator begin()
	{
		return _hashTable.begin();
	}

	iterator end()
	{
		return _hashTable.end();
	}

private:
	HashTable<K, pair<K, V>, MapKeyOfValue, HashFun> _hashTable;
};

