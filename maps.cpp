#include <iostream>
#include <map>
#include <unordered_map>
#include "string.h"
#include <string>

using namespace std;

int main()
{

    map<string,float> fruits;

    unordered_map<int,int> mymap;
    multimap<string,float> fruits
    {
        {"orange",120},
        {"apple",1.50},
    };
    fruits["apple"] = 5.4;
    cout<<fruits["apple"]<<endl;
    fruits.at("apple") = 1.2;
    cout<<fruits["apple"]<<endl;
    fruits.insert({"banan",3.50});

    for(map<string,float>::iterator it = fruits.begin();it != fruits.end();it++)
    {
        cout <<it->first<< "  "<<it->second << endl;
    }
   
    
    return 0;
}