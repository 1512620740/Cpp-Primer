#include<iostream>
#include<string>

using namespace std;

// ����
void test1()
{
/*
default (1)
string();

copy (2)
string (const string& str);

substring (3)
string (const string& str, size_t pos, size_t len = npos);

from c-string (4)
string (const char* s);

from sequence (5)
string (const char* s, size_t n);

fill (6)
string (size_t n, char c);
*/

	string s1;

	string s2("123");
	string s3 = "123"; // ���ι��캯��

	string s4("0123456789", 5); // "01234"

	string s5(s4);

	// ����Ϊ 2 ȡ 2 ���ַ�
	string s6(s4, 2, 2); // "23"

	string s7(10, 'a'); // ʮ�� 'a'
}

// ��ֵ����
void test2() 
{
	/*
string (1)
string& operator= (const string& str);
c-string (2)
string& operator= (const char* s);
character (3)
string& operator= (char c);
	*/
	
	string s = "123";
	string s2 = "bbb";

	s = "aaa";
	s = s2;
	s = 'a';
}

// ������
void test3()
{
	string str("0123456789");
	
	// �ɶ���д������
	// iterator
	// begin ָ���ַ�����һ��Ԫ��
	// end ָ�����һ��Ԫ�ص���һ��
	// [begin(), end()) ����ҿ�
	for (string::iterator it = str.begin(); it != str.end(); it++)
	{
		cout << *it << endl;
		// *it = ' ';
	}

	// ���������
	// reverse_iterator
	// [rend(), rbegin()) ����ҿ�
	// rbegin() ָ�����һ��Ԫ�ص���һ��λ�á��Ƚ�����ǰһ��Ԫ�أ���++
	for(string::reverse_iterator it = str.rbegin(); it != str.rend(); it++)
		cout << *it << endl;

	// ֻ��������
	// const_iterator

	for (string::const_iterator cit = str.cbegin(); cit != str.cend(); cit++)
	{
		// *cit = ' '; // error �����޸�
	}

	// ֻ�����������
	// string::const_reverse_iterator
	// ����ʹ�� auto
	for (auto crit = str.crbegin(); crit != str.crend(); crit++)
		;
}

void printString(const string& str)
{
	// const ���͵Ķ���ֻ�ܵ��� const �ӿ�
	string::const_iterator cit = str.cbegin();
}

// Capacity
void test4()
{
	string str("0123456789");

	// size/lenth: ������Ч�ַ�����
	cout << str.size() << endl;
	cout << str.length() << endl;
	
	// capacity ���Դ�ŵ������Ч�ַ�����
	cout << str.capacity() << endl;
	
	// max_size: Returns the maximum length the string can reach.
	cout << str.max_size() << endl;
	
	// clear: Erases the contents of the string, which becomes an empty string
	// str.clear();
	

	// resize:Resizes the string to a length of n characters. 
	// void resize (size_t n); 
	// If n is smaller than the current string length, the current value is shortened to its first n character, removing the characters beyond the nth.
	// void resize(size_t n, char c);
	// If n is greater than the current string length, the current content is extended by inserting at the end as many characters as needed to reach a size of n. If c is specified, the new elements are initialized as copies of c, otherwise, they are value-initialized characters (null characters).
	
	// n > size, size ���ӣ�
	// ��� size > capacity, ���ݣ����� realloc��
	// ��� size < capacity, ֻ�޸� size 
	// ����ռ��� �ڶ���������ʾ���ַ���������ȱʡ�ڶ����������� NUL��ASCII Ϊ 0�����
	str.resize(str.size() + 10, 'a');
	cout << str << endl;
	cout << str.size() << endl;
	cout << str.capacity() << endl;

	// n < size ��ֻ�޸� size���ض��ַ���
	str.resize(str.size() - 10);
	cout << str << endl;
	cout << str.size() << endl;
	cout << str.capacity() << endl;


	// reserve 
	// void reserve (size_t n = 0)
	// PJ �� string ��һ������ 2 ����֮�� 1.5 ����

	cout << str << endl;
	cout << str.size() << endl;
	cout << str.capacity() << endl;

	str.reserve(40);
	cout << str << endl;
	cout << str.size() << endl;
	cout << str.capacity() << endl;
	
	str.reserve(5);
	cout << str << endl;
	cout << str.size() << endl;
	cout << str.capacity() << endl;

	// Note that the resulting string capacity may be equal or greater than n.

	// Shrink to fit: Requests the string to reduce its capacity to fit its size.
	// void shrink_to_fit()
	// ��� capacity Զ���� size ���Լ�С�ռ䣬�����˷�
	cout << "=========================" << endl;
	str.shrink_to_fit();
	cout << str.size() << endl;
	cout << str.capacity() << endl;

	// empty
	// bool empty() const;
	cout << str.empty() << endl;	
}

int main(void)
{
	//test3();
	test4();
}