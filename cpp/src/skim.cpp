// I downloaded a words.txt file from a git repository, credit to
// Xethron at https://github.com/Xethron/Hangman
// however, I find 2 letter/3 word letters unsatisfying in a game of hangman.
// so this script will cut out all words that dont have atleast 4 letters,
// and write a new .txt that contains words which passed my criteria.



#include <iostream>
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::string;
using std::getline;


int main() {
    string input_filename = "../../txt/words.txt";
    string output_filename = "../../txt/words_skimmed.txt";
    ifstream input_file(input_filename); // set up reading from input file
    ofstream output_file(output_filename); // set up writing to output file
    string line;
    while (getline(input_file, line)) { // check size of each line
        if (line.size() >= 4) {
	  output_file << line << endl; // append word to out file if big enough
        }
    }
    input_file.close();
    output_file.close();
    return 0;
}
