#include "std_lib_facilities.h"

int getcoins();
void pushbacknoms(int a, int b, int c, vector<int> d);
double getcost();
int getbill();
int remaining(int e);
void calculate_change(vector<int> d, int e);

int main() {
  // Get available coins
  cout << "Please insert the available currency coins: ";
  int nom1 = getcoins(), nom2 = getcoins(), nom3 = getcoins();
  
  vector<int> nomism; 
  pushbacknoms(nom1, nom2,nom3, nomism);

 

  
  // Begin loop
  while (true) {
    // Get product cost
    double cost = getcost();

    // If cost == -1 stop the loop
    if (cost == -1) {
      break;
    }

    int cost_a = remaining(cost); 

    
    // Calculate change from each denomination
    cout << "Your change is ";
    calculate_change(nomism, cost_a);
    

    // Chnage that we kept
    if (cost_a > 0) {
      cout << "The vending machine cannot give the following change " << cost_a; 
      cout << endl;
    } 
  }
  
  keep_window_open();
  return 0;
}

int getcoins() {
  int nom;
  cin >> nom;
  if (!cin) {
    throw runtime_error("Wrong input!");
  }
  return nom;
}

void pushbacknoms(int nom1, int nom2, int nom3, vector<int> nomism) {
  // Insert coins in a vector and sort it
  nomism.push_back(nom1);
  nomism.push_back(nom2);
  nomism.push_back(nom3);
  sort(nomism.begin(), nomism.end());
 } 

double getcost() {
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

int getbill() {
   int bill;
    cout << "Please pay using a 200, 500 or 1000 bill: ";
    cin >> bill;
    if (!cin) {
      throw runtime_error("Wrong input!");
    }
    return bill;
 }

 int remaining(int cost) {

   int cost_a = cost * 100;

    // While there is a remaining ammount
    while (cost_a > 0) {
      int bill = getbill();
     
      // Accept only specific bills
      if (bill == 500 || bill == 200 || bill == 1000) {
        cost_a -= bill;
      }
    }

    // Calculate change
    return cost *= -1;
 }

void calculate_change(vector<int> nomism, int cost_a) {
  for (int i = nomism.size() - 1; i >= 0; i--) {
      // Integet division => number of coins
      cout << nomism[i] << "x" << cost_a / nomism[i] << " ";
      // Modulo => remaining cost
      cost_a %= nomism[i];
  }
    cout << endl;
 }