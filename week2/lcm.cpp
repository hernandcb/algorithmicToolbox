#include <iostream>

int gcd(int a, int b){
  if(b > a){
    int temp = a;
    a = b;
    b = temp;
  }
  
  if(b == 0){
    return a;
  }
  
  int a_prime = a % b;
  return gcd(a_prime, b);
}

long long lcm(long a, long b) {
  int gcd_result = gcd(a, b);
  
  return (long long) ( (long long) (a*b) ) / gcd_result;
}

int main() {
  long a, b;
  std::cin >> a >> b;
  std::cout << (long long) lcm(a, b) << std::endl;
  return 0;
}
