#ifndef SERVER_HPP_INCLUDED
#define SERVER_HPP_INCLUDED

#include "User.hpp"
#include "Chat.hpp"

class Server
{
private:
	string name;
	vector<TextChannel*> chats;
	vector<User*> members;
	User* owner;
	vector<User*> admins;
	static int brojServera;
public:
	Server(string name, User* owner)
	{
		this->name=name;
		this->owner=owner;
	}
	void addAdmin(User* user,int tag)
	{
			if(owner!=user)
			{
				cout<<"You do not have permission for that command."<<endl;
				return;
			}
			for(auto i=members.begin();i<members.end();i++)
			{
				if((*i)->getTag()==tag)
				{
					admins.push_back((*i));
					cout<<"Succesfully added admin."<<endl;
				}
			}
	}
	void removeAdmin(User* user, int tag)
	{
		if(owner!=user)
			{
				cout<<"You do not have permission for this command."<<endl;
				return;
			}
			for(auto i=members.begin();i<members.end();i++)
			{
				if((*i)->getTag()==tag)
				{
					admins.erase(i);
					cout<<"Succesfully removed admin."<<endl;
				}
			}

	}
	TextChannel* addTextChannel(string name)
	{
		TextChannel* textChannelPoniter = new TextChannel(name);
		return textChannelPoniter;
	}
	void addTextChannelMain(User* user)
	{
		for(int i=0;i<admins.size();i++)
		{
			if(user==admins.at(i) || user==owner)
			{
				cout<<"Channel name:";
				string chatName;
				cin>>chatName;
				chats.push_back(addTextChannel(name));
				cout<<"Succesfully added a channel";
				return;
			}
		}
		cout<<"You do not have permission for this command."<<endl;

	}

};

#endif // SERVER_HPP_INCLUDED
