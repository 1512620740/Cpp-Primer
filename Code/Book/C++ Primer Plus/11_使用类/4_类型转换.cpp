#include<iostream>

using namespace std;

class A
{
private:
	int _a;
public:
	// ���ι��캯��
	A(int a)
	{
		_a = a;
	}

	//operator int() const
	//{
	//	return _a;
	//}

	//operator double() const
	//{
	//	return double(_a);
	//}

	int A_to_int()
	{
		return _a;
	}

	double A_to_double()
	{
		return (double)_a;
	}
};

//void test1()
//{
//	// 3.1 ����ת��Ϊ int ���ͣ�Ȼ����� A(3)
//	A b = 3.1;
//
//	int i = b;		// ok
//	double d = b;	// ok
//	
//	// ���ڶ����ԣ�double �� int ������ת��Ϊ long
//	// long l = b;
//	
//	cout << int(b) << endl;		// ok
//	cout << double(b) << endl;	// ok
//	
//	// ���ڶ����ԣ�b ����ת��Ϊ double �� int
//	// cout << b << endl;
//}

//void test2()
//{
//	A a(3);
//
//	int a = a.A_to_int();
//	double d = a.A_to_double();
//
//	cout << a << endl; // Error!
//}

class B
{
private:
	double _b;
public:
	B(double b)
	{
		cout << "B(double b) " << endl;
		_b = b;
	}
	//operator double() const
	//{
	//	return _b;
	//}

	B operator+(const B& b)
	{
		// �����ι���
		B ret(_b + b._b);
		return ret;
	}

	//B operator+(double d)
	//{
	//	return B(_b + d);
	//}

	double Show()
	{
		return _b;
	}

};

void test3()
{
	B b(3); 
	double d = 3.6;
	
	cout << (d + b) << endl;
}

int main(void)
{
	test3();
}