//#include"HashTable.hpp"
//
//template<class K, class V>
//class UnorderedMap
//{
//	// ˽�У����ڴ�����ʹ��
//	struct MapKeyOfValue
//	{
//		const K& operator()(const pair<K, V>& val)
//		{
//			return val.first;
//		}
//	};
//public:
//	bool insert(const pair<K, V>& val)
//	{
//		return _hashTable.insert(val);
//	}
//private:
//	HashTable<K, pair<K, V>, MapKeyOfValue> _hashTable;
//};