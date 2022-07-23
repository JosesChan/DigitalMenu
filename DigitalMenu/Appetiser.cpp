#include "Appetiser.h"

#include <string>
#include <iostream>

Appetiser::Appetiser(char typeInput,  std::string nameInput, float priceInput, float caloriesInput, bool shareableInput, bool twoForOneInput)
{
	type = typeInput;
	calories = caloriesInput;
	name = nameInput;
	price = priceInput;
	shareable = shareableInput;
	twoForOne = twoForOneInput;
}

// toString Method
std::string Appetiser::toString() {

	// Status is empty, changes string to reflect whether item is shareable/twoforone or not
	std::string shareableStatus = "";
	std::string twoForOneStatus = "";

	// checks status to prepare its output
	if (shareable == true) {
		shareableStatus = "(Shareable)";
	}

	if (twoForOne == true) {
		twoForOneStatus = "(twoForOne)";
	}

	return (" " + name + ", Calories: " + removeTrailingZeros(std::to_string(calories)) + ", Price: \xA3" + removeTrailingZeros(std::to_string(price)) + " " + shareableStatus + " " + twoForOneStatus);

}

bool Appetiser::getShareable()
{
	return shareable;
}

bool Appetiser::getTwoForOne()
{
	return twoForOne;
}

