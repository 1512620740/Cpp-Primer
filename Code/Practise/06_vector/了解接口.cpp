#include<iostream>
#include<vector>
#include<string>

using namespace std;

// ����
void test1()
{
	// ���������ǿյ�
	vector<int> v1;
	vector<char> v2;
	vector<string> v3;

	// size Ϊ 10��ֵ���� 5
	vector<int> v4(10, 5);

	string s("0123456789");
	// size Ϊ 10��capacity Ϊ 15 ����һ���ַ���
	string s1(s.begin(), s.end());
	// size��capacity ���� 10�������Ǹ��ַ�����
	vector<char> v5(s.begin(), s.end());

	vector<char> v6(v5);
}

// ����
void test2()
{
	vector<int> v(10, 6);
	vector<int>::iterator vit = v.begin();

	for (auto& i : v)
	{
		cout << i << " ";
		i = 66;
	}
	cout << endl;

	while (vit != v.end())
	{
		cout << *vit << " ";
		*vit = 666;
		vit++;
	}
	cout << endl;

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
		v[i] = 0;
	}
	cout << endl;

	for (auto& i : v)
	{
		cout << i << " ";
	}
	cout << endl;
	
	string s("0123456789");
	vector<char> v2(s.begin(), s.end());
	vector<char>::reverse_iterator rvit = v2.rbegin();

	while(rvit != v2.rend())
	{
		cout << *rvit << " ";
		rvit++;
	}
	cout << endl;
}

template<typename T>
void print(const vector<T>& v)
{
	typename vector<T>::const_iterator cit = v.cbegin();
	// ����ԭ����vector<T>�������;�ûȷ�����ٸ�һ�������������Ͳ�֪���ø�������ʲô�����ˣ�
	// ����typename��ʾ�Ժ���ȷ�����ͣ������Ȳ���
	
	while (cit != v.cend())
	{
		cout << *cit << " ";
		cit++;
	}
	cout << endl;

	typename vector<T>::const_reverse_iterator crit = v.crbegin();

	while (cit != v.cend())
	{
		cout << *crit << " ";
		crit++;
	}
	cout << endl;
}

void test3()
{
	int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	char a1[] = "0123456789";

	vector<int> v(a, a + 10);
	vector<char> v1(a1, a1 + 10);

	string a2[] = { "123", "ooo", "xxx" };
	vector<string> v2(a2, a2 + 3);

	print(v);
	print(v1);
	print(v2);

	// resize ���ȱʡ�ڶ���������Ĭ��ֵ value_type() �������������
	// ָ����� nullptr��int ���� 0�������;��ǵ��ø���Ĺ���

	v.resize(20);
	v1.resize(20);
	v2.resize(20);


}

void test4()
{
	vector<int> v;

	v.at(0);
}

void test5()
{
	vector<int> v(5, 1);
	cout << v.capacity() << endl;
	vector<int>::iterator it = v.begin();
	v.push_back(2);
	cout << v.capacity() << endl;
	// ע��������һ�У����� v �� capacity �����˱仯
	cout << *it << endl; // �������
}

void test6()
{
	vector<int> v(5, 1);
	vector<int>::iterator it = v.begin();
	vector<int>::iterator it2 = it + 2;
	// ɾ���±������ [1, 2]�� pos Ϊ 1
	v.erase(it + 1, it + 3);
	// it ָ���±�Ϊ 0 ��λ�ã��� pos ǰ�����Ե�������Ч
	cout << *it << endl;
	// it2 ָ���±�Ϊ 2 ��λ�ã��� pos ֮�󣬵�����ʧЧ���������
	cout << *it2 << endl;
	
}

void test7()
{
	vector<int> v(5, 1);
	cout << v.capacity() << endl;
	v.reserve(7);
	cout << v.capacity() << endl;
	vector<int>::iterator it = v.begin();
	v.push_back(2);
	cout << v.capacity() << endl;
	cout << *it << endl;
}

void test8()
{
	vector<int> v(5, 1);
	vector<int>::iterator it = v.begin();

	while (it != v.end())
	{
		it = v.erase(it);
	}
}

void test9()
{
	vector<int> v(5, 1);
	vector<int>::iterator it = v.begin();

	it = v.insert(it, 2);
	cout << *it << endl;
}

int main(void)
{
	cout << "test vector" << endl;

	test9();

	return 0;
}

