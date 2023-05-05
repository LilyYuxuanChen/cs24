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

set<Person*> stub;

std::set<Person*> Person::ancestors(PMod pmod) {
	return stub;	
}
std::set<Person*> Person::aunts(PMod pmod, SMod smod) {
	return stub;
}
std::set<Person*> Person::brothers(PMod pmod, SMod smod) {
	return stub;
}
std::set<Person*> Person::children() {
	set<Person*> childs;
	for (const auto& c : pchild) {
		childs.insert(c);
	}
	return childs;
}
std::set<Person*> Person::cousins(PMod pmod, SMod smod) {
	return stub;
}
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
std::set<Person*> Person::descendants() {
	return stub;
}
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

std::set<Person*> Person::grandfathers(PMod pmod) {
	return stub;
}
std::set<Person*> Person::grandmothers(PMod pmod) {
	return stub;
}
std::set<Person*> Person::grandparents(PMod pmod) {
	return stub;
}
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
std::set<Person*> Person::nephews(PMod pmod, SMod smod) {
	return stub;
}
std::set<Person*>  Person::nieces(PMod pmod, SMod smod) {
	return stub;
}
std::set<Person*> Person::parents(PMod pmod) {
	set<Person*> ps;
	if (pmod ==  PMod::ANY) {
		if (this->mom != nullptr) {
		ps.insert(this->mom);
		}
		if (this->dad != nullptr) {
		ps.insert(this->dad);
		}
	}
	else if (pmod == PMod::MATERNAL) {
		if (this->mom != nullptr) {
		ps.insert(this->mom);
		}
	}
	else {
		if(this->dad != nullptr) {
		ps.insert(this->dad);
		}
	}
	return ps;
}
std::set<Person*>  Person::siblings(PMod pmod, SMod smod) {
	return stub;
}
std::set<Person*> Person::sisters(PMod pmod, SMod smod) {
	return stub;
}
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

std::set<Person*> Person::uncles(PMod pmod, SMod smod) {
	return stub;
}
