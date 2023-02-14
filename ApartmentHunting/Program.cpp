// You're looking to move into a new apar-ment on specific street and you're given a list of contiguous
// blocks on that street where each block contains an apartment that you could move into.
// You also have a list of requirements: a list of buildings that are important to you. For instance, you
// might value having a school and a wrn near your apartn-pnt. The list of blocks thatyou have contains
// information at every block about all of the buildings that are present and absent at the block in
// question. For instance, for every block you might know whether a school. a pool. an office, and a ym
// are present.
// In order to optimize your life, you want to pick an apartment block such thatyou minimize the farthest
// distance you'd have to walk from your apartr-nent to reach any of your required buildings.
// Write a function that takes in a list of contiguous blocks on a specific street and a list of your required
// buildings and that returns the location (the index) of the block that's most optimal for you.
// If there are multiple most optimal blocks. your function can return ttE index of any one of them.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int apartmentHunting(vector<unordered_map<string, bool>> blocks,
                     vector<string> reqs) {
  // Write your code here;
  vector<int> dists[2];
  dists[0].resize(blocks.size());
  dists[1].resize(blocks.size());

  for (int r=0; r<reqs.size();++r){
    int i=r&1;
    for(int j=0;j<blocks.size();++j){
      if(blocks[j][reqs[r]]){
        dists[i][j] = 0;
      }else if (j==0 || dists[i][j-1] == INT_MAX){
        dists[i][j] = INT_MAX;
      }
      else{
        dists[i][j] = dists[i][j-1]+1;
      }
    }


  for(int j=blocks.size()-2;j>=0;--j){
    dists[i][j] = min(dists[i][j], dists[i][j+1]+1);
  }

  for(int j=0; j< blocks.size(); ++j){
    dists[i][j] = max(dists[i][j], dists[i^1][j]);

  }
                     }
  const vector<int> & dist = dists[(reqs.size()- 1) & 1];

  return min_element(begin(dist),end(dist)) - begin(dist);
}
int main() {
    vector<unordered_map<string, bool>> blocks(5);

      blocks[0].insert({"gym", false});
      blocks[0].insert({"school", true});
      blocks[0].insert({"store", false});

      blocks[1].insert({"gym", true});
      blocks[1].insert({"school", false});
      blocks[1].insert({"store", false});

      blocks[2].insert({"gym", true});
      blocks[2].insert({"school", true});
      blocks[2].insert({"store", false});

      blocks[3].insert({"gym", false});
      blocks[3].insert({"school", true});
      blocks[3].insert({"store", false});

      blocks[4].insert({"gym", false});
      blocks[4].insert({"school", true});
      blocks[4].insert({"store", true});

      vector<string> reqs = {"gym", "school", "store"};
    cout << apartmentHunting(blocks, reqs) << endl;
    return 0;
}
