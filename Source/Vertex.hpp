

#ifndef __VECTOR_H_
#define __VECTOR_H_

// #include "Node.hpp"
#include "State.hpp"
#include "language.hpp"
class State;

enum Equel
{
    Equel__src = 1 << 1,
    Equel__dis = 1 << 2,
    Equel__str = 1 << 3,
};

class Vertex
{
private:
    // State __src;
    State * __dis = NULL;

public:
    Language __str;

    Vertex(State*p__dis, const Language  &p___condition);
    bool CanGo(const char &__str) const &;
    State* MOVE() const &  ;

 
    operator std::string () const &;
 
    // inline bool operator==(const Vertex &other) const & {
    //     return (
    //         // Equel__src * (this->__src == other.__src) |
    //         // Equel__dis * (this->__dis == other.__dis) |
    //         Equel__str * (this->__str == other.__str));
    //     //  other.__str ==
    // }


    // friend std::ostream &operator<<(std::ostream &os, const Vertex &vertex);
    ~Vertex();
};

#endif