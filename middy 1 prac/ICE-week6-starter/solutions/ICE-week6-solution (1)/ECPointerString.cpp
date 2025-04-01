#include "ECPointerString.h"
#include <utility> // for std::move
using namespace std;

ECStringPtr::ECStringPtr() : ptr(new string()) {}

ECStringPtr::ECStringPtr(const std::string &strInit) : ptr(new string(strInit)) {}

ECStringPtr::ECStringPtr(const ECStringPtr &rhs) : ptr(new string(*rhs.ptr)) {}

ECStringPtr::ECStringPtr(ECStringPtr &&rhs) 
{
    // this->ptr = std::move(rhs.ptr);
    this->ptr = rhs.ptr;
    rhs.ptr = new std::string();
}

ECStringPtr::~ECStringPtr()
{
    delete ptr;
}

ECStringPtr &ECStringPtr::operator=(const ECStringPtr &rhs)
{
    if (this != &rhs)
    {
        delete ptr;
        ptr = new string(*rhs.ptr);
    }
    return *this;
}


void ECStringPtr::SetString(const std::string &strToSet)
{
    *ptr = strToSet;
}

const std::string *ECStringPtr::GetPtr() const
{
    return ptr;
}


ECStringPtr ECStringPtr::Duplicate() const
{
    string duplicatedStr = *ptr + *ptr;
    return ECStringPtr(duplicatedStr);
}
