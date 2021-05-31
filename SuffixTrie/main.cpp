#include<iostream>
using namespace std;

template<class T>
class Node
{
public:
	T item;
	char chara;
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
	void insertFront(T element,char c)
	{
		Node<T>* newNode = new Node<T>();
		newNode->item = element;
		newNode->chara = c;
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
	void insertBack(T element,char c)
	{
		Node<T>* newNode = new Node<T>();
		newNode->item = element;
		newNode->chara = c;
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
	char getchar(int position)
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
					return current->chara;
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
			cout << current->item;
			current = current->next;
		}
	}
};

class suffixNode
{
    public:
	suffixNode* child[256];
	LinkedList<int>* index;
	LinkedList<char>* chara;
	int n = 0;
public:
	suffixNode()
	{
		index = new LinkedList<int>();
		chara = new LinkedList<char>();
		for (int i = 0; i < 256; i++)
			child[i] = NULL;
	}
	void insert(char s[], int j, int indx)
	{
		if (n == 0)
		{
			index->insertFront(indx, s[0]);
			chara->insertFront(s[0]);
			n++;
		}
		else
		{
			index->insertBack(indx, s[0]);
			chara->insertBack(s[0]);
			n++;
		}
		int charSize = j;
		if (charSize > 0)
		{
			char temp = s[0];
			if (child[temp] == NULL)
				child[temp] = new suffixNode();

			char* sub = new char[charSize - 1];
			for (int i = 0; i < j - 1; i++)
			{
				sub[i] = s[i + 1];
			}
			child[temp]->insert(sub, j - 1, indx + 1);
		}
	}

	LinkedList<int>* search(char s[], int& size)
	{
		if (s[0] == '\0')
		{
			size = n;
			return index;
		}
		if (child[s[0]] != NULL)
		{
		    int ssize = 0;

		    for(int i = 0; s[i] != '\0'; i++)
            {
                ssize++;
            }
            char* sub = new char[ssize];
            for(int i = 0; s[i] != '\0'; i++)
            {
                sub[i] = s[i + 1];
            }

			return (child[s[0]])->search(sub, size);
		}
		else
            return NULL;
	}
    void print()
    {

        for(int i = 1; i< 256;i++)
        {
            if(child[i-1] != NULL)
            {
                child[i-1]->chara->print();
                cout<<endl;
            }
        }
    }
};

class SuffixTrie
{
    public:
	suffixNode root;
public:
	SuffixTrie(char txt[])
	{
	    int txtsize = 0;
	    for (int i = 0; txt[i] != '\0'; i++)
		{
		    txtsize++;
		}
		char* sub = new char[txtsize];
		for (int i = 0; txt[i] != '\0'; i++)
		{
			int j = i;
            int k = 0;
			for (; j < txtsize; j++)
			{
				sub[k] = txt[j];
				k++;
			}
			root.insert(sub, j, i);
		}
	}
	void Search(char s[])
	{
		int size = 0;
		int ssize = 0;
		for(int i = 0; s[i] != '\0'; i++)
            ssize++;
		LinkedList<int>* data = new LinkedList<int>();
		data = root.search(s, size);
//		int l = s.length();
		int b = 0;
		if (data == NULL){
            cout << "Not found" << endl;
        }
		else {
			cout << "Prints: ";
			for (int i = 0; i < size; i++)
			{
				cout << data->get(i) - ssize << " " ;
			}
			cout << endl;
		}
	}
    void print()
    {

        root.print();
    }
};

int main()
{
    // Construct a suffix trie containing all suffixes of "bananabanaba$"
    //            0123456789012
    SuffixTrie t("bananabanaba$");
    t.Search("ana");   // Prints: 1 3 7
    t.Search("naba"); // Prints: 4 8
    t.print();
    return 0;
}
