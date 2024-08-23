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

## Arrays 

* In Week 0, we talked about ***data types*** such as `bool`, `int`.`char`, `sting`, etc.
* Each data type requires a certain amount of system ressources:
  * `bool` 1 byte
  * `int` 4 bytes
  * `long` 8 bytes
  * `float` 4 bytes
  * `double` 8 bytes
  * `char` 1 byte
  * `string` ? bytes
* Inside of your computer, you have a finite amount of memory available.

![ram-barret](img/barret-ram.png)

* Physically, on the memory of your computer, you can imagine how specific types of data are stored on your computer. You might imagine that a `char`, which only requires 1 byte of memory, may look as follows:

![1 bytes of memeory in ram barret](img/barret-ram2.png)

* Similarly, an `int` which requires 4 bytes might look as follows:

![4 bytes of memeory in ram barret](img/barret-ram3.png)

* We can create aprogram that explore these concepts. Inside your terminal, type `code scores.c` and write code as follows:
```C 
#include <stdio.h>

int main(void)
{
  //scrores
  int score1 = 72;
  int score2 = 73;
  int socre3 = 33;
  
  //printf average
  printf("Average: %f\n", (score1 + score2 + score3) / 3.0);
  
}
```
Notice that the number on the right is a floating point value of `3.0` such that the calculation as a floating point value in the end.

* Running `make scores`, the program runs.
* You can imagine how these variables are stored in memory:

![variable stored in memory](img/variables-in-memory.png)

* ***Arrays*** are a way of storing data back-to-back in memory such that this data is easily accesible.
* `int scores[3]`  is a way of telling the compiler to provide you three back-to-back places in memory of size `int` to store three `scores`. Considering our program, you can revise your code as follows:
```C 
#include <stdio.h>
#include <cs50.h>

int main(void){
  //get scores
  int scores[3];
  scores[0] = get_int("Score: ");
  scores[1] = get_int("Score: ");
  scores[2] = get_int("Score: ");

  //print average 
  printf("Average: %f\n: ",(scores[0] + scores[1] + scores[2]) / 3.0 );
}
```
Notice that `scores[0]` examines the value at this location of memory by `indexing into` the arrays called `scores` at location `0` to see what value is stored there.
* You can see how while the above code works, there is still an opportunity for improving our code. Revise your code as follows:
```C 
#include <stdio.h>
#include <cs50.h>

int main(void)
{
  //Get scores
  int scores[3];
  for(int i = 0; i < 3; i++)
  {
    scores[i] = get_int("Score: ");
  }

  //print average
  printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}
```
Notice how we index into `scores` by using `scores[i]` where `i` is supplied by the `for` loop.
* We can simplify of `abstract away` the calculation of the average. Modify your code as follows:
```C  
#include <stdio.h>
#include <cs50.h>

//Constant
const int N = 3;

//Prototype
float get_average(int length, int array[]);

int main(void)
{
  int scores[N];
  for (int i = 0; i < N; i++) {
    scores[i] = get_int("Score: ");
  }
  float average = get_average(N, scores);
  printf("Average: %f\n", average);
  
}

float get_average(int length, int array[]){
  //Calculate the average
  int sum = 0;
  for(int i = 0; i < length; i++)
  {
    sum += array[i];
  }

  return sum / length;
}
```
Notice that a new function called `get_average` is declared,. Further, notice that a `const` or constant value of `N` is declared. Most importantly, notice how the `get_average` function takes `int array[]`, which means that the compiler passes an array to this function.
* Not only can arrays be containers: They can be passed between functions.
