//#include<map>
//#include<unordered_map>
//
//#include<iostream>
//
//#include<set>
//#include<unordered_set>
//
//using namespace std;
//
//void test1()
//{
//	map<int, int> m;
//	unordered_map<int, int> um;
//
//	m.insert(make_pair(1, 1));
//	m.insert(make_pair(2, 2));
//	m.insert(make_pair(4, 4));
//	m.insert(make_pair(5, 5));
//	m.insert(make_pair(3, 3));
//
//	um.insert(make_pair(1, 1));
//	um.insert(make_pair(2, 2));
//	um.insert(make_pair(4, 4));
//	um.insert(make_pair(5, 5));
//	um.insert(make_pair(3, 3));
//
//	// ���������������
//	cout << "======== map ======== " << endl;
//	map<int, int>::iterator it = m.begin();
//	while (it != m.end())
//	{
//		cout << it->first << " " << it->second << " ";
//		it++;
//	}
//	cout << endl;
//
//	// ��������������,˳���������һ���ǲ����˳��
//	cout << "======== unordered_map ======== " << endl;
//	unordered_map<int, int>::iterator uit = um.begin();
//	while (uit != um.end())
//	{
//		cout << uit->first << " " << uit->second << endl;
//		uit++;
//	}
//	
//	// unordered_map û�з��������
//
//	cout << "======== operator[] & at() ======== " << endl;
//	// operator[] ��д + ����
//	um[5] = 6;
//	um[6] = 6;
//
//	// at() ����
//	um.at(1) = 0;
//	//um.at(7) = 8; // �׳��쳣
//
//	uit = um.begin();
//	while (uit != um.end())
//	{
//		cout << uit->first << " " << uit->second << endl;
//		uit++;
//	}
//
//	cout << "======== find() & count() ======== " << endl;
//	// ���� key ��Ӧ�ĵ����������û���ҵ����� end()
//	uit = um.find(6);
//	cout << uit->first << " " << uit->second << endl;
//	uit = um.find(7);
//	cout << (uit == um.end()) << endl;
//	// ���� key Ϊ 6 ����
//	cout << um.count(6) << endl;
//	
//}
//
///*
// *	���� insert ��γ�ʼ�� value
// */
//void test2()
//{	
//	map<int, int> m;
//	
//
//}
//
//int main(void)
//{	
//	test2();
//
//	return 0;
//}