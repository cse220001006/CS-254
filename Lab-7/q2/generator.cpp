#include<bits/stdc++.h>
using namespace std;

const int lim = 1e5; 
const int inf = 1e9; 

int main()
{
    freopen("input.txt", "w", stdout); 
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> distrib(0, lim);
    uniform_int_distribution<> distrib1(0, inf);
    cout<<lim<<"\n"; 
    for(int i = 0; i < lim; i++)
    {
        cout<<i+1<<" "<<distrib(rng)<<" "<<distrib1(rng)<<"\n"; 
    }
}