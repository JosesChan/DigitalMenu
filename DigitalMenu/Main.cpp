#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

void runMenu() {
	string userCommand = "";
	vector <string> parameters;
	vector <int> removeLocationsInput; // stores inputs that specifies locations to be removed
	string helpOutput = "Type 'menu' to display what items are on the menu to order from \n"
		"Type 'add number' to add an item from menu to your order (e.g. add 1) \n"
		"Type 'remove number' to remove an item from your order (e.g. remove 1) \n"
		"Type 'checkout' to look at your order, then type 'print' to output the order \n"
		"Type 'exit' to end the program \n \n";
	string checkoutDecision = "";

	// Override all localisation settings
	setlocale(LC_ALL, "");

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();

	cout << "Type in help to access the help menu\n";

	while (userCommand != "exit")
	{
		getline(cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		if (parameters.size() != 0) {

			string command = parameters[0];

			if (command.compare("menu") == 0) {
				std::cout << menu.toString();
				std::cout << '\n';
			}
			else if (command.compare("add") == 0)
			{
				for (std::size_t i = 1; i < std::size(parameters); i++) {
					try {
						if (stoi(parameters[i]) - 1 < menu.getVectorSize() && stoi(parameters[i]) >= 1) { // if value inputted is in the vector do the following
							order.add(menu.getVectorPointer(std::stoi(parameters[i])));
							cout << "\nNumber added\n";
						}
						else { // else report that it couldn't be added
							cout << "\nCouldn't add the number " + (parameters[i]) + ", as its not a list number\n";
						}
					}
					catch (const std::exception& e) {
						(void)e;
						cout << "\nError found with input given\n";
					}
				}
			}
			else if (command.compare("remove") == 0)
			{
				try {
					if (order.getVectorSize() != 0) {
						if (parameters.size() == 2) {
							if (stoi(parameters[1]) - 1 < order.getVectorSize() && stoi(parameters[1]) >= 1) {
								order.deleteLocation(std::stoi(parameters[1]));
							}
							else {
								cout << "\nCouldn't add the number " + (parameters[1]) + ", as its not a list number\n";
							}
						}

						if (parameters.size() > 2) {
							for (size_t i = 1; i < parameters.size(); i++) {
								if (stoi(parameters[i]) - 1 < order.getVectorSize() && stoi(parameters[i]) >= 1) {
									removeLocationsInput.push_back(std::stoi(parameters[i])); // account for menu starting at 0
								}
								else {
									cout << "\nCouldn't add the number " + (parameters[i]) + ", as its not a list number\n";
								}
							}

							if (removeLocationsInput.empty() == false) {
								order.deleteLocation(removeLocationsInput);
								removeLocationsInput.clear();
							}
						}
					}
					else {
						cout << "\nCouldn't remove the input, check numbers available \n";
					}
				}
				catch (const std::exception& e) {
					(void)e;
					cout << "\nError found with input given\n";
				}
			}
			else if (command.compare("checkout") == 0)
			{
				cout << order.toString();

				cout << '\n';
				cout << '\n';
				cout << "Do you want to place your order?\n";
				cout << "Type 'y' to confirm, or 'n' to go back and modify it. \n";

				while (checkoutDecision != "n") {

					// stores user input
					cin >> checkoutDecision;

					// removes white spaces
					std::string::iterator end_pos = std::remove(checkoutDecision.begin(), checkoutDecision.end(), ' ');
					checkoutDecision.erase(end_pos, checkoutDecision.end());
					//checkoutDecision.erase(remove_if(checkoutDecision.begin(), checkoutDecision.end(), isspace), checkoutDecision.end());

					if (checkoutDecision == "y") { // if user wants to print file
						order.printReceipt(order.toString());
						cout << "File outputted";
						exit(0);
					}
					else if (checkoutDecision != "n") { // if user input is not recognised
						cout << "\nInput not recognized, please try again\n";
					}
				}

				checkoutDecision = ""; // reset while loop exit variable

			}
			else if (command.compare("help") == 0)
			{
				// output help string
				cout << helpOutput;
			}
			parameters.clear();
		}
	}
	cout<< "\nPress enter to exit";
	getchar();
}



int main() {
	cout<< "Press enter to continue\n";
	getchar();
	runMenu();
}