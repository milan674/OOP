#pragma once
#include "SoccerPlayer.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include "Goalkeeper.h"

class SoccerTeam
{
private:
	std::vector<const SoccerPlayer*> vektor;
public:
	bool add(const SoccerPlayer* s);
	int playerCount() const;
	const	SoccerPlayer* operator[](int index);
	~SoccerTeam();
};