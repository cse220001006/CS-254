#include<bits/stdc++.h>
using namespace std; 

int main()
{
    freopen("input.txt","r",stdin); 
    freopen("dp_output.txt","w",stdout); 

    long long n; cin>>n; 
    vector<int> weight(n), value(n); 
    for(int i = 0; i < n; i++)
        cin >> weight[i]; 
    for(int i = 0; i < n; i++)
        cin >> value[i]; 
    int w; cin>>w; 

    vector<vector<long long>> dp(n + 1, vector<long long>(w+1,0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = w; j >= 0; j--)
        {
            dp[i][j] = dp[i-1][j]; 
            if(j >= weight[i-1])
                dp[i][j] = max(dp[i][j], value[i-1] + dp[i-1][j - weight[i-1]]);  
        }   
    }
    long long res = dp[n][w]; 
    cout<<"Max Value: "<<res<<"\n"; 
    cout<<"Items: "; 
    for(int i = n; i > 0 && res > 0; i--)
    {     
        if (res == dp[i - 1][w])
            continue;    
        else  
        {
            cout<<i<<" "; 
            w -= weight[i-1]; 
            res -= value[i-1];              
        }
    }

}