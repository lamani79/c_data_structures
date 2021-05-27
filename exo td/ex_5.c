#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data[10];

    struct node *next;
} node;
node *creat_str_linked_list(int size)
{
    node *header, *temp, *new;
    int x;
    header = NULL;
    for (x = 0; x < size; x++)
    {

        new = (node *)malloc(sizeof(node));
        new->next = NULL;

        printf("entre string num %d: ", x + 1);
        scanf("%s", &new->data);

        if (header == NULL)
        {
            header = temp = new;
        }
        else
        {

            temp->next = new;
            temp = new;
        }
    }
    return header;
}

void display_list(node *list)
{
    printf("[");
    while (list != NULL)
    {
        printf("%s", list->data);
        if (list->next != NULL)
            printf(",");
        list = list->next;
    }

    printf("]\n");
}
int list_size(node *list)
{
    int size = 0;
    while (list != NULL)
    {
        size++;
        list = list->next;
    }

    return size;
}

int main()
{
    //  creat linked list of strings:
    node *new_list = creat_str_linked_list(3);
    // display the linked list
    display_list(new_list);
    printf("###############\n");

    void push_str_last(char data[10])
    {
        node *temp, *new_item;
        temp = new_list;
        new_item = (node *)malloc(sizeof(node));
        new_item->next = NULL;
        strcpy(new_item->data, data);

        while (temp != NULL)
        {
            if (temp->next == NULL)
            {
                temp->next = new_item;
                break;
            }
            temp = temp->next;
        }
    }

    push_str_last("last");
    display_list(new_list);
    return 0;
}