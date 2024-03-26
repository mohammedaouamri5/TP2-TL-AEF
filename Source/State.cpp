#include"State.hpp"
#include"Vertex.hpp"
#include "spdlog/spdlog.h"
 
State::State(const char * p_name ,bool p_finel )
{
    spdlog::info("CREAT STATE [{}]{}" ,
    p_name , 
    p_finel ? " IS_FINAL" : ""
    )
    ;

    this->finel =  p_finel;
    // this->type
    name = (char*) malloc(strlen(p_name)) ;
    strcpy(this->name , p_name); 
    
}

bool State::Is_Final() const & {
    return this->finel;
}

// State State::MOVE(const char __str)   {
//     for(const auto & _ : this->vertex){
//         if(_.CanGo(__str))
//         {
             
//             return _.MOVE() ;
//         }
//     }
// }

State * State::can_move(const char __str) const & {
    for(const auto & _ : this->vertex){
        if(_.CanGo(__str))
        {
            State * next =_.MOVE() ; 
            if(!next ) {
                spdlog::critical("[NEXT IS NULL]");
            } 
            spdlog::info("[MOVE TO {}]" , (const char*)(*next));
            return _.MOVE() ;
        }
    }
    return NULL;
}



void State::push_Vertex(const Vertex &  new__vertex  ) {
    // printf("WOW");
    spdlog::info("CREAT LINK FROM [{}] TO [{}] IF [{}]" ,
    (const char*)(*this),
    (const char*)(*(new__vertex.MOVE())),
    char( new__vertex.__str)  
    );
// spdlog::info("CREAT FROM [{}] TO [{}] IF [{}]" ,
//     (const char*)(new__vertex)  
//     );


    this->vertex.push_back(new__vertex);

}

State::~State()
{
    free(name); 
}
// int State::RUN(const char & __str, State & TheState){
//     for(const auto & _ : this->vertex) 
//         if(_.CanGo( __str))
//             TheState = _.MOVE()
// }