#include <iostream>
#include <ctime>
using namespace std;
//How much damage 
void rcheck(int r, int &h){
        if(r <=18){ h = h - 6;}
        else if(18<r && r <=32){ h = h - 5;}
        else if(32<r && r <=45){h = h - 4;}
        else if(45<r && r <=58){ h = h - 3;}
        else if(58<r && r <=71){h = h - 2;}
        else if(71<r && r <=85){ h = h - 1;}
        else if(85<r && r <=100){ h = h - 0;}
}
//Monster attack 
void Matk(int &ph){
     int r = rand()%100;
     rcheck(r, ph);

        if(ph <= 0){
cout <<"You are Dead!!" <<endl;
cout <<"***********************************************"<<endl;
    }
        else if(85<r && r <=100){cout << "The Monster missed you"<<endl;
cout <<"***********************************************"<<endl;
        }
        else{
cout << "The Monster have attacked You " << endl;
cout << "Your Health is " << ph <<endl;
cout <<"***********************************************"<<endl;
            }
}
//Player attack
void Monster(string atk, int &mh, int &ph){
    srand(time(0));

        if(mh > 0 && ph > 0){
cout << "Enter atk to attack"<< endl;
cin >>atk;
cout <<"***********************************************"<<endl;
         int r = rand()%100;
        if(atk == "atk"){
        rcheck(r, mh);
        if(85<r && r <=100){
cout <<"Missed!!"<<endl;
cout <<"***********************************************"<<endl;
            Matk(ph);
            Monster(atk, mh, ph);}
        else if(mh >= 1){
            cout << "You have attacked The Monster" << endl;
            cout << "The Monster Health is " << mh <<endl;
cout <<"***********************************************"<<endl;
            Matk(ph);
            Monster(atk, mh, ph);
            }

        else if(mh < 1){
                mh = 0;
                cout << "You have killed the  Monster!!" <<endl;
cout <<"***********************************************"<<endl;
            }
        }
        else if(atk == "off"){
             cout << "Good Bye!"<<endl;
cout <<"***********************************************"<<endl;
        }
        else{
            cout << "You haven't attacked The Monster" << endl;
            cout << "The Monster Health is " << mh <<endl;
cout <<"***********************************************"<<endl;
            Matk(ph);
            Monster(atk, mh, ph);
        }
    }
}


int main()
{
    string atk;
    int ph=100, mh = 100;;
    
    Monster(atk, mh, ph);
    return 0;
}