
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

class MediaCatalog {
public:
    ... // TODO: add methods

private:
    ... // TODO: add private members
};

#endif
