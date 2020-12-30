#ifndef SOCCERPLAYER_H
#define SOCCERPLAYER_H
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

class SoccerPlayer
{
const std::string name;
short speed;
short stamina;
public:
SoccerPlayer(const std::string& name, short speed, short stamina); 
virtual ~SoccerPlayer() = default;
const std::string& getName() const { return name; }
short getSpeed() const { return speed; }
short getStamina() const { return stamina; }
virtual short getOverall() const = 0;
};

std::ostream& operator<<  (std::ostream& o, const SoccerPlayer& f);

#endif