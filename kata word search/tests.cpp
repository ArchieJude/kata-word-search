#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sys/stat.h>
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
		if (line.length() > 0) { // way to overcome newlines
			int indexS = 0; //index start
			int indexE = 0; //index end
			// above variables will be used to split the line:
			// line.substr(indexB:indexE)
			// Or... I can use strtok http://www.cplusplus.com/reference/cstring/strtok/
		std:string s;
			int index = 0;
			for (char c : line) {
				//std::cout << c << std::endl;
				if (isalpha(c)) {
					s.push_back(c);
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

			for (auto item : wordList) {
				std::cout << item << std::endl;

			}

			return 1;
		}
	}
	return 0;
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
		std:string s;
			int index = 0;
			for (char c : line) {
				//std::cout << c << std::endl;
				if (isalpha(c)) {
					s.push_back(c);
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

int testSeven(const std::string& fileName) {
	/*
	Test Number 7:
		Iterate through the "grid"... it's actually just iterating through one dimensional string.
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

int testEight(const std::string& fileName) {
	/*
	Test Number 8:
		Produce a grid or 2 dimensional matrix that contains all the characters to be searched through
	*/
	std::vector< std::vector<char> > charGrid;
	fstream fileStream;
	fileStream.open(fileName);
	float lineCount = 0;
	float avgCharCount = 0;
	int y = 0;
	for (std::string line; std::getline(fileStream, line);) {
		if (line.size() > 0) { // way to overcome newlines
			if (lineCount >= 1) { //exclude the first line because it contains the words to be searched
				std::vector<char> temp;
				for (char c : line) {

					if (isalpha(c)) {
						temp.push_back(c);
					}
				}
				charGrid.push_back(temp);
			}
			lineCount++;
		}
	}
	for (int y = 0; y < charGrid.size(); y++) {
		for (int x = 0; x < charGrid[y].size(); x++) {
			std::cout << charGrid[y][x];
		}
		std::cout << endl;
	}
	return 0;

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
						temp.push_back(c);
					}
				}
				charGrid.push_back(temp);
			}
			lineCount++;
		}
	}
	return charGrid;
}



