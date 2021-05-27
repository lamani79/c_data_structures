#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;

    struct node *next;
} node;
// make second parameter (auto_fill) == 1 to auto fill the linked_list
// or 0 to fill it manually
node *creat_list(int size, int auto_fill)
{
    if (size <= 0)
        return NULL;
    else
    {
        node *head, *temp, *new;
        head = NULL;
        int x;
        for (x = 1; x <= size; x++)
        {

            new = (node *)malloc(sizeof(node));
            // if Unable to allocate memory
            if (new == NULL)
            {
                printf("Unable to allocate memory.");
                exit(0);
            }
            new->next = NULL;
            if (auto_fill == 1)
            {
                new->data = x;
            }
            else
            {
                printf("Entre data for index: %d\n", x - 1);
                scanf("%d", &new->data);
            }
            if (head == NULL)
            {
                head = temp = new;
            }
            else
            {
                temp->next = new;
                temp = new;
            }
        }
        return head;
    }
}

void display(node *list)
{
    printf("[");
    while (list != NULL)
    {
        printf("%d", list->data);
        if (list->next != NULL)
            printf(",");
        list = list->next;
    }

    printf("]\n");
}

void add_list_to_end(node *l1, node *l2)
{
    node *temp2 = l2;
    while (temp2 != NULL)
    {
        if (temp2->next == NULL)
        {
            temp2->next = l1;
            break;
        }

        temp2 = temp2->next;
    }
};

int main()
{
    node *l1, *l2;
    l1 = creat_list(5, 1);
    l2 = creat_list(3, 1);
    printf("l1:");
    display(l1);
    printf("l2:");
    display(l2);

    printf("####################\n");
    add_list_to_end(l1, l2);
    printf("l2 after add l1:\nl2:");
    display(l2);

    return 0;
}