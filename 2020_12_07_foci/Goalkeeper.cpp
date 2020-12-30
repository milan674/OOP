#include "Goalkeeper.h"

short Goalkeeper::getReflexes() const
{
	return reflexes;
}

short Goalkeeper::getAgility() const
{
	return agility;
}

short Goalkeeper::getOverall()const {
	short a = getSpeed() + getStamina() + getReflexes() + getAgility();
	a /= 4;
	return a;
}

Goalkeeper::Goalkeeper(std::string name, short speed, short stamina, short agility, short reflexes)
:SoccerPlayer(name, speed, stamina),reflexes(reflexes),agility(agility)
{
}
