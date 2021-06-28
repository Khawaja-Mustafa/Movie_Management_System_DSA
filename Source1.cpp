#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct registerddl
{
	int ID;
	string Name, Address, PhoneNo, Student, Institute;
	registerddl* next;
	registerddl* prev;
};
registerddl* R_head = NULL;
void RegisterUser()
{
	registerddl* newnode = new registerddl();
	int iId;
	string iname, iAddress, iPhone, student, institute;
	cout << "\t\t\tEnter ID:";
	cin >> iId;
	cout << "\t\t\tEnter Name:";
	cin.ignore();
	getline(cin, iname);
	cout << "\t\t\tEnter Address:";
	getline(cin, iAddress);
	cout << "\t\t\tEnter Phone No:";
	getline(cin, iPhone);
	cout << "\t\t\tstudent(Yes Or No):";
	cin >> student;
	if (student == "yes"||student == "Yes")
	{
		cout << "\t\t\tEnter Institute Name : ";
		cin.ignore();
		getline(cin, institute);
	}
	else
	{
		institute = "None";
		cout << "\t\t\tEnter Institute Name : " << institute <<"\n";
	}
	newnode->ID = iId;
	newnode->Address = iAddress;
	newnode->Name = iname;
	newnode->PhoneNo = iPhone;
	newnode->Student = student;
	newnode->Institute = institute;
	if (R_head == NULL)
	{
		newnode->next = NULL;
		newnode->prev = NULL;
		R_head = newnode;
		return;
	}
	else
	{
		registerddl* temp = R_head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->prev = temp;
		newnode->next = NULL;
	}
	
}
void R_display(int idisplay)
{
	fstream file, file2;
	registerddl* temp = R_head;
	file2.open("Registered_Users.txt", ios::out | ios::in | ios::trunc);
	file.open("Registered_Users.txt", ios::out| ios::in | ios::app);
	if(idisplay==0)
	{
	while (temp != NULL)
	{
		file << "Name : " << temp->Name << endl;
		file << "ID : " << temp->ID << endl;
		file << "Address : " << temp->Address << endl;
		file << "Phone No : " << temp->PhoneNo << endl;
		file << "student(Yes Or No) : " << temp->Student << endl;
		file << "Institute Name : " << temp->Institute << endl;
		temp = temp->next;
	}
	file2.close();
	file.close();
	}
	else if(idisplay==1)
	{
		while (temp != NULL)
		{
			cout << "ID : " << temp->ID << endl;
			cout << "Name : " << temp->Name << endl;
			cout << "Address : " << temp->Address << endl;
			cout << "Phone No : " << temp->PhoneNo << endl;
			cout << "student(Yes Or No) : " << temp->Student << endl;
			cout << "Institute Name : " << temp->Institute << endl;
			temp = temp->next;
		}
	}

}
void R_update()
{
		int id;
		if (R_head == NULL)
		{
			cout << "\n\t NULL";
		}
		else
		{
			registerddl* temp = R_head;
			cout << "\n\t\t Enter Id You Want To Update = ";
			cin >> id;
			cout << "\n";
			while (temp != NULL)
			{
				if (id == temp->ID)
				{
					cout << "\n\t\t The Id : "; 
					cin >> temp->ID;
					cout << "\n\t\t The Name : "; 
					cin >> temp->Name;
					cout << "\n\t\t The Phone No# : "; 
					cin >> temp->PhoneNo;
					cout << "\n\t\tStudent(Yes Or No) : "; 
					cin >> temp->Student;
					cout << "\n\t\t Institute Name "; 
					cin >> temp->Institute;
				}
				temp = temp->next;
			}
		}
}

void R_delete(int id)
{
	registerddl* p, * q;
	q = R_head;
	p = R_head->next;
	if (q->ID == id)
	{
		R_head = p;
		delete(q);
	}
	else
	{
		while (p->ID != id)
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
			q->next = p->next->prev;
			p->next->prev = q;
			delete(p);
		}
	}
}

