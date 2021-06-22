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
		cout << "\t\t\tEnter Institute Name : None\n";
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

int main()
{
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
	cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
	cout << "\t\t\t\t\t~~~~~ ADMIN ~~~~~\n";
	cout << "\n\n\t\t1) Register Users \n\n\t\t2) Book and Update Tickets \n\n\t\t3) Add or Update Movies \n\n\t\t4) Print or Update Bill \n\n\t\t5) View Movies \n\n\t\tYour Choice: ";
	int Admin_Choice;
	int display;
	cin >> Admin_Choice;
	if(Admin_Choice == 1)
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
			cout << "\t\t\t\t~~~~~ Register New Users ~~~~~\n\n";
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
			cout << "\t\t\t\t~~~~~ Register New Users ~~~~~\n\n";
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
		
	}
	else if(Admin_Choice == 2)
	{
		system("cls");
		cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
		cout << "\t\t\t\t~~~~~ Book/Update/Delete Ticket ~~~~~\n\n";
	}
	else if(Admin_Choice == 3)
	{
		system("cls");
		cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
		cout << "\t\t\t\t~~~~~ Add/Update/Delete Movies ~~~~~\n\n";
	}
	else if (Admin_Choice == 4)
	{
		system("cls");
		cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
		cout << "\t\t\t\t~~~~~ Print or Update Bill ~~~~~\n\n";
	}
	else if (Admin_Choice == 5)
	{
		system("cls");
		cout << "\t\t\t\t~~~~~ Movie Management System ~~~~~\n";
		cout << "\t\t\t\t\t~~~~~ View Movies ~~~~~\n\n";
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
