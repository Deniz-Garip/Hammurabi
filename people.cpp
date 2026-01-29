#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    const int people =100;
    int busles = 3000;
   int land =1000;
   int farm_up;
   srand(time(0));  
    int starved;
    int peopleleft;
    int a;
    int c;
    

    
    
    
        while (true)
    {
        cout <<"How many busles do you wish to feed your people?"<<endl;
        cin>> a;
        if(busles>=a)
        {
             busles = busles - a;
             cout<<busles<<endl;
           int starved = (people- (a/20));
             peopleleft=(people-starved);
           cout <<starved<<endl<<peopleleft<<endl;
           break;  
        }

         cout<<"Hamurabi: think again. you have only"<<endl<<"3000 buslesof grain"<<endl;
     }   
        
        farm_up= peopleleft *10;
         

        while (true)
        {
            cout<<"How many acres do you wish to plant with seed"<<endl;
            cout<<"An acre of land requires two bushels to plant seed"<<endl;
             cin>>c; 
             if(land>=c)
             {
                  if(farm_up>=c)
                { 
                 
                     if(c>=2)
                  {     
                    cout<<busles<<endl;
                      int bettwen_busles = rand() % 6 + 2;
                     int buslesresult = c+ bettwen_busles;
                     cout<<buslesresult<<endl;
                        busles = busles + buslesresult;
                        cout<<busles<<endl;                  
                     break;
                  } 
               }
             } 
            
            
        }

      cout<<"you starved " << starved<<"people in year"<<endl;
        
        
}