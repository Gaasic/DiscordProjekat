#ifndef CHAT_HPP_INCLUDED
#define CHAT_HPP_INCLUDED
#include "User.hpp"
#include "Message.hpp"
#include <vector>
#include <fstream>

class Chat
{
protected:
	vector<Message> messagez;
	vector<User> participants;
	string name;
public:
	Chat(User user,User receiver)
	{
		participants.push_back(user);
		participants.push_back(receiver);
		if(user.getTag()<receiver.getTag())
			name=user.getUsername()+" "+receiver.getUsername();
		else
			name=receiver.getUsername()+" "+user.getUsername();
	}
	void addParticipant(User participant)
	{
		if(participants.size()<10)
		{
			participants.push_back(participant);
		}
		else
		{
			cout<< "Maximum number of participants reached."<<endl;
		}
	}
	/*void removeParicipant(User paricipant) //admin
	{

	}*/
	void sendMessage(User user)
	{
		string text;
		cin>>text;
		Message message(text,user.getUsername());
		messagez.push_back(message);

	}
	void loadMessage()
	{
		ifstream file(name+".txt");
        if (file.is_open())
        {
            string text,author,line;
            while(!file.eof())
            {
                getline(cin,line);
                NizTokena segment(line,'|');
                Message message(segment.tokeni[0],segment.tokeni[1]);
                messagez.push_back(message);
            }
            file.close();
        }
        else
        {
            cout << "Unsuccesful onening of file " << name+".txt" << endl;
        }
	}
};

class TextChannel : public Chat
{
	private:
		string topic="";
		bool nsfw="";
	public:
		bool getNsfw()const {return nsfw;}
		string getTopic()const {return topic;}
		void setTopic(string topic) {this->topic=topic;} //admin
		void setNsfw(bool nsfw) {this->nsfw=nsfw;} //admin
};

#endif // CHAT_HPP_INCLUDED
