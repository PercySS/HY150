#include "std_lib_facilities.h"



double vector_magnitude(double a, double b);
double vector_magnitude(double a, double b, double c);


int main(){
    // dilono kai zitao apo to xristi na m dosei diastaseis kai to plithos ton diastaseon
    int pldiast;
    double diast1, diast2, diast3;
    cout << "Type the dimensions and the components of the vector.\n" << endl;
    
    // Input dimensions
    cin >> pldiast;
    // Exception
    if (!cin) {
      throw runtime_error("Wrong input!");
    }
    cout << endl;
   
   
    /* if (!cin) {
      error(u8"Δεν έδωσες αριθμό!");
    } else if (pldiast != 2 && pldiast != 3) {
      error(u8"Λάθος πλήθος διαστάσεων!");
    } */

    //Input components
    cin >> diast1;

    if (!cin) {
    throw runtime_error("Wrong input!");
  }
    /* if (!cin) {
      error(u8"Δεν έδωσες αριθμό!");
    }*/

    cin >> diast2; 

    if (!cin) {
      throw runtime_error("Wrong input!");
    }

    /* if (!cin) {
      error(u8"Δεν έδωσες αριθμό!");
    } */
 
    if (pldiast == 3) {
        cin >> diast3 ;
        //Excepion
        if (!cin) {
          throw runtime_error("Wrong input!");
        }
        cout << endl;
        // Output for 3 dimensions
        cout << vector_magnitude(diast1, diast2, diast3) << endl;
    } else {
        //output for 2 dimensions
        cout << vector_magnitude(diast1, diast2) << endl;
    }

    keep_window_open();

    return 0;
}

double vector_magnitude(double a, double b, double c) {
    return sqrt(a*a + b*b + c*c);

}

double vector_magnitude(double a, double b) {
    return sqrt(a*a + b*b);
}