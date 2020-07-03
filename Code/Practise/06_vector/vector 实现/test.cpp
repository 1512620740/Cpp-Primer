#include<iostream>
#include<vector>
#include<string>
#include"vector.h"

using namespace std;



void test1()
{
	Vector<int> V;

	V.push_back(1);
	V.push_back(2);
	V.push_back(3);
	cout << V.capacity() << endl;



	Vector<string> V1;

	V1.push_back("111");
	V1.push_back("222");
	V1.push_back("3333");

	// printVector(V);
}

void test2()
{
	Vector<int> V;

	V.resize(2);
	V.resize(5, 1);
	V.resize(3);
	V.printVector();

	Vector<string> V1;

	V1.resize(2);
	V1.resize(5, "123");
	V1.resize(3);
	V1.printVector();
}

void test3()
{
	Vector<int> V;

	V.insert(V.begin(), 5);
	V.insert(V.end(), 3);
	cout << *V.insert(V.end() - 1, 4) << endl;;
	V.printVector();

	Vector<string> V1;

	V1.insert(V1.begin(), "ooo");
	V1.insert(V1.end(), "xxx");
	V1.insert(V1.end() - 1, "---");
	V1.printVector();

	cout << "==================================" << endl;
	
	// ������ erase �ķ���ֵ֮ǰ���жϷ���ֵ�� end() �Ƿ����

	Vector<int>::iterator iit;
	if ((iit = V.erase(V.begin())) != V.end())
		cout << *iit << endl;
	V.erase(V.end() - 1);
	V.printVector();

	Vector<string>::iterator sit;
	if ((sit = V1.erase(V1.begin())) != V1.end())
		cout << *sit << endl;
	V1.erase(V1.end() - 1);
	V1.printVector();
}

void test4()
{
	Vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	
	// v {1, 2, 3, 4, 5, 6, 7}

	Vector<int>::iterator it = v.begin();
	
	// ɾ��������������û�����⣿ 
	while (it != v.end())
	{
		if (*it % 2 != 0)
			it = v.erase(it);
		it++;
	}
	v.printVector();

	// ɾ��ż���أ�
	while (it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		it++;
	}
	v.printVector();

	// ˼��һ��ԭ��
	// ��ʵ��͵�����ʧЧҲ�й�ϵ
	// ɾ����������ȷд����
	while (it != v.end())
	{
		if (*it % 2 != 0)
			it = v.erase(it);
			// ���⣬�����µ�����������Ҳ�ǿ��������������е�
			// �������ǰ���ǵ�������ʧЧ����������˳���洢�ģ����������洢����ô������Ǵ����
		else
			it++;
	}
	v.printVector();	
}

void test5()
{
	Vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);

	Vector<int> v1(v);
	v1.printVector();

	v1.push_back(8);

	v = v1;
	v.printVector();
}

class B
{
private:
	char ch;
};

class A
{
public:
	~A()
	{

	}

	int a;
	B b;
};

void test6()
{
	Vector<string> v;

	v.push_back("aaa");
	v.push_back("bbb");
	v.push_back("ccc");
	
	Vector<string> v2(v);
	v2.printVector();
	v2.push_back("ddd");

	v = v2;
	v.printVector();
}


int main() 
{
	test6();

	return 0;
}

