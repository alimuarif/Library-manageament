#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;


int admin();
int book();
void search_data();
void get_data();
void start_up();
void delete_data();
void update_data();

int main()
{
	start_up();
	system("pause");
	return 0;

}

int admin()
{
	string name = "none", class1, logname;
	int pas = 0, logpas;

	cout << setw(40) << setfill('*') << "*" << endl;
	cout << "Creating your labrary account :" << endl;
	cout << setw(40) << setfill('*') << "*" << endl;
	cout << "Enter your name: " ;
	cin.ignore();
	getline(cin, name);
	cout << "Enter your class :";
	cin >> class1;
	cout << "Enter User pasword : ";
	cin >> pas;

	system("cls");
	cout << setw(40) << setfill('*') << "*" << endl;
	cout << "you are successfully created your profile :" << endl;
	cout << setw(40) << setfill('*') << "*" << endl;
	cout << endl << endl << endl;

	
a:
	cout << setw(40) << setfill('*') << "*" << endl;

	cout << "\t\tLOGIN ACCOUNT " << endl;
	cout << setw(40) << setfill('*') << "*" << endl;
	cout << "Enter your name : " ;
	cin.ignore();
	getline(cin, logname);
	cout << "Enter User pasword : ";
	cin >> logpas;

	if (logpas == pas)
	{

		system("cls");
		book();
		return 0;
	}

	else
	{
		cout << "\n\nIncorrect Pasword or UserName" << endl<<endl<<endl;
		goto a;
	}
	return 0;
}
int  book()
{
	int n = 0;
b:
	cout << endl << "                                                   Welcome" << endl;
	cout << endl << "Press 1 to Enter Data : " << endl;
	cout << endl << "Press 2 to SearchData : " << endl;
	cout << endl << "Press 3 to UpDate Data : " << endl;
	cout << endl << "Press 4 to Delete Data : " << endl;
	cout << endl << "Press 5 to Exit : " << endl << endl<<endl;

	cout << "Enter your number :";
	cin >> n;
	switch (n)
	{
	case 1:
		get_data();
		system("pause");
		system("cls");
		goto b;
		break;

	case 2:
		search_data();
		system("pause");
		system("cls");
		goto b;
		break;

	case 3:
		update_data();
		system("pause");
		system("cls");
		goto b;
		break;

	case 4:
		delete_data();
		system("pause");
		system("cls");
		goto b;
		break;

	case 5:
		return 0;

	}
	return 0;
}
void get_data()
{
	fstream a;
	string s;
	fstream b;
	string book_name = "none";
	string book_id = "none";
	a.open("book_list.txt", ios::app);


	cout << endl << "Enter Book Id : " << endl;

	cin.ignore();
	getline(cin, book_id);
	s = book_id + ".txt";
	b.open(s.c_str(), ios::app | ios::out);
	a << book_id << endl;
	b << book_id << endl;

	
	cout << endl << "Enter Book Name : " << endl;


	getline(cin,book_name);

	b << book_name << endl;
	a.close();
	b.close();


}


void search_data()
{
	string book_id = "none";
	string search = "none";
	string book_name = "none";
	cin.ignore();
	cout << endl << "Enter Book Id you want to search : " << endl;

	getline(cin, book_id);

	fstream a;
	fstream b;
	a.open("book_list.txt", ios::in);

	while (a.good())
	{
		a >> search;

		if (search == book_id)
		{

			string s;
			s = search + ".txt";
			b.open(s.c_str(), ios::in);

			b >> book_id;
			cout << endl << "Book Id : " << book_id;
			b >> book_name;
			cout << endl << "Book Name : " << book_name<<endl<<endl;
			b.close();
			break;

		}
	}
	a.close();
}
void delete_data()
{
	string book_id = "none";
	string search = "none";
	cout << endl << "Enter Book Id You want to delete" << endl;
	cin >> book_id;
	fstream a;

	fstream c;
	a.open("book_list.txt", ios::in);
	c.open("book_list1.txt", ios::out | ios::app);
	while (a.good())
	{
		a >> search;
		if (book_id != search)
		{
			c << search << endl;

		}


	}
	a.close();
	c.close();
	remove("book_list.txt");
	rename("book_list1.txt", "book_list.txt");
	remove("book_list1.txt");
}

void update_data()
{
	string book_id = "none";
	string search = "none";
	string temp_id = "none";
	string temp_name = "none";

	cout << endl << "Enter Book Id You want to Updte" << endl;
	cin >> book_id;
	fstream a;
	fstream b;
	fstream c;
	a.open("book_list.txt", ios::in);
	c.open("book_list1.txt", ios::out | ios::app);
	while (a.good())
	{
		a >> search;
		if (book_id == search)
		{

			cout << endl << "Enter a New Book Id : " << endl;
			cin >> temp_id;
			string s;
			s = temp_id + ".txt";
			b.open(s.c_str(), ios::out | ios::app);
			b << temp_id;
			cout << endl << "Enter a New Book Name : " << endl;
			cin >> temp_name;
			b << temp_name;
			a.close();
			c.close();
			b.close();
			remove("book_list.txt");
			rename("book_list1.txt", "book_list.txt");
			remove("book_list1.txt");
			break;
		}
		else
		{
			c << search << endl;
		}


	}
	a.close();
	c.close();
	b.close();
	remove("book_list.txt");
	rename("book_list1.txt", "book_list.txt");
	remove("book_list1.txt");
}
void start_up()
{
	system("cls");
	cout << "\n\n\n\n\n\n\n\t\t#########################################";
	cout << "\n\t\t#\t\tWELCOME TO\t\t#";
	cout << "\n\t\t#   SUPERIOR LIBRARY MANAGEMENT SYSTEM  #";
	cout << "\n\t\t#########################################";
	cout << endl;
	//cout<<"\n\n\n\n\n press any key to continue......\n";
	//getch();//Use to holds screen for some seconds
	//	system("cls");//Use to clear screen
	admin();
}

