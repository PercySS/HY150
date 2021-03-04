#include "std_lib_facilities.h"

int main() {
    string first, second, third;
    cout << "Type a string!" << endl;
    getline(cin, first);
    cout << "Type another string!" << endl;
    getline(cin, second);

    int j{0}, k{0};
    
    //cout << first.length();
    //cout << second.length();

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

    cout << endl;
    cout << third << endl;

    keep_window_open();
    return 0;
}