
#include <stdio.h>
#include <cs50.h>
int main(void)
{
  char c1 = 'H';
  char c2 = 'I';
  char c3 = '!';
  
  printf("%i %i %i\n", c1, c2, c3);

  string s = "HI!";
  printf("%c%c%c\n", s[0], s[1], s[2]);
  printf("%i %i %i\n", s[0], s[1], s[2]);
  string t = "BYE!";
  printf("%s\n", s);
  printf("%s\n", t);

  string words[2];

  words[0] = "HI!";
  words[1] = "BYE!";

  printf("%s\n", words[0]);
  printf("%s\n", words[1]);
}
