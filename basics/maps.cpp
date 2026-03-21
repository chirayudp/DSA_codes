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
return 0;
}
