#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> largestRange(vector<int> array) {
  // Store element in a Map

  map<int,bool> elementCheckMap;
  vector<int> bestRange;
  int largestRange = 0;

  for(int i=0; i< array.size();i++){
    elementCheckMap[array[i]] = true;
  }
int currentLen = 0;
  for(int i=0; i< array.size();i++){
        if (elementCheckMap[array[i]] == false){
            continue;
        }
        elementCheckMap[array[i]] = false;
        currentLen = 1;
        int left = array[i]-1;
        int right = array[i]+1;
        for (auto i : elementCheckMap){
            if (left == i.first){
                elementCheckMap[left] = false;
                currentLen+=1;
                left-=1;
            }
        }

        for (auto i : elementCheckMap){
            if (right == i.first){
                elementCheckMap[right] = false;
                currentLen+=1;
                right+=1;
            }
        }

        if (currentLen>largestRange){
            largestRange = currentLen;
            bestRange = {left+1,right-1};
        }
  }
        return bestRange;
}


int main(){

 vector<int> result = largestRange({1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6});
 cout<<"Largest range is {";
 for (int i=0; i<result.size();i++){
    cout<<result[i]<<",";
 }
 cout<<"}";


}
