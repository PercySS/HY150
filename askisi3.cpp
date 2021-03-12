#include "std_lib_facilities.h"

float getInput(string);

float calculateTotalTime(int);
float calculateRange(int, float);

int main() {
    // int velocity = getVelocity(); 
    // int height = getHeight();

    int velocity = getInput("Please enter value for initial velocity (in m/sec)"); 
    int height = getInput("Please enter value for height (in km)");

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

float getInput(string message) {
    float ret;
    cout << message << " => ";
    cin >> ret;

    // Checks
    if (!cin) {
        throw runtime_error("Not a number!");
    } else if (ret < 0) {
        throw runtime_error("Negative value!");
    }

    cout << endl;

    return ret;
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
