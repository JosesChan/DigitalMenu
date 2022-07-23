#include "MainCourse.h"

MainCourse::MainCourse(char typeInput,  std::string nameInput, float priceInput, float caloriesInput)
{
	type = typeInput;
	calories = caloriesInput;
	name = nameInput;
	price = priceInput;
}


std::string MainCourse::toString() {
	return (" " + name + ", Calories: " + removeTrailingZeros(std::to_string(calories)) + ", Price: \xA3" + removeTrailingZeros(std::to_string(price)));
}