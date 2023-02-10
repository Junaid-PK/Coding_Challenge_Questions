#include <iostream>
#include <vector>
#include <map>

using namespace std;

string tournamentWinner(vector<vector<string>> competitions,vector<int> results) {
    map<string,int> resultsMap;
    for (int i=0; i< competitions.size(); i++){
        if (results[i] == 0){
            int points = resultsMap[competitions[i][1]];
            points+=3;
            resultsMap[competitions[i][1]] = points;
        }

        if (results[i] == 1){
            int points = resultsMap[competitions[i][0]];
            points+=3;
            resultsMap[competitions[i][0]] = points;
        }

    }

    int max = 0;
    string result = "";
    for(auto it = resultsMap.cbegin(); it != resultsMap.cend(); ++it)
{
    if (it->second > max){
        max = it->second;
        result = it->first;
    }
}
  return result;
}

int main(){
    vector<vector<string>> competitions = {{"HTML", "C#"}, {"C#", "Python"}, {"Python", "HTML"}};
    vector<int> results = {0, 0, 1};
    string result = tournamentWinner(competitions,results);
    cout<<result;
}
