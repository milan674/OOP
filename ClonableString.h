#pragma once
#include "Clonable.h"
class ClonableString : public Clonable
{
	std::string s;
public:
	ClonableString(std::string s) : s(s) {}
	std::string getString() const { return s; }
	Clonable* clone() const override;
};

