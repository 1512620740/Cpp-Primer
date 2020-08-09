#include<set>
#include<iostream>
#include<map>
#include<vector>

using namespace std;

void test1()
{
	set<int> s;

	int array[] = { 1, 2, 3, 4, 5 };

	set<int> s2(array, array + 5);

	set<int> s3(s2);

	// set ��Ԫ�ز��ܱ��޸ģ�����������ֻ����
}

void test2()
{
	map<string, int> m;

	vector<pair<string, int>> vec;
	// key �����ظ���value �����ظ�
	for (int i = 0; i < 10; i++)
	{
		pair<string, int> p((string)"bite" + (char)('0' + i), 5);
		vec.push_back(p);
		vec.push_back(pair<string, int>((string)"69" + (char)('0' + i), 10)); // ��������
		vec.push_back(make_pair((string)"68" + (char)('0' + i), 3)); // make_pair �ӿ� 
	}
	map<string, int> m2(vec.begin(), vec.end());
	map<string, int> copy(m2);

	map<string, int>::iterator it = m2.begin();
	// �������������� pair*
	// ������֧�� value �޸ģ���֧�� key �޸�
	while (it != m2.end())
	{
		cout << it->first << " " << it->second << endl;
		++it;
	}

	cout << "the number of elements in m2: " << m2.size() << endl;
}

void test3()
{
	map<int, int> m;

	cout << m[2] << endl; // 2 �� key�������ڵ��� insert ����
	//cout << m.at(2) << endl; // 2 ����������׳��쳣
	// �ɹ�ʱ������ value ������
	int& val = m[2];
	val = 10;
	cout << m[2] << endl;
}

void test4()
{
	map<string, int> m;

	/*
	single element(1)
		pair<iterator, bool> insert(const value_type & val);
	with hint(2)
		iterator insert(iterator position, const value_type & val);
    */
	// ��һ������������� pair ���͵Ķ��󣬷���ֵ�е� bool �����Ƿ����ɹ�
	// ���Ҫ����� key �Ѿ��� map �д��ڣ���ô�᷵���Ѿ����ڵĽڵ�ĵ�����
	pair<map<string, int>::iterator, bool> ret = m.insert(make_pair("8.4", 1));
	cout << "key: " << ret.first->first << " val: " << ret.first->second << " bool: " << ret.second << endl;
	pair<map<string, int>::iterator, bool> ret2 = m.insert(make_pair("8.4", 1));
	cout << "key: " << ret2.first->first << " val: " << ret2.first->second << " bool: " << ret2.second << endl;

	map<string, int>::iterator it = m.insert(m.begin(), make_pair("8.3", 0));
	cout << it->first << " " << it->second << endl;
	map<string, int>::iterator it2 = m.insert(m.begin(), make_pair("8.3", 0));
	cout << it2->first << " " << it2->second << endl;
}

void test5()
{
	int array[] = { 1, 2, 3, 4, 5 };
	set<int> s(array, array + 5);

	set<int>::iterator it = s.find(5);

	if (it != s.end())
		cout << *it << endl;

	cout << s.count(5) << endl;
}

void test6()
{
	map<string, int> m;

	m.insert(make_pair("8.4", 1));

	map<string, int>::iterator it = m.find("8.4");
	if (it != m.end())
		cout << it->first << " " << it->second << endl;

	cout << m.count("8.4") << endl;
}

int main(void)
{
	test6();

	return 0;
}