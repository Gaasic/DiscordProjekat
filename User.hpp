#ifndef USER_HPP_INCLUDED
#define USER_HPP_INCLUDED
#include <iostream>

using namespace std;

class User
{
protected:
	string name,lastName,username,email,password;
	int tag;
	static int numberOfUsers;
public:
	User()
	{
		name="";
		lastName="";
		username="";
		tag=++numberOfUsers;
		email="";
		password="";
	}
	User(string name,string lastName,string username,int tag,string email,string password)
	{
		this->name=name;
		this->lastName=lastName;
		this->username=username;
		this->tag=tag;
		this->email=email;
		this->password=password;
		numberOfUsers++;
	}
    void setup() //unos korisnika
    {
    	cout << "First name: ";
    	cin >> name;
    	cout << "Last name: ";
    	cin >> lastName;
    	cout << "Username: ";
    	cin >> username;
    	cout << "Email: ";
    	cin >> email;
    	changePassword();
    }

	string getName()const
	{
		return name;
	}
	string getLastName()const
	{
		return lastName;
	}
	string getUsername()const
	{
		return username;
	}
	int getTag()const
	{
		return tag;
	}
	string getEmail()const
	{
		return email;
	}
    string getPassword()const
    {
        return password;
    }
	void setName(string name)
	{
		this->name=name;
	}
	void setLastName(string lastName)
	{
		this->lastName=lastName;
	}
	void setUsername(string username)
	{
		this->username=username;
	}
	void setTag(int tag)
	{
		this->tag=tag;
	}
	void setEmail(string email)
	{
		this->email=email;
	}
	void changePassword()
	{
		string newPassword;
        cout << "Password:"<<endl;
        cin >> newPassword;
       	password=newPassword;
	}
    friend ostream& operator<<(ostream& output, const User& user)
    {
        output<<user.name<<" "<<user.lastName<<" "<<user.username<<" "<<user.tag<<" "<<user.email<<" "<<endl;
        return output;
    }

};

#endif // USER_HPP_INCLUDED
