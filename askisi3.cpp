#include "std_lib_facilities.h"

int getVelocity();
int getHeight();

float calculateTotalTime(int);
float calculateRange(int, float);

int main() {
    int velocity = getVelocity(); 
    int height = getHeight();

    // Conversion km to m
    height *= 1000;

    float time = calculateTotalTime(height);
    float range = calculateRange(velocity, time);

    cout << "The total range that the object will go through is: " << range/1000 << "km" << endl;
    cout << "The total time that the object will be in the air is: " << time << "sec" << endl;

    cout << endl;

    keep_window_open();

    return 0;
}

int getVelocity() {
    float velocity;
    cout << "Please enter initial velocity (in m/sec): ";
    cout << "=> ";
    cin >> velocity;

    // Checks
    if (!cin) {
        throw runtime_error("Not a number!");
    } else if (velocity < 0) {
        throw runtime_error("Negative value!");
    }

    /* if (!cin) {
      error(u8"Δεν έδωσες αριθμό!");
    } else if (arxtax < 0) {
      error(u8"Έδωσες αρνητική ταχύτητα!");
    } */

    cout << endl;

    return velocity;
}

int getHeight() {
    float height;
    cout << "Please enter value for height (in km): ";
    cout << "=> ";
    cin >> height;

    // Checks
    if (!cin) {
      throw runtime_error("Not a number!");
    } else if (height < 0) {
      throw runtime_error("Negative value");
    }

    /* if (!cin) {
      error(u8"Δεν έδωσες αριθμό!");
    } else if (height < 0) {
      error(u8"Έδωσες αρνητικό ύψος!");
    } */
    
    cout <<  endl;

    return height;
}

// Calculations for finding the total time
float calculateTotalTime(int height) {
    // Giving g constant its actual value finding it from searching the web
    const float g = 9.80665;
    return sqrt((2 * height) / g);
}

// Calculations for finding total range
float calculateRange(int velocity, float time) {
    return velocity * time;
}
