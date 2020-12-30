#include "FieldPlayer.h"

FieldPlayer::FieldPlayer(std::string name, short speed, short stamina, short shooting, short passing, short tackling)
	:SoccerPlayer(name, speed, stamina),shooting(shooting),passing(passing),tackling(tackling)
{
}

short FieldPlayer::getShooting() const
{
	return shooting;
}

short FieldPlayer::getPassing() const
{
	return passing;
}

short FieldPlayer::getTackling() const
{
	return tackling;
}

short FieldPlayer::getOverall() const {
	short a = getShooting() + getSpeed() + getStamina() + getTackling() + getPassing();
	a /= 5;
	return a;
}
