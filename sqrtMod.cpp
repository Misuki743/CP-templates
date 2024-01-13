/**
 * template name: sqrtMod
 * source: KACTL
 * verify: Library Checker - Sqrt Mod
 */

ll modpow(ll b, ll e, ll p) {
  ll ans = 1;
  for(; e; b = b * b % p, e /= 2)
    if (e & 1) ans = ans * b % p;
  return ans;
}

ll sqrt(ll a, ll p) {
	a %= p; if (a < 0) a += p;
	if (a == 0) return 0;
	//assert(modpow(a, (p-1)/2, p) == 1); // else no solution
  if (modpow(a, (p-1)/2, p) != 1) return -1;
	if (p % 4 == 3) return modpow(a, (p+1)/4, p);
	// a^(n+3)/8 or 2^(n+3)/8 * 2^(n-1)/4 works if p % 8 == 5
	ll s = p - 1, n = 2;
	int r = 0, m;
	while (s % 2 == 0)
		++r, s /= 2;
	/// find a non-square mod p
	while (modpow(n, (p - 1) / 2, p) != p - 1) ++n;
	ll x = modpow(a, (s + 1) / 2, p);
	ll b = modpow(a, s, p), g = modpow(n, s, p);
	for (;; r = m) {
		ll t = b;
		for (m = 0; m < r && t != 1; ++m)
			t = t * t % p;
		if (m == 0) return x;
		ll gs = modpow(g, 1LL << (r - m - 1), p);
		g = gs * gs % p;
		x = x * gs % p;
		b = b * g % p;
	}
}
