#include "../include/ListClass.h"
#include "../include/Result.h"

Result List::write(std::unordered_map<int, std::string> items) {
    std::ofstream list("list.txt", std::ios::app);
    if (!list.is_open()) {
        std::cout << "Cannot open the file";
        return Result::Err;
    }

    for (const auto &[key, value] : items) {
        list << key << " " << value << "\n";
        this->last_index += 1;
    }
    list.close();
    return Result::OK;
}

std::string List::read() {
    std::ifstream list("list.txt");
    if (!list.is_open()) {
        return "";
    }
    std::string items;
    std::string line;
    while (std::getline(list, line)) {
        items += line + "\n";
    }
    list.close();
    return items;
}

Result List::remove(int line_index) {
    std::fstream list("list.txt");
    if (!list.is_open()) {
        std::cout << "Cannot open the file";
        return Result::Err;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(list, line)) {
        lines.push_back(line);
    }
    list.close();

    if (line_index >= 1 && line_index <= static_cast<int>(lines.size())) {
        // Remove the target line
        lines.erase(lines.begin() + line_index - 1);

        // Write the modified content back to the file
        std::ofstream outputFile("list.txt", std::ios::trunc);
        if (!outputFile.is_open()) {
            std::cerr << "Error opening file for writing." << std::endl;
            return Result::Err;
        }

        for (const auto& modifiedLine : lines) {
            outputFile << modifiedLine << '\n';
        }

        outputFile.close();

        this->last_index -= 1;

        return Result::OK;
    } else {
        return Result::Err;
    }

}

int List::Get_last_index() {
    return this->last_index;
}