#ifndef __LANGUAGE__H__
#define __LANGUAGE__H__
#include "iostream"
#include "algorithm"
#include "string"
#include "set"
#include <string>

class Language
{
    std::set<char> info;

public:
    bool IsIn(const char &__word) const;
    Language(const char *__str);
    Language(const std::set<char> &__info);
    Language();

    Language operator|(const Language &other);
    Language operator/(const Language &other);
    Language operator&(const Language &other);

    void insert(const char &__c);
    void erase(const char &__c);

    inline operator std::set<char>() const { return info; }
    inline operator std::string() const
    {
        std::string result = " |";
        for (auto &__c : this->info)
        {
            result.push_back(__c) ; 
            result += std::string("|");
        }
        return result;
    }
    void print(const char *fmt = "\n", ...)
    {

        printf("| ");
        for (auto &&i : this->info)
        {
            printf("%c | ", i);
        }
        printf(fmt);
    }
    // TODO : add a gramemr and AEF and expration
    /*
     * TODO : `bool IsIn(const Word & __word)`
     */
};

#endif