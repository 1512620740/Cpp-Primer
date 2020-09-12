#ifndef QUEUE_H_
#define QUEUE_H_

typedef int Item;

class Queue
{
private:
	struct Node
	{
		Item item;
		Node* next;
	};
	enum {Q_SIZE = 10};

	Node* front;
	Node* rear;
	int cnt;
	const int qsize;

	// preemptive definition ���к�����ʱ��ʵ�֣��Ժ���������󣬽����Ϊ���в�ʵ��
	Queue(const Queue& q) :qsize(0) {}
	Queue& operator=(const Queue& q) { return *this; }
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool IsEmpty() const;
	bool IsFull() const;
	int QueueCount() const;
	bool EnQueue(const Item& it);
	bool DeQueue(Item& it);
	void Show() const;
};

#endif 