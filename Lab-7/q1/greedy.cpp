#include<bits/stdc++.h>
using namespace std; 

int main()
{
    freopen("input.txt","r",stdin); 
    freopen("greedy_output.txt","w",stdout); 

    int n; cin>>n; 
    vector<int> weight(n), value(n); 
    for(int i = 0; i < n; i++)
        cin >> weight[i]; 
    for(int i = 0; i < n; i++)
        cin >> value[i]; 
    int w; cin>>w; 

    auto comparator = [&](int item1, int item2)
    {
        double ratio1 = static_cast<double>(value[item1]) / weight[item1];
        double ratio2 = static_cast<double>(value[item2]) / weight[item2];
        return ratio1 < ratio2; 
    };

    priority_queue<int, vector<int>, decltype(comparator)> pq(comparator); 
    
    for(int i = 0; i < n; i++)
        pq.push(i); 

    long long max_value = 0; 
    vector<int> items; 
    while(!pq.empty())
    {
        auto item = pq.top(); 
        pq.pop(); 
        if(w >= weight[item])
        {
            w -= weight[item]; 
            max_value += value[item]; 
            items.push_back(item); 
        }
    }
    
    cout<<"Items: "; 
    for(int item : items) cout<<item + 1<<" "; 
    cout<<"\nMax value: "<<max_value; 
}