#include <iostream>
#include <vector>

using namespace std;


int main() {
  int t = 0;

  cin >> t;

  for (int i = 0; i < t; i++) {
    int a, b;

    cin >> a >> b;

    int diff = b - a;

    if (diff == 0) cout << 0 << endl;
    if (diff > 0) {
      if (diff % 2 == 1) {
	cout << 1 << endl;
      }else {
	cout << 2 << endl;
      }
    }
    if (diff < 0) {
      if (diff % 2 == 0) {
	cout << 1 << endl;
      }else {
	cout << 2 << endl;
      }
    }
  }
  return 0;
}
