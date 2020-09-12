#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include"String.h"

int String::num_strings = 0;

String::String()
{
	len = 1;
	str = new char[len];
	/*
	 *	str = new char[1] Ϊ�Ͳ�д�� str = new char
	 *  ���Ŀ����Ϊ���� new[] �� delete[] ƥ��
	 *  �����������У�����ʹ�õ��� delete[] �������������ʽ�᲻ƥ��
	 */
	str[0] = '\0';
	// ����Ĵ���Ҳ���Ը�Ϊ str = 0; // sets str to null pointer
	num_strings++;

	//std::cout << "String() invoked: " << num_strings << " "
	//	<< str << std::endl;
}

String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;

	//std::cout << "String(const char* s) invoked: " << num_strings << " "
	//	<< str << std::endl;
}

String::String(const String& s)
{
	len = s.len;
	num_strings++;
	str = new char[len + 1];
	std::strcpy(str, s.str);

	//std::cout << "String(const String& s) invoked: " << num_strings << " "
	//	<< str << std::endl;
}

String::~String()
{
	if (str)
	{
		len = 0;
		num_strings--;
		delete[] str;

		//std::cout << "~String() invoked: " << num_strings << " "
		//	<< std::endl;
	}
}

String& String::operator=(const String& s)
{
	if (&s != this)
	{
		delete[] str;
		len = s.len;
		str = new char[len + 1];
		std::strcpy(str, s.str);
	/*	std::cout << "operator=(const String& s) invoked: " << num_strings << " "
			<< std::endl;*/
	}
	return *this;
}

String& String::operator=(const char* s)
{
	delete[] str;
	
	len = std::strlen(s);
	str = new char[len + 1];
	str = std::strcpy(str, s);

	return *this;
}

bool operator<(const String& s1, const String& s2)
{
	// �����һ���ַ������ַ��ڵڶ����ַ������ַ�֮ǰ�����ظ�ֵ
	// ��ȣ����� 0
	return (std::strcmp(s1.str, s2.str) < 0);
}

bool operator>(const String& s1, const String& s2)
{
	return (std::strcmp(s1.str, s2.str) > 0);
}

bool operator==(const String& s1, const String& s2)
{
	return (std::strcmp(s1.str, s2.str) == 0);
}

char& String::operator[](int n)
{
	return str[n];
}

/*
 * const String s("Shepard");
 * cout << s[1]; // Ҫȷ�� s[1] �����ı� 
 */
const char& String::operator[](int n) const
{
	return str[n];
}


std::ostream& operator<<(std::ostream& os, const String& s)
{
	os << s.str;
	return os;
}

/*
 * if�жϣ������Ϊĳ��ԭ�򣨵����ļ�β�����߶�ȡ���˿��У���������ʧ�ܣ�is ��ֵΪ��Ϊ false
 * while ѭ������ȡ���������
 */
std::istream& operator>>(std::istream& is, String& s)
{
	char buffer[String::CINLIM];
	is.get(buffer, String::CINLIM);
	if (is)
		s = buffer;
	while (is && is.get() != '\n')
		;
	return is;
}
