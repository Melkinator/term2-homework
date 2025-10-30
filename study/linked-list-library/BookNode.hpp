#ifndef BOOKNODE_HPP // to prevent error when include multiple time
#define BOOKNODE_HPP

#include <string>

class BookNode{
public:
    std::string title;
    std::string borrowDate;
    BookNode* next;

    // Constructor
    BookNode(std::string title, std::string borrowDate): title(title), borrowDate(borrowDate), next(nullptr) {
        // your code here
    }
};

#endif