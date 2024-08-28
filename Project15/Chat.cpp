#include "Chat.h"
#include <iostream>
#include <functional>

bool Chat::registerUser(const std::string& login, const std::string& password, const std::string& name)
{
	std::string password_hash = std::to_string(std::hash<std::string>{}(password));
	if (!user_table.find(login).empty())
	{
		std::cout << "User with this login already exists." << std::endl;
		return false;
	}
	user_table.add(login, password_hash);
	user_map[login] = User(login, password, name);

	std::cout << "User " << name << " registered successfully." << std::endl;
	return true;
}

bool Chat::login(const std::string& login, const std::string& password) {
    std::string password_hash = std::to_string(std::hash<std::string>{}(password));
    std::string stored_hash = user_table.find(login);

    if (stored_hash == password_hash) {
        std::cout << "Logged in successfully." << std::endl;
        return true;
    }
    else {
        std::cout << "Invalid login or password." << std::endl;
        return false;
    }
}

void Chat::sendMessage(const std::string& sender, const std::string& recipientName, const std::string& message) {
    if (user_map.find(sender) == user_map.end()) {
        std::cout << "Sender " << sender << " not found." << std::endl;
        return;
    }
    std::string recipientLogin;
    bool recipientFound = false;

    for (const auto& user : user_map) {
        if (user.second.name == recipientName) {
            recipientLogin = user.first;
            recipientFound = true;
            break;
        }
    }

    if (!recipientFound) {
        std::cout << "User " << recipientName << " not found." << std::endl;
        return;
    }
    messages.emplace_back(sender, recipientLogin, message);
    std::cout << "Message from " << user_map.at(sender).name << " to " << recipientName << ": " << message << std::endl;
}

void Chat::displayMessage() const {
    for (const auto& message : messages) {
        std::string senderName = (user_map.find(message.sender) != user_map.end())
            ? user_map.at(message.sender).name
            : message.sender;
        std::string recipientName = (user_map.find(message.recipient) != user_map.end())
            ? user_map.at(message.recipient).name
            : message.recipient;

        std::cout << "Message from " << senderName << " to " << recipientName << ": " << message.content << std::endl;
    }
}

const std::unordered_map<std::string, User>& Chat::getUsers() const {
    return user_map;
}