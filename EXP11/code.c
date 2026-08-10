#include <stdio.h>
#include <string.h>

struct Symbol
{
    char name[20];
    char type[20];
    int address;
};

struct Symbol table[50];
int count = 0;

void insert()
{
    printf("Enter symbol name: ");
    scanf("%s", table[count].name);

    printf("Enter type: ");
    scanf("%s", table[count].type);

    printf("Enter address: ");
    scanf("%d", &table[count].address);

    count++;

    printf("Symbol inserted successfully.\n");
}

void search()
{
    char name[20];
    int i, found = 0;

    printf("Enter symbol to search: ");
    scanf("%s", name);

    for(i = 0; i < count; i++)
    {
        if(strcmp(table[i].name, name) == 0)
        {
            printf("Symbol found\n");
            printf("Name    : %s\n", table[i].name);
            printf("Type    : %s\n", table[i].type);
            printf("Address : %d\n", table[i].address);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Symbol not found.\n");
}

void deleteSymbol()
{
    char name[20];
    int i, j, found = 0;

    printf("Enter symbol to delete: ");
    scanf("%s", name);

    for(i = 0; i < count; i++)
    {
        if(strcmp(table[i].name, name) == 0)
        {
            for(j = i; j < count - 1; j++)
                table[j] = table[j + 1];

            count--;
            found = 1;

            printf("Symbol deleted successfully.\n");
            break;
        }
    }

    if(!found)
        printf("Symbol not found.\n");
}

void display()
{
    int i;

    printf("\nSymbol Table\n");
    printf("--------------------------------\n");
    printf("Name\tType\tAddress\n");
    printf("--------------------------------\n");

    for(i = 0; i < count; i++)
    {
        printf("%s\t%s\t%d\n",
               table[i].name,
               table[i].type,
               table[i].address);
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Delete");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                search();
                break;

            case 3:
                deleteSymbol();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}
