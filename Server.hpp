#ifndef SERVER_HPP_INCLUDED
#define SERVER_HPP_INCLUDED

#include "User.hpp"
#include "Chat.hpp"

class Server
{
private:
	string name;
	vector<TextChannel> chats;
	vector<User> members;
};

#endif // SERVER_HPP_INCLUDED
