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
//void Delete()
//{
//
//}
void display() 
{
	MovieManagement* temp = head;
	fstream file;
	file.open("Movie_Details.txt", ios::in | ios::out | ios::app);
	while (temp != NULL) 
	{
		
		file << temp->Name << endl;
		file << temp->Date << endl;
		file << temp->Time << endl << endl;
		cout << "Movie Name: " << temp->Name << endl;
		cout << "Date of Venue: " << temp->Date << endl;
		cout << "Time of Venue: " << temp->Time << endl;
		temp = temp->next;
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
	fstream file;
	cout << "\t\t\t******************************************************\n";
	cout << "\t\t\t\t\tMovie Management System\n";
	cout << "\t\t\t******************************************************\n\n";
	cout << "\t\t\t\t\t<<<<<< Seat Left >>>>>>\n\n";
	string text;
	file.open("Book_Ticket.txt", ios::in | ios::out | ios::app);
	while (!file.eof())
	{
		getline(file, text);
	}
	file.close();
	for (int i = 0; i < 7; i++)//Determines Seat booking
	{
		for (int j = 0; j < 7; j++)
		{
			if (Av_Tickets[i][j] == 0)
			{
				cout << "\t| " << i << j << " |\t";
				file << "\t| " << i << j << " |\t";
			}
			else
			{
				cout << "\t| " << "XX" << " |\t";
				file << "\t| " << "XX" << " |\t";
			}
		}

	}
}
int main() 
{

	string mName;
	Main_Menu:
	cout << "\t\t\tMovie Management System\n";
	cout << " 1) Add Movies\n 2) Update Movies\n 3) Display Movies\n Your Choice: ";
	int choice;
	cin >> choice;
	if(choice == 1)
	{
		addMoviedetails();
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
	else
	{
		cout << "\nWrong Input!";
		system("cls");
		goto Main_Menu;
	}
	system("cls");
	return 0;
}