//so lets say someone is logged in to slack from multiple devices and whenver a messages comes 
// all the devices has to sent notification
// another example could be we have whatsapp group so whenver a message comes all the group members has to be notified


#include<bits/stdc++.h>
using namespace std;

class ISubscriber{
    public:
        virtual void notify(string msg) =0;

};
class User: public ISubscriber{
    private: 
        int userId;
    public: 
        User(int userId){
            this->userId = userId;
        }
        void notify(string msg){
            cout<<"User "<<userId<<" received msg "<<msg<<endl;
        }
};
class Group{
    private:
        list<ISubscriber*>users;
    public:
        void subscribe(ISubscriber * user){
            users.push_back(user);
        }
        void unsubscribe(ISubscriber*user){
            users.remove(user);
        }
        void notify(string msg){
            for(auto user: users){
                user->notify(msg);
            }
        }
};

int main(){
    Group* group = new Group;
    User* user1 = new User(1);
    User* user2 = new User(2);
    User* user3 = new User(3);
    group ->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);
    group->notify("new msg");
    group->unsubscribe(user1);
    group->notify("new message");
    return 0;
}