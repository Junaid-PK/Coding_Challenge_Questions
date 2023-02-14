#include <iostream>
#include <vector>

using namespace std;



bool isOutOfBounds(int row, int col, int height, int width){
return row<0 || row>height || col<0 || col>width;
}

vector<int> zigzagTraverse(vector<vector<int>> array) {
    int height = array.size()-1;
    int width  = array[0].size()-1;
    int row = 0;
    int col = 0;
    vector<int> result;
    bool goingDown = true;
    while (!isOutOfBounds(row,col,height,width)){
            result.push_back(array[row][col]);
        if (goingDown){
            if (col==0 || row == height){
                goingDown = false;
                if(row == height){
                    col+=1;
                }else{
                    row+=1;
                }
            }
            else{
                row+=1;
                col-=1;
            }
        }
        else{
            if(row == 0 || col == width){
                goingDown =true;
                if(col == width){
                    row+=1;
                }
                else{
                    col+=1;
                }
            }
            else{
                row-=1;
                col+=1;
            }
        }
    }

  return result;
}


int main(){
vector<vector<int>> test = {
          {1, 3, 4, 10}, {2, 5, 9, 11}, {6, 8, 12, 15}, {7, 13, 14, 16}};
vector<int> result = zigzagTraverse(test);

for(int i=0;i<result.size();i++){
    cout<<result[i]<<" ";
}


}
