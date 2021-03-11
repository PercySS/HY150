#include "std_lib_facilities.h"

int main() {
    string first, second, third;
    //Input of strings
    cout << "Type a string!" << endl;
    getline(cin, first);
    cout << "Type another string!" << endl;
    getline(cin, second);


    
    
    //cout << first.length();
    //cout << second.length();

    
    int j{0}, k{0};
    for (int i = 0; i < first.length() + second.length(); i++) {
        //Accessing the vector with 3 counters 
        //So I get a letter from the first string if the repetiton is even
        //Or if the repetition is odd I get a letter from the second string
        //And if I have no letters left in a string I take all the remaining letters from the other
        //i-> combined string
        //j->first string 
        //k->second string
        // 
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

    cout << endl;
    //Output combined string
    cout << third << endl;

    keep_window_open();
    return 0;
}