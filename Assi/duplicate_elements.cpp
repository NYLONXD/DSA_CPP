#include <iostream>
using namespace std;

int main() {
    int arr[7] = {1,1,4,2,4,5,2};

    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 7; j++) {
            if (arr[i] == arr[j]) {
          
                for (int k=j;k<7-1;k++) {
                    arr[k] = arr[k + 1];
                }
                7-1;   
                j--;   
            }
        }
    }

    cout << "Array after removing duplicates:\n";
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}