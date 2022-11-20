#include "Beverage.h"
#include <string>

// isAlcohol Method
bool Beverage::isAlcohol(float abvInput) {
	// UK Alcohol Free is beneath 0.05% abv
	if (abvInput >= 0.05) {
		return(true);
	}
	else {
		return(false);
	}
}


// toString Method
std::string Beverage::toString() {

	std::string alcoholStatus = "";
	
	// checks if alcoholic, adds alcohol percentage
	if (isAlcohol(abv) == true) {
		alcoholStatus = ", " + removeTrailingZeros(std::to_string(abv)) + '%';
	}
	return (" " + name + ", Calories: " + removeTrailingZeros(std::to_string(calories)) + ", Price: $" + removeTrailingZeros(std::to_string(price)) + " (" + removeTrailingZeros(std::to_string(volume)) + " ml" + alcoholStatus + ")");
}

Beverage::Beverage(char typeInput, std::string nameInput, float priceInput, float caloriesInput, float volumeInput, float abvInput)
{
	type = typeInput;
	calories = caloriesInput;
	name = nameInput;
	price = priceInput;
	volume = volumeInput;
	abv = abvInput;
}

