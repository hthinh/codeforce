#include <iostream>

using namespace std;


int main(int argc, char** argv) {

  int t, n, tmp;
  int sum;
  cin >> t;

  int flag = 0;
  for (int i = 0; i < t; i++) {
    sum = 0;
    flag = 0;
    cin >> n;
    
    for (int j = 0; j < n; j++) {
      cin >> tmp;
      flag += tmp % 2;
      sum += tmp;
    }

    if (n == 1) {
      if (flag == 1) cout << "YES" << endl;
      else cout << "NO" << endl;
    }else{
      if (sum % 2 == 1) cout << "YES" << endl;
      else {
	if (flag == 0 || flag == n) cout << "NO" << endl;
	else cout << "YES" << endl;
      }
    }
  }

  return 0;
}
