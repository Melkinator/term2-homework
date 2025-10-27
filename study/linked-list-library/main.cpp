#include "utils/LibrarySystem.hpp"
#include "utils/Member.hpp"

int main(){
    LibrarySystem lib;
    // implement your logic here

    lib.addMember("John");
    Member *john = lib.findMember("John");
    if (john) {
        john->borrowBook("Moby Dick", "12/12/1550");
    }
    lib.displayMemberBooks("John");
    
    return 0;
}
