#include <iostream>
using namespace std;
#include "SoccerPlayer.h"
#include "Goalkeeper.h"
#include "FieldPlayer.h"
#include "SoccerTeam.h"



int main() {

	const FieldPlayer* fp1 = new FieldPlayer("C. Ronaldo", 90, 85, 95, 91, 76);
	const FieldPlayer* fp2 = new FieldPlayer("L. Messi", 88, 93, 75, 88, 96);
	const Goalkeeper* gk = new Goalkeeper("M. Neuer", 89, 87, 94, 95);
	const SoccerPlayer* p1 = fp1;
	const SoccerPlayer* p2 = fp2;
	const SoccerPlayer* p3 = gk;
	cout << p1->getName() << endl;
	cout << p1->getSpeed() << endl;
	cout << p1->getStamina() << endl;
	cout << fp1->getShooting() << endl;
	cout << fp1->getPassing() << endl;
	cout << fp1->getTackling() << endl;
	cout << p1->getOverall() << endl;
	cout << endl;
	cout << fp2->getName() << endl;
	cout << fp2->getSpeed() << endl;
	cout << fp2->getStamina() << endl;
	cout << fp2->getShooting() << endl;
	cout << fp2->getPassing() << endl;
	cout << fp2->getTackling() << endl;
	cout << fp2->getOverall() << endl;
	cout << endl;
	cout << gk->getName() << endl;
	cout << gk->getSpeed() << endl;
	cout << gk->getStamina() << endl;
	cout << gk->getReflexes() << endl;
	cout << gk->getAgility() << endl;
	cout << gk->getOverall() << endl;
	cout << endl;
	cout << *p1 << endl;
	cout << *p2 << endl;
	cout << *p3 << endl;
	delete p1;
	delete fp2;
	delete gk;

	SoccerTeam team;

	if (team.add(new FieldPlayer("C. Ronaldo", 90, 85, 95, 91, 76)))
		cout << "Player added: " << *team[team.playerCount() - 1] << endl;
	else
		cout << "Failed to add C. Ronaldo.\n";

	if (team.add(new FieldPlayer("L. Messi", 88, 93, 75, 88, 96)))
		cout << "Player added: " << *team[team.playerCount() - 1] << endl;
	else
		cout << "Failed to add L. Messi.\n";

	if (team.add(new Goalkeeper("M. Neuer", 89, 87, 94, 95)))
		cout << "Player added: " << *team[team.playerCount() - 1] << endl;
	else
		cout << "Failed to add M. Neuer.\n";

	if (team.add(team[0]))
		cout << "Player added: " << *team[team.playerCount() - 1] << endl;
	else
		cout << "Failed to add " << *team[0] << endl;

	if (team.add(team[1]))
		cout << "Player added: " << *team[team.playerCount() - 1] << endl;
	else
		cout << "Failed to add " << *team[1] << endl;

	if (team.add(team[2]))
		cout << "Player added: " << *team[team.playerCount() - 1] << endl;
	else
		cout << "Failed to add " << *team[2] << endl;

	Goalkeeper* gk2 = new Goalkeeper("H. Lloris", 85, 86, 92, 94);
	if (team.add(gk2))
		cout << "Player added: " << *team[team.playerCount() - 1] << endl;
	else
		cout << "Failed to add " << *gk2 << endl;
	delete gk2;

	for (size_t i = 0; i < (size_t)team.playerCount(); ++i)
	{
		cout << *team[i] << endl;
		cout << team[i]->getName() << endl;
		cout << team[i]->getSpeed() << endl;
		cout << team[i]->getStamina() << endl
			<< endl;
	}

	return 0;
}