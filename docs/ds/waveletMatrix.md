---
title: ds/waveletMatrix.cpp
documentation_of: ../../ds/waveletMatrix.cpp
---

## usage

- `waveletMatrix<T, mxBit>(init)` construct WM using init, whose value ranges from $0$ to $2^{\text{mxBit} + 1} - 1$, $O(n \cdot mxBit)$
- `kth(l, r, k)` return k-th smallest number in range $[l, r)$, $O(mxBit)$
- `rectQuery(l, r, d, u)` return number of elements with value in $[d, u)$ whose position in $[l, r)$, $O(mxBit)$
