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
