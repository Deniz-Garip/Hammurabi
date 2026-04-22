#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;



class Customer_contact
{
    public:
    string customer_name;
    string customer_addres;
    int customer_phone;
    float total;
    
    Customer_contact(string cn, string cd, int cp )
    {
        customer_name = cn;
        customer_addres =cd;
        customer_phone = cp;
    }

  
    
    virtual void printcustomer_contact() =0;
};

class Total_price : public Customer_contact
{
    private:
    string Menu_item;
    string Type_of_order;
    float total_price;


    public:
    Total_price(string cn,string cd, int cp, string m_i, string to, float tp): Customer_contact(cn,cd,cp)
    {
        Menu_item = m_i;
        Type_of_order = to;
        total_price = tp;
    }
    
    void printcustomer_contact()
    {
        cout<<"Customer Name: "<<customer_name<<endl;
        cout<<"Contact: "<<customer_phone<<endl;
        cout<<"Address: "<<customer_addres<<endl;
        cout<<"Meal name: "<<Menu_item<<endl;
        cout<<"Type of order: "<<Type_of_order<<endl;
        cout<<"Total price: "<<total_price<<"\x9C" <<endl;
    }

  
};


class Menu_Item
{
    public:
    string Cuisine;
    string Item_name;
    int Item_quantity =0;
    

     Menu_Item(string c, string In, int IQ )
    {
        Cuisine = c;
        Item_name = In;
        Item_quantity = IQ;
        
       
    }

    virtual void printmenu() =0;

    
};

class Menu_sales :public  Menu_Item 
{
    private:

    string Availability;
    float Item_price;
   int Popularity_rating;
   int Menu_Number;
   

    public:


     Menu_sales(string c, string In, int IQ ,string av, float Ip, int Pr, int m_n) :Menu_Item(c,In,IQ)
     {
        Availability =av;
        Item_price= Ip;
        Popularity_rating = Pr;
        Menu_Number =m_n;
       
     }

     float pricecalculater(int quantity, float *total)
     {
        return *total += Item_price * quantity; // I will check that code

     }

     int Most_popular_cuisine(int* cyprus, int* greece, int* Menu ) 
    {
        
        cout<<*Menu<<endl;
        if(*Menu>= 5)
        {
            *cyprus++;
            
        }

        else if(*Menu <=4)
        {
            *greece++;
           
        }
    } 

    int total_orders(int* quantity, int* totalorders)
    {
            *totalorders = *quantity;    
    }


    void getAvailability(int* quantity ) 
    {
         Item_quantity=Item_quantity - *quantity;
        if(Item_quantity <=0)
        {
           Availability = "No"; 
          
        
        }        
    }


        void printmenu()    
        {
            cout << "------------------------" << endl;
            cout <<"Menu Number:"<<Menu_Number<<endl;
            cout <<"Cuisine:" <<Cuisine<<endl;
            cout <<"Item name:" <<Item_name<<endl;
            cout <<"Item quantity:"<<Item_quantity<<endl;
            cout << "Availability:" << Availability << endl;
            cout << "Item price: "<< Item_price << "\x9C"<< endl;
            cout << "Popularity rating:" << Popularity_rating << endl;
            cout << "------------------------" << endl;
        }
    
}; 


class Staff_contact
{
   
    public:
     
    string Name;
    string Addres;
    int Phone_Number;

     Staff_contact(string n, string a,  int p)
    {
        Name = n;
        Addres = a;
        Phone_Number = p;
    }

    virtual void printinfo() = 0;
   
};

class Staff: public Staff_contact
{
    private:
    string staff;
    string Cuisine_specialist;

    public:

     Staff(string n, string a,  int p , string s, string cs) : Staff_contact(n,a,p)
    {
        staff = s;
        Cuisine_specialist = cs;
    }

     string customer_name(string Customer_Name)
   {
        return Customer_Name =Name;
   }
    
