#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;

    struct node *next;
} node;

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

int main()
{
    node *new_list = creat_list(5, 1);
    display(new_list);

    return 0;
}