#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int check_score(string response);

int main(void)
{
  string player_1 = get_string("Player 1: ");
  string player_2 = get_string("Player 2: ");


  int score_player_1 = 0;
  int score_player_2 = 0;

  score_player_1 = check_score(player_1);
  score_player_2 = check_score(player_2);

  if (score_player_1 > score_player_2) {
    printf("%d\n", score_player_1);
    printf("%d\n", score_player_2);
    printf("Player 1 wins!\n");
  }else if (score_player_2 > score_player_1) {
    printf("%d\n", score_player_1);
    printf("%d\n", score_player_2);
    printf("Player 2 wins!\n");
  } else {
    printf("Tie!\n");
  } 

  return 0;
}

int check_score(string response)
{
  string alphabet = "ABCDEFGHIJKLMNOPQRSTUV";

  int points[22];
  points[0] = 1;
  points[1] = 3;
  points[2] = 3;
  points[3] = 2;
  points[4] = 1;
  points[5] = 4;
  points[6] = 2;
  points[7] = 4;
  points[8] = 1;
  points[9] = 8;
  points[10] = 5;
  points[11] = 1;
  points[12] = 3;
  points[13] = 1;
  points[14] = 1;
  points[15] = 3;
  points[16] = 10;
  points[17] = 1;
  points[18] = 1;
  points[19] = 1;
  points[20] = 1;
  points[21] = 4;

  int score = 0;

  int i = 0;
  while (response[i] != '\0') {
    for (int j = 0; j < strlen(alphabet); j++) {
      if(toupper(response[i]) == alphabet[j]){
        score += points[j];
        printf("%c: %d -> ",alphabet[j], points[j]);
      }
    }
    i++;
  }

  printf("score: %d\n", score);
  return score;
}