    void printinfo() 
    {
        cout <<"Staff:" <<staff<<endl;
        cout << "Name: " << Name << endl;
        cout << "Addres: " << Addres << endl;
        cout << "Phone_Number: " << Phone_Number << endl;
        cout << "Cuisine_specialist: " << Cuisine_specialist << endl;
        cout << "------------------------" << endl;
    }
};

class result
{
    private:

    vector <Staff_contact*>people;
    vector <Menu_Item*>menu;
    vector<Customer_contact*>customer;

    public:

    void addcustomer(Customer_contact* c)
    {
        customer.push_back(c);
    }
      
    void addmenu(Menu_Item* m)
    {
        menu.push_back(m);
    }

    void addperson(Staff_contact* p)
    {
        people.push_back(p);
    }

    void listmenu()
    {
        for (Menu_Item* m: menu)
        {
            m->printmenu();
        }
        
    }

    void listpeople()
    {
        for (Staff_contact* p: people)
        {
            p->printinfo();
        }
    }

    void example()
    {   for(Customer_contact* c: customer)
        {
            c->printcustomer_contact();
        }
        
    }
void loyalCustomer() // I wiil check this code because I'm not sure is it working also I dont know how it is working
{
    if (customer.empty()) return;

    Customer_contact* loyal = customer[0];

    for (Customer_contact* c : customer)
    {
        if (c->total > loyal->total)
        {
            loyal = c;
        }
    }

    cout << "--- Loyal Customer ---" << endl;
    loyal->printcustomer_contact();
}

};



class Menu
{
    
    private:
    int choice;
    result r;
    string name;
    string location;
    string input;
    string Item_name;
    int Item_quantity;
    Menu_sales* ms;
   
   

     
    
    int phone;
    int Menu =0;
    int quantity;
    float total_income =0;
    float total =0;
    int cyprus =0;
    int greece =0;
    int most_menu =0;
    int rating =0;
    int totalorders =0;
    int takeaway_Count = 0;
    string orderTypeStr;
    int orderType;
    string canDeliver; 
    Menu_sales* m1;
    Menu_sales* m2;
    Menu_sales* m3;
    Menu_sales* m4;
    Menu_sales* m5;
    Menu_sales* m6;
    Menu_sales* m7;
    Menu_sales* m8;
    bool system_exist = true ;

    string places[5] 
    {
        "Treforest", "Glyntaff","Rhydyfelin","Upper Boat","Pontypridd"     
    };
        


