def ri():
    return int(input())

def li():
    return list(map(int, input().split()))

def solve(l, r, depth):
    if l > r: 
        return
    #  get max in list a
    max_val = max(a[l:r+1])
    index = a.index(max_val)
    depths[index] = depth
    solve(l, index-1, depth+1)
    solve(index+1, r, depth+1)
 
for _ in range(ri()):
    n = ri()
    a = li()
    depths = [0]*n
    solve(0, n-1, 0)
    print(*depths)