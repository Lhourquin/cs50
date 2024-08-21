#include <stdio.h>
#include <cs50.h>

long sum_of_split_tens(long number, int length);

long get_two_first_number(long number, int length);

long sum_of_products(long number, int length);

int get_length(long number);

int main(void)
{
  long card_number = 0;

  do {
    card_number = get_long("Number: ");
  } while (card_number == 0);

  int length = get_length(card_number);
  printf("card_number: %ld\n", card_number);
  long two_first_number = get_two_first_number(card_number, length);
  printf("two_first_number: %ld\n", two_first_number);
  long result = sum_of_products(card_number, length);
  printf("result: %ld\n", result);
  return 0;
}


int get_length(long number){

  int length = 0;

  while (number != 0 ) {
    number = number / 10; 
    length++;
  } 
  return length;
}

long get_two_first_number(long number, int length){
  long dividor = 1;
  for (int i = 2; i < length; i++) {
    dividor = dividor * 10;
  }
  long two_first_nb = number / dividor; 
  return two_first_nb;
}

long sum_of_products(long number, int length){//use them for multiplication?

  long mod = 0;
  long tmp_number = number;
  long sum = 0;
  for (int i = 0; i < length; i++) {
    if ((i % 2) == 1) {
      mod = tmp_number % 10;
      //mutliply by 2 the number in this condition and store the result
      long result_of_multiplication = mod * 2;
      int length_of_result_of_multiplication = get_length(result_of_multiplication);
      if(length_of_result_of_multiplication > 1){
        sum += sum_of_split_tens(result_of_multiplication, length);
      }else{
        sum += result_of_multiplication;
      }
    } 
    tmp_number = tmp_number / 10;
  }

  return sum;
}

//function to split a tens number and make addition with the number, example: input: 12, instruction -> 1 + 2, output: 3.
long sum_of_split_tens(long number, int length){
  long mod = 0;
  long tmp_number = number;
  long sum = 0;
  for (int i = 0; i < length; i++) {
    mod = tmp_number % 10;
    sum+= mod;
    tmp_number = tmp_number / 10;
  }
  return sum;
}
