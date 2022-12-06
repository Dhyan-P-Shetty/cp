from collections import defaultdict

with open("in") as f:
    d = defaultdict(int)
    for x in f.read().splitlines():
        for i in range(len(x)):
            if i >= 14:
                d[x[i-14]] -= 1
                if d[x[i-14]] == 0:
                    del d[x[i-14]]
            d[x[i]] += 1
            if len(d) == 14:
                print(i+1)
                break