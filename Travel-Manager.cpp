#include<iostream>    // To include i/p-o/p file
#include<fstream>     // To handle our files
#include<iomanip>     // To show floating point values
#include<windows.h>

using namespace std;
void menu();

class ManageMenu{
    protected : 
        string userName;     // Hide admin name

    public:
        ManageMenu(){
            system("color 0A");    // change terminal color
            cout << "\n\n\n\n\n\n\n\n\n\t Enter your name to continue as an admin : ";
            cin >> userName;
            system("CLS");
            menu();
        }
        ~ManageMenu(){};
};


class Customers{
    public :
        string name, gender, address;
        int age, MobileNo;
        static int CusID;
        char all[999];

        void GetDetails(){

            ofstream out("old-customer.txt", ios::app);{
                cout << "Enter Customer ID : " << endl;
                cin >> CusID;
                cout << endl << "Enter name : ";
                cin >> name;
                cout << endl << "Enter age : ";
                cin >> age;
                cout << endl << "Enter mobile number : " ;
                cin >> MobileNo;
                cout << endl << "Enter gender : ";
                cin >> gender;
                cout << endl << "Enter address : ";
                cin >> address;
            }

            out << "\nCustomer ID : " << CusID << "\nName : " << name << "\nAge" << age << "\nMobile number : " << MobileNo << "\nAddress" << address << "\nGender : " << gender << endl;
            out.close();
            cout << "\nSaved \nNote : We save your details for future record purposes\n" << endl;

        }

        void ShowDetails(){

            ifstream in("old-customers.txt");{

                if(!in){
                    cout << "File error!" << endl;
                }
                while(!(in.eof())){
                    in.getline(all, 999);
                    cout << all << endl;
                }

            }

        }
};

int Customers :: CusID;

class Cabs{

    public :
        int cabChoice;
        int kilometers;
        float cabCost;
        static float lastCabCost;

        void cabDetails(){
            cout << "We collaborated with fastest, safest, and smartest cab service around the country" << endl;
            cout << "-----------ABC Cabs-----------\n" << endl;
            cout << "1. Rent a standard Cab - Rs.15 for 1km" << endl;
            cout << "2. Rent a Luxury Cab - Rs.25 per 1km" << endl;

            cout << "\nTo calculate the cost for your journey : " << endl;
            cout << "Enter which kind of cab you need : ";
            cin >> cabChoice;
            cout << "Enter kilometers you have to travel : ";
            cin >> kilometers;

            int hireCab;

            if(cabChoice == 1){
                cabCost = kilometers * 15;
                cout << "\nYour tour cost " << cabCost << "rupees for a standard cab" << endl;
                cout << "Press 1 to hire this cab : or" << endl;
                cout << "Press 2 to select another cab : ";
                cin >> hireCab;

                system("CLS");
                if(hireCab == 1){
                    lastCabCost = cabCost;
                    cout << "\nYou have successfully hired a standard cab" << endl;
                    cout << "Goto Menu and take the receipt" << endl;
                }
                else if (hireCab == 2){
                    cabDetails();
                }
                else{
                    cout << "Invalid Input! Redirecting to previous menu \nPlease wait!" << endl;
                    Sleep(999);
                    system("CLS");
                    cabDetails();
                }
            }

            else if (cabChoice == 2){

                cabCost = kilometers * 25;
                cout << "\nYour tour cost " << cabCost << "rupees for a luxury cab" << endl;
                cout << "Press 1 to hire this cab : or" << endl;
                cout << "Press 2 to select another cab : ";
                cin >> hireCab;

                system("CLS");
                if(hireCab == 1){
                    lastCabCost = cabCost;
                    cout << "\nYou have successfully hired a luxury cab" << endl;
                    cout << "Goto Menu and take the receipt" << endl;
                }
                else if (hireCab == 2){
                    cabDetails();
                }
                else{
                    cout << "Invalid Input! Redirecting to previous menu \nPlease wait!" << endl;
                    Sleep(1100);
                    system("CLS");
                    cabDetails();
                }

            }
            else{
                cout << "Invalid Input! Redirecting to Main Menu \nPlease Wait!" << endl;
                Sleep(1100);
                system("CLS");
                menu();
            }

            cout <<"\nPress 1 to Redirect Main menu : ";
            cin >> hireCab;
            system("CLS");
            if(hireCab == 1){
                menu();
            }
            else{
                menu();
            }
        }
};

float Cabs :: lastCabCost;

class Booking{

    public :
        int choiceHotel, packChoice;
        static float hotelCost;

