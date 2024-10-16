# Week 1 - C

Machine only understand binary, where humans write *source code*, a list of instructions for the computer that is human readable, machine only understand what we can now call *machine code*. This machine code is pattern of ones and zeros that produces a desired effect. It turns out that we can convert *source code* into `machine code` using a very special piece of software called a *compiler*. We will be introducing you to a compiler that will allow you to convert source code into programming language *C* into machine code. In addition to learning about how to code, we will be learning about how write good code. 
Code can be evaluated upon three axes:
* First: *correctness* refers to "does the code run as intended ?"
* Second: *design* refers to "how well is the code designed ?"
* Finally: *style* refers to "how aesthetically pleasing and consistent is the code ?"

## Hello World

```C
#include <stdio.h>

int main(void){
	printf("Hello, world\n");
	return 0;
}
```
⚠️ *The original course use vscode and a specific command make to compile, execute the and create an exec file, I personally use vim to write my code and gcc command to compile them.*

Note that every single character above serves a purpose. If you type incorrectly, the program will not run. `printf` is a function that can output a line of text. Notice the placement of the quotes and the semicolon. Further, notice that the `\n` creates a new line after the words `Hello, world`.

* In this case, I use gcc to compile the program, like this `gcc hello.c`, if executing this commands results in no errors, you can proceed. If not, double check your code to ensure it matches the above. 
* Then we have `a.out` executable file. To execute the program, we just have to typing `./a.out` on the terminal. Your program will execute saying `Hello, world`.
* We can also improve that by this command `gcc hello.c -o hello` this command tell to compile the program on the file hello.c and create executable file `hello` to output the result in.

## Functions

* In Scratch we utilized the `say` block to display any text on the screen. Indeed, in C, we have a function called `printf` that does exactly this.
* Notice our code already invokes this functions:
```C
printf("Hello, world\n");
```
Notice that the printf function is called. The argument passed to prinftf is 'Hello, world\n'. The statement of code is closed with a `;`.
* A common error in C programming is the omision of a semicolon. Modify your code as follows:
```C
#include  <stdio.h>

int main(void){
	printf("Helllo, world\n")
}
```
NOtice the semicolon is now gone.
* In your terminal window, run `gcc hello.c -o hello`. You will now be met with numerous errors:
```
hello.c:4:27: error: expected ';' after expression
        printf("Helllo, world\n")
                                 ^
                                 ;
1 error generated.
```
Placing the semicolon back  in the correct position and running `gcc hello.c -o hello` again, the errors go away.
* Notice also the special symbol `\n` in your code. Try removing those characters and `making` your program again by executing `gcc hello.c -o hello`. Typing `./hello` in the terminal:
```
❯ ./hello 
Helllo, world% 
```
How did your program change ? This `\` character is called *escape sequence/character* that tells the compiler that `\n` is a special instruction.
* Restore your program to the following:

```C
#include  <stdio.h>

int main(void){
	printf("Helllo, world\n");
}
```
Result:
```
❯ ./hello             
Helllo, world

```
* The statement at the start of the code `#include <stdio.h>` is a very special command that tells the compile that you want to use the capabilities of a *library* called `stdio.h`, a *header file*. This allows you, among many other things, to utilize the `printf` function. You can read about all the capabilities of this library one the [Manual Pages](https://manual.cs50.io) (or you can also have information by typing man stdio in our terminal). The manual pages provide a means by which to better understand what various commands do and how they function.
* Libraries are collections of pre-written functions that orders have written in the past that we can utilize in our code.
* It turns out that CS50 has it own library called `cs50.h`. Let's use this library in your program. 

## Variables

