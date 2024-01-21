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

void mergeSort(int a[], int l, int r) {
    if (r>l) {
        int mid = (r+l)/2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

int main() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array:";
    for (int num : arr) {
        cout << " " << num;
    }
    cout << endl;

    return 0;
}
