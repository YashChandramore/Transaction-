

void addEdge(struct Graph *graph, int src, int dest, int weight)
{
    struct Node *newNode = createNode(dest, weight);
    struct Node *current = graph->adj_list[src];

    if (src == dest)
    {
        return;
    }

    // Check if an edge already exists
    while (current != NULL)
    {
        if (current->destination == dest)
        {
            current->weight = current->weight + weight; // Update the weight
            return;
        }
        current = current->next;
    }

    // Edge does not exist, add a new edge
    newNode->next = graph->adj_list[src];
    graph->adj_list[src] = newNode;
}