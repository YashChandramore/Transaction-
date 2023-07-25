

struct Group * executeFunction(struct Group *group, struct Graph *graph)
{
    printf("\n------------------------------Initial Transaction ----------------------------------");
    printGraph(group, graph);

    while (isCyclic(graph))
    {

        int cyclic_vertex = -1;
        for (int i = 0; i < graph->numVertices; i++)
        {
            if (graph->cycle1[i] == -1)
            {
                continue;
            }
            else
            {
                cyclic_vertex = graph->cycle1[i];
            }
        }

        // printf("-------- %d\n" , cyclic_vertex);
        graph = removeExtraEdgeCyclic(graph, cyclic_vertex);
        // printGraph(graph);
    }

    longestPath(graph);

    int i = 0;

    while (!isSimplified(graph))
    {
        if (i > (graph->numVertices - 1))
        {
            i = 0;
        }

        // printf("i-------%d\n",i);
        if (graph->depth[i] > 1)
        {
            graph = removeExtraEdge(graph, i);
            longestPath(graph);
            // printf("i -> %d", i);
            i++;
        }
        else
        {
            i++;
        }
    }

    printf("----------------------------------------Simplified Transaction ---------------------------");
    printGraph(group, graph);

    return group;
}