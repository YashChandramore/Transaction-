


void longestPath(struct Graph *g)
{
    for (int i = 0; i < g->numVertices; i++)
    {
        g->depth[i] = 0;
        g->longBranch[i] = -1;
    }

    for (int i = 0; i < g->numVertices; i++)
    {

        int current_path = 0;
        struct Node *current_vertex = g->adj_list[i];
        struct Node *current_branch = current_vertex;
        struct Node *temp = current_vertex;

        while (current_branch != NULL)
        {

            if (temp == NULL)
            {

                if (current_path > g->depth[i])
                {
                    g->depth[i] = current_path;
                    temp = current_branch->next;
                    g->longBranch[i] = current_branch->destination;
                    current_branch = current_branch->next;
                    current_path = 0;
                }
                else
                {
                    temp = current_branch->next;
                    current_branch = current_branch->next;
                    current_path = 0;
                }
            }
            else
            {
                current_path++;
                int dest = temp->destination;
                temp = g->adj_list[dest];
            }
        }
    }
    // for (int i = 0; i < g->numVertices; i++)
    // {
    //     printf(" %d", g->depth[i]);
    // }
    // printf("\n h----------\n");
}
