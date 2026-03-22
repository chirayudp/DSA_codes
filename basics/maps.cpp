#include <bits/stdc++.h>
using namespace std;
int main(){
    map<string,int> marks;
marks["girish"] = 9;
marks["rohan"] = 10;
marks["manish"] = 9;
map<string,int> :: iterator i;
for ( i = marks.begin(); i != marks.end(); i++)
{
    cout << (*i).first << ',' << (*i).second << endl;
}
cout << endl;
map<int,int> marks2;
marks2[1] = 9;
marks2[4] = 10;
marks2[3] = 9;
map<int,int> :: iterator j;
for ( j = marks2.begin(); j != marks2.end(); j++)
{
    cout << (*j).first << ',' << (*j).second << endl;
}
cout << endl;
return 0;
}
