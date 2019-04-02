#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <stdio.h>
#include <ctype.h>
#include "WordSearch.h"
using namespace std;


int main() {
	string fileName = "input.txt"; //Here insert fileName

	if (runAllTests(fileName)) {
		search(fileName);
	}
	else {
		return 0;
	}

	
}

