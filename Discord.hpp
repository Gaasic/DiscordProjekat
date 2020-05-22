#ifndef DISCORD_HPP_INCLUDED
#define DISCORD_HPP_INCLUDED
#include <iostream>

using namespace std;

#include "Server.hpp"
class Discord
{
private:
	vector<User*> users;
	vector<Server> servers;
	string serverFile;
	string usersFile;
public:
	Discord(string serversFile="servers.txt",string usersFile="users.txt")
	{
		this->serverFile=serverFile;
		this->usersFile=usersFile;
		loadUsers();
        //loadServers();
	}
	User* login()
    {
    	while(1)
    	{
        	string username,password;
        	cout << "Username:";
        	cin >> username;
        	cout << "Passowrd:";
        	cin >> password;
        	for(auto i=users.begin();i!=users.end();i++)
        	{
           	 	if(((*i)->getUsername())==username && ((*i)->getPassword())==password)
            	{
                	cout << "Login succesful!\n";
                	return *i;
            	}
        	}
        	cout << "Unsuccesful login. Try again.\n";
    	}
	}
	void signUp()
    {
        User* userPointer=new User;
        userPointer->setup();
        users.push_back((User*)userPointer);
    }

	void loadUsers()
    {
        ifstream file(usersFile);
        if (file.is_open())
        {
            string name,lastName,username,email,password;
            int tag;
            while(!file.eof())
            {
                file>>name>>lastName>>username>>tag>>email>>password;
                if(file.eof()) break;

                    User* userPointer=new User(name,lastName,username,tag,email,password);
                    users.push_back(userPointer);
            }
            file.close();
        }
        else
        {
            cout << "Unsuccesful onening of file " << usersFile << endl;
            saveUsers();
        }
    }
    void saveUsers()const
    {
        ofstream file(usersFile);
        for(auto i=users.begin();i!=users.end();i++)
        {
            file<<(*i)->getName()<<" ";
            file<<(*i)->getLastName()<<" ";
            file<<(*i)->getUsername()<<" ";
            file<<(*i)->getTag()<<" ";
            file<<(*i)->getEmail()<<" ";
            file<<(*i)->getPassword()<<" ";
        }
        file.close();
    }

}
#endif // DISCORD_HPP_INCLUDED
