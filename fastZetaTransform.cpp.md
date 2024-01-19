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
  bundledCode: "#line 1 \"fastZetaTransform.cpp\"\n/**\n * template name: fastZetaTransform\n\
    \ * author: Misuki\n * last update: 2023/03/26\n * note: to change to poset, flip\
    \ the condition inside if statement. \n * four possible usage:\n * fastZetaTransform\
    \ on subset (SOS)\n * fastZetaTransform on poset\n * fastMobiusTransform on subset\n\
    \ * fastMobiusTransform on poset (IEP)\n */\n\ntemplate<class T>\nvoid fastZetaTransform(vector<T>\
    \ &vec, bool inverse = false) {\n  for(int i = 0; (1 << i) < (int)vec.size();\
    \ i++)\n    for(int j = 0; j < (int)vec.size(); j++)\n      if (j >> i & 1)\n\
    \        vec[j] += (inverse ? -vec[j ^ (1 << i)] : vec[j ^ (1 << i)]);\n}\n"
  code: "/**\n * template name: fastZetaTransform\n * author: Misuki\n * last update:\
    \ 2023/03/26\n * note: to change to poset, flip the condition inside if statement.\
    \ \n * four possible usage:\n * fastZetaTransform on subset (SOS)\n * fastZetaTransform\
    \ on poset\n * fastMobiusTransform on subset\n * fastMobiusTransform on poset\
    \ (IEP)\n */\n\ntemplate<class T>\nvoid fastZetaTransform(vector<T> &vec, bool\
    \ inverse = false) {\n  for(int i = 0; (1 << i) < (int)vec.size(); i++)\n    for(int\
    \ j = 0; j < (int)vec.size(); j++)\n      if (j >> i & 1)\n        vec[j] += (inverse\
    \ ? -vec[j ^ (1 << i)] : vec[j ^ (1 << i)]);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: fastZetaTransform.cpp
  requiredBy: []
  timestamp: '2023-06-16 02:10:58+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fastZetaTransform.cpp
layout: document
redirect_from:
- /library/fastZetaTransform.cpp
- /library/fastZetaTransform.cpp.html
title: fastZetaTransform.cpp
---
