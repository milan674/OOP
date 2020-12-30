#pragma once
#include "SoccerPlayer.h"
#include <string>
class Goalkeeper : public SoccerPlayer
{
private:
	short reflexes;
	short agility;
public:
	short getReflexes() const;
	short getAgility() const;
	short getOverall() const override;
	Goalkeeper(std::string name, short speed, short stamina, short agility, short reflexes);
};

