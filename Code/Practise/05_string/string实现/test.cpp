#include<iostream>
#include<string>
#include<string.h>
#include "String.h"

using namespace std;


void print(string& s)
{
  cout << s.c_str() << " " << s.size() << " " << s.capacity() << endl;
}

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

  print(str1);
  

	Str1.resize(5);
	Str1.resize(30, 'x');
	Str1.reserve(50);

  Str1.print();

	cout << "========            insert            ========" << endl;
  string str3("123");
  str3.insert(0, "0");
  str3.insert(4, "456789");
  str3.insert(5, 5, 'x');

  print(str3);

  String Str3("123");
  Str3.insert(0, "0");
  Str3.insert(4, "456789");
  Str3.insert(5, 5, 'x');
  
  Str3.print();

	cout << "======= append,+=,push_back,pop_back ========" << endl;
  string str4;
  str4.push_back('a');
  str4.append("bc");
  str4 += str4;
  str4.pop_back();

  print(str4);

  String Str4;
  Str4.push_back('a');
  Str4.append("bc");
  Str4 += Str4;
  Str4.pop_back();

  Str4.print();

	cout << "=======           erase             ========" << endl;
  string str5("12345"); 
  str5.erase(1, 1);
  print(str5);
  str5.erase(1);
  print(str5);

  
  String Str5("12345"); 
  Str5.erase(1, 1);
  Str5.print();
  Str5.erase(1);
  Str5.print();

	cout << "=======           find              ========" << endl;
  string str6("123123");
  cout << str6.find("123") << " " << str6.find("123", 1) << endl;

  String Str6("123123");
  cout << Str6.find("123") << " " << Str6.find("123", 1) << endl;


	cout << "=======          operator           ========" << endl;
  string str7("123");
  string str8("123");
  string str9("1234");
  string str10 = str7 + str9;
  print(str10);
  cout << (str7 == str8) << endl;
  cout << (str9 > str8) << endl;

  String Str7("123");
  String Str8("123");
  String Str9("1234");
  String Str10 = Str7 + Str9;
  Str10.print();
  cout << (Str7 == Str8) << endl;
  cout << (Str9 > Str8) << endl;

	cout << "=======          operator           ========" << endl;
  string str11("aaa");
  str11.insert(3, 10, '\0');
  cout << str11 << " " << 'o' << endl;
  print(str11);

  String Str11("aaa");
  Str11.insert(3, 10, '\0');
  cout << Str11 << " " << 'o' << endl;
  Str11.print();

	return 0;

}

// cout << "======== �޲ι��� ========" << endl;
