#ifndef ITEM_H
#define ITEM_H

#include <string>


// Item class
class Item {
public:
	// accessors to be used if any of the variables are wanted
	char getType();
	float getCalories();
	std::string getName();
	float getPrice();	

	// virtual method to be implement in its classes
	virtual std::string toString() = 0;

protected:
	// class fields
	char type;
	float calories;
	std::string name;
	float price;

	// class method, removes trailing zeros from the string
	std::string removeTrailingZeros(std::string inputString);
};

#endif // ITEM_H

