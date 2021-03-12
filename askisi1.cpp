#include "std_lib_facilities.h"



double vector_magnitude(double a, double b);
double vector_magnitude(double a, double b, double c);
double getdiast();

int main(){
    // Input for dimensions of the vector
    int pldiast;
    cout << "Type the dimensions of the vector.\n" << endl;
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

    
    
    //Input for components
    double diast1 = getdiast(), diast2 = getdiast(), diast3;
    if (pldiast == 3) diast3 = getdiast();
    
    //Calculation of the vector's meter
    if (pldiast == 3) {
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

double getdiast() {
  double diast;
  cout << "Type component. =>";
  cin >> diast;
  
  //Exception
  if (!cin) {
    throw runtime_error("Wrong input!");
  }

  return diast;
}