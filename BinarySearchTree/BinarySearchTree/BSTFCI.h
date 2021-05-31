#pragma once
#include <iostream>
#include <queue> 
#include<vector>

using namespace std;
template <class T>
class  BSTNode
{
private:
    T key;
    BSTNode<T>* left;
    BSTNode<T>* right;
public:
    BSTNode() 
    { 
        left = right = 0; 
    }
    BSTNode(T& el, BSTNode* l = NULL, BSTNode* r = NULL) {
        key = el;
        left = l;
        right = r;
    }

    BSTNode*& getLeft()
    { 
        return left; 
    }
    void setLeft(BSTNode* newNode)
    {
        left = newNode;
    }
    BSTNode*& getRight()
    { 
        return right; 
    }
    void setRight(BSTNode* newNode)
    {
        right = newNode;
    }
    T getKey()
    { 
        return key; 
    }
    void setKey(T k)
    {
        key=k;
    }
};
template <class T>
class BSTFCI :BSTNode<T>
{
    BSTNode<T>* root;
    //post to print left then right then BSTNode parent
    void postorder(BSTNode<T>* p)
    {
        if (p != NULL)
        {
            postorder(p->getLeft());
            postorder(p->getRight());
            cout << p->getKey() << " ";
        }
    }
    //parent node then left then right
    void preorder(BSTNode<T>* p)
    {
        if (p != NULL)
        {
            cout << p->getKey() << " ";
            preorder(p->getLeft());
            preorder(p->getRight());
        }
    }
    //this function to save data in queue to use it in flip tree
    void preorder2(BSTNode<T>* p, queue<T>& z)
    {
        if (p != NULL)
        {
            z.push(p->getKey());
            preorder2(p->getLeft(), z);
            preorder2(p->getRight(), z);
        }
    }
    //this function to print left then parent node then right
    void inorder(BSTNode<T>* p)
    {
        if (p != NULL)
        {
            inorder(p->getLeft());
            cout << p->getKey() << " ";
            inorder(p->getRight());
        }
    }
    void largest(vector<int>& vec, BSTNode<T>* root, int size)
    {
        if (root == NULL)
            return;

        // Expand list size 
        if (size == vec.size())
            vec.push_back(root->getKey());

        else
        {
            if (vec[size] >= root->getKey())
                vec[size] = vec[size];
            else
                vec[size] = root->getKey();
        }

        largest(vec, root->getLeft(), size + 1);
        largest(vec, root->getRight(), size + 1);
    }
   //clear to delete tree
    void clear(BSTNode<T>* &p)
    {
        if (p != NULL)
        {
            clear(p->getLeft());
            clear(p->getRight());
            delete p;
            p = NULL;
        }
    }
    //this function used in flip 
    //in insertion binary tree the large value put at right and small value at left
    //in insertionopposite binary tree the small value put at right and large value at left
    void insertopposite(T item)
    {
        BSTNode<T>* current = root;
        BSTNode<T>* trailCurrent = new BSTNode<T>;
        BSTNode<T>* newNode = new BSTNode<T>(item);
        if (root == NULL)
            root = newNode;
        else
        {
            current = root;

            while (current != NULL)
            {
                trailCurrent = current;
                if (current->getKey() > item)
                    current = current->getRight();
                else
                    current = current->getLeft();
            }
            if (trailCurrent->getKey() > item)
                trailCurrent->getRight() = newNode;
            else
                trailCurrent->getLeft() = newNode;
        }
    }
    //this function put all data of tree in queue by preorder and insert it opposite after clear data 
    void flip(BSTNode<T>* p = root)
    {
        queue <T> q;
        preorder2(root, q);
        clearTree();
        int x = q.size();
        for (int i = 0; i < x; i++)
        {
            insertopposite(q.front());
            q.pop();
        }
        cout << endl;
    }
    //this function to check if every node has two child one left and one right
    bool balance(BSTNode<T>* node, int& l, int& r)
    {
        bool flag = true;
        /*if (node->right != NULL&& node->left != NULL)
        {*/
        if (node->getLeft() != NULL)
        {
            if (balance(node->getLeft(), l, r));
            l++;
        }
        if (node->getRight() != NULL)
        {
            if (balance(node->getRight(), l, r));
            r++;
        }
        /*  }*/
        else
            flag = false;
        return flag;
    }
    int sumTree(BSTNode<T>* root, int sum)
    {

        if (root == NULL) return 0;

        sum = (sum * 10 + root->getKey());

        if (root->getLeft() == NULL && root->getRight() == NULL)
            return sum;


        return sumTree(root->getLeft(), sum) + sumTree(root->getRight(), sum);
    }
     void deletee(BSTNode<T>*& p)
    {
        BSTNode<T>* current;    //pointer to traverse 
                                        //the tree
        BSTNode<T>* trailCurrent;   //pointer behind current
        BSTNode<T>* temp;        //pointer to delete the node

        if (p->getLeft() == NULL && p->getRight() == NULL)
        {
            delete p;
            p = NULL;
        }
        else if (p->getLeft() == NULL)
        {
            temp = p;
            p = p->getRight();
            delete temp;
        }
        else if (p->getRight() == NULL)
        {
            temp = p;
            p = p->getLeft();
            delete temp;
        }
        else
        {
            current = p->getLeft();
            trailCurrent = NULL;

            while (current->getRight() != NULL)
            {
                trailCurrent = current;
                current = current->getRight();
            }

            p->setKey(current->getKey());

            if (trailCurrent == NULL) 
                p->getLeft() = current->getLeft();
            else
                trailCurrent->getRight() = current->getLeft();

            delete current;
        }
    }
public:
    BSTFCI()
    {
        root = NULL;
    }
   bool isEmpty()
    {
        return (root == NULL);
    }
   void clearTree()
    {
        clear(root);
    }
   void insert(T item)
    {
        BSTNode<T>* current = root;
        BSTNode<T>* trailCurrent = new BSTNode<T>;
        BSTNode<T>* newNode = new BSTNode<T>(item);
        if (root == NULL)
            root = newNode;
        else
        {
            current = root;

            while (current != NULL)
            {
                trailCurrent = current;

                /*if (current->key == item)
                {
                    cout << "this items is already in data" << endl;
                    return;
                }
                else*/
                if (current->getKey() > item)
                    current = current->getLeft();
                else
                    current = current->getRight();
            }
            if (trailCurrent->getKey() > item)
                trailCurrent->setLeft(newNode);
            else
                trailCurrent->setRight(newNode);
        }
    }



