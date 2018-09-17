#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// NOTES FOR THE PROGRAM
/*
	Fleurevca Francois, Andre Vincent, Syeed Farrakhan, Daniel Hart, Xavier Ward, Whitney Griffith, George Jenkins, Tariq
	- AN INCH IS ASSUMED TO BE 8 SPACES
	- MAX NUMBER OF CHARACTERS PER LINE IS 80
	- MAX NUMBER OF INCHES ON A PAGE IS 10 INCHES
	- IF THE WORD IS TOO MANY CHARACTERS WIDE FOR THE LINE AFTER THE MARGINS ARE APPLIED, THE PROGRAM GETS SHUT
		DOWN
	- IF THE MARGINS EXCESSED 10 INCHES OR ARE NEGATIVE NUMBERS, THE PROGRAM WON'T RUN.
*/


int main() {
	
	ifstream inFile;				// the file stream thats being read from.
	ofstream outFile;				// the text file stream where the formatted text will be outputted.

	char ch;						// the character reading in.
	int leftMargin = 0;				// the inch size of the left + right margin
	int rightMargin = 0;			
	int x = 0;
	int charsPerLine = 80;			// the max chars per line of 80
	//int lineCount = 0;		
	int orgCharsPerLine;
	string word = "";				// variable for the word			
	string befWord = "";			// variable for the previous word
	string line = "";				// the line to be printed
	string fileName = "";			// the file name that is being read
	bool endOfLine = false;
	string margin = "";				// the margin in that is being added to the line.
	string marginLine = "";
	int wordLen = 0;


	// saving the input file path to a variable
	cout << "Enter input file path including file extension \n\n"; 
	cin >> fileName;

	// opening the input and output files
	inFile.open(fileName);
	outFile.open("DAT1.TXT");

	// the file can't be opened
	if (!inFile) {	

		cout << "Can't open file. \n";
		system("pause");
		return 0;
	}
	// read in the margins
	inFile >> leftMargin;
	inFile >> rightMargin;

	// the margins exceeds 10 inches or are negative so the program can't be run

	if ((leftMargin + rightMargin) >= 10) {		 
		cout << "Can't open file. the margin exceeds the page size. \n";
		system("pause");
		return 0;
	}

	if (leftMargin < 0 || rightMargin < 0) {
		cout << "Can't open file. The margins are negative. \n";
		system("pause");
		return 0;
	}

	// set the margin in string form
	for (int i = 0; i < (leftMargin * 8); i++) {
		margin += " ";
	}

	// sets char per line amount
	charsPerLine = 80 - ((leftMargin + rightMargin) * 8);
	orgCharsPerLine = charsPerLine;

	while ((ch = inFile.get()) != EOF) {

		// skips the margin lines.
		if (x<1) {
			x++;
			continue;
		}

		// creates the word.
		word += ch;
		charsPerLine--;

		if (ch == '.') {//add extra space between sentences
			word += ' ';
			charsPerLine --;
		}

		if (ch != ' ' && ch != '\n') continue;

		wordLen = word.length();
		if (wordLen > orgCharsPerLine) {
			cout << "This word is too big to fit within the specficed margin. Program can not be continued." << endl;
			break;
		}
		//case 1. Add word to line so long as there isn't a line break and limit hasn't been reached and the word length doesn't exceed the chars left
		if (ch != '\n' && charsPerLine > 0 && (wordLen < charsPerLine)) {
			line += word;
			befWord = word;
			word = "";
			continue; //keep adding to line
		}

		//case 2. New line has been reached before char limit per line is reached and the word length doesn't exceed the chars left
		else if (ch == '\n' && charsPerLine > 0 && (wordLen < charsPerLine - 1)) {
			line += word + '\n';
			befWord = word;
			word = "";
		}
		//case 3. Number of chars per line was exceeded
		else if ((wordLen > charsPerLine - 1)) {
			
			line += '\n';

			line = margin + line;//add left margin
			outFile << line;
			line = "";


			line = line + word;
			befWord = word;
			word = "";

			//reset for next line

			charsPerLine = 80 - ((leftMargin + rightMargin) * 8) - befWord.length();

			continue;
		}

		line = margin + line;//add left margin
		outFile << line;

		//reset for next line
		line = "";
		charsPerLine = 80 - ((leftMargin + rightMargin) * 8);

	}

	system("pause");
	return 0;

}