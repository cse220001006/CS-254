#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
long long a[N][N], b[N][N], c[N][N];

void multiply(int rowa, int cola, int rowb, int colb)
{
    for (int i = 0; i < rowa; i++)
    {
        for (int j = 0; j < colb; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < cola; k++)
            {
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
}

int main(){
    int rowa, cola, rowb, colb; cin >> rowa >> cola >> rowb >> colb;
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
    multiply(rowa, cola, rowb, colb);
    for(int i = 0; i < rowa; i++){
        for(int j = 0; j < colb; j++){
            cout << c[i][j] << " ";
        }
        cout << '\n';
    }
}