    void printInorder()
    {
        inorder(root);
        cout << endl;
    }



    void printpreorder()
    {
        preorder(root);
        cout << endl;
    }



    void printpostorder()
    {
        postorder(root);
        cout << endl;
    }
    void search(T item)
    {
        bool flag = false;
        BSTNode<T>* current = root;
        if (isEmpty() == true)
            cout << "your tree is Empty\n";
        else
        {
            while (current != NULL)
            {
                if (item == current->getKey())
                {
                    flag = true;
                    cout << "founded\n";
                    current = current->getRight();
                }
                else if (item < current->getKey())
                    current = current->getLeft();
                else
                    current = current->getRight();
            }
        }
        if (current == NULL && flag == false)
            cout << "not founded\n";
    }
    void flipTree()
    {
        flip(root);
        cout << "print in order: ";
        printInorder();
        cout << "print pre order: ";
        printpreorder();
        cout << "print in order: ";
        printpostorder();
        cout << endl;
    }
    //function save data in queue then print data between low and heigh
    void printRange(T low, T heigh)
    {
        queue <T> q;
        preorder2(root, q);
        int x = q.size();
        cout << "[";
        for (int i = 0; i < x; i++)
        {
            if (q.front() >= low && q.front() <= heigh)
                cout << q.front() << "  ";
            q.pop();
        }
        cout << "]" << endl;
    }
  //thi function print root and right becouse at the right largest value in the row
    /*void largestValues()
    {
        Node* current = root;
        if (isEmpty() == true)
            cout << "your tree is Empty\n";
        else
        {
            while (current != NULL)
            {
                cout << current->key <<"\t";
                current = current->right;
            }
            cout << endl;
        }
    }*/
    bool isBalance()
    {
        //if tree is empty
        if (root == NULL)
        {
            cout << "is empty" << endl;
            return true;
        }
        //this tree has one item
        if (root->getLeft() == NULL && root->getRight() == NULL)
        {
            cout << "one item" << endl;
            return true;
        }
        int l = 0, r = 0, n = 0;
        //l is number of left children
        bool flag = balance(root, l, r), check = false;
        //this while to check if every node has two child depended on this equation n=n*2+1 or (n^2-1) 
        while (l >= n)
        {
            n = n * 2 + 1;
            if (n == l)
                check = true;
        }
        //if number of left child = right child and every node has two child
        if (l == r && flag == true /*&& check == true*/)
        {
            cout << "l = " << l << "r =" << r << endl;
            return true;
        }
        else
        {
            cout << "l = " << l << "r =" << r << endl;
            return false;
        }
    }
    void sum()
    {
        cout << sumTree(root, 0) << endl;
    }
    // function to find largest values 
    void largestValues()
    {
        vector<int> vec;
        int size = 0;
        largest(vec, this->root, size);
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << "\t";
        }
        cout << endl;
    }
    void remove(T ele)
    {
        BSTNode<T>* current;  //pointer to traverse the tree
        BSTNode<T>* trailCurrent; //pointer behind current

        if (root == NULL)
        {
            cout << "Cannot delete from the empty tree." << endl;
            return;
        }
        if (root->getKey() == ele)
        {
            deletee(root);
            return;
        }

        //if you get here, then the item to be deleted is not the root
        trailCurrent = root;

        if (root->getKey() > ele)
            current = root->getLeft();
        else
            current = root->getRight();

        //search for the item to be deleted.
        while (current != NULL)
        {
            if (current->getKey() == ele)
                break;
            else
            {
                trailCurrent = current;
                if (current->getKey() > ele)
                    current = current->getLeft();
                else
                    current = current->getRight();
            }
        }// once the while is done, current points to either NULL or to the node to be deleted

        if (current == NULL)
            cout << "The delete item is not in the tree." << endl;
        else if (trailCurrent->getKey()> ele)
            deletee(trailCurrent->getLeft());
        else
            deletee(trailCurrent->getRight());
    }
    ~BSTFCI()
    {
        clear(root);
    }
};

