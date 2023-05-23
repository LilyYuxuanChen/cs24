#include "WordList.h"
#include <memory>
#include <cmath>
#include <string>
using namespace std;

WordList::WordList(std::istream& stream) {
	string wd;
	while (stream >> wd) {
		bool L = true;
		for (char c : wd) {
			if (!(islower(c))) {
				L = false;
				break;
			}
		}
		if (L) {
			mWords.push_back(wd);
		}
	}

}
Heap WordList::correct(const std::vector<Point>& points, size_t maxcount, float cutoff) const {
	Heap a = new Heap(maxcount);
	return a;
}

