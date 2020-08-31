#include <string>
#include <iostream>

using namespace std;

string test_demo_string(string inputString)
{
	cout << "input string is: \n"
		 << inputString << endl;
	string result;
	result = inputString.append("----> hello world...");
	return result;
}

double test_demo_int(double inputNum)
{
	cout << "input string is: \n"
		 << inputNum << endl;
	double result;
	result = inputNum + 100;
	return result;
}

int main()
{
	string safe = "safe here";
	cout << test_demo_string(safe) << endl;
	return 0;
};
