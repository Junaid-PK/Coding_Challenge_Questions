#include <iostream>
#include <vector>
using namespace std;

#define MAX_INT 2147483647
#define MIN_INT -2147483648



bool isOutOfOrder(int i, int num, vector<int> array) {
  if (i == 0) {
    return num > array[i + 1];
  }
  if (i == array.size() - 1) {
    return num < array[i - 1];
  }
  return num > array[i + 1] || num < array[i - 1];
}


vector<int> subarraySort(vector<int> array) {
  // Write your code here.
  int minOutOfOrder = MAX_INT;
  int maxOutOfOrder = MIN_INT;
  for (int i = 0; i < array.size(); i++) {
    int num = array[i];
    if (isOutOfOrder(i, num, array)) {
      minOutOfOrder = min(minOutOfOrder, num);
      maxOutOfOrder = max(maxOutOfOrder, num);
    }
  }
  if (minOutOfOrder == MAX_INT) {
    return {-1, -1};
  }
  int subarrayLeftIdx = 0;
  while (minOutOfOrder >= array[subarrayLeftIdx]) {
    subarrayLeftIdx++;
  }
  int subarrayRightIdx = array.size() - 1;
  while (maxOutOfOrder <= array[subarrayRightIdx]) {
    subarrayRightIdx--;
  }
  return {subarrayLeftIdx, subarrayRightIdx};
}



int main(){
  vector<int> array = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
  vector<int> result = subarraySort(array);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  cout << endl;
  return 0;
}
