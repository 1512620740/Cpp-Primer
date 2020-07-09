#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>

using namespace std;

template<class T>
T Add(T& t1, T& t2)
{
	return t1 + t2;
}

/**
 * ����ģ���ػ�
 * const char*& t1 ��� & ���ű���Ҫд��Ҫ��ģ�屣��һ��
 */
template<>
char* Add<char*>(char*& t1, char*& t2)
{
	char* ret = new char[strlen(t1) + strlen(t2) + 1];
	strcpy(ret, t1);
	strcat(ret, t2);
	
	return ret;
}

/**
 * �ػ�д�������鷳�����ǿ���ֱ�Ӷ���һ�� char* ר���� Add ������
 * ��������Ȼ���ȵ��ô˺���
 */
 char* Add(char* t1, char* t2)
 {
 	char* ret = new char[strlen(t1) + strlen(t2) + 1];
 	strcpy(ret, t1);
 	strcat(ret, t2);
 	
 	return ret;
 }

 /**
 * ģ�������
 *   - ������ģ�����
 *      1. ��������������Լ��ַ����ǲ�������Ϊ������ģ������ġ�
 *		2. �����͵�ģ����������ڱ����ھ���ȷ�Ͻ����
 *   - ����ģ�����
 */

 template<class T, size_t N = 10>
 class Array
 {
 private:
	 T _array[N];
 };

 /**
 * ��ģ���ػ�
 * ȫ�ػ�
 * ƫ�ػ�
 */

template<class T1, class T2>
class B
{
public:
	B()
	{
		cout << "<class T1, class T2>" << endl;
	}
};

// ȫ�ػ�
template<>
class B<int, double>
{
public:
	B()
	{
		cout << "<int, double>" << endl;
	}
};

// ƫ�ػ��������ػ�
template<class T1>
class B<T1, double>
{
public:
	B()
	{
		cout << "<T1, double>" << endl;
	}
};

// ƫ�ػ�������ģ��
template<class T1, class T2>
class B<T1&, T2&>
{
public:
	B()
	{
		cout << "<T1&, T2&>" << endl;
	}
};

void test1()
{
	int a = 1, b = 2;
	int rst1 = Add(a, b);
	
	char* p1 = new char[7];
	char* p2 = new char[6];
	strcpy(p1, "Hello ");
	strcpy(p2, "World");
	char* rst2 = Add(p1, p2);
}

void test2()
{
	B<char, string> b1;
	B<int, double> b2;
	B<char, double> b3;
	B<char&, string&> b4;
}

/**
 * ���� ��
 * http://cplusplus.com/reference/ostream/ostream/operator%3C%3C/
 * http://cplusplus.com/reference/ostream/ostream/operator-free/
 */
void test3()
{
	// �������ַ,��Ϊ ostream �е� operator<< û������ C ������
	cout.operator<<("123").operator<<(endl);

	operator<<(cout, "123");
	cout.operator<<(4).operator<<(endl);
	// �ȼ���
	cout << "123" << 4 << endl;
}

#include<fstream>

// ���ļ�
void test4()
{
	ifstream ifs("./text.txt");
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		exit(EXIT_FAILURE);
	}
	
	/**
	 *  �ļ��е������� Hello World������ >> ���ļ��ж�ȡ���� Hello
	 *	>> ���������ַ�ʱ�������ȡ
	 */
	char str1[100];
	ifs >> str1;
	cout << str1 << endl;

	/**
	 *	getline �������Զ�ȡ���С��ڶ��������ƶ�����ȡ���ֽ���
	 *	getline ����������ַ������Ͽ��ַ������ַ����ڶ�����ܵ��ַ�����
	 */
	ifstream ifs2("./text.txt");
	char str2[100];
	// ע�����һ�� ��û�ж��룬��Ϊ���ַ�ռ���� 1 ���ֽ�
	ifs2.getline(str2, 12); 
	cout << str2 << endl;
}

