#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/stat.h>
using namespace std;

int testOne(const std::string& fileName) {
	/*
	Test Number 1:
		Does the input data file exist?

	return 0 if false
	return 1 if true
	*/
	struct stat buffer;
	return (stat(fileName.c_str(), &buffer) == 0);

}
int testTwo(const std::string& fileName) {
	/*
	Test Number 2:
		Can the input data file be opened?

	return 0 if false
	return 1 if true
	*/
	fstream fileStream;
	fileStream.open(fileName);
	if (fileStream.fail()) {

		//file doesn't exist
		return 0;
	}
	else {

		//file does exist
		return 1;
	}


}

int main() {
	string fileName = "input.txt";
	std::cout << testOne(fileName) << std::endl;
	std::cout << testTwo(fileName) << std::endl;
}
