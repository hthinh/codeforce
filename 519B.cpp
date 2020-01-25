#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeSort (vector<int>);
vector<int> merge (vector<int>&, vector<int>&);
int search (vector<int>&, int);
int binSearch (vector<int>& s, int begin, int end, int x);

int main() {
  int n;
  cin >> n;

  vector<int> source;
  vector<int> first;
  vector<int> second;
  
  int tmp;
  
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    source.push_back (tmp);
  }
  source = mergeSort (source);
  
  for (int i = 0; i < n - 1; i++) {
    cin >> tmp;
    first.push_back (tmp);
  }
  first = mergeSort (first);
  
  for (int i = 0; i < n - 2; i++) {
    cin >> tmp;
    second.push_back (tmp);
  }
  second = mergeSort (second);

  for (int i = 0; i<source.size(); i++) {
    if (i >= first.size() || source[i] != first[i]) {
      cout << source[i] << endl;
      break;
    }
  }

  for (int i = 0; i <first.size(); i++) {
    if (i >= second.size() || first[i] != second[i]) {
      cout << first[i] << endl;
      break;  
    }
  }
  
  return 0;
}

int search (vector<int>& s, int x) {
  return binSearch (s, 0, s.size() - 1, x);
}

int binSearch (vector<int>& s, int begin, int end, int x) {
  if (begin > end) return -1;
  
  int middle = (begin + end) / 2;

  if (s[middle] == x) return middle;

  int l_result = binSearch (s, begin, middle - 1, x);

  if (l_result != -1) return l_result;

  return binSearch (s, middle + 1, end, x);
}

vector<int> mergeSort (vector<int> source) {

  if (source.size() <= 1) {
    return source;
  }
  //devide source to two seperated array
  int middle = source.size() / 2;
  vector<int> left (source.begin(), source.begin() + middle);
  left = mergeSort(left);

  vector<int> right (source.begin() + middle, source.end());
  right = mergeSort (right);

  return merge (left, right);
}

vector<int> merge (vector<int>& left, vector<int>& right) {

  vector<int> result;
  result.reserve (left.size() + right.size());
  int l_idx = 0;
  int r_idx = 0;

  while (l_idx < left.size () ||
	 r_idx < right.size()) {

    if (r_idx >= right.size() ||
	( l_idx < left.size() && left[l_idx] <= right[r_idx])) {
      result.push_back (left[l_idx]);
      l_idx++;
    }else {
      result.push_back (right[r_idx]);
      r_idx++;
    }
  }

  return result;
}

