#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>
#include <ctype.h>
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

int fileRead(const std::string& fileName) {
	/*
	Test Number 3:
		Can it read the data file?
	*/

	if (fileExist(fileName) == 1 && fileOpen(fileName) == 1) {
		fstream fileStream;
		fileStream.open(fileName);

		return 1;
	}

	else {
		return 0;
	}
}


int fileEmpty(const std::string& fileName) {
	/*
	Test Number 4:
		Check if the file is empty or not.
	*/

	fstream fileStream;
	fileStream.open(fileName);
	int lineCount = 0;

	for (std::string line; std::getline(fileStream, line);) {
		if (line.length() > 0) { // way to overcome newlines
			lineCount = lineCount + 1;
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

int rowCol(const std::string& fileName) {
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
	//t::cout << lineCount << t::endl;
	//t::cout << avgCharCount << t::endl;
	if (lineCount == avgCharCount) {
		return 1;
	}
	else {
		return 0;
	}

}

vector<string>  getWordList(const std::string& fileName) {
	/*
	findWordList:
		returns the a list that contains the words to be searched.
	*/
	fstream fileStream;
	fileStream.open(fileName);
	vector<string> wordList; //this will hold words to be looked for.
	for (std::string line; std::getline(fileStream, line);) {
		/*
		std::cout << line<<" ";
		std::cout << line.size() << std::endl;
		*/
		if (line.length() > 0) { // way to overcome newlines
			int indexS = 0; //index start
			int indexE = 0; //index end
			// above variables will be used to split the line:
			// line.substr(indexB:indexE)
			// Or... I can use strtok http://www.cplusplus.com/reference/cstring/strtok/
			std::string s;
			int index = 0;
			for (char c : line) {
				//std::cout << c << std::endl;
				if (isalpha(c)) {
					s.push_back(toupper(c));
				}
				else if (isalpha(c) == false) {
					//std::cout << s << std::endl;
					wordList.push_back(s);
					s = "";

				}
				if (index == line.length() - 1) {
					wordList.push_back(s);
					s = "";
				}
				index++;
			}
		}
		if (wordList.size() != 0) { // this line stops the loop from continuing when the search words are extracted.
			return wordList;
		}
	}
	return wordList;



}

vector< vector<char> > getCharGrid(const std::string& fileName) {
	std::vector< vector<char> > charGrid;
	fstream fileStream;
	fileStream.open(fileName);
	float lineCount = 0;
	float avgCharCount = 0;
	int y = 0;
	for (std::string line; std::getline(fileStream, line);) {
		if (line.size() > 0) { // way to overcome newlines
			if (lineCount >= 1) { //exclude the first line because it contains the words to be searched
				vector<char> temp;
				for (char c : line) {

					if (isalpha(c)) {
						temp.push_back(char(toupper(c)));
					}
				}
				charGrid.push_back(temp);
			}
			lineCount++;
		}
	}
	return charGrid;
}

std::map<char, std::vector<vector<int>>> getCharDic(const std::string& fileName) {
	/*
	Produce a dictionary => Key: char, Value: [[y,x],][y1,x1],[etc]]
	I am using dictionary because it would be runtime cost affective around nlog(n)
	ex:
		testDic['a'] => [[1,1],[2,3],[etc]]
	*case senstive 'a' != 'A'
	*/

	std::map<char, std::vector<vector<int>>> testDic;
	std::vector< vector<char> > charGrid = getCharGrid(fileName);

	for (int y = 0; y < charGrid.size(); y++) {
		for (int x = 0; x < charGrid[y].size(); x++) {

			std::vector<int> temp;
			temp.push_back(y);
			temp.push_back(x);

			testDic[charGrid[y][x]].push_back(temp);
		}
	}

	/*this iterator below prints out the given key's contents
		for (int y = 0; y < testDic['A'].size(); y++) {
		for (int x = 0; x < testDic['A'][y].size(); x++) {
			std::cout << testDic['A'][y][x]<<' ';
		}
		std::cout << endl;
	}
	*/


	return testDic;
}

template<typename T>
void printWordPositionDic(T wordPositionDic) {
	ofstream solutionFile;
	solutionFile.open("solution.txt");

	for (auto const& item : wordPositionDic)
	{

		std::cout << item.first <<":"; //accesing key
		solutionFile << item.first << ":"; 
		for (auto pos : item.second) {
			std::cout << " (" << pos[0] << "," << pos[1] << ")";
			solutionFile << " (" << pos[0] << "," << pos[1] << ")";
		}

		std::cout << "\n" << endl;
		solutionFile << "\n" << endl;

	}
	solutionFile.close();
}

int search(const std::string& fileName) {
	/*
	Implement all the search techniques.
	*/


	std::map<char, std::vector<vector<int>>> charDic = getCharDic(fileName);
	std::vector< vector<char> > charGrid = getCharGrid(fileName);
	vector<string> wordList = getWordList(fileName);

	std::map<std::string, std::vector<vector<int>>> wordPositionDic; // {"kirk":[[x1,y1],[x2,y2],[x3,y3]..]}

	for (auto word : wordList) {
		char c = word[0];
		for (int i = 0; i < charDic[c].size(); i++) {
			int posY = charDic[c][i][0];
			int posX = charDic[c][i][1];
			//search 'up' and "left' diagonally
			int up = 0;
			int down = 0;
			int left = 0;
			int right = 0;

			std::string sRight = "";
			std::string sLeft = "";

			std::string sUp = "";
			std::string sDown = "";

			std::string sUpRight = "";
			std::string sUpLeft = "";

			std::string sDownRight = "";
			std::string sDownLeft = "";



			std::vector< vector<int> > rightXY; //[[x,y],[x1,y1],[x2,y2]...]
			std::vector< vector<int> > leftXY; //[[x,y],[x1,y1],[x2,y2]...]

			std::vector< vector<int> > upXY; //[[x,y],[x1,y1],[x2,y2]...]
			std::vector< vector<int> > downXY; //[[x,y],[x1,y1],[x2,y2]...]

			std::vector< vector<int> > upRightXY; //[[x,y],[x1,y1],[x2,y2]...]
			std::vector< vector<int> > upLeftXY; //[[x,y],[x1,y1],[x2,y2]...]

			std::vector< vector<int> > downRightXY; //[[x,y],[x1,y1],[x2,y2]...]
			std::vector< vector<int> > downLeftXY; //[[x,y],[x1,y1],[x2,y2]...]

			for (int k = 0; k < word.length(); k++) {
				
				std::vector<int> tempRight;
				std::vector<int> tempLeft;

				std::vector<int> tempUp;
				std::vector<int> tempDown;
				
				std::vector<int> tempUpRight;
				std::vector<int> tempUpLeft;

				std::vector<int> tempDownRight;
				std::vector<int> tempDownLeft;

				up = posY - k;
				down = posY + k;
				right = posX + k;
				left = posX - k;
				//right

				if (right >= 0 and right < int(charGrid.size())) {

					tempRight.push_back(right);
					tempRight.push_back(posY);
					sRight.push_back(charGrid[posY][right]);
					rightXY.push_back(tempRight);

				}
				//left
				if (left >= 0 and left < charGrid.size()) {
					tempLeft.push_back(left);
					tempLeft.push_back(posY);
					sLeft.push_back(charGrid[posY][left]);
					leftXY.push_back(tempLeft);
				}
				//up
				if (up >= 0 and up < charGrid.size()) {
					tempUp.push_back(posX);
					tempUp.push_back(up);

					sUp.push_back(charGrid[up][posX]);
					upXY.push_back(tempUp);

					//std::cout << charGrid[posY][posX-x] << std::endl;
					//std::cout << posX<< std::endl;
					//std::cout << (posX + 1) - int(wordList[0].length()) << std::endl;
				}
				//down
				if (down >= 0 and down < charGrid.size()) {
					tempDown.push_back(posX);
					tempDown.push_back(down);

					sDown.push_back(charGrid[down][posX]);
					downXY.push_back(tempDown);
				}
				//up-right
				if (up >= 0 and up < charGrid.size() and right >= 0 and right < charGrid.size()) {
					tempUpRight.push_back(right);
					tempUpRight.push_back(up);

					sUpRight.push_back(charGrid[up][right]);
					upRightXY.push_back(tempUpRight);
				}
				//up-left
				if (up >= 0 and up < charGrid.size() and left >= 0 and left < charGrid.size()) {
					tempUpLeft.push_back(left);
					tempUpLeft.push_back(up);

					sUpLeft.push_back(charGrid[up][left]);
					upLeftXY.push_back(tempUpLeft);
				}
				
			
				//down-right diagonal
				if (down >= 0 and down < charGrid.size() and right >= 0 and right < charGrid.size()) {
					tempDownRight.push_back(right);
					tempDownRight.push_back(down);

					sDownRight.push_back(charGrid[down][right]);
					downRightXY.push_back(tempDownRight);
				}

				
				//down-left diagonal
				if (down >= 0 and down < charGrid.size() and left >= 0 and left < charGrid.size()) {
					tempDownLeft.push_back(left);
					tempDownLeft.push_back(down);

					sDownLeft.push_back(charGrid[down][left]);
					downLeftXY.push_back(tempDownLeft);
				}
			}
			if (sRight == word) {
				wordPositionDic[word] = rightXY;
			}
			if (sLeft == word) {
				wordPositionDic[word] = leftXY;
			}

			if (sUp== word) {
				wordPositionDic[word] = upXY;
			}
			if (sDown == word) {
				wordPositionDic[word] = downXY;
			}
			if (sUpRight == word) {
				wordPositionDic[word] = upRightXY;
			}
			if (sUpLeft == word) {
				wordPositionDic[word] = upLeftXY;
			}
			if (sDownRight == word) {
				wordPositionDic[word] = downRightXY;
			}
			if (sDownLeft == word) {
				wordPositionDic[word] = downLeftXY;
			}
		}
	}
	if (wordPositionDic.size() > 0) {
		printWordPositionDic(wordPositionDic);
		return 1;
	}
	return 0;

}


int runAllTests(const std::string& fileName) {

	if (fileExist(fileName)) {
		if (fileOpen(fileName)) {
			if (fileEmpty(fileName)) {
				if (fileRead(fileName)) {
					if (rowCol(fileName)) {
						return 1;
					}
					else {
						std::cout << "ROW AND COL DOESN'T MATCH" << std::endl;
					}
				}
				else {
					std::cout << "CAN'T READ FILE" << std::endl;
				}
			}
			else {
				std::cout << "FILE EMPTY" << std::endl;
			}
		}
		else {
			std::cout << "CAN'T OPEN FILE" << std::endl;
		}
	}
	else {
		std::cout << "FILE DOESN'T EXIST" << std::endl;
	}

	return 0;
}