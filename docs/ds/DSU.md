---
title: ds/DSU/DSU.cpp
documentation_of: ../../ds/DSU/DSU.cpp
---

## constructor

`DSU(int n)`: create a disjoint set of size $\text{n}$ without additional data attacted

`DSU(vector<T> init, F f(T &larger_set, T &smaller_set) -> void)`: create a disjoint set where $\text{i}$-th set is attached with $\text{init[i]}$. when calling merge, data would be merged from smaller set to larger set using function $\text{f}$.

## example usage:

standard DSU: https://judge.yosupo.jp/submission/349238

DSU attach with $O(1)$ data: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/submission/360830642

DSU attach with $O(\text{size})$ data and use small-to-large style merge: https://codeforces.com/contest/600/submission/360850419