    void getaddres()
{
       

    cout << "What is your name" << endl;
    cin >> name;
    cout<<"We can only deliver to the this location Treforest, Glyntaff, Rhydyfelin, Upper Boat, Pontypridd"<<endl;
    cout << "Location" << endl;
    cin >> location;
    cout << "Phone number" << endl;
    cin >> phone;
  
   while(true)
    {
    cout<<"We can order the only that location:Treforest, Glyntaff, Rhydyfelin , Upper Boat, Pontypridd"<<endl;
    cout << "1: Take away" << endl;
    cout << "2: In Person" << endl;
    cin >> orderType;

    if (orderType == 1) 
    {
        if(takeaway_Count<15)
      {
            orderTypeStr = "Take away";
         takeaway_Count++;
         
       
         for (int i = 0; i < 5; i++) 
         {
            if (*(places + i) == location) 
            {
                canDeliver ="No";           
              break;
              
            }
            else
            {     orderTypeStr = "In Person";
                 cout << " We cannot deliver to the " << location << " area." << endl;
                 cout<<"We can only deliver to the ths location Treforest, Glyntaff, Rhydyfelin, Upper Boat, Pontypridd"<<endl;
                cout << " In Person: Please come to the store to pick it up." << endl;
                cout<<"if you dont want to order you can cancle the now Yes or No"<<endl;

                 cout<<"Do you want to cancle it the order"<<endl;
                cin>>canDeliver;

                break;
            }
        }
        
      }
            
       else
       {
            cout<<"We can not  delivery you have only change choose the in person "<<endl;
            cout<<"if you dont want to order you cancle the now Yer or No"<<endl;
            cin>>canDeliver;
       }     
        break;
    }

      if (orderType == 2)
    {
            orderTypeStr = "In Person";
            cout << " Please come to the store to pick it up." << endl;
            canDeliver ="No";
            break;
        
    }

    else if(orderType == 0 || orderType >= 3)
    {
         cout << "You cannot put that number, you can put only these numbers 1,2." << endl;
    }

 } 

   if(takeaway_Count<=1 ||canDeliver =="No" ) 
{

  
    while(canDeliver == "No")
    {
    
        cout<<"Which menu do you take"<<endl;
        cout<<"Choose the menu number. If you don't remeber the menu number you check the menu "<<endl;
        cin>> Menu;
    
        
          if(Menu >=1 && Menu<=8 )
         {
                   
        totalorders++;
        
        switch (Menu)
        {
        case 1:  // I will conctuinte on this code 
        while (true)
        {
              
       cout << "How many Gyros do you want: ";
           cin >> quantity;
           
        if(quantity >0 && quantity <=10)
        {
            Item_name ="Gyros";
           
            m1->getAvailability(&quantity);
              m1->pricecalculater(quantity,&total);
               
             m1->Most_popular_cuisine(&cyprus, &greece, &Menu);
             m1->total_orders(&quantity,&totalorders);
             break;
        }
        else
        {
            cout <<"You cannot enter the numbers 0 or 11."<<endl;
        }
    
      }     
           break;
            
        case 2:
        while(true)
              {  cout << "How many Lamp souvlaki do you want: ";
             cin >> quantity;
             if(quantity >0 && quantity <=10)
              {   Item_name ="Lamp souvlaki";
             m2->getAvailability(&quantity);

               m2->pricecalculater(quantity,&total);
                 m2->Most_popular_cuisine(&cyprus, &greece, &Menu);
                m2->total_orders(&quantity,&totalorders);
            break;
            }
             else
          {
            cout <<"You cannot enter the numbers 0 or 11."<<endl;
          }
        }
        break;
        case 3:
        while(true)
        {
            cout << "How many Dolmadakia do you want: ";
             cin >> quantity;
          if(quantity >0 && quantity <=10)
           { Item_name ="Dolmadakia";
                 m3->getAvailability(&quantity);
             total = m3->pricecalculater(quantity,&total);
                   m3->Most_popular_cuisine(&cyprus, &greece, &Menu);
                    m3->total_orders(&quantity,&totalorders);
             break;
        }
        else
        {
           cout <<"You cannot enter the numbers 0 or 11."<<endl;
        }
    }
    break;
        case 4:
            while (true)
            {
         cout << "How many Grilled octopus do you want: ";
              cin >> quantity;
             if(quantity >0 && quantity <=10)
             {
                Item_name ="Grilled octopus";
             m4->getAvailability(&quantity);
             total = m4->pricecalculater(quantity,&total);
                  m4->Most_popular_cuisine(&cyprus, &greece, &Menu);
                  m4->total_orders(&quantity,&totalorders);
              
            break;
             }
             else
             {
                  cout <<"You cannot enter the numbers 0 or 11."<<endl;

             }
             
            }
                break;
            
            case 5:
                while(true)
                {
                    cout << "How many Makaronia tou Fournou do you want: ";
                     cin >> quantity;
                    if(quantity >0 && quantity <=10)
                    {
                    
                   Item_name ="Makaronia tou Fournou";
                 m5->getAvailability(&quantity); 
             total = m5->pricecalculater(quantity,&total);
                   m5->Most_popular_cuisine(&cyprus, &greece, &Menu);
                     m5->total_orders(&quantity,&totalorders);

            break; 
             }

             else
             {
                  cout <<"You cannot enter the numbers 0 or 11."<<endl;
             }
             
           }
           break;
            case 6:
                while(true)
                {
                     cout << "How many Sheftalies do you want: ";
                   cin >> quantity;

                  if(quantity >0 && quantity <=10)
                  {

                 Item_name ="Sheftalies";
                m6->getAvailability(&quantity);  
               total = m6->pricecalculater(quantity,&total);
               m6->Most_popular_cuisine(&cyprus, &greece, &Menu);
               m6->total_orders(&quantity,&totalorders);

            break; 
                  }  

                  else
                  {
                    cout <<"You cannot enter the numbers 0 or 11."<<endl;  
                  }
            }
            break;
            case 7:
                while(true)
                {
                     cout << "How many Koubes do you want: ";
                    cin >> quantity;                                     
            if(quantity >0 && quantity <=10)
            {
                 Item_name ="Koubes";
            m7->getAvailability(&quantity); 
             
             total = m7->pricecalculater(quantity,&total);
                 m7->Most_popular_cuisine(&cyprus, &greece, &Menu);
                 m7->total_orders(&quantity,&totalorders);
            break; 
            }
            else
            {
                 cout <<"You cannot enter the numbers 0 or 11."<<endl;  

            }
        }    
            break;   
            case 8:
                while (true)
                {
                    cout << "How many Ofto Kleftiko do you want: ";
                    cin >> quantity;
                if(quantity >0 && quantity <=10)
                {
                     Item_name ="Ofto Kleftiko";
              m8->getAvailability(&quantity);
              total = m8->pricecalculater(quantity,&total);
                m8->Most_popular_cuisine(&cyprus, &greece, &Menu);
                m8->total_orders(&quantity,&totalorders);
            break;
                } 
                else
                {
                   cout <<"You cannot put that number you can put only these numbers 1 to 11"<<endl;  

                } 
              }
              break;            
        }
         cout<<"Do you want any order again.  No"<<endl;
        cin>>input;
        if(input == "No")
        {
              Total_price* t1 = new Total_price(name,location,phone,Item_name, orderTypeStr,total);
        r.addcustomer(t1);
        r.example();
        cout<<"Order placed successfully"<<endl;
            break;  
        }
       
         } 
         else
         {
         cout << "You cannot put that number , you can put only this numbers 1 2 3." << endl;
         }
       }   
    }     
}   
   
