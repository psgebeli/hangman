// test of random word generation

#include <iostream>
using std::cout;
using std::endl;

#include "../include/word.h"

int main()
{
  std::string randomWord = generateRandomWord();
  cout << "word is: " << randomWord << endl;
  return 0;
}
