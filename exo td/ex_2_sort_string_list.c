#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data[10];

    struct node *next;
} node;

void display_arr_int(int arr[5])
{
    int x;

    for (x = 0; x < 5; x++)
    {
        printf("%d", arr[x]);
    }
}
void display_arr_str(char arr[5][10])
{
    int x;

    for (x = 0; x < 5; x++)
    {
        printf("%s\n", arr[x]);
    }
}
node *array_to_list(char arr[5][10], int array_size)
{
    node *head, *temp, *new;
    head = NULL;
    int x;
    for (x = 0; x < array_size; x++)
    {

        new = (node *)malloc(sizeof(node));
        //new->data = arr[x];
        strcpy(new->data, arr[x]);
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

node *sort_string_list(node *list)
{
    char swith_name[10];
    int size = list_size(list);
    node *head, *temp;
    head = list;
    int x;
    for (x = 1; x < size; x++)
    {
        list = head;
        while (list->next != NULL)
        {

            if (list->data[0] > list->next->data[0])
            {
                strcpy(swith_name, list->data);
                strcpy(list->data, list->next->data);
                strcpy(list->next->data, swith_name);
            }

            list = list->next;
        }
    }
    return head;
}

int main()
{
    char names[5][10] = {"yasser", "tamer", "amira", "sousou", "houria"};
    // creat new string list from array
    node *names_list = array_to_list(names, 5);
    printf("\n\n\nlinked list before sorting it:\n");
    display_list(names_list);
    // sort the string linked list item
    node *sorted_list = sort_string_list(names_list);
    printf("\n\n\nlinked list after sorting:\n");

    display_list(sorted_list);
    // printf("%d\n", list_size(sorted_list));

    return 0;
}