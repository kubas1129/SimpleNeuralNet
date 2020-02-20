#pragma once
#include <vector>
#include <ostream>
#include "Matrix.h"

struct F_Data
{
	Matrix inputs;
	Matrix outputs;
	Matrix classes;
	int count;
	float bias;
};

struct F_DataSet
{
	int input_count;
	int output_count;
	F_Data training_set;
	F_Data validation_set;
	F_Data test_set;
};

inline std::ostream& operator<<(std::ostream& out, const F_DataSet& fd)
{
	out << "Input count: " << fd.input_count << std::endl;
	out << "Output count: " << fd.output_count << std::endl;
	out << "Training Set: " << std::endl << fd.training_set.inputs << fd.training_set.classes << std::endl;
	out << "Validation Set: " << std::endl << fd.validation_set.inputs << fd.validation_set.classes << std::endl;
	out << "Test Set: " << std::endl << fd.test_set.inputs << fd.test_set.classes << std::endl;
	return out;
}