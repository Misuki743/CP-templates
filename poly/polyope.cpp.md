---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/polyope.cpp\"\n//source: KACTL\n\n#define rep(i, a,\
    \ b) for(int i = a; i < (b); ++i)\n#define all(x) begin(x), end(x)\n#define sz(x)\
    \ (int)(x).size()\ntypedef vector<int> vi;\nusing vl = vector<ll>;\n\nconst ll\
    \ mod = (119 << 23) + 1, root = 62; // = 998244353\n// For p < 2^30 there is also\
    \ e.g. 5 << 25, 7 << 26, 479 << 21\n// and 483 << 21 (same root). The last two\
    \ are > 10^9.\n\nll modpow(ll b, ll e) {\n\tll ans = 1;\n\tfor (; e; b = b * b\
    \ % mod, e /= 2)\n\t\tif (e & 1) ans = ans * b % mod;\n\treturn ans;\n}\n\nll\
    \ modpow(ll b, ll e, ll p) {\n  ll ans = 1;\n  for(; e; b = b * b % p, e /= 2)\n\
    \    if (e & 1) ans = ans * b % p;\n  return ans;\n}\n\nll sqrt(ll a, ll p) {\n\
    \ta %= p; if (a < 0) a += p;\n\tif (a == 0) return 0;\n\t//assert(modpow(a, (p-1)/2,\
    \ p) == 1); // else no solution\n  if (modpow(a, (p-1)/2, p) != 1) return -1;\n\
    \tif (p % 4 == 3) return modpow(a, (p+1)/4, p);\n\t// a^(n+3)/8 or 2^(n+3)/8 *\
    \ 2^(n-1)/4 works if p % 8 == 5\n\tll s = p - 1, n = 2;\n\tint r = 0, m;\n\twhile\
    \ (s % 2 == 0)\n\t\t++r, s /= 2;\n\t/// find a non-square mod p\n\twhile (modpow(n,\
    \ (p - 1) / 2, p) != p - 1) ++n;\n\tll x = modpow(a, (s + 1) / 2, p);\n\tll b\
    \ = modpow(a, s, p), g = modpow(n, s, p);\n\tfor (;; r = m) {\n\t\tll t = b;\n\
    \t\tfor (m = 0; m < r && t != 1; ++m)\n\t\t\tt = t * t % p;\n\t\tif (m == 0) return\
    \ x;\n\t\tll gs = modpow(g, 1LL << (r - m - 1), p);\n\t\tg = gs * gs % p;\n\t\t\
    x = x * gs % p;\n\t\tb = b * g % p;\n\t}\n}\n\ntypedef vector<ll> vl;\nvoid ntt(vl\
    \ &a) {\n\tint n = sz(a), L = 31 - __builtin_clz(n);\n\tstatic vl rt(2, 1);\n\t\
    for (static int k = 2, s = 2; k < n; k *= 2, s++) {\n\t\trt.resize(n);\n\t\tll\
    \ z[] = {1, modpow(root, mod >> s)};\n\t\trep(i,k,2*k) rt[i] = rt[i / 2] * z[i\
    \ & 1] % mod;\n\t}\n\tvi rev(n);\n\trep(i,0,n) rev[i] = (rev[i / 2] | (i & 1)\
    \ << L) / 2;\n\trep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);\n\tfor (int\
    \ k = 1; k < n; k *= 2)\n\t\tfor (int i = 0; i < n; i += 2 * k) rep(j,0,k) {\n\
    \t\t\tll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];\n\t\t\ta[i + j +\
    \ k] = ai - z + (z > ai ? mod : 0);\n\t\t\tai += (ai + z >= mod ? z - mod : z);\n\
    \t\t}\n}\nvl conv(const vl &a, const vl &b) {\n\tif (a.empty() || b.empty()) return\
    \ {};\n\tint s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;\n\t\
    int inv = modpow(n, mod - 2);\n\tvl L(a), R(b), out(n);\n\tL.resize(n), R.resize(n);\n\
    \tntt(L), ntt(R);\n\trep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv\
    \ % mod;\n\tntt(out);\n\treturn {out.begin(), out.begin() + s};\n}\n\nvl inv(vl\
    \ v, int k) {\n  assert(!v.empty() and v[0] != 0);\n  vl q(1, modpow(v[0], mod\
    \ - 2));\n  for(int i = 1; (1 << (i - 1)) < k; i++) {\n    vl p(1 << i, 0);\n\
    \    copy(v.begin(), v.begin() + min(1 << i, (int)size(v)), p.begin());\n    vl\
    \ r = conv(p, q);\n    for(ll &x : r) x = (-x + mod) % mod;\n    r[0] = (r[0]\
    \ + 2) % mod;\n    q = conv(q, r);\n    q.resize(1 << i, 0);\n  }\n  q.resize(k);\n\
    \  return q;\n}\n\nvl deriv(vl v) {\n  assert(!v.empty());\n  vl p(ssize(v) -\
    \ 1);\n  for(int i = 1; i < ssize(v); i++)\n    p[i - 1] = v[i] * i % mod;\n \
    \ return p;\n}\n\nvl integr(vl v) {\n  vl inv(ssize(v) + 1);\n  inv[1] = 1;\n\
    \  for(int i = 2; i < ssize(inv); i++)\n    inv[i] = (mod - mod / i) * inv[mod\
    \ % i] % mod;\n  vl p(ssize(v) + 1, 0);\n  for(int i = 0; i < ssize(v); i++)\n\
    \    p[i + 1] = v[i] * inv[i + 1] % mod;\n  return p;\n}\n\nvl log(vl v, int k)\
    \ {\n  assert(!v.empty() and v[0] == 1);\n  vl p = conv(deriv(v), inv(v, k));\n\
    \  p.resize(k - 1, 0);\n  return integr(p);\n}\n\nvl exp(vl v, int k) {\n  assert(!v.empty()\
    \ and v[0] == 0);\n  vl q(1, 1);\n  for(int i = 1; (1 << (i - 1)) < k; i++) {\n\
    \    vl p(1 << i, 0);\n    copy(v.begin(), v.begin() + min(1 << i, (int)size(v)),\
    \ p.begin());\n    vl r = p;\n    r[0] = (r[0] + 1) % mod;\n    for(int j = 0;\
    \ ll x : log(q, 1 << i)) r[j] = (r[j] - x + mod) % mod, j++;\n    q = conv(q,\
    \ r);\n    q.resize(1 << i, 0);\n  }\n  q.resize(k);\n  return q;\n}\n\nvl pow(vl\
    \ v, ll idx, int k) {\n  if (idx == 0) {\n    vl p(k, 0);\n    p[0] = 1;\n   \
    \ return p;\n  }\n  for(int i = 0; i < ssize(v) and i * idx < k; i++) {\n    if\
    \ (v[i] != 0) {\n      ll inv = modpow(v[i], mod - 2);\n      vl p(ssize(v) -\
    \ i);\n      for(int j = i; j < ssize(v); j++)\n        p[j - i] = v[j] * inv\
    \ % mod;\n      p = log(p, k);\n      for(ll &x : p)\n        x = idx % mod *\
    \ x % mod;\n      p = exp(p, k);\n      vl q(k, 0);\n      ll pow = modpow(v[i],\
    \ idx);\n      for(int j = 0; i * idx + j < k; j++)\n        q[i * idx + j] =\
    \ p[j] * pow % mod;\n      return q;\n    }\n  }\n  return vl(k, 0);\n}\n\nvl\
    \ sqrt(vl v, int k) {\n  assert(!v.empty());\n  if (v[0] == 0) {\n    for(int\
    \ i = 1; i < ssize(v); i++) {\n      if (v[i] != 0) {\n        if (i & 1) return\
    \ {};\n        if (i / 2 >= k) break;\n        vl q = sqrt(vl(v.begin() + i, v.end()),\
    \ k - i / 2);\n        if (q.empty()) return {};\n        q.resize(k, 0);\n  \
    \      ranges::rotate(q, q.begin() + k - i / 2);\n        return q;\n      }\n\
    \    }\n    return vl(k, 0);\n  }\n\n  ll sqr = sqrt(v[0], mod), inv2 = modpow(2,\
    \ mod - 2);\n  if (sqr == -1) return {};\n  vl q(1, sqr);\n  for(int i = 1; (1\
    \ << (i - 1)) < k; i++) {\n    vl p(1 << i, 0);\n    copy(v.begin(), v.begin()\
    \ + min(1 << i, (int)size(v)), p.begin());\n    vl r = conv(p, inv(q, 1 << i));\n\
    \    for(int j = 0; ll x : q)\n      r[j] = (r[j] + x) % mod, j++;\n    for(ll\
    \ &x : r)\n      x = x * inv2 % mod;\n    r.resize(1 << i);\n    r.swap(q);\n\
    \  }\n  q.resize(k);\n  return q;\n}\n"
  code: "//source: KACTL\n\n#define rep(i, a, b) for(int i = a; i < (b); ++i)\n#define\
    \ all(x) begin(x), end(x)\n#define sz(x) (int)(x).size()\ntypedef vector<int>\
    \ vi;\nusing vl = vector<ll>;\n\nconst ll mod = (119 << 23) + 1, root = 62; //\
    \ = 998244353\n// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21\n\
    // and 483 << 21 (same root). The last two are > 10^9.\n\nll modpow(ll b, ll e)\
    \ {\n\tll ans = 1;\n\tfor (; e; b = b * b % mod, e /= 2)\n\t\tif (e & 1) ans =\
    \ ans * b % mod;\n\treturn ans;\n}\n\nll modpow(ll b, ll e, ll p) {\n  ll ans\
    \ = 1;\n  for(; e; b = b * b % p, e /= 2)\n    if (e & 1) ans = ans * b % p;\n\
    \  return ans;\n}\n\nll sqrt(ll a, ll p) {\n\ta %= p; if (a < 0) a += p;\n\tif\
    \ (a == 0) return 0;\n\t//assert(modpow(a, (p-1)/2, p) == 1); // else no solution\n\
    \  if (modpow(a, (p-1)/2, p) != 1) return -1;\n\tif (p % 4 == 3) return modpow(a,\
    \ (p+1)/4, p);\n\t// a^(n+3)/8 or 2^(n+3)/8 * 2^(n-1)/4 works if p % 8 == 5\n\t\
    ll s = p - 1, n = 2;\n\tint r = 0, m;\n\twhile (s % 2 == 0)\n\t\t++r, s /= 2;\n\
    \t/// find a non-square mod p\n\twhile (modpow(n, (p - 1) / 2, p) != p - 1) ++n;\n\
    \tll x = modpow(a, (s + 1) / 2, p);\n\tll b = modpow(a, s, p), g = modpow(n, s,\
    \ p);\n\tfor (;; r = m) {\n\t\tll t = b;\n\t\tfor (m = 0; m < r && t != 1; ++m)\n\
    \t\t\tt = t * t % p;\n\t\tif (m == 0) return x;\n\t\tll gs = modpow(g, 1LL <<\
    \ (r - m - 1), p);\n\t\tg = gs * gs % p;\n\t\tx = x * gs % p;\n\t\tb = b * g %\
    \ p;\n\t}\n}\n\ntypedef vector<ll> vl;\nvoid ntt(vl &a) {\n\tint n = sz(a), L\
    \ = 31 - __builtin_clz(n);\n\tstatic vl rt(2, 1);\n\tfor (static int k = 2, s\
    \ = 2; k < n; k *= 2, s++) {\n\t\trt.resize(n);\n\t\tll z[] = {1, modpow(root,\
    \ mod >> s)};\n\t\trep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;\n\t}\n\tvi\
    \ rev(n);\n\trep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;\n\trep(i,0,n)\
    \ if (i < rev[i]) swap(a[i], a[rev[i]]);\n\tfor (int k = 1; k < n; k *= 2)\n\t\
    \tfor (int i = 0; i < n; i += 2 * k) rep(j,0,k) {\n\t\t\tll z = rt[j + k] * a[i\
    \ + j + k] % mod, &ai = a[i + j];\n\t\t\ta[i + j + k] = ai - z + (z > ai ? mod\
    \ : 0);\n\t\t\tai += (ai + z >= mod ? z - mod : z);\n\t\t}\n}\nvl conv(const vl\
    \ &a, const vl &b) {\n\tif (a.empty() || b.empty()) return {};\n\tint s = sz(a)\
    \ + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;\n\tint inv = modpow(n, mod\
    \ - 2);\n\tvl L(a), R(b), out(n);\n\tL.resize(n), R.resize(n);\n\tntt(L), ntt(R);\n\
    \trep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;\n\tntt(out);\n\
    \treturn {out.begin(), out.begin() + s};\n}\n\nvl inv(vl v, int k) {\n  assert(!v.empty()\
    \ and v[0] != 0);\n  vl q(1, modpow(v[0], mod - 2));\n  for(int i = 1; (1 << (i\
    \ - 1)) < k; i++) {\n    vl p(1 << i, 0);\n    copy(v.begin(), v.begin() + min(1\
    \ << i, (int)size(v)), p.begin());\n    vl r = conv(p, q);\n    for(ll &x : r)\
    \ x = (-x + mod) % mod;\n    r[0] = (r[0] + 2) % mod;\n    q = conv(q, r);\n \
    \   q.resize(1 << i, 0);\n  }\n  q.resize(k);\n  return q;\n}\n\nvl deriv(vl v)\
    \ {\n  assert(!v.empty());\n  vl p(ssize(v) - 1);\n  for(int i = 1; i < ssize(v);\
    \ i++)\n    p[i - 1] = v[i] * i % mod;\n  return p;\n}\n\nvl integr(vl v) {\n\
    \  vl inv(ssize(v) + 1);\n  inv[1] = 1;\n  for(int i = 2; i < ssize(inv); i++)\n\
    \    inv[i] = (mod - mod / i) * inv[mod % i] % mod;\n  vl p(ssize(v) + 1, 0);\n\
    \  for(int i = 0; i < ssize(v); i++)\n    p[i + 1] = v[i] * inv[i + 1] % mod;\n\
    \  return p;\n}\n\nvl log(vl v, int k) {\n  assert(!v.empty() and v[0] == 1);\n\
    \  vl p = conv(deriv(v), inv(v, k));\n  p.resize(k - 1, 0);\n  return integr(p);\n\
    }\n\nvl exp(vl v, int k) {\n  assert(!v.empty() and v[0] == 0);\n  vl q(1, 1);\n\
    \  for(int i = 1; (1 << (i - 1)) < k; i++) {\n    vl p(1 << i, 0);\n    copy(v.begin(),\
    \ v.begin() + min(1 << i, (int)size(v)), p.begin());\n    vl r = p;\n    r[0]\
    \ = (r[0] + 1) % mod;\n    for(int j = 0; ll x : log(q, 1 << i)) r[j] = (r[j]\
    \ - x + mod) % mod, j++;\n    q = conv(q, r);\n    q.resize(1 << i, 0);\n  }\n\
    \  q.resize(k);\n  return q;\n}\n\nvl pow(vl v, ll idx, int k) {\n  if (idx ==\
    \ 0) {\n    vl p(k, 0);\n    p[0] = 1;\n    return p;\n  }\n  for(int i = 0; i\
    \ < ssize(v) and i * idx < k; i++) {\n    if (v[i] != 0) {\n      ll inv = modpow(v[i],\
    \ mod - 2);\n      vl p(ssize(v) - i);\n      for(int j = i; j < ssize(v); j++)\n\
    \        p[j - i] = v[j] * inv % mod;\n      p = log(p, k);\n      for(ll &x :\
    \ p)\n        x = idx % mod * x % mod;\n      p = exp(p, k);\n      vl q(k, 0);\n\
    \      ll pow = modpow(v[i], idx);\n      for(int j = 0; i * idx + j < k; j++)\n\
    \        q[i * idx + j] = p[j] * pow % mod;\n      return q;\n    }\n  }\n  return\
    \ vl(k, 0);\n}\n\nvl sqrt(vl v, int k) {\n  assert(!v.empty());\n  if (v[0] ==\
    \ 0) {\n    for(int i = 1; i < ssize(v); i++) {\n      if (v[i] != 0) {\n    \
    \    if (i & 1) return {};\n        if (i / 2 >= k) break;\n        vl q = sqrt(vl(v.begin()\
    \ + i, v.end()), k - i / 2);\n        if (q.empty()) return {};\n        q.resize(k,\
    \ 0);\n        ranges::rotate(q, q.begin() + k - i / 2);\n        return q;\n\
    \      }\n    }\n    return vl(k, 0);\n  }\n\n  ll sqr = sqrt(v[0], mod), inv2\
    \ = modpow(2, mod - 2);\n  if (sqr == -1) return {};\n  vl q(1, sqr);\n  for(int\
    \ i = 1; (1 << (i - 1)) < k; i++) {\n    vl p(1 << i, 0);\n    copy(v.begin(),\
    \ v.begin() + min(1 << i, (int)size(v)), p.begin());\n    vl r = conv(p, inv(q,\
    \ 1 << i));\n    for(int j = 0; ll x : q)\n      r[j] = (r[j] + x) % mod, j++;\n\
    \    for(ll &x : r)\n      x = x * inv2 % mod;\n    r.resize(1 << i);\n    r.swap(q);\n\
    \  }\n  q.resize(k);\n  return q;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/polyope.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/polyope.cpp
layout: document
redirect_from:
- /library/poly/polyope.cpp
- /library/poly/polyope.cpp.html
title: poly/polyope.cpp
---
