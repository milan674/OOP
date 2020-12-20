#pragma once
#include <vector>
#include "Clonable.h"
#include "ClonableNumber.h"
#include "ClonableString.h"
class CloneContainer
{
	std::vector<Clonable*> cont;
public:
	void push_back(const ClonableNumber c) {
		Clonable* a = c.clone();
		cont.push_back(a);
	}
	void push_back(const ClonableString c) {
		Clonable* a = c.clone();
		cont.push_back(a);
	}

	~CloneContainer() {
		for (auto c : cont) {
			delete c;
		}
	}
	Clonable& operator[](int index) {
		return *cont[index];
	}
	int size() {
		return cont.size();
	}
};

