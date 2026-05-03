#pragma once


#include <vector>
#include <string>

std::vector<std::string> mapping = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


void find_permutations(std::string& output,const std::string& digits, size_t i, std::vector<std::string>& ans);
