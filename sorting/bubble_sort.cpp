#include <iostream>
using namespace std;

void swap(int &a ,int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
int arr[]={27,26,4,7,11,39,2,14};
int n = sizeof(arr) / sizeof(arr[0]);
int s=1;//swapped var
while (s)
{
    s=0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i-1]> arr[i])
        {
            swap(arr[i-1],arr[i]);
            s=1;
        }
    }
    n--;
}

 n = sizeof(arr) / sizeof(arr[0]);
for (int i = 0; i < n; i++)
{
    cout << arr[i] << " ";
}

cout << endl;
}
