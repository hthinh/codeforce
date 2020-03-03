#include <iostream>
#include <vector>

using namespace std;

// int main() {

//   int t, n, m;
//   vector<int> a, flag;

//   cin >> t;

//   for (int i = 0; i < t; i++) {

//     cin >> n >> m;

//     a.resize(n);
//     flag.resize(n);

//     for (int j = 0; j < n; j++) {
//       cin >> a[j];
//       flag[j] = 0;
//     }

//     int tmp;
//     for (int j = 0; j < m; j++) {
//       cin >> tmp;
//       flag[tmp - 1] = 1;
//       if (flag[tmp] == 0) flag[tmp] = 2;
//     }

//     int state = 0,
//       c_min = 1000,
//       c_max = -1,
//       p_max = -1,
//       _exit = 0;

//     for (int j = 0; j < n; j++) {
//       if (j == 0) {
// 	state = flag[j];

// 	c_min = a[j];
// 	c_max = a[j];
//       }else {
// 	if (state == 0) {
// 	  if (flag[j] == 0) {
// 	    if (a[j] < a[j-1]) {
// 	      cout << "NO" << endl;
// 	      _exit = 1;
// 	      break;
// 	    }
// 	  }else{
// 	    c_min = a[j];
// 	    c_max = a[j];
// 	    p_max = a[j-1];
// 	    state = 1;
// 	  }
// 	}else if (state == 1){
// 	  if (flag[j] == 0) {
// 	    if (c_min < p_max) {
// 	      cout << "NO" << endl;
// 	      _exit = 1;
// 	      break;
// 	    }else{
// 	      if (a[j] < c_max) {
// 		cout << "NO" << endl;
// 		_exit = 1;
// 		break;
// 	      }
// 	      p_max = c_max;
// 	      state = 0;
// 	    }
// 	  }else{
// 	    if (c_min > a[j]) c_min = a[j];
// 	    if (c_max < a[j]) c_max = a[j];
// 	  }

// 	  if (flag[j] == 2) {
// 	    if (c_min < p_max) {
// 	      cout << "NO" << endl;
// 	      _exit = 1;
// 	      break;
// 	    }

// 	    state = 2;
// 	    p_max = c_max;
	    
// 	  }
// 	}else{
// 	  //state == 2
// 	  c_min = a[j];
// 	  c_max = a[j];
// 	  state = flag[j];

// 	  if (state == 0) {
// 	    if (a[j] < p_max) {
// 	      cout << "NO" << endl;
// 	      _exit = 1;
// 	      break;
// 	    }
// 	  }
// 	}
//       }
//     }

//     if (_exit == 0) cout << "YES" << endl;
//   }
//   return 0;
// }

//editorial is much shorter and simpler
//no need nested if/else
//which is different?


int main() {

  int t = 0;
  cin >> t;

  int n, m;
  vector<int> a,p;
  
  while (t--) {
    cin >> n >> m;

    a.resize(n);
    p.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      p[i] = 0;
    }

    for (int i = 0; i < m; i++) {
      int pos = 0;
      cin >> pos;
      p[pos - 1] = 1;
    }

    int p_max = 0, max=a[0];
    bool ok = true;
    for (int i = 1; i < n && ok; i++) {
      if (!p[i-1]) p_max = max;

      if (p_max > a[i]) {
	ok = false;
      }

      if (max < a[i]) max = a[i];
    }

    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
