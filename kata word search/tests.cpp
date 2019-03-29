#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/stat.h>
using namespace std;

int fileExist(const std::string& fileName) {
	/*
	Test Number 1:
		Does the input data file exist?

	return 0 if false
	return 1 if true
	*/
	struct stat buffer;
	return (stat(fileName.c_str(), &buffer) == 0);

}
int fileOpen(const std::string& fileName) {
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

int testThree(const std::string& fileName) {
	/*
	Test Number 3:
		Can it read the data file?

	*/

	if (fileExist(fileName) == 1 && fileOpen(fileName) == 1) {
		fstream fileStream;
		fileStream.open(fileName);


		for (std::string line; std::getline(fileStream, line);) {
			std::cout << line << std::endl;
		}

		return 1;
	}

	else {
		return 0;
	}
}


int testFour(const std::string& fileName) {
	/*
	Test Number 4:
		Check if the file is empty or not.
	*/

	fstream fileStream;
	fileStream.open(fileName);
	int lineCount = 0;

	for (std::string line; std::getline(fileStream, line);) {
		if (line.size() > 0) { // way to overcome newlines
			lineCount++;
		}
	}

	if (lineCount == 0) {
		//file is empty
		return 0;
	}
	else {
		return 1;
	}

}

int testFive(const std::string& fileName) {
	/*
	Test Number 5:
		Check if number of rows match the number of characters in a line.
	*/

	fstream fileStream;
	fileStream.open(fileName);
	float lineCount = 0;
	float avgCharCount = 0;
	for (std::string line; std::getline(fileStream, line);) {
		if (line.size() > 0) { // way to overcome newlines
			
			
			if (lineCount >= 1) { //exclude the first line because it contains the words to be searched

				float charCount = 0;
				for (char c : line) {
					if (c != ',') {
						
						charCount++;
					}
				}
				avgCharCount = avgCharCount + charCount;
			}

			lineCount++;
	
		}
	}

	//decrement from lineCount because the line that contains the words to be searched does not count

	lineCount--;
	avgCharCount = avgCharCount / lineCount;
	//check if the equivalency of lineCount and number of characters in a line 
	//std::cout << lineCount << std::endl;
	//std::cout << avgCharCount << std::endl;
	if (lineCount == avgCharCount) {
		return 1;
	}
	else {
		return 0;
	}
	
}

int testSix(const std::string& fileName) {
	/*
	Test Number 6:
		Individually parse out the words in the first line and save it in a list.
	*/
	fstream fileStream;
	fileStream.open(fileName);
	vector<string> wordList; //this will hold words to be looked for.

	for (std::string line; std::getline(fileStream, line);) {
		/*
		std::cout << line<<" ";
		std::cout << line.size() << std::endl;
		*/
		if (line.size() > 0) { // way to overcome newlines
			int indexS = 0; //index start
			int indexE = 0; //index end
			// above variables will be used to split the line:
			// line.substr(indexB:indexE)
			// Or... I can use strtok http://www.cplusplus.com/reference/cstring/strtok/

			for (char c : line) {
				//std::cout << c << std::endl;

				if (c == ',') {
					//std::cout << line.substr(indexS, indexE-indexS) << std::endl;
					//std::cout << line.substr(indexS, indexE) << std::endl;
					wordList.push_back(line.substr(indexS, indexE - indexS));
					indexS = indexE + 1;
				}

				indexE++;

			}

		}

		if (wordList.size() != 0) { // this line stops the loop from continuing when the search words are extracted.

			for (auto item : wordList) {
				std::cout << item << std::endl;

			}

			return 1;
		}
	}

	return 0;

}

int testSeven(const std::string& fileName) {
	/*
	Test Number 7:
		Iterate through the grid

		abc
		def   => a,b,c,d,e,f,j,k,l
		jkl

	*/

	fstream fileStream;
	fileStream.open(fileName);
	float lineCount = 0;
	float avgCharCount = 0;
	for (std::string line; std::getline(fileStream, line);) {
		if (line.size() > 0) { // way to overcome newlines
			if (lineCount >= 1) { //exclude the first line because it contains the words to be searched
				for (char c : line) {
					if (c != ',') {
						std::cout << c << std::endl;
					}
				}
			}
			lineCount++;
		}
	}
	return 0;
}
int main() {
	string fileName = "input.txt";
	/*
	std::cout << fileExist(fileName) << std::endl;
	std::cout << fileOpen(fileName) << std::endl;
	std::cout << testThree(fileName) << std::endl;
	std::cout << testFour(fileName) << std::endl;
	std::cout << testFive(fileName) << std::endl;
	std::cout << testSix(fileName) << std::endl;
	std::cout << testSeven(fileName) << std::endl;
	*/
	
	
	
}
