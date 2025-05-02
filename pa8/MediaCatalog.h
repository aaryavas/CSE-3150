
#ifndef MEDIACATALOG_H
#define MEDIACATALOG_H

#include <string>
#include <map>
#include <memory>

class Media {
public:
    Media(std::string title, double price);
    virtual ~Media() = default;
    std::string getTitle() const;
    double getPrice() const;

private:
    std::string title;
    double price;
};

using namespace std;
class MediaCatalog {
public:
    // TODO: add methods
    //we want to return a single thing
    static MediaCatalog& getInstance();

    bool addMedia(const string& title, shared_ptr<Media>); //add method
    
    bool removeMedia(const string& title);
    bool isAvailable(const string& title) const;
    shared_ptr<Media> getMedia(const string& title);
    
private:
    // TODO: add private members
    MediaCatalog();//default constructor
    ~MediaCatalog(); //destructor
    map<string, shared_ptr<Media>> inventory; //map for storing the media type and how much of that media type inventory is there
    //one instance so we need to remove the copy costructors and operators
    MediaCatalog(const MediaCatalog &other) = delete;
    MediaCatalog& operator=(const MediaCatalog &other) = delete;



};

#endif
