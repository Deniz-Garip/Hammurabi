#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

 int people =100;
 int busles = 3000;
 int land =1000;

class People
{
    private:
     
    int peopleleft =0;
    int died;
    

    public:

    void getpeople()
    {
        cout<<"Population is now " <<people<<endl;
    }

    int starved()
    {
        

        while (true)
        {
            cout <<"How many busles do you wish to feed your people?"<<endl;
            cin>>a;
            if(bushels>=a)
            {
                died=(people-(a/20));
                
            }
            
        }
        
    }

    int peopleleft()
    {
            peopleleft=(people-died);
    }

};
    class Land
    {
       private:
        int land = 1000;

        public: 
         
        void getland()
        {
            cout<< "The city own now " <<land<<endl;
        }
    };


    class bushels
    {
         private:
        int bushels = 3000;
        int a;
        

        public: 

        void printbushels()
        {
            cout<< "You now have "<<bushels<<"bushesl in store"<<endl;
        }

        void getbushels()
        {
            cin>>a;
        }


    };

    class Menu
    {
         private:

        public: 

        
    };

int main()
{
    
}