#ifndef HANGMAN_H
#define HANGMAN_H

#include <iostream>
#include <string>

using namespace std;

void print_hangman(int tries_left) {
    string noose = " O\n/|\\\n/ \\\n";
    string head = " O\n";
    string body = "|";
    string arm1 = "/";
    string arm2 = "\\";
    string leg1 = "/";
    string leg2 = "\\";

    string limbs = "";
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
        cout << noose << endl;
    } else {
        cout << noose << limbs << endl;
    }
}

#endif
