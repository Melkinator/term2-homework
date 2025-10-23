#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>
using namespace std;
class Solution{
public:
    bool areNumAscending(std::string s){
        // your code here ...
        vector<int> numbers;
        int arr[100]={};
        int size=0;
        for (int i=0;i<s.size();i++) {
            if (isdigit(s[i])) {
                int num=0;
                while (i<s.size()&&isdigit(s[i])) {
                    num = num*10+(s[i]-'0');
                    i++;
                }
                numbers.push_back(num);
            }
        }
        for (int i=0;i<numbers.size()-1;i++) {
            if (numbers[i]>=numbers[i+1]) {
                return false;
            }
        }
        return numbers.size()>1;
    }
};
