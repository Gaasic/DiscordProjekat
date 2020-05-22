#ifndef MESSAGE_HPP_INCLUDED
#define MESSAGE_HPP_INCLUDED
#include <iostream>

using namespace std;

#include "Kozuh.hpp"

class Message
{
	private:
		string text;
		string author;
	public:
		Message(string text, string author)
		{
			this->text=text;
			this->author=author;
		}
		string getText()const {return text;}
		string getAuthor()const {return author;}

		void editMessage(string newText)
		{
			text=newText;
		}
		friend ostream& operator<<(ostream& output, const Message& message)
    {
        output<<message.text<<"|"<<message.author<<endl;
        return output;
    }
};
#endif // MESSAGE_HPP_INCLUDED

