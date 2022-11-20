#include "Order.h"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <sstream>	


// printreceipt Method, writes user's order to a text file called receipt.txt, using output from toString function
void Order::printReceipt(std::string orderReceipt){
	std::ofstream receiptFile("receipt.txt");
	receiptFile << orderReceipt;
	receiptFile.close();
}

// runs through Order items vector, to check two for one deals
std::string Order::calculateTotal(){

	float total = 0;
	float savings = 0;
	int twoForOneCounter = 0; // int to be used with modulus to calculate savings

	std::stringstream stream; // stringstream used to format a string to give to return

	for (std::size_t i = 0; i < items.size(); i++) {
		
		// do the following if the item is an appetiser
		if (std::static_pointer_cast<Appetiser>(items[i])->getTwoForOne()==true) {

			twoForOneCounter++; // increment twoforone counter

			if ((twoForOneCounter%2)==0) { // store the paired
				savings += items[i]->getPrice();
			} else { // if appetiser is not in a pair, add price normally
				total += items[i]->getPrice();
			}

		} else { // if its not an appetiser, add price normally
				total += items[i]->getPrice();
		}

	}

	if (savings == 0) {
		stream << ("Savings: $""0.00 \nTotal: $");
		stream << std::fixed << std::setprecision(2) << (total);
		return(stream.str());
	}

	stream << ("Savings: $");
	stream << std::fixed << std::setprecision(2) << (savings);
	stream << ("\nTotal: $");
	stream << std::fixed << std::setprecision(2) << (total);
	return(stream.str());
}

//Add an item to the order
void Order::add(std::shared_ptr<Item> item)
{
	items.push_back(item);
}

// returns receipt of order
std::string Order::toString() {

		std::string returnStrings = "";

		for (std::size_t i = 0; i < items.size(); i++) {
			returnStrings += '(' + std::to_string(i + 1) + ')';
			returnStrings += items[i]->toString();
			returnStrings += '\n';
		}

		returnStrings += '\n';
		returnStrings += '\n';
		returnStrings += calculateTotal();

		return(returnStrings);
}

// check if memory location matches
void Order::deleteLocation(int index)
{
	items.erase(items.begin() + index-1);

	std::cout << "Item Removed: ";
	std::cout << index;
	std::cout << '\n';
}

void Order::deleteLocation(std::vector<int> collectionIndices)
{
	// Sort the locations used to remove
	std::sort(collectionIndices.begin(), collectionIndices.end());

	std::cout << '\n';

	// change all locations that need to be removed into nullptrs 
	for (std::size_t i = 0; i< collectionIndices.size(); i ++) {

		// Inform user of its removal
		std::cout << "Item Removed: ";
		std::cout << collectionIndices[i];
		std::cout << '\n';
		items[collectionIndices[i]-1] = (nullptr);
	}

	// removes all locations with value set as nullptrs, erase all at the end (erase-remove idiom)
	items.erase(std::remove(items.begin(), items.end(), nullptr), items.end());

}