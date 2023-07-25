

struct Group *addDebts(struct Group *group, struct Graph *graph)
{

    int numPeople = 0;
    int maxPeople = 0;
    char choice[10];

    printf("\nWant to add debt? (yes/no): ");
    scanf("%s", choice);

    while (strcmp(choice, "yes") == 0)
    {
        char byWho[100];
        char toWho[100];
        int amount;

        printf("Who owes: ");
        scanf("%s", byWho);

        printf("To who: ");
        scanf("%s", toWho);

        // Convert strings to lowercase
        for (int i = 0; byWho[i]; i++)
        {
            byWho[i] = tolower(byWho[i]);
        }
        for (int i = 0; toWho[i]; i++)
        {
            toWho[i] = tolower(toWho[i]);
        }

        int byWhoIndex = -1;
        int toWhoIndex = -1;

        // Find existing people or add new people
        for (int i = 0; i < numPeople; i++)
        {
            if (strcmp(group->members[i].name, byWho) == 0)
            {
                byWhoIndex = i;
            }
            if (strcmp(group->members[i].name, toWho) == 0)
            {
                toWhoIndex = i;
            }
        }

        if (byWhoIndex == -1)
        {
            if (numPeople == maxPeople)
            {
                maxPeople += 10;
                group->members = realloc(group->members, maxPeople * sizeof(Person));
                if (group->members == NULL)
                {
                    printf("Memory allocation failed. Exiting...\n");
                }
            }

            group->members[numPeople].name = malloc((strlen(byWho) + 1) * sizeof(char));
            strcpy(group->members[numPeople].name, byWho);
            group->members[numPeople].assignedInteger = numPeople;

            byWhoIndex = numPeople;
            numPeople++;
        }

        if (toWhoIndex == -1)
        {
            if (numPeople == maxPeople)
            {
                maxPeople += 10;
                group->members = realloc(group->members, maxPeople * sizeof(Person));
                if (group->members == NULL)
                {
                    printf("Memory allocation failed. Exiting...\n");
                }
            }

            group->members[numPeople].name = malloc((strlen(toWho) + 1) * sizeof(char));
            strcpy(group->members[numPeople].name, toWho);
            group->members[numPeople].assignedInteger = numPeople;

            toWhoIndex = numPeople;
            numPeople++;
        }

        printf("How much: ");
        scanf("%d", &amount);

        // Update debt
        addEdge(graph, byWhoIndex, toWhoIndex, amount);
        printf("Debt updated!\n");

        printf("\nWant to add debt? (yes/no) ");
        scanf("%s", choice);
    }

    group = executeFunction(group, graph);
    return group;
}