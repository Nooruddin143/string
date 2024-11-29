//
//  string.cpp
//  String
//
//  Created by Nooruddin Mohammadi on 10/25/24.
//
#include "string.h"
#include <cstring>
namespace String
{
string::string()
{
    cout << "Constructing empty string" << endl;
    len = 0;
    buffer = nullptr;
}
string::string(const char s[])
{
    
    cout << "Constructing \"" << s << "\"" << endl;
    len = strlen(s);
    if (len > 0)
    {
       buffer = new char[len];
       for (int i = 0; i < len; i++)
       {
          buffer[i] = s[i];
       }
    }
    else
    {
       buffer = nullptr;
    }
}
//
////big 3
string::string(const string& other)
{
    cout << "Copying \"" << other << "\"" << endl;
    len = other.len;
    if (len > 0)
    {
        buffer = new char[len];
        for (int i = 0; i < len; i++)
        {
            buffer[i] = other.buffer[i];
        }
    }
    else
    {
        buffer = nullptr;
    }
}
string& string::operator=(const string& other)
{
    cout << "Assigning \"" << other << "\" to \"" << *this << "\"" << endl;
    if (this != &other)
    {
        delete[] buffer;
        len = other.len;
        if (len > 0)
        {
            buffer = new char[len];
            for (int i = 0; i < len; i++)
            {
                buffer[i] = other.buffer[i];
            }
        }
        else
        {
            buffer = nullptr;
        }
    }
    return *this;
}
string::~string()
{
    cout << "Destroying \"" << *this << "\"" << endl;
    delete[] buffer;
}


int string::length() const
{
    return len;
}

//subject to change
int string::size() const
{
    int size = 0;
    for (int i = 0; i < strlen(buffer); ++i) {
        size++;
    }
    return size;
}
char& string::operator[](int i)
{
    return buffer[i];
}

const char& string::operator[](int i) const
{
    return buffer[i];
}

string string::operator+(const string& other) const
{
    string result;
    result.len = len + other.len;
    result.buffer = new char[result.len];
    for (int i = 0; i < len; i++)
    {
        result.buffer[i] = buffer[i];
    }
    for (int i = 0; i < other.len; i++)
    {
        result.buffer[len + i] = other.buffer[i];
    }
    return result;
}
string string::operator+(const char& ch) const
{
    string result;
    result.len = len + 1;
    result.buffer = new char[result.len];
    for (int i = 0; i < len; i++)
    {
        result.buffer[i] = buffer[i];
    }
    //for (int i = 0; i < result.len; i++)
    //{
        result.buffer[len] = ch;
    //}
    return result;
}

bool string::operator==(const string& other) const
{
    if (len != other.len) { return false; }
    for (int i = 0; i < len; i++)
    {
        if (buffer[i] != other.buffer[i]) { return false; }
    }
    return true;
}
int string::find(const char* s, int pos) const
{
    for (int i = pos; i < len; ++i)
    {
        if (buffer[i] == s[0])
        {
            int j = 0;
            while (s[j] != '\0' && (i + j) < len && buffer[i + j] == s[j])
            {
                ++j;
            }
            if (s[j] == '\0')
            {
                return i;
            }
        }
    }
    return -1;
}

void string::print(ostream& out) const
{
    for (int i = 0; i < len; i++)
    {
        out << buffer[i];
    }
}

ostream& operator<<(ostream& out, const string& str)
{
    str.print(out);
    return out;
}
istream& operator>>(istream& in, string& str)
{
    str = "";
    char c;
    while (in.get(c) && c != ' ')
    {
        str = str + c;
    }
    return in;
}
bool operator!=(const string& s, const string& t)
{
    return !(s == t);
}
bool operator>(const string& lhs, const string& rhs)
{
    int minLength;
    if (lhs.size() < rhs.size())
    {
        minLength = lhs.size();
    }
    else
    {
        minLength = rhs.size();
    }
    for (int i = 0; i < minLength; ++i)
    {
        if (lhs[i] > rhs[i])
        {
            return true;
        }
        else if(lhs[i] < rhs[i])
        {
            return false;
        }
    }
    return lhs.size() > rhs.size();
}
         
}
