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
