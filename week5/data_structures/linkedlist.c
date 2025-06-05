#include <stdio.h>
#include <stdlib.h>

//Singly-Linked Lists
typedef struct node
{
    int number;
    struct node *next; // use to point to another
}
node;

//Doubly-Linked Lists
typedef struct dllist
{
    int number;
    struct dllist* prev;
    struct dllist* next;
}
dllist;

int main(int argc, char *argv[])
{
    node *list = NULL;

    for(int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            printf("Memory not allocate\n");
            free(n);
            return 1;
        }

        n->number = number;
        n->next = NULL;

        n->next = list; // prepending or like enqueue in Queue
        list = n;

    }
    // create iterator thru the list
    node *ptr = list; // point to the beginning of the list

    while(ptr != NULL)
    {
        printf("%i ", ptr -> number);
        ptr = ptr -> next;
    }
/*  this will work the same
    for(node *ptr = list; ptr!= NULL; ptr = ptr ->next)
    {
        printf("%i ", ptr -> number);
    }
*/
    // free the whole list node by node
    ptr = list;
    while(ptr != NULL)
    {
        node *next = ptr->next; //create an anchor
        free(ptr);
        ptr=next;
    }
    printf("\n");
}