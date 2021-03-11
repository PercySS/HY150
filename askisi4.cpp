#include "std_lib_facilities.h"

int main() {
    cout << "Type a string!" << endl;
    cout << "=>" ;
    string str;
    getline(cin, str);
    cout << endl;
    vector<char> parenth;
    vector<int> pos;
    int i{0}; 

    while (i < str.size()) {
        if (str.at(i) == '(') {
            parenth.push_back(str.at(i));
            pos.push_back(i);
           
        } else if (str.at(i) == ')') {
            if ( parenth.size() != 0 && parenth.back() ==  '(') {
                parenth.pop_back();
                pos.pop_back();
             
            } else {
                cout << "Wrong at position " << i << '.' << endl;
                // keep_window_open();
                return 0;
            }
        }
        i++;    
    }

    if (0 == parenth.size()) {
        cout << "Correct." << endl; 
    } else {
        cout << "Wrong at position " << pos.back() << '.' << endl;
    }

    // keep_window_open();
    return 0;
}


