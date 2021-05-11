#pragma once
#include<iostream>
#include<fstream>
#include <string>
#include<sstream>
#include<fmt/core.h>
#include<unordered_map>

std::unordered_map<std::string, std::string> getConfig(std::string fileName);
