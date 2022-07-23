#include "ItemList.h"
#include <iostream>


std::shared_ptr<Item> ItemList::getVectorPointer(int vectorIndex) {
	return items[vectorIndex-1]; // Since the menu starts at 1 instead of 0, adjust for userinput
}


int ItemList::getVectorSize() {
	return items.size();
}