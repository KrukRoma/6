#include <iostream>
using namespace std;

int main()
{
    //1
    int a;
    cout << "Enter a number: ";
    cin >> a;

    int arrss[3][3];

    arrss[0][0] = a;
    for (int i = 1; i < 3; i++)
    {
        arrss[0][i] = arrss[0][i - 1] * 2;
    }

    for (int i = 1; i < 3; i++)
    {
        arrss[i][0] = arrss[i - 1][2] * 2;
        for (int j = 1; j < 3; j++)
        {
            arrss[i][j] = arrss[i][j - 1] * 2;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arrss[i][j] << " ";
        }
        cout << endl;
    }

    //2
    int b;
    cout << "Enter a number: ";
    cin >> b;

    int arrs[3][3];

    arrs[0][0] = b;
    for (int i = 1; i < 3; i++)
    {
        arrs[0][i] = arrs[0][i - 1] + 1;
    }

    for (int i = 1; i < 3; i++)
    {
        arrs[i][0] = arrs[i - 1][2] + 1;
        for (int j = 1; j < 3; j++)
        {
            arrs[i][j] = arrs[i][j - 1] + 1;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arrs[i][j] << " ";
        }
        cout << endl;
    }

    //3
    const int ROWS = 2;
    const int COLS = 6;
    int arr[ROWS][COLS];

    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = rand() % 10;
        }
    }

    cout << "Initial Array:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int shifts;
    char direction;
    cout << "Enter number of shifts: ";
    cin >> shifts;
    cout << "Choose a side (l - left, r - right, u - up, d - down): ";
    cin >> direction;

    int temp[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            temp[i][j] = arr[i][j];
        }
    }

    if (direction == 'l') {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                arr[i][j] = temp[i][(j + shifts) % COLS];
            }
        }
    }
    else if (direction == 'r') {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                arr[i][j] = temp[i][(j - shifts + COLS) % COLS];
            }
        }
    }
    else if (direction == 'u') {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                arr[i][j] = temp[(i + shifts) % ROWS][j];
            }
        }
    }
    else if (direction == 'd') {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                arr[i][j] = temp[(i - shifts + ROWS) % ROWS][j];
            }
        }
    }

    cout << "Shifted Array:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
