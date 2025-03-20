# prim-algorithm

understanding the code

# pseudo-code
```
PRIM(G, w, r)
  for each u in V[G]
    key[u] = ∞
    parent[u] = NIL
  key[r] = 0
  Q = V[G]
  while Q ≠ ∅
    u = EXTRACT-MIN(Q)
    for each v in Adj[u]
      if v in Q and w(u, v) < key[v]
        parent[v] = u
        key[v] = w(u, v)
```


![alt text](https://konspekta.net/infopediasu/baza12/3382261464535.files/image132.jpg)

 The graph in the image can be represented using a 2D matrix. After executing the graph.c file, the output will be as follows:
```
    A   B   C   D   E   F   G   H   I
A |    .   4   .   .   .   .   .   8   .
B |    4   .   8   .   .   .   .  11   .
C |    .   8   .   7   .   4   .   .   2
D |    .   .   7   .   9   .   .   .   .
E |    .   .   .   9   .  10   .   .   .
F |    .   .   4   .  10   .   2   .   .
G |    .   .   .   .   .   2   .   1   6
H |    8  11   .   .   .   .   1   .   .
I |    .   .   2   .   .   .   6   .   .
```
When the PrimMST algorithm is executed, this path should be revealed:

![alt text](https://konspekta.net/infopediasu/baza12/3382261464535.files/image134.jpg)

```
    A   B   C   D   E   F   G   H   I
A |  .   4   .   .   .   .   .   8   .
B |  4   .   8   .   .   .   .   11  .
C |  .   8   .   7   .   4   .   .   2
D |  .   .   7   .   9   .   .   .   .
E |  .   .   .   9   .   10  .   .   .
F |  .   .   4   .   10  .   2   .   .
G |  .   .   .   .   .   2   .   1   6
H |  8   11  .   .   .   .   1   .   .
I |  .   .   2   .   .   .   6   .   .

Prim MST:
Edge    Weight
A - B   4
B - C   8
C - D   7
D - E   9
C - F   4
F - G   2
G - H   1
C - I   2

```