* Recall that in Scratch, we had the ability to ask the user "What's your name ?" and say "Hello" with that name appended to it.
* In C, we can do the same. Modify your code as follows:
```C
#include <stdio.h>

int main(void){
	string answer = get_string("What's your name ?");
	printf("Hello, %s\n", answer);
}
```
The `get_string` function is used to get a string from the user. Then, the variable `answer` is passed to the `printf` function, `%s` tells the `printf` function to prepare itself to receive a `string`.
* `answer` is a special holding place we call a *variable*. `answer` is of type `string` and can hold any string within it. There are many *data types* such as `int`, `bool`, `char`, and many others.
* `%s` is a placeholder called a *format code* that tells the `printf` function to prepare to receive a `string`. `answer` is the `string` being passed to `%s`.
* Running `make hello` again in the terminal, notice that numerous errors apear:
```
hello.c:4:2: error: use of undeclared identifier 'string'
        string answer = get_string("What's your name ?");
        ^
hello.c:5:25: error: use of undeclared identifier 'answer'
        printf("Hello,  %s\n", answer);
                               ^
2 errors generated.
```
* Looking at the errors `string` and `get_string` are not recognized by the compiler. We have to teach the compiler these features by adding a library called `cs50.h`:
```C
#include <cs50.h>
#include <stdio.h>

int main(void){
	string answer = get_string("What's your name ?");
	printf("Hello, %s\n", answer);
}
```
Notice that `#include <cs50.h>` has been added to the top of your code.
* Now running `make hello` again in the terminal, you can run your program by typing `./hello`. The program now asks for your name and then says hello with your name attached, as intended.
* `printf` allows for many format codes. Here is a non comprehensive list of ones you may utilize in this course:
```
%c
%f
%i
%li
%s
```
`%s` is used for `string` variables. `%i` is used for `int` or integer variables. You can find out more about this in the [Manual Pages](https://manual.cs50.io/)

## Conditionals

* Another building block you utilized with Scratch was that of *conditionals*. For example, you might want to do one thing if x is greater that y. Further, you might want to do something else if that condition is not met.
* We look at a few example from Scratch.
* In C, you  can assign a value to an `int` or integer as follows:
```C
int counter = 0;
```
Notice how a variable called `counter` of type `int` is assigned the value `0`;
* C can also be programmed to add one to `counter` as follows:
```C
counter = counter + 1;
```
Notice how `1` is added to the value of `counter`.
* This can be represented also as:
```C
counter = counter++;
```
Notice how `1` is added to the value of `counter`. However the `++` is used instead of `counter + 1`.
* You can also substract one from `counter` as follows:
```C
counter = counter--;
* Using this new knowledge about how to assign values to variables, you can program your first conditonnal statement.
* Write the code as follows:
```C 
#include <stdio.h>
#include <cs50.h>

int main(void){
  int x = get_int("What's x? ");
  int y = get_int("What's y? ");

  if(x < y){
    printf("x is less than y\n");
  }
}
```
Notice that we create two variable, an `int` or integer called `x` and another called `y`. The values of these are populated using the `get_int` function.
Result:
```
❯ ./compare
What's x? 8
What's y? 10
x is less than y
```
* *Flow charts* are a way by which you can examine how computer program functions. Such charts can be usde to examine the efficiency of our code.
* Looking at the flow chart above, we can notice numerous shortcomings.
* We can improve your program by coding as follows:
```C 
#include <stdio.h>
#include <cs50.h>

int main(void){
  int x = get_int("What's x? ");
  int y = get_int("What's y? ");

  if(x < y){
    printf("x is less than y\n");
  }else if(x > y){
    printf("y is less than x\n");
  }else{
    printf("y is equal to x\n");
  }
}
```
Notices that all potential that outcomes are now accounted for.
* Considering another data type called `char` we can start a new program we called `agree.c`, where a `string` is a series of `char`:
```C 

#include <stdio.h>
#include <cs50.h>
int main(void){
  //Prompt user to agree
  char c = get_char("Dou you agree ?");

  //Check whether agreed
  if(c == 'Y' || c == 'y'){
    printf("You agreed\n");
  }else if (c == 'N' || c == 'n') {
    printf("You not agreed\n");
  }
  return 0;
}
```
Notice that single quote is used for only one character, further, notice that `==` ensure that something *is equal* to something else, where a single sign have another function in C. Finally, that `||` effectively mean *or*.

## Loops

* We can use loop building block from Scratch in our C programs
* We can look at few examples from Scratch. Consider the following code:
```C 
int counter = 3;
  while(counter > 0){
  printf("Meow\n");
  counter = counter -1;
}
```
Notice that is  oce assigns the value of `3` to the `counter` variable. Then, the `while` loop says `meow` and removes one from the counter for each iteration. Once the counter is not greater than zero, the loop ends.
* In your terminal window, type `code meow.c` and write code as follows:
```C 
#include <stdio.h>

int main(void){
  printf("meow\n");
  printf("meow\n");
  printf("meow\n");
}
```
Notice this does as intended but has an opportunity for better design.
* We can improve our program by modifying your code as follows:
```C 
#include <stdio.h>

int main(void){
  int i = 3;
  while(i > 0){
    printf("meow\n");
    i--;
  }
}
```
Notice that we create an `int` called `i` and assgn it the value `3`. Then, we create a `while` loop that will run as long as `i > 0`. Then, the loop runs, Every time `1` is substracted to `i` using the `i--` statement.
* Similarly, we can implement a count-up of sorts by modifying our code as follows:

```C 
#include <stdio.h>

int main(void){
  int i = 1;
  while(i <= 3){
    printf("meow\n");
    i++;
  }
}
```
Notice how our counter `1` is started at `1`. Each time the loop runs, it will increment the counter by `1`. Once the counter is greater than `3`. it will stop the loop.
* Generally, in computer science we count from zero. Best to revise your code as follows:

```C 
#include <stdio.h>

int main(void){
  int i = 0;
  while(i > 3){
      printf("meow\n");
      i++;
  }
}
```
Notice we now count from zero.
o* Another tool in our toolbox for looping is a `for` loop.
* You can further improve the design of our `meow.c` program using a `for` loop. Modify your code as follows:

```C 
#include <stdio.h>

int main(void){
  for(int i =0; i < 3; i++){
    printf("meow\n");
  }
}
```
Notice that the `for` loop include three arguments. The first argument `int i =0` starts our counter at zero. The second argument `i < 3` is the condition that is being checked. Finally, the argument `i++` tells the loop to increment by one each time the loop runs.
* We can even loop forever using the following code.

```C 
#include <stdio.h>

int main(void){
  while(true){
    printf("meow\n");
  }
}
```
Notice that `ture` will always be the case. Therefore, the code will always run. You will lose control of your terminal by running this code. You can break from an infinite loop by hitting `Ctrl-C` on your keyboard.
* While we will provide much more guidance later, once you can create your own function within C as follows:
```C 
void meow(void){
  printf("meow\n");
}
```
The initial `void` means that the function does not return any values. The `(void)` means that no values are being provided to the function.
* This function can be used in the main function as follows:

```C 
#include <stdio.h>

void meow(void);

int main(void){
  for(int i =0; i < 3; i++){
    meow();
  }
}

void meow(void){
  printf("meow\n");
}
```
Notice how the `meow` function is called with the `meow()` instruction. This is possible because the `meow` function is defined at the bottom of the code and the *prototype* of the function is provided at the top of the code as `void meow(void)` 
* Your `meow` function can be further modified to accept input:

```C 
#include <stdio.h>

void meow(void);

int main(void){
  meow(3);
}
//meow some number of time
void meow(int n){
  for(int i =0; i < n; i++){
    printf("meow\n");
  }
}
```
Notice that the prototype has changed to `void meow(int n)`  to show accepts an `int` as its input

## Operators and Abstraction

* Look the program as follows:
```C 
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for x
    int x = get_int("x: ");

    // Prompt user for y
    int y = get_int("y: ");

    // Perform addition
    printf("%i\n", x + y);
}

