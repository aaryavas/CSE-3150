// Check if the string contains valid parentheses
// The string may include '(', ')', '[', ']' and other characters
// These parentheses must be properly matched e.g. (), [()], [([])]

#include <string>
#include <iostream>
using namespace std;

bool ECParenthesesCheck(const std::string& strInput)
{
    //cleaning up the strings
    string filtered;
    for (char c : strInput) {
        if (c == '(' || c == ')' ||
            c == '{' || c == '}' ||
            c == '[' || c == ']') {
            filtered.push_back(c);
        }
    }
    //create "stack" with string
    string stack;
    for (char c : filtered) {
        //push to stack if open found
        if (c == '(' || c == '{' || c == '[') {
            stack.push_back(c);
        } 
        else {
            if (stack.empty()) {
                
                return false;
            }
            char top = stack.back();
            stack.pop_back();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    return stack.empty();
}
