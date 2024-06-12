struct node3
	{
		int form_no;
		string description;
		node3 *next;

	};
class Feedback // class for feedback information
{
private:
	int form_no;
	string description;
	struct node3 *head;
	struct node3 *tail;

public:
	void AddFeedback();
	void GetFeedbackList();
	Feedback()//construtor of class guest
	{
		head = tail = NULL;
	}
};

	//method : Add New Feedback
	void Feedback :: AddFeedback() // add a new guest
	{
		node3 *pointer = new node3;
		cout << "\n\t\t\tEnter Form Number:  -";
		cin >> form_no;
		pointer->form_no = form_no;
		cout << "\t\t\tEnter Feedback Description: \n\t\t\t-";
		cin.ignore();
		getline(cin, description);
		pointer->description = description;
		pointer->next = NULL;
		if (head == NULL)
		{
			head = pointer;
		}
		else
			tail->next = pointer;
			tail = pointer;
			cout << "\n\t\t\tFeedback has been added successfully." << endl;
	}

	//Display Feedback
	void Feedback:: GetFeedbackList()
	{
		node3 *pointer = head;
		if (head == NULL)
		{
			cout << "\nList is empty.";
		}
		else
		{
			cout << "\t		***	Feedback List  ***" << endl << endl;
			cout<< "\t---------------------------------------------------------------------------------\n";
			cout << "\t\t" << left << setw(10) << "Form No.";
			cout << "\t"<< "Description" << endl ;
			cout<< "\t---------------------------------------------------------------------------------"<< endl;

			while (pointer != NULL)
			{
				cout << "\t\t" << left << setw(10) << pointer->form_no;
				cout << "\t"<< pointer->description << endl;
				pointer = pointer->next;
			}
		}
	}
