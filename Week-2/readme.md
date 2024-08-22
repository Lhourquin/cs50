# Arrays 

## Welcome!

* In our previous session, we learned about C, a text based programming language.
* This week, we are going to take a deeper look at additional building-blocks that will support our goals of learning more about programming from the bottom-up.
* Fundamentally, in addition to the essentials of programming, this course is about problem solving. Accordingly, we will also focus further on how to approach computer science problems.

### Compiling 

* ***Encryption*** is the act of hiding plain text from prying eyes. ***decrypting***, then, is the act of taking an encrypted piece of text and returning to a human-readable form.
* An encrypted piece of text may look like the following:

![encrypted-piece](img/encrypted-piece.png)
* Recall that last week you learned about a ***compiler***, a specialized computer program that converts ***source code*** into ***machine code*** that can be understand by a computer.
* For example, you might have a computer program that looks like this:
```C  
#include <stdio.h> 

int main(void)
{
  printf("hello, world\n");
}
```
* A compiler will take the above code and turn it into following machine code:

![machine-code](img/machine-code.png)
* ***VS Code***, the programming environment utilizes a compiler called `clang` or `c language`
* If you were to type `make hello`, it runs a command that executes clang to create an output file that you can run as a user.
* VS Code has been pre-programmed such that `make` will run numerous command line arguments along with clang for you convenience as a user.
* Consider the following code:
```C 
#include <stdio.h>
#include <cs50.h>

int main(void){
  string name = get_string("What's your name ?");
  printf("hello, %s\n", name);
}
```
* You can attempt to enter into the terminal window: `clang -o hello hello.c`. You will be met by an error that indicates that clang does not know where to find the `cs50.h` library.
* Attempting again to compile this code, run the following command in the terminal: `clang -o hello hello.c -lcs50`. This will enable the compiler to access the `cs50.h` library.
* Running in the terminal window `./hello`, your program will run as intended.
* While the above is offered as an illustration, such that you can understand more deeply the process and concept of compiling code, using `make` in CS50 perfectly fine and the expectation!
* Compiling involves major steps, including the following:
  * First, ***preprocessing*** is where the header files in your code, designated by a `#`(such as `#include <cs50.h>`) are effectively copied and pasted into your file. During this step, the code from `cs50.h` is copied into your program. Similarly, just as your code contains `#include <stdio.h>`, code contained within `stdio.h` somewhere on your computer is copied to your program. This step can be visualized as follows:
  ```C 
  string get_string(string prompt);
  int printf(string format, ...);

  int main(void)
  {
    string name = get_stirng("What's your name ? ");
    printf("hello, %s\n", name);
  }
  ```
  * Second, ***compiling*** is where your program is converted into assembly code. This step can be visualized as follows:

  ![assembly-code](img/assembly-code.png)
  * Third, ***assembling*** involves the compiler converting your assembly code into machine code. This step can be visualized as follows:

  ![binary-code](img/binary-code.png)
  * Finally, during the ***linking*** step, code from your included libraries are converted also into machine code and combined with your code. The final executable file is then outputted.

  ![linking-step](img/linking-step.png)

## Debugging 

* Everyone will make mistakes while coding.
* Consider the following image from last week:

![mario](img/mario.png)

* Further, consider the following code that has a bug purposely inserted within it:
```C 
#include <stdio.h>

int main(void)
{
  for(int i = 0; i <= 3; i++)
  {
    printf("#\n");
  }
}
```
* Running this code, four bricks appear instead of the intended three.
* `printf` is a very useful way of debugging your code. You could modify your code as follows:
```C 
#include <stdio.h>

int main(void){
  for(int i = 0; i <= 3; i++)
  {
    printf("i is %d\n", i);
    printf("#\n");
  }
}
```
* Running this code, you will see numerous statements, including `i is 0`, `i is 2`, and `i is 3`. Seeing this, you might realize that Further code needs to be corrected as follows:
```C 
#include <stdio.h>

int main(void){
  for(int i = 0; i < 3; i++)
  {
    printf("#\n");
  }
}
```
Notice the `<=` has been replaced with `<`.
* This code can be further improved as follows:

```C 
#include <stdio.h>
#include <cs50.h>
void print_column(int height);

int main(void)
{
  int h = get_int("Height: ");
  print_column(h);

}

void print_column(int height){
  for (int i = 0; i <= height; i++) {
    printf("#\n");
  }
}

```
Notice that compiling and running this code still results in a bug.
* To address this bug, we will use a new tool at our disposal.
* A second tool in debugging is called a ***debugger***, a software tool created by programmers to help track down bugs in code.
* In VS Code, a preconfigured debugger has been provided to you.
* To utilize this debugger, first set a ***breakpoint*** by clicking to the left of a line of your code, just to the left of the line number. When you click here, you will see a red dot appearing. Imagine this as a stop sign, asking the compiler to pause such that you can consider what's happening in this part of your code.

![debugging](img/debugging.png)

* Second, run `debug50 ./buggy0`. You will notice that after the debugger comes to life that a line of code will illuminate in a gold-like color. Quite literally, the code has ***paused*** at this line of code. Notice in the top of your window, you can click the `step over` button and it will keep moving through your code. Notice how the value of `h` increases.
* While this tool will not show you where your bug is, it will help you slow down and see how your code is running step by step. You can use `step into` as a way to look further into the details of your buggy code.
* A final form of debugging is called ***rubber duck debugging***. When you are having challenges with your code, consider how speaking out loud to, quite literally, a rubber duck about the code problem. If you'd rather not talk to a small plastic duck, you are welcome to speak to a human near you! They need not understand how to program: Speaking with them is an opportunity for you to speak about your code.
