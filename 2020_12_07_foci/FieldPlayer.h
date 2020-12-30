#pragma once
#include "SoccerPlayer.h"
#include <string>

class FieldPlayer: public SoccerPlayer
{
private:
	short shooting;
	short passing;
	short tackling;
public:
	FieldPlayer(std::string name, short speed, short stamina, short shooting, short passing, short tackling);
	short getShooting () const;
	short getPassing () const;
	short getTackling() const;
	short getOverall() const override;
};

