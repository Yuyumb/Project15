#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include "User.h"
#include "HashTable.h"

struct Message
{
	std::string sender;
	std::string recipient;
	std::string content;

	Message(const std::string& sender, const std::string& recipient, const std::string content) : sender(sender), recipient(recipient), content(content) {}

};

class Chat
{
private:
	HashTable user_table;
	std::unordered_map<std::string, User> user_map;
	std::vector<Message> messages;
public:
	bool registerUser(const std::string& login, const std::string& password, const std::string& name);
	bool login(const std::string& login, const std::string& password);
	void sendMessage(const std::string& sender, const std::string& recipientName, const std::string& message);
	void displayMessage() const;

	const std::unordered_map<std::string, User>& getUsers() const;
};