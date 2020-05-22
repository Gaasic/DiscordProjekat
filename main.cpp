#include <iostream>

using namespace std;

#include "discord.hpp"
#include <windows.h>
int User::numberOfUsers=0;

int main()
{
	Discord discord;
	discord.loadUsers();
	while(1)
    {
        char choice;
        cout<<"Welcome back!"<<endl;
        cout<<"1) Login"<<endl;
        cout<<"2) Register"<<endl;
        cout<<"3) Exit"<<endl;
        cout<<"->";
        cin>>choice;
        switch(choice)
        {
        case 1:
            {
               // User* user=discord.login();
                break;
            }
        case 2:
            {
                /*discord.signUp();*/
            }
        case 3:
            {
                cout<<"cao";
                return 0;
            }

        }
    }
	return 0;
}
