#include <iostream>
#include <vector>

using namespace std;

void initMatrix(vector<vector<int>> &matrix, int N) {
    for (int i = 0; i < N; i++) {
        vector<int> row;

        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            row.push_back(num);
        }
        matrix.push_back(row);
    }
    
    return;
}

void rotateMatrix(vector<vector<int>> &matrix, int N) {
    vector<vector<int>> rotated(N, vector<int>(N, 0));
    
    // 배열의 시계방향 회전은 [j][N - i - 1]에 [i][j]를 순서대로 대입 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
        	rotated[j][N - i - 1] = matrix[i][j];
        }
    }
    
    matrix = rotated;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N;
        cin >> N;
        vector<vector<int>> matrix;
        initMatrix(matrix, N);
        
     	vector<vector<vector<int>>> rotated_matrices;
        
        for (int rotation = 0; rotation < 3; rotation++) {
            rotateMatrix(matrix, N);
            rotated_matrices.push_back(matrix);
        }
        
        int row = 0;
        int col = 0;
        int matrix_idx = 0;
        int count = 0;
        int max_roop = N * N * 3;
		        
        cout << "#" << test_case << "\n";
        while (count < max_roop) {
            if (col >= N) {
                cout << " ";
                col = 0;
                matrix_idx++;
            }
            if (matrix_idx >= 3) {
                cout << "\n";
                matrix_idx = 0;
                row++;
            }
            cout << rotated_matrices[matrix_idx][row][col];
            col++;
            count++;
        }
        cout  << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}