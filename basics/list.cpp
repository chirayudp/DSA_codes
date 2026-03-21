#include <bits/stdc++.h>
using namespace std;

void dispList(list<int> lis){
    list<int> :: iterator i;
    for (i = lis.begin(); i != lis.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
}
int main(){
list <int> list2;//for an empty list
list <int> list1(5);// list of size 5;
for (int i=0; i < 3; i++)
{
    int x;
    cin >> x;
    list2.push_back(x);
}
dispList(list2);
for (int i=0; i < 5; i++)
{
    int x;
    cin >> x;
    list1.insert(list1.begin(),2,x);
}
dispList(list1);
}
