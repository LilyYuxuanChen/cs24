#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int main (int argc, char* argv[]){
if (argc != 2) {
	exit (1);
}
	string str;
	getline(cin,str);
	string original = str;
	int num = atoi(argv[1]);
	int len = str.size();
if (num > 0) {	
	for (int i = 0; i < len; i++) {
		if (isupper(original[i])) {
			str[i] = tolower(str[i]);
			cout << i << endl; 
			if ((i+num) < len) {
				str[i+num] = toupper(str[i+num]);
			//cout << i +num << endl;
			}
			else {
				str[(i+num)%len] = toupper(str[(i+num)%len]);
			//cout << (i+num)%len << endl;
			}


		}

	}
	
}
else{ 
}

	cout << str << endl;

	


	return 0;
}
