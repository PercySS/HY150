#include "std_lib_facilities.h"

string getinput();
void string_check(vector<char> a, vector<int> b, string c);

int main() {
    
    string str = getinput();
    cout << endl;

    //Making a vector for checking perantheses
    vector<char> parenth;
    //Making vector for getting positions
    vector<int> pos;
    

    string_check(parenth, pos, str);


    keep_window_open();
    return 0;
}

string getinput() {
    cout << "Type a string!" << endl;
    cout << "=>" ;
    string str;
    //Input string
    getline(cin, str);
    return str;
}

void string_check(vector<char> parenth, vector<int> pos, string str) {
    int i{0}; 
    while (i < str.size()) {
        //Pushing back left parenthesis in the vector
        if (str.at(i) == '(') {
            parenth.push_back(str.at(i));
            pos.push_back(i);
        //If I find a right parenthesis I check vector   
        } else if (str.at(i) == ')') {
            //If previous parenthesis is left I pop it back and count it as a closed one
            if ( parenth.size() != 0 && parenth.back() ==  '(') {
                parenth.pop_back();
                pos.pop_back();
            //If there isnt a left parenthesis theres output for wrong parenthesis 
            } else {
                cout << "Wrong at position " << i << '.' << endl;
                break;
            }
        }
        i++;    
    }

    //Checking vector so there isnt any parentheses left inside
    //That means the string is correct
    if (0 == parenth.size()) {
        cout << "Correct." << endl; 
    //If theres a parenthesis left in the vector I get his position from the vector pos that is changing simultaneously with 
    //vector parenth    
    } else {
        cout << "Wrong at position " << pos.back() << '.' << endl;
    }
}
