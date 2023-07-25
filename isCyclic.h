

int isCyclicUtil(int vertex, int *visited, int *recursionStack, struct Graph *graph)
{
    if (visited[vertex] == 0)
    {
        visited[vertex] = 1;
        recursionStack[vertex] = 1;

        struct Node *currNode = graph->adj_list[vertex];
        while (currNode != NULL)
        {
            int destination = currNode->destination;
            if (visited[destination] == 0 && isCyclicUtil(destination, visited, recursionStack, graph))
            {
                graph->cycle1[destination] = 1;
                return 1;
            }
            else if (recursionStack[destination] == 1)
            {
                graph->cycle1[destination] = 1;
                return 1;
            }
            currNode = currNode->next;
        }
    }
    recursionStack[vertex] = 0;
    return 0;
}

void findCyclicNodes(struct Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        graph->cycle1[i] = -1;
    }
    int visited[MAX_VERTICES] = {0};
    int recursionStack[MAX_VERTICES] = {0};
    // int visited[MAX_VERTICES] = {0};
    // int recursionStack[MAX_VERTICES] = {0};
    // int cycle[MAX_VERTICES] = {0};

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (visited[i] == 0)
        {
            if (isCyclicUtil(i, visited, recursionStack, graph))
            {
                graph->cycle1[i] = 1;
            }
        }
    }

    // printf("Nodes participating in the cycle:\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        if (graph->cycle1[i] == 1)
        {
            // printf("%d ", i);
            graph->cycle1[i] = i;
        }
        else
        {
            graph->cycle1[i] = -1;
        }
    }
    // printf("\n");
}

int isCyclic(struct Graph *g)
{
    
    findCyclicNodes(g);
    for (int i = 0; i < g->numVertices; i++)
    {
        if (g->cycle1[i] != -1)
        {
            return 1;
        }
    }
    return 0;
}