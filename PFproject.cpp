#include<iostream>
#include<fstream>
#include<string>
using namespace std;
string name, father, id, date, crime, bondage, designation, criminalId, status;
int age, batch;
struct criminal{
	string name;
	string father;
	int age;
	int batch;
	string id;
	char crime;
	string date;
	string bondage;
	string idNo;

}c;

void addCriminalRecord() {
	ofstream write;
	write.open("E:\\salman\\file2.txt", ios::app);
	if (write.fail()) {
		cout << "THE FILE COULD NOT BE OPEN...press any key";
		cin.ignore();
		cin.get();
	}

	cout << "\n\n";
	cout << "\t\t\t<========ADD A CRIMINAL RECORD=========>\n\n";
	cout << "\t\t\tEnter Criminal Name: ";
	cin.ignore();
	getline(cin, c.name);
	cout << "\t\t\tEnter Criminal Father Name: ";
	getline(cin, c.father);
	cout << "\t\t\tEnter Criminal Age: ";
	cin >> c.age;
	cout << "\t\t\tEnter Criminal Batch Number: ";
	cin >> c.batch;
	cout << "\t\t\tEnter Criminal id-card Number: ";
	cin.ignore();
	getline(cin, c.id);
	cout << "\t\t\tEnter Crime Date: ";
	getline(cin, c.date);
	cout << "\t\t\tEnter Crime: ";
	cin >>  c.crime;
	cout << "\t\t\tEnter Time of Bondage: ";
	cin.ignore();
	getline(cin,  c.bondage);

	write << c.name << endl;
	write << c.father << endl;
	write << c.age << endl;
	write << c.batch << endl;
	write << c.id << endl;
	write << c.date << endl;
	write << c.crime << endl;
	write << c.bondage << endl;
	write.close();

	cin.ignore();
	cout << endl;
	cout << "\t\t\t\tTHE RECORD SUCCESSFULLY SAVED" << endl;
	cout << endl;
	cout << "Press Any Key To Continue...";
	cin.ignore();
	cin.get();
}
void displayCriminalRecord() {
	ifstream read;
	bool check = true;
	read.open("E:\\salman\\file2.txt", ios::app);
	if (read.fail()) {
		cout << "THE FILE COULD NOT BE OPEN...press any key";
		cin.ignore();
		cin.get();
	}

	cout << "\n\n";
	cout << "\t\t\t<========ALL CRIMINAL RECORDS=========>\n\n";
	cout << "\t\t\t\t<=============================>"<< endl << endl;

	while (read >> c.name >> c.father >> c.age >>c. batch >>c. id >>c. date >>c. crime >>c. bondage) {
		cout << "\t\t\tCriminal Name: " <<c. name << endl;
		cout << "\t\t\tCriminal Father Name: " << c.father << endl;
		cout << "\t\t\tCriminal Age: " << c.age << endl;
		cout << "\t\t\tCriminal Batch Number: " << c.batch << endl;
		cout << "\t\t\tCriminal id-card Number: " << c.id << endl;
		cout << "\t\t\tCrime Date: " <<c.date << endl;
		cout << "\t\t\tCrime: " <<c.crime << endl;
		cout << "\t\t\tTime of Bondage: " <<c.bondage << endl;
		cout << "\t\t\t\t<=============================>"<< endl << endl;

		check = false;
	}

	read.close();

	if (check)
		cout << "\t\t\t\tNO RECORDS FOUND...." << endl;

	cout << endl;
	cout << "Press Any Key To Continue...";
	cin.ignore();
	cin.get();
}

