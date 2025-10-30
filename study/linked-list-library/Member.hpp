#ifndef MEMBER_HPP
#define MEMBER_HPP

#include <iostream>
#include "BookNode.hpp"
#include <string>

class Member{
private:
    std::string name;
    BookNode* firstBook;

public:
    Member(std::string name){
        this->name = name;
        firstBook = nullptr;
    }
    ~Member(){
        BookNode* current = firstBook;
        while(current){
            BookNode* next = current->next;
            delete current;
            current = next;
        }
    }
    
    BookNode* getFirstBook(){
        return firstBook;
    }

    void borrowBook(std::string title, std::string borrowDate){
        // your code here
        BookNode *newBook = new BookNode(title, borrowDate);

        if (!firstBook) {
            firstBook = newBook;
        } else {
            BookNode *temp = firstBook;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newBook;
        }
    }

    void returnBook(std::string title){
        // your code here
        if (!firstBook) return;

        BookNode *temp = firstBook;
        BookNode *prev = nullptr;

        while (temp&&temp->title!=title) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp) return;

        if (!prev) {
            firstBook = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
    }

    void displayBorrowInfo(){
        BookNode* temp = firstBook;
        while (temp){
            std::cout<<"- ";
            std::cout<< temp->title <<" Borrow on: "<< temp->borrowDate << std::endl;
            temp = temp->next;
        }
    }

    std::string getName(){
        return this->name;
    }
};

#endif