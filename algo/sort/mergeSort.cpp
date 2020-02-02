#include <iostream>
#include <vector>

using namespace std;

void mergeSort (vector<int>& arr, int left, int right);
void merge (vector<int>& arr, int left, int middle, int right); 

int main (int argc, char ** argv) {
  int n;
  cin >> n;
  int tmp;
  vector<int> a;
  a.reserve (n);
  for (int i=0; i<n; i++) {
    cin >> tmp;
    a.push_back (tmp);
  }

  mergeSort (a, 0, a.size() - 1);

  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  
  return 0;
}

void mergeSort (vector<int>& arr, int left, int right) {
  if (left >= right) return;
  int middle = (right + left) / 2;

  mergeSort (arr, left, middle);
  mergeSort (arr, middle + 1, right);
  merge (arr, left, middle, right);
}

void merge (vector<int>& arr, int left, int middle, int right) {

  vector<int> tmp_arr (right - left + 1);
  int k = 0;
  int left_idx = left;
  int right_idx = middle + 1;

  while (k <= right - left) {
    if (left_idx > middle) {
      tmp_arr [k] = arr[right_idx];
      right_idx++;
    }else if (right_idx > right) {
      tmp_arr [k] = arr[left_idx];
      left_idx++;
    }else if (arr[left_idx] <= arr[right_idx]) {
      tmp_arr[k] = arr[left_idx];
      left_idx++;
    }else{
      tmp_arr[k] = arr[right_idx];
      right_idx++;
    }
    k++;
  }

  for (int i = left; i<= right; i++) {
    arr[i] = tmp_arr[i - left];
  }
  
}
