#include<iostream>
#include<string>
#include<string.h>
#include "String.h"

using namespace std;


// �����Ƕ� STL �е� string ����ʵ�ֵ� String �����ĶԱ�
// �����û�� cout ��ʽ������������ڵ����жԱ��������ʵ��������
// ��Ҳ�Ƽ����õ���ȥ�۲⣬��Ϊʮ�ַ��㣬�Ͼ����� VS ������
int main(void)
{
	string str;
	String Str;

	cout << "========            �޲ι���           ========" << endl;

	cout << "========          c string ����        ========" << endl;
	string str1("123");
	String Str1("123");

	cout << "========            ��������           ========" << endl;
	string str2(str1);
	String Str2(Str1);

	cout << "========        ��ֵ���������         ========" << endl;

	str = str2;
	Str = Str2;

	cout << "========             ������            ========" << endl;

	for (auto& c : str1)
	{
		c = 'a';
		cout << c << " ";
	}
	cout << endl;

	for (const auto& c : str1)
	{
		cout << c << " ";
	}
	cout << endl;

	for (auto& c : Str1)
	{
		c = 'a';
		cout << c << " ";
	}
	cout << endl;

	for (const auto& c : Str1)
	{
		cout << c << " ";
	}
	cout << endl;

	cout << "========        resize��reserve       ========" << endl;

	str1.resize(5);
	str1.resize(30, 'x');
	str1.reserve(50);

	Str1.resize(5);
	Str1.resize(30, 'x');
	Str1.reserve(50);

	getchar();
	return 0;

}

// cout << "======== �޲ι��� ========" << endl;