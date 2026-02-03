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

        void getbushels()
        {   
            
            cin>>feed;
            
            
        }
        void getharvest()
        {
            cin>>harvest;
        }
        int buslesoutput()
        {
            return feed;
           
            
        }

        int buslesharvest()
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
        
        void printland()
        {

        }

    };
 

class People
{
    private:
     
    int peopleleft =0;
    int died;
    int immigrants;
    

    public:

    void getpeople()
    {
        cout<<"Population is now " <<people<<endl;
    }

    int starved()
    {   
        bushels b;
       

        while (true)
        {
            cout <<"How many busles do you wish to feed your people?"<<endl;

            b.getbushels(); //threse problem in here cin>>feed
            if(busles>=b.buslesoutput())
            {

                died=(people-(b.buslesoutput()/20));
                break;
            }
            cout<<"Hamurabi: think again. you have only"<<endl<<"3000 buslesof grain"<<endl;

        }
        
    }

    int  inputpeopleleft()
    {
           return peopleleft=(people-died);
            
    }
    void outputpeopleleft()
    {
        cout<<peopleleft<<endl;
    }

    int immigrant()
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
        string yes;

        public: 
         
        void getland()
        {
            cout<< "The city own now " <<land<<endl;
            
        }

        void getdata()
        {
            cin>>yes;
        }

        string landdata()
        {
            return yes;
        }

        int limitfarm_up()
        {
            People p;
            
            return farm_up =p.inputpeopleleft() *10;
        }
        
        int intputland()
        {
            bushels b;

            
            while (true)
            {
                cout<<"Land is trading at "<<b.landprice() <<" bushels per ace"<<endl;
                cout<<"How many acres do you wish to buy? Yes or No"<<endl; 
                if(yes == "yes" || yes == "Yes") // you need the change or because it is wrong i thinks so it is correct
                {
                    if(b.buslesoutput()>=b.landprice())
                    {
                         int result= b.buslesoutput()/b.landprice();
                         return busles = busles - b.buslesoutput();
                         return land = land + b.landprice();
                         break;

                    }
                }
                
            }
            
        }

         int harvests() //there is a problem in here you need the change
        {
            Land l;
            bushels b;
            l.limitfarm_up();
            while (true)
        {
            cout<<"How many acres do you wish to plant with seed"<<endl;
            cout<<"An acre of land requires two bushels to plant seed"<<endl;
             //cin>>b.getharvest(); 
             if(land>=b.buslesharvest())
             {
                  if(l.limitfarm_up()>= b.buslesharvest())
                { 
                 
                     if(b.buslesharvest()>=2)
                  {     
                    cout<<busles<<endl;
                      
                     int buslesresult = b.buslesharvest() + b.buslesbettwehn();
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
       p.getpeople();
       l.getland();
       b.printbuslesbettwen();
       b.printbushels();
       l.intputland();
      
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
