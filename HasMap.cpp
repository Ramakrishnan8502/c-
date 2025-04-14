//implement Hashing technique - Linaer Probing

#include <iostream>
using namespace std;

class HashTable
{
    private :
        int *HT;
        int Size;
    public:
        HashTable(int);
        ~HashTable();
        int Hash(int);
        int LinearProbing(int);
        void Insert(int);
        int Search(int);
        void Display();
};

HashTable::HashTable(int s)
{
    Size = s;
    HT = new int [Size];
    for(int i = 0 ;i < Size; i++ )
    {
        HT[i] = {0};
    }
}

HashTable::~HashTable()
{
    delete [] HT;
}

int HashTable::Hash(int key)
{
    return key % Size;
}

int HashTable::LinearProbing(int key)
{
    int idx = Hash(key);
    int i = 0;
    while(HT[(idx + i) %  Size] != 0)
    {
        i++;
    }
    return (idx + i) % Size;
}

void HashTable:: Insert(int key)
{
    int idx = Hash(key);
   if(HT[idx] != 0)
   {
     idx = LinearProbing(key);
   }
   HT[idx] = key;
}

int HashTable::Search(int key)
{
    int idx = Hash(key);
    int i =0;
    while(HT[(idx + i) % Size ] != key)
    {
        i++;
        if(HT[(idx + i )% Size ] == 0)
        {
            return -1;
        }
    }
    return (idx + i) % Size;
}

void HashTable::Display()
{
    cout <<"Hash Table Values"<<endl;
    for(int i = 0; i < Size ; i++)
    {
        cout<<HT[i]<< "  ";
        cout<<endl;
    }
}

int main()
{
    int size;
    cout << "Enter the size of Hashmap"<<endl;
    cin >> size;
    HashTable Hs(size);
    int key;
    for(int i = 0; i < size; i++)
    {
        cin >> key;
        Hs.Insert(key);
    }
    Hs.Display();
    cout<<"\n Enter the search key"<<endl;
    cin >> key;
    int index = Hs.Search(key);
    if(index != -1)
    cout<<"found at "<<index + 1 << "st Postion"<<endl;


}