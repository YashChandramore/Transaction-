


int isSimplified(struct Graph *g)
{

    for (int i = 0; i < g->numVertices; i++)
    {
        if (g->depth[i] > 1)
        {

            return 0;
        }
        else
        {
            continue;
        }
    }

    return 1;
}