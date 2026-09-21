#include <iostream>
using namespace std;

int main() {
    int n, m;

    cout << "Enter rows and columns: ";
    cin >> n >> m;

    int arr1[n][m];
    int arr2[n][m];
    int result[n][m];

    
    cout << "Enter first matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr1[i][j];
        }
    }

    cout << "Enter second matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr2[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    cout << "Result:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}