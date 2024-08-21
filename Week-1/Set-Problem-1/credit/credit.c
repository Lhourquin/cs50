#include <stdio.h>
#include <cs50.h>

long get_number_from_begin(long number, int length, int number_of_numbers);

long sum_of_split_tens(long number, int length);

long get_two_first_number(long number, int length);

long check_sum(long number, int length);

int get_length(long number);

int main(void)
{
  long card_number = 0;

  do {
    card_number = get_long("Number: ");
  } while (card_number == 0);

  int length = get_length(card_number);

  long two_first_number = get_two_first_number(card_number, length);
  long first_number = get_number_from_begin(two_first_number, get_length(two_first_number), 1);
  long result = check_sum(card_number, length);

  if(result != 0){
    printf("INVALID\n");
  }else {
    if (two_first_number == 34 || two_first_number == 37) {
      if(length != 15){
        printf("INVALID\n");
      }else{
        printf("AMEX\n") ;
      }
    } else if (two_first_number == 51 || two_first_number == 52||two_first_number == 53 || two_first_number == 54 ||two_first_number == 55) {
      if(length != 16){
        printf("INVALID\n");
      }else{
        printf("MASTERCARD\n");
      }
    } else if(first_number == 4){
      if(length == 13 || length == 16){
        printf("VISA\n");
      }else{
        printf("INVALID\n");
      }
    } else{
      printf("INVALID\n");
    }
  }
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

long check_sum(long number, int length){//use them for multiplication?

  long mod = 0;
  long tmp_number = number;
  long sum_of_products = 0;
  long sum_of_not_multiply = 0;
  long result = 0;

  for (int i = 0; i < length; i++) {
    mod = tmp_number % 10;
    if ((i % 2) == 1) {
      long result_of_multiplication = mod * 2;
      int length_of_result_of_multiplication = get_length(result_of_multiplication);
      if(length_of_result_of_multiplication > 1){
        sum_of_products += sum_of_split_tens(result_of_multiplication, length);
      }else{
        sum_of_products += result_of_multiplication;
      }
    }else {
      sum_of_not_multiply += mod;
    } 
    tmp_number = tmp_number / 10;
  }
  result = sum_of_products + sum_of_not_multiply; 
  return result % 10;
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

long get_number_from_begin(long number, int length, int number_of_numbers){
  long dividor = 1;
  for (int i = number_of_numbers; i < length; i++) {
    dividor = dividor * 10;
  }
  long two_first_nb = number / dividor; 
  return two_first_nb;
}
