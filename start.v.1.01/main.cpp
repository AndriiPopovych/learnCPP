#include <iostream>
#include <typeinfo>

using namespace std;

int a;


int arr[2][2] = {
        {1, 2},
        {2, 3}
};


int** getMinor(int** a, int n, int row, int col) {
    int** result = 0;
    result = new int*[n-1];
    int _i = 0;
    int _j = 0;
    for (int i = 0; i < n; i++) {
        if (i != row) {
            result[_i] = new int[n-1];
            _j = 0;
            for (int j = 0; j < n; j++) {
                if (j != col) {
                    result[_i][_j] = a[i][j];
                    _j++;
                }
            }
            _i++;
        }
    }
//    printArr(result);
//    cout << "opa" << endl;

    return result;
}
void printArr(int a[][2], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j];
        }
        cout << endl;
    }
}

int calcDeterminant(int** a, int n) {
    int determinant = 0;
    if (n == 2) {
        determinant = a[0][0]*a[1][1] - a[0][1]*a[1][0];
    }
    else {
        for (int i = 0; i < n; i++) {
            if (i%2 == 0) {
                determinant += a[0][i]*calcDeterminant(getMinor(a, n, 0, i), n-1);
            }
            else {
                determinant -= a[0][i]*calcDeterminant(getMinor(a, n, 0, i), n-1);
            }
        }
    }
    return determinant;
}

int main() {

    int** result = 0;
    result = new int*[3];
    result[0] = new int[3] {1,2, 3};
    result[1] = new int[3] {4,2, 3};
    result[2] = new int[3] {4,5, 7};

    cout << calcDeterminant(result, 3) << endl;
    return 0;
}
