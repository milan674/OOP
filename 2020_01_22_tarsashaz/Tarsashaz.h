#pragma once
#include "BekesTulajdonos.h"
#include "PereskedoTulajdonos.h"
#include "Kozgulyes.h"
#include <vector>
class Tarsashaz
{
protected:
	std::vector <Tarstulajdonos*> tulajok;
public:
	Tarsashaz() {};
	void addTulajdonos(Tarstulajdonos * tt);
	void holdKozgyules(Kozgyules* kgy); 

};

// - A Tarsashaz osztaly:
// ... STL kontenerben, hozzadas sorrendjeben tarolja a tulajdonosokra hivatkozo pointereket
// ... 2-es szinthez a Tarstulajdonosok pointereit az addTulajdonos() metodussal lehet hozzaadni
// ... 2-es szinthez megvalositja meg a holdKozgyules() metodust. Ez a metodus gondoskodik rola, hogy
//     minden 2. pereskedo tulajdonos, es minden 3. bekes tulajdonos reszt vegyen a kozgyulesen (ehhez a kozgyules addJelenlevo() metodusat lehet hasznalni)