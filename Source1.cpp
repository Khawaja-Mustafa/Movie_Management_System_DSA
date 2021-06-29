#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <conio.h>
using namespace std;
void displayMovies(int d);//Prototyping
//---------------------MovieFunction Block---------------------------------//
struct Movieddl
{
	string Movie_Name, Movie_Date, Movie_Time;
	Movieddl* next;
	Movieddl* prev;
};
Movieddl* M_head = NULL;
void addMoviedetails()
{
	Movieddl* newnode = new Movieddl();
	string iname, idate, itime;
	cout << "\n\t\t Movie Name:";
	cin.ignore();
	getline(cin, iname);
	cout << "\n\t\t Movie Date:";
	getline(cin, idate);
	cout << "\n\t\t Movie Time:";
	getline(cin, itime);
	newnode->Movie_Name = iname;
	newnode->Movie_Date = idate;
	newnode->Movie_Time = itime;
	if (M_head == NULL)
	{
		newnode->next = NULL;
		newnode->prev = NULL;
		M_head = newnode;
		return;
	}
	else
	{
		Movieddl* temp = M_head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->prev = temp->next;
		newnode->next = NULL;
	}
}
void updateMovies()
{
	string mName;
u_M:
	int d = 1;
	int flag = 0;
	displayMovies(d);
	cout << "Enter Movie name you want to update: ";
	cin.ignore();
	getline(cin, mName);
	Movieddl* temp = M_head;
	while (temp != NULL)
	{
		if (mName == temp->Movie_Name)
		{
			cout << "\n\t\t Enter updated Movie Name : ";
			getline(cin, temp->Movie_Name);
			cout << "\n\t\t Enter updated Date : ";
			getline(cin, temp->Movie_Date);
			cout << "\n\t\t Enter updated Time : ";
			getline(cin, temp->Movie_Time);
			flag++;
			return;
		}
		temp = temp->next;
	}
	if (flag == 0)
	{
		cout << "Movie Not Found!, try again:";
		system("pause");
		system("cls");
		goto u_M;
	}
}
void displayMovies(int d)
{
	fstream file, file2;
	Movieddl* temp = M_head;
	if (d == 0)
	{
		file2.open("Movie_Details.txt", ios::in | ios::out | ios::trunc);
		file.open("Movie_Details.txt", ios::in | ios::out | ios::app);
		while (temp != NULL)
		{
			file << temp->Movie_Name << endl;
			file << temp->Movie_Date << endl;
			file << temp->Movie_Time << endl << endl;
			temp = temp->next;
		}
		file2.close();
		file.close();
	}
	else if (d == 1)
	{
		while (temp != NULL)
		{
			cout << "\n\t\t Movie Name: " <<temp->Movie_Name << endl;
			cout << "\n\t\t Movie Date: " << temp->Movie_Date << endl;
			cout << "\n\t\t Movie Time: " << temp->Movie_Time << endl << endl;
			temp = temp->next;
		}
	}

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
void deleteMovies()
{
	string m_name;
	cout << "\n\n\t\tEnter the Name of the Movie you want to delete: ";
	cin.ignore();
	getline(cin, m_name);
	Movieddl* p, * q;
	q = M_head;
	p = M_head->next;
	if (m_name == q->Movie_Name)
	{
		M_head = p;
		delete(q);
		p->prev = NULL;
	}
	else
	{
		while (p->Movie_Name != m_name)
		{
			p = p->next;
			q = q->next;
		}
		if (p->next == NULL)
		{
			q->next = NULL;
			delete(p);
		}
		else
		{
			q->next = p->next;
			p->next->prev = q;
			delete(p);
		}
	}
}
int searchmovie(string n_movie) {
	Movieddl* temp = M_head;
	int flag = 0;
	while (temp != NULL) 
	{
		if (n_movie == temp->Movie_Name) 
		{
			flag++;
			return 1;
		}
		temp = temp->next;
	}
	if(flag == 0)
		{
			return 0;
		}
}
//-----------------------------------------------------BookTicket Block---------------------------------------------------
int iAv_Ticket[7][7] = { NULL };
void Display(int Payment);
void ConfirmTransaction(int Av_Tickets[][7]);
void BookTicket()
{
	char choice_B;
	for (int i = 0; i < 7; i++) //49 Table outputs
	{
		for (int j = 0; j < 7; j++)
		{
			if (iAv_Ticket[i][j] == 0)
			{
				cout << "\t| " << i << j << " |\t";
			}
			else
			{
				cout << "\t| " << "XX" << " |\t";

			}
		}
		cout << endl << endl;
	}

	for (int i = 0; i < 7; i++)//Booking
	{
		for (int j = 0; j < 7; j++)
		{
		Ticket_Booking:
			cout << "\n\t\t Do you want to book a Seat/ticket? (Y/N):";
			cin >> choice_B;
			if (choice_B == 'Y' || choice_B == 'y')
			{
				cout << "\n\t\t Select Row and Column (0 1) :";
				cin >> i >> j;
				if(iAv_Ticket[i][j] == 1)
				{
					cout << "\n\t\t Ticket Cannot Be Booked, It is already Booked by user!";
					cout << "\n\t\t Trying Booking any other movie!\n";
					goto Ticket_Booking;
				}
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
				cout << "\n\n\t\t Wrong Input!\n\n";
			}
		}
	}
}
void Booked_Tickets()
{
	char choice_b = ' ';
	cout << "\t\t\t******************************************************\n";
	cout << "\t\t\t\t\tMovie Management System\n";
	cout << "\t\t\t******************************************************\n\n";
	cout << "\t\t\t\t\t<<<<<< Seat Left >>>>>>\n\n";
	string text;
	for (int i = 0; i < 7; i++)//Determines Seat booking
	{
		for (int j = 0; j < 7; j++)
		{
			if (iAv_Ticket[i][j] == 0)
			{
				cout << "\t| " << i << j << " |\t";
			}
			else
			{
				cout << "\t| " << "XX" << " |\t";

			}

		}
		cout << "\n\n";
	}
	cout << "\t\t";

	ConfirmTransaction(iAv_Ticket);
}
void ConfirmTransaction(int Av_Tickets[][7])
{
	int Payment = 0;
	//Transaction Operation
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (Av_Tickets[i][j] == 1)
			{
				Payment++;
			}
			else
			{
				continue;
			}
		}
	}
	Display(Payment);
}
void Display(int Payment)
{
	//For Current Time and Date
	struct tm newtime;
	time_t t = time(0);
	localtime_s(&newtime, &t);
	int Month = 1 + newtime.tm_mon;
	int Day = newtime.tm_mday;
	int Year = newtime.tm_year + 1900;
	int hour = newtime.tm_hour;
	int minuts = newtime.tm_min;
	int sec = newtime.tm_sec;
	//-----------------------------

	string Movie_Name, Customer_Name, Customer_Number;
	int x, TicketPrice = 600, totalPayment = 0, choice = 0;
	char Student;
	int d = 1;
	cout << "\n\t\t--------------------------------------------\n";
	displayMovies(d);
	cout << "\n\t\t--------------------------------------------\n";
	cout << "\n\t\t Enter Movie Name you want to see: ";
	cin.ignore();
	getline(cin, Movie_Name);
	cout << "\n\t\t Enter Your Name: ";
	getline(cin, Customer_Name);
	cout << "\n\t\t Enter Your Contact Number: ";
	getline(cin, Customer_Number);
	x = searchmovie(Movie_Name);

	fstream file;
	file.open("Bill.txt", ios::in | ios::out | ios::app);
	if (x == 1)
	{
		string institute_N, program;
		cout << "\n\t\t Student (Y/N) : ";
		cin >> Student;
		if (Student == 'y' || Student == 'Y')
		{
			cout << "\n\t\t Discount of 50% is given to students per ticket!\n";
			cout << "\n\t\t Enter Institution name: ";
			string institution;
			cin.ignore();
			getline(cin, institution);
			cout << endl;
			system("pause");
			system("cls");
			TicketPrice = 300;
			cout << "\n\t\t--------------------------------------------\n";
			cout << "\n\t\t Customer Name : " << Customer_Name << endl;
			cout << "\n\t\t Customer Contact N0# : " << Customer_Number << endl;
			cout << "\n\t\t Movie Name : " << Movie_Name << endl;
			totalPayment = Payment * TicketPrice;
			cout << "\n\t\t Price of Tickets after discout : " << TicketPrice << endl;
			cout << "\n\t\t Amount of Tickets bought : " << Payment << endl;
			cout << "\n\t\t The Total Bill : " << totalPayment << endl;
			cout << "\n\t\t Bill time : " << hour << ":" << minuts << ":" << sec << endl;
			cout << "\n\t\t Bill date : " << Day << "/" << Month << "/" << Year << endl;
			cout << "\n\t\t--------------------------------------------\n";
			//----------------------------------Saving bill through file handling--------------------------------------------------//
			file << "\n\t\t--------------------------------------------\n";
			file << "\n\t\t Customer Name : " << Customer_Name << endl;
			file << "\n\t\t Customer Contact N0# : " << Customer_Number << endl;
			file << "\n\t\t Movie Name : " << Movie_Name << endl;
			totalPayment = Payment * TicketPrice;
			file << "\n\t\t Price of Tickets after discout : " << TicketPrice << endl;
			file << "\n\t\t Amount of Tickets bought : " << Payment << endl;
			file << "\n\t\t The Total Bill : " << totalPayment << endl;
			file << "\n\t\t Bill time : " << hour << ":" << minuts << ":" << sec << endl;
			file << "\n\t\t Bill date : " << Day << "/" << Month << "/" << Year << endl;
			file << "\n\t\t--------------------------------------------\n";
			Payment = 0;
		}
		else
		{
			system("pause");
			system("cls");
			cout << "\n\t\t--------------------------------------------\n";
			cout << "\n\t\t Customer Name : " << Customer_Name << endl;
			cout << "\n\t\t Customer Contact N0# : " << Customer_Number << endl;
			cout << "\n\t\t Movie Name : " << Movie_Name << endl;
			totalPayment = Payment * TicketPrice;
			cout << "\n\t\t Price of Tickets : " << TicketPrice << endl;
			cout << "\n\t\t Amount of Tickets : " << Payment << endl;
			cout << "\n\t\t The Total Bill : " << totalPayment << endl;
			cout << "\n\t\t Bill time : " << hour << ":" << minuts << ":" << sec << endl;
			cout << "\n\t\t Bill date : " << Day << "/" << Month << "/" << Year << endl;
			cout << "\n\t\t--------------------------------------------\n";

			file << "\n\t\t--------------------------------------------\n";
			file << "\n\t\t Customer Name : " << Customer_Name << endl;
			file << "\n\t\t Customer Contact N0# : " << Customer_Number << endl;
			file << "\n\t\t Movie Name : " << Movie_Name << endl;
			totalPayment = Payment * TicketPrice;
			file << "\n\t\t Price of Tickets : " << TicketPrice << endl;
			file << "\n\t\t Amount of Tickets : " << Payment << endl;
			file << "\n\t\t The Total Bill : " << totalPayment << endl;
			file << "\n\t\t Bill time : " << hour << ":" << minuts << ":" << sec << endl;
			file << "\n\t\t Bill date : " << Day << "/" << Month << "/" << Year << endl;
			file << "\n\t\t--------------------------------------------\n";

			Payment = 0;
		}
	}
	else
	{
		cout << "\n\t\t Movie not found\n";
	}
	file.close();
}
//------------------------------------------MAIN FUNCTION------------------------------------//
int main()
{
	int d;
	int loginchances = 3;
Main_Page:
	int i = 0;
	cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
	cout << "\n\n\t\t1) Admin login \n\n\t\tYour Choice: ";
	int Main_Choice;
	cin >> Main_Choice;
	if (Main_Choice == 1)
	{
		system("cls");
		goto Admin_Login;
	}
	//+++++++++++++++++++++++++++++Admin Block+++++++++++++++++++++++++++++++++++++++++++++++++++++
Admin_Login:
	int Admin_ID;
	string Admin_Pass;
	cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
	cout << "\t\t\t\t\t~~~~~ ADMIN LOGIN ~~~~~\n";
	cout << "\n\n\t\tAdmin ID: ";
	string pass = "";
	char ch;
	cin >> Admin_ID;
	cout << "\n\n\t\tAdmin Password: ";
	ch = _getch();
	while (ch != 13)
	{
		pass.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	if (pass == "123")
	{
		system("cls");
		cout << "\n\n\t\t <<<WELCOME>>> \n\n";
		cout << "\n\n\t\t PRESS ENTER TO CONTINUE \n\n";
		system("pause");
		system("cls");
		goto Admin_Block;
	}
	else
	{
		cout << "\n\n\t\t Wrong Input \n\n";
		if (loginchances > 1)
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
	cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
	cout << "\t\t\t\t\t~~~~~ ADMIN ~~~~~\n";
	cout << "\n\n\t\t1) Add or Update Movies \n\n\t\t2) Book and Update Tickets \n\n\t\t3) View Movies \n\n\t\t4) Logout \n\n\t\tYour Choice: ";
	int Admin_Choice;
	int display;
	cin >> Admin_Choice;
	if (Admin_Choice == 1)//Add and Update Movies
	{
	Add_Movie_Block:
		system("cls");
		cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
		cout << "\t\t\t\t~~~~~ Add/Update/Delete Movies ~~~~~\n\n";
		cout << "\n\n\t\t1) Add Movies \n\n\t\t2) Update Movies \n\n\t\t3) Delete Movies \n\n\t\t4) Display Movies \n\n\t\t5) Back Page \n\n\t\tYour Choice: ";
		int Movies_User_Choice;
		cin >> Movies_User_Choice;
		if (Movies_User_Choice == 1)
		{
			d = 0;
			system("cls");
			cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
			cout << "\t\t\t\t~~~~~ Add Movies ~~~~~\n\n";
			display = 0;
			addMoviedetails();
			displayMovies(d);
			system("pause");
			system("cls");
			goto Add_Movie_Block;
		}
		else if (Movies_User_Choice == 2)
		{
			d = 0;
			system("cls");
			cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
			cout << "\t\t\t\t~~~~~ Update Movies ~~~~~\n\n";
			updateMovies();
			displayMovies(d);
			system("pause");
			system("cls");
			goto Add_Movie_Block;
		}
		else if (Movies_User_Choice == 3)
		{
			system("cls");
			cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
			cout << "\t\t\t\t~~~~~ Delete Movies ~~~~~\n\n";
			display = 0;
			string M_Name;
			d = 1;
			displayMovies(d);
			deleteMovies();
			d = 0;
			displayMovies(d);
			system("pause");
			system("cls");
			goto Add_Movie_Block;
		}
		else if (Movies_User_Choice == 4)
		{
			d = 1;
			system("cls");
			cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
			cout << "\t\t\t\t~~~~~ Display Movies ~~~~~\n\n";
			displayMovies(d);
			system("pause");
			system("cls");
			goto Add_Movie_Block;
		}
		else if (Movies_User_Choice == 5)
		{
			system("cls");
			goto Admin_Block;
		}
		else
		{
			cout << "\t\t\tWrong Input!";
			system("pause");
			system("cls");
			goto Add_Movie_Block;
		}

	}
	else if (Admin_Choice == 2)//Book Ticket and Update Ticket {Remaining}
	{
		system("cls");
		cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
		cout << "\t\t\t\t~~~~~ Book/Update/Delete Ticket ~~~~~\n\n";
		BookTicket();
		Booked_Tickets();
		system("pause");
		system("cls");
		goto Admin_Block;

	}
	else if (Admin_Choice == 3)//View Movies
	{
		d = 1;
		system("cls");
		cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
		cout << "\t\t\t\t\t~~~~~ View Movies ~~~~~\n\n";
		displayMovies(d);
		system("pause");
		system("cls");
		goto Add_Movie_Block;
	}
	else if (Admin_Choice == 4)
	{
		exit(1);
	}
	else
	{
		system("cls");
		cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
		cout << "\n\n\t\t\tWrong Input!";
		cout << "\n\n\t\t\tRedirecting to Admin Page...............!";
		system("pause");
		system("cls");
		goto Admin_Block;
	}
	system("pause");
	return 0;
}
