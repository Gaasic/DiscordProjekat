#include <iostream>

using namespace std;

#include "discord.hpp"
#include <windows.h>
int User::numberOfUsers=0;

int main()
{
    Discord discord;
    discord.loadUsers();
    bool isLoggedIn=false;
    char choice;
    while(1)
    {
    User* user;
    while(!isLoggedIn)
    {
        cout<<"Welcome back!"<<endl;
        cout<<"1) Login"<<endl;
        cout<<"2) Register"<<endl;
        cout<<"3) Exit"<<endl;
        cout<<"->";
        cin>>choice;
        switch(choice)
        {
        case '1':
            {
                user=discord.login();
                isLoggedIn=true;
                break;
            }
        case '2':
            {
                discord.signUp();
                break;
            }
        case '3':
            {
                cout<<"cao";
                return 0;
            }

        }
    }
    while(isLoggedIn)
    {
        cout<<"Discord"<<endl;
        cout<<"1) DM someone"<<endl;
        cout<<"2) Server someone"<<endl;
        cout<<"3) Log out"<<endl;
        cout<<"4) Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
        case '1':
            {
                int receiverTag;
                discord.listUsers(user->getTag());
                cin>>receiverTag;
                User* receiver=discord.findUserByTag(receiverTag);
                if(receiver==NULL)
                {
                    cout<<"No users with that tag"<<endl;
                    break;
                }
                Chat chat(user,receiver);
                chat.loadMessages();
                chat.printDM();
                bool inChat=true;
                while(inChat)
                {
                    cout<<"1) Send message\n2) Back\n->";
                    cin>>choice;
                    switch(choice)
                    {
                    case '1':
                        {
                            chat.sendMessage();
                            chat.printDM();
                            fflush(stdin);
                            break;
                        }
                    case '2':
                        {
                            inChat=false;
                            break;
                        }
                    }
                }
                chat.saveMessages();
                break;
            }
        case '2':
            {

            }
        case '3':
            {
                isLoggedIn=false;
                break;
            }
        case '4':
            {
                return 0;
            }
        }
    }

    }
}
