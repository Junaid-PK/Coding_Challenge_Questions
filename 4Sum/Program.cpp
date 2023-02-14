#include <iostream>
#include <vector>
using namespace std;

// Sort the array
void sort(vector<int> &array) {
    int n = array.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
  int n = array.size();
    vector<vector<int>> result;
    // sort the array
    sort(array);
    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            int left = j + 1;
            int right = n - 1;
            while (left < right) {
                int sum = array[i] + array[j] + array[left] + array[right];
                if (sum == targetSum) {
                    vector<int> temp;
                    temp.push_back(array[i]);
                    temp.push_back(array[j]);
                    temp.push_back(array[left]);
                    temp.push_back(array[right]);
                    result.push_back(temp);
                    left++;
                    right--;
                } else if (sum < targetSum) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    return result;
}



int main() {
    vector<int> array = {7, 6, 4, -1, 1, 2};
    int targetSum = 16;
    vector<vector<int>> result = fourNumberSum(array, targetSum);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}