#include <bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot){
            i++;
        }
        while (arr[j] > pivot){
            j--;
        }
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
            }
      };
      if (left < j) quickSort(arr, left, j);
      if (i < right) quickSort(arr, i, right);
}

int main() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted array:";
    for (int num : arr) {
        cout << " " << num;
    }
    cout << endl;

    return 0;
}
