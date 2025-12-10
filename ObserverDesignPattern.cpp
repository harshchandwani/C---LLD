#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Observerable interface
class Subject {
public:
    virtual void attach(class Observer* observer) = 0;
    virtual void detach(class Observer* observer) = 0;
    virtual void notify() = 0;
    virtual ~Subject() {}
};

class Observer {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~Observer() {}
};


// Concrete Subject
class NewsAgency: public Subject {
private:
    vector<Observer*> observers;
    string news;
public:
    void attach(Observer* observer) override {
        observers.push_back(observer);
    }
    void detach(Observer* observer) override {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() override {
        for(Observer* observer : observers) {
            observer->update(news);
        }
    }

    void setNews(const string& newsUpdate) {
        news = newsUpdate;
        notify();
    }

};

// Concrete Observer
class GeneralPublic: public Observer {
private:
    string name;
public:
    GeneralPublic(const string& name) : name(name) {}
    void update(const std::string& message) override {
        cout<< name << " received news update: " << message << endl;
    }
};


int main(){
    NewsAgency agency;
    
    GeneralPublic harsh("Harsh");
    GeneralPublic alice("Alice");

    agency.attach(&harsh);
    agency.attach(&alice);

    agency.setNews("news"); // No news yet
    
    // Simulate news update
    agency.detach(&alice);
    agency.setNews("new news"); // Only Harsh should receive the update
}