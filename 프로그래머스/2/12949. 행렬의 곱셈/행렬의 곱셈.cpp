#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    for (int arr1_row = 0; arr1_row < arr1.size(); arr1_row++) {
        vector<int> new_row;
        int arr1_columns = arr1[0].size();
        int arr2_columns = arr2[0].size();
        int j = 0;
        
        for (int arr2_column = 0; arr2_column < arr2_columns; arr2_column++) {
            int i = 0;
            int temp_calc = 0;
            
            while (i < arr1_columns) {
                temp_calc += arr1[arr1_row][i] * arr2[i][j];
                i++;
            }
            new_row.push_back(temp_calc);
            j++;
        }
        answer.push_back(new_row);
    }
    
    return answer;
}