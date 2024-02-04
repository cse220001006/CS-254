#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
int arr[N];

int main() {
    int n, k; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    cin >> k;
    cout << "Kth largest element is: " << arr[n-k] << endl;
    return 0;
}
