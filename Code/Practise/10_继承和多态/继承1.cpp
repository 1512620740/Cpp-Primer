#include<iostream>

using namespace std;

/**
 * ����/����:
 *
 */
class Person
{
public:
	void print()
	{
		cout << "age = " << _age << " name =  " << _name << " " << _test << endl;
	}

public:
	int start;

protected:
	int _age = 20;
	string _name = "Shepard";

// ˽�г�Ա�������һ���֣��������಻�ɼ�������ֱ�ӷ��ʣ�
// ��������̳е� print() ���������˽�г�Ա����������� print �������ǿ��Է������˽�г�Ա��
private:
	int _test = 1;
};

/**
 * ����/������: 
 * 
 */
class Student : public Person
{};

class Empty
{};

void test1()
{
	Student s;
	s.print();
	
	// �յ�����Ĵ�С�͸�����ͬ������Ĵ�СΪ 1
	cout << sizeof(Person) << endl;
	cout << sizeof(Student) << endl;
	cout << sizeof(Empty) << endl;
}

class Student2 : public Person
{
public:
	void setAge(int age)
	{
		_age = age;
	}

public:
	int id = 1234;
};

/**
 * ��Ƭ
 */
void test2()
{
	Person p;
	Student2 s;

	// ��Ƭ�������������һ���֣����壩�и�����
	// ��Ƭ������ʽ����ת�����ǰ�ȫ��
	p = s;
	Person& rp = s;
	Person* pp = &s;

	// s = p; // ����������ø����������ֵ
	// ����ǿת�������ͣ�������������ȫ�����ܻ����Խ��
	// ָ������;����ܷ��ʵ��ڴ��С��
	// ��Ϊ Student2 ���ʹ�С�����丸�࣬���� Student2* �ܷ��ʵ��ڴ����
	// ָ���� Student2 ���ͣ�ps ʵ��ָ����� Person ���Ͷ���
	Student2& rs = (Student2&)p;
	Student2* ps = (Student2*)&p;
	
	cout << rs.id << " " << ps->id << endl; // -858993460 -858993460
	
	// ����д�ǰ�ȫ�ģ�ָ���� Student2 ���ͣ�ps ʵ��ָ���Ҳ�� Student2 ���͵Ķ���
	Student2& rs2 = (Student2&)rp;
	Student2* ps2 = (Student2*)pp;

	cout << rs2.id << " " << ps2->id << endl; // 	1234 1234

}

void test2p()
{
	Person p;
	Student2 s;

	Student2* pp = (Student2*)&p;
	
	// pp ��ָ�� Person ���͵�ָ��
	// start �� Person ���еĵ�һ����Ա�������������ĵ�ַ����Person ���Ͷ��� p ���׵�ַ
	// �� Person ������׵�ַ��ȥ pp->id �ĵ�ַ�����ǾͿ���֪�� pp->id ����� p �׵�ַ��ƫ����
	cout << &pp->start - &pp->id << endl;

	Student2* ps = &s;
	
	// ps ����ָ�� Student ���͵�ָ��
	// ���������Կ��� ��Ա id ����� Student ���Ͷ��� s �׵�ַ��ƫ����
	cout << &ps->start - &ps->id << endl;

	// ������� 10
	// ��˵�����Զ���ĳ�Ա����ʵ�����ǿ�ָ��ƫ������ɵ�
}

void print()
{
	cout << "global" << endl;
}

/**
 *	���������������������������ͬ���ĳ�Ա
 *	�����ͽ������Լ�����ĳ�Ա��ʹ�� ����::��Ա ���ʸ����Ա
 *	
 *	��������/���� �� ��������
 *	��ͬ��������û�����صĸ���
 *	
 *	ע�������ض����Ǹ��ǣ����Ҫ���ø����ȫ�ֵ�ͬ��������Ҫ���⴦������ C �����ܵ��þ͵��ã�
 *	����ȫ�ֺ��� ::������
 */
class Student3 : public Person
{
public:
	void print()
	{
		// ���������и����ͬ����Ա��������ͽ���
		cout << _age << endl; // 26
		// Ҫ��������е� _age
		cout << Person::_age << endl;
		
		// ���õ��� Student3 �ĳ�Ա�������Ӷ������ݹ�
		// print();

		// ���ʸ����ͬ������
		Person::print();

		// ����ȫ�ֵ� print ����
		::print();
	}
	

protected:
	int _age = 26;
};

