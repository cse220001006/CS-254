#include<bits/stdc++.h>
using namespace std;
 
struct Job
{
    string id;
    int deadLine, profit;
};
 
struct DisjointSet
{
    vector<int> parent; 
    void init(int sz)
    {
        parent.assign(sz+1,0); 
        for(int i = 0; i <= sz; i++)
            parent[i] = i; 
    }
    int find(int s)
    {
        if (s == parent[s])
            return s;
        return parent[s] = find(parent[s]);
    }
    void merge(int u, int v)
    {
        parent[v] = u;
    }
};

int findMaxDeadline(struct Job arr[], int n)
{
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
        ans = max(ans, arr[i].deadLine);
    return ans;
}
 
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    int n; cin>>n;
    vector<Job> jobs(n); 
    int maxDeadLine = 0;  
    for(auto &j : jobs)
    {
        cin>>j.id; 
        cin>>j.deadLine; 
        cin>>j.profit; 
        maxDeadLine = max(j.deadLine,maxDeadLine); 
    }
    DisjointSet DSU;
    DSU.init(1 + maxDeadLine); 
    sort(jobs.begin(),jobs.end(),[](auto job1,auto job2)
    {
        return job1.profit > job2.profit; 
    }); 
    long long total = 0; 
    for(int i = 0; i < n; i++)
    {
        int slot = DSU.find(jobs[i].deadLine); 
        if(slot > 0)
        {
            total += jobs[i].profit; 
            DSU.merge(DSU.find(slot - 1),slot); 
            cout<<jobs[i].id<<" "; 
        }
    }
    cout<<"\nProfit: "<<total<<"\n";
}
