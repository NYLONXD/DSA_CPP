#include <iostream>
using namespace std;

int arr[4][3] = {
    {0, 0, 3},
    {0, 0, 0},
    {4, 0, 0},
    {0, 5, 0}
};

int t_arr[3][4];
int mul[4][4];

int main()
{
    cout << "Original Array: " << endl;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //Transpose//
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            t_arr[i][j] = arr[j][i];
        }
    }

    cout << "Transpose Matrix: " << endl;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << t_arr[i][j] << " ";
        }
        cout << endl;
    }

    //Multiplication//
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            mul[i][j] = 0;

            for(int k = 0; k < 3; k++)
            {
                mul[i][j] += arr[i][k] * t_arr[k][j];
            }
        }
    }

    cout << "Multiplied Array: " << endl;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout << mul[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}