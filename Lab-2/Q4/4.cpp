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
    int ans = 0;
    int k = n/2;
    if(n%2==0){
        ans = (arr[k-1]+arr[k])/2;
    }
    else{
        ans = arr[k];
    }
    cout << "Median element of array is: " << ans << endl;
    return 0;
}
