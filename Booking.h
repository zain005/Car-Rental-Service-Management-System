struct node5
{
		string cust_name;
		string car_make;
		string payment ;
		int rental_no;
		int rent_rate;
		int total_fare;
		int row;
		string rowItem;
		node5 *next;
};

int choice1, choice2, choice3,customer_id;
char choice4;
int GenerateBID = 1000;
int option1 = 0;
string name;
bool Error = false;
bool Status = false;

class Reservation
{
private:
	int reId;
	int ReservationDate[3];
	int ReturnDate[3];
	string location;
	struct node5 *head;
	struct node5 *tail;

public:
	void rental(train &d,Guest &cust, AddOnItem &ad, int &i);
	string BillCust(int type)
	{
		node5 *pointer = head;

		while (pointer != NULL)
		{
			if (type == pointer->rental_no)
			{
				return pointer->cust_name;
			}
			pointer = pointer->next;
		}
	}
	int BillVe(int type)
	{
		node5 *pointer = head;

		while (pointer != NULL)
		{
			if (type== pointer->rental_no)
			{
				return pointer->row;
			}
			pointer = pointer->next;
		}
	}
	string BillIt(int type)
	{
		node5 *pointer = head;

		while (pointer != NULL)
		{
			if (type== pointer->rental_no)
			{
				return pointer->rowItem;
			}
			pointer = pointer->next;
		}
	}
	void ReportView()
	{
		cout << "\t\t **************** Report View *****************" << endl << endl;
		int grandTotal=0;
		node5 *pointer = head;

			cout << "\t\t" << left << setw(20) << "Ticket ID";
			cout << left << setw(25) << "Train Make";
			cout << left << setw(20) << "Total Charge"  << endl;
			cout << "\t\t-------------------------------------------------------------------" << endl;
		if (head == NULL)
		{
			cout << "\nList is empty.";
		}
		else
		{
		while (pointer != NULL)
		{
			if(pointer->payment=="Succeed")
			{
				cout  << "\t\t"  << left << setw(20) << pointer->rental_no;
				//cout << left << setw(25) << pointer->car_make;
				cout << "RM "<< left << setw(20) << pointer->total_fare << endl;
				grandTotal+=pointer->total_fare;
			}
		pointer = pointer->next;
		}
		}
		cout << "\t\t------------------------------------------------------------------- " << endl;
		cout << "\t\t" << left << setw(45)  << "GRAND TOTAL : " << " RM " << grandTotal << endl;
		system("pause");
	}
	int checking(train &d, int rent_id, int &total_charge, int &pen){
		node5 *pointer = head;
		char drop;
		string pen_detail;
		while (pointer != NULL)
		{
			if ( rent_id == pointer->rental_no && pointer->payment == "Pending" )
			{
				cout << left << setw(25) << "\t\tCustomer Name" << " : " << pointer->cust_name << endl;
				//cout << left << setw(25) << "\t\tTrain make" << " : "<< pointer->car_make << endl;
				cout << left << setw(25) << "\t\tPayment Status"<< " : " << pointer->payment << endl;
				cout << left << setw(25) << "\t\tPrice"<< " : RM " << pointer->rent_rate << endl;
				cout << left << setw(25) << "\t\tEstimated Total" << " : RM " << pointer->total_fare << endl;
				cout << "\t\t*******************************************" << endl;
				cout << "\t\t Confirm Payment [Y/N] : " ;
				cin >> drop;
				if(drop=='Y' || drop=='y' )
				{
					d.Return(pointer->row);
				}
				else
				{
					cout <<"\t\t Payment Process Cancelled! " <<endl;
					system("pause");
					break;
				}
				cout << "\n\t\tSeats are now available for booking!" << endl;
				cout << "\t\tContinue to Proceed with Payment!\n\t" ;
				system("pause");
				system("cls");
				cout << "\t\t********************* Payment *****************" << endl;
				cout << "\t\tEnter Penalty Amount (if any) : RM ";
				cin >> pen;

				if (pen > 1)
				{
					cout << "\t\tEnter Penalty Details : ";
					cin.ignore();
					getline(cin, pen_detail);
				}
				cout << "\n\t\t********************* Payment ********************" << endl;
				cout << "\t\t Price :\t\t RM " << right << setw(6)<< pointer->rent_rate << endl;
				//cout << "\t\t Number of Day Rent    :\t\t    " << right << setw(6) << (pointer->total_fare/pointer->rent_rate) << endl;
				//cout << "\t\t Penalty Amount        :\t\t RM " << right << setw(6)<< pen << endl;
				if(pointer->rowItem!="")
				cout << "\t\t Add On Item	        :\t\t RM " << right << setw(6)<< "10" << endl;
				cout << "\t\t Deposit Amount        :\t\t-RM " << right << setw(6)<< pointer->total_fare*0.2 << endl;
				cout << "\t\t -------------------------------------------------" << endl;
				cout << "\t\t TOTAL CHARGE          :\t\t RM "<< right << setw(6) << (pointer->total_fare - (pointer->total_fare*0.2) + pen) << endl;
				total_charge=(pointer->total_fare - (pointer->total_fare*0.2) + pen) ;
				pointer->total_fare=total_charge + (pointer->total_fare*0.2);
				pointer->payment = "Succeed";
				return 0;
			}
			else if(rent_id == pointer->rental_no && pointer->payment=="Succeed")
			{
				cout <<"\n Error! Payment for Ticket " << pointer->rental_no << " had already made !" << endl;
				system("pause");
				system("cls");
				return 1;

			}
			pointer = pointer->next;

		}
		cout<<"\n Enter Invalid Ticket ID  ! " << endl;
		cout<<"\n Sorry! The system is terminating! " << endl;
		system("pause");
		system("cls");
		return 1;
	}

