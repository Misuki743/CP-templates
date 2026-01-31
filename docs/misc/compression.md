---
title: misc/compression.cpp
documentation_of: ../../misc/compression.cpp
---

An std-like coordinate compression template

about some usage cases of projection, see `misc/rectangleSum.cpp`

## usage

#### constructors

- `compression(vector<T> &init)` initialize with coordinates in init
- `compression(int size = 0)` reserve space for later addition of coordinates, after finishing inserting coordinate, call precompute()

#### member functions

- `void precompute()` do coordinate compression and store result in `ord` and `val`
- `int lower_bound(T x)` find # of coordinates less than $x$
- `int size()` return # of coordinates
- `void mapping(rng &v, proj p = {})` replace coordinates in a range `v` with its compressed coordinates, projection is allowed to used so you can do e.g. mapping a certain entry of a `vector<array<T, sz>>`
- `void insert(rng &v, proj p = {})` insert coordinates in a range `v`, projection is allowed to used so you can do e.g. inserting certain entry of a `vector<array<T, sz>>`

