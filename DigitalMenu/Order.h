#ifndef ORDER_H
#define ORDER_H

#include "ItemList.h"

class Order : public ItemList {
public:
	void printReceipt(std::string orderReceipt);
	std::string calculateTotal();
	void add(std::shared_ptr<Item> item);
	std::string toString() override;
	void deleteLocation(int index);
	void deleteLocation(std::vector<int> collectionIndices);
	float total = 0;
};

#endif // ORDER_H