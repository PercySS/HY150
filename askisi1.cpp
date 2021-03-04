#include "std_lib_facilities.h"



double vector_magnitude(double a, double b);
double vector_magnitude(double a, double b, double c);


int main(){
    // dilono kai zitao apo to xristi na m dosei diastaseis kai to plithos ton diastaseon
    int pldiast;
    double diast1, diast2, diast3;
    cout << "Dose m tis diastaseis toy dianismatos kai tis syntetagmenes toy sto xoro.\n" << endl;
    cin >> pldiast;

    if (!cin) {
      error(u8"Δεν έδωσες αριθμό!");
    } else if (pldiast != 2 && pldiast != 3) {
      error(u8"Λάθος πλήθος διαστάσεων!");
    }

    cout << endl;
    cin >> diast1;

    if (!cin) {
      error(u8"Δεν έδωσες αριθμό!");
    }

    cin >> diast2;

    if (!cin) {
      error(u8"Δεν έδωσες αριθμό!");
    }
 
    if (pldiast == 3) {
        cin >> diast3 ;
        cout << endl;

        cout << vector_magnitude(diast1, diast2, diast3) << endl;
    } else {
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