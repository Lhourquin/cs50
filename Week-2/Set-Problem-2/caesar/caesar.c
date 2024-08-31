#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

string encrypt_plaintext(string plaintext, int key);

int main(int argc, char *argv[])
{
  //get argument of the command line to get the key to encrypt
  //check if the user as been enter a key (number back-to-back and no other)
  //if is it good input, ask for the plaintext to encrypt 
  //encrypt the plaintexxt and output the ciphertext

  //check for good argument
  if (argc != 2) {
    printf("Usage: %s key\n", argv[0]);
    return 1;
  }else {
    int key = atoi(argv[1]);
    if(key <= 0){
      printf("Usage: %s key\n", argv[0]);
      return 1;
    }else {
      //array of ascii decimal value
      //make operation with modulo to get cipher char
      printf("key: %d\n", key );
      string plaintext = get_string("plaintext: ");
      string ciphertext = encrypt_plaintext(plaintext, key);
      printf("ciphertext: %s\n", ciphertext);
    }
  } 

  return 0;
}

string encrypt_plaintext(string plaintext, int key){
  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//should be replaced by ascii
  int lowercase_alphabet[26] = {
    65,
    66,
    67,
    68,
    69,
    70,
    71,
    72,
    73,
    74,
    75,
    76,
    77,
    78,
    79,
    80,
    81,
    82,
    83,
    84,
    85,
    86,
    87,
    88,
    89,
    90
  };
    int uppercase_alphabet[26] = {
    97,
    98,
    99,
    100,
    101,
    102,
    103,
    104,
    105,
    106,
    107,
    108,
    109,
    110,
    111,
    112,
    113,
    114,
    115,
    116,
    117,
    118,
    119,
    120,
    121,
    122,
  };
  int length = strlen(alphabet);

  string ciphertext = plaintext;

  int i = 0;
  while (ciphertext[i] != '\0') {
    if(ciphertext[i] >= 65 && ciphertext[i] <= 90){
      for (int j = 0; j < length;j++) {
        if(ciphertext[i] == lowercase_alphabet[j]){
          int cipher_char_idx = (j + key) % 26;
          ciphertext[i] = lowercase_alphabet[cipher_char_idx];
          break;
        }
      }
    }else if (ciphertext[i] >= 97 && ciphertext[i] <= 122) {
      for (int j = 0; j < length;j++) {
        if(ciphertext[i] == uppercase_alphabet[j]){
          int cipher_char_idx = (j + key) % 26;
          ciphertext[i] = uppercase_alphabet[cipher_char_idx];
          break;
        }
      }
    }
    i++;
  }
  return ciphertext;
}
