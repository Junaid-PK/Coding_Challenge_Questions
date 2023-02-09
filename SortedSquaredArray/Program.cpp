#include <iostream>
#include <vector>
using namespace std;


vector<int> sortedSquaredArray(vector<int> array) {
  // Write your code here.
    int size = array.size();
    int i = 0;
    int j = size-1;
    vector<int> result(size);
    int k = size-1;
    while(i<=j){
        if(abs(array[i]) > abs(array[j])){
            result[k] = array[i]*array[i];
            i++;
        }
        else{
            result[k] = array[j]*array[j];
            j--;
        }
        k--;
    }
    return result;
}

int main(){
    vector<int> array = {-10,-5,0,5,10};
    vector<int> result = sortedSquaredArray(array);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}