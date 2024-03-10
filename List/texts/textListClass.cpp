#include "../include/ListClass.h"
#include "../include/Result.h"
#include <cassert>
#include <cstdio>


void text();

int main() {
    text();
}

void text() {
    List textList;
    std::unordered_map<int, std::string> textInput = {
            {0, "Text"},
            {1, "Text1"},
            {2, "Text2"}
    };
    Result result = textList.write(textInput);
    assert(result == Result::OK);
    std::string textRead = textList.read();
    assert(textRead != "");
    Result resultRemove = textList.remove(2);
    assert(resultRemove == Result::OK);

    std::remove("list.txt");
}