---
title: DSU
documentation_of: ../../ds/DSU/DSU.cpp
---

## constructor

`DSU(int n)`: create a standard disjoint set without additional data attacted

`DSU(vector<T> init, F f(T &larger_set, T &smaller_set) -> void)`: create a disjoint set where i-th set is attached with init[i]. when calling merge, data would be merged from smaller set to larger set using function F.

## example usage:

standard DSU: https://judge.yosupo.jp/submission/349238
DSU attach with $O(1)$ data: https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/submission/360830642
DSU attach with $O(size)$ data and use small-to-large style merge: https://codeforces.com/contest/600/submission/360850419
