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
int list_size(node *l)
{
    int size;
    while (l != NULL)
    {
        size++;
        l = l->next;
    }
    return size;
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
node *get_last(node *l)
{

    while (l != NULL)
    {
        if (l->next == NULL)
        {
            return l;
        }
        l = l->next;
    }
}

void add_list_to_index(node *l1, node *l2, int index)
{
    if (index >= list_size(l2) - 1 || index <= 0)
    {
        printf("error in index it must be less than last index of list _2 and beggar than 0");
    }
    else
    {
        int i = 0;

        node *temp2 = l2;
        while (temp2 != NULL)
        {
            if (i == index - 1)
            {
                /*get last node in L1*/
                node *last_l1 = get_last(l1);
                last_l1->next = temp2->next;
                temp2->next = l1;
                break;
            }

            i++;
            temp2 = temp2->next;
        }
    }
}
int main()
{

    node *l1, *l2;
    l1 = creat_list(5, 1);
    /*entre value of l2 manually to make different between l1 and l2 */
    l2 = creat_list(3, 0);
    printf("l1:");
    display(l1);
    printf("l2:");
    display(l2);

    printf("####################\n");
    add_list_to_index(l1, l2, 1);
    printf("\nl2: ");
    display(l2);
    return 0;
}