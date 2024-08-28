#pragma once
#include <string>
#include <unordered_map>

class HashTable
{
public:
	HashTable() = default;
	~HashTable() = default;

	void add(const std::string& login, const std::string& password_hash);
	std::string find(const std::string& login) const;

private:
	std::unordered_map<std::string, std::string> table;
};