#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

void draw(int n);

int main(int argc, char *argv[]){
  if(argc != 2){
    printf("Usage: ./recursion n\n");
    return 1;
  }
  draw(atoi(argv[1]));
  return 0;
}

void draw(int n){
  //If nothing to draw
  if(n <= 0){
    return;
  }
  //Draw pyramid of height n - 1
  draw(n - 1);

  //Draw ine more row of width n
  for (int i = 0; i < n; i++) {
    printf("#");
  }
  printf("\n");
}
