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
    int Menu_item;
    string Type_of_order;
    

    public:
    int total_price;
    Total_price(string cn,string cd, int cp, int m_i, string to, int tp): Customer_contact(cn,cd,cp)
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
        cout<<"Menu Item: "<<Menu_item<<endl;
        cout<<"Type of order: "<<Type_of_order<<endl;
        cout<<"Total price: "<<total_price<<endl;
    }

  
};


class Menu_Item
{
    public:
    string Cuisine;
    string Item_name;
    string Drinks;

     Menu_Item(string c, string In, string dk )
    {
        Cuisine = c;
        Item_name = In;
        Drinks = dk;
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


     Menu_sales(string c, string In, string dk,string av, float Ip, int Pr, int m_n) :Menu_Item(c,In,dk)
     {
        Availability =av;
        Item_price= Ip;
        Popularity_rating = Pr;
        Menu_Number =m_n;
       
     }

     float pricecalculater(int quantity)
     {
        return Item_price * quantity;
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
        
        cout<<"working"<<endl;
            *totalorders = *quantity;    
    }

    int  Most_popular_item(int* Menu, int * rating ) // I will check
    {
        switch (*Menu)
        {
        case 1:
            cout<<"Gyros"<<endl;
            (*rating)++;
            break;
        case 2:
            cout<<"Lamp souvlaki"<<endl;
            (*rating)++;
            break; 
        case 3:
            cout<<"Dolmadakia"<<endl;
            (*rating)++;
            break;                           
        case 4:
            cout<<"Grilled octopus"<<endl;
            (*rating)++;
            break;
        case 5:
            cout<<"Makaronia tou Fournou"<<endl;
            (*rating)++;
            break;
        case 6:
            cout<<"Sheftalies"<<endl;
            (*rating)++;
            break; 
            
        case 7:
            cout<<"Koubes"<<endl;
            (*rating)++;
            break;    
        
        case 8:
            cout<<"Ofto Kleftiko"<<endl;
            (*rating)++;
            break;    
        default:
            break;
        }
    }

       

        void printmenu()    
        {
            cout <<"Menu Number:"<<Menu_Number<<endl;
            cout <<"Cuisine:" <<Cuisine<<endl;
            cout <<"Item_name:" <<Item_name<<endl;
            cout << "Drinks: " << Drinks << endl;
            cout << "Availability: " << Availability << endl;
            cout << "Item_price: " << Item_price << endl;
            cout << "Popularity_rating: " << Popularity_rating << endl;
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
    string customer_name;
    string name;
    string location;
     
    
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
    bool canDeliver = false;
    Menu_sales* m1;
    Menu_sales* m2;
    Menu_sales* m3;
    Menu_sales* m4;
    Menu_sales* m5;
    Menu_sales* m6;
    Menu_sales* m7;
    Menu_sales* m8;

    string places[5] = 
    {
        "Treforest", "Glyntaff","Rhydyfelin","Upper Boat","Pontypridd"     
    };
        


    void getaddres()
    {
       

    cout << "What is your name" << endl;
    cin >> name;
    cout<<"We can only deliver to the ths location Treforest, Glyntaff, Rhydyfelin, Upper Boat, Pontypridd"<<endl;
    cout << "Location" << endl;
    cin >> location;
    cout << "Phone number" << endl;
    cin >> phone;
    cout<<"We can order the only that location:Treforest, Glyntaff, Rhydyfelin , Upper Boat, Pontypridd"<<endl;
    cout << "1: Takeaway" << endl;
    cout << "2: In Person" << endl;
    cin >> orderType;

    if (orderType == 1) // I will check
    {
            orderTypeStr = "Take away";
         takeaway_Count++;
       
         for (int i = 0; i < 5; i++) {
            if (*(places + i) == location) 
            {
                canDeliver = true;                
              break;
            }
            
            else
            {     orderTypeStr = "In Person";
                 cout << " We cannot deliver to the " << location << " area." << endl;
                 cout<<"We can only deliver to the ths location Treforest, Glyntaff, Rhydyfelin, Upper Boat, Pontypridd"<<endl;
                cout << " In Person: Please come to the store to pick it up." << endl;
                break;
            }
        }
        
    
    }

     else if (orderType == 2)
    {
            orderTypeStr = "In Person";
            cout << " Please come to the store to pick it up." << endl;
        
    }
   

        cout<<"Which menu do you take"<<endl;
        cin>> Menu;

        if(takeaway_Count>=15)
        {

        
        switch (Menu)
        {
        case 1: 
           cout << "How many Gyros do you want: ";
             cin >> quantity;
             total = m1->pricecalculater(quantity);
                
             m1->Most_popular_cuisine(&cyprus, &greece, &Menu);
             m1->Most_popular_item(& Menu, &rating );
             m1->total_orders(&quantity,&totalorders);
               cout << "Total price: " << total << endl;
            break;
        case 2:
            
             cout << "How many Lamp souvlaki do you want: ";
             cin >> quantity;
             total = m2->pricecalculater(quantity);
                   m2->Most_popular_cuisine(&cyprus, &greece, &Menu);
                 m2->Most_popular_item(& Menu, &rating );
                m2->total_orders(&quantity,&totalorders);

                  
             cout<<total<<endl;
            break;

        case 3:
        cout << "How many Dolmadakia do you want: ";
             cin >> quantity;
             total = m3->pricecalculater(quantity);
                   m3->Most_popular_cuisine(&cyprus, &greece, &Menu);
                 m3->Most_popular_item(& Menu, &rating ); 
                    m3->total_orders(&quantity,&totalorders);

             break;
        
        case 4:
         cout << "How many Grilled octopus do you want: ";
             cin >> quantity;
             total = m4->pricecalculater(quantity);
                  m4->Most_popular_cuisine(&cyprus, &greece, &Menu);
                    m4->Most_popular_item(& Menu, &rating ); 
                                m4->total_orders(&quantity,&totalorders);


              cout<<total<<endl;
            break;
            case 5:
         cout << "How many Makaronia tou Fournou do you want: ";
             cin >> quantity;
             total = m5->pricecalculater(quantity);
                   m5->Most_popular_cuisine(&cyprus, &greece, &Menu);
                            m5->total_orders(&quantity,&totalorders);

              cout<<total<<endl;
            break; 

            case 6:
         cout << "How many Sheftalies do you want: ";
             cin >> quantity;
             total = m6->pricecalculater(quantity);
                   m6->Most_popular_cuisine(&cyprus, &greece, &Menu);
                                m6->total_orders(&quantity,&totalorders);

              cout<<total<<endl;
            break;   

            case 7:
         cout << "How many Koubes do you want: ";
             cin >> quantity;
             total = m7->pricecalculater(quantity);
                   m7->Most_popular_cuisine(&cyprus, &greece, &Menu);
                                m7->total_orders(&quantity,&totalorders);

              cout<<total<<endl;
            break; 

            case 8:
         cout << "How many Ofto Kleftiko do you want: ";
             cin >> quantity;
              total = m8->pricecalculater(quantity);
                m8->Most_popular_cuisine(&cyprus, &greece, &Menu);
                                m8->total_orders(&quantity,&totalorders);

               cout<<total<<endl;
            break;              
        }
    
        Total_price* t1 = new Total_price(name,location,phone,Menu, orderTypeStr,total);
        
        
        r.addcustomer(t1);
        r.example();

        
        }
        
        else{

            switch (Menu)
        {
        case 1: 
           cout << "How many Gyros do you want: ";
             cin >> quantity;
             total = m1->pricecalculater(quantity);
                
             m1->Most_popular_cuisine(&cyprus, &greece, &Menu);
             m1->Most_popular_item(& Menu, &rating );
             m1->total_orders(&quantity,&totalorders);
               cout << "Total price: " << total << endl;
            break;
        case 2:
            
             cout << "How many Lamp souvlaki do you want: ";
             cin >> quantity;
             total = m2->pricecalculater(quantity);
                   m2->Most_popular_cuisine(&cyprus, &greece, &Menu);
                 m2->Most_popular_item(& Menu, &rating );
                m2->total_orders(&quantity,&totalorders);

                  
             cout<<total<<endl;
            break;

        case 3:
        cout << "How many Dolmadakia do you want: ";
             cin >> quantity;
             total = m3->pricecalculater(quantity);
                   m3->Most_popular_cuisine(&cyprus, &greece, &Menu);
                 m3->Most_popular_item(& Menu, &rating ); 
                    m3->total_orders(&quantity,&totalorders);

             break;
        
        case 4:
         cout << "How many Grilled octopus do you want: ";
             cin >> quantity;
             total = m4->pricecalculater(quantity);
                  m4->Most_popular_cuisine(&cyprus, &greece, &Menu);
                    m4->Most_popular_item(& Menu, &rating ); 
                                m4->total_orders(&quantity,&totalorders);


              cout<<total<<endl;
            break;
            case 5:
         cout << "How many Makaronia tou Fournou do you want: ";
             cin >> quantity;
             total = m5->pricecalculater(quantity);
                   m5->Most_popular_cuisine(&cyprus, &greece, &Menu);
                            m5->total_orders(&quantity,&totalorders);

              cout<<total<<endl;
            break; 

            case 6:
         cout << "How many Sheftalies do you want: ";
             cin >> quantity;
             total = m6->pricecalculater(quantity);
                   m6->Most_popular_cuisine(&cyprus, &greece, &Menu);
                                m6->total_orders(&quantity,&totalorders);

              cout<<total<<endl;
            break;   

            case 7:
         cout << "How many Koubes do you want: ";
             cin >> quantity;
             total = m7->pricecalculater(quantity);
                   m7->Most_popular_cuisine(&cyprus, &greece, &Menu);
                                m7->total_orders(&quantity,&totalorders);

              cout<<total<<endl;
            break; 

            case 8:
         cout << "How many Ofto Kleftiko do you want: ";
             cin >> quantity;
              total = m8->pricecalculater(quantity);
                m8->Most_popular_cuisine(&cyprus, &greece, &Menu);
                                m8->total_orders(&quantity,&totalorders);

               cout<<total<<endl;
            break;              
        }
    
        Total_price* t1 = new Total_price(name,location,phone,Menu, orderTypeStr,total);
        
        
        r.addcustomer(t1);
        r.example();
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

    void most_popular_item() // Perhabs I cahnge this code because i wiil make better and more faster
    {
        switch(Menu) // output is not very well i should be change the output
        {
            case 1:
            cout<<"Gyros ";
            cout<<rating<<endl;
            break;
            case 2:
             cout<<"Lamp souvlaki "<<endl;
             cout<<rating<<endl;
            break;
            case 3:
            cout<<"Dolmadakia "<<endl;
            cout<<rating<<endl;
            break;
            case 4:
            cout<<"Grilled octopus "<<endl;
            cout<<rating<<endl;
            break;
            case 5:
            cout<<"Makaronia tou Fournou "<<endl;
            cout<<rating<<endl;
            break;
            case 6:
            cout<<"Sheftalies "<<endl;
            cout<<rating<<endl;
            break;
            case 7:
            cout<<"Koubes "<<endl;
            cout<<rating<<endl;
            break;
            case 8:
            cout<<"Ofto Kleftiko "<<endl;
            cout<<rating<<endl;
            break;

        }
        
    }

   void printstaf()
   {
      
      cin>>customer_name;
      
        Staff* s1 = new Staff(customer_name, "London", 123456, "Chef", "Greece and Cyprus");
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

            m1 = new Menu_sales("Greece", "Gyros","cola","yes", 10,4,1);
             m2 = new Menu_sales("Greece", "Lamp souvlaki","cola","yes", 10,4,2);
            m3 = new Menu_sales("Greece", "Dolmadakia","cola","yes", 10,4,3);
            m4 = new Menu_sales("Greece", "Grilled octopus","cola","yes", 10,4,4);
            m5 = new Menu_sales("Cyprus", "Makaronia tou Fournou","cola","yes", 10,4,5);
            m6 = new Menu_sales("Cyprus", "Sheftalies","cola","yes", 10,4,6);
             m7 = new Menu_sales("Cyprus", "Koubes","cola","yes", 10,4,7);
            m8 = new Menu_sales("Cyprus", "Ofto Kleftiko","cola","yes",10,4,8);
       
 
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
        cout<<totalorders<<endl;
   }


void loadFromFile()
{
    ifstream inputFile("Takey-away.txt");

    string label;
    inputFile >> label >> name;        
    inputFile >> label >> phone;        
    inputFile >> label >> location;     
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
    outputFile << "Order: "<< orderTypeStr<< endl;
    outputFile << "Total: "<<total<<endl;
    outputFile <<"-----------"<<endl;

    outputFile.close();
}


 
   public:

   void start()
   {
        while (true)
        {
            cout<<"1: Worker"<<endl;
            cout<<"2: Menu"<<endl;
            cout<<"3: Which menu do you want buy"<<endl;
            cout<<"4: Total incomer"<<endl;
            cout<<"5: most_popular_cuisine"<<endl;
            cout<<"6: most_popular_item"<<endl;
            cout<<"7: loyalCustomer"<<endl;
            cout<<"8: total order"<<endl;
            cout<<"9: Load from file"<<endl;
            cin >> choice;
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
            }  
        }
        
              
   }
             
};

int main()
{
    
    Menu m;
    m.start();
    
}
