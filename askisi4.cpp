#include "std_lib_facilities.h"

string get_input();
int string_check(string);

int main() {    
    string str = get_input();
    cout << endl;

    int res = string_check(str);

    if (res == -1) {
      cout << "Correct." << endl; 
    } else {
      cout << "Wrong at position " << res << '.' << endl;
    }

    keep_window_open();
    return 0;
}

string get_input() {
    cout << "Type a string!" << endl;
    cout << "=> ";
    string str;
    // Input string
    getline(cin, str);
    return str;
}

// Return the position of the wrong parenthesis
// or -1 in case the input is correct
int string_check(string str) {
    int i{0};

    // Making a vector for checking perantheses
    vector<char> parenth;
    // Making vector for getting positions
    vector<int> pos;

    while (i < str.size()) {
        // Push back left parenthesis in the vector
        if (str.at(i) == '(') {
            parenth.push_back(str.at(i));
            pos.push_back(i);
        // If I find a "right" parenthesis,
        // I check vector for matching "left" parenthesis  
        } else if (str.at(i) == ')') {
            // If previous parenthesis is "left" I pop it back and count it as a closed one
            if ( parenth.size() > 0 && parenth.back() ==  '(') {
                parenth.pop_back();
                pos.pop_back();
            // If there isn't a left parenthesis output the position of the wrong parenthesis 
            } else {
                return i;
            }
        }
        i++;    
    }

    // Checking vector so there isn't any "open" parentheses left
    if (parenth.size() > 0) {
        // If there's a parenthesis left in the vector,
        // I get it's position from vector "pos",
        // that is changing along with vector "parenth"
        return pos.back();
    }

    // No errors found
    return -1;
}
