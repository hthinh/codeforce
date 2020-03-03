#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> sum (vector<int> x, vector<int> t) {
  vector<int> r;
  r.resize(26);
  for (int i = 0; i < 26; i++) {
    r[i] = x[i] + t[i];
  }

  return r;
}

string my_to_string (vector<int> r) {
  string s;
  for (int i = 0; i < r.size(); i++) {
    s += to_string(r[i]) + " ";
  }
  return s;
}
int main(){
  int t = 0;

  cin >> t;

  int n, m;
  char c;
  vector<vector<int>> x;
  while (t--) {
    cin >> n;
    cin >> m;

    x.resize(n);
    
    for (int i = 0; i < n; i++) {
      cin >> c;
      vector<int> tmp;
      tmp.resize(26, 0);
      tmp[c - 'a']++;

      if (i == 0) x[i] = tmp;
      else x[i] = sum (x[i - 1], tmp);
    }

    vector<int> r;
    r.resize(26, 0);
    for (int i = 0; i < m; i++) {
      int pos;
      cin >> pos;
      
      r = sum (r, x[pos - 1]);
    }

    r = sum(r, x[n-1]);
    cout << my_to_string (r) << endl;
  }
  return 0;
}






