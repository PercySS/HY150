#include "std_lib_facilities.h"

/*
 * Function declaration
 * ------------------------------ */

int get_nom();
void store_and_sort_noms(int, int, int, vector<int>&);
double get_cost();
int get_bill(int);
int remaining(double);
void calculate_change(vector<int>, int);

/*
 * Main
 * ------------------------------ */

int main() {
  // Get available coins
  cout << "Please insert the available currency coins: ";
  int nom1 = get_nom(), nom2 = get_nom(), nom3 = get_nom();
  
  vector<int> nomism; 
  store_and_sort_noms(nom1, nom2, nom3, nomism);
  
  // Begin loop
  while (true) {
    // Get product cost
    cout << endl;
    double cost = get_cost();

    // If cost == -1 stop the loop
    if (cost == -1) {
      break;
    }

    int cost_a = remaining(cost); 
    
    // Calculate change from each denomination
    calculate_change(nomism, cost_a);       
  }
  
  keep_window_open();
  return 0;
}

/*
 * Function implementation
 * ------------------------------ */

int get_nom() {
  int nom;
  cin >> nom;
  if (!cin) {
    throw runtime_error("Wrong input!");
  }
  return nom;
}

void store_and_sort_noms(int nom1, int nom2, int nom3, vector<int> &nomism) {
  // Insert coins in a vector and sort it
  nomism.push_back(nom1);
  nomism.push_back(nom2);
  nomism.push_back(nom3);

  sort(nomism.begin(), nomism.end());
 } 




double get_cost() {
  cout << "Please insert the cost of the product (insert -1 to stop): ";
  double cost;
  cin >> cost;
  if (!cin) {
    throw runtime_error("Wrong input!");
    
    /* cout << "Wrong input!";
    keep_window_open();
    return -1; */
  }

  return cost;
}

int get_bill(int cost_a) {
  int bill;
  cout << "Please pay using a 200, 500 or 1000 bill (" << cost_a << " left): ";
  cin >> bill;
  if (!cin) {
    throw runtime_error("Wrong input!");
  }
  return bill;
 }

int remaining(double cost) {

  int cost_a = cost * 100;

  // While there is a remaining ammount
  while (cost_a > 0) {
    int bill = get_bill(cost_a);
    
    // Accept only specific bills
    if (bill == 500 || bill == 200 || bill == 1000) {
      cost_a -= bill;
    }
  }

  // Calculate change
  return cost_a *= -1;
}

void calculate_change(vector<int> nomism, int cost_a) {
  cout << "Your change is ";
  for (int i = nomism.size() - 1; i >= 0; i--) {
      // Integet division => number of coins
      cout << nomism[i] << "x" << cost_a / nomism[i] << " ";
      // Modulo => remaining cost
      cost_a %= nomism[i];
  }
  
  cout << endl;

  // Change that we couldn't give back
  if (cost_a > 0) {
    cout << "The vending machine cannot give the following change " << cost_a; 
    cout << endl;
  } 
}