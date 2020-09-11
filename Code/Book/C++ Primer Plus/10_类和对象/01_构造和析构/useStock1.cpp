#include<iostream>
#include"Stock1.h"

int main(void)
{
	using std::cout;
	using std::ios_base;
	// #.## format
	cout.precision(2);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);

	cout << "====== Use constructor to create new objects ======= \n ";
	Stock stock1("doudou", 12, 20.0);
	stock1.show();
	/*
	 * �������俴���Ǹ�ֵ��ʵ�����ǹ���
	 * ����ȿ���ͨ����ʼ��Ҳ����ͨ����ֵ�����ö����ֵ����Ӧ�ò��ó�ʼ��
	 * ͨ�����ַ�ʽЧ�ʸ���
	 */
	Stock stock2 = Stock("diandian", 20, 13);
	stock2.show();

	cout << "\n====== Assigning stock1 to stock2 ======= \n";
	stock2 = stock1;
	stock1.show();
	stock2.show();
	
	/*
	 * ���ù��캯��������һ����������ʱ����Ȼ�󽫸���ʱ�����Ƶ� stock1 ��ȥ
	 * ��ʱ������ܻᱻ����ɾ����Ҳ���ܻ��һ��ʱ�䣨��������Ҳ���һ��ʱ��ŵ��ã�
	 */
	cout << "\n===== Using a constructor to reset an object ====== \n";
	stock1 = Stock("Shepard", 10, 50.0);
	stock1.show();
	
	/*
	 * ע�⵽ stock2 �����������ȱ����á�
	 * ���������Զ����������ջ�У������󴴽��Ķ�������ȱ�ɾ����
	 */
	return 0;
}

/*  
�����
====== Use constructor to create new objects ====== =
constructor called
Company : doudou Shares : 12 Share Price : 20.00 Total Worth : 240.00
constructor called
Company : diandian Shares : 20 Share Price : 13.00 Total Worth : 260.00

====== Assigning stock1 to stock2 ====== =
Company : doudou Shares : 12 Share Price : 20.00 Total Worth : 240.00
Company : doudou Shares : 12 Share Price : 20.00 Total Worth : 240.00

==== = Using a constructor to reset an object ======
constructor called
Bye, Shepard!
Company : Shepard Shares : 10 Share Price : 50.00 Total Worth : 500.00
Bye, doudou!
Bye, Shepard!
*/