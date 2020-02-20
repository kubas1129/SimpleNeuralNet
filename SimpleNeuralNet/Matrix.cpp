#include "Matrix.h"
#include <regex>

Matrix::Matrix()
{
	this->matrix = std::vector<std::vector<float>>{};
}

Matrix::Matrix(int rows, int columns)
{
	std::vector<float> x(columns,0.f);
	this->matrix = std::vector<std::vector<float>>(rows, x);
	this->columns = columns;
	this->rows = rows;
}

Matrix::Matrix(std::vector<std::vector<float>> data)
{
	this->matrix = data;
	if (data.size() > 0)
	{
		this->rows = data.size();
		this->columns = data[0].size();
	}
}

Matrix::Matrix(std::initializer_list<float> data)
{
	matrix.push_back({});
	for (float i : data)
		matrix[0].push_back(i);
	this->rows = 1;
	this->columns = data.size();
}

Matrix::Matrix(std::vector<float> data)
{
	matrix.push_back({});
	for (float i : data)
		matrix[0].push_back(i);
	this->rows = 1;
	this->columns = data.size();
}

Matrix::Matrix(const Matrix& A)
{
	this->matrix = A.GetMatrix();
	this->columns = A.columns;
	this->rows = A.rows;
}

Matrix Matrix::transposeMatrix()
{
	Matrix out = Matrix(this->columns, this->rows);

	for (int x = 0; x < out.rows; x++)
	{
		for (int y = 0; y < out.columns; y++)
		{
			out.matrix[x][y] = this->matrix[y][x]; 
		}
	}
	return out;
}

Matrix Matrix::operator+(const Matrix& A)
{
	if (this->columns == A.columns && this->rows == A.rows)
	{
		Matrix out = Matrix(this->rows, this->columns);

		for (int x = 0;x < out.rows;x++)
		{
			for (int y = 0; y < out.columns;y++)
			{
				out.matrix[x][y] = this->matrix[x][y] + A.matrix[x][y];
			}
		}
		return out;
	}
	else
	{
		return Matrix();
	}
}

Matrix Matrix::operator+(float scalar)
{
	Matrix out = Matrix(this->rows, this->columns);
	
	for (int x = 0; x < out.rows; x++)
	{
		for (int y = 0; y < out.columns; y++)
		{
			out.matrix[x][y] = this->matrix[x][y] + scalar;
		}
	}
	return out;
}

Matrix Matrix::operator*(const Matrix& A)
{
	if (this->columns == A.rows)
	{
		Matrix out = Matrix(this->rows, this->columns);
		for (int x = 0; x < out.rows; x++)
		{
			for (int y = 0; y < out.columns; y++)
			{
				float sum = 0.f;

				//Compute sum
				for (int z = 0; z < this->columns; z++)
				{
					sum += this->matrix[x][z] * A.matrix[z][y];
				}

				//Output value
				out.matrix[x][y] = sum;
			}
		}
		return out;
	}
	else
		return Matrix();
}

Matrix Matrix::operator*(float scalar)
{
	Matrix out = Matrix(this->rows, this->columns);

	for (int x = 0; x < out.rows; x++)
	{
		for (int y = 0; y < out.columns; y++)
		{
			out.matrix[x][y] = this->matrix[x][y] * scalar;
		}
	}
	return out;
}

Matrix Matrix::hadamard(const Matrix& A)
{
	if (this->columns == A.columns && this->rows == A.rows)
	{
		Matrix out = Matrix(this->rows, this->columns);

		for (int x = 0; x < out.rows; x++)
		{
			for (int y = 0; y < out.columns; y++)
			{
				out.matrix[x][y] = this->matrix[x][y] * A.matrix[x][y];
			}
		}
		return out;
	}
	else
		return Matrix();
}

Matrix Matrix::kronecker(const Matrix& A)
{
	Matrix out = Matrix(this->columns, this->rows);

	for (int x = 0; x < out.rows; x++)
	{
		for (int y = 0; y < out.columns; y++)
		{
			out.matrix[x][y] = this->matrix[0][x] * A.matrix[y][0];
		}
	}
	return out;
}

Matrix Matrix::horizontalConcatenation(const Matrix& A)
{
	if (this->rows == A.rows)
	{
		Matrix out = *this;
		out.columns = out.columns + A.columns;

		for (int x = 0; x < A.rows; x++)
		{
			for (int y = 0; y < A.columns; y++)
			{
				out.matrix[x].push_back(A.matrix[x][y]);
			}
		}
		return out;
	}
	else
		return Matrix();
}

int Matrix::ConvertToClassNumber()
{
	if (matrix.size() == 1)
	{
		for (int i = 0; i < matrix[0].size(); i++)
		{
			if (matrix[0][i] != 0.f)
				return i;
		}
	}
	return -1;
}

int Matrix::AppendFromString(std::string line, int count, std::string pattern)
{
	if (line.empty() == false)
	{
		// - regex (\d+\.\d+|\d+) - wykrywa liczby
		std::regex rgx(pattern);
		std::smatch matches;
		int currentCount = 0;
		std::vector<float> classNumber;

		//Add row for new data
		this->matrix.push_back({});

		while (std::regex_search(line, matches, rgx))
		{
			currentCount++;
			if (currentCount <= count)
			{
				//Push to added row
				this->matrix.back().push_back(std::stof(matches[0]));
			}
			else
			{
				//Add class number
				classNumber.push_back(std::stof(matches[0]));
			}

			line = matches.suffix();
		}

		//Convert to class number
		Matrix c(classNumber);
		int result = c.ConvertToClassNumber();
		return result;
	}
	else
	{
		return -1;
	}	
}

std::ostream& operator<<(std::ostream& out, const Matrix& A)
{
	for (const std::vector<float>& r : A.GetMatrix())
	{
		out << "| ";
		for (const float& v : r)
		{
			out << v << " ";
		}
		out << "|" << std::endl;
	}
	return out;
}