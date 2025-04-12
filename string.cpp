#include <iostream>

//main func

int len(const char *data)
{
    int counter = 0;
    while (data[counter] != '\0') {
        counter++;
    }
    return counter;
}

void strcpy(char* &str, const char *copy) { //copy string
    if(!copy) 
        return;
    
    int newlen = len(copy);
    char* newstr = new char[newlen + 1];

    for(int i = 0; i < newlen; i++) {
        newstr[i] = copy[i];
    }

    newstr[newlen] = '\0';
    delete[] str;
    str = newstr;
}

void strcat(char* &str, const char* cat) {
    int len1 = len(str);
    int len2 = len(cat);
    char* newstr = new char[len1 + len2 + 1];

    for(int i = 0; i < len1; i++) {
        newstr[i] = str[i];
    }

    for(int i = 0; i < len2; i++) {
        newstr[i + len1] = cat[i];
    }

    newstr[len1 + len2] = '\0';

    delete[] str;
    str = newstr;
}

class String {
private:
    char *data;
    int strlen;
public:
    String(const char *d)
    {
        strlen = len(d);
        data = new char[strlen + 1];
        strcpy(data, d);
    }
    String() {
        strlen = 0;
        data = new char[1];
    }

    bool empty() const
    {
        if (!data)
            return true;
        else
            return false;
    }

    void clear()
    {
        delete[] data;
        data = nullptr;
    }

    void resize(int size)
    {
        if(size < 0) return;

        char* newstr = new char[size + 1];

        for(int i = 0; i < size; i++) {
            if(i >= strlen) 
                newstr[i] = ' ';
            else
                newstr[i] = data[i];
        }

        newstr[size] = '\0';

        delete[] data;
        strlen = size;
        data = newstr;
    }


    int countOfElements(const char el) const
    {
        int counter = 0;
        for (int i = 0; i < strlen; i++)
        {
            if (data[i] == el)
                counter++;
        }
        return counter;
    }

    char charAt(const int i) const
    {
        if (i < 0 || i >= strlen)
            return '\0';
        return data[i];
    }

    char find(const char *el, int pos = 0) const
    {
        for (int i = pos; i < strlen; i++)
        {
            if (data[i] == *el)
                return data[i];
            else
                continue;
        }
        return '\0';
    }

    char* reverse()
    {
        char* newstr = new char[strlen + 1];

        for(int i = 0; i < strlen; i++) {
            newstr[i] = data[strlen - i];
        }

        newstr[strlen] = '\0';
        delete[] data;
        data = newstr;
        return data;
    }

    int length() const
    {
        return strlen;
    }

    //================================================operators

    String operator+(const String &str) {
        char* newstr = new char[1];
        strcpy(newstr, data);
        strcat(newstr, str.data);

        return String(newstr);
    }

    bool operator==(const String &str) {
        if(str.length() != length())
            return false;
        
        for(int i = 0; i < str.length(); i++) {
            if(data[i] != str.data[i])
                return false;
        }
        return true;
    }

    bool operator!=(const String &str) {
        if(str.length() == length())
            return false;
        
        for(int i = 0; i < str.length(); i++) {
            if(data[i] == str.data[i])
                return false;
        }
        return true;
    }

    bool operator!() {
        if(!(*data))
            return true;
        return false;
    }

    bool operator>(const String &str) {
        if(length() > str.length())
            return true;
        return false;
    }

    bool operator<(const String &str) {
        if(length() < str.length())
            return true;
        return false;
    }

    bool operator>=(const String &str) {
        if(length() >= str.length())
            return true;
        return false;
    }

    bool operator<=(const String &str) {
        if(length() <= str.length())
            return true;
        return false;
    }

    friend std::ostream &operator<<(std::ostream &os, const String &str) {
        return os << str.data;
    }

    friend std::istream &operator>>(std::istream &is, const String &str) {
        return is >> str.data;
    }

    ~String()
    {
        delete[] data;
    }
};