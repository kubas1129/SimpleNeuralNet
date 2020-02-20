#pragma once
#include<vector>
#include<iostream>

class Matrix
{
private:

	std::vector<std::vector<float>> matrix;
	int rows, columns;



public:

	/* Consturctors */

	//Create null matrix
	Matrix();

	//Create zeros matrix
	Matrix(int rows, int columns);

	//Create matrix of passed data
	Matrix(std::vector<std::vector<float>> data);

	//Create normal vector matrix
	Matrix(std::initializer_list<float> data);

	Matrix(std::vector<float> data);

	//Copy constructor
	Matrix(const Matrix& A);

	/* Methods */

	//Transpose matrix
	Matrix transposeMatrix();

	//Operator +
	Matrix operator+(const Matrix& A);
	Matrix operator+(float scalar);

	//Operator *
	Matrix operator*(const Matrix& A);
	Matrix operator*(float scalar);

	//Hadamard multiplication
	Matrix hadamard(const Matrix& A);

	//Kronecker mutliplication
	Matrix kronecker(const Matrix& A);

	//Horizontal concatenation
	Matrix horizontalConcatenation(const Matrix& A);

	//Operator <<
	friend std::ostream& operator<<(std::ostream& out, const Matrix& A);

	//Conversion
	int ConvertToClassNumber();

	//Add row from line of file
	int AppendFromString(std::string line, int count, std::string pattern);

	//Append row
	void AppendRow(std::vector<float> rowData) { matrix.push_back(rowData); }

	//Append to last row
	void AppendOnBack(float data) { matrix.back().push_back(data); }

	/* Getters/Setters */
	std::vector<std::vector<float>> GetMatrix() const { return matrix; }
	int GetRowsNum() { return rows; }
	int GetColumnsNum() { return columns; }

};