	void deposit(int calculate);
	static const int count = 1;
	Reservation()//construtor of class vehicle
	{
		head = tail = NULL;
	}

};

void Reservation::deposit(int calculate)
{
	float dep;
	system("cls");
	cout << "\t **************** Pay Deposit ******************* " << endl;
	cout << "\t Estimated Total Fares : \tRM " << calculate << endl;
	cout << "\t Deposit Payable Amount : \tRM " << calculate*0.2 <<endl;
	cout << "\t Enter Deposit Amount : \tRM " ;
	cin >> dep ;
	cout << "\n\t Deposit paid! Booking done! Generating Invoice!\n\t" ;
}
void Reservation::rental(train &d, Guest &cust, AddOnItem &ad, int &i)
{
			node5 *pointer = new node5;
			cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
			cout << "*                                Booking Ticket                               *\n";
			cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
			cout << "                                 1. New Booking" << endl;
			cout << "                                 2. View Booking" << endl;
			cout << "                                 3. Return to Main Menu" << endl;
			cout << "\n\n                                 Your option : ";

			cin >> option1;
			if(i==1)
			{
				head =tail =NULL;
					i++;
			}

			switch(option1){
				case  1: //new reservation
				{
					reId = GenerateBID;
					GenerateBID+=1;
					pointer->rental_no=reId;
					system("cls");
					cout << "\t\t***************** RESERVATION ******************** " << endl;
					cout <<"\n\t\t\tEnter customer ID : ";
					name = cust.Details();
					if(name=="")
						name=cust.AddNewGuest();
					pointer->cust_name=name;
				D:	cout << "\n\n\t\t\tEnter Reservation Date(dd/mm/yyyy)	: ";
					std::cin >> ReservationDate[0] ;
					cin.get();
					std::cin >> ReservationDate[1] ;
					cin.get();
					std::cin >> ReservationDate[2] ;
					if(ReservationDate[0]>31 || ReservationDate[1] > 12 || ReservationDate[2] <2017)
					{
						cout << "\t\t\tInvalid Date! Enter Again ! " <<endl;
						goto D;
					}
				E:	cout << "\n\n\t\t\tEnter Return Date(dd/mm/yyyy)		: ";
					std::cin >> ReturnDate[0] ;
					cin.get();
					std::cin >> ReturnDate[1] ;
					cin.get();
					std::cin >> ReturnDate[2] ;
					if(ReturnDate[0]>31 || ReturnDate[1] > 12 || ReturnDate[2] <2017)
					{
						cout << "\t\t\tInvalid Date! Enter Again ! " <<endl;
						goto E;
					}
					cout << "\n\n\t\t\tTotal Day : "<< ReturnDate[0]-ReservationDate[0];

					cout << "\n\n\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
					cout << "\t*                          Available Seats List                                 *\n";
					cout << "\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n";
					d.GetTrainList();
					cout<<"\n\t *NOTE: Seats will be random given, choose only what type of train that are available." << endl;
					cout << "\n\t\t\tEnter Seats (Row) : ";
					cin >> choice3;
					int calculate;
					cin.ignore();
					calculate=d.TrainReservation(choice3);
					pointer->row = choice3;
					pointer->rent_rate=calculate;
					calculate*=(ReturnDate[0]-ReservationDate[0]);
					cout << "\n\t\t\tEnter Departure  : " ;
					getline(cin, location);
					cout << "\n\n\t\t\tTicket Successfully Booked! " << endl;
					cout << "\n\tDo You Wish to Add On Item? [Y/N] : ";
					cin >> choice4;
					if(choice4=='Y' || choice4=='y')
					{

						ad.GetAddOnItemList();
						cout << "\n\t\t\tEnter the Item you like to add (row) : ";
						cin >> choice1;
						string addItem=ad.AddItemDetail(choice1);
						cout << "\t\t\tItem Selected : " << addItem << endl;
						pointer->rowItem=addItem;
						system("pause");
						calculate += 10;

					}
					pointer->total_fare=calculate;
					deposit(calculate);
					system("pause");
					system("cls");
					cout << "\n\t\t*********************** Invoice ********************* \n" << endl ;
					cout << left << setw(25) <<"\t\tTicket ID" << " : " << reId << endl;
					cout << left << setw(25) <<"\t\tName" << " : " << name << endl;
					cout << left << setw(25) <<"\t\tDepature" << " : " << location << endl;
					cout << left << setw(25) <<"\t\tNumber of Day Travelling" << " : " << ReturnDate[0]-ReservationDate[0] << endl;
					d.TrainReservation(choice3);
					cout << "\n\t\t*********************** Invoice ********************* \n" << endl <<"\t\t" ;

					pointer->payment="Pending";
					pointer->next = NULL;
					if (head == NULL)
					{
							head = pointer;
					}
					else
					{
						tail->next = pointer;
					}	tail = pointer;

					system("pause");
					break;
				}

					case 2: //view reservation
					{
						cout << "\n\n\t\t ************** Booking List **********" << endl << endl;
						node5 *pointer = head;
						if (head == NULL)
						{
							cout << "\nList is empty.";
						}
						else
						{
							while (pointer != NULL)
							{
								cout << "\n\t\tTicket ID \t: \t" << left << setw(20) << pointer->rental_no;
								cout << "\n\t\tCustomer Name \t: \t" << left << setw(20) << pointer->cust_name;
								//cout << "\n\t\tCar Detail \t: \t" << left << setw(20) << pointer->car_make;
								cout <<"\n\t\tPrice\t: \tRM " <<  left << setw(20) << pointer->rent_rate;
								cout << "\n\t\tTotal Fare \t: \tRM " << left << setw(15) << pointer->total_fare;
								cout << "\n\t\tPayment Status \t: \t"<< left << setw(20) << pointer->payment << endl;
							pointer = pointer->next;
							}
						}
						system("pause");
						break;
					}
					}

}