        void hotels() {
            string hotelNo[] = {"Avendra", "ChoiceYou", "ElephantBay"};
            for(int a = 0; a < 3; a++){
                cout << (a+1) << ". hotel" << hotelNo[a] << endl;
            }

            cout << "\nCurrently we collaborated with above hotels" << endl;

            cout << "Press any key to back or\nEnter number of the hotel you want to book : ";
            cin >> choiceHotel;

            system("CLS");

            if(choiceHotel == 1){
                cout << "-------WELCOME TO HOTEL AVENDRA-------\n"  << endl;

                cout << "The Garden, food and beverage. Enjoy all you can drink, stay cool and get chilled in the summer sun." << endl;

                cout << "Packages offered by Avendra :\n" << endl;

                cout << "1. Standard Pack" << endl;
                cout << "\tAll basic facilities you need just for : Rs. 5000.00" << endl;
                cout << "2. Premium Pack" << endl;
                cout << "\tEnjoy Premium : Rs.10000.00" << endl;
                cout << "3. Luxury Pack" << endl;
                cout << "\tLive a luxury at Avendra : Rs.15000.00" << endl;

                cout << "\nPress another key to back or\nEnter package number you want to book : ";
                cin >> packChoice;

                if (packChoice == 1){
                    hotelCost = 5000.00;
                    cout << "\nYou have successfully booked Standard Pack at Avendra" << endl;
                    cout << "Goto Menu and take the receipt" << endl;
                }
                else if (packChoice == 2){
                    hotelCost = 10000.00;
                    cout << "\nYou have successfully booked Premium Pack at Avendra" << endl;
                    cout << "Goto Menu and take the receipt" << endl;
                }
                else if (packChoice == 3){
                    hotelCost = 15000.00;
                    cout << "\nYou have successfully booked Luxury Pack at Avendra" << endl;
                    cout << "Goto Menu and take the receipt" << endl;
                }
                else{
                    cout << "Invalid Input! Redirecting to previous menu \nPlease wait!" << endl;
                    Sleep(1100);
                    system("CLS");
                    hotels();
                }

                int gotomenu;
                cout << "\nPress 1 to redirect main menu : ";
                cin >> gotomenu;
                if (gotomenu == 1){
                    menu();
                }
                else{
                    menu();
                }

            }

            if(choiceHotel == 2){
                cout << "-------WELCOME TO HOTEL ChoiceYou-------\n"  << endl;

                cout << "The Garden, food and beverage. Enjoy all you can drink, stay cool and get chilled in the summer sun." << endl;

                cout << "Packages offered by ChoiceYou :\n" << endl;

                cout << "1. Family Pack" << endl;
                cout << "\tAll basic facilities you need just for : Rs. 15000.00" << endl;
                cout << "2. Couple Pack" << endl;
                cout << "\tEnjoy Couple : Rs.10000.00" << endl;
                cout << "3. Single Pack" << endl;
                cout << "\tLive single at ChoiceYou : Rs.5000.00" << endl;

                cout << "\nPress another key to back or\nEnter package number you want to book : ";
                cin >> packChoice;

                if (packChoice == 1){
                    hotelCost = 15000.00;
                    cout << "\nYou have successfully booked Family pack at ChoiceYou." << endl;
                    cout << "Goto Menu and take the receipt" << endl;
                }
                else if (packChoice == 2){
                    hotelCost = 10000.00;
                    cout << "\nYou have successfully booked Couple Pack at ChoiceYou" << endl;
                    cout << "Goto Menu and take the receipt" << endl;
                }
                else if (packChoice == 3){
                    hotelCost = 5000.00;
                    cout << "\nYou have successfully booked single Pack at ChoiceYou" << endl;
                    cout << "Goto Menu and take the receipt" << endl;
                }
                else{
                    cout << "Invalid Input! Redirecting to previous menu \nPlease wait!" << endl;
                    Sleep(1100);
                    system("CLS");
                    hotels();
                }

                int gotomenu;
                cout << "\nPress 1 to redirect main menu : ";
                cin >> gotomenu;
                if (gotomenu == 1){
                    menu();
                }
                else{
                    menu();
                }
            }
            if(choiceHotel == 3){
                cout << "-------WELCOME TO HOTEL ElephantBay-------\n"  << endl;

                cout << "The Garden, food and beverage. Enjoy all you can drink, stay cool and get chilled in the summer sun." << endl;

                cout << "Packages offered by ElephantBay :\n" << endl;

                cout << "1. Special Pack" << endl;
                cout << "\tAll basic facilities you need just for : Rs. 15000.00" << endl;
                cout << "2. Couple Pack" << endl;
                cout << "\tEnjoy Couple : Rs.10000.00" << endl;
                cout << "3. Single Pack" << endl;
                cout << "\tLive single at ChoiceYou : Rs.5000.00" << endl;

                cout << "\nPress another key to back or\nEnter package number you want to book : ";
                cin >> packChoice;

                if (packChoice == 1){
                    hotelCost = 5000.00;
                    cout << "\nYou have successfully booked ElephantBay Special Pack." << endl;
                    cout << "Goto Menu and take the receipt" << endl;
                }
                else if (packChoice == 2){
                    hotelCost = 10000.00;
                    cout << "\nYou have successfully booked Couple Pack at ElephantBay" << endl;
                    cout << "Goto Menu and take the receipt" << endl;
                }
                else if (packChoice == 3){
                    hotelCost = 5000.00;
                    cout << "\nYou have successfully booked single Pack at ElephantBay" << endl;
                    cout << "Goto Menu and take the receipt" << endl;
                }
                else{
                    cout << "Invalid Input! Redirecting to previous menu \nPlease wait!" << endl;
                    Sleep(1100);
                    system("CLS");
                    hotels();
                }

                int gotomenu;
                cout << "\nPress 1 to redirect main menu : ";
                cin >> gotomenu;
                if (gotomenu == 1){
                    menu();
                }
                else{
                    menu();
                }
            }
        }
};


