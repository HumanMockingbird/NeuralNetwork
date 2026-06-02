#pragma once
class Matrix
{
public:
	double** values;
	size_t rows, cols;

	void MultiplyMatrixes(Matrix* A, Matrix* B)
	{
		if (CheckMultiplyAbility(A,B))
		{
			for (size_t i = 0; i < A->rows; i++)
			{
				for (size_t j = 0; j < B->cols; j++)
				{
					for (size_t k = 0; k < A->cols; k++)
					{
						this->values[i][j] += A->values[i][k] * B->values[k][j];
					}
				}
			}
		}
		else
	}

	static bool CheckMultiplyAbility(Matrix* A, Matrix* B)
	{
		return (A->cols == B->rows);// Результат будет (A.rows x B.cols)
	}
};

