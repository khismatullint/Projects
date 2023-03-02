n, a, b, w, h = map(int, input().split())
l = 0
r = max(h, w)
while(r-l>1):
    d = (l+r) // 2
    cnt = (h // (a+2*d)) * (w //(b+2*d))
    if (cnt < n):
        r=d
    else:
        l=d
ans = l
l = 0
r = max(h, w)
while(r-l>1):
    d = (l+r) // 2
    cnt = (h // (b+2*d)) * (w //(a+2*d))
    if (cnt <= n):
        r=d
    else:
        l=d
print(max(ans, l))