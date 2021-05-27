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
void add_list_toTop(node *list1, node *list2)
{

    node *head1 = list1, *head2 = list2;
    node *temp1 = list1;
    while (temp1 != NULL)
    {
        if (temp1->next == NULL)
        {
            temp1->next = head2;
            list2 = head1;
            break;
        }
        temp1 = temp1->next;
    };
}

int main()
{
    node *l1 = creat_list(4, 1);
    node *l2 = creat_list(8, 1);
    printf("L1:");
    display(l1);
    printf("L2:");

    display(l2);
    printf("#################\n");
    add_list_toTop(l1, l2);
    printf("L2: befor adding l1 to it\n");

    display(l2);

    return 0;
};