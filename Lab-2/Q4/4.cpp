#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
int arr[N];

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    cout << "Median element of array is: " << arr[n/2] << endl;
    return 0;
}
