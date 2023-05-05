#include "Person.h"

// Person Member Functions

Person::Person(string name, string gender) {
	pname = name;
	pgender = gender;
	dad = nullptr;
	mom = nullptr;
}


const std::string& Person::name() const {
	return pname;
}
Gender Person::gender() const {
	if (pgender == "female") {
		return Gender::FEMALE;
	}
	else {
		return Gender::MALE;
	}
}
Person* Person::mother() {
	return mom;
}
Person* Person::father() {
	return dad;
}

std::set<Person*> Person::ancestors(PMod pmod = PMod::ANY) {

}
std::set<Person*> Person::aunts(PMod pmod = PMod::ANY, SMod smod = SMod::ANY);
std::set<Person*> Person::brothers(PMod pmod = PMod::ANY, SMod smod = SMod::ANY);
std::set<Person*> Person::children() {
	set<Person*> childs;
	for (const auto& c : pchild) {
		childs.insert(c);
	}
	return childs;
}
std::set<Person*> Person::cousins(PMod pmod = PMod::ANY, SMod smod = SMod::ANY);
std::set<Person*> Person::daughters() {
	set<Person*> daugh;
	set<Person*> childs = this->children();
	for(const auto& child : childs) {
		if (child->pgender == "female") {
			daugh.insert(child);
		}
	}
	return daugh;
}
std::set<Person*> descendants();
std::set<Person*> Person::grandchildren() {
	set<Person*> gchilds;
	set<Person*> childs_1 = this->children();
	for(const auto& child : childs_1) {
		set<Person*> childs_2 = child->children();
		for (const auto& c : childs_2) {
			gchilds.insert(c);
		}
	}
	return gchilds;
}

std::set<Person*> Person::granddaughters() {
	set<Person*> gdaugh;
	set<Person*> gchilds = this->grandchildren();
	for(const auto& child : gchilds) {
		if (child->pgender == "female") {
			gdaugh.insert(child);
		}
	}
	return gdaugh;
}

std::set<Person*> grandfathers(PMod pmod = PMod::ANY);
std::set<Person*> grandmothers(PMod pmod = PMod::ANY);
std::set<Person*> grandparents(PMod pmod = PMod::ANY);
std::set<Person*> Person::grandsons() {
	set<Person*> gsons;
	set<Person*> gchilds = this->grandchildren();
	for(const auto& child : gchilds) {
	       	if (child->pgender == "male") {
	                gsons.insert(child);
               }
        }
       return gsons;
}
std::set<Person*> nephews(PMod pmod = PMod::ANY, SMod smod = SMod::ANY);
std::set<Person*> nieces(PMod pmod = PMod::ANY, SMod smod = SMod::ANY);
std::set<Person*> Person::parents(PMod pmod = PMod::ANY) {
	set<Person*> ps;
	if (pmod ==  PMod::ANY) {
		ps.insert(this->mom);
		ps.insert(this->dad);
	}
	else if (pmod == PMod::MATERNAL) {
		ps.insert(this->mom);
	}
	else {
		ps.insert(this->dad);
	}
	return ps;
}
std::set<Person*> siblings(PMod pmod = PMod::ANY, SMod smod = SMod::ANY);
std::set<Person*> sisters(PMod pmod = PMod::ANY, SMod smod = SMod::ANY);
std::set<Person*> Person::sons() {
	set<Person*> son;
	set<Person*> childs = this->children();
	for (const auto& child : childs) {
		if (child->gender() == Gender::FEMALE) {
			son.insert(child);
		}
	}
	return son;
}

std::set<Person*> uncles(PMod pmod = PMod::ANY, SMod smod = SMod::ANY);
