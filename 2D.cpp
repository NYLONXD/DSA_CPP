#include <iostream>
using namespace std;
int main(){
    int n;
    int m;
    cout<<"enter the number in 2d array";
    cin>>n>>m;
    int arr1[n][m];
    int arr2[n][m];
    int result[n][m];
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin>>arr1[i][j];
        }
    }
    for(int i =0;i<n;i++){
        for(int j = 0; j<m;j++){
            cin>>arr2[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            result[i][j]=arr1[i][j]+arr2[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){

            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
