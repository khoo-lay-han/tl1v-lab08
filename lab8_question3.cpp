#include <iostream>
#include <string> 

void displayLines(char type, int count)
{
    printf_s("\n");

    for (int i = 0; i != count; i++)
        printf_s("%c", type);
}

class Ticket
{
public:
    Ticket(float _price = 10) 
        : price(_price) 
    {}

    void setTickets()
    {
        std::cout << "Please enter number of tickets to purchase: ";
        std::cin >> no;
    }

    friend class Student;

private:
    int no;
    float price;
};

class Student
{
public:
    void setStudent()
    {
        std::cout << "\nEnter ID: ";
        std::cin >> id;
        std::cout << "Enter Name: ";
        std::cin >> name;
    }

    void ticketEntry()
    {
        std::cout << "Do you want to purchase charity tickets? [Enter Y or N]: ";
        std::cin >> userInput;
        
        if (userInput == 'Y')
        {
            purchase = "Yes";
            p.setTickets();
        }
        else
        {
            purchase = "No";
            std::cout << "-------No ticket purchased-------\n";
        }
    }

    void display()
    {
        displayLines('-', 25);
        std::cout << "\nSTUDENT DETAILS";
        displayLines('-', 25);

        std::cout << "\nID   : " << id << "\nName : " << name << "\n"; 
        
        displayLines('-', 25);
        std::cout << "\nADDITIONAL DETAILS";
        displayLines('-', 25);

        if (purchase == "Yes")
        {
            std::cout << "\nYou've purchased " << p.no
                << " Tickets\nTotal amount : RM " 
                << p.price * p.no << "\n\n"; 
        }
        else 
        {
            std::cout << "\nYou've not purchased any tickets\n";
        }
    }

private:
    char userInput;
    std::string id;
    std::string name;
    std::string purchase;
    Ticket p;
};

int main()
{
    Student student[3];
    
    for (int i = 0; i != 3; i++)
    {
        student[i].setStudent();
        student[i].ticketEntry();
        student[i].display();
    }
}