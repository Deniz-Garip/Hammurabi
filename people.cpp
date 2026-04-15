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
    int total_price;


    public:
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
    

     Menu_Item(string c, string In )
    {
        Cuisine = c;
        Item_name = In;
       
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


     Menu_sales(string c, string In, string av, float Ip, int Pr, int m_n) :Menu_Item(c,In)
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
            *totalorders = *quantity;    
    }



    

        void printmenu()    
        {
            cout <<"Menu Number:"<<Menu_Number<<endl;
            cout <<"Cuisine:" <<Cuisine<<endl;
            cout <<"Item_name:" <<Item_name<<endl;
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
    string Cancel;
     
    
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

    string places[5] 
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

    if (orderType == 1) 
    {
        if(takeaway_Count<1)
      {
            orderTypeStr = "Take away";
         takeaway_Count++;
         cout<<takeaway_Count<<endl;
       
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
            
       else
       {
            cout<<"We can not  delivery you have only change choose the in person "<<endl;
            cout<<"if you dont want to order you cancle the now Yer or No"<<endl;
            cin>>Cancel;
       }     
       
    }

     else if (orderType == 2)
    {
            orderTypeStr = "In Person";
            cout << " Please come to the store to pick it up." << endl;
            cout<<"if you dont want to order you cancle the now Yer or No"<<endl;
            cin>>Cancel;

        
    }

    while(Cancel != "No")
    {
    
        cout<<"Which menu do you take"<<endl;
        cin>> Menu;

        if(!quantity ==0)
        {
            cout<<"You can not  put this number, you can put only this numbers 1 2 3 like that "<<endl;
            break;
        }

        if(takeaway_Count<=1)
    {
            
        totalorders++;
        
    
        switch (Menu)
        {
        case 1: 
           cout << "How many Gyros do you want: ";
             cin >> quantity;
             total = m1->pricecalculater(quantity);
                
             m1->Most_popular_cuisine(&cyprus, &greece, &Menu);
             m1->total_orders(&quantity,&totalorders);
               
            break;
        case 2:
            
             cout << "How many Lamp souvlaki do you want: ";
             cin >> quantity;
             total = m2->pricecalculater(quantity);
                   m2->Most_popular_cuisine(&cyprus, &greece, &Menu);
                m2->total_orders(&quantity,&totalorders);
            break;

        case 3:
        cout << "How many Dolmadakia do you want: ";
             cin >> quantity;
             total = m3->pricecalculater(quantity);
                   m3->Most_popular_cuisine(&cyprus, &greece, &Menu);
                    m3->total_orders(&quantity,&totalorders);

             break;
        
        case 4:
         cout << "How many Grilled octopus do you want: ";
             cin >> quantity;
             total = m4->pricecalculater(quantity);
                  m4->Most_popular_cuisine(&cyprus, &greece, &Menu);
                  m4->total_orders(&quantity,&totalorders);


              
            break;
            case 5:
         cout << "How many Makaronia tou Fournou do you want: ";
             cin >> quantity;
             total = m5->pricecalculater(quantity);
                   m5->Most_popular_cuisine(&cyprus, &greece, &Menu);
                            m5->total_orders(&quantity,&totalorders);

            break; 

            case 6:
         cout << "How many Sheftalies do you want: ";
             cin >> quantity;
             total = m6->pricecalculater(quantity);
            m6->Most_popular_cuisine(&cyprus, &greece, &Menu);
             m6->total_orders(&quantity,&totalorders);

            break;   

            case 7:
         cout << "How many Koubes do you want: ";
             cin >> quantity;
             total = m7->pricecalculater(quantity);
                 m7->Most_popular_cuisine(&cyprus, &greece, &Menu);
                 m7->total_orders(&quantity,&totalorders);
            break; 

            case 8:
         cout << "How many Ofto Kleftiko do you want: ";
             cin >> quantity;
              total = m8->pricecalculater(quantity);
                m8->Most_popular_cuisine(&cyprus, &greece, &Menu);
                m8->total_orders(&quantity,&totalorders);

            break;              
        }
    
        Total_price* t1 = new Total_price(name,location,phone,Menu, orderTypeStr,total);
        
        
        r.addcustomer(t1);
        r.example();

    
       }   
       
    
     else{
            
         cout<<"Calisti"<<endl;

            switch (Menu)
        {

        case 1: 
           cout << "How many Gyros do you want: ";
             cin >> quantity;
             total = m1->pricecalculater(quantity);
                
             m1->Most_popular_cuisine(&cyprus, &greece, &Menu);
             m1->total_orders(&quantity,&totalorders);
            break;
        case 2:
            
             cout << "How many Lamp souvlaki do you want: ";
             cin >> quantity;
             total = m2->pricecalculater(quantity);
                   m2->Most_popular_cuisine(&cyprus, &greece, &Menu);
                m2->total_orders(&quantity,&totalorders);

                  
            break;

        case 3:
        cout << "How many Dolmadakia do you want: ";
             cin >> quantity;
             total = m3->pricecalculater(quantity);
                   m3->Most_popular_cuisine(&cyprus, &greece, &Menu);
                    m3->total_orders(&quantity,&totalorders);

             break;
        
        case 4:
         cout << "How many Grilled octopus do you want: ";
             cin >> quantity;
             total = m4->pricecalculater(quantity);
                  m4->Most_popular_cuisine(&cyprus, &greece, &Menu);
                    m4->total_orders(&quantity,&totalorders);
            break;
            case 5:
         cout << "How many Makaronia tou Fournou do you want: ";
             cin >> quantity;
             total = m5->pricecalculater(quantity);
                   m5->Most_popular_cuisine(&cyprus, &greece, &Menu);
                m5->total_orders(&quantity,&totalorders);

            break; 

            case 6:
         cout << "How many Sheftalies do you want: ";
             cin >> quantity;
             total = m6->pricecalculater(quantity);
                   m6->Most_popular_cuisine(&cyprus, &greece, &Menu);
                     m6->total_orders(&quantity,&totalorders);

            break;   

            case 7:
         cout << "How many Koubes do you want: ";
             cin >> quantity;
             total = m7->pricecalculater(quantity);
                   m7->Most_popular_cuisine(&cyprus, &greece, &Menu);
                   m7->total_orders(&quantity,&totalorders);
                break; 

            case 8:
         cout << "How many Ofto Kleftiko do you want: ";
             cin >> quantity;
              total = m8->pricecalculater(quantity);
                m8->Most_popular_cuisine(&cyprus, &greece, &Menu);
                 m8->total_orders(&quantity,&totalorders);

            break;              
        }
    
        Total_price* t1 = new Total_price(name,location,phone,Menu, orderTypeStr,total);
        
        
        r.addcustomer(t1);
        r.example();
        }
   
        break;
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

   

   void printmenu() // I will delet the cola
   {

            m1 = new Menu_sales("Greece", "Gyros","yes", 15,4,1);
             m2 = new Menu_sales("Greece", "Lamp souvlaki","yes", 14,5,2);
            m3 = new Menu_sales("Greece", "Dolmadakia","yes", 16,3,3);
            m4 = new Menu_sales("Greece", "Grilled octopus","yes", 20,2,4);
            m5 = new Menu_sales("Cyprus", "Makaronia tou Fournou","yes", 13,5,5);
            m6 = new Menu_sales("Cyprus", "Sheftalies","yes", 12,4,6);
             m7 = new Menu_sales("Cyprus", "Koubes","yes", 14,4,7);
            m8 = new Menu_sales("Cyprus", "Ofto Kleftiko","yes",12,5,8);
       
 
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
            cout<<"5: Most popular cuisine"<<endl;
            cout<<"6: Most popular item"<<endl;
            cout<<"7: Loyal Customer"<<endl;
            cout<<"8: Total order"<<endl;
            cout<<"9: Load from file"<<endl;
            cout <<"10 : Save and Quit"<<endl;
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