void test3()
{
	Person p;
	Student3 s;
	
	cout << sizeof(p) << " " << sizeof(s) << endl;// 36 40

	s.print();
}

/**
 * ��Ա����
 */
class Person2
{
public:
	Person2(string name = "Shepard", int age = 20)
		:_name(name)
		,_age(age)
	{
		cout << "Person2(string = , int = )" << endl;
	}

	Person2(string name, int age, int nouse)
		:_name(name)
		,_age(age)
	{
		cout << "Person2(string, int)" << endl;
	}

	Person2(const Person2& p)
		:_name(p._name)
		,_age(p._age)
	{
		cout << "Person2(const Person2& p)" << endl;
	}

	Person2& operator=(const Person2& p)
	{
		if (this != &p)
		{
			_name = p._name;
			_age = p._age;
			cout << "Person2& operator=(const Person2& p)" << endl;
		}
		return *this;
	}

	~Person2()
	{
		cout << "~Person2()" << endl;
	}

protected:
	string _name;
	int _age;
};

class Student4 : public Person2
{
	// ���û����ʾ�ĵ��ø���Ĺ��캯�����������Զ����ø����Ĭ�Ϲ��캯��,��ɸ����Ա�ĳ�ʼ��
	// �������û��Ĭ�Ϲ��캯����������ʾ�ĵ���
public:
	// �Զ����Ĭ�Ϲ���Ҳ����ø����Ĭ�Ϲ��죨��ʼ���б���
	// �ȹ��츸�࣬Ȼ���ٹ�������

	// ���ø����Ĭ�Ϲ���
	Student4(int id = 1234)
		:_id(id)
	{
		cout << "Student4(id = )" << endl;
		//cout << _name << " " << _age << " " << _id << endl;
	}

	// ָ�����ø���Ĺ��캯��
	// �ȹ��츸��Ȼ���ٳ�ʼ������ĳ�Ա
	Student4(int id, int nouse)
		:Person2("Samantha", 26)
		,_id(id)
	{
		cout << "Student4(int, int)" << endl;
		//cout << _name << " " << _age << " " << _id << endl;
	}

	// 1.�������Զ����ɵĿ���������ø���Ŀ�������
	// 2.��ʾ����Ŀ���������ø����Ĭ�Ϲ���
	// 3.���ø��࿽�����������Ƭ����
	Student4(const Student4& s)
		:Person2(s) // ��Ƭ
		// Ҳ���� Person(s._name, s,_age) ���ø����Ĭ�Ϲ���
		,_id(s._id)
	{
		cout << "Student4(const Student4& s)" << endl;
	}
	
	// 1.�������Զ����ɵĸ�ֵ��������غ������ø���ĸ�ֵ��������غ���
	// 2.��ʾ����ĸ�ֵ��������غ���������ø���ģ���Ϊͬ��/��Ա����
	//   ��Ҫ��ʾ���ø���ĸ�ֵ��������غ���
	Student4& operator=(const Student4& s)
	{
		if (this != &s)
		{
			Person2::operator=(s);
			_id = s._id;
			cout << "Student4& operator=(const Student4& s)" << endl;
		}
		return *this;
	}
	
	// �Զ����ø�������
	// �ȵ�����������Ȼ����ø�������
	~Student4()
	{
		cout << "~Student4()" << endl;
		// ~Person2(); // ����ֱ�ӵ�����������Ϊ�ײ�����͸���ĺ�������ͬ�����ɺ�������
		//Person2::~Person2(); // �����Ƿ���ʾ���ø��������������������Զ�����һ�θ�������
		// ��Ҫ��ʾ�ĵ��ø������������ܻ������Դ�Ķ����ͷ�
	}
	
protected:
	int _id;
};

void test4()
{
	//Student4 s(4321, 0);
	Student4 s2;
	//Student4 copy(s2);

	//s = s2;

}

/**
 * ���μ̳к���������̳�
 * �����������ָ��
 *
 */

int main(void)
{
	test4();
	

	return 0;
}