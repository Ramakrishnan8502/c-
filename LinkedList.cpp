#include <iostream>
using namespace std;

template <class T>
 class node
{
    public:
        T data;
        node<T> *Link;
};
template <class T>
class Chain
{
    private:
        node<T> *First,*Last;
        int len;
    public:
         Chain();
        ~Chain(){}
        void Insert(int,T);
        void Delete(int,T&);
        bool Find(int,T&);
        int Search(T);
        void Display();
        int Length(){return len;}
        bool IsEmpty();
};

template <class T>
Chain<T>::Chain()
{ 
    First = Last = NULL;
    len = 0;

}

template <class T>
void Chain<T>::Insert(int pos,T Element)
{
    node<T> *temp;
    temp = new node<T>;
    temp->data = Element;
    temp->Link = NULL;

    if(len == 0)
    {
        First = Last = temp;
    }
    else if(pos == 1)
    {
        temp->Link = First;
        First = temp;
    }
    else if(pos == len + 1)
    {
        Last->Link = temp;
        Last = temp;
    }
    else
    {
        node<T> *P = First;
        for(int i=0;i<pos-2;i++)
        P = P->Link;
        temp->Link = P->Link;
        P->Link = temp;
    }
    len++;
}

template <class T>
void Chain<T>:: Display()
{
    node<T> *temp;
    temp = First;
    while(temp != NULL)
    {
        cout<<temp->data<<"  ";
        temp = temp->Link;
    }
}

template <class T>
void Chain<T>::Delete(int pos,T& element)
 {
    node<T> *p;
    node<T> *q;
    p = q = First;

    if(len == 0)
    {
        cout<<"linked list is empty \n";
        return; 
    }
    if(pos == 1)
    {
    First = First->Link;
    }
    else if(pos == len)
    {
        for(int i=0;i<pos - 2;i++)
        p = p-> Link;
        p->Link = NULL;
        Last = p;
    }
    else
    {
        for(int i=0;i<pos - 2;i++)
        p = p-> Link;
        q = p->Link;
        p -> Link = q -> Link;   
    }   
     element = q->data;
     delete q;
     len--;
       
    
 } 

 template <class T>
 bool Chain<T>::Find(int pos,T &element)
 {
    if((pos < 1) || (pos > len ))
    {
        cout<<"invalid position \n";
        return false; 
    }
    else
    {   node<T> *p;
        p = First; 
        for(int i=0;i < pos-2;i++)
        p = p->Link;
        element = p->data;
        return true; 
    }
 }

 template <class T>
 int Chain<T>::Search(T element)
 {
    node<T>* p;
    p = First;
    int i = 1; 
    while(p != NULL)
    {
        if (element == p->data)
        {
            return i;
        }
        p = p->Link;
        i++;
    }
    return -1;

 }

template <class T>
bool Chain<T>::IsEmpty()
{
    if(First == NULL)
    return true;
    else
    return false;
}
int main()
{
    Chain<int> ch;
    int del;
    ch.Insert(1,1);
    ch.Insert(2,100);
    ch.Insert(3,3);
    ch.Insert(4,4);
    ch.Display();
    ch.Delete(2,del);
    cout<<"\n";
    cout<<"deleted value is "<<del<<"\n";
    ch.Display();
     cout<<"\n";
    int x = 0;
    if(ch.Find(1,x))
    {
        cout<<"found on "<<x<<" = th position \n";
    }
    int  a = 0;
    a = ch.Search(3);
    cout<<"position = "<<a;
}