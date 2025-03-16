/**
 * Author: Nalime
 * Date: 2023-09-04
 * License: CC0
 * Source: Myself
 * Description: A general way to tree walk on ZKW lazy segment tree.
 *  This implementation requires $N$ to be
 *  an \textbf{integral power of} $\mathbf{2}$.
 *  You need to separate out the single node pushdown logic
 *  from \texttt{push} to \texttt{push0}.
 *  \texttt{operator<} also needs to be defined for \texttt{T1}.
 * Time: O(\log N).
 * Status: AC on Codeforces EDU segment tree 2-3-C
 */
#pragma once

#include "homemade/segmentTreeLazy.h"

int first(int i, M x) {
  M y = Mid();
  for (push(i += size);; i >>= 1) if (i & 1) { // if is necessary
    if (M z = Mop(y, data[i]); z < x) {
      if ((i & (i + 1)) == 0) return -1; // fail on rightmost
      y = z, i++;
    } else break;
  }
  while (i < size) {
    if (tag[i] != Tid()) {
      apply(i << 1, tag[i]), apply(i << 1 | 1, tag[i]);
      tag[i] = Tid();
    }
    if (M z = Mop(y, data[i <<= 1]); z < x) y = z, i++;
  }
  return i - size;
}
