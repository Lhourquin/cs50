#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_number_of_words(string text);
int count_number_of_letters(string text);
int count_number_of_sentences(string text);
float get_average(float number, int number_of_words);

int main(void)
{
  string text = get_string("Text: ");

  int number_of_words = count_number_of_words(text);
  float number_of_letters = count_number_of_letters(text);
  float number_of_sentences = count_number_of_sentences(text);

  float average_nb_of_letters = get_average(number_of_letters, number_of_words);
  float average_nb_of_sentences = get_average(number_of_sentences, number_of_words);

  int index = round(0.0588 * average_nb_of_letters - 0.296 * average_nb_of_sentences - 15.8);

  if(index < 1){
    printf("Before Grade 1\n"); 
  }else if(index >= 1 && index < 16){
    printf("Grade %d\n", index);
  }else {
    printf("Grade 16+\n");

  }
  return 0;
}

int count_number_of_words(string text){ 
  int number_of_words = 0;
  for (int i = 0; text[i] != '\0'; i++) {
    if(text[i] == 32){
      number_of_words++; 
    }
  }
  number_of_words +=1;
  return number_of_words;
}

int count_number_of_letters(string text){ 
  int number_of_letters = 0;
  for (int i =0; text[i] != '\0'; i++) {
    if(text[i] > 64 && text[i] < 91 || text[i] > 96 && text[i] < 123){
      number_of_letters++; 
    }
  }
  return number_of_letters;
}


int count_number_of_sentences(string text){
  int number_of_sentences = 0;
  for (int i =0;text[i] != '\0'; i++) {
    if(text[i] == 33 || text[i] == 46 || text[i] == 63){
      number_of_sentences++;
    }
  } 
  return number_of_sentences;

}

float get_average(float number, int number_of_words){
  float average = number / number_of_words;
  return average * 100;
}

