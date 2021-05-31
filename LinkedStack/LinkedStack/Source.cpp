#include<iostream>
using namespace std;
template<class T>
class LinkedStack
{
private:
	struct Node
	{
		T item;
		Node* next;
	};
	Node* current,* top;
public:
	LinkedStack()
	{
		top = NULL;
	}
	bool isEmpty()
	{
		return top == NULL;
	}
	void push(T element)
	{
		Node* newnode = new Node;
		if (newnode == NULL)
		{
			cout << "Stack push cannot allocate memory";
		}
		else
		{
			newnode->item = element;
			newnode->next = top;
			top = newnode;
		}
	}
	void pop()
	{
		if (isEmpty())
			cout << "Stack empty on pop";
		else {
			Node* temp = top;
			top = top->next;
			temp->next = NULL;
			delete temp;
		}
	}
	T getTop()
	{
		if (isEmpty())
		{
			cout << "stack empty on getTop";
			return 0;
		}
		else{
			Node* current = top;
			return current->item;
		}
	}
	void display()
	{
		current = top;
		cout << "\nItems in the stack : ";
		cout << "[ ";
		while (current != NULL)
		{
			cout << current->item<<"	";
			current = current->next;
		}
		cout << " ]\n";
	}
};
int main()
{
	LinkedStack<int> l;
	cout << l.getTop();
	l.push(50);
	l.push(40);
	l.push(30);
	cout << l.getTop();
	l.pop();
	l.display();
	return 0;
}