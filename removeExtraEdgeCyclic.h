



int isInCycle(struct Graph *g, int vertex)
{

    for (int i = 0; i < g->numVertices; i++)
    {
        if (vertex == g->cycle1[i])
        {
            return 1;
        }
    }
    return 0;
}

struct Graph *removeExtraEdgeCyclic(struct Graph *g, int vertex)
{   
    
    struct Node *temp1 = g->adj_list[vertex];
    struct Node *temp2;
    int next1, next2;

    while (temp1 != NULL)
    {
        if (isInCycle(g, (temp1->destination)))
        {

            next1 = temp1->destination;
            break;
        }
        else
        {
            temp1 = temp1->next;
        }
    }

    temp2 = g->adj_list[next1];

    while (temp2 != NULL)
    {
        if (isInCycle(g, (temp2->destination)))
        {
            next2 = temp2->destination;
            break;
        }
        else
        {
            temp2 = temp2->next;
        }
    }

   
    int x = temp1->weight;
    int y = temp2->weight;

    if (x > y)
    {
        temp1->weight = x - y;
        addEdge(g, vertex, next2, y);
        removeEdge(g, next1, next2);
    }
    else if (x < y)
    {
        addEdge(g, vertex, next2, x);
        temp2->weight = y - x;
        removeEdge(g, vertex, next1);
    }
    else
    {
        addEdge(g, vertex, next2, 0);
        removeEdge(g, vertex, next1);
        removeEdge(g, next1, next2);
    }
    return g;
}