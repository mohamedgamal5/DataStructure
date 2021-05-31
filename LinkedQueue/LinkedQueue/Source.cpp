#include <iostream>
using namespace std;
template<class T>
class LinkedQueue
{
	struct Node
	{
		T item;
		Node* next;
	};
	int length;
	Node *front,*rear;
public:
	LinkedQueue()
	{
		front = rear = NULL;
		length = 0;
	}
	bool isEmpty()
	{
		return (length == 0);
	}
	void enQueue(T element)
	{
		Node* newnode = new Node;
		newnode->item = element;
		newnode->next = NULL;
		if (length == 0)
		{
			front = rear = newnode;
			length++;
		}
		else
		{
			rear->next = newnode;
			rear = newnode;
			length++;
		}
	}
	void deQueue()
	{
		if(isEmpty())
			cout << "Empty Queue" << endl;
		else if (length == 1)
		{
			delete front;
			rear = NULL;
			length = 0;
		}
		else
		{
			Node* current = front;
			front = front->next;
			delete current;
			length--;
		}
	}
	void clearQueue()
	{
		Node* current;
		while (front != NULL)
		{
			current = front;
			front = front->next;
			delete current;
		}
		rear = NULL;
		length = 0;
	}
	bool search(T element)
	{
		Node* current = front;
		bool flag = false;
		while (current != NULL)
		{
			if (element == current->item)
			{	
				cout << "the item :" << element << " found" << endl;
				flag = true;
			}
			current = current->next;
		}
		return flag;
	}
	void display()
	{
		Node* current = front;
		cout << "Item in the queue :[ ";
		while (current != NULL)
		{
			cout << current->item << " ";
			current = current->next;
		}
		cout << "]" << endl;
	}
};
int main()
{
	LinkedQueue<int>q1;
	for (int i = 1; i <= 20; i++)
		q1.enQueue(i);
	q1.enQueue(20);
	q1.display();
	cout << q1.search(20) << endl;
	return 0;
}