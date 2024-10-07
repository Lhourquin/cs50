# Data Structures

* [Welcome!](#welcome)
* [Data Structures](#data-structure)
* [Stack and Queues](#stacks-and-queues)
* [Jack Learns the Facts](#jack-learns-the-facts)
* [Resizing Arrays](#resizing-arrays)
* [Linked Lists](#linked-lists)
* [Trees](#trees)
* [Dictionaries](#dictionaries)
* [Hashing and Hash Tables](#hashing-and-hash-tables)
* [Tries](#tries)
* [Summing Up](#summing-up)

## Welcome

* All the prior weeks have presented you with the fundamental building blocks of programming
* All you have learned in C will enable you to implement these building blocks in higher-level programming languages such as Python.
* Today, we are going to talk about organizing data in memory and design possibilities that emerge from your growing knowledge.

## Data Structures

* *Data structures*  essentially are forms of organization in memory.
* There are many ways to organize data in memory.
* *Abstract data structures* are those that we can conceptually imagine. When learning about computer science, it's often useful to begin with these conceptual data structures. Learning these will make it easier later to understand how to implement more concrete data structures.

## Stacks and Queues

* *Queues*  are one form of abstract data structure.
* Queues have specific properties. Namely, they are *FIFO* of "first in first out". You can imagine yourself in a line for a ride at an amusement park. The first person in the line gets to go on the ride first. The last person gets to go on the ride last.
* Queues have specific actions associated with them. For example, an item can be *enqueued* ; that is, the item can join them line or queue. Further, an item can be *dequeued*  or leave the queue once it reaches the front of the line.
* Queues contrast a *stack* . Fundamentally, the properties of a stack are different than a queue. Specifically, it is *LIFO* or "last in first out". Just like stacking trays in a cafetaria, a tray that is placed in a stack last is the first that may be picked up.
* Stacks have specific actions associated with them. For example, *push* places something on top of a stack. *Pop*  is removing something form the top of stack.
* In code, you might imagine s stack as follows:

```C
typedef struct
{
    person people[CAPACITY];
    int size;
}
stack;
```

Notice that an array called people is of type `person`. The `CAPACITY` is how hight the stack could be. The integer `size` is how full the stack actually is, regardless of how much it *could*  hold.

* You might imagine that the above code has a limitation. Sice the capacity of the array is always predetermined in this code. Therefore, the stack may always be oversized. You might imagine only using one place in the stack out of 5000.
* It would be nice for our stack to be dynamic - able to grow as items are added to it.

## Jack Learns the Fatcs

* We watched a video  called [Jack Learns the Facts](https://www.youtube.com/watch?v=ItAG3s6KIEI) by Professor Shanon Duvall of Elon University.

## Resizing Arrays

* Rewinding to Week 2, we introduced you to your first data structure.
* An array is a block of contiguous memory
* You might imagine an array as follows:

![array](img/array.png)

* In memory, there are other values being stored by other programs, functions, and variables. Many of these may be unused garbage values that were utilized at one point but available now for use.

![hello-world](img/garbage-value.png)

* Imagine you wanted to store a fourth value `4` in our array? What would be needed is to allocate a new area of memory and move the old array to a new one. Initially, this new area of memory would be populated with garbage values.

![fourth](img/fourth.png)

* As values are added to this new area of memory, old garbage values would be overwritten.

![overwritten](img/overwritten.png)

* Eventually, all old garbage values would be overwritten with our new data.

![new-data](img/new-data.png)

* One of the drawbacks of this approach is that it's bad design: Every time we add a number, we have to copy the array item by item.
* Wouldn't it be nice if we able to put the `4` somewhere else in memory? By definition, this would no longer be an array because `4` would no longer be in contiguous memory.
* In your terminal, type `code list.c` ans write code as follows:

```C
// implements a list of numbers with an array of fixed size

#include <stdio.h>

int main(void)
{
    //List of size 3
    int list[3];

    // Initialize list with numbers
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    for (int i = 0 ; i < 3; i++)
    {
        printf("%i\n", list[i]);
    }
}
```

Notice that the above is very much like what we learned earlier in this course. We have memroy being preallocated for three items.

* Building upon our knowledge obtained more recently, we can leverage our understanding of pointers to create a better design in this code. Modify your code as follows:

```C
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //List of size 3
    int *list = malloc(3 * sizeof(int));
    if(list == NULL)
    {
        return 1;
    }

    // Initialize list with numbers
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // List of size 4
    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL) {
        free(list);
        return 1;
    }

    // Copy list of size 3 into list of size 4
    for (int i = 0 ; i < 3; i++)
    {
        tmp[i] = list[i];
    }

    //Add number to list of size 4
    tmp[3] = 4;

    // Free list of size 3
    free(list);

    //Remember list of size 4
    list = tmp;

    //Print list
    for (int i =0; i < 4; i++) {
        printf("%i\n", list[i]);
    }

    // Free list
    free(list);
    return 0;
}
```

Notice that a list of size three integers is created. Then, three memory addresses can be assigned the values `1, 2, and 3`. Then, a list of size four is created. Next, the list is copied from the first to second. The value for the `4` is added to the `tmp` list. Since the block of memory that `list` points to is no longer used, it is freed using the command `free(list)`. Finally, the compiler is told to point `list` pointer now to the block of memory that `tmp` points to. The contens of `list` are printed and then freed.

* It's useful to think about `list` and `tmp` as both signs that point at a chunk of memory. As in the example above, `list` at one point *pointed*  to an array of size 3. By the end, `list` was told to point to a chunk of memory of size 4. Technically, by the end of the above code, `tmp` and `list` both pointed to the same block of memory.
* One may be tempted to allocate way more memory than required for the list, such as 30 items instead of the required 3 or 4. However, this is bad design as it taxes system resources when they are not potentially needed. Further, there is little guarantee that memory for move than 30 items will be needed eventually.
