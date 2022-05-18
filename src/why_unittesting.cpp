#include <string>
#include <stdlib.h>
#include <iostream>


enum Emotion{happy, sad};

class IntelligentAgent{
    public:
    std::string name;
    std::string emotion;
    int helpingSkill;
    
    public:
    IntelligentAgent():name("Gerry"), emotion("happy"), helpingSkill(10){
        std::cout << name << " enters the realm.\n";
    }
    IntelligentAgent(std::string name): name(name), emotion("sad"), helpingSkill(10){
        std::cout << name << " enters the realm.\n";
    }

    void express(){
        if(emotion != "happy"){
            std::cout << name << " is sad \n";
        }else{
            std::cout << name << " is happy.\n";
        }
    }

    void help(IntelligentAgent& agent){
        //Look around for people that need help
        // random number between 1 and 100
        if (emotion == "happy"){
            std::cout << name << " is trying to help " << agent.name << "\n";
            if (helpingSkill >= 10){
                std::cout << name << " has the skill for it.\n";
                agent.emotion = "Happy"; //Some mad person with a case sensitive brain wrote this
                //agent.emotion = Emotion.happy //Wanneer levert dit een error op in python?
                std::cout << agent.name << " should be happy now.\n";
            }else{
                std::cout << "I couldn't help " << agent.name << "\n";
            }
        }else{
            std::cout << name << " doesn't want to help " << agent.name << " because he is not happy\n";
        }

    }

};


int main(){
    IntelligentAgent gerry = IntelligentAgent();
    IntelligentAgent bert = IntelligentAgent("Bert");
    IntelligentAgent linda = IntelligentAgent("Linda");
    gerry.express();
    bert.express();
    bert.help(linda);
    gerry.help(bert);
    bert.help(linda);
    return 0;
}
