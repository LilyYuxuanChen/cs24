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
	size_t l = points.size();
	unique_ptr<Heap> h(new Heap(maxcount));
	vector<string> wl;
	for (size_t i  = 0; i < mWords.size(); i++) {
		if (mWords[i].size() == l){
			wl.push_back(mWords[i]);
		}
	}
	for (size_t i = 0; i < wl.size(); i++) {
		int k = 0;
		float tot = 0;
		for (char w : wl[i]) {
			int val = w;
			int idx = val -97;
			float s = 1/ (10 * pow(sqrt(pow(QWERTY[idx].x-points[k].x, 2)+pow(QWERTY[idx].y-points[k].y, 2)), 2) +1);
			tot += s;
			k++;
		}
		float avg = tot/l;
		if (avg > cutoff) {
			if (h->Count() >= h->Capacity()) {
				if (h->top().score < avg) {
					h->pushpop(wl[i], avg);
				}
			}
			else {
				h->push(wl[i], avg);
			}
		}
	}
	return *h;

}