float Booking :: hotelCost;

class Charges : public Booking, Cabs, Customers{
    public :
        void printBill(){

            ofstream outf("receipt.txt");{

                outf << "----------ABC Travel Agency---------" << endl;
                outf << "-------------Receipt----------------" << endl;
                outf << "____________________________________" << endl;

                outf << "Customer ID : " << Customers::CusID << endl << endl;
                outf << "Description\t\t Total" << endl;
                outf << "Hotel cost:\t\t " << fixed << setprecision(2) << Booking::hotelCost << endl;
                outf << "Travel (cab) cost :\t " << fixed << setprecision(2) << Cabs::lastCabCost << endl;
                outf << "____________________________________" << endl;
                outf << "Total Charge : \t\t" << fixed << setprecision(2) << Booking::hotelCost+Cabs::lastCabCost << endl;
                outf << "____________________________________" << endl;
                outf << "-------------THANK YOU--------------" << endl;
            }

            outf.close();

        }

        void showBill(){
            ifstream inf("receipt.txt");{
                if(!inf){
                    cout << "File opening error!"<< endl;
                }
                while(!(inf.eof())){
                    inf.getline(all, 999);
                    cout << all << endl;
                }
            }
            inf.close();
        }
};

void menu(){

    int mainChoice, inChoice, gotomenu;

    cout << "\t\t           *ABC Travels *\n" << endl;
    cout << "--------------------------MAIN MENU--------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|\tCustomer Management -> 1\t|" << endl;
    cout << "\t|\tCabs Management     -> 2\t|" << endl;
    cout << "\t|\tBookings Management -> 3\t|" << endl;
    cout << "\t|\tCharges & Bill      -> 4\t|" << endl;
    cout << "\t|\tExit                -> 5\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;

    cout << "\nEnter your choice : ";
    cin >> mainChoice;

    system("CLS");

    Customers a2;
    Cabs a3;
    Booking a4;
    Charges a5;

    if(mainChoice == 1){
        cout << "------Customers-------\n" << endl;
        cout << "1. Enter new customer" << endl;
        cout << "2. See old customers" << endl;

        cout << "\nEnter choice : ";
        cin >> inChoice;

        system("CLS");
        if(inChoice == 1){
            a2.GetDetails();
        }
        else if (inChoice == 2){
            a2.ShowDetails();
        }
        else {
            cout << "Invalid Input! Redirecting to previous menu  \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }

        cout << "\nPress 1 to Redirect main menu";
        cin >> gotomenu;
        system ("CLS");
        if(gotomenu == 1){
            menu();
        }
        else{
            menu();
        }
    }
    else if (mainChoice == 2){
        a3.cabDetails();
    }
    else if (mainChoice == 3){
        cout << "--> Book a luxury hotel using the system <--" << endl;
        a4.hotels();
    }
    else if (mainChoice == 4){
        cout << "-->Get your receipt <--" << endl;
        a5.printBill();

        cout << "Your receipt is already printed. You can get it from file path\n" << endl;
        cout << "To display your receipt in the screen, enter 1 or enter any key to back main menu : ";

        cin >> gotomenu;

        if (gotomenu == 1){
            system("CLS");
            a5.showBill();
            cout << "\nPress 1 to redirect main menu : ";
            cin >> gotomenu;
            system("CLS");
            if(gotomenu ==1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            system("CLS");
            menu();
        }

    }
    else if(mainChoice == 5){
        cout << "--GOOD-BYE--" << endl;
        Sleep(999);
        system("CLS");
        menu();
    }
    else{
        cout << "Invalid Input! Redirecting to previous menu  \nPlease Wait!" << endl;
        Sleep(1100);
        system("CLS");
        menu();
    }

}

int main(){
   
    ManageMenu startobj;

    return 0;
}