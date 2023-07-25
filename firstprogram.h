

void firstprogram()
{

    int numVertices;
    char id[100];
    struct Group *group = NULL;

    printf("-------------Hello--------------!\n");
    char choice[10];
    if (group == NULL)
    {
        printf("    No group is present. \n\n     Would you like to Create a group ( yes / no ) \n");
        scanf("%s", choice);
        if (strcmp(choice, "yes") == 0)
        {
            printf("Enter the Group Name:");
            clearInputBuffer();
            fgets(id, sizeof(id), stdin);
            id[strcspn(id, "\n")] = '\0';
            printf("Enter the number of members in the group :");
            scanf("%d", &numVertices);
            group = createGroup(numVertices, id);
            group = start(group);
        }
        else
        {
            printf("Thank you for using our service. \n Have a nice day !.\n");
        }
    }

    while (strcmp(choice, "yes") == 0)
    {
        printf("\n");
        printf("\n");

        printf("---------------------------------------------------------------------------------------------------------\n");
        printf("1) Want to add new Group? (newgroup):\n");
        printf("\n2) Show the present Groups? (groups): \n");
        printf("\n3) Enter the Group? (start):\n ");
        printf("\n4) End the program. (end): ");

        scanf("%s", &choice);
        printf("\n");
        printf("\n");
        printf("\n");

        if (strcmp(choice, "newgroup") == 0)
        {
            printf("Enter the New Group Name :");
            clearInputBuffer();
            fgets(id, sizeof(id), stdin);
            id[strcspn(id, "\n")] = '\0';
            printf("Enter the number of members in the group :");
            scanf("%d", &numVertices);
            group = newGroup(group, numVertices, id);
            strcpy(choice, "yes");
        }
        else if (strcmp(choice, "groups") == 0)
        {
            struct Group *temp = group;
            int count = 1;
            char id_copy[100];
            printf("\n");
            printf("The groups which are present  now :\n");
            while (temp != NULL)
            {
                printf(" %d)  %s\n", count, temp->id);
                temp = temp->nextGroup;
                count++;
            }
            strcpy(choice, "yes");
            printf("\n");
            printf("\n");
        }
        else if (strcmp(choice, "start") == 0)
        {
            group = start(group);
            strcpy(choice, "yes");
            printf("\n");
            printf("\n");
        }
        else if (strcmp(choice, "end") == 0)
        {
            printf("Thank you for using our service \n Have a nice day !.\n");
        }
        else
        {
            printf("you entered something wrong.\n Please enter the appropriate command\n");
            strcpy(choice, "yes");
            printf("\n");
        }
    }
}