void modifyCriminalRecord()
{
	
	bool check = true;
	ifstream read("E:\\salman\\file2.txt");
	ofstream write("E:\\salman\\temp.txt");
	cout << "\n\n";
	cout << "\t\t\t<========MODIFY CRIMINAL RECORD=========>\n\n";
	cout << "\t\t\tEnter Criminal ID: ";
	cin.ignore();
	getline(cin, c.idNo);
	cout << endl;

	while (read >>c.name >> c.father >> c.age >> c.batch >> c.id >> c.date >> c.crime >> c.bondage) {
		if (c.id == c.idNo) {

			cout << "\n\n";
			cout << "\t\t\t<========MODIFY CRIMINAL RECORD=========>\n\n";
			cout << "\t\t\t\t<=============================>"<< endl << endl;
			cout << "\t\t\tChange Criminal Name: ";
			cin.ignore();
			getline(cin, c.name);
			cout << "\t\t\tChange Criminal Father Name: ";
			getline(cin, c.father);
			cout << "\t\t\tChange Criminal Age: ";
			cin >> c.age;
			cout << "\t\t\tChange Criminal Batch Number: ";
			cin >> c.batch;
			cout << "\t\t\tChange Criminal id-card Number: ";
			cin.ignore();
			getline(cin, c.id);
			cout << "\t\t\tChange Crime Date: ";
			getline(cin, c.date);
			cout << "\t\t\tChange Crime: ";
			cin >> c.crime;
			cout << "\t\t\tChange Time of Bondage: ";
			cin.ignore();
			getline(cin,c.bondage);
			cout << "\t\t\t\t<=============================>"<< endl << endl;

			write << c.name << endl;
			write << c.father << endl;
			write << c.age << endl;
			write << c.batch << endl;
			write << c.id << endl;
			write << c.date << endl;
			write << c.crime << endl;
			write << c.bondage << endl;

			check = false;
		}
		else {
			write << name << endl;
			write << father << endl;
			write << age << endl;
			write << batch << endl;
			write << id << endl;
			write << date << endl;
			write << crime << endl;
			write << bondage << endl;
		}
	}

	if (check) {
		cout << "\t\t\t\tNO RECORD FOUND...." << endl;
		cout << endl;
	}
	else {
		cout << "\t\t\tFILE IS UPDATED SUCCESSFULLY" << endl;
		cout << endl;
	}

	cout << "Press Any Key To Continue...";
	cin.ignore();
	cin.get();
	read.close();
	write.close();
	remove("E:\\salman\\file2.txt");
	rename("E:\\salman\\Temp.txt", "E:\\salman\\file2.txt");
}

void deleteCriminalRecord() {
	char choice;

	bool check = true;
	ifstream read("E:\\salman\\file2.txt");
	ofstream write("E:\\salman\\Temp.txt");
	cout << "\n\n";
	cout << "\t\t\t<========MODIFY CRIMINAL RECORD=========>\n\n";
	cout << "\t\t\tEnter Criminal ID: ";
	cin.ignore();
	getline(cin, c.idNo);
	cout << endl;

	while (read >> c.name >> c.father >> c.age >> c.batch >> c.id >> c.date >> c.crime >> c.bondage) {
		if (c.id == c.idNo) {
			continue;
		}
		else {
			check = false;
			write << c.name << endl;
			write << c.father << endl;
			write << c.age << endl;
			write << c.batch << endl;
			write << c.id << endl;
			write << c.date << endl;
			write << c.crime << endl;
			write << c.bondage << endl;
		}
	}

	if (check) {
		cout << "\t\t\tRECORD NOT FOUND...." << endl;
		cout << endl;
	}
	else {
		cout << "\t\t\t\tRECORD DELETED SUCCESSFULLY";
		cout << endl;
	}

	cout << "Press any key to continue....";
	cin.ignore();
	cin.get();
	read.close();
	write.close();
	remove("E:\\salman\\file2.txt");
	rename("E:\\salman\\temp.txt", "E:\\salman\\file2.txt");
}
struct staff{
	string name;
	string designation;
	int age;
	string id;
}s;
void addStaffRecord() {
	ofstream write;
	write.open("E:\\salman\\file3.txt", ios::app);

	if (write.fail()) {
		cout << "THE FILE COULD NOT BE OPEN...press any key";
		cin.ignore();
		cin.get();
	}

	cout << "\n\n";
	cout << "\t\t\t<========ADD A STAFF RECORD=========>\n\n";
	cout << "\t\t\tEnter Staff Name: ";
	cin.ignore();
	getline(cin, s.name);
	cout << "\t\t\tEnter Staff Designation: ";
	getline(cin, s.designation);
	cout << "\t\t\tEnter Staff Age: ";
	cin >> s.age;
	cout << "\t\t\tEnter Staff ID: ";
	cin.ignore();
	getline(cin, s.id);

	write << s.name << endl;
	write << s.designation << endl;
	write << s.age << endl;
	write << s.id << endl;

	write.close();
	cin.ignore();
	cout << endl;
	cout << "\t\t\t\tTHE FILE SUCCESSFULLY SAVED" << endl;
	cout << endl;
	cout << "Press Any Key To Continue...";
	cin.ignore();
	cin.get();
}

