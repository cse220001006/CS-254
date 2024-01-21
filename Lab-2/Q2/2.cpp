#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]){
            i++;
        }
        else {
            int val = a[j];
            int it = j;
            while(it > i){
                a[it] = a[it-1];
                it--;
            }
            a[i] = val;
            i++, j++, mid++;
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    merge(arr, 0, m-1, n-1);
    cout << "Sorted array: " << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
