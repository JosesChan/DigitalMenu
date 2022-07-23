#include "Item.h"

#include <string>

std::string Item::removeTrailingZeros(std::string inputString){

	if (inputString[inputString.find_last_not_of('0')]=='.') {
		// erase comma and trailing zeros 
		inputString.erase(inputString.find_last_not_of('0'), std::string::npos); // npos is max size of string
		return inputString;
	} else {
		// erase after finding the last character that dosen't match the char given
		inputString.erase(inputString.find_last_not_of('0') + 1, std::string::npos); // npos is max size of string
		return inputString;
	}
}
	

char Item::getType()
{
	return type;
}

float Item::getCalories() {
	return calories;
}
std::string Item::getName() {
	return name;
}
float Item::getPrice() {
	return price;
}