    void Total_incomer()
    {
        cout<<"Total income for the day"<<endl;
        cout<<total<<endl;
    }

    void most_popular_cuisine()
    {
        if(cyprus>greece)
        {
            cout<<"Most popular Cuisine is Cyprus "<<endl;
        }
        else 
        {
            cout<<"Most popular Cuisine is Greece "<<endl;
        }
    }

    void most_popular_item() 
    {
        switch(Menu)
        {
            if(Menu >=1 && Menu <=8)
            {
            case 1:
            cout<<"Most popular item is Gyros "<<endl;
            rating++;
            
            break;
            case 2:
             cout<<"Most popular item is Lamp souvlaki "<<endl;
             rating++;
             cout<<rating<<endl;
            break;
            case 3:
            cout<<"Most popular item is Dolmadakia "<<endl;
            rating++;
            cout<<rating<<endl;
            break;
            case 4:
            cout<<"Most popular item is Grilled octopus "<<endl;
            rating++;
            cout<<rating<<endl;
            break;
            case 5:
            cout<<"Most popular item is Makaronia tou Fournou "<<endl;
            rating++;
            cout<<rating<<endl;
            break;
            case 6:
            cout<<"Most popular item is Sheftalies "<<endl;
            rating++;
            cout<<rating<<endl;
            break;
            case 7:
            cout<<"Most popular item is Koubes "<<endl;
            rating++;
            cout<<rating<<endl;
            break;
            case 8:
            cout<<"Most popular item is Ofto Kleftiko "<<endl;
            rating++;
            cout<<rating<<endl;
            break;

        }
     }
    }

   void printstaf() // I will check that code
   {
      
      
        Staff* s1 = new Staff("James", "London", 123456, "Chef", "Greece and Cyprus");
         Staff* s2 = new Staff("John", "Bristol", 987654, "Delivery Staff", "");
        Staff* s3 = new Staff("Sara", "Manchester", 456789, "Manager", "");
        Staff* s4 = new Staff("Alex", "Manchester", 456789, "Receptionist", "");

    r.addperson(s1);
    r.addperson(s2);
    r.addperson(s3);
    r.addperson(s4);
    r.listpeople();

   }

   

