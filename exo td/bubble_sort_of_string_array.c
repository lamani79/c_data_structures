#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int main()
{
    int num[5] = {5, 4, 3, 2, 1};
    char names[5][10] = {"yasser", "tamer", "amira", "sousou", "houria"};

    // bubble sort :
    // allways iterate num of item -1;
    // for beter performence y<5-x;
    int x, y;
    char temp[10];

    for (y = 1; y <= 5 - 1; y++)
    {

        for (x = 0; x <= (5 - 1) - y; x++)
        {

            if (names[x][0] > names[x + 1][0])
            {
                strcpy(temp, names[x]);
                // temp = names[x];
                strcpy(names[x], names[x + 1]);

                // names[x] = names[x + 1];
                strcpy(names[x + 1], temp);

                // names[x + 1] = temp;
            }
        }
        // to see how sort work
        // display_arr(num);
    }

    display_arr_str(names);

    return 0;
}