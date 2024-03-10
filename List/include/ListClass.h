//
// Created by Lilian on 10.03.2024.
//

#ifndef LIST_LISTCLASS_H
#define LIST_LISTCLASS_H

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include "Result.h"
#include <vector>

class List {
    int last_index = 1;
public:
    Result write(std::unordered_map<int, std::string> items);
    std::string read();
    Result remove(int line_index);
    int Get_last_index();
};

#endif //LIST_LISTCLASS_H
