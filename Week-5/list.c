// Prepends numbers to a linked list, using while loop to print 
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int number;
    struct node *next;
} node;

int main(int argc, char *argv[])
{
    //Memory for numbers
    node *list = NULL;

    //for each command lune argument
    for (int i = 1; i < argc; i++) {
        //convert argument to int
        int number = atoi(argv[i]);
        
        //allocate node for number
        node *n = malloc(sizeof(node));
        if(n == NULL){
            return 1;
        }
        n->number = number;
        n->next = NULL;

        //Prepend node to list
        n->next = list;
        list = n;
    }

    //print numbers
    node *ptr = list;
    while (ptr != NULL) {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }

    ptr = list;
    while (ptr != NULL) {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}

