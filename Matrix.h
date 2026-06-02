#pragma once
class Matrix
{
public:
	Matrix(size_t rows, size_t cols, double defaultValue = 0.0)
	{
		this->rows = rows;
		this->cols = cols;
		std::cout << "Created matrix (" << rows << " x " << cols << ")" << std::endl;
		values = new double* [rows];
		for (size_t i = 0; i < rows; i++)
		{
			values[i] = new double[cols];
			for (int j = 0; j < cols; j++)
			{
				values[i][j] = defaultValue;
			}
		}
	}
	~Matrix()
	{
		for (size_t i = 0; i < rows; i++)
		{
			delete[] values[i];
		}
		delete[] values;
		std::cout << "Deleted matrix (" << rows << " x " << cols << ")" << std::endl;
	}

	double** values;
	size_t rows, cols;

	void GetFromMultiplication(Matrix* A, Matrix* B)
	{
		if (CheckMultiplyAbility(A, B))
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
		//else
		//TODO throw exception
	}

	void GetFromFile(std::string filename)
	{
		//TODO
	}

	void Out()
	{
		std::cout << "Matrix output (" << rows << "x" << cols << "):" << std::endl;
		for (size_t i = 0; i < rows; i++)
		{
			std::cout << "[ ";
			for (size_t j = 0; j < cols; j++)
			{
				std::cout << this->values[i][j] << " ";
			}
			std::cout << "]" << std::endl;
		}
	}

	static bool CheckMultiplyAbility(Matrix* A, Matrix* B)
	{
		return (A->cols == B->rows);// Результат будет (A.rows x B.cols)
	}
};

