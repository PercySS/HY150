#include "std_lib_facilities.h"

int main(){
    //Giving g constant its actual value finding it from searching the web
    const float g = 9.80665;
    cout << "Parakalo eisagete thn arxiki taxythta se metra ana deyterolepto! ";
    float arxtax;
    cout << "=> ";
    cin >> arxtax;
    //Exception for initial velocity *arxiki taxitita*
    if (!cin) {
      throw runtime_error("Wrong input!");
    }
    cout << endl;
    /* if (!cin) {
      error(u8"Δεν έδωσες αριθμό!");
    } else if (arxtax < 0) {
      error(u8"Έδωσες αρνητική ταχύτητα!");
    } */

    
    cout << "Parakalo eisagete to ypsos toy gkremoy se km!";
    float height;
    cout << "=> ";
    cin >> height;
    // Exception for height 
    if (!cin) {
      throw runtime_error("Wrong input!");
    }


    /* if (!cin) {
      error(u8"Δεν έδωσες αριθμό!");
    } else if (height < 0) {
      error(u8"Έδωσες αρνητικό ύψος!");
    } */
    
    cout <<  endl;

    
    //Conversion km to m
    height *= 1000;

    //Arithmetic operations for finding the total time
    float t_ol;
    t_ol = sqrt( (2 * height) / g );

    //Arithmetic operations for finding total range
    float belin;
    belin = arxtax * t_ol;

    cout << "The total range that the object will go through is: " << belin/1000 << "km" << endl;
    cout << "The total time that the object will be in the air is: " << t_ol << "sec" << endl;

    keep_window_open();

    return 0;
}