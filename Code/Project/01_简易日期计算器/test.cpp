#include"Date.h"

int main(void)
{
	Date::menu();
	int choice, day;
	Date d1, d2;

	while (1)
	{
		cout << "����������ѡ��";
		cin >> choice;

		//cout << "*          " << "1. �������ڲ�" << endl;
		//cout << "*          " << "2. �������ڣ����" << endl;
		//cout << "*          " << "3. �������ڣ���ǰ��" << endl;
		//cout << "*          " << "4. �Ƚ����ڴ�С" << endl;
		//cout << "*          " << "0.     �˳�" << endl;
		switch(choice)
		{
		case 0: 
			Date::exitDate(); break;

		case 1:			
			d1 = Date::newDate();
			d2 = Date::newDate();

			d1.daysBetweenTwoDates(d2);
			break;

		case 2:
			d1 = Date::newDate();
			cout << "����" << endl;
			cin >> day;

			d1.inferDateBack(day);
			break;

		case 3:
			d1 = Date::newDate();
			cout << "����" << endl;
			cin >> day;

			d1.inferDateFront(day);
			break;

		case 4:
			d1 = Date::newDate();
			d2 = Date::newDate();

			d1.compareDate(d2);
			break;
		}
		
	}
	
	return 0;
}