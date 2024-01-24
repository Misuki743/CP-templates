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
  bundledCode: "#line 1 \"geometry/geometryPolygon.cpp\"\n//source: KACTL\n\nbool\
    \ inPolygon(vector<P> &p, P a, bool strict = true) {\n\tint cnt = 0, n = sz(p);\n\
    \trep(i,0,n) {\n\t\tP q = p[(i + 1) % n];\n\t\tif (onSegment(p[i], q, a)) return\
    \ !strict;\n\t\t//or: if (segDist(p[i], q, a) <= eps) return !strict;\n\t\tcnt\
    \ ^= ((a.y<p[i].y) - (a.y<q.y)) * a.cross(p[i], q) > 0;\n\t}\n\treturn cnt;\n\
    }\n\ntemplate<class T>\nT polygonArea2(vector<Point<T>>& v) {\n\tT a = v.back().cross(v[0]);\n\
    \trep(i,0,sz(v)-1) a += v[i].cross(v[i+1]);\n\treturn a;\n}\n\nP polygonCenter(const\
    \ vector<P>& v) {\n\tP res(0, 0); double A = 0;\n\tfor (int i = 0, j = sz(v) -\
    \ 1; i < sz(v); j = i++) {\n\t\tres = res + (v[i] + v[j]) * v[j].cross(v[i]);\n\
    \t\tA += v[j].cross(v[i]);\n\t}\n\treturn res / A / 3;\n}\n\nvector<P> polygonCut(const\
    \ vector<P>& poly, P s, P e) {\n\tvector<P> res;\n\trep(i,0,sz(poly)) {\n\t\t\
    P cur = poly[i], prev = i ? poly[i-1] : poly.back();\n\t\tbool side = s.cross(e,\
    \ cur) < 0;\n\t\tif (side != (s.cross(e, prev) < 0))\n\t\t\tres.push_back(lineInter(s,\
    \ e, cur, prev).second);\n\t\tif (side)\n\t\t\tres.push_back(cur);\n\t}\n\treturn\
    \ res;\n}\n\ndouble rat(P a, P b) { return sgn(b.x) ? a.x/b.x : a.y/b.y; }\ndouble\
    \ polyUnion(vector<vector<P>>& poly) {\n\tdouble ret = 0;\n\trep(i,0,sz(poly))\
    \ rep(v,0,sz(poly[i])) {\n\t\tP A = poly[i][v], B = poly[i][(v + 1) % sz(poly[i])];\n\
    \t\tvector<pair<double, int>> segs = {{0, 0}, {1, 0}};\n\t\trep(j,0,sz(poly))\
    \ if (i != j) {\n\t\t\trep(u,0,sz(poly[j])) {\n\t\t\t\tP C = poly[j][u], D = poly[j][(u\
    \ + 1) % sz(poly[j])];\n\t\t\t\tint sc = sideOf(A, B, C), sd = sideOf(A, B, D);\n\
    \t\t\t\tif (sc != sd) {\n\t\t\t\t\tdouble sa = C.cross(D, A), sb = C.cross(D,\
    \ B);\n\t\t\t\t\tif (min(sc, sd) < 0)\n\t\t\t\t\t\tsegs.emplace_back(sa / (sa\
    \ - sb), sgn(sc - sd));\n\t\t\t\t} else if (!sc && !sd && j<i && sgn((B-A).dot(D-C))>0){\n\
    \t\t\t\t\tsegs.emplace_back(rat(C - A, B - A), 1);\n\t\t\t\t\tsegs.emplace_back(rat(D\
    \ - A, B - A), -1);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tsort(all(segs));\n\t\tfor\
    \ (auto& s : segs) s.first = min(max(s.first, 0.0), 1.0);\n\t\tdouble sum = 0;\n\
    \t\tint cnt = segs[0].second;\n\t\trep(j,1,sz(segs)) {\n\t\t\tif (!cnt) sum +=\
    \ segs[j].first - segs[j - 1].first;\n\t\t\tcnt += segs[j].second;\n\t\t}\n\t\t\
    ret += A.cross(B) * sum;\n\t}\n\treturn ret / 2;\n}\n\nvector<P> convexHull(vector<P>\
    \ pts) {\n\tif (sz(pts) <= 1) return pts;\n\tsort(all(pts));\n\tvector<P> h(sz(pts)+1);\n\
    \tint s = 0, t = 0;\n\tfor (int it = 2; it--; s = --t, reverse(all(pts)))\n\t\t\
    for (P p : pts) {\n\t\t\twhile (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;\n\
    \t\t\th[t++] = p;\n\t\t}\n\treturn {h.begin(), h.begin() + t - (t == 2 && h[0]\
    \ == h[1])};\n}\n\narray<P, 2> hullDiameter(vector<P> S) {\n\tint n = sz(S), j\
    \ = n < 2 ? 0 : 1;\n\tpair<ll, array<P, 2>> res({0, {S[0], S[0]}});\n\trep(i,0,j)\n\
    \t\tfor (;; j = (j + 1) % n) {\n\t\t\tres = max(res, {(S[i] - S[j]).dist2(), {S[i],\
    \ S[j]}});\n\t\t\tif ((S[(j + 1) % n] - S[j]).cross(S[i + 1] - S[i]) >= 0)\n\t\
    \t\t\tbreak;\n\t\t}\n\treturn res.second;\n}\n\nbool inHull(const vector<P>& l,\
    \ P p, bool strict = true) {\n\tint a = 1, b = sz(l) - 1, r = !strict;\n\tif (sz(l)\
    \ < 3) return r && onSegment(l[0], l.back(), p);\n\tif (sideOf(l[0], l[a], l[b])\
    \ > 0) swap(a, b);\n\tif (sideOf(l[0], l[a], p) >= r || sideOf(l[0], l[b], p)<=\
    \ -r)\n\t\treturn false;\n\twhile (abs(a - b) > 1) {\n\t\tint c = (a + b) / 2;\n\
    \t\t(sideOf(l[0], l[c], p) > 0 ? b : a) = c;\n\t}\n\treturn sgn(l[a].cross(l[b],\
    \ p)) < r;\n}\n\n#define cmp(i,j) sgn(dir.perp().cross(poly[(i)%n]-poly[(j)%n]))\n\
    #define extr(i) cmp(i + 1, i) >= 0 && cmp(i, i - 1 + n) < 0\ntemplate <class P>\
    \ int extrVertex(vector<P>& poly, P dir) {\n\tint n = sz(poly), lo = 0, hi = n;\n\
    \tif (extr(0)) return 0;\n\twhile (lo + 1 < hi) {\n\t\tint m = (lo + hi) / 2;\n\
    \t\tif (extr(m)) return m;\n\t\tint ls = cmp(lo + 1, lo), ms = cmp(m + 1, m);\n\
    \t\t(ls < ms || (ls == ms && ls == cmp(lo, m)) ? hi : lo) = m;\n\t}\n\treturn\
    \ lo;\n}\n\n#define cmpL(i) sgn(a.cross(poly[i], b))\ntemplate <class P>\narray<int,\
    \ 2> lineHull(P a, P b, vector<P>& poly) {\n\tint endA = extrVertex(poly, (a -\
    \ b).perp());\n\tint endB = extrVertex(poly, (b - a).perp());\n\tif (cmpL(endA)\
    \ < 0 || cmpL(endB) > 0)\n\t\treturn {-1, -1};\n\tarray<int, 2> res;\n\trep(i,0,2)\
    \ {\n\t\tint lo = endB, hi = endA, n = sz(poly);\n\t\twhile ((lo + 1) % n != hi)\
    \ {\n\t\t\tint m = ((lo + hi + (lo < hi ? 0 : n)) / 2) % n;\n\t\t\t(cmpL(m) ==\
    \ cmpL(endB) ? lo : hi) = m;\n\t\t}\n\t\tres[i] = (lo + !cmpL(hi)) % n;\n\t\t\
    swap(endA, endB);\n\t}\n\tif (res[0] == res[1]) return {res[0], -1};\n\tif (!cmpL(res[0])\
    \ && !cmpL(res[1]))\n\t\tswitch ((res[0] - res[1] + sz(poly) + 1) % sz(poly))\
    \ {\n\t\t\tcase 0: return {res[0], res[0]};\n\t\t\tcase 2: return {res[1], res[1]};\n\
    \t\t}\n\treturn res;\n}\n"
  code: "//source: KACTL\n\nbool inPolygon(vector<P> &p, P a, bool strict = true)\
    \ {\n\tint cnt = 0, n = sz(p);\n\trep(i,0,n) {\n\t\tP q = p[(i + 1) % n];\n\t\t\
    if (onSegment(p[i], q, a)) return !strict;\n\t\t//or: if (segDist(p[i], q, a)\
    \ <= eps) return !strict;\n\t\tcnt ^= ((a.y<p[i].y) - (a.y<q.y)) * a.cross(p[i],\
    \ q) > 0;\n\t}\n\treturn cnt;\n}\n\ntemplate<class T>\nT polygonArea2(vector<Point<T>>&\
    \ v) {\n\tT a = v.back().cross(v[0]);\n\trep(i,0,sz(v)-1) a += v[i].cross(v[i+1]);\n\
    \treturn a;\n}\n\nP polygonCenter(const vector<P>& v) {\n\tP res(0, 0); double\
    \ A = 0;\n\tfor (int i = 0, j = sz(v) - 1; i < sz(v); j = i++) {\n\t\tres = res\
    \ + (v[i] + v[j]) * v[j].cross(v[i]);\n\t\tA += v[j].cross(v[i]);\n\t}\n\treturn\
    \ res / A / 3;\n}\n\nvector<P> polygonCut(const vector<P>& poly, P s, P e) {\n\
    \tvector<P> res;\n\trep(i,0,sz(poly)) {\n\t\tP cur = poly[i], prev = i ? poly[i-1]\
    \ : poly.back();\n\t\tbool side = s.cross(e, cur) < 0;\n\t\tif (side != (s.cross(e,\
    \ prev) < 0))\n\t\t\tres.push_back(lineInter(s, e, cur, prev).second);\n\t\tif\
    \ (side)\n\t\t\tres.push_back(cur);\n\t}\n\treturn res;\n}\n\ndouble rat(P a,\
    \ P b) { return sgn(b.x) ? a.x/b.x : a.y/b.y; }\ndouble polyUnion(vector<vector<P>>&\
    \ poly) {\n\tdouble ret = 0;\n\trep(i,0,sz(poly)) rep(v,0,sz(poly[i])) {\n\t\t\
    P A = poly[i][v], B = poly[i][(v + 1) % sz(poly[i])];\n\t\tvector<pair<double,\
    \ int>> segs = {{0, 0}, {1, 0}};\n\t\trep(j,0,sz(poly)) if (i != j) {\n\t\t\t\
    rep(u,0,sz(poly[j])) {\n\t\t\t\tP C = poly[j][u], D = poly[j][(u + 1) % sz(poly[j])];\n\
    \t\t\t\tint sc = sideOf(A, B, C), sd = sideOf(A, B, D);\n\t\t\t\tif (sc != sd)\
    \ {\n\t\t\t\t\tdouble sa = C.cross(D, A), sb = C.cross(D, B);\n\t\t\t\t\tif (min(sc,\
    \ sd) < 0)\n\t\t\t\t\t\tsegs.emplace_back(sa / (sa - sb), sgn(sc - sd));\n\t\t\
    \t\t} else if (!sc && !sd && j<i && sgn((B-A).dot(D-C))>0){\n\t\t\t\t\tsegs.emplace_back(rat(C\
    \ - A, B - A), 1);\n\t\t\t\t\tsegs.emplace_back(rat(D - A, B - A), -1);\n\t\t\t\
    \t}\n\t\t\t}\n\t\t}\n\t\tsort(all(segs));\n\t\tfor (auto& s : segs) s.first =\
    \ min(max(s.first, 0.0), 1.0);\n\t\tdouble sum = 0;\n\t\tint cnt = segs[0].second;\n\
    \t\trep(j,1,sz(segs)) {\n\t\t\tif (!cnt) sum += segs[j].first - segs[j - 1].first;\n\
    \t\t\tcnt += segs[j].second;\n\t\t}\n\t\tret += A.cross(B) * sum;\n\t}\n\treturn\
    \ ret / 2;\n}\n\nvector<P> convexHull(vector<P> pts) {\n\tif (sz(pts) <= 1) return\
    \ pts;\n\tsort(all(pts));\n\tvector<P> h(sz(pts)+1);\n\tint s = 0, t = 0;\n\t\
    for (int it = 2; it--; s = --t, reverse(all(pts)))\n\t\tfor (P p : pts) {\n\t\t\
    \twhile (t >= s + 2 && h[t-2].cross(h[t-1], p) <= 0) t--;\n\t\t\th[t++] = p;\n\
    \t\t}\n\treturn {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};\n}\n\n\
    array<P, 2> hullDiameter(vector<P> S) {\n\tint n = sz(S), j = n < 2 ? 0 : 1;\n\
    \tpair<ll, array<P, 2>> res({0, {S[0], S[0]}});\n\trep(i,0,j)\n\t\tfor (;; j =\
    \ (j + 1) % n) {\n\t\t\tres = max(res, {(S[i] - S[j]).dist2(), {S[i], S[j]}});\n\
    \t\t\tif ((S[(j + 1) % n] - S[j]).cross(S[i + 1] - S[i]) >= 0)\n\t\t\t\tbreak;\n\
    \t\t}\n\treturn res.second;\n}\n\nbool inHull(const vector<P>& l, P p, bool strict\
    \ = true) {\n\tint a = 1, b = sz(l) - 1, r = !strict;\n\tif (sz(l) < 3) return\
    \ r && onSegment(l[0], l.back(), p);\n\tif (sideOf(l[0], l[a], l[b]) > 0) swap(a,\
    \ b);\n\tif (sideOf(l[0], l[a], p) >= r || sideOf(l[0], l[b], p)<= -r)\n\t\treturn\
    \ false;\n\twhile (abs(a - b) > 1) {\n\t\tint c = (a + b) / 2;\n\t\t(sideOf(l[0],\
    \ l[c], p) > 0 ? b : a) = c;\n\t}\n\treturn sgn(l[a].cross(l[b], p)) < r;\n}\n\
    \n#define cmp(i,j) sgn(dir.perp().cross(poly[(i)%n]-poly[(j)%n]))\n#define extr(i)\
    \ cmp(i + 1, i) >= 0 && cmp(i, i - 1 + n) < 0\ntemplate <class P> int extrVertex(vector<P>&\
    \ poly, P dir) {\n\tint n = sz(poly), lo = 0, hi = n;\n\tif (extr(0)) return 0;\n\
    \twhile (lo + 1 < hi) {\n\t\tint m = (lo + hi) / 2;\n\t\tif (extr(m)) return m;\n\
    \t\tint ls = cmp(lo + 1, lo), ms = cmp(m + 1, m);\n\t\t(ls < ms || (ls == ms &&\
    \ ls == cmp(lo, m)) ? hi : lo) = m;\n\t}\n\treturn lo;\n}\n\n#define cmpL(i) sgn(a.cross(poly[i],\
    \ b))\ntemplate <class P>\narray<int, 2> lineHull(P a, P b, vector<P>& poly) {\n\
    \tint endA = extrVertex(poly, (a - b).perp());\n\tint endB = extrVertex(poly,\
    \ (b - a).perp());\n\tif (cmpL(endA) < 0 || cmpL(endB) > 0)\n\t\treturn {-1, -1};\n\
    \tarray<int, 2> res;\n\trep(i,0,2) {\n\t\tint lo = endB, hi = endA, n = sz(poly);\n\
    \t\twhile ((lo + 1) % n != hi) {\n\t\t\tint m = ((lo + hi + (lo < hi ? 0 : n))\
    \ / 2) % n;\n\t\t\t(cmpL(m) == cmpL(endB) ? lo : hi) = m;\n\t\t}\n\t\tres[i] =\
    \ (lo + !cmpL(hi)) % n;\n\t\tswap(endA, endB);\n\t}\n\tif (res[0] == res[1]) return\
    \ {res[0], -1};\n\tif (!cmpL(res[0]) && !cmpL(res[1]))\n\t\tswitch ((res[0] -\
    \ res[1] + sz(poly) + 1) % sz(poly)) {\n\t\t\tcase 0: return {res[0], res[0]};\n\
    \t\t\tcase 2: return {res[1], res[1]};\n\t\t}\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometryPolygon.cpp
  requiredBy: []
  timestamp: '2024-01-24 20:41:29+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/geometryPolygon.cpp
layout: document
redirect_from:
- /library/geometry/geometryPolygon.cpp
- /library/geometry/geometryPolygon.cpp.html
title: geometry/geometryPolygon.cpp
---
