#include "HashTable.h"

void HashTable::add(const std::string& login, const std::string& password_hash)
{
	table[login] = password_hash;
}

std::string HashTable::find(const std::string& login) const
{
	auto it = table.find(login);
	if (it != table.end())
	{
		return it->second;
	}
	return "";
}