/*Game 1: [Game name], which is an text-based RPG(role playing game)
with an good storyline.
The narrator is Eva the retired adventure guide, Who is trying to save the prince from the cursed dragon*/
#include<iostream>
#include<string>  //for strings based functions
#include<unistd.h> //for sleep function
#include<random>  //for random numbers(used in attack and defense)
using namespace std;
int phealth=100;
  string name;
  int main();
class game{   //parent class which has main logic for the game
  public:
  char c;
  void start(){   //function which starts the game storyline
    cout<<"Eva: The prince is in very bad condition we need your help!"<<endl; sleep(2);
    cout<<"Eva: Your main objective is to bring back the healing crystal from the cursed dragon cave "<<endl;
    sleep(2);   //sleep function to add delay which increases the game experience
    cout<<"Eva: Only the healing crystal can save the prince"<<endl; sleep(2);
    cout<<"Eva: To enter the cave , you need to kill the guards and then kill the dragon "<<endl; sleep(3);
    cout<<"Narrator: Now you have reached the cave where dragon and healing crystal are located "<<endl; sleep(3);
    cout<<"Narrator: First you need to defeat the guards "<<endl; sleep(5);
  }
  void attack(int &ehealth, int min, int max){   //the main logic for attack and defense in the game
    while( (phealth >0)&&(ehealth>0) ){  
     cout<<"Press 'E' to attack the enemy, or press 'D' to defend "<<endl;
     cin>>c;
     if(c=='E'|| c=='e'){
         ehealth-=rand() % (25 - 10 + 1) + 10;
         phealth-=rand() % (5-0+1)+0;
         cout<<"Your health is: "<<phealth<<endl;
         cout<<"Enemy's health is: "<<ehealth<<endl;
     }
     else if(c=='D' || c=='d'){
         phealth-=rand() % (max-min+1)+min;
         ehealth-=rand() % (5 - 0 + 1) + 0;
         cout<<"Your health is: "<<phealth<<endl;
         cout<<"Enemy's health is: "<<ehealth<<endl;
     }
     else {
    cout << "Invalid choice! Press 'E' or 'D' only." << endl;
}
  }
  }
void end(){ int h;
    if(phealth>0){
  cout << "Congratulations, " << name << "! You've gained the healing crystal!" << endl;sleep(2); //congratulation message
  cout<<"Eva: You have defeated the enemy "<<endl;sleep(2);
  cout<<"Eva: Next level is comimg soon "<<endl; sleep(2);
  cout<<"Eva: Meet you soon "<<endl; sleep(2);
  cout<<"Eva: Good luck "<<name<<endl;sleep(2);
    cout<<"Press 1 to play again or 2 to exit: "<<endl; cin>>h;
    if(h==1){
      main();
    }
    else{
      exit(0);
    }}
  else{
    cout << "Game Over! You have been defeated by the enemy." << endl;sleep(3); //game over message
    cout<<"Press 1 to play again or 2 to exit: "<<endl; cin>>h;
    if(h==1){
      main();
    }
    else{
      exit(0);
    }
  }
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
         cout<<"Goblin: You fool, you dare to challenge me? "<<endl; sleep(2);
         cout<<"Goblin: You will never reach the master"<<endl; sleep(2);
         attack(health,0,10);
    }  
};
class lv2:public game{  //child class to store level 2 enemy details 
    int health;
     public: lv2(){
        health=80;
    }
    void echa(){
        cout<<"Narrator: Now you have defeated the goblins "<<endl; sleep(3);
        cout<<"Narrator: Now you need to kill the dragon to aquire the healing crystal"<<endl; sleep(3);
        cout<<"Narrator: As you go deeper into the cave , the strong aura of the dragon grows "<<endl; sleep(3);
        cout<<"Narrator: You stand in front of the dragon and your job is to kill him and acquire the crystal "<<endl; sleep(5);
        cout<<"Dragon stares at you and starts to talk to you! "<<endl; sleep(2);
         cout<<"Dragon: Ohh! you passed thorugh the gate keeper, "<<name<<endl; sleep(2);
         cout<<"Dragon: You are execptionally good"<<endl; sleep(2);
         cout<<"Dragon: You think you can defeat me?"<<endl; sleep(2);
         cout<<"Dragon: Here is the final challenge, Defeat me and take that crystal"<<endl; sleep(2);
         attack(health,10,25);
    }  
};
int main(){    //main funtion to start the game
    player p;
    p.cha();
    p.start();
    {lv1 e;     //bloks{} for optimal usage of memory 
    e.echa();}
    {lv2 e;
    e.echa();}
    p.end();
    return 0;
}
