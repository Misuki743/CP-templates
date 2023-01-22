//////////////////////////////////////////////////
//template name: treap
//author: __Shioko(Misuki)
//last update: 2022/07/19
//split(now, x, l, r): split treap into first x element and last (now.sz - x) element.

#define clock chrono::steady_clock::now().time_since_epoch().count()
mt19937 rng(clock);

struct node {
  int pri;
  node *l = nullptr, *r = nullptr;
  node() : pri(rng()) {}
  int sz = 1;
};

int size(node *now) {
  return now ? now -> sz : 0;
}
void update(node *now) {
  if (!now) return;
  now -> sz = size(now -> l) + size(now -> r) + 1;
}

void push(node *now) {
  if (!now) return;
}

void split(node *now, int x, node *&l, node *&r, int add = 0) {
  if (!now) {
    l = r = nullptr;
    return;
  }
  push(now);
  int key = add + size(now -> l);
  if (key < x)
    split(now -> r, x, now -> r, r, add + size(now -> l) + 1), l = now;
  else
    split(now -> l, x, l, now -> l, add), r = now;
  update(now);
}

node* merge(node *l, node *r) {
  if (!l) return r;
  if (!r) return l;

  push(l);
  push(r);
  if (l -> pri < r -> pri) {
    l -> r = merge(l -> r, r);
    update(l);
    return l;
  } else {
    r -> l = merge(l, r -> l);
    update(r);
    return r;
  }
}
//////////////////////////////////////////////////
