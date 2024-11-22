#include "spdlog/spdlog.h"

#include "iostream"
#include "State.hpp"
#include "Vertex.hpp"
#include "language.hpp"
#include <string>
#include <vector>


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
 
  std::vector<State*> Q(7) ;
  for (int i = 0 ; i < 7 ; i++)
  {
    Q[i] = new State(std::to_string(i).c_str(), int(i == 6)) ;
  }


  Q[0]->push_Vertex(Vertex(Q[1], letter));
  Q[1]->push_Vertex(Vertex(Q[1], letter/chiffre));
  Q[1]->push_Vertex(Vertex(Q[2], "@"));
  Q[2]->push_Vertex(Vertex(Q[2], letter));
  Q[2]->push_Vertex(Vertex(Q[3], "."));
  Q[3]->push_Vertex(Vertex(Q[4] , "c" )); 
  Q[4]->push_Vertex(Vertex(Q[5] , "o" )); 
  Q[5]->push_Vertex(Vertex(Q[6] , "m"));

  

  std::string __input; 
  printf("Input : ");
  std::getline(std::cin, __input);
  int result = AUTO_MATH(Q[0], __input.c_str());
  std::cout << Is_IN(result) << std::endl;

  return 0; 
  
 
 
  return 0;
}
