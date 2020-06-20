/***********************************************
 *	Date.cpp:
 *		ʵ��������������أ��ӿں���ʵ��
 *
 **********************************************/


#include"Date.h"
#include<math.h>


// �������������

ostream& operator<<(ostream& _cout, const Date& date)
{
	_cout << date._year << "-" << date._month << "-" << date._day;
	return _cout;
}

istream& operator>>(istream& _cin, Date& date)
{
	cout << "�����룺�� �� ��" << endl;
	_cin >> date._year >> date._month >> date._day;
	return _cin;
}


void Date::menu()
{
	cout << endl;
	cout << "         VX���ںţ������̵ĳ���Բ " << endl;
	cout << endl;
	cout << "**********************************************" << endl;
	cout << "*   " << "�˵��������������ɶ�Ӧ�Ĳ���"		 << endl;
	cout << "*          " << "1. �������ڲ�"				 << endl;
	cout << "*          " << "2. �������ڣ����"			 << endl;
	cout << "*          " << "3. �������ڣ���ǰ��"			 << endl;
	cout << "*          " << "4. �Ƚ����ڴ�С"				 << endl;
	cout << "*          " << "0.     �˳�"					 << endl;
	cout << "**********************************************" << endl;
}

Date Date::newDate()
{
	int year, month, day;

	cout << "�����룺�� �� ��" << endl;
	cin >> year >> month >> day;
	
	Date d1(year, month, day);

	return d1;
}


void Date::daysBetweenTwoDates(const Date& d2)
{
	cout << "���ղ" << abs((*this - d2)) << "��" << endl;
}

void Date::inferDateBack(int day)
{
	cout << day << " ��������Ϊ��" << (*this + day) << endl;
}

void Date::inferDateFront(int day)
{
	cout << day << " ��ǰ������Ϊ��" << (*this - day) << endl;
}


void Date::compareDate(const Date& d2)
{
	if (*this == d2)
		cout << "�������" << endl;
	else if (*this > d2)
		cout << *this << " ���� " << d2 << endl;
	else 
		cout << *this << " С�� " << d2 << endl;

}

void Date::exitDate()
{

	cout << "��л֧�֣��ټ���" << endl;
	exit(EXIT_SUCCESS);
}