void viewStaffRecord() {
	ifstream read;
	bool check = true;
	read.open("E:\\salman\\file3.txt", ios::app);

	if (read.fail()) {
		cout << "THE FILE COULD NOT BE OPEN...press any key";
		cin.ignore();
		cin.get();
	}

	cout << "\n\n";
	cout << "\t\t\t<========ALL STAFF RECORD=========>\n\n";
	cout << "\t\t\t\t<=============================>"<< endl << endl;

	while (getline(read, s.name)) {
		getline(read, s.designation);
		read >> s.age;
		read.ignore();
		getline(read, s.id);

		cout << "\t\t\tStaff Name: " << s.name << endl;
		cout << "\t\t\tStaff Designation: " << s.designation << endl;
		cout << "\t\t\tStaff Age: " << s.age << endl;
		cout << "\t\t\tStaff ID: " << s.id << endl;
		cout << "\t\t\t\t<=============================>"<< endl << endl;

		check = false;
	}

	read.close();

	if (check)
		cout << "\t\t\t\tRECORD NOT FOUND...." << endl;

	cout << endl;
	cout << "Press Any Key To Continue...";
	cin.ignore();
	cin.get();
}

void modifyStaffRecord() {
	string idNo;
	bool check = true;
	ifstream read("E:\\salman\\file3.txt");
	ofstream write("E:\\salman\\Temp.txt");

	cout << "\n\n";
	cout << "\t\t\t<========MODIFY STAFF RECORD=========>\n\n";
	cout << "\t\t\tEnter Staff ID: ";
	cin.ignore();
	getline(cin, idNo);
	cout << endl;

	while (getline(read, s.name)) {
		getline(read, s.designation);
		read >> s.age;
		read.ignore();
		getline(read, s.id);

		if (s.id == idNo) {
			cout << "\t\t\tChange Staff Name: ";
			getline(cin, s.name);
			cout << "\t\t\tChange Staff Designation: ";
			getline(cin, s.designation);
			cout << "\t\t\tChange Staff Age: ";
			cin >> s.age;
			cout << endl;

			check = false;
		}

		write << s.name << endl;
		write << s.designation << endl;
		write << s.age << endl;
		write << s.id << endl;
	}

	if (check) {
		cout << "\t\t\t\tNO RECORD FOUND...." << endl;
		cout << endl;
	}
	else {
		cout << "\t\t\tFILE IS UPDATED SUCCESSFULLY" << endl;
		cout << endl;
	}

	cout << "Press Any Key To Continue...";
	cin.ignore();
	cin.get();
	read.close();
	write.close();
	remove("E:\\salman\\file3.txt");
	rename("E:\\salman\\Temp.txt", "E:\\salman\\file3.txt");
}

