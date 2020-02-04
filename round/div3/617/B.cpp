#include <iostream>

using namespace std;

int burlesCanSpend (int numb) {

  if (numb < 10) return numb;

  return (numb - numb % 10) + burlesCanSpend (numb / 10 + numb % 10);
  
}
int main() {
  
  int t = 0;
  int s = 0;

  cin >> t;

  for (int i = 0; i < t; i++) {
    cin >> s;
    cout << burlesCanSpend (s) << endl;
  }
  return 0;
}
