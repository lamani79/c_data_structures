#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;

	struct node *next;
} node;
// function to creat a list:
int creat_list(int size)
{
	// if size is negative value:
	size = abs(size);
	if (size == 0)
	{
		return 0;
	}
	else
	{
		node *head, *new_node, *temp;
		head = NULL;
		int x;
		for (x = 1; x <= size; x++)
		{
			new_node = (node *)malloc(sizeof(node));
			new_node->next = NULL;
			new_node->data = x;
			if (head == NULL)
			{
				head = temp = new_node;
			}
			else
			{
				temp->next = new_node;
				temp = new_node;
			}
		}
		//	return first elemnt of list
		return head;
	}
};
//display the list:
void display_list(node *list)
{

	printf("\n[");
	while (list != NULL)
	{
		printf("%d", list->data);
		//		to avoid ',' in the end of the list
		if (list->next != NULL)
			printf(",");
		list = list->next;
	}
	printf("]\n");
};
// return list size:
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

// add item to list in the first position:(return new list):
node *push_first(node *list, int item)
{
	// list  == the list == head of list;
	node *new_item;
	new_item = (node *)malloc(sizeof(node));
	new_item->data = item;
	// new_item->index = 0;

	new_item->next = list;
	list = new_item;
	return list;
}

// add item at the end of the list (return new list):
node *push_last(node *list, int item)
{
	// I use head this time because when loop throw the list the list change
	//  but I need it to == the first element in the list
	// to use it again wheen display or ..
	// so a return it
	node *head;
	head = list;
	while (list != NULL)
	{
		if (list->next == NULL)
		{
			node *new_item;
			new_item = (node *)malloc(sizeof(node));
			new_item->data = item;
			new_item->next = NULL;
			list->next = new_item;
			break;

			/* code */
		}
		list = list->next;
	}
	return head;
}

// get index of  an item in the list: (the first item that much return)
int list_index(node *list, int item)
{
	int index = 0;
	while (list != NULL)
	{
		if (list->data == item)
		{
			return index;
		}
		list = list->next;
		index++;
	}
	// return -1 if item not found
	return -1;
}

// get item in such index in the list:
int get_item_list(node *list, int index_inp)
{
	int index;
	while (list != NULL)
	{
		if (index == index_inp)
		{
			return list->data;
		}
		list = list->next;
		index++;
	}
	// return -1 if index not found
	return -1;
}

// get if an item is existe in the list and how many time:
int *list_existe(node *list, int item)
{
	// return array {is_existe , how_many_times};
	// is_existe : 1== if true || O == if flase:
	// how_many_times == positive number
	int result[2] = {0, 0};
	int *p;
	p = result;
	while (list != NULL)
	{
		if (list->data == item)
		{
			result[0] = 1;
			result[1]++;
		}

		list = list->next;
	}
	return p;
}

// get indexes :
void display_indexes_list(node *list)
{
	int index = 0;
	while (list != NULL)
	{
		printf("value: %d	index: %d\n", list->data, index);

		list = list->next;
		index++;
	}
}

// remove item with his index fom list:

node *remove_list(node *list, int index_inp)
{
	int index = 0;
	node *head, *temp;
	head = list;
	if (list_size(list) > index_inp)
	{
		// if the list is empty
		if (head == NULL)
			// return head (the orginal list if the list is empty)
			return head;
		if (index_inp == 0)
		{
			// delet from the first position;

			head = list->next;
			free(list);
			return head;
		}
		// if the index is in the end of the list;
		if (index_inp == list_size(list) - 1)
		{
			while (1 == 1)
			{
				if (list->next == NULL)
				{
					temp->next = NULL;
					free(list);
					return head;
				}
				temp = list;

				list = list->next;
			}
		}
		//remove item from the midle of the list:
		int i = 0;
		while (list != NULL)
		{
			// way 1:
			// ##########################

			// if (index == index_inp)
			// {
			// 	temp->next = list->next;
			// 	list->next = NULL;
			// 	free(list);
			// 	return head;
			// }
			// temp = list;
			// ##########################
			// second way:
			if (index == index_inp - 1)
			{
				temp = list->next;
				list->next = temp->next;
				free(temp);
				return head;
			}
			index++;
			i++;
			list = list->next;
		}
	}
	else
	{
		// return head (the original list if no index much)
		return head;
	}

	// else if ()
	// {
	// }
}

int main()
{
	node *new_list = creat_list(10);
	display_list(new_list);
	// node *my_list = (node *)creat_list(10);
	// display_list(my_list);

	// my_list = remove_list(my_list, 3);
	// display_list(my_list);

	// printf("the size of the list = %d\n", list_size(my_list));

	// printf("add 999 to the list and display it: \n");

	// my_list = push_first(my_list, 999);
	// display_list(my_list);
	// printf("the size of the list = %d\n", list_size(my_list));

	// printf("\nAdd 888 to the last of the list: \n");

	// my_list = push_last(my_list, 10);
	// display_list(my_list);
	// printf("\nthe size of the list = %d\n", list_size(my_list));

	// printf("\nIndex of number 9 is : %d\n", list_index(my_list, 9));

	// printf("\nget the value of the index 8\n");
	// printf("\n the value of index 8 is = %d\n", get_item_list(my_list, 8));

	// // display_indexes_list(my_list);

	// int *tab = list_existe(my_list, 10);
	// printf("\ncheck if num 1 is in the list and how many time it repeat\n");
	// printf("\nnum 100 is in the list: %d\nand it's repeat %d times\n", *tab, *(tab + 1));

	// // printf("\n remove index 1 from the list \n");
	// // my_list = remove_list(my_list, 1);
	// // display_list(my_list);

	// // printf("\n\n");
	// node *list2 = creat_list(0);
	// display_list(list2);
	// list2 = remove_list(list2, 0);
	// printf("Ok");
	// display_list(list2);
	return 0;
}
