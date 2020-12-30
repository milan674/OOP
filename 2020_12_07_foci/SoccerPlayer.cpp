#include "SoccerPlayer.h"

SoccerPlayer::SoccerPlayer(const std::string& name, short speed, short stamina)
	:name(name), speed(speed),stamina(stamina)
{
}

std::ostream& operator<<(std::ostream& o, const SoccerPlayer& f)
{
	o << f.getName() << " (" << f.getOverall() << ")";
	return o;
}
