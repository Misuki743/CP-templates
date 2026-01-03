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
  bundledCode: "#line 1 \"icpc/polyope.cpp\"\n//source: KACTL\n//#include<ttt.cpp>\n\
    \ntemplate<ll mod = 998'244'353>\nll modpow(ll b, ll e) {\n\tll ans = 1;\n\tfor\
    \ (; e; b = b * b % mod, e /= 2)\n\t\tif (e & 1) ans = ans * b % mod;\n\treturn\
    \ ans;\n}\n\nll modpow(ll b, ll e, ll p) {\n  ll ans = 1;\n  for(; e; b = b *\
    \ b % p, e /= 2)\n    if (e & 1) ans = ans * b % p;\n  return ans;\n}\n\nll sqrt(ll\
    \ a, ll p) {\n\ta %= p; if (a < 0) a += p;\n\tif (a == 0) return 0;\n\t//assert(modpow(a,\
    \ (p-1)/2, p) == 1); // else no solution\n  if (modpow(a, (p-1)/2, p) != 1) return\
    \ -1;\n\tif (p % 4 == 3) return modpow(a, (p+1)/4, p);\n\t// a^(n+3)/8 or 2^(n+3)/8\
    \ * 2^(n-1)/4 works if p % 8 == 5\n\tll s = p - 1, n = 2;\n\tint r = 0, m;\n\t\
    while (s % 2 == 0)\n\t\t++r, s /= 2;\n\t/// find a non-square mod p\n\twhile (modpow(n,\
    \ (p - 1) / 2, p) != p - 1) ++n;\n\tll x = modpow(a, (s + 1) / 2, p);\n\tll b\
    \ = modpow(a, s, p), g = modpow(n, s, p);\n\tfor (;; r = m) {\n\t\tll t = b;\n\
    \t\tfor (m = 0; m < r && t != 1; ++m)\n\t\t\tt = t * t % p;\n\t\tif (m == 0) return\
    \ x;\n\t\tll gs = modpow(g, 1LL << (r - m - 1), p);\n\t\tg = gs * gs % p;\n\t\t\
    x = x * gs % p;\n\t\tb = b * g % p;\n\t}\n}\n\ntypedef vector<ll> vl;\ntemplate<ll\
    \ mod = 998'244'353, ll root = 3>\nvoid ntt(vl &a) {\n\tint n = sz(a), L = 31\
    \ - __builtin_clz(n);\n\tstatic vl rt(2, 1);\n\tfor (static int k = 2, s = 2;\
    \ k < n; k *= 2, s++) {\n\t\trt.resize(n);\n\t\tll z[] = {1, modpow<mod>(root,\
    \ mod >> s)};\n\t\trep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;\n\t}\n\tvi\
    \ rev(n);\n\trep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;\n\trep(i,0,n)\
    \ if (i < rev[i]) swap(a[i], a[rev[i]]);\n\tfor (int k = 1; k < n; k *= 2)\n\t\
    \tfor (int i = 0; i < n; i += 2 * k) rep(j,0,k) {\n\t\t\tll z = rt[j + k] * a[i\
    \ + j + k] % mod, &ai = a[i + j];\n\t\t\ta[i + j + k] = ai - z + (z > ai ? mod\
    \ : 0);\n\t\t\tai += (ai + z >= mod ? z - mod : z);\n\t\t}\n}\ntemplate<ll mod\
    \ = 998'244'353, ll root = 3>\nvl conv(const vl &a, const vl &b) {\n\tif (a.empty()\
    \ || b.empty()) return {};\n\tint s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s),\
    \ n = 1 << B;\n\tint inv = modpow<mod>(n, mod - 2);\n\tvl L(a), R(b), out(n);\n\
    \tL.resize(n), R.resize(n);\n\tntt<mod, root>(L), ntt<mod, root>(R);\n\trep(i,0,n)\
    \ out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;\n\tntt<mod, root>(out);\n\
    \treturn {out.begin(), out.begin() + s};\n}\n\nvl conv_any_mod(const vl &a, const\
    \ vl &b, const ll MOD) {\n  constexpr ll mod[3] = {998'244'353, 469'762'049, 167'772'161};\n\
    \  vector A(3, a), B(3, b);\n  for(int i = 0; i < 3; i++) {\n    for(ll &x : A[i])\
    \ x %= mod[i];\n    for(ll &x : B[i]) x %= mod[i];\n  }\n  A[0] = conv<mod[0],\
    \ 3>(A[0], B[0]);\n  A[1] = conv<mod[1], 3>(A[1], B[1]);\n  A[2] = conv<mod[2],\
    \ 3>(A[2], B[2]);\n  vl res(ssize(A[0]));\n  const ll im0 = modpow<mod[1]>(mod[0]\
    \ % mod[1], mod[1] - 2);\n  const ll im1 = modpow<mod[2]>(mod[1] % mod[2], mod[2]\
    \ - 2);\n  const ll im0m1 = im1 * modpow<mod[2]>(mod[0] % mod[2], mod[2] - 2)\
    \ % mod[2];\n  const ll m0 = mod[0] % MOD, m0m1 = m0 * mod[1] % MOD;\n  for(int\
    \ i = 0; i < ssize(res); i++) {\n    ll y0 = A[0][i];\n    ll y1 = ((A[1][i] -\
    \ y0) % mod[1] + mod[1]) % mod[1] * im0 % mod[1];\n    ll y2 = ((A[2][i] - y0)\
    \ % mod[2] + mod[2]) % mod[2] * im0m1 % mod[2] - im1 * y1 % mod[2];\n    y2 =\
    \ (y2 + mod[2]) % mod[2];\n    res[i] = y0 + m0 * y1 % MOD + m0m1 * y2 % MOD;\n\
    \    res[i] %= MOD;\n  }\n\n  return res;\n}\n\nconst ll mod = 998'244'353;\n\n\
    vl inv(vl v, int k) {\n  assert(!v.empty() and v[0] != 0);\n  vl q(1, modpow(v[0],\
    \ mod - 2));\n  for(int i = 1; (1 << (i - 1)) < k; i++) {\n    vl p(1 << i, 0);\n\
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
  code: "//source: KACTL\n//#include<ttt.cpp>\n\ntemplate<ll mod = 998'244'353>\n\
    ll modpow(ll b, ll e) {\n\tll ans = 1;\n\tfor (; e; b = b * b % mod, e /= 2)\n\
    \t\tif (e & 1) ans = ans * b % mod;\n\treturn ans;\n}\n\nll modpow(ll b, ll e,\
    \ ll p) {\n  ll ans = 1;\n  for(; e; b = b * b % p, e /= 2)\n    if (e & 1) ans\
    \ = ans * b % p;\n  return ans;\n}\n\nll sqrt(ll a, ll p) {\n\ta %= p; if (a <\
    \ 0) a += p;\n\tif (a == 0) return 0;\n\t//assert(modpow(a, (p-1)/2, p) == 1);\
    \ // else no solution\n  if (modpow(a, (p-1)/2, p) != 1) return -1;\n\tif (p %\
    \ 4 == 3) return modpow(a, (p+1)/4, p);\n\t// a^(n+3)/8 or 2^(n+3)/8 * 2^(n-1)/4\
    \ works if p % 8 == 5\n\tll s = p - 1, n = 2;\n\tint r = 0, m;\n\twhile (s % 2\
    \ == 0)\n\t\t++r, s /= 2;\n\t/// find a non-square mod p\n\twhile (modpow(n, (p\
    \ - 1) / 2, p) != p - 1) ++n;\n\tll x = modpow(a, (s + 1) / 2, p);\n\tll b = modpow(a,\
    \ s, p), g = modpow(n, s, p);\n\tfor (;; r = m) {\n\t\tll t = b;\n\t\tfor (m =\
    \ 0; m < r && t != 1; ++m)\n\t\t\tt = t * t % p;\n\t\tif (m == 0) return x;\n\t\
    \tll gs = modpow(g, 1LL << (r - m - 1), p);\n\t\tg = gs * gs % p;\n\t\tx = x *\
    \ gs % p;\n\t\tb = b * g % p;\n\t}\n}\n\ntypedef vector<ll> vl;\ntemplate<ll mod\
    \ = 998'244'353, ll root = 3>\nvoid ntt(vl &a) {\n\tint n = sz(a), L = 31 - __builtin_clz(n);\n\
    \tstatic vl rt(2, 1);\n\tfor (static int k = 2, s = 2; k < n; k *= 2, s++) {\n\
    \t\trt.resize(n);\n\t\tll z[] = {1, modpow<mod>(root, mod >> s)};\n\t\trep(i,k,2*k)\
    \ rt[i] = rt[i / 2] * z[i & 1] % mod;\n\t}\n\tvi rev(n);\n\trep(i,0,n) rev[i]\
    \ = (rev[i / 2] | (i & 1) << L) / 2;\n\trep(i,0,n) if (i < rev[i]) swap(a[i],\
    \ a[rev[i]]);\n\tfor (int k = 1; k < n; k *= 2)\n\t\tfor (int i = 0; i < n; i\
    \ += 2 * k) rep(j,0,k) {\n\t\t\tll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i\
    \ + j];\n\t\t\ta[i + j + k] = ai - z + (z > ai ? mod : 0);\n\t\t\tai += (ai +\
    \ z >= mod ? z - mod : z);\n\t\t}\n}\ntemplate<ll mod = 998'244'353, ll root =\
    \ 3>\nvl conv(const vl &a, const vl &b) {\n\tif (a.empty() || b.empty()) return\
    \ {};\n\tint s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;\n\t\
    int inv = modpow<mod>(n, mod - 2);\n\tvl L(a), R(b), out(n);\n\tL.resize(n), R.resize(n);\n\
    \tntt<mod, root>(L), ntt<mod, root>(R);\n\trep(i,0,n) out[-i & (n - 1)] = (ll)L[i]\
    \ * R[i] % mod * inv % mod;\n\tntt<mod, root>(out);\n\treturn {out.begin(), out.begin()\
    \ + s};\n}\n\nvl conv_any_mod(const vl &a, const vl &b, const ll MOD) {\n  constexpr\
    \ ll mod[3] = {998'244'353, 469'762'049, 167'772'161};\n  vector A(3, a), B(3,\
    \ b);\n  for(int i = 0; i < 3; i++) {\n    for(ll &x : A[i]) x %= mod[i];\n  \
    \  for(ll &x : B[i]) x %= mod[i];\n  }\n  A[0] = conv<mod[0], 3>(A[0], B[0]);\n\
    \  A[1] = conv<mod[1], 3>(A[1], B[1]);\n  A[2] = conv<mod[2], 3>(A[2], B[2]);\n\
    \  vl res(ssize(A[0]));\n  const ll im0 = modpow<mod[1]>(mod[0] % mod[1], mod[1]\
    \ - 2);\n  const ll im1 = modpow<mod[2]>(mod[1] % mod[2], mod[2] - 2);\n  const\
    \ ll im0m1 = im1 * modpow<mod[2]>(mod[0] % mod[2], mod[2] - 2) % mod[2];\n  const\
    \ ll m0 = mod[0] % MOD, m0m1 = m0 * mod[1] % MOD;\n  for(int i = 0; i < ssize(res);\
    \ i++) {\n    ll y0 = A[0][i];\n    ll y1 = ((A[1][i] - y0) % mod[1] + mod[1])\
    \ % mod[1] * im0 % mod[1];\n    ll y2 = ((A[2][i] - y0) % mod[2] + mod[2]) % mod[2]\
    \ * im0m1 % mod[2] - im1 * y1 % mod[2];\n    y2 = (y2 + mod[2]) % mod[2];\n  \
    \  res[i] = y0 + m0 * y1 % MOD + m0m1 * y2 % MOD;\n    res[i] %= MOD;\n  }\n\n\
    \  return res;\n}\n\nconst ll mod = 998'244'353;\n\nvl inv(vl v, int k) {\n  assert(!v.empty()\
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
  path: icpc/polyope.cpp
  requiredBy: []
  timestamp: '2026-01-03 23:17:25+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: icpc/polyope.cpp
layout: document
redirect_from:
- /library/icpc/polyope.cpp
- /library/icpc/polyope.cpp.html
title: icpc/polyope.cpp
---
