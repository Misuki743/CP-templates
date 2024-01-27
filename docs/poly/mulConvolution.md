---
title: mulConvolution
documentation_of: ../../poly/mulConvolution.cpp
---

## theory

Consider writing $i, j$ as power of some primitive root $r$ i.e. $(i = r^{i'}, j = r^{j'}, k = r^{k'})$, then $ij \equiv k \text{ mod } P\leftrightarrow r^{(i'+j')} \equiv r^{k'} \text{ mod } P \leftrightarrow i' + j' \equiv k' \text{ mod } (P - 1)$
reduce the problem to the normal convolution and can be solved by NTT.

## usage

Given prime $P$ and two polynomial $f(x), g(x)$, compute $h(x)\text{ s.t. } h_k = \sum\limits_{ij \equiv k \text{ mod } P} f_ig_j$ in $O(P\lg P)$

- `transform(f)` map $f_i$ to $f_{i'}$ where $r^{i'} \equiv i \text{ mod } P$
- `invTransform(f)` map $f_{i'}$ back to $f_i$
- `mulConv(f, g, conv)` compute $h(x)\text{ s.t. } h_k = \sum\limits_{ij \equiv k \text{ mod } P} f_ig_j$

