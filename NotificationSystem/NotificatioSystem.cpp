#include <iostream>
using namespace std;

/* -----------------------
Notification and Decorator
--------------------------*/
class INotification{
    public:
        virtual string getContent() = 0;
        virtual ~INotification() {};
};

// Concrete Notification: simple text notification
class SimpleNotification: public INotification{
    private:
        string text;
    public:
        SimpleNotification(const string& msg){
            text = msg;
        }

        string getNotification(){
            return text; 
        }
};


class INotificationDecorator()