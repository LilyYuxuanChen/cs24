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
	set<Person*> ans;
	set<Person*> EMPTY;
	if (this->dad ==nullptr && this->mom ==nullptr){
	       return EMPTY;
	}
	if (this->dad !=nullptr && pmod == PMod::PATERNAL) {
		ans.insert(this->dad);
		set<Person*> dans = this->dad->ancestors();
		for (const auto& a : dans) {
			ans.insert(a);
		}
		return ans;
	}
	else if (this->mom != nullptr && pmod ==PMod::MATERNAL) {
		ans.insert(this->mom);
		set<Person*> mans = this->mom->ancestors();
		for (const auto& a : mans) {
			ans.insert(a);
		}
		return ans;
	}
	else {
		if (this->dad != nullptr) {
		ans.insert(this->dad);
		set<Person*> dans = this->dad->ancestors();
		for (const auto& a :dans) {
			ans.insert(a);
		}
		}
		if (this->mom != nullptr) {
		ans.insert(this->mom);
		set<Person*> mans = this->mom->ancestors();
		for (const auto& a :mans) {
			ans.insert(a);
		}
		}
		return ans;
	}
	
}
std::set<Person*> Person::aunts(PMod pmod, SMod smod) {
	set<Person*> a;
	set<Person*> temp;
	if (pmod == PMod::MATERNAL) {
		if (this->mom != nullptr) {
			a = this->mom->sisters(PMod::ANY, smod);
		}
	}
	else if (pmod == PMod::PATERNAL) {
		if (this->dad != nullptr) {
			a = this->dad->sisters(PMod::ANY, smod);
		}
	}
	else {
		if (this->dad != nullptr) {
			a = this->dad->sisters(PMod::ANY, smod);
		}
		if (this->mom != nullptr) {
		temp = this->mom->sisters(PMod::ANY, smod);
		for (const auto& t : temp) {
			a.insert(t);
		}
		}
		
	}

	return a;
}
std::set<Person*> Person::brothers(PMod pmod, SMod smod) {
	set<Person*> bro;
	set<Person*> sib = this->siblings(pmod, smod);
	for (const auto& s : sib) {
		if (s->pgender == "male") {
			bro.insert(s);

		}
	}

	return bro;
}
std::set<Person*> Person::children() {
	set<Person*> childs;
	for (const auto& c : pchild) {
		childs.insert(c);
	}
	return childs;
}
std::set<Person*> Person::cousins(PMod pmod, SMod smod) {
	set<Person*> cous;
	set<Person*> sib;
	if (pmod == PMod::MATERNAL) {
		if (this->mom != nullptr) {
			sib = this->mom->siblings(PMod::ANY, smod);
			for (const auto& s : sib) {
				set<Person*> temp = s->children();
				for (const auto& t : temp) {
					cous.insert(t);
				}
			}
		}
	}
	else if (pmod == PMod::PATERNAL) {
		if (this->dad != nullptr) {
			sib = this->dad->siblings(PMod::ANY, smod);
			for (const auto& s : sib) {
				set<Person*> temp = s->children();
				for (const auto& t : temp) {
					cous.insert(t);
				}
			}
		}
	}
	else {
		if (this->mom != nullptr) {
			sib = this->mom->siblings(PMod::ANY, smod);
		}
		if (this->dad != nullptr) {
			set<Person*> t = this->dad->siblings(PMod::ANY, smod);
			for (const auto& temp : t) {
				sib.insert(temp);
			}

		}
		for (const auto& s : sib) {
			set<Person*> child  = s->children();
			for (const auto& c : child) {
				cous.insert(c);
			}
		}
	}
	return cous;
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
	set<Person*> des;
	set<Person*> d1 = this->children();
	for (const auto& d : d1) {
		des.insert(d);
		set<Person*> d2 = d->descendants();
		for (const auto& e : d2) {
			des.insert(e);
		}
	}

	return des;
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
	set<Person*> gdad;
	if (pmod == PMod::PATERNAL) {
		if(this->dad != NULL && this->dad->dad != NULL) {
			gdad.insert(this->dad->dad);
		}
	}
	else if (pmod == PMod::MATERNAL) {
		if (this->mom != NULL && this->mom->dad != NULL) {
			gdad.insert(this->mom->dad);
		}
	}
	else {
		if(this->dad != NULL && this->dad->dad != NULL) {
			gdad.insert(this->dad->dad);
		}
		if(this->mom != NULL && this->mom->dad != NULL) {
			gdad.insert(this->mom->dad);
		}
	}

	return gdad;
}
std::set<Person*> Person::grandmothers(PMod pmod) {
	set<Person*> gmom;
	if (pmod == PMod::PATERNAL) {
		if(this->mom != NULL && this->dad->mom != NULL) {
			gmom.insert(this->dad->mom);
		}
	}
	else if (pmod == PMod::MATERNAL) {
		if (this->mom != NULL && this->mom->mom != NULL) {
			gmom.insert(this->mom->mom);
		}
	}
	else {
		if (this->mom != NULL && this->dad->mom != NULL) {
			gmom.insert(this->dad->mom);
		}
		if (this->mom != NULL && this->mom->mom != NULL) {
			gmom.insert(this->mom->mom);
		}
	}
	return gmom;
}
std::set<Person*> Person::grandparents(PMod pmod) {
	set<Person*> gparents;

	if (pmod == PMod::PATERNAL) {
		if (this->dad != NULL && this->dad->dad != NULL){
			gparents.insert(this->dad->dad);
		}
		if (this->dad != NULL && this->dad->mom != NULL){
			gparents.insert(this->dad->mom);
		}
	}
	else if (pmod == PMod::MATERNAL) {
	 	if (this->mom != NULL && this->mom->dad != NULL){
		        gparents.insert(this->mom->dad);
		}
	        if (this->mom != NULL && this->mom->mom != NULL){
		        gparents.insert(this->mom->mom);
		}
	}
	else {
		if (this->dad != NULL && this->dad->dad != NULL){
			 gparents.insert(this->dad->dad);
		}
		if (this->dad != NULL && this->dad->mom != NULL){
		         gparents.insert(this->dad->mom);
		}
		if (this->mom != NULL && this->mom->dad != NULL){
		         gparents.insert(this->mom->dad);
		}
		if (this->mom != NULL && this->mom->mom != NULL){
		         gparents.insert(this->mom->mom);
		}

	}
	return gparents;
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
	set<Person*> neph;
	set<Person*> sib = this->siblings(pmod, smod);
	for (const auto& s : sib) {
		set<Person*> sibs  = s->sons();
		for (const auto& son :sibs) {
			neph.insert(son);
		}
	}
	return neph;
}
std::set<Person*>  Person::nieces(PMod pmod, SMod smod) {
	set<Person*> nie;
	set<Person*> sib = this->siblings(pmod, smod);
	for (const auto& s : sib) {
		set<Person*> sibs = s->daughters();
		for (const auto& d : sibs) {
			nie.insert(d);
		}
	}
	return nie;
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
	//set<Person*> sib;
	set<Person*> dsib;
	set<Person*> msib;
	set<Person*> asib;
	set<Person*> fsib;
	set<Person*> hdsib;
	set<Person*> hmsib;
	set<Person*> hsib;

	if (this->dad != NULL) {
		dsib = this->dad->children();
	}
	if (this->mom != NULL) {
		msib = this->mom->children();
	}

	for (const auto& d : dsib) {
		asib.insert(d);
	}
	for (const auto& m : msib) {
		asib.insert(m);
	}

	for (const auto& d : dsib) {
		if (msib.find(d) != msib.end()) {
			fsib.insert(d);
		}
		else {
			hdsib.insert(d);
			hsib.insert(d);
		}
	}
	for (const auto& m : msib) {
		if (fsib.find(m) == fsib.end()) {
			hmsib.insert(m);
			hsib.insert(m);
		}
	}
	
	//sib.erase(this);
	dsib.erase(this);
	msib.erase(this);
	asib.erase(this);
	fsib.erase(this);
	hdsib.erase(this);
	hmsib.erase(this);
	hsib.erase(this);

	if (smod == SMod::FULL) {
		return fsib;
	}
	else if (smod == SMod::ANY) {
		if (pmod == PMod::MATERNAL) {
			return msib;
		}
		else if (pmod == PMod::PATERNAL) {
			return dsib;
		}
		else {
			return asib;
		}
	}
	else {
		if (pmod == PMod::MATERNAL) {
			return hmsib;
		}
		else if (pmod == PMod::PATERNAL) {
			return hdsib;
		}
		else {
			return hsib;
		}
	}

}
std::set<Person*> Person::sisters(PMod pmod, SMod smod) {
	set<Person*> sis;
	set<Person*> sib = this->siblings(pmod, smod);
	for (const auto& s : sib) {
		if (s->pgender == "female") {
			sis.insert(s);
		}
	}
	return sis;
}
std::set<Person*> Person::sons() {
	set<Person*> son;
	set<Person*> childs = this->children();
	for (const auto& child : childs) {
		if (child->gender() == Gender::MALE) {
			son.insert(child);
		}
	}
	return son;
}

std::set<Person*> Person::uncles(PMod pmod, SMod smod) {
	 set<Person*> a;
         set<Person*> temp;
         if (pmod == PMod::MATERNAL) {
 	        if (this->mom != nullptr) {
	                a = this->mom->brothers(PMod::ANY, smod);
	        }
	 }
	 else if (pmod == PMod::PATERNAL) {
	        if (this->dad != nullptr) {
	                a = this->dad->brothers(PMod::ANY, smod);
	        }
	 }
	 else {
	        if (this->dad != nullptr) {
	                a = this->dad->brothers(PMod::ANY, smod);
	        }
	        if (this->mom != nullptr) {
		        temp = this->mom->brothers(PMod::ANY, smod);
			for (const auto& t : temp) {
		        	a.insert(t);
			}
		}
         }
	return a;
}
