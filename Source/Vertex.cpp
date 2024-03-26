

#include "Vertex.hpp"
#include "State.hpp"
#include "iostream"
#include "vector"

Vertex::Vertex( State*p__dis, const char &p___str) :
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
    return p__str == this->__str;
}

Vertex::operator const char *() const &
{
    // Custom formatting logic
    std::string result = ("Go to {" + std::string((char *)this->__dis) + "} if w==");
    switch (this->__str)
    {
    case '\0' /* constant-expression */:
        result.append("eps");
        break;
    case '\n' /* constant-expression */:
        result.append("\\n");
        break;

    case '\r' /* constant-expression */:
        result.append("\\r");
        break;

    default:
        break;
    }
    return result.c_str();
}

Vertex::~Vertex()
{
}
