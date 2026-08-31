#include<iostream>
using namespace std;
int main()
{
    int arr[] = {1,2,3,4,5,6,7,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int actual_sum = 0;
    for(int i=0; i<n; i++)
    {
        actual_sum += arr[i];
    }
    int expected_sum = n*(n+1)/2;
    cout << "Missing element is: " << expected_sum - actual_sum << endl;
    
}

