#include "ConfigFileReader.hpp"

std::unordered_map<std::string, std::string> getConfig(std::string fileName){
	std::ifstream configFile(fileName);
	std::string line;
	std::unordered_map<std::string, std::string> config;
	std::string tok, leftHandValue, rightHandValue;

	if (!configFile) {
		fmt::print("Failed to open colors.txt! Please verify it exists.");
		return {};
	}

	while (getline(configFile, line)) {
		if (line.rfind("#", 0) == 0 || line.empty())
			continue;
		leftHandValue = line.substr(0, line.find('=')).c_str();
		rightHandValue = line.substr(line.find('=')+1, line.length()).c_str();
		config[leftHandValue] = rightHandValue;
	}
	return config;
}

/*
colorValue = colorValue.substr(1, colorValue.size() - 2);
std::stringstream iss(colorValue);
fmt::print("{}={}\n", colorName, colorValue);
std::getline(iss, tok, ',');
int R = std::stoi(tok);
std::getline(iss, tok, ',');
int G = std::stoi(tok);
std::getline(iss, tok, ',');
int B = std::stoi(tok);
fmt::print("color:({},{},{})\n", R, G, B);
*/