

struct Node
{
    int destination;
    int weight;
    struct Node *next;
};
typedef struct
{
    char *name;
    int assignedInteger;

} Person;

struct Graph
{
    int numVertices;
    struct Node **adj_list;
    int *cycle1;
    int *depth;
    int *longBranch;
};

struct Group
{

    char id[100];
    struct Graph *graph;
    Person * members;
    struct Group *nextGroup;
};

struct Node *createNode(int destination, int weight)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->destination = destination;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int numVertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adj_list = (struct Node **)malloc(numVertices * sizeof(struct Node *));
    graph->cycle1 = (int *)malloc(sizeof(int) * numVertices);
    graph->depth = (int *)malloc(sizeof(int) * numVertices);
    graph->longBranch = (int *)malloc(sizeof(int) * numVertices);
    

    for (int i = 0; i < numVertices; i++)
    {
        graph->adj_list[i] = NULL;
        graph->cycle1[i] = -1;
        graph->depth[i] = 0;
        graph->longBranch[i] = -1;
    }

    return graph;
}

struct Group *createGroup(int numvertices, const char* key)
{
    
    struct Graph *newGraph = createGraph(numvertices);

    struct Group *new = (struct Group *)malloc(sizeof(struct Group));
    strcpy(new->id , key);
    new->graph = newGraph;
    new->members = NULL;
    new->nextGroup = NULL;
    
    
    return new;
}

struct Group *newGroup(struct Group *group, int numvertices, const char* key)
{
    
    struct Group *new = createGroup(numvertices, key);
    struct Group *temp = group;

    while (temp->nextGroup != NULL)
    {

        temp = temp->nextGroup;
    }

    temp->nextGroup = new;
    return group;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}