```
Notice how `get_int` function is utilized to obtain an integer from the user twice. One integer is stored in the `int` variable called `x` and another integer int the `int` variable called `y`. Then, the function `printf` print the value of `x + y` , deisgnated by the `%i` symbol.
* *Operators* refers to the mathematical operations that are supported by your compiler. In C, these mathematicel operators include:
  * `+` for addition
  * `-` for substraction
  * `/` for division
  * `*` for multiplication
  * `%` for remainder
* *Abstraction* is the art of simplifying our code such that it deal with smaller and smaller problems.
* Expanding on our previously acquired knowledge about functions, we *abstract away* the addition into a function. Modify our code as follows:
```C 
#include <cs50.h>
#include <stdio.h>

int add(int a, int b);

int main(void)
{
    // Prompt user for x
    int x = get_int("x: ");

    // Prompt user for y
    int y = get_int("y: ");

    // Perform addition
    int z = add(x, y);
    printf("%i\n", z);
}

int add(int a, int b)
{
    int c = a + b;
    return c;
}
```
Notices that the `add` function taker two `int` variables as its input. These values are assigned to `a` and `b` and performs a calculations, returning the value of `c`. Further, notice that the *scope* (or context in which variables exist) of `x` is the `main` function. The variable `c` is only within the scope of the `add` function.

* The design of this program can be further improved as follows:
```C 
#include <cs50.h>
#include <stdio.h>

int add(int a, int b);

int main(void)
{
    // Prompt user for x
    int x = get_int("x: ");

    // Prompt user for y
    int y = get_int("y: ");

    // Perform addition
    printf("%i\n", add(x, y));
}

