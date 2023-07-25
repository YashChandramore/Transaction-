
struct Group *start(struct Group *group)
{
    char choice[10];
    // printf("Want to start to add the transactions(yes / no):");
    // scanf("%s", choice);
    strcpy(choice, "yes");
    while (strcmp(choice, "yes") == 0)
    {
        struct Group *temp = group;
        /* code */

        int count = 1;
        char id_copy[100];
        printf("\n");
        printf("The groups which are present  now  :\n");
        while (temp != NULL)
        {
            printf("   %d)", count);
            printf(" %s\n", temp->id);
            temp = temp->nextGroup;
            count++;
        }
        printf("\n");

        printf("Which group you want to enter :");
        clearInputBuffer();
        fgets(id_copy, sizeof(id_copy), stdin);
        id_copy[strcspn(id_copy, "\n")] = '\0';
        temp = group;

        while (temp != NULL)
        {
            if (strcmp(temp->id,id_copy)==0)
            {
                struct Graph *g = temp->graph;
                temp = addDebts(temp, g);

                return group;
            }
            else
            {
                temp = temp->nextGroup;
            }
        }
        printf("The  entered group is not present\n Want to try again (yes / no)");
        scanf("%s", choice);
    }
}