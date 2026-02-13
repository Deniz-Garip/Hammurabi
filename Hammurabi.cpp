#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;    

 int people =100;
 int bushels = 3000;
 int land =1000;
 int year=0;
  int between = 0;
  int owner =0;


  class Bushels
    {
         private:
        
        int feed;
        int harvest;
        int price;
        
        int bettwen_busles;  
        
        public: 
        
        void printbushels() // print bushels BEGIN THE game
        {
            cout<< "You now have "<<bushels<<" bushesl in store"<<endl;
        }

        void getfeed() // you feed  poeple 
        {   
            
            cin>>feed;
        
        }
        void getharvest() // 
        {
            cin>>harvest;
        }
        int feedoutput() // return the feed
        {
            return feed;
            
        }

        int harvestoutput() // return the harvest
        {
             return harvest;
        }
        
    
        int landprice() // randomsy land price every year
        {
            price = rand() % 10 + 17; 
            return owner = price;
        }

        

        int buslesbettwehn()
        {
            
             bettwen_busles = rand() % 5 + 2;
            return between = bettwen_busles;
            
        }
        
        void printbuslesbettwen()
        {
          

            cout <<"You harvested "<<between<<" bushels per ace"<<endl;
        }

    };
 

class People
{
    private:
     
    int peopleleft =0;
    int died =0;
    int immigrants;
    int result_immigrant ;
    int imigrantpeople;
    

    public:

    void printpeople()
    {
        cout<<"Population is now " <<people<<endl;
    }

    int starved()
    {   
        Bushels b;
       

        while (true)
        {
            cout <<"How many busles do you wish to feed your people?"<<endl;

            b.getfeed(); 
            if(bushels>=b.feedoutput())
            {

                died=(people-(b.feedoutput()/20));
                return bushels = bushels -b.feedoutput();
                

                break;
            }
            cout<<"Hamurabi: think again. you have only"<<endl <<bushels<<" busles of grain"<<endl;
 
        }
        
    }

    int peopledied()
    {
        return died;
    }

   

    int  outputpeopleleft()
    {
           return people=(people-died);
            
    }

    void printstarved()
    {   
        if(0<died)
        {
            cout<<died<<endl;
        }
        
        else
        {
            cout<<"0 People starved,";
        }
    }
    

    void immigrant() 
    {
       if(bushels>=2900)
       {
         result_immigrant = (bushels -2900) /20;
         cout<< " "<<result_immigrant<<" came to the city"<<endl;
       }
       else
       {
         cout<<"0 "<<"came to the city"<<endl;
       }
        
    }

    int returnimigrant() 
    {
        return imigrantpeople = result_immigrant + people;
        
    }

    int addpeople()
    {
        return people = imigrantpeople;
    }
    

   
};
    class Land
    {
       private:
        int plant;
        string input;
        int buslesleft;
        int result;

        public: 
         
        void printland()
        {
            cout<< "The city own now " <<land<<endl;
            
        }

        void getdata()   
        {
            cin>>input;
        }

        string landdata()   
        {
            return input;
        }

        int limitfarm_up() // I will change him name 
        {
            People p;
            return plant = people *10; 
        }
        
        int intputland()
        {
            Bushels b;

            
            while (true)
            {
                cout<<"Land is trading at "<<owner <<" bushels per ace"<<endl;
                 cout<<"Do you wish to buy acres ? Yes / No "<<endl;
                    getdata();
                    
                if(input == "yes" || input == "Yes") 
                {   
                    cout<<"How many acres do you wish to buy? "<<endl;
                    
                    b.getfeed();

                    
                    
                    if(b.feedoutput()>= owner)
                    {
                          result= b.feedoutput() / owner;
                         return bushels = bushels - b.feedoutput();
                        
                         break;

                    }

                }

                else if (input == "no" || input == "No")
                {
                    break;
                }
                
            }
            
        }

        int landreturn()
        {
            
          return land = land + result;
             
        }

         int harvests() 
        {
            Land l;
            Bushels b;
            
            while (true)
        {
            cout<<"How many acres do you wish to plant with seed"<<endl;
            cout<<"An acre of land requires two bushels to plant seed"<<endl;
            
            
             b.getharvest();
             if(land>=b.harvestoutput())
             {
               
                  if(l.limitfarm_up()>= b.harvestoutput())
                { 
                   
                     if(b.harvestoutput()>=2)
                  {     
                      
                         bushels = b.harvestoutput() - bushels;
                      buslesleft = b.harvestoutput()* between;
                     
                        
                     break; 
                  }
               }
             } 
            
            
        }
        }

        int returnharvests()
        {
            
            return bushels = buslesleft + bushels;
        }
       
       
    
    };

     class Year
    {
        private:
        int year;
        public:

        int yearcalculator()
        {
            if(year<=9)
         {
              return  year++;
                
         }
        }
        
        void printyear()
        {
            cout<<"In Year "<<year<<" ,";
        }

        
    };

    
    class Menu
    {
         private:
            bool running = true;
            People p;
            Bushels b;
            Land l;
            Year y;
        void play() 
    {
            while(true)
        {
            y.yearcalculator();
            y.printyear();
            p.printstarved();
             p.immigrant();
            b.buslesbettwehn();
             b.landprice();
             p.printpeople();
             l.printland();
            b.printbuslesbettwen();
            b.printbushels();
            l.intputland();
            p.starved();
            p.outputpeopleleft();
            l.limitfarm_up();
            l.harvests();
            l.returnharvests();
            p.returnimigrant(); 
            p.addpeople();
            l.landreturn();
        

            if(p.peopledied()>=45)
           {
                cout<< "You starved "<<p.peopledied()<<" people in "<< year<< " year!!!"<<endl;
                cout<<"Due to this exterme mismanagement you have not only"<<endl;
                cout<<"Been impeached and thrown out of office but you have"<<endl;
                cout<<"Also been declared national fink!!!!"<<endl;
                 break;
           }

          else if (year ==10)
          {
            cout<<"Congratulations you win the game"<<endl;
            break;
          }
        
      }  
    }

     

void saveToFile()
{
    ofstream outPutFile("Hammurabi.txt");

    outPutFile << year   << endl;
    running = false;
    outPutFile.close();
   
}






        
void loadFromFile()
{
    
    ifstream inputFile("Hammurabi.txt");

    inputFile >> year;
    inputFile.close();

    
}


        
        public: 
            void start()
            {
                while (running)
                {
                    cout << "1. Start the game" << endl;

			        cout << "2. Load from file" << endl;
			        cout << "3. Save a Quit" << endl;
                    
                    int choice;
                    cin >> choice;
                    
                    switch (choice)
                    {
                    case 1:
                        play();
                        break;
                         
                    case 2:
                        loadFromFile();
                        break;
                        
                    case 3:
                        saveToFile();
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
