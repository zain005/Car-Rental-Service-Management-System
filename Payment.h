class Payment
{
private:
		int total_charge;
		int penalty;
		int amountReceived;
		int rent_id;
public:
	void Receipt(Reservation &book, train &d, Guest &cust, AddOnItem &ad, int charge, int type)
	{
		string cust_name,item;
		int row;
		system("cls");
		cout <<"\t*********************************************************************"<< endl;
		cout <<"\t\t\t\t  WELCOME TO"<< endl;
		cout <<"\t\t\t  Railway Ticket Booking System" <<endl;
		cout <<"\t*********************************************************************\n"<< endl;
		cout <<"\t\t\t\t     RECEIPT"<< endl;
		cust_name=book.BillCust(type);
		row=book.BillVe(type);
		item=book.BillIt(type);
		cust.BillDetail(cust_name);
		d.BillDetail(row);

		if(item!="")
		{
		cout << "\t\t\t"<<item ;
		cout<<"	: RM 10"  << endl;
		}
		cout <<"\t*********************************************************************\n"<< endl;
		cout << left << setw(25) <<"\t\t TOTAL AMOUNT RECEIVED " << " : RM " << charge << endl;
		cout << left << setw(25) <<"\t\t TOTAL CHARGED " << " : RM " << total_charge << endl;
		cout << "\t\t ^^^^^^^^^^^^^^^ THANKS YOU ! ^^^^^^^^^^^^^^^^^^^^^ " << endl;
		cout << "\t\t ^^^^^^^^^^^^^ Please Come Again ! ^^^^^^^^^^^^^^^^ " << endl;
	}

	int Return(Reservation &book, train &d) {
		cout << "\t *********************** PAYMENT ****************** " << endl;
		cout << left << setw(25) << "\t\tEnter Rental Number" << " : " ;
		cin >> rent_id;
		int a=book.checking(d, rent_id,total_charge,penalty);
		switch(a)
		{
		case 1:
			{
				return 0;
				break;
			}
		}
		cout << "\n\t\t********************* Payment ********************" << endl;
		cout << "\t\t\t 1. Cash " << endl;
		cout << "\t\t\t 2. Card " << endl;
		cout << "\t\t\t Your Option : " ;
		return rent_id;
	}
	int Cash()
	{
		cout << "\n\t\tEnter Amount Received : \t\t RM    ";
		cin >> amountReceived;
		if (amountReceived > total_charge)
		cout << "\n\t\tBalance : \t\t\t\t RM    " << amountReceived - total_charge;
		cout << "\n\t\t****************** Payment Done! *************" << endl;
		cout << " \t\tGenerating Receipt! " << endl;
		system("pause");
		return total_charge;
	}

	int Card()
	{
		int card_number;
		int cvv;
		cout << "\n\t\t Card Number (last 4 digit) :  ";
		cin >> card_number;
		cout << "\n\t\t CVV Number :  ";
		cin >> cvv;
		cout << "\n\t\tEnter Amount Received : \t\t RM    ";
		cin >> amountReceived;
		cout << "\n\t\t****************** Payment Done! *************" << endl;
		cout << " \t\tGenerating Receipt! " << endl;
		system("pause");
		return total_charge;
	}
};
