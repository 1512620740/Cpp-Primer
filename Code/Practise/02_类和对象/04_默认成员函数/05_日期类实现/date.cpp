#include<iostream>

using namespace std;

class Date
{
public:
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
	{

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
	Date operator+(int day)
	{
		Date ret = *this;
		ret += day;
		return ret;
	}

	// ����-����
	Date operator-(int day)
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
	Date operator++(int)
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
	bool operator>(const Date& d)
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
	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	// >=���������
	bool operator >= (const Date& d)
	{
		return (*this == d || *this > d);
	}
	
	// <���������
	bool operator < (const Date& d)
	{
		return !(*this >= d);
	}
	
	// <=���������
	bool operator <= (const Date& d)
	{
		return !(*this > d);
	}
	
	// !=���������
	bool operator != (const Date& d)
	{
		return !(*this == d);
	}
	
	// ����-���� ��������
	int operator-(const Date& d)
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

	Date* operator&()
	{
		return this;
	}

	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

// ��Ҫ�����еĳ�Ա��������Ϊ public 
//ostream& operator<<(ostream& _cout, const Date& date)
//{
//	_cout << date._year << date._month << date._day << endl;
//	return _cout;
//}

int main(void) {

	Date d(2020, 6, 14);
	d.print();
	d += 20;
	d.print();
	d += 365;
	d.print();
	cout << "================" << endl;
	Date d1(2020, 6, 31);
	cout << "================" << endl;
	Date d2(1, 1, 10);
	d2 -= 10;
	d2.print();
	cout << "================" << endl;
	Date d3(2020, 6, 14);
	d3++.print();
	d3--.print();
	d3.print();
	cout << "================" << endl;
	Date d4(2020, 6, 30);
	(++d4).print();
	(--d4).print();
	cout << "================" << endl;
	Date d5(2019, 12, 31);
	Date d6(2019, 12, 30);
	cout << (d5 == d6) << endl;
	cout << (d5 != d6) << endl;
	cout << (d5 > d6) << endl;
	cout << (d5 >= d6) << endl;
	cout << (d5 < d6) << endl;
	cout << (d5 <= d6) << endl;
	cout << "================" << endl;
	Date d7(1, 2, 15);
	cout << &d7 << endl;
	(d7 + 31).print();
	d7.print();
	(d7 - 31).print();
	d7.print();
	cout << "========�������˶��������========" << endl;
	Date d8(2020, 1, 7);
	Date d9(2020, 6, 14);
	cout << (d9 - d8) << endl;
	cout << (d8 - d9) << endl;

	return 0;
}
