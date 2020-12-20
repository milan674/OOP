#include <iostream>
#include "Clonable.h"
#include"ClonableNumber.h"
#include "ClonableString.h"
#include "CloneContainer.h"
using namespace std;


int main() {
	/*
	const ClonableString str1("text");
	string testStr = str1.getString();
	cout << "str1 = " << testStr << endl;
	ClonableString* str2 = str1.clone();
	cout << "str2 = " << str2->getString() << endl;

	
	const ClonableNumber num1(3.14);
	double testNum = num1.getNumber();
	cout << "num1 = " << testNum << endl;
	ClonableNumber* num2 = num1.clone();
	cout << "num2 = " << num2->getNumber() << endl;
	
	delete str2;
	delete num2;
	*/
	
	const ClonableString str1("szo");
	const ClonableString str2("szoveg");
	const ClonableString str3("word");

	const ClonableNumber num1(4.2);
	const ClonableNumber num2(-6.66);

	CloneContainer clones;
	clones.push_back(str1);
	clones.push_back(num1);
	clones.push_back(str2);
	cout << clones.size() << " clones have been made\n";

	
	Clonable& i1 = clones[0];
	string testStr = dynamic_cast<ClonableString*>(&i1)->getString();
	cout << "Item 1: " << testStr << endl;

	ClonableNumber* i2 = dynamic_cast<ClonableNumber*>(&clones[1]);
	cout << "Item 2: " << i2->getNumber() << endl;

	ClonableString& i3 = dynamic_cast<ClonableString&>(clones[2]);
	cout << "Item 3: " << i3.getString() << endl;

	clones.push_back(str3);
	clones.push_back(num2);
	cout << clones.size() << " clones have been made\n";

	ClonableString* i4 = dynamic_cast<ClonableString*>(&clones[3]);
	cout << "Item 4: " << i4->getString() << endl;

	ClonableNumber& i5 = dynamic_cast<ClonableNumber&>(clones[4]);
	cout << "Item 5: " << i5.getNumber() << endl;
	
	

	return 0;

}