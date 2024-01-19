/**
 * template name: pbdsSet
 * author: __Shioko(Misuki)
 * last update: 2022/01/13
 * header: bits/extc++.h (ext/pb_ds/assoc_container.hpp and ext/pb_ds/tree_policy.hpp for cf)
 * usage: order_of_key(x) : number of items strictly smaller than x
 *        find_by_order(k): K-th element in a set (0-based)
 */


using orderedSet = __gnu_pbds::tree<pii, __gnu_pbds::null_type, less<pii>,
  __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