void deleteStaffRecord() {
	string idNo;
	bool check = true;
	ifstream read("E:\\salman\\file3.txt");
	ofstream write("E:\\salman\\Temp.txt");

	cout << "\n\n";
	cout << "\t\t\t<========DELETE STAFF RECORD=========>\n\n";
	cout << "\t\t\tEnter Staff ID: ";
	cin.ignore();
	getline(cin, idNo);
	cout << endl;

	while (getline(read, s.name)) {
		getline(read, s.designation);
		read >> s.age;
		read.ignore();
		getline(read, s.id);

		if (s.id == idNo) {
			continue;
		}
		else {
			check = false;
			write << s.name << endl;
			write << s.designation << endl;
			write << s.age << endl;
			write << s.id << endl;
		}
	}

	if (check) {
		cout << "\t\t\tRECORD NOT FOUND...." << endl;
		cout << endl;
	}
	else {
		cout << "\t\t\t\tRECORD DELETED SUCCESSFULLY";
		cout << endl;
	}

	cout << "Press Any Key To Continue...";
	cin.ignore();
	cin.get();
	read.close();
	write.close();
	remove("E:\\salman\\file3.txt");
	rename("E:\\salman\\temp.txt", "E:\\salman\\file3.txt");
}
struct FIR{
	string id;
	string name;
	string criminalId;
	string crime;
	string date;
	string status;

}f;
void addFIRRecord() {
	ofstream write;
	write.open("E:\\salman\\file4.txt", ios::app);

	if (write.fail()) {
		cout << "THE FILE COULD NOT BE OPEN...press any key";
		cin.ignore();
		cin.get();
	}

	cout << "\n\n";
	cout << "\t\t\t<========ADD A FIR RECORD=========>\n\n";
	cout << "\t\t\tEnter FIR ID: ";
	cin.ignore();
	getline(cin, f.id);
	cout << "\t\t\tEnter Complainant Name: ";
	getline(cin, f.name);
	cout << "\t\t\tEnter Criminal ID: ";
	getline(cin, f.criminalId);
	cout << "\t\t\tEnter Crime: ";
	getline(cin, f.crime);
	cout << "\t\t\tEnter Date: ";
	getline(cin, f.date);
	cout << "\t\t\tEnter Status: ";
	getline(cin, f.status);

	write << f.id << endl;
	write << f.name << endl;
	write << f.criminalId << endl;
	write << f.crime << endl;
	write << f.date << endl;
	write << f.status << endl;

	write.close();
	cin.ignore();
	cout << endl;
	cout << "\t\t\t\tTHE FILE SUCCESSFULLY SAVED" << endl;
	cout << endl;
	cout << "Press Any Key To Continue...";
	cin.ignore();
	cin.get();
}

void viewFIRRecord() {
	ifstream read;
	bool check = true;
	read.open("E:\\salman\\file4.txt", ios::app);

	if (read.fail()) {
		cout << "THE FILE COULD NOT BE OPEN...press any key";
		cin.ignore();
		cin.get();
	}

	cout << "\n\n";
	cout << "\t\t\t<========ALL FIR RECORD=========>\n\n";
	cout << "\t\t\t\t<=============================>"<< endl << endl;

	while (getline(read, f.id)) {
		getline(read, f.name);
		getline(read, f.criminalId);
		getline(read, f.crime);
		getline(read, f.date);
		getline(read, status);

		cout << "\t\t\tFIR ID: " << f.id << endl;
		cout << "\t\t\tComplainant Name: " << f.name << endl;
		cout << "\t\t\tCriminal ID: " << f.criminalId << endl;
		cout << "\t\t\tCrime: " << f.crime << endl;
		cout << "\t\t\tDate: " << f.date << endl;
		cout << "\t\t\tStatus: " << f.status << endl;
		cout << "\t\t\t\t<=============================>"<< endl << endl;

		check = false;
	}

	read.close();

	if (check)
		cout << "\t\t\t\tRECORD NOT FOUND...." << endl;

	cout << endl;
	cout << "Press Any Key To Continue...";
	cin.ignore();
	cin.get();
}