   void printmenu() 
   {

            m1 = new Menu_sales("Greece", "Gyros",1,"Yes", 15,4,1);
             m2 = new Menu_sales("Greece", "Lamp souvlaki",13,"Yes", 14,5,2);
            m3 = new Menu_sales("Greece", "Dolmadakia",14,"Yes", 16,3,3);
            m4 = new Menu_sales("Greece", "Grilled octopus",10,"Yes", 20,2,4);
            m5 = new Menu_sales("Cyprus", "Makaronia tou Fournou",8,"Yes", 13,5,5);
            m6 = new Menu_sales("Cyprus", "Sheftalies",14,"Yes", 12,4,6);
             m7 = new Menu_sales("Cyprus", "Koubes",12,"Yes", 14,4,7);
            m8 = new Menu_sales("Cyprus", "Ofto Kleftiko",15,"Yes",12,5,8);
       
 
        r.addmenu(m1);
        r.addmenu(m2);
        r.addmenu(m3);
        r.addmenu(m4);
        r.addmenu(m5);
        r.addmenu(m6);
        r.addmenu(m7);
        r.addmenu(m8);
        r.listmenu();

   }

   void totalincrease()
   {
        cout<<"Total orders "<<totalorders<<endl;
   }


void loadFromFile()
{
    ifstream inputFile("Takey-away.txt");

    string label;
    inputFile >> label >> name;        
    inputFile >> label >> phone;        
    inputFile >> label >> location;
    inputFile >> label >> Item_name;     
    inputFile >> label >> orderTypeStr; 
    inputFile >> label >> total;

    inputFile.close();

}


void saveToFile()
{
    ofstream outputFile("Takey-away.txt");

   
    outputFile <<"-----------"<<endl;
    outputFile << "Name: "<< name<< endl;
    outputFile << "Phone: "<< phone<< endl;
    outputFile << "Location: "<< location<< endl;
    outputFile <<"Menu name: "<<Item_name<<endl;
    outputFile << "Order: "<< orderTypeStr<< endl;
    outputFile << "Total: "<<total<<"£"<<endl;
    outputFile <<"-----------"<<endl;

    outputFile.close();
}

    void Exist()
    {
          system_exist = false;
    }
 
   public:

   void start()
   {
        while (system_exist)
        {
            cout<<"1: Worker"<<endl;
            cout<<"2: Menu"<<endl;
            cout<<"3: Which menu do you want buy"<<endl;
            cout<<"4: Total incomer"<<endl;
            cout<<"5: Most popular cuisine"<<endl;
            cout<<"6: Most popular meal"<<endl;
            cout<<"7: Loyal Customer"<<endl;
            cout<<"8: Total order"<<endl;
            cout<<"9: Load from Bill"<<endl;
            cout <<"10 : Print the Bill"<<endl;
            cout<<"11: System Exist"<<endl;
            cin >> choice;
            if(choice >=1 && choice <=11)
            {
            switch (choice)
            {
            case 1:
                printstaf();
                break;
            case 2:
                printmenu();
                break;
            case 3:
                getaddres();
                break;
            case 4:
                Total_incomer();
                break;
            case 5:
            most_popular_cuisine();
              break;
            case 6:
            most_popular_item();
            break;
            case 7:
            r.loyalCustomer();
            break;
            case 8:
            totalincrease();
            break;
            case 9:
            loadFromFile();
            break;
            
            case 10:
            saveToFile();
            break;
            
            case 11:
            Exist();
            break;
            }
          }
          
          else
          {
           cout << "You cannot put that number, you can put only these numbers 1 to 12." << endl;
          }
        }
        
              
   }
             
};

int main()
{
    
    Menu m;
    m.start();
    
}
