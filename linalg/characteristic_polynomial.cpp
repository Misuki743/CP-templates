template<class Mint>
array<Mint, 2> operator+(array<Mint, 2> a, array<Mint, 2> b) {
  return {a[0] + b[0], a[1] + b[1]};
}
template<class Mint>
array<Mint, 2> operator-(array<Mint, 2> a, array<Mint, 2> b) {
  return {a[0] - b[0], a[1] - b[1]};
}
template<class Mint>
array<Mint, 2> operator*(Mint m, array<Mint, 2> b) {
  return {m * b[0], m * b[1]};
}

template<class Mint>
vc<Mint> characteristic_polynomial(vvc<Mint> M) {
  if (M.empty()) return {1};
  assert(size(M) == size(M[0]));
  const int N = size(M);

  vc P(N, vc<array<Mint, 2>>(N));
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      P[i][j] = {-M[i][j], i == j};

  //reduce to lower Hessenberg Matrix
  for(int r = 0; r < N - 2; r++) {
    const int c = r + 1;
    int i = c;
    while(i < N and P[r][i][0] == 0) i++;
    if (i == N) continue;
    if (i > c) {
      P[i].swap(P[c]);
      for(int j = 0; j < N; j++)
        swap(P[j][i], P[j][c]);
    }
    Mint inv = P[r][c][0].inverse();
    for(int j = c + 1; j < N; j++) {
      Mint R = -inv * P[r][j][0];
      for(int k = 0; k < N; k++)
        P[k][j] = P[k][j] + R * P[k][c];
    }

    for(int j = r + 2; j < N; j++) {
      Mint R = -P[r + 1][j][1];
      for(int k = 0; k < N; k++)
        P[r + 1][k] = P[r + 1][k] + R * P[j][k];
    }
  }

  auto add = [&](vector<Mint> a, vector<Mint> b) {
    if (ssize(a) < ssize(b)) a.resize(size(b));
    for(int i = 0; i < ssize(b); i++)
      a[i] += b[i];
    return a;
  };
  auto mul = [&](vector<Mint> &a, array<Mint, 2> b) {
    vector<Mint> c(ssize(a) + 1);
    for(int i = 0; i < ssize(a); i++) {
      c[i] += a[i] * b[0];
      c[i + 1] += a[i] * b[1];
    }
    return c;
  };
  auto neg = [&](array<Mint, 2> a) { return array<Mint, 2>{-a[0], -a[1]}; };

  //DP
  vc dp(1, vc<Mint>{1});
  for(int i = 0; i < N - 1; i++) {
    vc<vc<Mint>> nxt(i + 2);
    for(int j = 0; j < ssize(dp); j++) {
      nxt[j] = add(nxt[j], mul(dp[j], P[i][i + 1]));
      nxt[i + 1] = add(nxt[i + 1], mul(dp[j], (i - j) % 2 ? neg(P[i][j]) : P[i][j]));
    }
    dp.swap(nxt);
  }

  vc<Mint> C = {0};
  for(int j = 0; j < N; j++)
    C = add(C, mul(dp[j], (N - 1 - j) % 2 ? neg(P[N - 1][j]) : P[N - 1][j]));

  return C;
}
