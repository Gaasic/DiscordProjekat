#ifndef CHAT_HPP_INCLUDED
#define CHAT_HPP_INCLUDED
#include "User.hpp"
#include "Message.hpp"
#include <vector>
#include <fstream>

class Chat
{
protected:
	vector<Message*> messagez;
	User* sender;
	User* receiver;
	string name;
public:
	Chat(User* sender,User* receiver)
	{
		this->sender=sender;
		this->receiver=receiver;
		if(sender->getTag()<receiver->getTag())
			name=sender->getUsername()+"_"+receiver->getUsername()+".txt";
		else
			name=receiver->getUsername()+"_"+sender->getUsername()+".txt";
	}
	void sendMessage()
	{
		string text;
		fflush(stdin);
		getline(cin,text);
		Message* messagePointer=new Message(text,sender->getUsername());
		messagez.push_back(messagePointer);

	}
	void printDM()
	{
        for(auto i=messagez.begin();i!=messagez.end();i++)
        {
            cout<<(*i)->getAuthor()<<":"<<endl;
            cout<<(*i)->getText()<<endl;
        }
	}
	void saveMessages()
	{
        ofstream file;
        file.open(name);
        for(auto i=messagez.begin();i!=messagez.end();i++)
        {
            if(i!=messagez.begin())
                file<<endl;
            file<<(*i)->getText()<<"|";
            file<<(*i)->getAuthor();
        }
        file.close();
	}
	void loadMessages()
	{
		ifstream file;
		file.open(name);
        if (file.is_open())
        {
            string text,author,line;
            while(!file.eof())
            {
                getline(file,line);
                NizTokena segment(line,'|');
                Message* messagePointer= new Message(segment.tokeni[0],segment.tokeni[1]);
                messagez.push_back(messagePointer);
            }
            file.close();
        }
        else
        {
            cout << "Unsuccesful onening of file " << name+".txt" << endl;
        }
	}
};

class TextChannel
{
	private:
		string name;
		string topic;
		vector<Message*> messagez;
		bool nsfw;
	public:
		TextChannel(string name,string topic="",bool nsfw=false)
		{
			this->name=name;
			this->topic=topic;
			this->nsfw=nsfw;
		}
		bool getNsfw()const {return nsfw;}
		string getTopic()const {return topic;}
		string getName()const {return name;}
		void setTopic(string topic) {this->topic=topic;} //admin
		void setNsfw(bool nsfw) {this->nsfw=nsfw;} //admin
		void setName(string name) {this->name=name;} //admin
};

#endif // CHAT_HPP_INCLUDED
