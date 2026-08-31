#include<iostream>
using namespace std;
int arr[4][4] = {
{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}
};

int main()
{
 cout<<"Original array:"<<endl;
 for(int i = 0; i < 4;i++)
 {
    for(int j = 0;j < 4;j++)
    {
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
 }
 int i = 0;
 int j = 0;
 int start = arr[i][j];
 do
 {
    if((i+j) % 2 == 0)
 {
    j++;
 }
 else
 {
    i++;
 }
 
 } while (i < 4 && j < 4 );
 
 
 
}