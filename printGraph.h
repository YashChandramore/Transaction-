

void printGraph(struct Group * group , struct Graph *graph)
{
    printf("\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        struct Node *temp = graph->adj_list[i];
        // printf("Adjacency list of vertex   %s ===  ", group->members[i]);
        while (temp)
        {
            // printf("%s: %d ----> \n", group->members[(temp->destination)] , temp->weight);
            // printf("%s: %d ----> \n", group->members[(temp->destination)] , temp->weight);
            // printf("%s -->%s : %d \n", group->members[i] , group->members[(temp->destination)] , temp->weight);

            
            printf("%s-->",group->members[i]);
            printf("%s:",group->members[(temp->destination)]);
            printf("%d.\n",temp->weight);


            temp = temp->next;
        }
        // printf("\n");
    }
    printf("\n");



}