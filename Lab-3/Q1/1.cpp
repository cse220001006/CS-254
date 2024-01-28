#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrix_multiply_dc(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rows_A = A.size();
    int cols_A = A[0].size();
    int cols_B = B[0].size();
    if (cols_A == 1) {
        vector<vector<int>> result(rows_A, vector<int>(cols_B, 0));
        for(int i = 0; i < rows_A; i++){
            for(int j = 0; j < cols_B; j++){
                result[i][j] = A[i][0]*B[0][j];
            }
        }
        return result;
    }
    int mid = cols_A / 2;
    vector<vector<int>> A11(rows_A, vector<int>(mid, 0));
    vector<vector<int>> A12(rows_A, vector<int>(cols_A - mid, 0));
    vector<vector<int>> B11(mid, vector<int>(cols_B, 0));
    vector<vector<int>> B12(cols_A - mid, vector<int>(cols_B, 0));

    for (int i = 0; i < rows_A; ++i) {
        for (int j = 0; j < mid; ++j) {
            A11[i][j] = A[i][j];
        }
    }
    for (int i = 0; i < rows_A; ++i) {
        for (int j = 0; j < cols_A-mid; ++j) {
            A12[i][j] = A[i][j+mid];
        }
    }
    for (int i = 0; i < mid; ++i) {
        for (int j = 0; j < cols_B; ++j) {
            B11[i][j] = B[i][j];
        }
    }
    for (int i = 0; i < cols_A-mid; ++i) {
        for (int j = 0; j < cols_B; ++j) {
            B12[i][j] = B[i + mid][j];
        }
    }

    vector<vector<int>> P1 = matrix_multiply_dc(A11, B11);
    vector<vector<int>> P2 = matrix_multiply_dc(A12, B12);
    vector<vector<int>> result(rows_A, vector<int>(cols_B, 0));

    for (int i = 0; i < rows_A; ++i) {
        for (int j = 0; j < cols_B; ++j) {
            result[i][j] = P1[i][j] + P2[i][j];
        }
    }

    return result;
}

int main() {
    int rowa, cola, rowb, colb; cin >> rowa >> cola >> rowb >> colb;
    vector<vector<int>>a(rowa, vector<int>(cola, 0));
    vector<vector<int>>b(rowb, vector<int>(colb, 0));
    for(int i = 0; i < rowa; i++){
        for(int j = 0; j < cola; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < rowb; i++){
        for(int j = 0; j < colb; j++){
            cin >> b[i][j];
        }
    }
    vector<vector<int>> result = matrix_multiply_dc(a, b);
    cout << "Matrix C: " << endl;
    for(int i = 0; i < rowa; i++){
        for(int j = 0; j < colb; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
