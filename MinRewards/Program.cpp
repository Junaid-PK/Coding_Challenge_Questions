#include <iostream>
#include <vector>
using namespace std;

int minRewards(vector<int> scores) {
  // Write your code here.
  int size = scores.size();
  vector<int> rewards(size,1);
  for(int k=0;k<size;k++){
        cout<<rewards[k];
  }

  for (int i=1; i<size;i++){
    if (scores[i]>scores[i-1]){
        rewards[i] = rewards[i-1]+1;
    }
  }

  for(int j= size-2;j>=0;j--){
    if (scores[j]>scores[j+1]){
        rewards[j]= max(rewards[j],rewards[j+1]+1);
    }
  }
  int result = 0;
  for(int k=0;k<size;k++){
    result+=rewards[k];
  }
  return result;
}

int main(){
int result = minRewards({8, 4, 2, 1, 3, 6, 7, 9, 5});
cout<< result;
}
