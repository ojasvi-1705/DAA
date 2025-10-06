#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

struct DisjointSet {
    int *parent, *rank;
    int n;
};

struct DisjointSet* createSet(int n) {
    struct DisjointSet* ds = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
    ds->n = n;
    ds->parent = (int*)malloc(n * sizeof(int));
    ds->rank = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
        ds->parent[i] = i;
    return ds;
}

int find(struct DisjointSet* ds, int u) {
    if (ds->parent[u] != u)
        ds->parent[u] = find(ds, ds->parent[u]);
    return ds->parent[u];
}

int unionSet(struct DisjointSet* ds, int u, int v) {
    int rootU = find(ds, u);
    int rootV = find(ds, v);

    if (rootU == rootV)
        return 0; 

    if (ds->rank[rootU] < ds->rank[rootV])
        ds->parent[rootU] = rootV;
    else if (ds->rank[rootU] > ds->rank[rootV])
        ds->parent[rootV] = rootU;
    else {
        ds->parent[rootV] = rootU;
        ds->rank[rootU]++;
    }
    return 1;
}

int cmpEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

void kruskal(struct Edge edges[], int n, int e) {
    qsort(edges, e, sizeof(struct Edge), cmpEdges);

    struct DisjointSet* ds = createSet(n);
    int mstWeight = 0;

    printf("Edges in MST:\n");

    for (int i = 0; i < e; i++) {
        if (unionSet(ds, edges[i].u, edges[i].v)) {
            mstWeight += edges[i].w;
            printf("%d -- %d == %d\n", edges[i].u, edges[i].v, edges[i].w);
        }
    }

    printf("Total weight of MST = %d\n", mstWeight);
}

int main() {
    int n = 4; 
    int e = 5; 

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(edges, n, e);

    return 0;
}
