#include "MediaOutlets.h"
#include <string>
#include<iostream>


void Newspaper::publish()
{
	counter++;
}

Newspaper::Newspaper(std::string name, Person* editor, Regularity reg)
	: MediaOutlet(name), editor(editor), reg(reg)
{

}

void Newspaper::introduce()
{
	std::cout << "Newspaper called: " << getName() << " (editor in chief: " << getEditor() << ") appears on a "<< regularityToString(reg)<< " basis and has been published " << getCounter() << " times" << std::endl;
}

void MediaOutlet::printSubscribers()
{
	std::cout << getCounter() << " people subscribed to newspaper called " << getName() << std::endl;
	for (auto a : feliratkozok) {
		std::cout <<" -->"<< a->name<<std::endl;
	}
}

void MediaOutlet::subscribe(Person* person)
{
	feliratkozok.push_back(person);
}

void TVShow::air()
{
	counter++;
	
}

TVShow::TVShow(std::string name, Person* host)
	: MediaOutlet(name), host(host)
{
}

void TVShow::introduce()
{
	// TV show called Daily news is hosted by Hajdu Hedvig and has aired 1 times
	std::cout << "TV show called " << getName() << " is hosted by " << getHost() << " and has aired " << getCounter() << " times" << std::endl;
}

bool isMediaOutletANewspaper(MediaOutlet* mo) {
	return dynamic_cast<Newspaper*> (mo) != nullptr;
}


Newspaper* convertMediaOutletToNewspaper(MediaOutlet* mo) {
	return dynamic_cast<Newspaper*>(mo);
}