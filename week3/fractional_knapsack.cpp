#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  for(int i=0; i<weights.size(); i++){
    double amount = 0.0;
    
    if(capacity == 0) return value;
    
    int indexMaxValuePerUnit = 0;
    double max = 0;
    for(int j=0; j<weights.size(); j++){
      if(weights[j] <= 0) continue;
      double valuePerUnit = (double) values[j]/weights[j];
      
      if(valuePerUnit > max){
        max  = valuePerUnit;
        indexMaxValuePerUnit = j;
      }
    }
    
    amount = (weights[indexMaxValuePerUnit] <= capacity) ? weights[indexMaxValuePerUnit] : capacity;
    value += amount * ( (double) values[indexMaxValuePerUnit] / weights[indexMaxValuePerUnit]);
    weights[indexMaxValuePerUnit] -= amount; 
    capacity -= amount;
  }
  
  return value;
}


int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  vector<int> unitValues(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
    unitValues[i] = values[i] / weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
