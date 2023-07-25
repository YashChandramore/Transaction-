
struct Graph *removeExtraEdge(struct Graph *g, int vertex)
{

    struct Node *temp1 = g->adj_list[vertex];
    struct Node *temp2;

    while (temp1 != NULL)
    {
        if (temp1->destination == g->longBranch[vertex])
        {
            break;
        }
        else
        {
            temp1 = temp1->next;
        }
    }

    temp2 = g->adj_list[(temp1->destination)];
    int next1 = temp1->destination;

    while (temp2 != NULL)
    {
        if (temp2->destination == g->longBranch[(next1)])
        {
            break;
        }
        else
        {
            temp2 = temp2->next;
        }
    }

    int next2 = temp2->destination;

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
        addEdge(g, vertex, next2, x);
        removeEdge(g, vertex, next1);
        removeEdge(g, next1, next2);
    }
    // printf(" hello %d %d", x, y);
    return g;
}
