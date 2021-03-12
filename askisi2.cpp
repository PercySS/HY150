#include "std_lib_facilities.h"


string getinput();
string combination(string a, string b);

int main() {
    //Input of strings
    string first = getinput(), second = getinput();
    cout << endl;
    
    //cout << first.length();
    //cout << second.length();
    
    //Output combined string
    cout << combination(first, second) << endl;

    keep_window_open();
    return 0;
}

string getinput() {
    string str;
    cout << "Type a string!" << endl;
    getline(cin, str);
    return str;
} 


string combination(string first, string second) {
    int j{0}, k{0};
    string third;
    //Accessing the vector with 3 counters 
    //So I get a letter from the first string if the repetiton is even
    //Or if the repetition is odd I get a letter from the second string
    //And if I have no letters left in a string I take all the remaining letters from the other
    //i-> combined string
    //j->first string 
    //k->second string
    // 
    for (int i = 0; i < first.length() + second.length(); i++) {
        if (j < first.length() && (i % 2 == 0 || k == second.length())) {
            third += first.at(j);
            j++;
            //cout << j;
        } else {
            third += second.at(k);
            k++;
            //cout << k;
        }
    }
    return third;
}