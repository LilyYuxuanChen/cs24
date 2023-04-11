#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int main (int argc, char* argv[]){
/*	string input;
	getline(cin,input);
	
	int num = stoi(argv[1]);
	int len = input.length();
	int lett = 0;
	for (int i = 0; i < len; i++) {
		char a = input[i];
		if (!isalpha(a)) {
			cout << a;
			continue;
		}
		char base = isupper(a) ? 'A' : 'a';
		a = base + (a-base+((num+lett)%26)) % 26;
		cout << a;
		lett++;
		cout << endl;

			if (islower(input[i])){
				input[i] = 'a' + (input[i] - 'a' + num) % 26;
			}
			else {
				input[i] = 'A' + (input[i] - 'A' + num) % 26;
				
			}

		}

	}

	//cout << input << endl;


	return 0;
}
*/
/*
int rotation = stoi(argv[1]);

string line;
getline(cin, line);

string rotated;
for (char c : line) {
	if (isalpha(c)) {
		char base = isupper(c) ? 'A' : 'a';
		int index = c-base;
		int rotatedIndex = (index + rotation) % 26;
		if (rotatedIndex < 0) {
			rotatedIndex += 26;
		}
		c = base+ rotatedIndex;
	}
	rotated +=c;
}
*/
/*rotation  = rotation % line.length();

string rotated; 
for (char c : line) {
	if (isalpha(c)) {
		int offset = isupper(c)? 'A': 'a';
		int rotatedIndex = ((c - offset +rotation) % 26 + 26) %26;

		c = rotatedIndex + offset;
	}
	rotated += c;
}
*/
/*
string rotated = line.substr(line.length() - rotation) + line.substr(0, line.length() - rotation);
for (int i = 0; i < rotated.length(); i++) {
	char c = rotated[i];

	if (isalpha(c)) {
		if(isupper(c)) {
			rotated[i] = 'A' + ((c - 'A' + rotation) % 26);
		}
		else {
			rotated[i] = 'a' + ((rotated[i] - 'a' + rotation) %26);
		}
	}
}
*/

/*
for(char& c : rotated) {
	if (isalpha(c)) {
		c = ((c-'A' + rotation) % 26) +'A';
	}
	else {
		c = tolower(c);
	}
}*/
//cout << rotated << endl;
//return 0;
//}
string line;
int n = atoi(argv[1]);
if (getline(cin, line)) {
	int len = line.size();
	int i = 0;
	bool wrap_around = false;
	while (i < len) {
		if (isupper(line[i])) {
			line[i] = tolower(line[i]);
			int j = (i+n)% len;
			while (j !=i) {
				if (isalpha(line[j])) {
					line[j] = toupper(line[j]);
					break;
				}
				j = (j+1) %len;
			}
			if (j == 1) wrap_around = true;
			i = j;
		}
		else if (isdigit(line[i])) {

		}
		else {
			int j = (i+1) %len;
			if (j ==1) wrap_around = true;
			i = j;
		}
	}
	if (wrap_around){
	i = 0;
	while (i <n) {
		if (isalpha(line[i])) {
			line[i] = toupper(line[i]);
			break;
		}
		++i;
	}
}

cout << line << endl;

}
return 0;
}


