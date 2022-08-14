# Problem: https://codeforces.com/problemset/problem/1400/E
n = int(input())
a = list(map(int, input().split()))

def solve(l, r):
    if l > r:
        return 0
    # we will apply type 1 operation (min a_i) times
    min_val = min(a[l:r+1])
    m = -1
    for i in range(l, r+1):
        a[i] -= min_val
        if a[i] == 0:
            m = i
    if m == -1:
        # we can't split, so we have to apply type 2 operation
        return 1 + solve(l, r)
    return min(solve(l, m-1) + solve(m+1, r) + min_val, r-l+1)

print(solve(0, n-1))