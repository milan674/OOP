#pragma once
#include <string>
using namespace std;
#include <fstream>
#include <vector>
class Clonable {
public:
	virtual ~Clonable() = default;
	virtual Clonable* clone() const =0;
};





