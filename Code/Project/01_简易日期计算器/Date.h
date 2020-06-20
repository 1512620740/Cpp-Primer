/***********************************************
 *	Date.h:
 *		Date �ࡣ����������������������
 *		Ȼ����ȥ���ӿں������ӿں���������Լ�ʵ��		
 *		
 **********************************************/


#pragma once

#include<iostream>
#include<stdlib.h>

using namespace std;

class Date
{
	friend ostream& operator<<(ostream& _cout, const Date& date);
	friend istream& operator>>(istream& _cin, Date& date);

public:
	
	//  �ӿں���
	static void menu();
	
	// ����һ���µĶ������û������ʼ��
	static Date newDate();

	// �������ڲ�
	void daysBetweenTwoDates(const Date& d2);

	// �������ڣ����
	void inferDateBack(int day);

	// �������ڣ���ǰ��
	void inferDateFront(int day);

	//�Ƚ����ڴ�С
	void compareDate(const Date& d2);

	// �Ƴ�����
	static void exitDate();

	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1900, int month = 1, int day = 1)
	{
		if (year > 0 && month > 0 && month < 13 && day > 0 && day <= getMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "��������Ƿ���" << year << "-" << month << "-" << day << endl;
			cout << "��������Ϊ��1970-1-1" << endl;
			_year = 1970;
			_month = 1;
			_day = 1;
		}
	}

	// �������캯��
	// d2(d1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}


	// ��ֵ���������
	// d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}

		return *this;
	}

	// ��������
	~Date()
	{}
	
	// ȡ��ַ

	Date* operator&()
	{
		return this;
	}

	const Date* operator&() const
	{
		return this;
	}
	
	// �������Щ������Ҳ��������Ϊ public
private:
	// ��ȡĳ��ĳ�µ�����
	int getMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];

		// �ж��Ƿ�Ϊ����
		if (month == 2 && ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
			day++;

		return day;
	}



	// ����+=����
	Date& operator+=(int day)
	{
		// ���� += -���� Ҳ�͵��� ���� -= ����
		if (day < 0)
			return *this -= day;

		_day += day;

		// �������ڵ�������
		while (_day > getMonthDay(_year, _month))
		{
			// ������ȥ��������
			_day -= getMonthDay(_year, _month);
			_month++;
			// �·ݴ��� 12
			if (_month > 12)
			{
				_month = 1;
				_year++;
			}
		}

		return *this;
	}

	// ����+����
	// �����޸ĵ�ǰ�Ķ���
	Date operator+(int day) const
	{
		Date ret = *this;
		ret += day;
		return ret;
	}

	// ����-����
	Date operator-(int day) const
	{
		Date ret = *this;
		ret -= day;
		return ret;
	}


	// ����-=����
	Date& operator-=(int day)
	{
		if (day < 0)
			return *this += day;

		_day -= day;

		// �������С���㣬ÿ��ѭ��Ӧ�ü�����һ���µ�����
		// ������һ�����п���С�ڵ��� 0�����Բ���ֱ�Ӽ���һ���µ�������Ӧ�����Ƴ��Ϸ����ϸ���1
		while (_day <= 0)
		{
			_month--;
			if (_month <= 0)
			{
				_month = 12;
				_year--;
				if (_year <= 0)
				{
					cout << "����������������Ϊ��1-1-1" << endl;
					_year = 1;
					_month = 1;
					_day = 1;
					return *this;
				}
			}
			_day += getMonthDay(_year, _month);
		}

		return *this;
	}

	// ǰ��++
	Date& operator++()
	{
		return *this += 1;
	}

	// ����++
	Date& operator++(int)
	{
		// ���ÿ�������
		// �ȱ��浱ǰ��״̬
		Date ret(*this);
		*this += 1;
		// ��������ǰ��״̬
		return ret;
	}

	// ǰ��--
	Date& operator--()
	{
		return *this -= 1;
	}

	// ����--
	Date operator--(int)
	{
		Date ret(*this);
		*this -= 1;
		return ret;
	}



	// >���������
	bool operator>(const Date& d) const
	{
		if (_year > d._year)
			return true;
		else if (_year == d._year && _month > d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day > d._day)
			return true;
		else
			return false;

	}

	// ==���������
	bool operator==(const Date& d) const
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	// >=���������
	bool operator >= (const Date& d) const
	{
		return (*this == d || *this > d);
	}

	// <���������
	bool operator < (const Date& d) const
	{
		return !(*this >= d);
	}

	// <=���������
	bool operator <= (const Date& d) const
	{
		return !(*this > d);
	}

	// !=���������
	bool operator != (const Date& d) const
	{
		return !(*this == d);
	}

	// ����-���� ��������
	int operator-(const Date& d) const
	{
		Date d1(*this);
		int num = 0;
		if (d1 < d)
		{
			while (d1 < d)
			{
				d1++;
				num--;
			}
		}
		else
		{
			// ��� d1 == d ��ô�������ѭ�� num Ϊ 0
			while (d1 > d)
			{
				d1--;
				num++;
			}
		}

		return num;
	}


private:
	// ��Ա����
	int _year;
	int _month;
	int _day;
};






