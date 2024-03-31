
#ifndef __STATE_H_
#define __STATE_H_

#include "iostream"
#include "vector"
#include <string>
#include <cstring>
// #include "Vertex.hpp"

class Vertex;

class State
{
private:
    char *name;
    std::vector<Vertex> vertex;
    bool finel;
    // State *next_state = NULL;
public:
    // State(const char *p_name, std::vector<Vertex> p_vector);
    
    
    /**
     * p_finel = false
     */
    State(const char *p_name, bool p_finel = false);
    bool Is_Final() const &;

    explicit operator const char *() const & {
        return this->name ;
    }

    // State * MOVE()  ;
    State *can_move(const char __str) const &;

    State* push_Vertex(const Vertex &new__vertex);
    inline bool operator==(const State &other) const &
    {

        return !std::strcmp(other.name, this->name);
    }
    //  other.__str ==

    int RUN(const char &__str);
    ~State();
};

#endif