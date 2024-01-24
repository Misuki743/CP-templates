//source: KACTL
//note: inv calculate modulo inverse of r mod m where gcd(r, m) = 1

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

ll inv(ll r, ll m) {
  ll x, y;
  ll gcd = euclid(r, m, x, y);
  assert(gcd == 1);
  return (x % m + m) % m;
}
