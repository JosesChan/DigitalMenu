#ifndef MENU_H
#define MENU_H

#include "ItemList.h"

class Menu : public ItemList
{
public:
	Menu(std::string fileName);
	std::string toString() override;
	void checkBool(bool& boolHolder, std::string charInput);

private:
	std::vector<std::string> split(const std::string& s, char delim);
};


#endif // Menu_H