#include <iostream>
using namespace std;
template<class T>
class Node
{
public:
	T item;
	Node* next;
};

template<class T>
class LinkedList
{
	Node<T>* first;
	Node<T>* last;
	int length;
public:
	LinkedList()
	{
		first = last = NULL;
		length = 0;
	}
	bool isEmpty()
	{
		return(length == 0);
	}
	void insertFront(T element)
	{
		Node<T>* newNode = new Node<T>();
		newNode->item = element;
		if (length == 0)
		{
			first = last = newNode;
			newNode->next = NULL;
		}
		else
		{
			newNode->next = first;
			first = newNode;
		}
		length++;
	}
	void insertBack(T element)
	{
		Node<T>* newNode = new Node<T>();
		newNode->item = element;
		if (length == 0)
		{
			first = last = newNode;
			newNode->next = NULL;
		}
		else
		{
			last->next = newNode;
			newNode->next = NULL;
			last = newNode;
		}
		length++;
	}
	void insertPosition(int position, T element)
	{
		if (position < 0 || position > length)
			cout << "ERROR: Out of range" << endl;
		else
		{
			Node<T>* newNode = new Node<T>();
			newNode->item = element;
			if (position == 0) //insert at the begining
				insertFront(element);
			else if (position == length) //insert at the end;
				insertBack(element);
			else
			{
				Node<T>* current = first;
				for (int i = 1; i < position; i++)
					current = current->next;

				newNode->next = current->next;
				current->next = newNode;
				length++;
			}

		}

	}
	T get(int position)
	{
		if (position < 0 || position > length - 1)
		{
			return NULL;
		}
		else
		{
			Node<T>* current = new Node<T>;
			current = first;
			int i = 0;
			if (i == position)
			{
				return current->item;
			}
			while (current != NULL)
			{
				if (position == i)
				{
					return current->item;
				}
				//cout << current->item << endl;
				current = current->next;
				i++;
			}

		}

	}
	void print()
	{
		Node<T>* current = new Node<T>;
		current = first;
		while (current != NULL)
		{
			cout << current->item << endl;
			current = current->next;
		}
	}
};
int main()
{
	LinkedList<int> l;
	l.insertFront(0);
	l.insertPosition(0, 4);
	l.insertBack(5);
	l.print();
	cout << ">>>>>>>>>>>>>" << endl;
	cout<<l.get(3)<<endl;
	if(l.get(3) == NULL)
		cout << ">>>>>>>>>>>>>>\n";
	LinkedList<int> g = l;
	g.print();
	return 0;
}









