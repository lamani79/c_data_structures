// #################################
// #################################
// #################################

// transform array to linked list

// #################################
// #################################
// #################################

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;

    struct node *next;
} node;

node *array_to_list(char arr[5][10], int array_size)
{
    node *head, *temp, *new;
    head = NULL;
    int x;
    for (x = 0; x < array_size; x++)
    {

        new = (node *)malloc(sizeof(node));
        new->data = arr[x];
        new->next = NULL;

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
void display_array(char arr[5][10], int size)
{
    int i;
    printf("{");
    for (i = 0; i < size; i++)
    {
        printf("%s", arr[i]);
        if (i + 1 != size)
            printf(",");
    }
    printf("}\n");
}
int main()
{
    char arr[5][10] = {"amira", "tamer", "yasser", "sarim", "osama"};
    display_array(arr, 5);
    node *new_list = array_to_list(arr, 5);
    display_list(new_list);

    return 0;
}