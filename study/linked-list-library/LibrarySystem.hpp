#ifndef LIBRARYSYSTEM_HPP
#define LIBRARYSYSTEM_HPP

#include "Member.hpp"
#include <vector>

class LibrarySystem{
private:
    std::vector<Member*> members;

public:
    ~LibrarySystem(){
        for(Member* member: members){
            delete member;
        }
    }

    void addMember(std::string name){
        members.push_back(new Member(name));
    }

    Member* findMember(std::string name){
        for(Member* member: members){
            // your code here
            if (member->getName()==name) {
                return member;
            }
        }
        return nullptr;
    }

    void displayMemberBooks(std::string name){
        Member* member = findMember(name);
        if(member){
            std::cout<<member->getName() << ":" <<std::endl;
            member->displayBorrowInfo();
        }else{
            std::cout<<"Member not found"<<std::endl;
        }
    }
};


#endif