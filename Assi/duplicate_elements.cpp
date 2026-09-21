#include <iostream>
using namespace std;

int main() {
    int n = 6;
    int arr[n] = {1, 2, 2, 3, 2, 1};

    int seen[100] = {0};
    int size = 0;

    for (int i = 0; i < n; i++) {
        if (seen[arr[i]] == 0) {
            seen[arr[i]] = 1;
            arr[size] = arr[i];
            size++;
        }
    }

    return 0;
}