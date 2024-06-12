#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class employee
{
public:
	void display();
	void addEmployee(string a, string b, string c);
	void edit_name(string new_name);
	void edit_hp_no(string new_hp_no);
	void edit_position(string new_position);
	employee();
	employee(string a, string b, string c);
	string retrieve_name();
	string retrieve_hp_no();
	string retrieve_position();

protected:
	string EmpName;
	string position;
	string hp_no;
};

class admin : public employee
{
public:
	void display();
	void addEmployee(string a, string b, string c, string d);
	void edit_AdminID(string new_AdminID);
	admin();
	admin(string a, string b, string c, string d);
	string retrieve_AdminID();

private:
	string adminID;

};

class staff : public employee
{
public:
	void display();
	void addEmployee(string a, string b, string c, string e);
	void edit_StaffID(string new_StaffID);
	staff();
	staff(string a, string b, string c, string e);
	string retrieve_StaffID();

private:
	string staffID;
};

employee::employee()
{
	EmpName = "";
	hp_no = "";
	position = "";
}

employee::employee(string a, string b, string c)
{
	EmpName = a;
	hp_no = b;
	position = c;
}

admin::admin()
{
	adminID = "";
}

admin::admin(string a, string b, string c, string d)
	:employee(a, b, c)
{
	adminID = d;
}

staff::staff()
{
	staffID = "";
}

staff::staff(string a, string b, string c, string e)
	:employee(a, b, c)
{
	staffID = e;
}

void employee::addEmployee(string a, string b, string c)
{
	EmpName = a;
	hp_no = b;
	position = c;
}

void admin::addEmployee(string a, string b, string c, string d)
{
	employee::addEmployee(a, b, c);
	adminID = d;
}

void staff::addEmployee(string a, string b, string c, string e)
{
	employee::addEmployee(a, b, c);
	staffID = e;
}

string employee::retrieve_name()
{
	return EmpName;
}

string employee::retrieve_hp_no()
{
	return hp_no;
}

string employee::retrieve_position()
{
	return position;
}

string admin::retrieve_AdminID()
{
	return adminID;
}

string staff::retrieve_StaffID()
{
	return staffID;
}

void employee::edit_name(string new_name)
{
	EmpName = new_name;
}

void employee::edit_hp_no(string new_hp_no)
{
	hp_no = new_hp_no;
}

void employee::edit_position(string new_position)
{
	position = new_position;
}

void admin::edit_AdminID(string new_AdminID)
{
	adminID = new_AdminID;
}

void staff::edit_StaffID(string new_StaffID)
{
	staffID = new_StaffID;
}