int testNine(const std::string& fileName) {
	/*
	Test Number 9:
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


	return 0;
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



int testTen(const std::string& fileName) {
	/*
	Test Number 10:
		Search horizontally for "SCOTTY"
	*/

	std::map<char, std::vector<vector<int>>> charDic = getCharDic(fileName);
	std::vector< vector<char> > charGrid = getCharGrid(fileName);

	vector<string> wordList = getWordList(fileName);

	for (int i = 0; i < charDic[wordList[3][0]].size(); i++) {

		int posY = charDic[wordList[3][0]][i][0];
		int posX = charDic[wordList[3][0]][i][1];

		//std::cout<< charDic['B'][i][0] << charDic['B'][i][1] << std::endl;

		if ((posX + 1) - int(wordList[3].length()) > 0) { //search left
			std::string s = "";
			for (int x = 0; x < wordList[3].length(); x++) {
				s.push_back(charGrid[posY][posX - x]);
				//std::cout << charGrid[posY][posX-x] << std::endl;
				//std::cout << posX<< std::endl;
				//std::cout << (posX + 1) - int(wordList[0].length()) << std::endl;
			}
			if (s == wordList[3]) {
				std::cout << "Found Scotty" << std::endl;
				return 1;
			}
			std::cout << s << std::endl;
		}

		if ((posX + 1) + int(wordList[3].length()) <= charGrid.size()) { //search right

			std::string s = "";
			for (int x = 0; x < wordList[3].length(); x++) {
				s.push_back(charGrid[posY][posX + x]);
				//std::cout << charGrid[posY][posX + x] << std::endl;
				//std::cout << posX<< std::endl;
				//std::cout << (posX + 1) - int(wordList[0].length()) << std::endl;
			}

			if (s == wordList[3]) {
				std::cout << "Found Scotty" << std::endl;
				return 1;
			}
			std::cout << s << std::endl;
		}

	}
	return 0;
}
int testEleven(const std::string& fileName) {
	/*
	Test Number 11:
		Search horizontally for every word and then print out found word's coordinates
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

			//std::cout<< charDic['B'][i][0] << charDic['B'][i][1] << std::endl;

			if ((posX + 1) - int(word.length()) > 0) { //search left
				std::string s = "";
				std::vector< vector<int> > positionCoord; //[[x,y],[x1,y1],[x2,y2]...]

				for (int x = 0; x < word.length(); x++) {
					std::vector<int> temp;
					temp.push_back(posX - x);
					temp.push_back(posY);

					s.push_back(charGrid[posY][posX - x]);
					positionCoord.push_back(temp);

					//std::cout << charGrid[posY][posX-x] << std::endl;
					//std::cout << posX<< std::endl;
					//std::cout << (posX + 1) - int(wordList[0].length()) << std::endl;
				}
				if (s == word) {
					wordPositionDic[word] = positionCoord;
				}

			}


			if ((posX + 1) + int(word.length()) <= charGrid.size()) { //search right

				std::string s = "";
				std::vector< vector<int> > positionCoord; //[[x,y],[x1,y1],[x2,y2]...]
				for (int x = 0; x < word.length(); x++) {
					std::vector<int> temp;
					temp.push_back(posX + x);
					temp.push_back(posY);

					s.push_back(charGrid[posY][posX + x]);
					positionCoord.push_back(temp);
					//std::cout << charGrid[posY][posX + x] << std::endl;
					//std::cout << posX<< std::endl;
					//std::cout << (posX + 1) - int(wordList[0].length()) << std::endl;
				}

				if (s == word) {
					wordPositionDic[word] = positionCoord;
				}

			}
		}
	}

	for (auto const& item : wordPositionDic)
	{

		std::cout << "Found: " << item.first << std::endl; //accesing key


		std::cout << "Positions:" << std::endl;

		for (auto pos : item.second) {
			std::cout << " (" << pos[0] << "," << pos[1] << ")";
		}

		std::cout << "\n" << endl;

	}

	if (wordPositionDic.size() > 0) {
		return 1;
	}
	return 0;
}
int testTwelve(const std::string& fileName) {
	/*
		Test Number Eleven:
			Search vertically and print out results.
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

			//std::cout<< charDic['B'][i][0] << charDic['B'][i][1] << std::endl;

			if ((posY + 1) - int(word.length()) > 0) { //search 'up'
				std::string s = "";
				std::vector< vector<int> > positionCoord; //[[x,y],[x1,y1],[x2,y2]...]

				for (int y = 0; y < word.length(); y++) {
					std::vector<int> temp;

					temp.push_back(posX);
					temp.push_back(posY - y);

					s.push_back(charGrid[posY - y][posX]);
					positionCoord.push_back(temp);

					//std::cout << charGrid[posY][posX-x] << std::endl;
					//std::cout << posX<< std::endl;
					//std::cout << (posX + 1) - int(wordList[0].length()) << std::endl;
				}
				if (s == word) {
					wordPositionDic[word] = positionCoord;
				}

			}

			if ((posY + 1) + int(word.length()) <= charGrid.size()) { //search down

				std::string s = "";
				std::vector< vector<int> > positionCoord; //[[x,y],[x1,y1],[x2,y2]...]
				for (int y = 0; y < word.length(); y++) {
					std::vector<int> temp;

					temp.push_back(posX);
					temp.push_back(posY + y);

					s.push_back(charGrid[posY + y][posX]);
					positionCoord.push_back(temp);
					//std::cout << charGrid[posY][posX + x] << std::endl;
					//std::cout << posX<< std::endl;
					//std::cout << (posX + 1) - int(wordList[0].length()) << std::endl;
				}

				if (s == word) {
					wordPositionDic[word] = positionCoord;
				}

			}
		}
	}

	for (auto const& item : wordPositionDic)
	{

		std::cout << "Found: " << item.first << std::endl; //accesing key


		std::cout << "Positions:" << std::endl;

		for (auto pos : item.second) {
			std::cout << " (" << pos[0] << "," << pos[1] << ")";
		}

		std::cout << "\n" << endl;

	}

	if (wordPositionDic.size() > 0) {
		return 1;
	}
	return 0;

}
int testThirteen(const std::string& fileName) {
	/*
	Test Number 13:
		Search diagonally and then print out the results
	*/

	/*
	Did some quick analysis and discovered that certain conditions has to be met to search diagonally:
		* ~ means the direction of the arrow
		up-left: can only occur if there is 'space' in up and left directions
		~
			X
				X
					X
		up-right: if up AND right

					~
				X
			X
		X
		down-left: if down AND left
					X
				X
			X
		~
		down-right: if down AND right
		X
			X
				X
					~
	Up:
		if ((posY + 1) - int(word.length()) > 0)
	Down:
		if ((posY + 1) + int(word.length()) <= charGrid.size())
	Left:
		if ((posX + 1) - int(word.length()) > 0) { //search left
	Right
		if ((posX + 1) + int(word.length()) <= charGrid.size()) { //search right

	int up = (posY + 1) - int(word.length());
	int down =  (posY + 1) + int(word.length());
	int left = (posX + 1) - int(word.length());
	int right = (posX + 1) + int(word.length());
	Up-Left:
		if (up >= 0 and left >= 0))  //search left
	Up-Right:
		if (up >= 0 and right <= charGrid.size())
	Down-Left:
		if (down <= charGrid.size() and left >= 0) { //search left
	Down-Right:
		if (down <= charGrid.size() and right <= charGrid.size()) { //search right
	*/

	std::map<char, std::vector<vector<int>>> charDic = getCharDic(fileName);
	std::vector< vector<char> > charGrid = getCharGrid(fileName);
	vector<string> wordList = getWordList(fileName);

	std::map<std::string, std::vector<vector<int>>> wordPositionDic; // {"kirk":[[x1,y1],[x2,y2],[x3,y3]..]}
	/*
	for (auto word : wordList) {
		std::cout << word << std::endl;
	}
	std::cout << "finished showing words to be searched" << std::endl;
	*/
	for (auto word : wordList) {
		char c = word[0];
		for (int i = 0; i < charDic[c].size(); i++) {



			int posY = charDic[c][i][0];
			int posX = charDic[c][i][1];

			int up = (posY + 1) - int(word.length());
			int down = (posY + 1) + int(word.length());

			int left = (posX + 1) - int(word.length());
			int right = (posX + 1) + int(word.length());


			//search 'up' and "left' diagonally
			if (up >= 0 and left >= 0) {
				std::string s = "";
				std::vector< vector<int> > positionCoord; //[[x,y],[x1,y1],[x2,y2]...]

				for (int k = 0; k < word.length(); k++) {
					std::vector<int> temp;

					temp.push_back(posX - k);
					temp.push_back(posY - k);

					s.push_back(charGrid[posY - k][posX - k]);
					positionCoord.push_back(temp);
					/* std::cout << charGrid[posY - k][posX - k] << std::endl;
					std::cout << posX - k << std::endl;
					std::cout << posY - k << std::endl; */

				}
				//std::cout<<s<<std::endl;
				if (s == word) {
					wordPositionDic[word] = positionCoord;
				}

			}

			//search 'up' and "right' diagonally
			if (up > 0 and right <= charGrid.size()) { //search right

				std::string s = "";
				std::vector< vector<int> > positionCoord; //[[x,y],[x1,y1],[x2,y2]...]
				for (int k = 0; k < word.length(); k++) {
					std::vector<int> temp;

					temp.push_back(posX + k);
					temp.push_back(posY - k);

					s.push_back(charGrid[posY - k][posX + k]);
					positionCoord.push_back(temp);
					/*					std::cout << charGrid[posY - k][posX + k] << std::endl;
					std::cout << posX + k << std::endl;
					std::cout << posY - k << std::endl;*/

				}
				//std::cout << s << std::endl;
				if (s == word) {
					wordPositionDic[word] = positionCoord;
				}

			}

			//search 'down' and 'left' diagonally
			if (down <= charGrid.size() and left >= 0) {
				std::string s = "";
				std::vector< vector<int> > positionCoord; //[[x,y],[x1,y1],[x2,y2]...]

				for (int k = 0; k < word.length(); k++) {
					std::vector<int> temp;
					int x = posX - k;
					int y = posY + k;
					temp.push_back(x);
					temp.push_back(y);

					s.push_back(charGrid[y][x]);
					positionCoord.push_back(temp);
					/* std::cout << charGrid[posY - k][posX - k] << std::endl;
					std::cout << posX - k << std::endl;
					std::cout << posY - k << std::endl; */

				}
				//std::cout<<s<<std::endl;
				if (s == word) {
					wordPositionDic[word] = positionCoord;
				}

			}

			//search 'down' and 'right' diagonally
			if (down <= charGrid.size() and right <= charGrid.size()) {
				std::string s = "";
				std::vector< vector<int> > positionCoord; //[[x,y],[x1,y1],[x2,y2]...]

				for (int k = 0; k < word.length(); k++) {
					std::vector<int> temp;
					int x = posX + k;
					int y = posY + k;
					temp.push_back(x);
					temp.push_back(y);

					s.push_back(charGrid[y][x]);
					positionCoord.push_back(temp);
					/* std::cout << charGrid[posY - k][posX - k] << std::endl;
					std::cout << posX - k << std::endl;
					std::cout << posY - k << std::endl; */

				}
				//std::cout<<s<<std::endl;
				if (s == word) {
					wordPositionDic[word] = positionCoord;
				}

			}
		}
	}

	for (auto const& item : wordPositionDic)
	{

		std::cout << "Found: " << item.first << std::endl; //accesing key


		std::cout << "Positions:" << std::endl;

		for (auto pos : item.second) {
			std::cout << " (" << pos[0] << "," << pos[1] << ")";
		}

		std::cout << "\n" << endl;

	}

	if (wordPositionDic.size() > 0) {
		return 1;
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
	std::cout << testEight(fileName) << std::endl;
	std::cout << testNine(fileName) << std::endl;
	std::cout << testTen(fileName) << std::endl;
	std::cout << testEleven(fileName) << std::endl;
	std::cout << testTwelve(fileName) << std::endl;
	std::cout << testThirteen(fileName) << std::endl;

	*/


	std::cout << testEight(fileName) << std::endl;
}