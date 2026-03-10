//decompose {Ax + B mod M, 0 <= x < N} into O(sqrt(M)) APs
auto AP_sqrt_heuristic(ll A, ll B, ll N, ll M) {
  assert(A < M and B < M and N <= M);
  ll S = sqrtl(M);
  while(S * S <= M) S++;

  struct AP { ll A, B, N; };
  vc<AP> sol;
  if (N <= S) {
    for(ll i = 0, y = B; i < N; i++, y = (y + A >= M ? y + A - M : y + A))
      sol.eb(0, y, 1);
    return sol;
  }

  auto get = [&](ll n) { return (A * n + B) % M; };

  vll id(S, -1);
  for(ll j = 0, y = B; ; j++, y = (y + A >= M ? y + A - M : y + A)) {
    if (id[y / S] == -1) {
      id[y / S] = j;
    } else {
      ll D = j - id[y / S];
      ll A2 = A * D % M;
      if (A2 > M / 2) A2 -= M;
      for(ll i = id[y / S]; i < j; i++) {
        for(ll k = i, B2 = get(k); k < N; B2 = get(k)) {
          ll NMX = ceilDiv(N - k, D);
          ll N2 = [&]() {
            if (A2 > 0) return ceilDiv(M - B2, A2);
            else if (A2 < 0) return ceilDiv(-1ll - B2, A2);
            else return N;
          }();
          chmin(N2, NMX);
          sol.eb(A2, B2, N2);
          k += N2 * D;
        }
      }
      for(ll i = 0, B2 = B; i < id[y / S]; i++, B2 = (B2 + A >= M ? B2 + A - M : B2 + A))
        sol.eb(0, B2, 1);
      break;
    }
  }

  return sol;
}
