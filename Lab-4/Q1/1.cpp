#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    int n; cin >> n;
    ordered_set s;
    long long inv = 0;
    while(n--){
        int x; cin >> x;
        inv += s.size()-s.order_of_key(x);
        s.insert(x);
    }
    cout << "Number of inversions are: " << inv << endl;
    return 0;
}
