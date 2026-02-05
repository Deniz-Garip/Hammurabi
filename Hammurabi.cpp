#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

 int people =100;
 int busles = 3000;
 int land =1000;

  class bushels
    {
         private:
        
        int feed;
        int harvest;
        int price;
        int landbusles;
        int bettwen_busles;   
        public: 
        
        void printbushels()
        {
            cout<< "You now have "<<busles<<" bushesl in store"<<endl;
        }

        void getfeed()
        {   
            
            cin>>feed;
        
        }
        void getharvest()
        {
            cin>>harvest;
        }
        int feedoutput()
        {
            return feed;
            
        }

        int harvestoutput()
        {
             return harvest;
        }
        
    
        int landprice()
        {
           return price = rand() % 26 + 17; // it was not work sometimes they gave 34 like that 
        }

        

        int buslesbettwehn()
        {
            return bettwen_busles = rand() % 6 + 2;
        }
        void printbuslesbettwen()
        {
            cout <<"You harvested "<<buslesbettwehn()<<" bushels per ace"<<endl;
        }

    };
 

class People
{
    private:
     
    int peopleleft =0;
    int died;
    int immigrants;
    

    public:

    void printpeople()
    {
        cout<<"Population is now " <<people<<endl;
    }

    int starved()
    {   
        bushels b;
       

        while (true)
        {
            cout <<"How many busles do you wish to feed your people?"<<endl;

            b.getfeed(); 
            if(busles>=b.feedoutput())
            {

                died=(people-(b.feedoutput()/20));

                break;
            }
            cout<<"Hamurabi: think again. you have only"<<endl <<busles<<" busles of grain"<<endl;
 
        }
        
    }

    int peopledied()
    {
        return died;
    }

   

    int  inputpeopleleft()
    {
           return people=(people-died);
            
    }
    void outputpeopleleft()
    {
        cout<<people<<endl;
    }

    int immigrant() // I will check
    {
        People p;

        if(3020>=busles)
        {
            int d = busles -3000;
            int f = d /20;

            return people = f + people;
        }
    }

   
};
    class Land
    {
       private:
        int land = 1000;
        int farm_up;
        string input;

        public: 
         
        void getland()
        {
            cout<< "The city own now " <<land<<endl;
            
        }

        void getdata()  // i will check this
        {
            cin>>input;
        }

        string landdata() // i will check this
        {
            return input;
        }

        int limitfarm_up()
        {
            People p;

            cout<<people<<endl;
            return farm_up = people *10; // I will check
        }
        
        int intputland()
        {
            bushels b;

            
            while (true)
            {
                cout<<"Land is trading at "<<b.landprice() <<" bushels per ace"<<endl;
                cout<<"How many acres do you wish to buy? Yes or No"<<endl;
                    cin>>input; 
                    
                if(input == "yes" || input == "Yes") // you need the change or because it is wrong i thinks so it is correct
                {   
                    b.getfeed();

                    
                    
                    if(b.feedoutput()>=b.landprice())
                    {
                         int result= b.feedoutput()/b.landprice();
                         return busles = busles - b.feedoutput();
                         return land = land + b.landprice();
                         break;

                    }

                }

                else if (input == "no" || input == "No")
                {
                    break;
                }
                
            }
            
        }

         int harvests() //there is a problem in here you need the change
        {
            Land l;
            bushels b;
            
            while (true)
        {
            cout<<"How many acres do you wish to plant with seed"<<endl;
            cout<<"An acre of land requires two bushels to plant seed"<<endl;
             b.getharvest();
             if(land>=b.harvestoutput())
             {
                cout<<"working"<<endl;
                  if(l.limitfarm_up()>= b.harvestoutput())
                { 
                    cout<<"working"<<endl;
                     if(b.harvestoutput()>=2)
                  {     
                    cout<<"working"<<endl;
                    cout<<busles<<endl;
                      
                     int buslesresult = b.harvestoutput() + b.buslesbettwehn();
                     cout<<buslesresult<<endl;
                      return  busles = busles + buslesresult;
                        cout<<busles<<endl;                  
                     break; 
                  } 
               }
             } 
            
            
        }
        }

    
    };

    class Start
    {
private:
        People p;
        Land l;
        bushels b;

public:
    void play()
    {
       p.printpeople();
       l.getland();
       b.printbuslesbettwen();
       b.printbushels();
       l.intputland();
       p.starved();
       p.inputpeopleleft();
       p.outputpeopleleft();
       l.limitfarm_up();

       l.harvests();

       if(p.peopledied()>=45)
       {
         cout<< "You starved "<<p.peopledied()<<" people in one year!!!"<<endl;// you need to put a year in here
         cout<<"Due to this exterme mismanagement you have not only"<<endl;
         cout<<"Been impeached and thrown out of office but you have"<<endl;
         cout<<"Also been declared national fink!!!!"<<endl;
       }
        
    }
    };


   

    class Menu
    {
         private:
            bool running = true;
            People p;
            bushels b;
            Start s;
        public: 
            void start()
            {
                while (running)
                {
                    cout << "1. Start the game" << endl;
                    
                    int choice;
                    cin >> choice;
                    
                    switch (choice)
                    {
                    case 1:
                        s.play();
                        break;
                    
                    default:
                        break;
                    }
                }
                
            }

        
    };

int main()
{
     srand(time(0));
     Menu m;
    m.start();

}
