#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for (int arr1_row = 0; arr1_row < arr1.size(); arr1_row++) {
        vector<int> answer_row;
        int j = 0;
        
        while (j < arr2[0].size()) {
            int i = 0;
            int temp_calc = 0;
            
            while (i < arr1[0].size()) {
                temp_calc += arr1[arr1_row][i] * arr2[i][j];
                i++;
            }
            answer_row.push_back(temp_calc);
            j++;
        }
        answer.push_back(answer_row);
    }
    
    return answer;
}