#include <iostream>
using namespace std;
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector>
//楊英豪 B10803207

void calculateArea(int &x, int &y, int &z) {
  float s = (x + y + z) / 2;
  float area = sqrt(s * (s - x) * (s - y) * (s - z));
  cout << "These values can form a triangle!, "
       << "Area of triangle is " << fixed << setprecision(2) << area << "\n\n";
}

void isTriangle(int &x, int &y, int &z) {
  // checks if 3 sides can be a triangle
  if (x + y <= z || x + z <= y || y + z <= x) {
    cout << "These values can't form a triangle! \n\n";
  } else {
    calculateArea(x, y, z);
  }
}

void checkSideValues(int &x, int &y, int &z) {
  if (x > 99 || y > 99 || z > 99) {
    cout << "Value more than '100' detected, Please enter a value between "
            "0~100 \n";
  } else if (x < 0 || y < 0 || z < 0) {
    cout << "Negative value detected, Please enter a value between 0~100 \n\n";
  } else {
    isTriangle(x, y, z);
  }
}

void print(vector<int> const &random_number)
{
    for (auto it =random_number.cbegin(); it != random_number.cend(); it++) {
        cout << *it << ' ';
    }
}

void generateRandomSides(int &x, int &y, int &z) {
  srand(time(0));
  vector<int> random_number;
  for (int i = 0; i < 9; i++) {
    x = 1 + (rand() % 100);
    y = 1 + (rand() % 100);
    z = 1 + (rand() % 100);
    cout << x << ", " << y << ", " << z << "\n";
    checkSideValues(x, y, z);
    
    random_number.insert(random_number.end(), {x, y, z});
  }
  // print(random_number);
}


void manualInput(int &x, int &y, int &z) {
  for (int i = 0; i < 9; i++) {
    cout << "Loop " << i << " | Insert 3 sides of triangle:";
    cin >> x >> y >> z;
    checkSideValues(x, y, z);
  }
}

int main() {
  int x, y, z;
  int mode;
  cout << "Please Enter Mode by number: 1.Manual Input 2.Random" << endl;
  cin >> mode;
  if (mode == 1) {
    manualInput(x, y, z);
  } else {
    generateRandomSides(x, y, z);
  }
  
}
