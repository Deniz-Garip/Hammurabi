#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

int people = 100;
int bushels = 3000;
int land = 1000;
int year = 0;
int between = 0;
int Landprice = 0;


class Bushels 
{
private:

    int feed;
    int harvest;
    int price;

public:

    void printBushels() // print bushels begin the game
    {
        cout << "You now have " << bushels << " bushesl in store" << endl;
    }

    void getFeed() // you feed  poeple 
    {
        cin >> feed;
    }

    void getHarvest() // 
    {
        cin >> harvest;
    }

    int feedOutput() // return the feed
    {
        return feed;
    }

    int harvestOutput() // return the harvest
    {
        return harvest;
    }

    int landPrice() // randomsy land price every year
    {
        return Landprice = rand() % 10 + 17;
        
    }

    int bushlesBetween() // randomsy bushlesBetween price every year
    {
       return between  = rand() % 5 + 2;
        
    }
    void printBushlesBetween() // print the BushlesBetween
    {
        cout << "You harvested " << between << " bushels per ace" << endl;
    }
};


class People
{
private:

    int peopleleft = 0;
    int died = 0;
    int result_immigrant;


public:

    void printPeople() // print the people
    {
        cout << "Population is now " << people << endl;
    }

    int Starved() //
    {
        Bushels b;


        while (true)
        {
            cout << "How many bushels do you wish to feed your people?" << endl;

            b.getFeed();
            if (bushels >= b.feedOutput())
            {
                died = (people - (b.feedOutput() / 20));
                return bushels = bushels - b.feedOutput();
              
                break;
            }
            cout << "Hammurabi: think again. You have only " << endl << bushels << " bushels of grain." << endl;

        }

    }

    int peopleDied() // return the died
    {
        return died;
    }



    int outputPeopleLeft() // calculate how many people left
    {
        return people = (people - died);

    }

    void printStarved() // print starved
    {
        if (0 < died)
        {
            cout << died << " People Starved,";
        }

        else
        {
            cout << "0 People Starved,";
        }
    }


    void immigrant()  // calculate the immigrant
    {
        if (bushels >= 2900)
        {
            result_immigrant = (bushels - 2900) / 20;
            cout << " " << result_immigrant << " came to the city" << endl;
        }
        else
        {
            cout << "0 " << "came to the city" << endl;
        }

    }


    int addPeople() // add the immigrant to people
    {
        return people = people  + result_immigrant;
    }
};

class Land
{
private:

    int plant;
    string input;
    int bushels_left;
    int result;

public:

    void printLand() // print the ladn
    {
        cout << "The city own now " << land << endl;

    }

    void getData()   // 
    {
        cin >> input;
    }

    string landData()
    {
        return input;
    }

    int limitFarmUp() // I will change him name 
    {
        People p;
        return plant = people * 10;
    }

    int inputLand() // calcilaten the land
    {
        Bushels b;

        while (true)
        {
            cout << "Land is trading at " << Landprice << " bushels per ace." << endl;
            cout << "Do you wish to buy acres ? Yes / No " << endl;
            getData();

            result = 0;

            if (input == "yes" || input == "Yes")
            {
                cout << "How many acres do you wish to buy? " << endl;

                b.getFeed();
                
                

                if (b.feedOutput() >= Landprice)
                {
                    result = b.feedOutput() / Landprice;
                    return bushels - b.feedOutput();
                    break;

                }

            }

            else if (input == "no" || input == "No")
            {
                break;
            }

        }

    }

   int landReturn() // return land
    {
        return land = land + result;
    }

      int Harvests()      
    {
        Bushels b;

        while (true)
        {
            cout << "How many acres do you wish to plant with seed" << endl;
            cout << "An acre of land requires two bushels to plant seed" << endl;

            b.getHarvest();
            
                if (plant >= b.harvestOutput()) 
                {

                    if (b.harvestOutput() >= 2)
                    {
                      cout<<between<<endl;

                        
                        bushels_left = b.harvestOutput() * between;
                        int a = bushels - b.harvestOutput()  ;
                          return bushels = bushels_left + a;
                        cout << bushels << endl;
                      
                        break;

                    }
                    else if (b.harvestOutput() == 0)
                    {
                       break;
                    }

                }
            
        }
    }
    

};

class Year
{
public:

    int yearCalculator() // calculaten the year
    {
        if (year <= 9)
        {
            return  year++;

        }
    }

    void printYear() // print the year
    {
        cout << "In Year " << year << " ,";
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

    void play() // start the game
    {
        while (true)
        {
            y.yearCalculator();
            y.printYear();
            p.printStarved();
            p.immigrant();
            b.bushlesBetween();
            b.landPrice();
            p.printPeople();
            l.printLand();
            b.printBushlesBetween();
            b.printBushels();
            l.inputLand();
            p.Starved();
            p.outputPeopleLeft();
            l.limitFarmUp();
            l.Harvests();
            p.addPeople();
            l.landReturn();

            if (people <= 45) // print the game loset
            {
                int died = p.peopleDied();
                cout << "You Starved " << died << " people in " << year << " year!!!" << endl;
                cout << "Due to this exterme mismanagement you have not only" << endl;
                cout << "Been impeached and thrown out of office but you have" << endl;
                cout << "Also been declared national fink!!!!" << endl;
                break;
            }
            else if (year == 10) // print the game won
            {
                cout << "Congratulations you won the game!" << endl;
                break;
            }
        }
    }


    void change_the_people() // you can change the people
    {
        cin >> people;
    }

    void change_the_land() // you can change the land
    {
        cin >> land;
    }

    void change_the_bushels() // you can change the bushels
    {
        cin >> bushels;
    }

    void loadFromFile() // loding the file
    {
        ifstream inputFile("Hammurabi.txt");
        inputFile >> year;
        inputFile.close();
    }

    void saveToFile() // saving the file
    {
        ofstream outPutFile("Hammurabi.txt");
        outPutFile << year << endl;
        running = false;
        outPutFile.close();
    }

public:

    void start()
    {
        while (running)
        {
            cout << "1. Start the game" << endl;
            cout << "2. Change the number of people " << endl;
            cout << "3. Change the number of land " << endl;
            cout << "4. Change the number of bushels " << endl;
            cout << "5. Load from file" << endl;
            cout << "6. Save and Quit" << endl;

            int choice;
            cin >> choice;

            switch (choice)
            {
            case 1:
                play();
                break;
            case 2:
                change_the_people();
                break;
            case 3:
                change_the_land();
                break;
            case 4:
                change_the_bushels();
                break;
            case 5:
                loadFromFile();
                break;
            case 6:
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
