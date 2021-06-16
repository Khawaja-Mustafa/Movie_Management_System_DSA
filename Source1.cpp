#include <iostream>
#include <string>
#include <fstream>
int Av_Tickets[7][7];
using namespace std;
struct MovieManagement
{
	string Name, Date, Time;
	MovieManagement* next;
	MovieManagement* prev;
};
MovieManagement* head = NULL;
void addMoviedetails() 
{
	MovieManagement* newnode = new MovieManagement();
	string iname, idate, itime;
	cout << "Movie Name:";
	cin.ignore();
	getline(cin, iname);
	cout << "\nVenue Date:";
	cin.ignore();
	getline(cin, idate);
	cout << "\nVenue Time:";
	cin.ignore();
	getline(cin, itime);
	newnode->Name = iname;
	newnode->Date = idate;
	newnode->Time = itime;
	if (head == NULL) 
	{
		newnode->next = NULL;
		newnode->prev = NULL;
		head = newnode;
		return;
	}
	else 
	{
		MovieManagement* temp = head;
		while (temp->next != NULL) 
		{
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->prev = temp->next;
		newnode->next = NULL;
	}
}
void update(string mName)
{
	MovieManagement* temp = head;
	while (temp != NULL)
	{
		if (temp->Name == mName)
		{
			cout << "Enter updated Name : ";
			cin >> temp->Name;
			cout << "Enter updated Date : ";
			cin >> temp->Date;
			cout << "Enter updated Time : ";
			cin >> temp->Time;
			return;
		}
		temp = temp->next;
	}
}

void display() 
{
	fstream file, file2;
	/*
	file.open("Movie_Details.txt", ios::in | ios::out);
	string text;
	while (!file.eof())
	{
		getline(file, text);
		cout << text << endl;
	}
	file.close();*/

	MovieManagement* temp = head;
	
	file2.open("Movie_Details.txt", ios::in | ios::out | ios::trunc);
	file.open("Movie_Details.txt", ios::in | ios::out | ios::app);
	while (temp != NULL) 
	{
		
		file << temp->Name << endl;
		file << temp->Date << endl;
		file << temp->Time << endl << endl;
		/*cout << "Movie Name: " << temp->Name << endl;
		cout << "Date of Venue: " << temp->Date << endl;
		cout << "Time of Venue: " << temp->Time << endl;*/
		temp = temp->next;
	}
	file2.close();
	file.close();

}
void view_movies()
{
	fstream file, file2;
	file.open("Movie_Details.txt", ios::in | ios::out);
	string text;
	while (!file.eof())
	{
		getline(file, text);
		cout << text << endl;
	}
	file.close();
}
//======================================================================================
void BookTicket()
{
	int Show_No;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			Av_Tickets[i][j] = 0;
		}
	}
	Show_No = 0;
}
void Setseats(int iAv_Tickets[][7])
{
	int Av_Tickets[7][7];
	for (int i = 0; i < 7; i++)//Values Pass
	{
		for (int j = 0; j < 7; j++)
		{
			Av_Tickets[i][j] = iAv_Tickets[i][j];
		}
	}
}
void UpdateAvailableSeats()
{
	fstream file, file2;
	cout << "\t\t\t******************************************************\n";
	cout << "\t\t\t\t\tMovie Management System\n";
	cout << "\t\t\t******************************************************\n\n";
	cout << "\t\t\t\t\t<<<<<< Seat Left >>>>>>\n\n";
	string text;
	file2.open("Book_Ticket.txt", ios::in | ios::out | ios::trunc);
	file.open("Book_Ticket.txt", ios::in | ios::out | ios::app);
	while (!file.eof())
	{
		getline(file, text);
		cout << text << endl;
	}
	file2.close();
	file.close();

	for (int i = 0; i < 7; i++)//Determines Seat booking
	{
		for (int j = 0; j < 7; j++)
		{
			if (Av_Tickets[i][j] == 0)
			{
				cout << "\t| " << i << j << " |\t";
				
			}
			else
			{
				cout << "\t| " << "XX" << " |\t";
				
			}
		}

	}

}
int main() 
{

	string mName;
	Main_Menu:
	cout << "\t\t\t---------------------------------------\n\n";
	cout << "\t\t\t<<<<<<<<Movie Management System>>>>>>>>\n\n";
	cout << "\t\t\t---------------------------------------\n\n";
	cout << " \t\t\t1) Add Movies\n \t\t\t2) Update Movies\n \t\t\t3) Display Movies\n \t\t\t4) Book Ticket \n \t\t\t5) View Movies \n \t\t\t6) Exit Program \n \t\t\tYour Choice: ";
	int choice;
	cin >> choice;
	if(choice == 1)
	{
		addMoviedetails();
		display();
		system("Pause");
		system("cls");
		goto Main_Menu;
	}
	else if(choice == 2)
	{
		cout << "Enter Movie Name you want to update : ";
		cin.ignore();
		getline(cin, mName);
		update(mName);
		display();
		system("pause");
		system("cls");
		goto Main_Menu;
	}
	else if (choice == 3) 
	{
		system("cls");
		cout << "\n\n***********Display******************\n\n" << endl;
		display();
		cout << "\n";
		system("pause");
		system("cls");
	}
	else if (choice == 4) //BOOK Ticket
	{
		//BOOKTICKET
		system("cls");
		cout << "\t\t\t******************************************************\n";
		cout << "\t\t\t\t\tMovie Management System\n";
		cout << "\t\t\t******************************************************\n\n";
		cout << "\t\t\t\t\t<<<<<< Book Your Seats >>>>>>\n\n";

		cout << "\t\t\tEnter the following details :-" << endl;
		cout << "\t\t\tUser ID: ";
		cin.ignore();
		//-----------------------------
		int RiID;
		string RiName;
		int iAv_Ticket[7][7];
		string Movie_choice;
		//-----------------------------
		cin >> RiID;

		cout << "\t\t\tUser Name: ";
		cin.ignore();
		
		getline(cin, RiName);
		cout << endl;

		cout << "\t\t\tWhich Moviue You want to see? :-" << endl << endl;
		display();
		cout << "\n\n";
		cout << "You have Selected :";
		cin >> Movie_choice;
		cout << endl << endl;
		system("ClS");
		cout << "\t\t\t******************************************************\n";
		cout << "\t\t\t\t\tMovie Management System\n";
		cout << "\t\t\t******************************************************\n\n";
		cout << "\t\t\t\t\t<<<<<< Book Your Seats >>>>>>\n\n";
		char choice_B;
		for (int i = 0; i < 7; i++) //Initializing 2D array == 0
		{
			for (int j = 0; j < 7; j++)
			{
				iAv_Ticket[i][j] = 0; //initialize 2day array to '0'
			}
		}

		for (int i = 0; i < 7; i++) //49 Table outputs
		{
			for (int j = 0; j < 7; j++)
			{
				cout << "\t| " << i << j << " |\t";
			}
			cout << endl << endl;
		}

		for (int i = 0; i < 7; i++)//Booking
		{
			for (int j = 0; j < 7; j++)
			{
				cout << "Do you want to book a Seat/ticket? (Y/N):";
				cin >> choice_B;
				if (choice_B == 'Y' || choice_B == 'y')
				{
					cout << "Select Row and Column (0 1) :";
					cin >> i >> j;
					iAv_Ticket[i][j] = 1;
					i = 0; // i = 0, j = 0 for running program on i = 6, j = 6.
					j = 0;
				}
				else if (choice_B == 'N' || choice_B == 'n')
				{
					i = 6;
					j = 6;
					system("cls");
					break;//breaks the loop
				}
				else
				{
					cout << "\n\nWrong Input!\n\n";
				}
			}
		}
		Setseats(iAv_Ticket);
		UpdateAvailableSeats();
		system("pause");
		system("CLS");
		goto Main_Menu;
	}
	else if (choice == 5)
	{
		system("CLS");
		cout << "\t\t\t******************************************************\n";
		cout << "\t\t\t\t\tMovie Management System\n";
		cout << "\t\t\t******************************************************\n\n";
		cout << "\t\t\t\t\t<<<<<< View Movies >>>>>>\n\n";
		view_movies();
		system("pause");
		system("cls");
		goto Main_Menu;
	}
	else if(choice == 6)
	{
		exit;
	}
	else
	{
		cout << "\nWrong Input!";
		system("cls");
		goto Main_Menu;
	}
	system("cls");
	return 0;
}
