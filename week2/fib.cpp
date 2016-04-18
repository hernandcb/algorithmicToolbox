#include <iostream>

int calc_fib_recursive(int n) {
    if (n <= 1)
        return n;

    return calc_fib(n - 1) + calc_fib(n - 2);
}

long calc_fibonacci(int n){
	long results[n+1];
	results[0] = 0;
	results[1] = 1;
	
	for(int i=2; i <= n; i++){
		results[i] = results[i-1] + results[i-2];
	}
	
	return results[n];
}

int main() {
    int n = 0;
    std::cin >> n;

    std::cout << (long)calc_fibonacci(n) << '\n';
    return 0;
}
