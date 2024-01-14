#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int V = 4;
    int graph[][V] = { { 0, 20, 42, 35},
                       { 20, 0, 30, 34},
                       { 42, 30, 0, 12},
                       { 35, 34, 12, 0 } };
    int s = 0;
    vector<int> vertex;
    for (int i = 0; i < V; i++){
            vertex.push_back(i);
    }
    int min_path = INT_MAX;
    do {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
        min_path = min(min_path, current_pathweight);
 
    } while (next_permutation(vertex.begin(), vertex.end()));
    cout << min_path << '\n';
}