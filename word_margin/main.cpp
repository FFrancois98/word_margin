/*
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	ifstream inFile;
	ofstream outFile;
	char ch;
	int leftMargin = 0;
	int rightMargin = 0;
	int x = 0;
	int charsPerLine = 100;
	int lineCount = 0;
	int orgCharsPerLine;
	string word = "";
	string befWord = "";
	string line = "";
	string fileName = "";
	bool endOfLine = false;
	string margin = "";

	cout << "Enter input file path including file extension \n\n";
	cin >> fileName;

	inFile.open(fileName);
	outFile.open("DAT1.TXT");

	if (!inFile) {

		cout << "Can't open file. \n";
		return 0;
	}//if

	inFile >> leftMargin;
	inFile >> rightMargin;

	for (int i = 0; i < leftMargin; i++) {
		margin += " ";
	}//for

	charsPerLine = 100 - leftMargin - rightMargin;
	orgCharsPerLine = charsPerLine;

	while ((ch = inFile.get()) != EOF) {

		//skip first two lines of file
		if (x<1) {
			x++;
			continue;
		}//if

		 //step 1. Build word
		word += ch;
		charsPerLine--;

		if (ch == '.') {//add extra space between sentences
			word += ' ';
			charsPerLine--;
		}

		if (ch != ' ' && ch != '\n') continue;

		//step 2. Build line

		//case 1. Add word to line so long as there isn't a line break and limit hasn't been reached
		if (ch != '\n' && charsPerLine >= 0) {

			line += word;
			lineCount = line.length();
			befWord = word;
			word = "";
			continue; //keep adding to line
		}

		//case 2. New line has been reached before char limit per line is reached
		else if (ch == '\n' && charsPerLine >= 0) {
			line += word + '\n';
			lineCount = line.length();
			befWord = word;
			word = "";
		}
		//case 3. Number of chars per line was exceeded
		else if (charsPerLine < 0) {

			
			line += '\n';

			line = margin + line;//add left margin
			//cout << "Inserting " << ": " << line << "\n";
			outFile << line;
			line = "";


			line = line + word;
			befWord = word;
			word = "";

			//reset for next line

			charsPerLine = (100 - leftMargin - rightMargin) + charsPerLine;
			
			continue;
		}

		line = margin + line;//add left margin
		//cout << "Inserting " << ": " << line << "\n";
		outFile << line;

		//reset for next line
		line = "";
		lineCount = line.length();
		charsPerLine = 100 - leftMargin - rightMargin;
		

	}//while

	inFile.close();
	outFile.close();

	system("pause");
	return 0;
}
*/
