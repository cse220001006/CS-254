#include <bits/stdc++.h>
using namespace std;

const int N = 2e7+10;
int a[N], b[N];
int c[N];
unordered_map<int, int>mp1, mp2;

void merge_sort(int m, int n, int type){
    int cur = 0;
    int idx1 = 0, idx2 = 0;
    while(idx1 < m && idx2 < n){
        if(a[idx1] < b[idx2]){
            int val = 0;
            if(type == 1){
                val = mp1[a[idx1]]+mp2[a[idx1]];
            }
            else if(type == 2){
                val = max(mp1[a[idx1]], mp2[a[idx1]]);
            }
            else{
                val = min(mp1[a[idx1]], mp2[a[idx1]]);
            }
            mp1[a[idx1]] = 0;
            mp2[a[idx1]] = 0;
            while(val--){
                c[cur] = a[idx1];
                cur++;
            }
            idx1++;
        }
        else{
            int val = 0;
            if(type == 1){
                val = mp1[b[idx2]]+mp2[b[idx2]];
            }
            else if(type == 2){
                val = max(mp1[b[idx2]], mp2[b[idx2]]);
            }
            else{
                val = min(mp1[b[idx2]], mp2[b[idx2]]);
            }
            mp1[b[idx2]] = 0;
            mp2[b[idx2]] = 0;
            while(val--){
                c[cur] = b[idx2];
                cur++;
            }
            idx2++;
        }
    }
    while(idx1 < m){
        int val = 0;
        if(type == 1){
            val = mp1[a[idx1]]+mp2[a[idx1]];
        }
        else if(type == 2){
            val = max(mp1[a[idx1]], mp2[a[idx1]]);
        }
        else{
            val = min(mp1[a[idx1]], mp2[a[idx1]]);
        }
        mp1[a[idx1]] = 0;
        mp2[a[idx1]] = 0;
        while(val--){
            c[cur] = a[idx1];
            cur++;
        }
        idx1++;
    }
    while(idx2 < n){
        int val = 0;
        if(type == 1){
            val = mp1[b[idx2]]+mp2[b[idx2]];
        }
        else if(type == 2){
            val = max(mp1[b[idx2]], mp2[b[idx2]]);
        }
        else{
            val = min(mp1[b[idx2]], mp2[b[idx2]]);
        }
        mp1[b[idx2]] = 0;
        mp2[b[idx2]] = 0;
        while(val--){
            c[cur] = b[idx2];
            cur++;
        }
        idx2++;
    }
    for(int i = 0; i < cur; i++){
        cout << c[i]  << " ";
    }
    cout << '\n';
}

void calc(int m, int n){
    for(int i = 0; i < m; i++){
        mp1[a[i]]++;
    }
    for(int i = 0; i < n; i++){
        mp2[b[i]]++;
    }
}

int main(){
    int m, n; cin >> m >> n;
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    calc(m, n);
    cout << "sorted array by merging A and B: " << endl;
    merge_sort(m, n, 1);
    cout << endl;
    calc(m, n);
    cout << "sorted array for A ∪ B: " << endl;
    merge_sort(m, n, 2);
    cout << endl;
    calc(m, n);
    cout << "sorted array for A ∩ B: " << endl;
    merge_sort(m, n, 3);
}