void modifyFIRRecord() {
	string idNo;
	bool check = true;
	ifstream read("E:\\salman\\file4.txt");
	ofstream write("E:\\salman\\Temp.txt");

	cout << "\n\n";
	cout << "\t\t\t<========MODIFY FIR RECORD=========>\n\n";
	cout << "\t\t\tEnter FIR ID: ";
	cin.ignore();
	getline(cin, idNo);
	cout << endl;

	while (getline(read, f.id)) {
		getline(read, f.name);
		getline(read, f.criminalId);
		getline(read, f.crime);
		getline(read, f.date);
		getline(read, f.status);

		if (f.id == idNo) {
			cout << "\t\t\tChange Complainant Name: ";
			getline(cin, f.name);
			cout << "\t\t\tChange Criminal ID: ";
			getline(cin, f.criminalId);
			cout << "\t\t\tChange Crime: ";
			getline(cin, f.crime);
			cout << "\t\t\tChange Date: ";
			getline(cin, f.date);
			cout << "\t\t\tChange Status: ";
			getline(cin, f.status);
			cout << endl;

			check = false;
		}

		write << f.id << endl;
		write << f.name << endl;
		write << f.criminalId << endl;
		write << f.crime << endl;
		write << f.date << endl;
		write << f.status << endl;
	}

	if (check) {
		cout << "\t\t\t\tNO RECORD FOUND...." << endl;
		cout << endl;
	}
	else {
		cout << "\t\t\tFILE IS UPDATED SUCCESSFULLY" << endl;
		cout << endl;
	}

	cout << "Press Any Key To Continue...";
	cin.ignore();
	cin.get();
	read.close();
	write.close();
	remove("E:\\salman\\file4.txt");
	rename("E:\\salman\\Temp.txt", "E:\\salman\\file4.txt");
}

void deleteFIRRecord() {
	string idNo;
	bool check = true;
	ifstream read("E:\\salman\\file4.txt");
	ofstream write("E:\\salman\\Temp.txt");

	cout << "\n\n";
	cout << "\t\t\t<========DELETE FIR RECORD=========>\n\n";
	cout << "\t\t\tEnter FIR ID: ";
	cin.ignore();
	getline(cin, idNo);
	cout << endl;

	while (getline(read, f.id)) {
		getline(read, f.name);
		getline(read, f.criminalId);
		getline(read, f.crime);
		getline(read, f.date);
		getline(read, f.status);

		if (f.id == idNo) {
			continue;
		}
		else {
			check = false;
			write << f.id << endl;
			write << f.name << endl;
			write << f.criminalId << endl;
			write << f.crime << endl;
			write << f.date << endl;
			write << f.status << endl;
		}
	}

	if (check) {
		cout << "\t\t\tRECORD NOT FOUND...." << endl;
		cout << endl;
	}
	else {
		cout << "\t\t\t\tRECORD DELETED SUCCESSFULLY";
		cout << endl;
	}

	cout << "Press Any Key To Continue...";
	cin.ignore();
	cin.get();
	read.close();
	write.close();
	remove("E:\\salman\\file4.txt");
	rename("E:\\salman\\temp.txt", "E:\\salman\\file4.txt");
}


