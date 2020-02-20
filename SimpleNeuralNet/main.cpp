#pragma once
#include <iostream>
#include "Matrix.h"
#include "GlobalTools.h"
#include "GlobalStructs.h"

int main()
{
	std::string testFileName{ "../Data/iris_test.dat" };
	std::string trainingFileName{ "../Data/iris_training.dat" };
	std::string validationFileName{ "../Data/iris_validation.dat" };

	Matrix trainingMatrix, validationMatrix, testMatrix;
	Matrix trainingClass, validationClass, testClass;

	F_DataSet data_set;
	GlobalTools::InitDataSet(data_set, trainingFileName, validationFileName, testFileName, trainingMatrix, validationMatrix, testMatrix, trainingClass, validationClass, testClass);

	std::cout << data_set << std::endl;

	return 0;
}