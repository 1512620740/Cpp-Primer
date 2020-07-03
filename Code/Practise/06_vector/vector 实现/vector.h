#pragma once

#include<iostream>
#include<cstring>

using namespace std;

template<class T>
class Vector
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;

	Vector()
		:_start(nullptr)
		,_finish(nullptr)
		,_eos(nullptr)
	{}

	Vector(const Vector<T>& v) 
		:_start(new T[v.capacity()])
	{
		// ���������ΪʲôҪ�������Կ������ T Ϊ string �������
		for (int i = 0; i < v.size(); i++)
		{
			_start[i] = v[i];
		}
		_finish = _start + v.size();
		_eos = _start + v.capacity();
	}

	Vector<T>& operator=(const Vector<T> v)
	{
		Swap(v);
		return *this;
	}

	void Swap(Vector<T> v)
	{
		swap(_start, v._start);
		swap(_finish, v._finish);
		swap(_eos, v._eos);
	}

	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _eos = nullptr;
		}
	}


	iterator begin()
	{
		return _start;
	}

	const_iterator begin() const
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	const_iterator end() const
	{
		return _finish;
	}

	size_t size() const 
	{
		return _finish - _start;
	}

	size_t capacity() const
	{
		return _eos - _start;
	}

	void push_back(const T& val)
	{
		// 1.�ж��Ƿ���Ҫ����
		if (_finish == _eos)
		{
			int cap = capacity();
			int newCap = (cap == 0) ? 2 : 2 * cap;
			reserve(newCap);
		}
		// 2. ����
		*_finish = val;
		// 3. ����
		_finish++;
	}

	void reserve(size_t n)
	{
		if (n <= capacity())
			return;

		int oldSize = size();

		// ���ռ�
		T* tmp = new T[n];

		// �����ǰ������Ϊ�գ������ɿռ����ݵ��¿ռ�
		if (oldSize != 0)
		{
			// ��� T Ϊ string �࣬memset �Ŀ�����ʽ����ʵ�������
			// memcpy(tmp, _start, sizeof(T) * oldSize);
			for (int i = 0; i < oldSize; i++)
			{
				// ���� T ���͵ĸ�ֵ�����
				tmp[i] = _start[i];
			}
		}

		//3. �ͷ�ԭ�пռ�
		delete[] _start;

		//4. ���¿ռ�ָ�� ����
		_start = tmp;
		_finish = _start + oldSize;
		_eos = _start + n;
	}

	// ������ const T& val = T()
	// ��� T �������ͣ������ T ��Ĭ�Ϲ��칹��һ����������
	// ��� T ���������ͣ�int �ͳ�ʼ��Ϊ 0��ָ���ʼ��Ϊ nullptr �ַ�����ʼ��Ϊ ""
	void resize(size_t n, const T& val = T())
	{
		if (n > capacity())
		{
			reserve(n);
		}

		if (n > size())
		{
			while (_finish != _start + n)
			{
				*_finish++ = val;
			}
		}
		else
		{
			_finish = _start + n;
		}
	}

	iterator insert(iterator pos, const T& val)
	{	
		// ����ĺϷ�����
		if (pos >= _start && pos <= _finish)
		{
			// ���ڵ�����ʧЧ�����⣬����Ӧ���ȼ�¼����λ��
			size_t insertIdx = pos - _start;
			// �ж��Ƿ�����
			if (_finish == _eos)
			{
				size_t newCap = (capacity() == 0) ? 1 : 2 * capacity();
				reserve(newCap);
			}
			// ���µ�����
			pos = _start + insertIdx;
			// �ƶ� [pos, _finish - 1] ��Ԫ�� �� [pos + 1, _finish]
			iterator begin = _finish;
			while (begin > pos)
			{
				*begin = *(begin - 1);
				begin--;
			}
			// ����Ԫ��
			*pos = val;
			// ����
			_finish++;

			return pos;
		}
		else
			return _finish;
	}

	iterator erase(iterator pos)
	{
		if (pos >= _start && pos < _finish)
		{
			// ������Ԫ�ػ�����Ϊ��
			if (capacity() == 0 || size() == 0)
				return _finish;
			iterator begin = pos;
			while (begin < _finish - 1)
			{
				*(begin) = *(begin + 1);
				begin++;
			}
			_finish--;
			return pos;
		}
		else
			return _finish;
	}

	T& operator[](size_t n)
	{
		return *(_start + n);
	}

	const T& operator[](size_t n) const 
	{
		return *(_start + n);
	}

	void printVector()
	{
		for (int i = 0; i < size(); i++)
		{
			cout << *(_start + i) << " ";
		}
		cout << endl;
	}
	


private:
	T* _start;
	T* _finish;
	T* _eos; // end_of_storage
};

template<class T>
void printVector(const Vector<T>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	for (const auto& i : v)
	{
		cout << i << " ";
	}
	cout << endl;

	// typename ��ʾ��ԭ����vector<T>�������;�ûȷ�����ٸ�һ�������������Ͳ�֪���ø�������ʲô�����ˣ�
	// ����typename��ʾ�Ժ���ȷ�����ͣ������Ȳ���
	typename Vector<T>::iterator it = v.begin();

	for (; it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
