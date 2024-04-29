#include "spdlog/spdlog.h"

#include "iostream"
#include "State.hpp"
#include "Vertex.hpp"
#include "language.hpp"


// #include "spdlog/include/spdlog/spdlog.h"

// // #include<fmt.less>/
// // #include"Walnut/Core/Log.h"

#define Is_IN(A) ((A) ? "est appartien" : "n'est pas appartien")

int AUTO_MATH(State *state, const char *__str)
{
  
  if(!state) 
  {
    spdlog::critical("The AEF blocked");
    return 0; 
  }
  spdlog::info("__word = {}" , __str);
  
  if (state->Is_Final() && __str[0] == '\0')
    return 1;
  else if (__str[0] != '\0')
    return AUTO_MATH(state->can_move(__str[0]), __str + 1);

  return 0;
}

int main(int argc, char const *argv[])
{



  spdlog::set_pattern("[%H:%M:%S] %^[%l] [%v]%$");
  spdlog::set_level(spdlog::level::debug); // Set global log level to debug


  Language letter , chiffre ; 
  for (char Lmin = 'a' , Lmaj = 'A' , _Nb = '0' ; 
            Lmin != ('z' + 1) ||
            Lmaj != ('Z' + 1) ||
            _Nb != ('9' + 1)
            ;)
  {
    if(Lmin != ('z' + 1 )) letter.insert(Lmin++)  ;
    if(Lmaj != ('Z' + 1)) letter.insert(Lmaj++)  ;
    if(_Nb != ('9' + 1)) chiffre.insert(_Nb++) ;
  }
 
  State Q1("Q1", 0);
  State Q2("Q2", 0);
  State Q3("Q3", 0);
  State Q4("Q4", 1);
  State Q5("Q5", 1);
   
  Q1.push_Vertex(Vertex(&Q2 , letter));
  Q1.push_Vertex(Vertex(&Q3 , chiffre));
  Q3.push_Vertex(Vertex(&Q5 , chiffre )) ; 
  Q5.push_Vertex(Vertex(&Q3 , chiffre )) ;
  Q2.push_Vertex(Vertex(&Q4 , letter/chiffre ));
  Q4.push_Vertex(Vertex(&Q2 , letter/chiffre )) ; 


  int result = AUTO_MATH(&Q1, "2222");
  std::cout << Is_IN(result) << std::endl;

  return 0; 
  
 
 
  return 0;
}