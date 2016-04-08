#include <iostream>

int main(){
	int n = 0;
	long long max1 = 0;
	long long max2 = 0;
	long long result = 0;
	int aux = 0;
	
	std::cin >> n;
	
	for(int i=0; i < n; i++){
		std::cin >> aux;

		if(aux > max1 && aux > max2){
			if(max1 > max2){
				max2 = max1;
			}
			max1 = aux;
		} else if(aux > max1){
			if(max1 > max2){
				max2 = max1;
			}
			max1 = aux;
		} else if(aux > max2){
			max2 = aux;
		}		
	}

	result =  max1 * max2;
	std::cout << result;
	
	return 0;
}