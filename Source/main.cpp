#include "spdlog/spdlog.h"

#include "iostream"
#include "State.hpp"
#include "Vertex.hpp"
// #include "spdlog/include/spdlog/spdlog.h"

// // #include<fmt.less>/
// // #include"Walnut/Core/Log.h"

#define Is_IN(A) ((A) ? "est appartien" : "n'est pas appartien")

int AUTO_MATH(State*state, const char *__str)
{ 


  if (state->Is_Final() && __str[0] == '\0')
      return 1;
    else if( __str[0] != '\0')
        return AUTO_MATH(state->can_move(__str[0]), __str + 1);

  return 0;
}

int main(int argc, char const *argv[])
{

  // printf("WOW");
  spdlog::set_pattern("[%H:%M:%S] %^[%l] [%v]%$");

  // State
  State Q0("0", 0);
  State Q1("1", 0);
  State Q2("2", 0);
  State Q3("3", 1);

  // spdlog::info("test logger {}", (char *)Q1);

  Vertex Q0Q11(&Q1, '1');
  Vertex Q1Q01(&Q0, '1');
  Vertex Q2Q31(&Q3, '1');
  Vertex Q3Q21(&Q2, '1');

  Vertex Q0Q10(&Q1, '0');
  Vertex Q1Q00(&Q0, '0');
  Vertex Q2Q30(&Q3, '0');
  Vertex Q3Q20(&Q2, '0');
  // // Q3Q20

  Q0.push_Vertex(Q0Q11);
  Q0.push_Vertex(Q0Q10);
  Q1.push_Vertex(Q1Q01);
  Q1.push_Vertex(Q1Q00);
  Q2.push_Vertex(Q2Q31);
  Q2.push_Vertex(Q2Q30);
  Q3.push_Vertex(Q3Q21);
  Q3.push_Vertex(Q3Q20);

  int result = AUTO_MATH(&Q2,"0");
  std::cout << Is_IN( result) << std::endl ;
  return 0;
}