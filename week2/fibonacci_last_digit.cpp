#include <iostream>

int get_fibonacci_last_digit(int n) {
  int fib_n;
  int fib_n_2 = 0;
  int fib_n_1 = 1;
  
  for(int i=2; i <= n; i++){
    fib_n = (fib_n_1 + fib_n_2) % 10; 
    
    fib_n_2 = fib_n_1;
    fib_n_1 = fib_n;
  }
  
  return (n == 0) ? 0 : (n == 1) ? 1 : fib_n;
}
 
 
int main() {
  int n;
  std::cin >> n;
  int c = get_fibonacci_last_digit(n);
  std::cout << c << '\n';
}
