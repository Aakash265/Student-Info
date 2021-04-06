//There is a login part at the start of the program. Please input the details given below as user id and password ....
//*******User id is 2020 and password is abc********
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<conio.h>
using namespace std;
class login
{
	int id;
	string password;
	public:
		void login_page();
};

void login::login_page()
{
	string str("abc");
	cout<<setw(18)<<"LOGIN USERNAME"<<endl;
	cout<<"Enter your Username: ";
	cin>>id;
	if (id==2020)
	{
		cout<<"Username matched...\n";
	}
	else
	while(id!=2020)
	{
			cout<<"Wrong username\a\n";
			cout<<"Enter username again: ";
			cin>>id;
			if(id==2020)
			{
			    cout<<"Username matched..."<<endl;
				break;	
			}
	}
	cout<<"Password: ";
	getline(cin>>ws, password);
	if (str==password)
	{
		cout<<"Password matched... \nLogin confirm...\n";
	}
	else
	while(password!=str)
	{
			cout<<"Wrong Pasword\a\n";
			cout<<"Enter password again: ";
			getline(cin>>ws, password);
			if(password==str)
			{
				cout<<"Password matched... \nLogin confirm...\n";
				break;
			}
	}	
}
class student
{
	string name, f_name, add, email, mob, br;
	int reg_no, inter;
	float cgpa, avg_att, perc;
	public:
		void input();
		void delete_data();
		void search();
		void view();
};

void student::input()
{
	int i=1;
	while(i>0)
		{
			label:
			cout<<"Enter Registration No.: ";
			cin>>reg_no;	
			cout<<"Enter the name of student: ";
			getline(cin>>ws, name);
			cout<<"Enter Father's name: ";
			getline(cin>>ws, f_name);
			cout<<"Enter Mobile no.: ";
			getline(cin>>ws, mob);
			cout<<"Enter Branch of the student: ";
			getline(cin>>ws, br);
			cout<<"Enter address of the student: ";
			getline(cin>>ws, add);
			cout<<"Enter E-mail address of the student: ";
			getline(cin>>ws, email);
			cout<<"Enter average CGPA of the student: ";
			cin>>cgpa;
			cout<<"Enter the average attendance of the student: ";
			cin>>avg_att;
			cout<<"Enter no of interviews the student has cleared: ";
			cin>>inter;
			cout<<"Enter the percentage the student got in class 12: ";
			cin>>perc;
			cout<<"Data input successful..."<<endl;

			fstream fout;
			fout.open("Student.txt", ios::app);
			if(!fout)
			{
				cout<<"Error in opening file!!!";
			}
			
			fout<<"Registration No.: "<<reg_no<<endl;
			fout<<"Name: "<<name<<endl;
			fout<<"Father's Name: "<<f_name<<endl;
			fout<<"Mobile No.: "<<mob<<endl;
			fout<<"Branch: "<<br<<endl;
			fout<<"Address: "<<add<<endl;
			fout<<"E-mail Address: "<<email<<endl;
			fout<<"Average CGPA: "<<cgpa<<endl;
			fout<<"Average Attendance: "<<avg_att<<"%"<<endl;
			fout<<"Selection in interviews: "<<inter<<endl;
			fout<<"12th Percentage: "<<perc<<"%"<<endl;
			fout<<endl;
		    fout.close();

			char a='y';
			cout<<"\nWant to enter more data? (y/n): ";
			cin>>a;       	
			cout<<endl;	
				if (a=='y')
					{
						i++;
						goto label;
					}
					else
					{
						break;
					}
			
	   }
}

void student::view()
{
	fstream fin;
	fin.open("Student.txt", ios::in);
	if(!fin)
	{
		cout<<"File not found!!!\n";
	}
	string content;
	while(getline(fin, content))
	{
		cout<<content<<endl;
	}
	fin.close();
}

void student::search()
{
	fstream fin;
	string info, content;
	int temp;
	fin.open("Student.txt", ios::in);
	cout<<"Enter the Registration No. of the student: ";
	cin>>info;
	cout<<endl;
	if (fin.is_open())
	{
		while(!fin.eof())
		{
			getline(fin, content);
			if((temp=content.find(info, 0))!=string::npos)
			{
				cout<<"Data found!!!\n"<<endl;
				char ch;
				while(!fin.eof())
				{
					fin>>noskipws>>ch;
					cout<<ch;
				}
				fin.close();
			}
		}
	}
		else 
		cout<<"No data found!!!";
}

void student::delete_data()
{
  string line, no;
  cout<<"Enter the Registration no. of student whose record you want to delete: ";
  cin>>no;
  fstream fin;
  fstream fout;
  fin.open("Student.txt");
  fout.open("temp.txt");
  while (getline(fin, line))
  {
    if (line != name)
      fout<<line<<endl;
  }
  cout<<"The record with the Reg no "<<no<<" has been deleted if it exsisted"<<endl;
  fin.close();
  fout.close();
  remove("Student.txt");
  rename("temp.txt", "Student.txt");
}

main()
{
	student s;
	int x;
	login ob;
	ob.login_page();
	cout<<endl;
	cout<<setw(10)<<"HOME\n";
	cout<<"[1]Enter Student data\n";
	cout<<"[2]View Student data\n";
	cout<<"[3]Search Student data\n";
	cout<<"[4]Delete Student data\n";
	cout<<"[5]Log Out\n";
	for (int i=1; i>0; i++)
	{
		cout<<"\nWhich action you want to perform ? "<<endl;
		cin>>x;
		cout<<endl;
		switch(x)
		{
			case 1: 
				{
					s.input();
					break;
				}

			case 2: 
				{
					s.view();
					break;
				}
				
			case 3:
				{
					s.search();
					break;	
				}
				
			case 4:
				{
					s.delete_data();
					break;
				}
				
			case 5:
				{
					cout<<"Logging Out...";
					return(0); 
					break;					
				}	
			default:
				{
					cout<<"Error in performing operation!!!!!";
					break;
				}								
		}
	}
}
