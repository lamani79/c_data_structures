#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data[10];

    struct node *next;
} node;

int main()
{
    int num;
    printf("entre a int num less or equal to 16\n");
    scanf("%d", &num);
    if (num > 16)
    {
        printf("\ninput error : you should entra num less or equal to 16\n");
    }
    else
    {
        char chain[num][10];

        int j;
        for (j = 0; j < num; j++)
        {
            printf("\n entre a string number: %d\n", j + 1);
            scanf("%s", &chain[j]);
        }
        // #############################################
        // copy the array to linked list;
        node *head, *temp, *new;
        head = NULL;
        int x;
        for (x = 0; x < num; x++)
        {

            new = (node *)malloc(sizeof(node));
            strcpy(new->data, chain[x]);
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
        // ###############################################################
        // display the list

        node *temp_of_print = head;
        printf("[");
        while (temp_of_print != NULL)
        {
            printf("%s", temp_of_print->data);
            if (temp_of_print->next != NULL)
                printf(",");
            temp_of_print = temp_of_print->next;
        }

        printf("]\n");

        // ####################################################################
        // sort the linked list

        char swith_name[10];

        node *head_2, *temp_2;
        head_2 = head;
        int z;
        for (z = 1; z < num; z++)
        {
            // head 2 is the head of sorted list
            head = head_2;
            while (head->next != NULL)
            {

                if (head->data[0] > head->next->data[0])
                {
                    strcpy(swith_name, head->data);
                    strcpy(head->data, head->next->data);
                    strcpy(head->next->data, swith_name);
                }

                head = head->next;
            }
        }

        // ###############################################################
        // display the list

        node *temp_of_print_2 = head_2;
        printf("[");
        while (temp_of_print_2 != NULL)
        {
            printf("%s", temp_of_print_2->data);
            if (temp_of_print_2->next != NULL)
                printf(",");
            temp_of_print_2 = temp_of_print_2->next;
        }

        printf("]\n");

        // ###############################################################
        // copy sorted list inside new array
        char sorted_array[num][10];
        int s = 0;
        node *temp_3 = head_2;
        while (temp_3 != NULL)
        {
            strcpy(sorted_array[s], temp_3->data);
            s++;
            temp_3 = temp_3->next;
        }

        // ################################################################
        // print the new sorted array
        printf("{");
        for (s = 0; s < num; s++)
        {
            printf("%s", sorted_array[s]);

            if (s != num - 1)
                printf(",");
        }
        printf("}\n");
    }

    return 0;
}