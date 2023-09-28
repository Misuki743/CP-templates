#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef vector<int> vi;
using vl = vector<ll>;

const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

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

typedef vector<ll> vl;
void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, modpow(root, mod >> s)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
}
vl conv(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	int inv = modpow(n, mod - 2);
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}

vl inv(vl v, int k) {
  assert(!v.empty() and v[0] != 0);
  vl q(1, modpow(v[0], mod - 2));
  for(int i = 1; (1 << (i - 1)) < k; i++) {
    vl p(1 << i, 0);
    copy(v.begin(), v.begin() + min(1 << i, (int)size(v)), p.begin());
    vl r = conv(p, q);
    for(ll &x : r) x = (-x + mod) % mod;
    r[0] = (r[0] + 2) % mod;
    q = conv(q, r);
    q.resize(1 << i, 0);
  }
  q.resize(k);
  return q;
}

vl deriv(vl v) {
  assert(!v.empty());
  vl p(ssize(v) - 1);
  for(int i = 1; i < ssize(v); i++)
    p[i - 1] = v[i] * i % mod;
  return p;
}

vl integr(vl v) {
  vl inv(ssize(v) + 1);
  inv[1] = 1;
  for(int i = 2; i < ssize(inv); i++)
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  vl p(ssize(v) + 1, 0);
  for(int i = 0; i < ssize(v); i++)
    p[i + 1] = v[i] * inv[i + 1] % mod;
  return p;
}

vl log(vl v, int k) {
  assert(!v.empty() and v[0] == 1);
  vl p = conv(deriv(v), inv(v, k));
  p.resize(k - 1, 0);
  return integr(p);
}

vl exp(vl v, int k) {
  assert(!v.empty() and v[0] == 0);
  vl q(1, 1);
  for(int i = 1; (1 << (i - 1)) < k; i++) {
    vl p(1 << i, 0);
    copy(v.begin(), v.begin() + min(1 << i, (int)size(v)), p.begin());
    vl r = p;
    r[0] = (r[0] + 1) % mod;
    for(int j = 0; ll x : log(q, 1 << i)) r[j] = (r[j] - x + mod) % mod, j++;
    q = conv(q, r);
    q.resize(1 << i, 0);
  }
  q.resize(k);
  return q;
}

vl pow(vl v, ll idx, int k) {
  if (idx == 0) {
    vl p(k, 0);
    p[0] = 1;
    return p;
  }
  for(int i = 0; i < ssize(v) and i * idx < k; i++) {
    if (v[i] != 0) {
      ll inv = modpow(v[i], mod - 2);
      vl p(ssize(v) - i);
      for(int j = i; j < ssize(v); j++)
        p[j - i] = v[j] * inv % mod;
      p = log(p, k);
      for(ll &x : p)
        x = idx % mod * x % mod;
      p = exp(p, k);
      vl q(k, 0);
      ll pow = modpow(v[i], idx);
      for(int j = 0; i * idx + j < k; j++)
        q[i * idx + j] = p[j] * pow % mod;
      return q;
    }
  }
  return vl(k, 0);
}

vl sqrt(vl v, int k) {
  assert(!v.empty());
  if (v[0] == 0) {
    for(int i = 1; i < ssize(v); i++) {
      if (v[i] != 0) {
        if (i & 1) return {};
        if (i / 2 >= k) break;
        vl q = sqrt(vl(v.begin() + i, v.end()), k - i / 2);
        if (q.empty()) return {};
        q.resize(k, 0);
        ranges::rotate(q, q.begin() + k - i / 2);
        return q;
      }
    }
    return vl(k, 0);
  }

  ll sqr = sqrt(v[0], mod), inv2 = modpow(2, mod - 2);
  if (sqr == -1) return {};
  vl q(1, sqr);
  for(int i = 1; (1 << (i - 1)) < k; i++) {
    vl p(1 << i, 0);
    copy(v.begin(), v.begin() + min(1 << i, (int)size(v)), p.begin());
    vl r = conv(p, inv(q, 1 << i));
    for(int j = 0; ll x : q)
      r[j] = (r[j] + x) % mod, j++;
    for(ll &x : r)
      x = x * inv2 % mod;
    r.resize(1 << i);
    r.swap(q);
  }
  q.resize(k);
  return q;
}
