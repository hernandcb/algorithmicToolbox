#include <iostream>

int get_change(int m) {
  int n = 0;
  int v[3] = {10, 5, 1};
  
  for(int i=0; i<3; i++){
    if(v[i]> m) continue;
    
    int a = m/v[i];
    m -= (a*v[i]);
    n += a;
  }
  return n;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << get_change(n) << '\n';
}
