#pragma once

#pragma warning(disable : 4996)

#include<cstring>
#include<iostream>



using namespace std;

class String
{
public:
	// �޲ι���
	String()
		:_str(new char[16])
		, _size(0)
		, _capacity(0)
	{
		_str[_size] = '\0';
		// ע�⣺_size �� _capacity �Ĵ�С��������β����ֹ�ַ�
		_capacity = 15;
	}

	// c ����ַ�������
	String(const char* s)
	{
		_size = strlen(s);
		_capacity = _size;
		_str = new char[_capacity];
		strcpy(_str, s);
	}


	/*��������
   String(const String& str)
	   :_str(new char[str._capacity + 1])
	   ,_size(str._size)
	   ,_capacity(str._capacity)
   {
	   strcpy(_str, str._str);
   }*/

   // ���������ִ�д�������ڴ��븴��
	String(const String& str)
		:_str(nullptr)
		// һ��Ҫ��ʼ��Ϊ�գ���Ϊ������ tmp._str ָ���� this->_str ָ��Ŀռ�
		// ��� this->_str û�г�ʼ������ʱ���� tmp ���ͷ�ʱ������������ͷ� tmp._str
		// Ҳ���Ǳ����ģ�this->_str�� ָ��Ŀռ䣬������ռ�������ģ���˻�����δ������Ϊ
	{
		// ���� c ����캯��
		String tmp(str._str);
		Swap(tmp);
		// ����������õ� swap(*this, tmp) �����������ã�
		// ������һ����ʱ�� String ���͵ı�����Ȼ�󻹻������������ͼ�ĸ�ֵ���Ƚϵ�Ч

	}

	void Swap(String& tmp)
	{
		swap(_str, tmp._str);
		swap(_size, tmp._size);
		swap(_capacity, tmp._capacity);
	}
	//void Swap(String& str)
	//{
	//	//��������
	//	String tmp = str;
	//	//��ֵ�����
	//	str = *this;
	//	//��ֵ�����
	//	*this = tmp;
	//}

	// ��ֵ��������غ���
	// ����ֵ���ݣ����������ı䲻Ӱ�챾����ֵ
	String& operator=(String str)
	{
		Swap(str);
		// ����Ҫ���ÿ������죬��Ϊʵ�δ����β�ʱ���ǿ�������
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_size = 0;
			_capacity = 0;
		}
	}


	const char* c_str() const
	{
		return _str;
	}

	typedef char* iterator;
	typedef const char* const_iterator;

	iterator begin()
	{
		return _str;
	}

	iterator end()
	{
		return _str + _size;
	}

	const_iterator cbegin() const
	{
		return _str;
	}

	const_iterator cend() const
	{
		return _str + _size;
	}

	size_t size() const
	{
		return _size;
	}

	void resize(size_t n, char ch = '\0')
	{
		if (n == _size)
			return;

		if (n > _capacity)
		{
			reserve(n);
		}
		if (n > _size)
		{
			memset(_str + _size, ch, n - _size);
		}

		_size = n;
		_str[_size] = '\0';
	}

	void reserve(size_t n = 0)
	{
		if (n <= _capacity)
			return;
		
		// ���¿ռ�
		char* tmp = new char[n + 1];
		// Ų������
		strcpy(tmp, _str);
		// �ͷžɿռ�
		delete[] _str;
		
		// ����
		_str = tmp;
		_capacity = n;
	}



// �۲� string �����ĳ�Ա������������Ҫ������
private:
	char* _str;
	size_t _size;
	size_t _capacity;
};