// д�ļ�
void test5()
{
	// ����ļ������ڣ��½�һ���ļ�
	ofstream ofs("read.txt");
	if (!ofs.is_open())
	{
		cout << "ofs �ļ���ʧ��" << endl;
		exit(EXIT_FAILURE);
	}
	ofs << "Hello " << "World!" << endl;
	// ���ļ�ǰ�ȹر��ļ�
	ofs.close();

	// ���´��ļ�
	ifstream ifs("read.txt");
	if (!ifs.is_open())
	{
		cout << "ifs �ļ���ʧ��" << endl;
		exit(EXIT_FAILURE);
	}
	char str[100];

	ifs >> str;
	// Hello �����ո�ֹͣ
	cout << str << endl;

	// ����Ҳ���Բ���ʾ���� close ��Ϊ ifs ����ʱ��������������л���� close 
	ifs.close();
}

struct Student
{
	char name[20];
	int age;
	char gender[5];
};

// �����ƶ�д�ļ���Ч�ʸߣ��ɶ��Բ�
void test6()
{
	ofstream ofs("binary.txt");
	if (!ofs.is_open())
	{
		cout << "ofs �ļ���ʧ��" << endl;
		exit(EXIT_FAILURE);
	}
	struct Student s = { "Shepard Wang", 20, "man" };
	// ע������ת��������Ҫ���� char* ����
	ofs.write((char*)&s, sizeof(s));
	ofs.close();

	ifstream ifs("binary.txt");
	if (!ifs.is_open())
	{
		cout << "ifs �ļ���ʧ��" << endl;
		exit(EXIT_FAILURE);
	}
	struct Student s2;
	ifs.read((char*)&s2, sizeof(s2));
	cout << s2.name << " " << s2.age << " " << s2.gender << endl;
	ifs.close();
}

// C++ �ı��ļ�
void test6p()
{
	// �ı���ʽд�ļ�
	ofstream text("text.cpp.txt");
	
	struct Student s = { "Shepard_Wang", 20, "man" };

	text << s.name << " " << s.age << " " << s.gender << endl;

	text.close();

	ifstream text2("text.cpp.txt");
	
	struct Student s2;

	text2 >> s2.name >> s2.age >> s2.gender;

	text2.close();
}

void test6cpppp()
{
	ofstream text("binary.cpp.txt");

	struct Student s = { "Shepard_Wang", 20, "man" };

	text.write((char*)&s, sizeof(s));

	text.close();

	ifstream text2("binary.cpp.txt");

	struct Student s2;

	text2.read((char*)&s2, sizeof(s2));

	text2.close();
}

// C ���԰��ı��ļ�
void test6pp()
{
	FILE* fp = fopen("text.c.txt", "w+");

	struct Student s = { "ShepardWang", 20, "man" };

	fprintf(fp, "%s %d %s", s.name, s.age, s.gender);

	fclose(fp);

	FILE* fp2 = fopen("text.c.txt", "r");

	struct Student s2;
	
	// ��ȡ���ִ���
	// s2.name �� Shepard�������ո������ȡ
	fscanf(fp2, "%s%d%s", s2.name, &s2.age, s2.gender);

	fclose(fp2);
}

// C ���԰�������ļ�
void test6ppp()
{
	FILE* fp = fopen("binary.c.txt", "w+");

	struct Student s = { "ShepardWang", 20, "man" };

	fwrite(&s, sizeof(s), 1, fp);

	fclose(fp);

	FILE* fp2 = fopen("binary.c.txt", "r");

	struct Student s2;

	fread(&s2, sizeof(s2), 1, fp2);

	fclose(fp2);
}

#include<sstream>
#include<stdlib.h>

// stingstream: �ѷ��ַ�������ת���ַ�����ʽ������
void test7()
{
	/**
	 *	C ���Խ����ַ���ת��Ϊ�ַ����ķ���
	 *	1. ʹ��itoa()����
	 *	2. ʹ��sprintf()����
	 */
	
	int x = 2;
	char str1[10], str2[10];
	// �����������ǽ� x ��ʮ���Ƶ���ʽת��Ϊ�ַ���
	_itoa(x, str1, 10);
	sprintf(str2, "%d", x);
	cout << str1 << " " << str2 << endl;

	stringstream ss;
	ss << x;
	string str = ss.str();
	cout << str << endl;
	ss.str("");
	ss.clear(); // ���״̬λ
	double y = 2.5;
	ss << y;
	cout << ss.str() << endl;
}

int main(void)
{
	test6cpppp();

	return 0;
}