#include<iostream>
#include<vector>

using namespace std;

class BitMap
{
public:
	BitMap(size_t range)
	{
		// �����ΧС�� 32��range / 32 Ϊ 0 
		_bit.resize(range / 32 + 1);
	}

	// ����
	bool Test(size_t n)
	{
		// ������λ��
		int idx = n / 32;
		// �������еı���λ
		int bitIdx = n % 32;

		// ��������д��������
		if ((_bit[idx] & (1 << bitIdx))) // ��Ҫд == 1����Ϊ & �Ľ����һ������ 1
		//if( ( (_bit[idx] >> bitIdx) & 1) == 1 )
			return true;
		else
			return false;
	}

	// ����
	void Set(size_t n)
	{
		int idx = n / 32;
		int bitIdx = n % 32;

		_bit[idx] |= (1 << bitIdx);
	}

	// ɾ��
	void Reset(size_t n)
	{
		int idx = n / 32;
		int bitIdx = n % 32;

		_bit[idx] &= ~(1 << bitIdx);
	}
private:
	vector<int> _bit;
};