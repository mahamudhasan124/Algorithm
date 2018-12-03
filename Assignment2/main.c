#include <stdio.h>
#include <stdlib.h>
const int MAX = 10000;
int id[10000];
int nodes;
int edges;
int i;
typedef struct pair pair;

struct pair{
    int x;
    int y;
    int z;
}p[10000];

void initialize()
{
    for(i = 0;i < MAX;++i)
        id[i] = i;
}

int cmp(pair a, pair b){
    return a.z > b.z;
}
int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}
long long kruskal()
{
    int x, y;
    long long cost, minimumCost = 0;
    for(i = 0;i < edges;++i)
    {
        x = p[i].x;
        y = p[i].y;
        cost = p[i].z;

        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}
int cmpfunc (pair a, pair b) {
   return ( a.z < b.z);
}
int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    scanf("%d %d", &nodes, &edges);
    for(i = 0;i < edges;++i)
    {
        scanf("%d %d %d", &x, &y, &weight);
        p[i].x = x;
        p[i].y = y;
        p[i].z = weight;
    }

    qsort(p, edges, sizeof(int), cmpfunc);
    minimumCost = kruskal();
    printf("%d",minimumCost);
    return 0;
}
