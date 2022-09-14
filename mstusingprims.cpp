#include<stdio.h>
#include<stdlib.h>

#define MAX 10
#define TEMP 0
#define PERM 1
#define infinity 9999
#define NIL -1

struct edge
{
        int u;
        int v;
};

int n;
int adj[MAX][MAX];

int predecessor[MAX];
int status[MAX];
int length[MAX];

void create_graph();
void maketree(int r, struct edge tree[MAX]);
int min_temp();

int main()
{
        int wt_tree = 0;
        int i, root;
        struct edge tree[MAX];

        create_graph();

        printf("\nEnter root vertex : ");
        scanf("%d",&root);

        maketree(root, tree);

        printf("\nEdges to be included in spanning tree are : \n");

        for(i=1; i<=n-1; i++)
        {
                printf("%d-> ",tree[i].u);
                printf("%d\n",tree[i].v);
                wt_tree += adj[tree[i].u][tree[i].v];
        }
        printf("\nWeight of spanning tree is : %d\n", wt_tree);

        return 0;

}

void maketree(int r, struct edge tree[MAX])
{
        int current,i;
        int count = 0;
        for(i=0; i<n; i++)
        {
                predecessor[i] = NIL;
                length[i] = infinity;
                status[i] = TEMP;
        }
        length[r] = 0;

        while(1)
        {
                current = min_temp();

                if(current == NIL)
                {
                        if(count == n-1) 
                                return;
                        else 
                        {
                                printf("\nGraph is not connected, No spanning tree possible\n");
                                exit(1);
                        }
                }
        status[current] = PERM;
                if(current != r)
                {
           count++;
                   tree[count].u = predecessor[current];
                   tree[count].v = current;
                }

                for(i=0; i<n; i++)
                        if(adj[current][i] > 0 && status[i] == TEMP)
                                if(adj[current][i] < length[i])
                                {
                                        predecessor[i] = current;
                                        length[i] = adj[current][i];
                                }
        }

}
int min_temp()
{
        int i;
        int min = infinity;
        int k = -1;

        for(i=0; i<n; i++)
        {
                if(status[i] == TEMP && length[i] < min)
                {
                        min = length[i];
                        k = i;
                }
        }

        return k;
}

void create_graph()
{
        int i,max_edges,origin,destin,wt;

        printf("\nEnter number of vertices : ");
        scanf("%d",&n);
        max_edges = n*(n-1)/2;

        for(i=1; i<=max_edges; i++)
        {
                printf("\nEnter edge %d(-1 -1 to quit) : ",i);
                scanf("%d %d",&origin,&destin);
                if((origin == -1) && (destin == -1))
                        break;
                printf("\nEnter weight for this edge : ");
                scanf("%d",&wt);
                if( origin >= n || destin >= n || origin < 0 || destin < 0)
                {
                        printf("\nInvalid edge!\n");
                        i--;
                }
                else
                {
                        adj[origin][destin] = wt;
                        adj[destin][origin] = wt;
                }
        }
}
