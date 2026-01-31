---
title: tree/auxiliaryTree.cpp
documentation_of: ../../tree/auxiliaryTree.cpp
---

## usage

`virtualTree(g, c)`: build virtual tree using $g$(undirected), and partition this tree according to label sequence $c$, return the result forest where $[0, n)$ is the original nodes, and $[n, 2n - 1)$ is virtual nodes, and return the root sequence of respective labels, $-1$ if label not exist. label sequence should be in $[0, n)^n$, $O(n\lg n)$
