struct node1
	{
		string itemName;
		int item_price;
		node1 *next;
	};

class AddOnItem // class for AddOnItem information
{
private:
	string itemName;
	int item_price;
	struct node1 *head;
	struct node1 *tail;

public:
	void AddItem(int price);
	void GetAddOnItemList();
	void SampleAddOnItem(string itemName, int price);
	void DefineAddOnItem();
	string AddItemDetail(int n);

	AddOnItem()//construtor of class AddOnItem
	{
		head = tail = NULL;
	}

};

	//method : Add Item
	void AddOnItem :: AddItem(int price) // add a new item
	{
		node1 *pointer = new node1;
		cout << "\n\t\t\tEnter Item Name : ";
		cin.ignore();
		getline(cin,itemName);
		pointer->itemName = itemName;
		cout << "\t\t\tEnter Price : RM";
		cin >> price;
		pointer->item_price=price;
		pointer->next = NULL;
		if (head == NULL)
		{
			head = pointer;
		}
		else
			tail->next = pointer;
			tail = pointer;
			cout << "\n\t\t\tNew Item has been added successfully." << endl;
	}

	//Display Item List
	void AddOnItem:: GetAddOnItemList()
	{
		node1 *pointer = head;
		if (head == NULL)
		{
			cout << "\nList is empty.";
		}
		else
		{
			cout << "\n\t		***	Add On Item List  ***\n" << endl;
			cout << "\t\t";
			cout << left << setw(30) << "Add On Item " ;
			cout << left << setw(20) << "Price \n" << endl;
			while (pointer != NULL)
			{
				cout <<"\t\t" ;
				cout << left << setw(30) <<pointer->itemName;
				cout << "RM "  << pointer->item_price << endl;
				pointer = pointer->next;
			}
		}
	}

	void AddOnItem::SampleAddOnItem(string itemName, int price)
	{
		node1* pointer = new node1;
		pointer->next = NULL;
		pointer->itemName = itemName;
		pointer->item_price = price;
		pointer->next = NULL;
		if (head == NULL)
		{
			head = pointer;
		}
		else
		{
			tail->next = pointer;
		}
		tail = pointer;
	}

	//predefined data
	void AddOnItem::DefineAddOnItem()
	{
		SampleAddOnItem("Chicken Rice",10);
		SampleAddOnItem("Thai Chicken Rice",10);
		SampleAddOnItem("Baby Seats", 10);
		SampleAddOnItem("Travelling Insurance", 18);
	}

	string AddOnItem::AddItemDetail(int n)
	{
		struct node1 *temp1=head;
		int i;
		for(i=1; i<=n; i++)
		{
			if(i!=n)
			{
				temp1=temp1->next;
			}
		}
		return temp1->itemName;
	}

