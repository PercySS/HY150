#include "std_lib_facilities.h"


int main() {
  // Get available coins
  cout << "Please insert the available currency coins: ";
  int nom1, nom2, nom3;
  vector<int> nomism; 
  cin >> nom1 >> nom2 >> nom3;
  if (!cin) {
    throw runtime_error("Wrong input!");
  }

  // Insert coins in a vector and sort it
  nomism.push_back(nom1);
  nomism.push_back(nom2);
  nomism.push_back(nom3);
  sort(nomism.begin(), nomism.end());

  // Begin loop
  while (true) {
    // Get product cost
    cout << "Please insert the cost of the product (insert -1 to stop): ";
    double cost;
    cin >> cost;
    if (!cin) {
      throw runtime_error("Wrong input!");
      /* cout << "Wrong input!";
      keep_window_open();
      return -1; */
    }

    // If cost == -1 stop the loop
    if (cost == -1) {
      break;
    }

    // Calculate remaining ammount as cents (* 100)
    int cost_a = cost * 100;

    // While there is a remaining ammount
    while (cost_a > 0) {
      int bill;
      cout << "Please pay using a 200, 500 or 1000 bill: ";
      cin >> bill;
      if (!cin) {
        throw runtime_error("Wrong input!");
      }
      // Accept only specific bills
      if (bill == 500 || bill == 200 || bill == 1000) {
        cost_a -= bill;
      }
    }

    // Calculate change
    cost_a *= -1;
    
    // Calculate change from each denomination
    cout << "Your change is ";
    for (int i = nomism.size() - 1; i >= 0; i--) {
      // Integet division => number of coins
      cout << nomism[i] << "x" << cost_a / nomism[i] << " ";
      // Modulo => remaining cost
      cost_a %= nomism[i];
    }
    cout << endl;

    // Chnage that we kept
    if (cost_a > 0) {
      cout << "The vending machine cannot give the following change " << cost_a; 
      cout << endl;
    } 
  }
  
  keep_window_open();
  return 0;
}