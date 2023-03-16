#ifndef WORD_H
#define WORD_H

// cpp libraries

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

#include <cstdlib>
using std::srand;
using std::rand;

#include <ctime>
using std::time;

std::string generateRandomWord()
{

  // open the words txt file
  ifstream file("../../txt/words_skimmed.txt");

  // create empty vector to store the words
  vector<std::string> words;

  // read in words, add to file
  std::string word;
  while (file >> word)
    {
      words.push_back(word);
    }

  // seed the number generator based on current time
  srand(time(NULL));

  // generate a random # based on the size of words.txt
  int index = rand() % words.size();

  // get the #th word in the words array
  std::string randomWord = words[index];

  return randomWord;
}

#endif
  
