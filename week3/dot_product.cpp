#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long min_dot_product(vector<int> a, vector<int> b) {
  std::sort(a.begin(), a.end(), std::greater<int>());
  std::sort(b.begin(), b.end());
  
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += (long long) a[i] * b[i];
  }
  return result;
}

long long min_dot_product_naive(vector<int> a, vector<int> b) {
  // write your code here
  long long result = 0;
  int indexMaxA =0;
  int indexMinB =0;
  for (size_t i = 0; i < a.size(); i++) {
    indexMaxA = std::max_element(a.begin(), a.end()) - a.begin();
    indexMinB = std::min_element(b.begin(), b.end()) - b.begin();
        
    result += (long long) a[indexMaxA] * b[indexMinB];
    a[indexMaxA] = -1000000;
    b[indexMinB] = 1000000;
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  
  std::cout << min_dot_product(a, b) << std::endl;  
}
