#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include <ostream>
#include "Matrix.h"
#include "GlobalStructs.h"

class GlobalTools
{
public:
	
	static Matrix LoadDataFromFile(std::string fileName, Matrix& classNumber);

	static void InitDataSet(F_DataSet& fd, std::string trainingFile, std::string validationFile, std::string testFile, Matrix& training_set, Matrix& validation_set, Matrix& test_set, Matrix& trainingClass, Matrix& validationClass, Matrix& testClass);

};

