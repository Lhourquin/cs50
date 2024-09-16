#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
    // get a string
    char *s  = get_string("s: ");
    if(s == NULL)
    {
        return 1;
    }
    //Allocate memory for another string
    char *t = malloc(strlen(s) + 1);
    if(t == NULL)
    {
        return 1;
    }

    //copy string into memroy, including `\0`
    strcpy(t, s);
    //capitalize copy
    if(strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    puts("Output");
    //print string twice
    printf("s: %s\n", s);
    printf("t: %s\n", t);
    free(t);
    return 0;
}
