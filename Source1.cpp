#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	int loginchances = 3;
	Main_Page:
	int i = 0;
	cout << "\t\t\t\t~~~ Movie Management System ~~~\n";
	cout << "\n\n\t\t1) Admin login \n\n\t\t2) Walk-In-Customer \n\n\t\tYour Choice: ";
	int Main_Choice;
	cin >> Main_Choice;
	if(Main_Choice == 1)
	{
		system("cls");
		goto Admin_Login;
	}
	else if(Main_Choice == 2)
	{
		//goto Walk_In_Customer;
	}

	//Admin Block
	Admin_Login:
	int Admin_ID;
	string Admin_Pass;
	cout << "\t\t\t\t~~~ Movie Management System ~~~\n";
	cout << "\t\t\t\t\t~~~ ADMIN LOGIN ~~~\n";
	cout << "\n\n\t\tAdmin ID: ";
	cin >> Admin_ID;
	cout << "\n\n\t\tAdmin Password: ";
	cin.ignore();
	getline(cin, Admin_Pass);
	if(Admin_ID == 123 && Admin_Pass == "Khawaja172")
	{
		system("cls");
		cout << "\n\n\t\t <<<Welcome Khawaja>>> \n\n";
		cout << "\n\n\t\t Chaliye Shru Krtay Hai!!!!! \n\n";
		system("pause");
		system("cls");
		goto Admin_Block;
	}
	else
	{
		cout << "\n\n\t\t Wrong Input \n\n";
		if(loginchances > 1)
		{
			loginchances--;
			cout << "\n\n\t\tYou have " << loginchances << " chances left!\n\n";
			system("Pause");
			system("CLS");
			goto Admin_Login;
		}
		else
		{
			system("cls");
			cout << "\n\n\t\tChances are finished, you can't login as Admin\n\n";
			system("Pause");
			system("CLS");
			goto Main_Page;
		}
	}
Admin_Block:
	cout << "\t\t\t\t~~~ Movie Management System ~~~\n";
	cout << "\t\t\t\t\t~~~ ADMIN ~~~\n";
	cout << "\n\n\t\t1) Register Users \n\n\t\t2) Book and Update Tickets \n\n\t\t3) Add or Update Movies \n\n\t\t4) Print or Update Bill \n\n\t\t5) View Movies \n\n\t\tYour Choice: ";
	int Admin_Choice;
	cin >> Admin_Choice;
	if(Admin_Choice == 1)
	{
		system("cls");
		cout << "\t\t\t\t~~~ Movie Management System ~~~\n";
		cout << "\t\t\t\t~~~ Register New Users ~~~\n\n";
	}
	else if(Admin_Choice == 2)
	{
		system("cls");
		cout << "\t\t\t\t~~~ Movie Management System ~~~\n";
		cout << "\t\t\t\t~~~ Book/Update/Delete Ticket ~~~\n\n";
	}
	else if(Admin_Choice == 3)
	{
		system("cls");
		cout << "\t\t\t\t~~~ Movie Management System ~~~\n";
		cout << "\t\t\t\t~~~ Add/Update/Delete Movies ~~~\n\n";
	}
	else if (Admin_Choice == 4)
	{
		system("cls");
		cout << "\t\t\t\t~~~ Movie Management System ~~~\n";
		cout << "\t\t\t\t~~~ Print or Update Bill ~~~\n\n";
	}
	else if (Admin_Choice == 5)
	{
		system("cls");
		cout << "\t\t\t\t~~~ Movie Management System ~~~\n";
		cout << "\t\t\t\t\t~~~ View Movies ~~~\n\n";
	}
	else 
	{
		system("cls");
		cout << "\t\t\t\t~~~ Movie Management System ~~~\n";
		cout << "\n\n\t\t\tWrong Input!";
		cout << "\n\n\t\t\tRedirecting to Admin Page...............!";
		system("pause");
		system("cls");
		goto Admin_Block;
	}
	system("pause");
	return 0;
}