void mainmenu(){
	    int choice;
    while (true) {
        system("cls");
        cout << "\t\t\t<============================================================>" << endl << endl;
        cout << "\t\t\t:\"IN THE NAME OF ALLAH THE MOST GRACIOUS AND THE MOST MERCIFUL:\"" << endl;
        cout << "\n\t\t\t<===========================================================>" << endl << endl;
        cout << "\n\n\n\t\t\t<=======POLICE STATION MANAGEMENT SYSTEM=========>\n\n\n";
        cout << "\t\t\t<========1. STAFF RECORD=========>\n";
        cout << "\t\t\t<========2. FIR RECORD=========>\n";
        cout << "\t\t\t<========3. CRIMINAL RECORD=========>\n";
        cout << "\t\t\t<========4. EXIT=========>\n";
        cout << "\t\t\tEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            system("cls");
            int ch1;
            while (true) {
                cout << "\n\n";
                cout << "\t\t\t<========STAFF RECORD=========>\n\n";
                cout << "\t\t\t<========1. ADD RECORD=========>\n";
                cout << "\t\t\t<========2. VIEW RECORD=========>\n";
                cout << "\t\t\t<========3. MODIFY RECORD=========>\n";
                cout << "\t\t\t<========4. DELETE RECORD=========>\n";
                cout << "\t\t\t<========5. BACK=========>\n";
                cout << "\t\t\tEnter Your Choice: ";
                cin >> ch1;

                switch (ch1) {
                case 1:
                    system("cls");
                    addStaffRecord();
                    break;
                case 2:
                    system("cls");
                    viewStaffRecord();
                    break;
                case 3:
                    system("cls");
                    modifyStaffRecord();
                    break;
                case 4:
                    system("cls");
                    deleteStaffRecord();
                    break;
                case 5:
                    system("cls");
                    break;
                default:
                    system("cls");
                    cout << "\n\n\t\t\t\t<========INVALID CHOICE=========>\n\n";
                    cout << "\t\t\t\tPress Any Key To Continue...";
                    cin.ignore();
                    cin.get();
                    system("cls");
                }

                if (ch1 == 5)
                    break;
            }
            break;
        }
        case 2: {
            system("cls");
            int ch2;
            while (true) {
                cout << "\n\n";
                cout << "\t\t\t<========FIR RECORD=========>\n\n";
                cout << "\t\t\t<========1. ADD RECORD=========>\n";
                cout << "\t\t\t<========2. VIEW RECORD=========>\n";
                cout << "\t\t\t<========3. MODIFY RECORD=========>\n";
                cout << "\t\t\t<========4. DELETE RECORD=========>\n";
                cout << "\t\t\t<========5. BACK=========>\n";
                cout << "\t\t\tEnter Your Choice: ";
                cin >> ch2;

                switch (ch2) {
                case 1:
                    system("cls");
                    addFIRRecord();
                    break;
                case 2:
                    system("cls");
                    viewFIRRecord();
                    break;
                case 3:
                    system("cls");
                    modifyFIRRecord();
                    break;
                case 4:
                    system("cls");
                    deleteFIRRecord();
                    break;
                case 5:
                    system("cls");
                    break;
                default:
                    system("cls");
                    cout << "\n\n\t\t\t\t<========INVALID CHOICE=========>\n\n";
                    cout << "\t\t\t\tPress Any Key To Continue...";
                    cin.ignore();
                    cin.get();
                    system("cls");
                }

                if (ch2 == 5)
                    break;
            }
            break;
        }
        case 3: {
            system("cls");
            int ch3;
            while (true) {
                cout << "\n\n";
                cout << "\t\t\t<========CRIMINAL RECORD=========>\n\n";
                cout << "\t\t\t<========1. ADD RECORD=========>\n";
                cout << "\t\t\t<========2. VIEW RECORD=========>\n";
                cout << "\t\t\t<========3. MODIFY RECORD=========>\n";
                cout << "\t\t\t<========4. DELETE RECORD=========>\n";
                cout << "\t\t\t<========5. BACK=========>\n";
                cout << "\t\t\tEnter Your Choice: ";
                cin >> ch3;

                switch (ch3) {
                case 1:
                    system("cls");
                    addCriminalRecord();
                    break;
                case 2:
                    system("cls");
                    displayCriminalRecord();
                    break;
                case 3:
                    system("cls");
                    modifyCriminalRecord();
                    break;
                case 4:
                    system("cls");
                    deleteCriminalRecord();
                    break;
                case 5:
                    system("cls");
                    break;
                default:
                    system("cls");
                    cout << "\n\n\t\t\t\t<========INVALID CHOICE=========>\n\n";
                    cout << "\t\t\t\tPress Any Key To Continue...";
                    cin.ignore();
                    cin.get();
                    system("cls");
                }

                if (ch3 == 5)
                    break;
            }
            break;
        }
        case 4:
            system("cls");
            exit(0);
        default:
            system("cls");
            cout << "\n\n\t\t\t\t<========INVALID CHOICE=========>\n\n";
            cout << "\t\t\t\tPress Any Key To Continue...";
            cin.ignore();
            cin.get();
            system("cls");
        }
    }
}


int main() {
	cout << "\t\t\t<============================================================>" << endl << endl;
    cout << "\t\t\t:\"IN THE NAME OF ALLAH THE MOST GRACIOUS AND THE MOST MERCIFUL:\"" << endl;
    cout << "\n\t\t\t<===========================================================>" << endl << endl;
    cout << "\n\n\n\t\t\t<=======POLICE STATION MANAGEMENT SYSTEM=========>\n\n\n";
	cout << "\t\t\t1.MAINMENU\n\n";
	cout << "\t\t\t2.EXIT\n\n";
	int choice;
	cout<<"\t\t\tEnter Choice:";
	cin>>choice;
	if(choice==1)
	{
	  mainmenu();	
	}
else{
	exit(0);
}
    return 0;
}
