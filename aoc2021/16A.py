from functools import cache
from collections import defaultdict, deque, Counter
import itertools
import heapq
import math

ret = 0
HEX = '0123456789ABCDEF'
s = ''
with open('in') as f:
    for i, l in enumerate(f.read().splitlines()):
        for c in l:
            idx = HEX.index(c)
            s += bin(idx)[2:]

print(s)

def f(l):
    global ret
    idx = l
    v = int(s[idx:idx+3], 2)
    idx += 3
    ret += v
    t = int(s[idx:idx+3], 2)
    idx += 3
    print(v, t)
    if t == 4:
        q = ''
        while 1:
            cur = s[idx:idx+5]
            idx += 5
            q += cur[1:]
            if cur[0] == '0':
                break
        return int(q, 2), idx
    i = int(s[idx], 2)
    idx += 1
    if i == 0:
        l = int(s[idx:idx+15], 2)
        idx += 15
        cur = idx
        rb = idx + l
        q = []
        while idx < rb:
            a, b = f(idx)
            q.append(a)
            idx = b
    else:
        l = int(s[idx:idx+11], 2)
        idx += 11
        q = []
        for _ in range(l):
            a, b = f(idx)
            q.append(a)
            idx = b
    return sum(q), idx

f(0)
print(ret)