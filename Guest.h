struct node2
	{
		string name;
		string ic;
		string tel;
		string email;
		node2 *next;

	};
class Guest // class for guest information
{
private:
	string name;
	string ic;
	string tel;
	string email;
	struct node2 *head;
	struct node2 *tail;

public:
	string AddNewGuest();
	void GetGuestList();
	void SampleGuest(string name, string ic, string tel, string email);
	void DefineGuest();
	string Details();
	void BillDetail(string cust_name);
	Guest()//construtor of class guest
	{
		head = tail = NULL;
	}
};

	//method : Add New Guest
	string Guest :: AddNewGuest() // add a new guest
	{
		node2 *pointer = new node2;
		cout << "\n\t\t\t**** ADD NEW CUSTOMER ****" << endl;
		cout << "\t\t\tEnter Customer Name : ";
		cin.ignore();
		getline(cin, name);
		pointer->name = name;
		cout << "\t\t\tEnter IC Number : ";
		cin >> ic;
		pointer->ic = ic;
		cout << "\t\t\tEnter Contact Number : " ;
		cin >> tel;
		pointer->tel = tel;
		cout << "\t\t\tEnter Email : " ;
		cin >> email;
		pointer->email = email;
		pointer->next = NULL;
		if (head == NULL)
		{
			head = pointer;
		}
		else
			tail->next = pointer;
			tail = pointer;
			cout << "\n\t\tNew Customer has been added successfully." << endl;
			return name;
	}

	//Display Guest List
	void Guest:: GetGuestList()
	{
		node2 *pointer = head;
		if (head == NULL)
		{
			cout << "\nList is empty.";
		}
		else
		{
			cout << "\t\t\t		***	Guest List  ***\n" << endl;
			cout << "\t\t" << left << setw(12) << "Name";
			cout << left << setw(17) << "IC" ;
			cout << left << setw(16) << "Contact Number";
			cout << left << setw(20) << "Email";
			cout <<  "Valid License\n" << endl;

			while (pointer != NULL)
			{
				cout << "\t\t" << left << setw(12) << pointer->name;
				cout << left << setw(17) << pointer->ic;
				cout << left << setw(16) << pointer->tel ;
				cout << left << setw(20) << pointer->email ;
				pointer = pointer->next;
			}
			cout<<endl<<endl;
		}
	}

	void Guest::SampleGuest(string name, string ic, string tel,string email)
	{
		node2* pointer = new node2;
		pointer->next = NULL;
		pointer->name = name;
		pointer->ic= ic;
		pointer->tel = tel;
		pointer->email=email;
		pointer->next = NULL;
		if (head == NULL)
			head = pointer;
		else {
			tail->next = pointer;
		}
		tail = pointer;
	}

	//predefined data
	void Guest::DefineGuest()
	{
		SampleGuest("Eada", "951216135830", "019815958", "eada@yahoo.com");
		SampleGuest("See Yung", "950526136033", "0138866033", "seeyung@gmail.com");
		SampleGuest("Phang How", "950329085695", "0165530128", "phow@live.com");
	}

	//Return Guest Detail
	string Guest::Details()
	{
		string cust_id;
		cin >>cust_id;
		node2 *pointer=head;
		int a;
		while(pointer!=NULL)
		{

			a=pointer->ic.compare(cust_id);
			if(a==0){
			cout << "\n\t\t************** CUSTOMER DETAIL ******************* " << endl;
			cout << "\t\t\tCustomer Name		: " << pointer->name << endl;
			cout << "\t\t\tCustomer Telephone	: " << pointer->tel << endl;
			cout << "\t\t\tCustomer Email		: " << pointer->email << endl;
			break;
			}
			pointer=pointer->next;
		}
		if(a==1)
			return "";
		else
		return pointer->name;
	}

	void Guest::BillDetail(string cust_name)
	{
		node2 *pointer=head;

		while(pointer!=NULL)
		{
			int a;
			a=pointer->name.compare(cust_name);
			if(a==0){
			cout << "\n\t*********************** CUSTOMER DETAIL **************************** " << endl;
			cout << "\t\t\t Name		: " << pointer->name << endl;
			cout << "\t\t\t Telephone	: " << pointer->tel << endl;
			cout << "\t\t\t Email		: " << pointer->email << endl;
			break;
			}
			pointer=pointer->next;
		}

	}
