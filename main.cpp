#include <iostream>
#include "stdio.h"
#include"Room.h"
#include"Agent.h"
#include"Grue.h"
#include"Player.h"
#include <ctime>
#include "string.h"
#include <string>

using namespace std;



int main()
{
    // ensure different random numbers each time the program is run
       // srand(time(NULL));

    //static maze ,in the north kitchen , east out , west masterbed , south dining room  & the middele or current position hall ;)
        Room  r;
        r.allocate();
        r.setname("HALL");
        r.setdire("middle");
        r.setdesp("no thins just fur rooms with four directions");
        Room kitchen("Kitchen", "You are in the Kitchen. only at south the (HALL)Pots and pans dangle above your head as you look across the room  ",5);
        Room diningRoom("Dining Room", "You are in the Dining Room.only at the north the (HALL),  You see a large table in the center of the room complete with a set of chairs. It seems no one has ate here in quite som time.",5);
        Room out("out", "outDOOR ",5);
        Room masterBed("Master Bed Room", "You are in the Bed Room.only at east the (HALL ) A large Master Bed greets you as you walk into the room. You can see a large master bath as weel in the backround",5);

        r.link(&r,"middel");
        r.link(&kitchen,"north");
        r.link(&diningRoom,"south");
        r.link(&out,"east");
        r.link(&masterBed,"west");
        cout<<"#current position is "<<r.getname()<<" #with direction : "<<r.getdire()<<" #wih descreption : "<<r.getdesp()<<endl;
        cout<<"--->if you want to move to kitchen enter north , master bed enter west , dining room enter south if quit enter quit or east ;)"<<endl;
        string choise="" ;
               cout<<"Your Cuurent position is HALL but please Enter (middle) to start ";
                //by deafult
               Room current = r;
               while  ((choise !="quit"))
               {
                cout<<"Enter your choise please : ";

                cin>>choise;
                cin.clear();
              if (choise  =="middle")
                     r.print();

                cout<<"Enter your choise please : ";
                cin>>choise ;
                cin.clear();
                        if (choise  != "quit"   )
                    {

                       current = *r.getlinked(choise );//to seek at the array ;)
                       current.print();


                    }
                     if ((choise == "quit") ||(choise  == "east") )break;

               }
        cout<<"End Of the maze :D "<<endl;

        //////////////////////////////////////////////////////////////////////////////////////////
        //*******************************************************************************************
        int nAgents;
        cout<<"Enter Number of Agents :";
        cin>>nAgents;
        Agent **agents = new Agent*[nAgents];
            int c;

            string n;


            Room* room = &r ;
            for (int i = 0 ; i < nAgents ; i++){
                cout<<endl<<"Choose Type of Agent :"<<(i+1)<<endl;
                cout<<"(1) Grue.";
                cout<<"(2) Player"<<endl;
                cin>>c;

                switch (c){
                    case 1:

                        n= "Grue";

                        agents[i] = new Grue(n,room);

                        if(agents[i]->act())
                            continue;
                        break;
                    case 2:

                        cout<<"Enter Player Name : ";
                        cin>>n;

                        agents[i] = new Player(n,room);
                        if(agents[i]->act())
                            continue;
                        else
                            cout<<"Thanks For Playing ... :)"<<endl;
                        break;
                    default:
                        cout<<"Enter a Valid choice please !!"<<endl;
                        i--;
                        break;
                    }

            }

                        cout<<"*************************************************************************"<<endl;
                        int play ;
                    for ( int i =0 ; i < nAgents ; i++){
                        cout<<"Choose function : "<<endl;
                        cout<<"(1) Enter Room"<<endl;
                        cout<<"(2) Leave Room"<<endl;
                        cout<<"(3) Display Occupants"<<endl;
                        cout<<"(0) Quit"<<endl;
                        cin>>play ;
                        switch(play){
                        case 0:
                                break;
                            break;
                        case 1:
                           // Room* rr = new Room("TEST","TEST",5);
                           agents[i]->setCurrRoom(&out);
                            agents[i]->getCurrRoom()->enter(agents[i]);
                            break;
                        case 2:
                            agents[i]->getCurrRoom()->leave(agents[i]);
                            break;
                        case 3:
                            agents[i]->getCurrRoom()->printOccupants();
                            break;
                        default:
                            cout<<"Enter a VALID INPUT ..... "<<endl;
                            break ;
                        }
                        cout<<agents[i]->getName()<<" is in Room : "<<agents[i]->getCurrRoom()->getname()<<endl;

                    }

                   /* while(true){
                            for(int i=0 ; i <nAgents; i++){

                                if(agents[i]->act()){
                                    cout<<" NEXT TURN .. : "<<endl;
                                }
                                else{
                                    cout<<"ERROR ... !! "<<endl;
                                }
                            }
                          }*/

return 0 ;
}




