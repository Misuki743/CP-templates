---
title: treap
documentation_of: ../../ds/treap.cpp
---

## usage

- `build(init)` use init to build a treap, return root of the treap, $O(\text{size of init})$
- `split(v, x, l, r)` split treap with root $v$ into first $x$ nodes(-> $l$) and last (size of $v$ - $x$) nodes(-> $r$), $O(\lg \text{ size of }v)$
- `merge(l, r)` merge two treap into one, return the root, $O(\lg \text{ size of }l + \lg \text{ size of }r)$
- `modify(root, l, r, x, rev)` put tag $x$ on root's $[l, r)$, the monoid should be commutative if reverse is used, $O(\lg \text{ size of root})$
- `query(root, l, r)` query the result of root's $[l, r)$, $O(\lg \text{ size of root})$
- `insert(root, i, x)` insert $x$ before i-th element of root, $O(\lg \text{ size of root})$
- `erase(root, i)` erase i-th element of root, $O(\lg \text{ size of root})$
