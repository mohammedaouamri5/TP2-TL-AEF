

#include "Vertex.hpp"
#include "State.hpp"
#include "iostream"
#include "vector"

Vertex::Vertex( State*p__dis, const Language &p___str) :
    __dis(p__dis),  __str(p___str)
{

}

// Vertex::Vertex(const State  & p__src,State &   p__dis ,const char & p___str ):
//     __src(p__src),  __dis(p__dis),__str(p___str)
// {
// }

State * Vertex::MOVE() const &  
{
    return __dis;
}

bool Vertex::CanGo(const char &p__str) const &
{
    return this->__str.IsIn(p__str);
}

Vertex::operator std::string  () const &
{
    // Custom formatting logic
    std::string result = ("Go to {" + std::string((char *)this->__dis) + "} if w==");
    result+= ((std::string)(this->__str));  
    return result ;
}

Vertex::~Vertex()
{
}
