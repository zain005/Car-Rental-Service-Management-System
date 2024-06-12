//  Project OOSD - Railway Ticket Booking System
//  Group Member:
//  Jong Soon Seng (56236) , Yii Shun Teng (58345) , Choo Zhin Jit (55733) ,
//  ABOBAKR AHMED AL-SAKKAF  (60062), SARDORJON MIRZAKARIMOV (55278)

//  Login for Admin
//        Username: admin
//        Password: admin

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <windows.h>
#include <time.h>

using namespace std;

#include "Employee.h"
#include "Vehicle.h"
#include "Addonitem.h"
#include "Guest.h"
#include "Feedback.h"
void AntiChar();
#include "Booking.h"
#include "Payment.h"
//#include "Report.h"
vector<Reservation>bookList; //Store reservation


void Login();

int main()
{
	int z=1;
	int main_option;
	//Report report;
	Feedback fb;
	AddOnItem ad;
	ad.DefineAddOnItem();
	Guest cust;
	cust.DefineGuest();
	train *ve;
	train d;
	d.DefineTrain();
	Reservation book;
	Payment p;

	admin emp_M[3] = { admin("Abu", "0138122311", "Administrator", "1001"), admin("Albert", "0165555528", "Administrator", "1002") };
	staff emp_S[5] = { staff("Jaefer", "0191231231", "Staff", "2001"), staff("Eada Ting Yi Ling", "0123321578", "Staff", "2002") };
	string name, contact, position, id_num, id_num2, f;
	int i = 2;
	int j = 2;
	const char seperator = ' ';
	const int nameWidth = 20;
	const int numWidth = 20;
	int option, pos;

	int choice = 0;

	//Main menu for the programme
	system("cls");
	system("COLOR A");  //yellow colour font for the menu
	cout << endl << endl;
	cout <<"\t*********************************************************************"<< endl;
	cout <<"\t\t\t\t  WELCOME TO"<< endl;
	cout <<"\t\t\t  RAILWAY TICKET BOOKING SYSTEM" <<endl;
	cout <<"\t*********************************************************************\n"<< endl;
	cout <<"\t--------------\n\t  MAIN MENU  \n\t--------------\n"<< endl;
	cout <<"\t[1] LOGIN "<< endl;
	cout <<"\t[2] EXIT "<< endl;
	cout <<endl<<endl;

	do{
		cout <<"\tInstruction:\n\n";
		cout <<"\tEnter 1 to enter the system.\n\tEnter 2 to exit the system."<<endl;
		cout <<"\n\tNOTE: \n\tPlease enter either \"1\" or \"2\"."<<endl;
		cout <<"\n\tPlease enter your choice <1 or 2> : " ;                   //Enter choice for which event to song details or exit
		while(!(cin >> main_option))
		{
			cout <<"\n\n\tERROR: Please enter a number!  Please try again.\n\n\tPlease enter your choice <1 or 2> : ";
			cin.clear ();
			cin.ignore (1000, '\n');
		}
		//Enter the song record system
		if(main_option==1){
			system("cls");
			//Straight to Main Menu
		}

		//Totally exit from system
		else if(main_option==2)
		{
			system("cls");
			cout<<endl<<endl<<endl;
			cout<<"\t\t\t\t\t\t  ****** System EXIT ******\n\n\t\t\t\t\t";
			system("pause");
			exit(0);
		}

		//Error occur when user input the wrong input
		else
		{
			system("cls");
			cout <<"\n\n\tYour input: "<< main_option;
			cout <<"\n\n\tERROR:\n\tWrong Input. Please follow the instruction and try again.\n\n";
		}
	}while(main_option !=1 && main_option !=2);

	while (choice != 9)
	{
		system("CLS");
		cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
		cout << "*                             RAILWAY TICKET BOOKING SYSTEM                     *\n";
		cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";

		cout << "\n\n                         Select:" << endl;
		cout << "                                 1. Reservation **" << endl;
		cout << "                                 2. Admin Only**" << endl;
		cout << "                                 3. Feedback" << endl;
		cout << "                                 4. Payment***" << endl;
		cout << "                                 5. Exit **" << endl;
		cout << "                                 ----> ";

		cin >> choice;
		if (choice < 1 || choice>5 || !cin.good())
		{
			AntiChar();
			cout << "\n                             Invalid Input!";
			choice = 5;
			system("PAUSE");
		}
		system("CLS");
		switch (choice)
		{
		case 1: //Ticket Booking
		{

			book.rental(d,cust,ad,z); //Create reservation object

		}
		break;

		case 2: //Admin Page
		{
		    Login();
			do
			{
				system("ClS");
				system("cls");
				cout << "\n\n\t\t****EMPLOYEE MENU****" << endl << endl;
				cout << "\t\tPlease enter your option: " << endl;
				cout << "\t\t1. Add new employee" << endl;
				cout << "\t\t2. Edit employee details" << endl;
				cout << "\t\t3. Display employee details" << endl;
				cout << "\t\t4. Add new items" << endl;
				cout << "\t\t5. Edit train" << endl;
				cout << "\t\t6. Main Menu." << endl << endl;
				cout << "\t\tYour option: ";
				cin >> option;

				switch (option)
				{
					case 1:
					do{
						system("CLS");
						cout << "\n\n\t\tPlease select the position for the new employee" << endl;
						cout << "\t\t1. Administrator " << endl;
						cout << "\t\t2. Staff " << endl;
						cout << "\t\t3. Add new items " << endl;
						cout << "\t\t4. Exit to main menu." << endl << endl;
						cout << "\t\tYour option: ";
						cin >> pos;


						if (pos == 1)		//Admin
						{
							cout << endl << "\n\n\t\tPlease enter the name of new admin: ";
							cin.ignore();
							getline(cin, name);
							cout << "\t\tPlease enter the contact number of new admin: ";
							cin >> contact;
							cout << "\t\tPlease re-enter the position of new admin: ";
							cin >> position;
							cout << "\t\tPlease enter the new ID number: ";
							cin >> id_num;

							emp_M[i].addEmployee(name, contact, position, id_num);
							i++;
							cout << endl << "\t\tNew admin details are added." << endl;
						}
						else if (pos == 2)		//staff
						{
							cout << endl << "\t\tPlease enter the name of new staff: ";
							cin.ignore();
							getline(cin, name);
							cout << "\t\tPlease enter the contact number of new staff: ";
							cin >> contact;
							cout << "\t\tPlease re-enter the position of new staff: ";
							cin >> position;
							cout << "\t\tPlease enter the new ID number: ";
							cin >> id_num2;

							emp_S[j].addEmployee(name, contact, position, id_num2);
							j++;
							cout << endl << "\t\tNew staff details are added." << endl;
						}
						else if (pos == 3)
						{
							cout << endl << "Exit to main menu." << endl;
						}

						else
							cout << endl << "Invalid input. Please try again." << endl << endl;
						system("pause");

					} while (pos != 3);

					break;

					case 2:
						edit_emp_detail(emp_M, emp_S);
						break;

					case 3:
						// Display the employee list
						system("CLS");
						cout << "Adminstrator" << endl;
						cout << "..............................................................................." << endl;
						cout << "<Name>	         <Contact no>	     <Position>		<ID no>" << endl;
						cout << "..............................................................................." << endl;

						for (int i = 0; i < 3; i++)
						{
							emp_M[i].display();
						}

						cout << endl << endl << endl << "Staff" << endl;
						cout << "..............................................................................." << endl;
						cout << "<Name>	         <Contact no>	     <Position>		<ID no>" << endl;
						cout << "..............................................................................." << endl;
						for (int j = 0; j < 5; j++)
						{
							emp_S[j].display();
						}
						system("pause");
						break;

                    case 4:
						system("CLS");
						int opt;
                        cout << "\n\n\t\t\t**** ADD ON ITEM MENU ****" << endl << endl;
                        cout << "\t\t\t1. Add New Item" << endl;
                        cout << "\t\t\t2. View Add On Item List " << endl;
                        cout << "\t\t\t3. Back to Main Menu " << endl;
                        cout << "\n\t\t\tYour Option : " ;
                        cin >> opt;
                        if(opt==1)
                        {
                            ad.AddItem(10);
                        }
                        else if(opt==2)
                        {
                            system("cls");
                            ad.GetAddOnItemList();
                        }
                        system("pause");
                        break;

                    case 5:

                        system("cls");
                        int opt2;
                        cout << "" <<endl;
                        cout << "\n\n\t\t\t**** Train Menu ****" << endl << endl;
                        cout << "\n\n\t\t\t1. Add Train" << endl;
                        cout << "\t\t\t2. View Train List " << endl;
                        cout << "\t\t\t3. Delete Train" << endl;
                        cout << "\t\t\t4. Back to Main " << endl;
                        cout << "\n\t\t\tYour choice: ";
                        cin >> opt2;
                        if (opt2 == 1)
                        {
                            system("cls");
                            cout << "\n\n\t\t\t**** Add Train Menu ****" << endl << endl;
                            cout << "\n\n\t\t\tCategory : "<< endl;
                            cout << "\t\t\t1. Class A Seat " << endl;
                            cout << "\t\t\t2. Class B Seat " << endl;
                            cout << "\t\t\t3. Class C Seat " << endl;
                            cout << "\t\t\t4. Budget Seat" << endl;
                            cout << "\n\t\t\tYour choice: ";
                            int cat;
                            int price;
                            cin >> cat;
                            switch(cat) {
                                case 1 : {
                                    Class_A trn;
                                    ve = &trn;
                                    ve -> SetPrice(50);
                                    price = ve->GetPrice();
                                    d.AddTrain(price);
                                    break;}
                                case 2 : {
                                    Class_B trn;
                                    ve = &trn;
                                    ve -> SetPrice(100);
                                    price = ve -> GetPrice();
                                    d.AddTrain(price);
                                    break; }
                                case 3 : {
                                    Class_C trn;
                                    ve = &trn;
                                    ve -> SetPrice(150);
                                    price = ve -> GetPrice();
                                    d.AddTrain(price);
                                    break; }
                                case 4 : {
                                    Class_Budget trn;
                                    ve = &trn;
                                    ve -> SetPrice(10);
                                    price = ve -> GetPrice();
                                    d.AddTrain(price);
                                    break; }
                            }}
                        if (opt2 == 2)
                        {
                            system("cls");
                            d.GetTrainList();
                        }
                        if (opt2 ==3 )
                        {
                            system("cls");
                            d.GetTrainList();
                            d.DisposeTrain();
                        }
                            system("pause");
                    break;

					case 6:
						system("CLS");
						cout << "****EXIT****" << endl;
						break;

					default:
						cout << "Invalid input. Please try again." << endl;
						system("pause");
						system("CLS");
				}
			}while (option != 6);

		}
		break;

		case 3:
		{
			system("cls");
			int opt;
			cout <<"\n\n\t\t\t****** FEEDBACK *****" << endl << endl;
			cout <<"\t\t\t1. Add New Feedback " << endl;
			cout <<"\t\t\t2. View Feedback " << endl;
			cout <<"\t\t\t3. Back to Main Menu " <<endl;
			cout <<"\n\t\t\tYour Option : ";
			cin >> opt;
			if(opt==1)
			{
				fb.AddFeedback();
			}
			else if (opt==2)
			{
				system("cls");
				fb.GetFeedbackList();
			}
			system("pause");
			break;
		}


		case 4:
		{
				int type,charge,select;
				type=p.Return(book, d);
				if(type!=0)
				{
				cin >> select;
				if(select==1)
				{
					charge=p.Cash();
					p.Receipt(book,d,cust,ad,charge,type);

				}
				else if(select==2)
				{
					charge=p.Card();
					p.Receipt(book,d,cust,ad,charge,type);
				}
				}
				system("pause");
				break;
		}
		case 5:
		{
				  exit(0);
				  break;
		}
		default:
			cout << "Invalid input. Please enter again!";
		}


	}
}

void Login(){
    string userName;
    string userPassword;
    int loginAttempt = 0;

    while (loginAttempt < 5)
    {
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\tUsername: ";
        cin >> userName;
        cout << "\t\t\t\t\t\tPassword: ";
        cin >> userPassword;

        if (userName == "admin" && userPassword == "admin")
        {
            cout << "\n\n\n\t\t\t\t\t\tWelcome admin!\n";
            break;
        }
        else
        {
			system("cls");
            cout << "\nInvalid login attempt. Please try again.\n" << '\n';
            loginAttempt++;
        }
    }
    if (loginAttempt == 5)
    {
            cout << "Exceed Login Attemp! The program will now terminate.";
    }

    cout << "\n\n\t\t\t\t\t    Thank you for logging in.\n";
}

void AntiChar()    //Avoid program collapse if character entered instead of INT
{
	cin.clear();
	cin.ignore(30, '\n');
}
