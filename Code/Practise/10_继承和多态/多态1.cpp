//#include<iostream>
//
//using namespace std;
//
//class Person
//{
//public:
//	virtual void print()
//	{
//		cout << "���ࣺ" << "age = " << _age << " name =  " << _name << " " << _test << endl;
//	}
//
//protected:
//	int _age = 20;
//	string _name = "Shepard";
//
//private:
//	int _test = 1;
//};
//
//class Student : public Person
//{
//	virtual void print()
//	{
//		cout << "ѧ����" << "age = " << _age << " name =  " << _name << " " <<  endl;
//	}
//};
//
//void print(Person& p)
//{
//	p.print();
//}
//
///**
// *	��̬������
// *		1.�̳�
// *		2.������д�麯��
// *		3.�����麯�������ͱ����� ָ��/���ã����� ָ��/���� ָ�����������Ƭ��
// */
//void test1()
//{
//	Person p;
//	Student s;
//
//	print(p);
//	print(s);
//}
//
///**
// *	��д�����麯�����򣺺�������ֵ������������������ȫһ��
// *	���⣺1.Э�亯����д 2.����������д
// *	
// *	��������麯����д���Ϲ淶������ɺ�������
// *	���಻д virtual �ؼ���Ҳ���Թ�����д
// */
//
//// 1. Э�䣺����ֵ���Բ�ͬ���������ǹ��� ���ӹ�ϵ ��ָ��/����
//class A
//{
//public:
//	int _a;
//};
//
//class B : public A
//{
//
//};
//
//class Person2
//{
//public:
//	// �������� ok
//	//virtual A& print()
//	//{
//	//	cout << "���ࣺ" << "age = " << _age << " name =  " << _name << " " << _test << endl;
//	//	A a;
//	//	return a; 
//	//}
//	
//	// ����ָ�� ok
//	//virtual A* print()
//	//{
//	//	cout << "���ࣺ" << "age = " << _age << " name =  " << _name << " " << _test << endl;
//	//	A a;
//	//	return &a;
//	//}
//
//	// ע�⸸�ุ�෵�ظ��ࣨPerson2 �� print ���� A�������෵������
//	// Ҫô���������ã�Ҫô������ָ�룬���ǲ��ܷ���һ����ͨ����
//
//protected:
//	int _age = 20;
//	string _name = "Shepard";
//
//private:
//	int _test = 1;
//};
//
//class Student2 : public Person2
//{
//	//virtual B& print()
//	//{
//	//	cout << "ѧ����" << "age = " << _age << " name =  " << _name << " " << endl;
//	//	B b;
//	//	return b;
//	//}
//
//	virtual B* print()
//	{
//		cout << "ѧ����" << "age = " << _age << " name =  " << _name << " " << endl;
//		B b;
//		return &b;
//	}
//
//};
//void test2()
//{
//	Person2 p;
//	Student2 s;
//}
//
//// 2. ��������
//class Person3
//{
//public:
//	Person3()
//	{
//		cout << "Person3()" << endl;
//	}
//
//	void print()
//	{
//		cout << "���ࣺ" << "age = " << _age << " name =  " << _name << " " << _test << endl;
//	}
//
//	//~Person3()
//	//{
//	//	cout << "~Person3()" << endl;
//	//}
//
//	virtual ~Person3()
//	{
//		cout << "~Person3()" << endl;
//	}
//
//protected:
//	int _age = 20;
//	string _name = "Shepard";
//
//private:
//	int _test = 1;
//};
//
//class Student3 : public Person3
//{
//public:
//	Student3()
//	{
//		cout << "Student3()" << endl;
//	}
//
//	void print()
//	{
//		cout << "ѧ����" << "age = " << _age << " name =  " << _name << " " << endl;
//	}
//
//	//~Student3()
//	//{
//	//	cout << "~Student3()" << endl;
//	//}
//
//	virtual ~Student3()
//	{
//		cout << "~Student3()" << endl;
//	}
//};
//
//void test3()
//{
//	Person3* p = new Person3;
//	Student3* s = new Student3;
//
//	delete p;
//	delete s;
//	
//	/*
//	�������Σ���������
//	 Person3()
//	 Person3()
//	 Student3()
//	 ~Person3()
//	 ~Student3()
//	 ~Person3()
//	*/
//	
//	Person3* p2 = new Person3;
//	Person3* s2 = new Student3;
//
//	delete p2;
//	delete s2;
//	/*
//	�������Σ�ֻ����������
//	Person3()
//	Person3()
//	Student3()
//	~Person3()
//	~Person3()
//	*/
//
//	// ������Ϊ s2 ָ���� Person3 ���ͣ�delete ʱ����� Person3 �������������ǵ��� Student3 ������
//	// ��ʱ�����Ǿ���Ҫ���麯����д������������ɶ�̬
//}
//
//class AA
//{
//public:
//	 virtual void print()
//	{
//		cout << "A" << endl;
//	}
//};
//
//class BB : public AA
//{
//public:
//	void print()
//	{
//		cout << "B" << endl;
//	}
//};
//
//class CC : public BB
//{
//public:
//	void print()
//	{
//		cout << "C" << endl;
//	}
//};
//
//void print(AA& r)
//{
//	r.print();
//}
//
//void print2(BB& r)
//{
//	r.print();
//}
//
//void test4()
//{
//	AA a;
//	BB b;
//	CC c;
//
//	print(a);
//	print(b);
//	print2(c);
//}
//
//int main(void)
//{
//	test4();
//
//	return 0;
//}
//
//
//
//
//
