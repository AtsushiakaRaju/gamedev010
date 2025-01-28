/*Game 1: [Game name], which is an text-based RPG(role playing game)
with an good storyline.
The narrator is Eva the retired adventure guide, Who is trying to save the prince from the cursed dragon*/
#include<iostream>
#include<string>  //for strings based functions
#include<unistd.h> //foe sleep function
#include<random>  //for random numbers(used in attack and defense)
using namespace std;
class game{   //parent class which has main logic for the game
  public:
  int phealth;
  string name;
  char c;
  game(){
      phealth=100;  //health of the player
  }
  void start(){   //function which starts the game storyline
    cout<<"Eva: The prince is in very bad condition we need your help!"<<endl; sleep(2);
    cout<<"Eva: Your main objective is to bring back the healing crystal from the cursed dragon cave "<<endl;
    sleep(2);   //sleep function to add delay which increases the game experience
    cout<<"Eva: Only the healing crystal can save the prince"<<endl; sleep(2);
    cout<<"Eva: To enter the cave , you need to kill the guards and then kill the dragon "<<endl; sleep(2);
  }
  void attack(int &ehealth){   //the main logic for attack and defense in the game
    while( (phealth >0)&&(ehealth>0) ){  
     cout<<"Press 'E' to attack the enemy, or press 'D' to defend "<<endl;
     cin>>c;
     if(c=='E'|| c=='e'){
         ehealth-=rand() % (25 - 10 + 1) + 10;
         cout<<"Your health is: "<<phealth<<endl;
         cout<<"Enemy's health is: "<<ehealth<<endl;
     }
     else if(c=='D' || c=='d'){
         phealth-=rand() % (10-0+1)+0;
         cout<<"Your health is: "<<phealth<<endl;
         cout<<"Enemy's health is: "<<ehealth<<endl;
     }
     else {
    cout << "Invalid choice! Press 'E' or 'D' only." << endl;
}

  }
  cout << "Congratulations, " << name << "! You've defeated the Goblin!" << endl;sleep(2); //congratulation message
  cout<<"Eva: You have killed the enemy "<<endl;sleep(2);
  cout<<"Eva: Next level is comimg soon "<<endl; sleep(2);
  cout<<"Eva: Good luck "<<name<<endl;
  }
};
class player:public game{          //child class to sotre player's details
    public:   
    void cha(){
        cout<<"Game started"<<endl; sleep(2);
         cout<<"Eva: What should I call you master? "; 
        cin>>name;
        cout<<"Eva: Hello, "<<name<<endl;sleep(2);
        cout<<"Eva: Your health is: "<<phealth<<endl; sleep(2);
    }  
};
class lv1:public game{  //child class to store level 1 enemy details 
    int health;
     public: lv1(){
        health=50;
    }
    void echa(){
         cout<<"Goblin: I never expected you would come here, "<<name<<endl; sleep(2);
         cout<<"Goblin: You bastard !"<<endl; sleep(2);
         cout<<"Goblin: You will never reach the master"<<endl; sleep(2);
         attack(health);
    }  
};
int main(){    //main funtion to start the game
    player p;
    p.cha();
    p.start();
    {lv1 e;
    e.echa();}
    return 0;
}