#include <stdio.h>
#include <stdlib.h>
struct list
{
    struct list *next;
    int val;
};

struct list *STARTNODE(int val)
{
    struct list *ptr = (struct list *)malloc(sizeof(struct list));
    ptr->val = val;
    ptr->next = NULL;
    return ptr;
}

struct list *createnode_atlast(struct list *last, int val)
{
    struct list *ptr = (struct list *)malloc(sizeof(struct list));
    ptr->val = val;
    last->next = ptr;
    ptr->next = NULL;
    last = ptr;

    return last;
}

struct list *createnode_atbeginning(struct list *start, int val)
{
    struct list *ptr = (struct list *)malloc(sizeof(struct list));
    ptr->val = val;
    ptr->next = start;
    return ptr;
}

struct list *traversal(struct list *start)
{
    struct list *ptr;
    do
    {
        printf("value = %d\n", start->val);
        ptr = start->next;
        start = start->next;
    } while (ptr != NULL);
    return ptr;
}

struct list *reverse_linkedlist(struct list *start)
{
    struct list *temp;
    struct list *prev;
    struct list *next;
    prev = start;
    temp = start->next;
    start->next = NULL;
    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    temp->next = prev;
    return prev;
}

int main()
{
    int val, choice;
    struct list *start;
    struct list *last;

    printf("enter the value of first node : ");
    scanf("%d", &val);
    start = STARTNODE(val);
    while (choice != 4)
    {
        printf("Chose one from the below options...\n");
        printf("\n1.create node at beginning\n2.creatnode at last\n3.traverse the linked list\n4.Exit");
        printf("\n Enter your choice \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("enter the value to store in node added at beginnig : ");
            scanf("%d", &val);
            start = createnode_atbeginning(start, val);
            break;
        }
        case 2:
        {
            printf("enter the value to store in node added at last : ");
            scanf("%d", &val);
            createnode_atlast(start, val);
            break;
        }
        case 3:
        {
            traversal(start);
            break;
        }
        case 4:
        {
            printf("Exiting....\n");
            break;
        }
        default:
        {
            printf("Please Enter valid choice ");
        }
        };
    }
}