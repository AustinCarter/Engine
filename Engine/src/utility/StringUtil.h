/**
 * Utility functions for working with strings
 */

#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


/**
 * A funtion to split a string at a given delimeter
 * @param s the string to be split
 * @param delim the delimeeter at which to split the string
 */
std::vector<std::string> split(std::string s, char delim) 
{
    std::stringstream ss(s);
    std::string item;
    std::vector<std::string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

#endif