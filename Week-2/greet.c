#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
  if(argc == 2){
    //printf("%s\n", argv[0]);Output: ./greet
    printf("Hello %s\n", argv[1]);
  }else {
    printf("Hello, world\n");
  }
}

