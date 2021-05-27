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

void push_str_to_midle(int index, char data[10]);
int main()
{

    //  creat linked list of strings:
    node *new_list = creat_str_linked_list(5);
    // display the linked list
    display_list(new_list);
    printf("###############\n");

    void push_str_to_midle(int index, char data[10])
    {
        if (index >= list_size(new_list) || index <= 0)
        {
            printf("your index is note in the midle of the list\n");
            printf("it must be in bigger than 0 and less than size of list");
        }

        else
        {
            node *temp, *new_item;
            temp = new_list;
            int i = 0;
            while (temp != NULL)
            {
                if (i == index - 1)
                {
                    new_item = (node *)malloc(sizeof(node));
                    strcpy(new_item->data, data);
                    new_item->next = temp->next;
                    temp->next = new_item;
                }
                temp = temp->next;
                i++;
            }
        }
    }
    printf("\n########\n");
    push_str_to_midle(3, "mama");

    display_list(new_list);
    return 0;
}