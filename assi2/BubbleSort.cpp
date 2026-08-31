#include<iostream>
using namespace std;
int main()
{   
    int arr[] = {12,23,11,7,34,32,45,67,43,99,78,33,76,80};
    int n = sizeof(arr)/sizeof(arr[0]);
    int temp;
    for(int i = 0; i < n - 1 ;i++)
    {
        for(int j = i + 1;j < n;j++)
        if(arr[i] > arr[j])
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    cout<<"Sorted Array: "<<endl;
for(int i = 0;i < n;i++)
{
    cout<<" "<<arr[i];
}

}