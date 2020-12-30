#include "SoccerTeam.h"

bool SoccerTeam::add(const SoccerPlayer* s)
{
	if (find(vektor.begin(), vektor.end(), s) != vektor.end()) {
		return false;
	}
	int counter = 0;
	const Goalkeeper* gk = dynamic_cast<const Goalkeeper*>(s);
	if (gk != nullptr) // ha nem nulptr akkor kapus
	{
		for (auto a: vektor)
		{
			const Goalkeeper* test = dynamic_cast<const Goalkeeper*>(a);
			if (test != NULL)  	counter++;
		}
		if (counter != 0) return false;
	}
	vektor.push_back(s);
	return true;
}

int SoccerTeam::playerCount() const
{
	int counter = 0;
	for (auto a : vektor) {
		counter++;
	}
	return counter;
	//return vektor.size();
}

const SoccerPlayer* SoccerTeam::operator[](int index)
{
	return vektor[index];
}



SoccerTeam::~SoccerTeam()
{
	for (auto a : vektor) {
		delete a;
	}
}
