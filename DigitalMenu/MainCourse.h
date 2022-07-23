#ifndef MainCourse_H
#define MainCourse_H

#include "Item.h"

// MainCourse class
class MainCourse : public Item {
public:
	//Constructor
	MainCourse(char typeInput, std::string nameInput, float priceInput, float caloriesInput);

	// toString Method
	std::string toString() override;
};

#endif // MainCourse_H
