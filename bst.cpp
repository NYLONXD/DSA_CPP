#include <iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5,6};
    int target = 4;
    int n = sizeof(arr)/sizeof(arr[0]);
    int left = 0, right = n-1;
    int mid = (left+right)/2;

    while(left<=right){
        if(arr[mid]==target){
            cout<<"Element found at index: "<<mid<<endl;
            return 0;
        }
        else if(arr[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
        mid=(left+right)/2;
    }
}