int add(int a, int b)
{
    return a + b;
}
```
Notice that `c` in the `add ` function is removed entirely.
* While very useful to be able to abstract away to an `add` function, you can also perform addition through *truncation* as follows:
```C 
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for x
    long x = get_long("x: ");

    // Prompt user for y
    long y = get_long("y: ");

    // Perform addition
    printf("%li\n", x + y);
}
```
Notice that the addition is performed within the `printf` function.
* Similarly, division can be performed as follows:
```C 
#include <stdio.h>
#include <cs50.h>

int main(void)
{
  //Prompt user for  x
  int x = get_int("x: ");

  //Prompt user for  y
  int y = get_int("y: ");


  // Divide x by y
  printf("%i\n", x / y);

}
```
Notice that division is performed within the `printf` function

## Mario

* Everything we've discussed on this course has focused on various building-blocks of your work as an emerging computer scientist.
* The following will help you orient toward working on a problem set for this class in general: How does one approach a computer science related problem ?
* Imagine we wanted to emulate the visual of the game Super Mario Bros. Considering the four question-blocks pictured, how could we create code that roughly represents these four horizontal blocks ?

![Question blocks](img/question-block.png)

* Write code as follows:
```C 
#include <stdio.h>

int main(void){
  for(int i = 0; i < 4; i++)
  {
    printf("?");
  }
  printf("\n");
  return 0;
}
```
Notice how four question marks are printed here using a loop.
* Similarly, we can apply this same logic to be able to create three vertical blocks.

![vertical Blocks](img/vertical-blocks.png)

* To accomplish this, modify your code as follows:

```C 
#include <stdio.h>

int main(void){
  for(int i = 0; i < 3; i++)
  {
    printf("#\n");
  }
  return 0;
}
```
Notice how three vertical bricks are printed using a loop.

* What if we wanted to combine these idea to create a three-by-three group of blocks ?

![three-by-three](img/three-by-three.png)

* We can follow this logic above, combining the same ideas. Modify your code as follows:
```C 
int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
```
Notice that one loop is inside another. The first loop defines what vertical row is being printed. For each row, three columns are printed. After each row, a new line is printed.
* What if we wanted to ensure that the number of blocks to be *constant*, that is, unchangeable ? Modify your code as follows:
```C 
int main(void)
{
    const int n = 3;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
```
Notice how `n` is now a constant. It can never be changed.
* As illustrated earlier in this lecture,we can make our prompt the user for the size of the grid. Modify your code as follows:
```C 
int main(void)
{
    int n = get_int("Size: ");;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
```
Notice that `get_int` is used to prompt the user/
* A general piece of advice within programming is that you should never fully trust your user. They will likely misbehave, typing incorrect values where they should not. We can protect our program from bad behavior by checking to make sure the user's input satisfies our needs. Modify your code as follows:
```C 
int main(void)
{
  int n;
  do {
    n = get_int("Size: ");
  }while(n < 1);

  for (int i = 0; i < n; i++)
  {
      for (int j = 0; j < n; j++)
      {
          printf("#");
      }
      printf("\n");
  }
}
```

Notice how the user is continuously prompted for the size until the user's input is 1 or greater.

## Types

* Once of C's shortcommings is the ease by which it managing memory. While C provides you immense control over how memory is utilized, programmgers have to be very aware of potential pitfalls of memory management
* Types refer to the possible data that can be stored within a variable. For example, a `char` is designed to accommodate a single character like `a` or `2`.
* Types are very important because each type has specific limits. For example, because of the limits in memory, the highest value of an `int` can be `4294967295` if you attempts to count an `int` higher, *integer overflow* will result where an incorrect value will be stored in this variable.
* The number of bits limits how high and low we can count.
* Types with which you might interact during this course include:
 * `bool`, a Boolean expression of either true or false
 * `char`, a single character like `a` or `2`
 * `double`, a floating-point value with more digits than a float
 * `float`, a floating-point value, or real number with a decimal value
 * `int`, integers up to a certain size, or number of bits
 * `long`, integers with more bits, so they can count higher than an int
 * `string`, a string of characters
* As you are coding, pay special attention to the types of variables you are using to avoid problems within your code.
* We examined some examples of disasters that can occur through memory-related errors.

## Summing Up  

In this lesson, you learned how to apply the building blocks you learned in Scratch to the C programming language. You learned…

  * How to create your first program in C.
  * Predefined functions that come natively with C and how to implement your own functions.
  * How to use variables, conditionals, and loops.
  * How to approach abstraction to simplify and improve your code.
  * How to approach problem-solving for a computer science problem.
  * How to use the Linux command line.
  * How to integrate comments into your code.
  * How to utilize types and operators.


[Source : Week 1](https://cs50.harvard.edu/x/2024/notes/1/)  
