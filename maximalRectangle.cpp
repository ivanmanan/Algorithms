#include "globals.h"

int maximalRectangle(vector<vector<char>>& matrix) {
	int row = matrix.size();
	if (row == 0) return 0;
	int col = matrix[0].size();
	vector<int> count(col, 0);
	int res = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (matrix[i][j] == '1') count[j]++;
			else count[j] = 0;
			int min = count[j];
			for (int z = j; z >= 0; z--)
			{
				if (count[z] == 0) break;
				if (count[z] < min) min = count[z];
				res = max(res, min * (j - z + 1));
			}
		}
	}
	return res;
}