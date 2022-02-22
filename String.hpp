//
//  String.hpp
//  String
//
//  Created by Артур Данилов on 22.02.2022.
//

#ifndef String_hpp
#define String_hpp

#include <iostream>

class String
{
    protected:

        char* data;
        size_t length;

    public:

        void append(const char* str);
        void append(const char symbol);
        size_t size() {return length;}
        const char* c_str() {return  data;}

        String(const int& s = 0);
        String(const char* txt);
        ~String();

        char& operator[] (const int index) {return data[index];}
        const char& operator[] (const int index) const {return data[index];}
        String& operator= (const char* txt);
        
        friend std::ostream& operator<< (std::ostream& out, const String& txt);
        friend std::istream& operator>> (std::istream& in, String& txt);
        friend bool operator== (const String& left, const String& right);
        friend bool operator!= (const String& left, const String& right);
};

#endif // String_hpp 
