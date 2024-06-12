struct node
{
		string plateNo;
		int seat_price;
		string availability;
		node *next;
};

class train // class for vehicle information
{
protected:
	string plateNo;
	int seat_price;
	struct node *head;
	struct node *tail;

public:
	string availability;
	void AddTrain(int price);
	void GetTrainList();
	void SampleTrain(string plateNo,int price,string availability);
	void DefineTrain();
	void DisposeTrain();
	void getTrainStatus();
	void Return(int n);
	void BillDetail(int n);
	int TrainReservation(int n);
	string TrainPlateNo(int n);

	//Polymorphism Method
	virtual int GetPrice()
	{
		return seat_price;
	}
	virtual void SetPrice(int price)
	{
		seat_price=price;
	}

	//Construtor of class vehicle
	train()
	{
		head = tail = NULL;
	}

};

//sub class : A
class Class_A : public train
{
	int seat_price;
public :
	Class_A():train()
	{
		seat_price=0;
	}
	int GetPrice()
	{
		return seat_price;
	}
	void SetPrice(int price)
	{
		seat_price= price;
	}
};

//sub class : B
class Class_B : public train
{
	int seat_price;

public :
	Class_B():train()
	{
		seat_price = 0;
	}
	int GetPrice()
	{
		return seat_price;
	}
	void SetPrice(int price)
	{
		seat_price = price;
	}
};

// sub class : C
class Class_C : public train
{
	int seat_price;

public :
	Class_C():train()
	{
		seat_price = 0;
	}
	int GetPrice()
	{
		return seat_price;
	}
	void SetPrice(int price)
	{
		seat_price = price;
	}
};

// sub class : budget
class Class_Budget : public train
{
	int seat_price;

public :
	Class_Budget():train()
	{
		seat_price=0;
	}
	int GetPrice()
	{
		return seat_price;
	}
	void SetPrice(int price)
	{
		seat_price= price;
	}
};

	//method
	void train :: AddTrain(int price) // add a new vehicle
	{
		node *pointer = new node;
		cout << "\n\t\t\tEnter Plate Number : ";
		cin.ignore();
		getline(cin,plateNo);
		pointer->plateNo = plateNo;
		pointer->seat_price=price;
		pointer->availability="Available";
		pointer->next = NULL;
		if (head == NULL)
		{
			head = pointer;
		}
		else
			tail->next = pointer;
			tail = pointer;
			cout << "\n\t\t\tNew train has been added successfully." << endl;
	}

	//display Vehicle List
	void train::GetTrainList()
	{
		node *pointer = head;
		if (head == NULL)
		{
			cout << "\nList is empty.";
		}
		else
		{
			cout << "\n\t\t		*** 	Train List	 ***\n" << endl;
			cout << "\t" << left << setw(15) << "Plate Number";
			cout << left << setw(15) << "Price";
			cout<< left << setw(10) << "    Status" << endl <<endl;

			while (pointer != NULL)
			{
				cout << "\t" <<left << setw(15) << pointer->plateNo;
				cout <<"RM " <<  left << setw(16) << pointer->seat_price;
				cout << left << setw(10) << pointer->availability <<endl;
				pointer = pointer->next;

			}
		}
	}

	void train::SampleTrain(string plateNo, int price,string availability)
	{
		node* pointer = new node;
		pointer->next = NULL;
		pointer->plateNo = plateNo;
		pointer->seat_price = price;
		pointer->availability = "Available";

		pointer->next = NULL;
		if (head == NULL)
			head = pointer;
		else {
			tail->next = pointer;
		}
		tail = pointer;
	}

	//predefined data
	void train::DefineTrain()
	{
		SampleTrain("QTT 9933",100,"Available");
		SampleTrain("QWQ 3399",50,"Available");
		SampleTrain("WAH 1013",100,"Available");
		SampleTrain("WTF 4488",200,"Available");
	}

	// Dispose Vehicle
	void train ::DisposeTrain()
	{
		int n;
		cout<< "\n\t\tDelete Selection :" << endl;
		cout << "\t\tEnter Number Train Position (Row) :  ";
		cin >> n;

		struct node *temp1=head;
		if(n==1){
			head=temp1->next;
			free(temp1);
			return;
		}
		int i;
		for(i=0;i<n-2;i++)
			temp1=temp1->next;

		struct node *temp2=temp1->next;
		temp1->next = temp2->next;
		free(temp2);
		cout << "\n\t\t\tOld Vehicle has been disposed successfully." << endl;
	}

	// Car Detail For Rental
	int train ::TrainReservation(int n)
	{
		struct node *temp1=head;

		int i;
		for(i=1; i<=n; i++){
			if(i!=n)
			{
				temp1=temp1->next;
			}
			else
			{
				temp1->availability = "Booked";
				cout << "\n\t\t************ Train Summary **************\n" ;
				cout << left << setw(25) << "\n\t\Plate Number" << "  : " << temp1->plateNo << endl;
				cout << left << setw(25)<<"\t\tPrice" << " : RM" << temp1->seat_price << endl;
				cout << left << setw(25)<<"\t\tTrain Status : " << " : " << temp1->availability <<endl;
			}
		}
		return temp1->seat_price;
	}

	// Train detail after booking
	void train ::Return(int n)
	{
		struct node *temp1=head;
		int i;
		for(i=1; i<=n; i++){
			if(i!=n)
			{
				temp1=temp1->next;
			}
			else
			{
				temp1->availability = "Available";
			}
		}

	}

	//Return Train Detail on Rental
	string train::TrainPlateNo(int n)
	{
		struct node *temp1=head;

		int i;
		for(i=1; i<=n; i++)
		{
			if(i!=n)
			{
				temp1=temp1->next;
			}

		}
		return temp1->plateNo ;
	}

	// Return Bill Detail
	void train::BillDetail(int n)
	{
		struct node *temp1=head;

		int i;
		for(i=1; i<=n; i++)
		{
			if(i!=n)
			{
				temp1=temp1->next;
			}
		}
			cout << "\n\t*********************** Train DETAIL **************************** " << endl;
			cout << "\t\t\tPlate Number	: " <<	temp1->plateNo << endl;
			cout << "\t\t\tPrice    	: RM " << temp1->seat_price << endl;
	}
