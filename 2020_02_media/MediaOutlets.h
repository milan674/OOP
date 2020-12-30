#ifndef MEDIAOUTLETS_H
#define MEDIAOUTLETS_H
#include "helpers.h"
#include <string>
#include <vector>
#include <iostream>
class MediaOutlet
{
protected:
	std::string name;
	int counter = 0;
	std::vector <Person*> feliratkozok;
public:
	MediaOutlet(std::string name) : name(name) {};
	virtual void introduce() { std::cout << " 000"; }; //todo
	void printSubscribers();//todo
	int getCounter() { return counter; }
	void subscribe(Person* person);
	
	std::string getName() const { return name;}
};


class Newspaper : public MediaOutlet{
	
	Person* editor;
	Regularity reg;
	
public:
	void publish();
	Newspaper(std::string name, Person* editor, Regularity reg); 
	virtual void introduce()  override;
	std::string getEditor() { return editor->name; }
};

class TVShow : public MediaOutlet  {
	Person* host;

public:
	void air();// todo
	TVShow(std::string name, Person* host);//todo
	virtual void introduce()  override;
	std::string getHost() { return host->name; }
};
#endif
