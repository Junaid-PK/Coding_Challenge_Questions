#include <iostream>
using namespace std;


bool isValidSubsequence(int *arr1,int size1, int *arr2, int size2){

    int i = 0;
    int j =0;
    bool isValid = false;
    while(i<size1 && j<size2){
        if(arr1[i] == arr2[j]){
            i++;
            j++;
            isValid = true;
        }
        else{
            i++;
            isValid = false;
        }
    }
    if(j == size2){
        return isValid;
    }
    else{
        return false;
    }
}
int main(){
    int arr1[4] = {1, 1, 6, 1};
    int arr2[4] = {1, 1, 1, 6};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    bool result = isValidSubsequence(arr1,size1,arr2,size2);
    cout<<result;
}