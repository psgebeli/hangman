// this header handles printing of the hang-man
// based on the number of incorrect guesses

#ifndef HANGMAN_H
#define HANGMAN_H

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

void print_hangman(int tries_left) {

  // draw body parts via strings
  
  string head = " O\n";
  string body = "|";
  string arm1 = "/";
  string arm2 = "\\";
  string leg1 = "\n/";
  string leg2 = " \\";

  string limbs = ""; // store the current limbs being hung
  if (tries_left < 6) {
    limbs += head;
  }
  if (tries_left < 5) {
    limbs += arm1;
  }
  if (tries_left < 4) {
    limbs += body;
  }
  if (tries_left < 3) {
    limbs += arm2;
  }
  if (tries_left < 2) {
    limbs += leg1;
  }
  if (tries_left < 1) {
    limbs += leg2;
  }
  
  if (limbs == "") {
    cout  << endl;
  } else {
    cout << limbs << endl;
  }
}

#endif
