// Problem: https://codeforces.com/problemset/problem/1400/E
#include<bits/stdc++.h>
using namespace std;
#define print(x) cout << x << endl
#define input(x) cin >> x

vector<int> a;

int solve(int l, int r) {
    if (l > r)
        return 0;
    int m, min_val;
    
    m = -1;
    // get min value from array a
    min_val = *min_element(a.begin() + l, a.begin() + r + 1);
    
    for (int i=l; i<=r; i++) {
        a[i] -= min_val;
        if (a[i] == 0)
            m = i;    
    }

    if (m == -1) {
        return 1 + solve(l, r);
    }

    return min(solve(l, m - 1) + solve(m + 1, r) + min_val, r - l + 1);
}

int main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    input(n);
    a.resize(n);
    for (int i=0; i<n; i++)
        input(a[i]);
    cout << solve(0, n - 1) << endl;

    return 0;
}
