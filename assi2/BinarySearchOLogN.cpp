#include<iostream>
using namespace std;
int main()
{
    int v;
    int arr[] = {3,7,11,18,23,36,45,49,54,69,76,89,90};
    int n = sizeof(arr)/sizeof(arr[0]);
    int left = 0;
    int right = n - 1;
    bool found = false;
    cout<<"enter the element you want to find: "<<endl;
    cin>>v;
    while(left <= right)
    {
        int mid = (left + right)/2;

        if(arr[mid] == v)
        {
            cout<<"Element "<<v<<" found at "<<mid +1<<" position"<<endl;
            found = true;
            break;
        }
        else if(arr[mid] > v)
        {
            right = mid - 1; 
        }
        else
        {
            left = mid + 1;        
        }
        


    }
    if(found == false)
        {
            cout<<"Element "<<v<<" not found"<<endl;
        }


return 0;
}