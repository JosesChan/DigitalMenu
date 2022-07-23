#ifndef BEVERAGE_H
#define BEVERAGE_H

#include "Item.h"

class Beverage : public Item {

public:
	// Constructor
	Beverage(char typeInput, std::string nameInput, float priceInput, float caloriesInput, float volumeInput, float abvInput);

	// public methods
	bool isAlcohol(float abv);
	std::string toString() override;
	
private:
	// class fields
	float abv;
	float volume;
};


#endif // BEVERAGE_H
