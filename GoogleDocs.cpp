#include <iostream>
using namespace std;

// Render call
class Data{
public:
    virtual void add(string text) = 0;
    virtual string get() = 0;
};
// Image class : Render
class Image: public Data {
    private:
    string imageUrl;
    public:
    void add(string text){
        this->imageUrl = text;
    }
    string get(){
        return this->imageUrl;
    }
};
// Text class : Render
class Text: public Data{
    private:
    string text;
    public:
    void add(string text){
        this->text = text;
    }
    
    string get(){
        return this->text;
    }
};

// Document class
class Document{
private:
    vector<Data*> data;
public:
    string getAll(){

        string res;
        for(int i = 0; i < data.size(); i++){
            res += data[i]->get();
            res += "\n";
        }

        return res;
    }

    void add(Data* arg){
        data.push_back(arg);
    }
};
int main(){
    Document doc;
    Image image;
    image.add("imageURL");
    doc.add(&image);
    Text text;
    text.add("text here");
    doc.add(&text);

    cout<<doc.getAll()<<endl;
    
}
