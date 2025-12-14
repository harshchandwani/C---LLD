#include <iostream>
#include <string>
using namespace std;

class Database {
private:
    Database() { /* connect to database */ }
    static Database* instance;
public:
    static Database* getInstance() {
        if (instance == nullptr) {
            instance = new Database();
        }
        return instance;
    }
    void query(string sql) { /* run query */ }
};