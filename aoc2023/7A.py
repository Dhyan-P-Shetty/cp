from functools import cache
from collections import defaultdict, deque
import math

def ints(s, split=' '):
    return [int(x) for x in s.split(split) if x]

def colon(s):
    return s.split(': ')[1]

def merge(l):
    return ''.join([str(x) for x in l])

digits = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
digmap = {}
for i, x in enumerate(digits):
    digmap[x] = i

lines = []
with open("in") as f:
    for a in f.read().splitlines():
        lines.append(a)
ln = len(lines)

value = 'AKQJT98765432'

def comp(s):
    ct = {}
    for k in s:
        if k not in ct:
            ct[k] = 0
        ct[k] += 1
    q = 1
    vv = list(ct.values())
    # tt = []
    # print(ct)
    # for a, b in ct.items():
    #     tt.append((b, -value.find(a)))
    # tt.sort(reverse=True)
    if 5 in vv:
        q = 7
    elif 4 in vv:
        q = 6
    elif 3 in vv and 2 in vv:
        q = 5
    elif 3 in vv:
        q = 4
    elif 2 in vv:
        c = 0
        for x in vv:
            if x == 2:
                c += 1
        if c == 2:
            q = 3
        else:
            q = 2
    # ss = ''.join(sorted([c for c in s], reverse=True))
    # print(s, q, tt)
    return (q, [-value.find(x) for x in s])

ll = [l.split(' ') for l in lines]
ll.sort(key=lambda x:comp(x[0]))
ret = 0
for x in ll:
    comp(x[0])
for i in range(ln):
    ret += (i+1) * int(ll[i][1])
print(ret)