void edit_emp_detail(admin emp_M[3], staff emp_R[5])
{
	int choice, choice1, choice2, row, n;

	string new_name, new_hp_no, new_position, new_SID;

	const char seperator = ' ';
	const int nameWidth = 18;
	const int numWidth = 20;

	do
	{
	B:	system("CLS");
		cout << "Choose which employee you want to edit." << endl;
		cout << "1. Admin" << endl;
		cout << "2. Staff" << endl;
		cout << "3. Exit to previous menu." << endl << endl;
		cout << "Your option: ";
		cin >> choice;

		if (choice == 1)
		{
			// edit admin
			cout << "\n..............................................................................." << endl;
			cout << "<Name>	         <Contact no>	     <Position>		<ID no>" << endl;
			cout << "..............................................................................." << endl;

			for (int i = 0; i < 3; i++)
			{
				emp_M[i].display();
			}

			cout << "\nPlease choose the row which you want to edit." << endl;
			cout << "\nRow: ";
			cin >> row;
		A:	system("CLS");
			cout << "..............................................................................." << endl;
			cout << "<Name>	         <Contact no>	     <Position>		<ID no>" << endl;
			cout << "..............................................................................." << endl;
			cout << left << setw(nameWidth) << setfill(seperator) << emp_M[row - 1].retrieve_name();
			cout << left << setw(numWidth) << setfill(seperator) << emp_M[row - 1].retrieve_hp_no();
			cout << left << setw(nameWidth) << setfill(seperator) << emp_M[row - 1].retrieve_position();
			cout << left << setw(nameWidth) << setfill(seperator) << emp_M[row - 1].retrieve_AdminID();
			cout << endl;
			cout << endl;
			cout << "Please select which field to edit." << endl;
			cout << "1. Name" << endl;
			cout << "2. Contact no" << endl;
			cout << "3. Position" << endl;
			cout << "4. ID no" << endl;
			cout << "5. Exit to previous menu" << endl;
			cout << endl << "Your option: ";
			cin >> choice1;

			if (choice1 == 1)
			{
				cout << "Edit the name of the employee: ";
				cin.ignore();
				getline(cin,new_name);
				emp_M[row - 1].edit_name(new_name);
			C:	cout << "Do you want to continue editing?";
				cout << "	( 1 - YES\t2 - NO )" << endl;
				cout << "Your choice : ";
				cin >> n;

				if (n == 1)
				{
					goto A;
				}
				else if (n == 2)
				{
					goto B;
				}
				else
				{
					cout << "Invalid input. Please try again." << endl;
					system("pause");
					goto C;
				}
			}
			else if (choice1 == 2)
			{
				cout << "Edit the contact no of the employee: ";
				cin >> new_hp_no;
				emp_M[row - 1].edit_hp_no(new_hp_no);

			D:	cout << "Do you want to continue editing?";
				cout << "	( 1 - YES\t2 - NO )" << endl;
				cout << "Your choice : ";
				cin >> n;

				if (n == 1)
				{
					goto A;
				}
				else if (n == 2)
				{
					goto B;
				}
				else
				{
					cout << "Invalid input. Please try again." << endl;
					system("pause");
					goto D;
				}
			}
			else if (choice1 == 3)
			{

				cout << "Edit the position of the employee: ";
				cin >> new_position;
				emp_M[row - 1].edit_position(new_position);

			E:	cout << "Do you want to continue editing?";
				cout << "	( 1 - YES\t2 - NO )" << endl;
				cout << "Your choice : ";
				cin >> n;

				if (n == 1)
				{
					goto A;
				}
				else if (n == 2)
				{
					goto B;
				}
				else
				{
					cout << "Invalid input. Please try again." << endl;
					system("pause");
					goto E;
				}
			}
			else if (choice1 == 4)
			{

				cout << "Edit the ID no of the employee: ";
				cin >> new_SID;
				emp_M[row - 1].edit_AdminID(new_SID);

			F:	cout << "Do you want to continue editing?";
				cout << "	(1 - YES\t2 - NO)" << endl;
				cout << "Your choice : ";
				cin >> n;

				if (n == 1)
				{
					goto A;
				}
				else if (n == 2)
				{
					goto B;
				}
				else
				{
					cout << "Invalid input. Please try again." << endl;
					system("pause");
					goto F;
				}
			}
			else if (choice1 == 5)
			{
				cout << "Exit to previous menu." << endl;
				system("pause");

				goto B;
			}
			else
			{
				cout << "Invalid input. Please try again." << endl;
				system("pause");

				goto A;
			}


		}
		else if (choice == 2)
		{
			// edit staff
			cout << "\n..............................................................................." << endl;
			cout << "<Name>	         <Contact no>	     <Position>		<ID no>" << endl;
			cout << "..............................................................................." << endl;

			for (int j = 0; j < 5; j++)
			{
				emp_R[j].display();
			}

			cout << "\nPlease choose the row which you want to edit." << endl;
			cout << "\nRow: ";
			cin >> row;

		G:	system("CLS");
			cout << "..............................................................................." << endl;
			cout << "<Name>	         <Contact no>	     <Position>		<ID no>" << endl;
			cout << "..............................................................................." << endl;
			cout << left << setw(nameWidth) << setfill(seperator) << emp_R[row - 1].retrieve_name();
			cout << left << setw(numWidth) << setfill(seperator) << emp_R[row - 1].retrieve_hp_no();
			cout << left << setw(nameWidth) << setfill(seperator) << emp_R[row - 1].retrieve_position();
			cout << left << setw(nameWidth) << setfill(seperator) << emp_R[row - 1].retrieve_StaffID();
			cout << endl;
			cout << endl;
			cout << "Please select which field to edit." << endl;
			cout << "1. Name" << endl;
			cout << "2. Contact no" << endl;
			cout << "3. Position" << endl;
			cout << "4. ID no" << endl;
			cout << "5. Exit to previous menu" << endl;
			cout << endl << "Your option: ";
			cin >> choice2;

			if (choice2 == 1)
			{
				cout << "Edit the name of the employee: ";
				cin.ignore();
				getline(cin,new_name);
				emp_R[row - 1].edit_name(new_name);
			H:	cout << "Do you want to continue editing?";
				cout << "	( 1 - YES\t2 - NO )" << endl;
				cout << "Your choice : ";
				cin >> n;

				if (n == 1)
				{
					goto G;
				}
				else if (n == 2)
				{
					goto B;
				}
				else
				{
					cout << "Invalid input. Please try again." << endl;
					system("pause");
					goto H;
				}
			}
			else if (choice2 == 2)
			{
				cout << "Edit the contact no of the employee: ";
				cin >> new_hp_no;
				emp_R[row - 1].edit_hp_no(new_hp_no);

			I:	cout << "Do you want to continue editing?";
				cout << "	( 1 - YES\t2 - NO )" << endl;
				cout << "Your choice : ";
				cin >> n;

				if (n == 1)
				{
					goto G;
				}
				else if (n == 2)
				{
					goto B;
				}
				else
				{
					cout << "Invalid input. Please try again." << endl;
					system("pause");
					goto I;
				}
			}
			else if (choice2 == 3)
			{

				cout << "Edit the position of the employee: ";
				cin >> new_position;
				emp_R[row - 1].edit_position(new_position);

			J:	cout << "Do you want to continue editing?";
				cout << "	( 1 - YES\t2 - NO )" << endl;
				cout << "Your choice : ";
				cin >> n;

				if (n == 1)
				{
					goto G;
				}
				else if (n == 2)
				{
					goto B;
				}
				else
				{
					cout << "Invalid input. Please try again." << endl;
					system("pause");
					goto J;
				}
			}
			else if (choice2 == 4)
			{

				cout << "Edit the ID no of the employee: ";
				cin >> new_SID;
				emp_R[row - 1].edit_StaffID(new_SID);

			K:	cout << "Do you want to continue editing?";
				cout << "	( 1 - YES\t2 - NO )" << endl;
				cout << "Your choice : ";
				cin >> n;

				if (n == 1)
				{
					goto G;
				}
				else if (n == 2)
				{
					goto B;
				}
				else
				{
					cout << "Invalid input. Please try again." << endl;
					system("pause");
					goto K;
				}
			}
			else if (choice2 == 5)
			{
				cout << "Exit to previous menu." << endl;
				system("pause");

				goto B;
			}
			else
			{
				cout << "Invalid input. Please try again." << endl;
				system("pause");

				goto G;
			}
		}
	}while (choice!=3);
}

void employee::display()
{
	if (EmpName == "")
	{
	}
	else
	{
		const char seperator = ' ';
		const int nameWidth = 18;
		const int numWidth = 20;

		cout << left << setw(nameWidth) << setfill(seperator) << EmpName;
		cout << left << setw(numWidth) << setfill(seperator) << hp_no;
		cout << left << setw(nameWidth) << setfill(seperator) << position;
	}
}

void admin::display()
{
	employee::display();
	cout << "" << adminID;
	cout << endl;
}

void staff::display()
{
	employee::display();
	cout << "" << staffID;
	cout << endl;
}
