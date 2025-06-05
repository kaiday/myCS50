#include <stdio.h>
#include <stdlib.h>

//Singly-Linked Lists
typedef struct node
{
    int number;
    struct node *next; // use to point to another
}
node;

int main(int argc, char *argv[])
{
    node *list = NULL; // now main node is empty
                      // or linked-list of size 0

    node *n = malloc(sizeof(node)); // just temporary node

    if( n == NULL)
    {
        printf("An error has occur, can not allocate!\n");
        return 1;
    }

    n -> number = 1; // can be understand as (*n).number which dereference the pointer n and access the value number
    n -> next = NULL; // the end of the linked-list

    list = n; // now our main node has value 1 and a pointer NULL

    n = malloc(sizeof(node)); // make n point to another node that different from list

    n -> number = 2;
    n -> next = list; // this make the node that contains value 2 point to the node that has value 1 in node list

    list = n; // this make the pointer list point to the node that contains value 2
    // list (start) -> 2 -> 1 -> NULL (end)
    // what u see here is the method of insertion in linked-list, always make sure not break the chain or lose the anchor

    // iterator thru the list
    node *ptr = list; // point to the beginning of the list

    while(ptr != NULL)
    {
        printf("%i ", ptr -> number);
        ptr = ptr -> next;
    }
    printf("\n");

    free(n); // free the memory to reduce wastage of memory after finish using
}