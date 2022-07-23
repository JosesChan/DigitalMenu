#ifndef APPETISER_H
#define APPETISER_H

#include "Item.h"


// Appetiser Class
class Appetiser : public Item {

public:	
	// constructor
	Appetiser(char typeInput, std::string nameInput, float priceInput, float caloriesInput, bool shareableInput, bool twoForOneInput);

	// public fields and methods
	std::string toString() override;
	bool getShareable(); // accessor
	bool getTwoForOne(); // accessor

private:
	// class fields
	bool shareable;
	bool twoForOne;
};

#endif // APPETISER_H
