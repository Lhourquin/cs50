# Week 1 - C

Machine only understand binary, where humans write *source code*, a list of instructions for the computer that is human readable, machine only understand what we can now call *machine code*. This machine code is pattern of ones and zeros that produces a desired effect. It turns out that we can convert *source code* into `machine code` using a very special piece of software called a *compiler*. We will be introducing you to a compiler that will allow you to convert source code into programming language *C* into machine code. In addtition to learining about how to code, we will be learning about how write good code. 
Code can be evaluated upon three axes:
* First: *correctness* refers to "does the code run as intended ?"
* Second: *design* refers to "how well is the code designed ?"
* Finally: *style* refers to "how aesthetically pleasing and consisten is the code ?"

⚠️ *The original course use vscode and a specific command make to compile, execute the and create an exec file, I personally use vim to write my code and gcc command to compile them.*

## Hello Wolrd

```C
#include <stdio.h>

int main(void){
	printf("Hello, world\n");
	return 0;
}
```

Note that every single character above serves a purpose. If you type incorretclty, the program will not run. `printf` is a function that can output a line of text. Notice the placement of the quotes and the semicolon. Further, notice that the `\n` creates a new line after the words `Hello, world`.

* In this case, I use gcc to compile the program, like this `gcc hello.c`, if executing this commands results in no errors, you can proceed. If not, double check your code to ensure it matches the above. 
* Then we have `a.out` executable file. To execute the program, we just have to typing `./a.out` on the terminal. Your program will execute saying `Hello, world`.
* We can also improve that by this command `gcc hello.c -o hello` this command tell to compile the program on the file hello.c and create executable file `hello` to output the result in.
