#include "GlobalTools.h"
#include <string>

Matrix GlobalTools::LoadDataFromFile(std::string fileName,Matrix& classNumber)
{
	std::vector<std::string> loadedData;
	std::string lineOfFile;
	std::ifstream inFile;
	inFile.open(fileName);
	Matrix m;

	while (!inFile.eof())
	{
		std::getline(inFile,lineOfFile);
		classNumber.AppendRow({(float)m.AppendFromString(lineOfFile, 4, "(\\d+\\.\\d+|\\d+)") });
	}
	inFile.close();
	return m;
}

void GlobalTools::InitDataSet(F_DataSet& fd,std::string trainingFile, std::string validationFile, std::string testFile, Matrix& training_set, Matrix& validation_set, Matrix& test_set, Matrix& trainingClass, Matrix& validationClass, Matrix& testClass)
{
	for (int x : {1,2,3})
	{
		switch (x)
		{
		case 1: 
			training_set = LoadDataFromFile(trainingFile, trainingClass); 
			fd.training_set.classes = trainingClass;
			fd.training_set.inputs = training_set;
			fd.training_set.count = training_set.GetRowsNum();
			break;
		case 2: validation_set = LoadDataFromFile(validationFile, validationClass); 
			fd.validation_set.classes = validationClass;
			fd.validation_set.inputs = validation_set;
			fd.validation_set.count = validation_set.GetRowsNum();
			break;
		case 3: test_set = LoadDataFromFile(testFile, testClass); 
			fd.test_set.classes = testClass;
			fd.test_set.inputs = test_set;
			fd.test_set.count = test_set.GetRowsNum();
			break;
		}
	}
	fd.input_count = training_set.GetRowsNum();
	fd.output_count = training_set.GetRowsNum();
}
