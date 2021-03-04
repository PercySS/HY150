#include "std_lib_facilities.h"

int main(){
    const float g = 9.80665;
    cout << "Parakalo eisagete thn arxiki taxythta se metra ana deyterolepto! ";
    float arxtax;
    cout << "=> ";
    cin >> arxtax;

    if (!cin) {
      error(u8"Δεν έδωσες αριθμό!");
    } else if (arxtax < 0) {
      error(u8"Έδωσες αρνητική ταχύτητα!");
    }

    cout << endl;
    cout << "Parakalo eisagete to ypsos toy gkremoy se km!";
    float height;
    cout << "=> ";
    cin >> height;

    if (!cin) {
      error(u8"Δεν έδωσες αριθμό!");
    } else if (height < 0) {
      error(u8"Έδωσες αρνητικό ύψος!");
    }
    
    cout <<  endl;

    
    
    height *= 1000;
    float t_ol;
    t_ol = sqrt( (2 * height) / g );
    float belin;
    belin = arxtax * t_ol;

    cout << "H apostasi poy tha dianysei to swma einai : " << belin/1000 << "km" << endl;
    cout << "O xronos poy to swma tha brisketai ston aera einai : " << t_ol << "sec" << endl;

    keep_window_open();

    return 0;
}