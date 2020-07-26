#include<iostream>

using namespace std;

class A
{
public:
	// final: ����ĺ������ܱ���д������ʵ�ּ̳У�����ֱ���ã�
	virtual void print() final
	{
		cout << "A: " << _a << endl;
	}

	virtual void drive()
	{
		cout << "A ����"<< endl;
	}

private:
	int _a = 10;
};

class B : public A
{
public:
	// override: ����Ҫ������д���������ṩ���,�ӿڼ̳У�������Ҫ�Լ�ʵ�֣�
	void drive() override
	{
		cout << "B ����" << endl;
	}
};

void test1()
{
	A* pa = new B;
	pa->drive();
}

// �����ࣺ�������麯������
class A2
{
public:
	// ���麯��
	virtual void print() = 0;
};

void test2()
{
	// �����಻��ʵ����������
	// A2 a;
}

class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}

	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}

	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}

private:
	int _b = 1;
};

class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}

	virtual void Func3()
	{
		cout << "Derive::Func3()" << endl;
	}

	virtual void Func4()
	{
		cout << "Derive::Func4()" << endl;
	}

private:
	int _d = 2;
};

typedef void (*VFPTR)();

void PrintVTable(VFPTR* VTable)
{
	cout << "����ַ��" << VTable << endl;
	for (int i = 0; VTable[i] != nullptr; i++)
	{
		cout << "�� " << i + 1 << " ���麯����ַ��" << VTable[i] << endl;
		VFPTR f = VTable[i];
		f();
	}
}

void test3()
{
	Base b;
	Derive d;
	
	VFPTR* VTable = (VFPTR*)(*(int*)&b);
	PrintVTable(VTable);

	VTable = (VFPTR*)(*(int*)&d);
	PrintVTable(VTable);

	// ����������ӡ�������ر�࣬����һ�½�����������±������У�gcc �Ǿ����������������ģ����� windows
}

class Base1
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}

	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}

private:
	int _b = 1;
};

class Base2
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}

	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}

private:
	int _b = 1;
};

class Derive2 : public Base1, public Base2
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}

	virtual void Func3()
	{
		cout << "Derive::Func3()" << endl;
	}


private:
	int _d = 2;
};

void test4()
{
	Derive2 d;
	
	// Base1 �����ָ��
	VFPTR* VTable = (VFPTR*)*(int*)&d;
	PrintVTable(VTable);

	// Base2 �����ָ��
	VTable = (VFPTR*)*(int*)((char*)&d + sizeof(Base1));
	PrintVTable(VTable);
}

int main(void)
{
	test4();

	return 0;
}