//---------------------MovieFunction Block---------------------------------
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
	cout << "Movie Movie_Name:";
	cin.ignore();
	getline(cin, iname);
	cout << "\nVenue Date:";
	cin.ignore();
	getline(cin, idate);
	cout << "\nVenue Time:";
	cin.ignore();
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
void updateMovies(string mName)
{
	Movieddl* temp = M_head;
	while (temp != NULL)
	{
		if (temp->Movie_Name == mName)
		{
			cout << "Enter updated Movie_Name : ";
			cin >> temp->Movie_Name;
			cout << "Enter updated Date : ";
			cin >> temp->Movie_Date;
			cout << "Enter updated Time : ";
			cin >> temp->Movie_Time;
			return;
		}
		temp = temp->next;
	}
}

void displayMovies(int d)
{
	fstream file, file2;
	Movieddl* temp = M_head;
	if(d==0)
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
	else if(d==1)
	{
		while (temp != NULL)
		{
			cout << temp->Movie_Name << endl;
			cout << temp->Movie_Date << endl;
			cout << temp->Movie_Time << endl << endl;
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
void deleteMovies(string m_name)
{
	Movieddl* p, * q;
	q = M_head;
	p = M_head->next;
	if (q->Movie_Name == m_name)
	{
		M_head = p;
		delete(q);
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
			q->next = p->next->prev;
			p->next->prev = q;
			delete(p);
		}
	}
}
int searchmovie(string n_movie) {
	Movieddl* temp = M_head;
	while (temp != NULL) {
		if (n_movie == temp->Movie_Name) {
			return 1;
		}
		else {
			return 0;
		}
		temp = temp->next;
	}
}

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
	string Movie_Name;
	int x;
	int TicketPrice = 600;
	int totalPayment = 0;
	int choice = 0;
	char Student;
	cin.ignore();
	getline(cin, Movie_Name);
	x= searchmovie(Movie_Name);
	if (x == 1) 
	{
		//searchFun(Movie Name);
		//Fourth Node -> Batman -> h1 -> 30 05 2000
		string institute_N, program;
		cout << "\n\t\t\t\t" << "Student : ";
		cin >> Student;
		if (Student == 'y' || Student == 'Y')
		{
			cout << "Enter Institution name: ";
			string institution;
			cin.ignore();
			getline(cin, institution);
			cout << endl;
			system("pause");
			system("cls");
			TicketPrice = 300;
			cout << "\n\t\t\t\t" << "Movie Name : " << Movie_Name << endl;
			//cout << "\n\t\t\t\t" << "Movie Venue : " << Movie_Venue[0] << endl;
			//cout << "\n\t\t\t\t" << "Movie Date : " << day[0] << "/" << month[0] << "/" << year[0] << endl;
			totalPayment = Payment * TicketPrice;
			cout << "\n\t\t\t\t" << "Price of Tickets : " << TicketPrice << endl;
			cout << "\n\t\t\t\t" << "Amount of Tickets : " << Payment << endl;
			cout << "\n\t\t\t\t" << "The Total Bill : " << totalPayment << endl;
			Payment = 0;
		}
		else
		{
			system("pause");
			system("cls");
			cout << "\n\t\t\t\t" << "Movie Name : " << Movie_Name << endl;
			//cout << "\n\t\t\t\t" << "Movie Venue : " << Movie_Venue[0] << endl;
			//cout << "\n\t\t\t\t" << "Movie Date : " << day[0] << "/" << month[0] << "/" << year[0] << endl;
			totalPayment = Payment * TicketPrice;
			cout << "\n\t\t\t\t" << "Price of Tickets : " << TicketPrice << endl;
			cout << "\n\t\t\t\t" << "Amount of Tickets : " << Payment << endl;
			cout << "\n\t\t\t\t" << "The Total Bill : " << totalPayment << endl;
			Payment = 0;
		}
	}
	else 
	{
		cout << "Movie not found\n";
	}
}


//-----------------------------------------------------------MAIN FUNCTION---------------------------------------------------------------------
int main()
{
	int d;
	int loginchances = 3;
	Main_Page:
	int i = 0;
	cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
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

//+++++++++++++++++++++++++++++Admin Block+++++++++++++++++++++++++++++++++++++++++++++++++++++
	Admin_Login:
	int Admin_ID;
	string Admin_Pass;
	cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
	cout << "\t\t\t\t\t~~~~~ ADMIN LOGIN ~~~~~\n";
	cout << "\n\n\t\tAdmin ID: ";
	cin >> Admin_ID;
	cout << "\n\n\t\tAdmin Password: ";
	cin.ignore();
	getline(cin, Admin_Pass);
	if(Admin_ID == 123 && Admin_Pass == "123")
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
	cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
	cout << "\t\t\t\t\t~~~~~ ADMIN ~~~~~\n";
	cout << "\n\n\t\t1) Register Users \n\n\t\t2) Book and Update Tickets \n\n\t\t3) Add or Update Movies \n\n\t\t4) Print or Update Bill \n\n\t\t5) View Movies \n\n\t\tYour Choice: ";
	int Admin_Choice;
	int display;
	cin >> Admin_Choice;
	if(Admin_Choice == 1)//Register Users 
	{
		Reg_User_Page:
		system("cls");
		cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
		cout << "\t\t\t\t~~~~~ Register New Users ~~~~~\n\n";
		cout << "\n\n\t\t1) Register New User \n\n\t\t2) Update User \n\n\t\t3) Delete User \n\n\t\t4) Display Reg User \n\n\t\t5) Back Page \n\n\t\tYour Choice: ";
		int Reg_User_Choice;
		cin >> Reg_User_Choice;
		if (Reg_User_Choice == 1)
		{
			system("cls");
			cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
			cout << "\t\t\t\t~~~~~ Register New Users ~~~~~\n\n";
			display = 0;
			RegisterUser();
			R_display(display);
			system("pause");
			system("cls");
			goto Reg_User_Page;
		}
		else if(Reg_User_Choice==2)
		{
			system("cls");
			cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
			cout << "\t\t\t\t~~~~~ Register New Users ~~~~~\n\n";
			display = 0;
			R_update();
			R_display(display);
			system("pause");
			system("cls");
			goto Reg_User_Page;
		}
		else if (Reg_User_Choice == 3)
		{
			system("cls");
			cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
			cout << "\t\t\t\t~~~~~ Delete Users ~~~~~\n\n";
			display = 0;
			int id;
			cout << "\n\n\t\tEnter the id of the user you want to delete: ";
			cin >> id;
			R_delete(id);
			R_display(display);
			system("pause");
			system("cls");
			goto Reg_User_Page;
		}
		else if (Reg_User_Choice == 4)
		{
			system("cls");
			cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
			cout << "\t\t\t\t~~~~~ Display Users ~~~~~\n\n";
			display = 1;
			R_display(display);
			system("pause");
			system("cls");
			goto Reg_User_Page;
		}
		else if (Reg_User_Choice == 5) 
		{
			system("cls");
			goto Admin_Block;
		}
		else
		{
			cout << "\t\t\tWrong Input!";
			system("pause");
			system("cls");
			goto Reg_User_Page;
		}
		
	}
	else if(Admin_Choice == 2)//Book Ticket and Update Ticket {Remaining}
	{
		system("cls");
		cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
		cout << "\t\t\t\t~~~~~ Book/Update/Delete Ticket ~~~~~\n\n";
		BookTicket();
		Booked_Tickets();


	}
	else if(Admin_Choice == 3)//Add and Update Movies
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
			string M_Name;
			updateMovies(M_Name);
			displayMovies(d);
			system("pause");
			system("cls");
			goto Add_Movie_Block;
		}
		else if (Movies_User_Choice == 3)
		{
			d = 0;
			system("cls");
			cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
			cout << "\t\t\t\t~~~~~ Delete Movies ~~~~~\n\n";
			display = 0;
			string M_Name;
			cout << "\n\n\t\tEnter the id of the user you want to delete: ";
			cin >> M_Name;
			deleteMovies(M_Name);
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
	else if (Admin_Choice == 4)//Print or Update BIll{Remaining}
	{
		system("cls");
		cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
		cout << "\t\t\t\t~~~~~ Print/Update/Delete Bill ~~~~~\n\n";


	}
	else if (Admin_Choice == 5)//View Movies
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
