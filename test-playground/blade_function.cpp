#include "blade.h"

std::string blade_function_parent(std::string imageParent)
{
	Blade blade;
	std::string result;
	result = blade.run_parent(imageParent);
	return result;
}

std::string blade_function_filestr(std::string imageFilesStr)
{
	Blade blade;
	std::string result;
	result = blade.run_filestr(imageFilesStr);
	return result;
}

std::string test_demo_string(std::string inputString)
{
	std::cout << "input string is: \n" << inputString << std::endl;
	std::string result;
	result = inputString.append("----> hello world...");
	return result;
}


double test_demo_int(double inputNum)
{
	std::cout << "input string is: \n" << inputNum << std::endl;
	double result;
	result = inputNum + 100;
	return result;
}
