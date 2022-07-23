#include "Menu.h"

#include <fstream>
#include <iostream>
#include <sstream>

Menu::Menu(std::string fileName) {

	std::string line = ""; // stores data of current line
	int itemCount = 0; // counts the amount of items currently given 

	std::vector<std::string> objectHolder; // vector that holds info from line before creating object

	// stores item info before creating an object
	bool shareableHolder;
	bool twoForOneHolder;

	// Create an input filestream to operate on file given
	std::ifstream userFile(fileName);

	// Ensures the file is open
	if (!userFile.is_open()) throw std::runtime_error("Could not open file");

	try {

		// while there are lines in the file, use current line to do following
		while (getline(userFile, line)) {

			objectHolder = split(line, ',');

			// switch case to reduce access time to same amount
			switch (line.front()) {
			case 'a':

				checkBool(shareableHolder, objectHolder[4]); // if char y is found, assume that its true, else set as false
				checkBool(twoForOneHolder, objectHolder[5]); // if char y is found, assume that its true, else set as false

				// create class and its pointer, store it in vector
				items.push_back(std::make_shared<Appetiser>(
					(objectHolder[0]).front(),
					objectHolder[1],
					std::stof(objectHolder[2]),
					std::stof(objectHolder[3]),
					shareableHolder,
					twoForOneHolder
					));


				break;
			case 'm':

				// create class and its pointer, store it in vector
				items.push_back(std::make_shared<MainCourse>((
					objectHolder[0]).front(),
					objectHolder[1],
					std::stof(objectHolder[2]),
					std::stof(objectHolder[3]))
				);

				break;
			case 'b':

				// create class and its pointer, store it in vector
				items.push_back(std::make_shared<Beverage>(
					(objectHolder[0]).front(),
					objectHolder[1],
					std::stof(objectHolder[2]),
					std::stof(objectHolder[3]),
					std::stof(objectHolder[6]),
					std::stof(objectHolder[7])
					));

				break;
			}
		}
	}
	catch (const std::exception& e) {
		std::cout << '\n';
		std::cout << "Error reading in the file";
		std::cout << '\n';
	}

}

// returns string that represents the entire menu
std::string Menu::toString() {

	std::string returnStrings = "";
	char previousType = ' '; // keeps track of what the previous object's type was (a,b or m)
	std::vector<std::string> headers{"Appetisers","Main Course","Beverage"};
	int headerIterator = 0; // iterates through the header

	returnStrings += '\n';

	for (std::size_t i = 0; i < items.size(); i++) {
		
		// if type of item changes, apply header
		if (items[i]->getType() != previousType) {
			returnStrings += headers[headerIterator];
			returnStrings += '\n';
			previousType = items[i]->getType();
			headerIterator++;
		}
		

		returnStrings += '(' + std::to_string(i + 1) + ')';
		returnStrings += items[i]->toString();
		returnStrings += "\n";
	}
	return(returnStrings);
}

// function that returns true or false based on character given.
void Menu::checkBool(bool& boolHolder, std::string charInput) {
	if ("y" == charInput) {
		boolHolder = true;
	}
	else {
		boolHolder = false;
	}
}

std::vector<std::string> Menu::split(const std::string& stringInput, char delimiter) {
	std::vector<std::string> result;
	std::stringstream ss(stringInput); // create a stringstream object from the string input given
	std::string substring;

	// select the string and store in substring until delimiter is found
	while (getline(ss, substring, delimiter)) {
		result.push_back(substring); // store in vector
	}
	return result; // return seperated string
}

