//
//  String.cpp
//  String
//
//  Created by Артур Данилов on 22.02.2022.
//

#include "String.hpp"

String::String(const int& s)
{
    if (s)
    {
        this->data = new char[s];
    }

    else
    {
        this->data = nullptr;
    }

    this->length = s;
}

String::String(const char* txt)
{
    size_t s = strlen(txt);

    this->data = new char[s];
    this->length = s;

    strcpy(this->data, txt);
}

String::~String()
{
    delete [] this->data;
}

void String::append(const char *str)
{
    size_t s = strlen(str);
    
    if (!this->length)
    {
        this->data = new char[s];
        this->length = s;
        
        strcpy(this->data, str);
    }
    
    else
    {
        char* buf = new char[this->length];
        strcpy(buf, this->data);
        
        this->length = this->length + s;
        this->data = new char[this->length];
        strcat(this->data, buf);
        strcat(this->data, str);
        
        delete [] buf;
    }
}

void String::append(const char symbol)
{
    if (!this->length)
    {
        this->data = new char[1];
        this->length = 1;
        
        this->data[0] = symbol;
    }
    
    else
    {
        char* buf = new char[this->length];
        strcpy(buf, this->data);
        
        this->length++;
        this->data = new char[this->length];
        
        strcpy(this->data, buf);
        
        this->data[this->length - 1] = symbol;
        
        delete [] buf;
    }
}

std::ostream &operator<<(std::ostream &out, const String &txt)
{
    out << txt.data;

    return out;
}

std::istream &operator>>(std::istream &in, String &txt)
{
    char buf[50000];
    gets(buf);

    size_t s = strlen(buf);
    txt.length = s;
    txt.data = new char[s];

    strcpy(txt.data, buf);

    return in;
}

bool operator== (const String& left, const String& right)
{
    if (!strcmp(left.data, right.data))
        return true;
    
    return false;
}

bool operator!= (const String& left, const String& right)
{
    if (strcmp(left.data, right.data) != 0)
        return true;
    
    return false;
}

String& String::operator=(const char *txt)
{
    size_t s = strlen(txt);
    this->length = s;
    this->data = new char[s];

    strcpy(this->data, txt);

    return *this;
}

