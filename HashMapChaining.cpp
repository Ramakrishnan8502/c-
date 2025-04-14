//HASHMAP - CHAINING

#include <iostream>
using namespace std;

class Node
{
    public:
    int Data;
    Node *Next;
};

class Hashtable
{
    public:
        Node **HT;
        Hashtable();
        ~Hashtable();
        int Hash(int);
        void Insert(int);
        int Search(int);
        void Display();
};

Hashtable::Hashtable()
{
    HT = new Node* [10];
    for(int i=0;i<10;i++)
    {
        HT[i] = NULL ;
    }
}

int Hashtable::Hash(int key)
{
    return key % 10;
}

void Hashtable::Insert(int key)
{
    int idx = Hash(key);
    Node *temp = new Node;
    temp->Data = key;
    temp->Next = NULL;

    if(HT[idx] == NULL )
    {
        HT[idx] = temp;
    }
    else
    {
        Node *p = HT[idx];
        Node *q = HT[idx];
        while(p != NULL && p->Data < key)
        {
            q = p;
            p = p->Next;
        }
        if(q==HT[idx])
        {
            temp->Next =  HT[idx];
            HT[idx] = temp;
         }
         else
         {
            temp -> Next = q -> Next;
            q->Next = temp;
         }
    }
}

int Hashtable::Search(int key)
{
    int idx = Hash(key);
    Node *p = HT[idx];

    while(p)
        {
            if(p->Data == key)
            return p->Data;
            p = p->Next;
        }
        return -1;
}

Hashtable::~Hashtable()
{
    for(int i = 0;i < 10; i++)
    {
        Node * temp = HT[i];
        while(temp)
        {
            Node *p = temp;
            temp = temp->Next;
            delete p;
        }
    }
    delete []HT;
}

void Hashtable::Display()
{
    for(int i = 0; i < 10; i++)
    {
        cout << "Bucket " << i << ": ";
        Node* p = HT[i];
        while(p)
        {
            cout << p->Data << " -> ";
            p = p->Next;
        }
        cout << "NULL" << endl;
    }
}


int main()
{
    int A[] = {1,34,76,9,3,34,45,11,23,67};
    Hashtable H;
    for(int i = 0;i < 10 ;i++)
    {
        H.Insert(A[i]);
    }
    int key = 45;
    int val = H.Search(key);
    cout << "value is "<< val << endl;
    H.Display();
}