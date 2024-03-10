#include <iostream>
#include "./include/ListClass.h"
#include <string>
#include <algorithm>
#include <cctype>

std::string removeSpaces(const std::string& input);
std::string toLowercase(const std::string& input);

int main() {
    List list;
    std::string option;
    std::unordered_map<int, std::string> input;

    while (true) {
        std::cout << "Welcome to the list\n";
        std::cout << list.read() << "\n";
        std::cout << "Please choose: ";
        std::cout << "\ntype a to add";
        std::cout << "\ntype r to remove";
        std::cout << "\ntype e to exit";

        std::cout << "\nOption: ";
        std::getline(std::cin, option);
        if (removeSpaces(toLowercase(option)) == "e") {
            break;
        }
        if (removeSpaces(toLowercase(option)) == "a") {
            std::string newItem;
            std::cout << "Item to add: ";
            std::getline(std::cin, newItem);
            list.write({
                {list.Get_last_index(), newItem}
            });
            continue;
        }
        if (removeSpaces(toLowercase(option)) == "r") {
            int itemToRemove;
            std::cout << "Index to remove: ";
            std::cin >> itemToRemove;
            std::cin.ignore();
            list.remove(itemToRemove);
            continue;
        }
    }
}


std::string removeSpaces(const std::string& input) {
    std::string result = input;

    // Use std::remove_if with std::isspace to remove spaces
    result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());

    return result;
}

std::string toLowercase(const std::string& input) {
    std::string result = input;

    // Convert each character to lowercase using std::transform and std::tolower
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);

    return result;
}