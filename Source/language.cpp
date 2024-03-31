

#include"language.hpp"
#include"string.h"
#include"malloc.h"

bool Language::IsIn(const char &  __word ) const {

    return this->info.find(__word) != this->info.end(); 
} 

void Language::insert(const char & __c){
    info.insert(__c);
} 
 
void Language::erase(const char & __c){
    info.erase(__c);
} 
 


Language::Language(const char *  __str) {

    for(int i = 0 ; __str[i] != '\0' ; i++)
        info.insert(__str[i]);       

}
Language::Language(const std::set<char> & __info): 
    info(__info) {} 

Language::Language() {
    this->info = {}; 
} 
 


Language Language::operator|(const Language & other ){
    std::set<char> result = {};
    std::set_union(other.info.begin(), other.info.end(),
                   this->info.begin(), this->info.end(),        
                   std::inserter(result, result.begin()));

}

Language Language::operator/(const Language & other ){
    std::set<char> result = {};
    
    std::set_union(other.info.begin(), other.info.end(),
                   this->info.begin(), this->info.end(),        
                   std::inserter(result, result.begin()));
    return Language(result);
}
Language Language::operator&(const Language & other ){
    std::set<char> result = {};
    std::set_union(other.info.begin(), other.info.end(),
                   this->info.begin(), this->info.end(),        
                   std::inserter(result, result.begin()));
}
