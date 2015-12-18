#!/user/bin/env python
# -*- coding: utf-8 -*-

N = input()
ans = 1
for i in range(2, N+1):
    ans *= i
    while ans % 10 == 0:
        ans /= 10
    ans %= 100000000000
print int(str(ans)[-9:])
