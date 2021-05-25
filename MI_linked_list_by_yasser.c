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

void print_item_by_index(node *list, int index)
{
    if (index < 0 || index >= list_size(list))
    {
        printf("you must make the index follow this rule ====>   0<=index<list_size");
    }
    else
    {
        int i = 0;
        while (list != NULL)
        {
            if (i == index)
            {
                printf("list[%d] == %d", index, list->data);
            }
            i++;
            list = list->next;
        }
    }
}

int get_index(node *list, int item)
{
    // this function return first index if thre is many items that much;
    int x = 0;
    while (list != NULL)
    {
        if (list->data == item)
        {
            printf("yes\n");
            return x;
        }
        x++;
        list = list->next;
    }
    return -1;
}

int main()
{
    node *new_list = creat_list(5, 1);
    display(new_list);
}