#include <iostream>
#include <vector>
using namespace std;

// Partition of the Function
int partition_array(vector<int> &coins, int start, int end)
{
    int pivot = coins[end];
    int partitionIndex = start;
    for (int i=start;i<end;i++){
        if (coins[i]<=pivot){
            swap(coins[i],coins[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(coins[partitionIndex],coins[end]);
    return partitionIndex;
}
// Quick Sort the Array
void QuickSort(vector<int> &coins, int start, int end){
    if(start<end)
    {
        int partionIndex = partition_array(coins,start,end);
        QuickSort(coins,start,partionIndex-1);
        QuickSort(coins,partionIndex+1,end);
    }
}
int nonConstructibleChange(vector<int> &coins) {
  // Write your code here.

  QuickSort(coins, 0,coins.size()-1);
  int change = 0;
  for (int i=0; i<coins.size();i++){
      if(coins[i]>change+1){
        return change+1;
      }
      change+=coins[i];

  }
  return change+1;
}

int main(){
    vector<int> input = {5, 7, 1, 1, 2, 3, 22};
    int expected = 20;

    auto actual = nonConstructibleChange(input);
    cout << actual;

}
