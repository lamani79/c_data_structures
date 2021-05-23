#include <stdio.h>
#include <stdlib.h>

int main()
{

    char tab[3][10] = {
        "spike",
        "tom",
        "jerry"};

    int x = 0;

    void bubble_sort()
    {
        int x, y;

        for (x = 0; x < 3; x++)
        {

            for (y = 1; y < 3; y++)
            {
                if (tab[y] > tab[y + 1])
                {
                    printf("change");
                }
            }
        }
    }

    void print_array()
    {
        int x;
        for (x = 0; x < 6; x++)
        {
            printf("%c\n", tab[x]);
        }
    }

    print_array();
    printf("############################\n");
    bubble_sort();
    print_array();

    char a = 'A';

    printf("############################\n");

    printf("%d", 'a' < 'b');

    return 0;
}
