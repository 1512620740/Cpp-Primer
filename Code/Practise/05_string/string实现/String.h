#pragma once

#include<cstring>
#include<iostream>

using namespace std;

class String
{
public:

	typedef char* iterator;
	typedef const char* const_iterator;
  static const size_t npos;

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

    // n ���� capacity ��Ҫ��������ռ�
		if (n > _capacity)
		{
			reserve(n);
		}
    // n ���� _size С�� _capacity 
		if (n > _size)
		{
			memset(_str + _size, ch, n - _size);
		}

    // ����
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

  
  char& operator[](size_t pos)
  {
    if(pos <= _size)
    {
      return *(_str + pos);
    }
  }

  const char& operator[](size_t pos) const 
  {
    if(pos <= _size)
    {
      return *(_str + pos);
    }
  }

  String& insert(size_t pos, const char* s)
  {
    if(pos <= _size && s != nullptr)
    {
      size_t len = strlen(s);
      
      if(_size + len > _capacity)
        reserve(_size + len);

      // �ƶ� [pos, _size] ��Ԫ�ص� [pos + len, _size + len]
      size_t end = _size + len; // '\0' ҲӦ���ƶ�
      
      // ��Ϊ end �� size_t��unsigned int�� ���ͣ������ʽ == 0��end �ٴ��Լ�����С�� 0���������������ѭ��
      // ����취�������жϱ��ʽ�в�Ҫ���� = ��
      while(end > pos + len - 1)
      {
        _str[end] = _str[end - len];
        end--;
      }

      for(size_t i = 0; i < len; i++)
      {
        _str[pos + i] = s[i];
      }
      
      _size += len;
    }
    return *this;
  }
  

  String& insert(size_t pos, size_t n, const char& ch)
  {
    if(pos <= _size && n > 0)
    {
      if(_size + n > _capacity)
        reserve(_size + n);
      size_t end = _size + n;
      while(end > pos + n - 1)
      {
        _str[end] = _str[end - n];
        end--;
      }

      for(size_t i = 0; i < n; i++)
      {
        _str[pos + i] = ch;
      }

      _size += n;
    }
    return *this;
  }


  String& erase(size_t pos = 0, size_t len = npos)
  {
    if(pos > _size)
      return *this;

    // ɾ�� pos ���ַ�������������
    // pos �����ַ��� [0, pos - 1] ������
    // len �����ַ��� [pos, pos + len)
    // ֱ�ӽ� pos λ�õ�Ԫ����Ϊ '\0' ����
    // ���ȱʡ len ���� erase��len ������ size_t �����ֵ
    // �����ʱ���� pos �ͻ���һ���Ƚ�С��ֵ���� pos �Ĵ�С
    if(pos + len >= _size || len == npos)
    {
      _str[pos] = '\0';
      _size = pos;
    }
    else
    {
      // [pos + len, _size] �ƶ��� [pos, ]
      size_t begin = pos + len;
      size_t cur = pos;
      while(begin < _size + 1)
      {
        _str[cur++] = _str[begin++];
      }

      _size -= len;
    }

    return *this;
  }


  String& operator+=(const String& str)
  {
    insert(_size, str._str);
    return *this;
  }

  String& operator+=(const char* str)
  {
    insert(_size, str);
    return *this;
  }

  String& append(const String& str)
  {
    insert(_size, str._str);
    return *this;
  }

  String& append(const char* str)
  {
    insert(_size, str);
    return *this;
  }

  void push_back(char ch)
  {
    insert(_size, 1, ch);
  }

  void pop_back()
  {
    if(_size != 0)
    {
      _str[--_size] = '\0';
    }
  }


  size_t find(const char* s, size_t pos = 0)
  {
    char* tar_str = strstr(_str + pos, s);

    if(tar_str)
      // �ҵ����ִ���λ��ƫ�Ƶ��ڣ��ִ����׵�ַ��ȥ�����ַ������׵�ַ��ע�ⲻҪ����˳��
      return tar_str - _str; 
    else 
      return npos;
  }

  void print(){
    cout << _str << " " << _size << " " << _capacity << endl;
  }



// �۲� string �����ĳ�Ա������������Ҫ������
private:
	char* _str;
	size_t _size;
	size_t _capacity;
};


const size_t String::npos = -1;

String operator+(const String& left, const String& right)
{
  String tmp(left);
  tmp += right;
  return tmp;
}

String operator+(const String& left, const char* s)
{
  String tmp(left);
  tmp += s;
  return tmp;
}

String operator+(const char* s, const String& right)
{
  String tmp(right);
  tmp += s;
  return tmp;
}

bool operator==(const String& left, const String& right)
{
  const char* sl = left.c_str();
  const char* rl = right.c_str();
  
  return strcmp(sl, rl) == 0;
  
}
bool operator>(const String& left, const String& right)
{
  const char* sl = left.c_str();
  const char* rl = right.c_str();

  return strcmp(sl, rl) > 0;
}

ostream& operator<<(ostream& _cout, const String& s)
{
  _cout << s.c_str(); 
  return _cout;
}


