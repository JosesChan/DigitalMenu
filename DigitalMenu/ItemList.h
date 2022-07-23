#ifndef ItemList_H
#define ItemList_H

#include "Item.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"
#include <string>
#include <vector>
#include <memory>

class ItemList
{
protected:
	// creates a vector of smart pointers (deletes once done) that lead to instances of item class
	std::vector<std::shared_ptr<Item>> items;
	
public:

	// Accessor for pointer of items vector
	std::shared_ptr<Item> getVectorPointer(int vectorIndex);
	int getVectorSize();

	// pure virtual function 
	virtual std::string toString() = 0;
};


#endif // ItemList_H
