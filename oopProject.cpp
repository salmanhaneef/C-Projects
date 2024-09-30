#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Criminal {
private:
	string name;
	string father;
	int age;
	int batch;
	string id;
	char crime;
	string date;
	string bondage;

public:
	void addRecord();
	void displayRecord();
	void modifyRecord();
	void deleteRecord();
};
void Criminal::addRecord() {
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
	getline(cin, name);
	cout << "\t\t\tEnter Criminal Father Name: ";
	getline(cin, father);
	cout << "\t\t\tEnter Criminal Age: ";
	cin >> age;
	cout << "\t\t\tEnter Criminal Batch Number: ";
	cin >> batch;
	cout << "\t\t\tEnter Criminal id-card Number: ";
	cin.ignore();
	getline(cin, id);
	cout << "\t\t\tEnter Crime Date: ";
	getline(cin, date);
	cout << "\t\t\tEnter Crime: ";
	cin >> crime;
	cout << "\t\t\tEnter Time of Bondage: ";
	cin.ignore();
	getline(cin, bondage);

	write << name << endl;
	write << father << endl;
	write << age << endl;
	write << batch << endl;
	write << id << endl;
	write << date << endl;
	write << crime << endl;
	write << bondage << endl;
	write.close();

	cin.ignore();
	cout << endl;
	cout << "\t\t\t\tTHE RECORD SUCCESSFULLY SAVED" << endl;
	cout << endl;
	cout << "Press Any Key To Continue...";
	cin.ignore();
	cin.get();
}

void Criminal::displayRecord() {
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

	while (read >> name >> father >> age >> batch >> id >> date >> crime >> bondage) {
		cout << "\t\t\tCriminal Name: " << name << endl;
		cout << "\t\t\tCriminal Father Name: " << father << endl;
		cout << "\t\t\tCriminal Age: " << age << endl;
		cout << "\t\t\tCriminal Batch Number: " << batch << endl;
		cout << "\t\t\tCriminal id-card Number: " << id << endl;
		cout << "\t\t\tCrime Date: " << date << endl;
		cout << "\t\t\tCrime: " << crime << endl;
		cout << "\t\t\tTime of Bondage: " << bondage << endl;
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

void Criminal::modifyRecord() 
{
	string idNo;
	bool check = true;
	ifstream read("E:\\salman\\file2.txt");
	ofstream write("E:\\salman\\temp.txt");
	cout << "\n\n";
	cout << "\t\t\t<========MODIFY CRIMAINAL RECORD=========>\n\n";
	cout << "\t\t\tEnter Crimainal ID: ";
	cin.ignore();
	getline(cin, idNo);
	cout << endl;

	while (read >> name >> father >> age >> batch >> id >> date >> crime >> bondage) {
		if (id == idNo) {
			cout << "\n\n";
			cout << "\t\t\t<========MODIFY CRIMINAL RECORD=========>\n\n";
			cout << "\t\t\t\t<=============================>"<< endl << endl;
			cout << "\t\t\tChange Criminal Name: ";
			cin.ignore();
			getline(cin, name);
			cout << "\t\t\tChange Criminal Father Name: ";
			getline(cin, father);
			cout << "\t\t\tChange Criminal Age: ";
			cin >> age;
			cout << "\t\t\tChange Criminal Batch Number: ";
			cin >> batch;
			cout << "\t\t\tChange Criminal id-card Number: ";
			cin.ignore();
			getline(cin, id);
			cout << "\t\t\tChange Crime Date: ";
			getline(cin, date);
			cout << "\t\t\tChange Crime: ";
			cin >> crime;
			cout << "\t\t\tChange Time of Bondage: ";
			cin.ignore();
			getline(cin, bondage);
			cout << "\t\t\t\t<=============================>"<< endl << endl;

			write << name << endl;
			write << father << endl;
			write << age << endl;
			write << batch << endl;
			write << id << endl;
			write << date << endl;
			write << crime << endl;
			write << bondage << endl;

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

void Criminal::deleteRecord() {
	char choice;
	string idNo;
	bool check = true;
	ifstream read("E:\\salman\\file2.txt");
	ofstream write("E:\\salman\\Temp.txt");
	cout << "\n\n";
	cout << "\t\t\t<========MODIFY CRIMIANL RECORD=========>\n\n";
	cout << "\t\t\tEnter Criminal ID: ";
	cin.ignore();
	getline(cin, idNo);
	cout << endl;

	while (read >> name >> father >> age >> batch >> id >> date >> crime >> bondage) {
		if (id == idNo) {
			continue;
		}
		else {
			check = false;
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

class Staff {
private:
	string name;
	string designation;
	int age;
	string id;

public:
	void addRecord();
	void viewRecord();
	void modifyRecord();
	void deleteRecord();
};

void Staff::addRecord() {
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
	getline(cin, name);
	cout << "\t\t\tEnter Staff Designation: ";
	getline(cin, designation);
	cout << "\t\t\tEnter Staff Age: ";
	cin >> age;
	cout << "\t\t\tEnter Staff ID: ";
	cin.ignore();
	getline(cin, id);

	write << name << endl;
	write << designation << endl;
	write << age << endl;
	write << id << endl;

	write.close();
	cin.ignore();
	cout << endl;
	cout << "\t\t\t\tTHE FILE SUCCESSFULLY SAVED" << endl;
	cout << endl;
	cout << "Press Any Key To Continue...";
	cin.ignore();
	cin.get();
}

void Staff::viewRecord() {
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

	while (getline(read, name)) {
		getline(read, designation);
		read >> age;
		read.ignore();
		getline(read, id);

		cout << "\t\t\tStaff Name: " << name << endl;
		cout << "\t\t\tStaff Designation: " << designation << endl;
		cout << "\t\t\tStaff Age: " << age << endl;
		cout << "\t\t\tStaff ID: " << id << endl;
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

void Staff::modifyRecord() {
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

	while (getline(read, name)) {
		getline(read, designation);
		read >> age;
		read.ignore();
		getline(read, id);

		if (id == idNo) {
			cout << "\t\t\tChange Staff Name: ";
			getline(cin, name);
			cout << "\t\t\tChange Staff Designation: ";
			getline(cin, designation);
			cout << "\t\t\tChange Staff Age: ";
			cin >> age;
			cout << endl;

			check = false;
		}

		write << name << endl;
		write << designation << endl;
		write << age << endl;
		write << id << endl;
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

void Staff::deleteRecord() {
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

	while (getline(read, name)) {
		getline(read, designation);
		read >> age;
		read.ignore();
		getline(read, id);

		if (id == idNo) {
			continue;
		}
		else {
			check = false;
			write << name << endl;
			write << designation << endl;
			write << age << endl;
			write << id << endl;
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
class FIR {
private:
	string id;
	string name;
	string criminalId;
	string crime;
	string date;
	string status;

public:
	void addRecord();
	void viewRecord();
	void modifyRecord();
	void deleteRecord();
};

void FIR::addRecord() {
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
	getline(cin, id);
	cout << "\t\t\tEnter Complainant Name: ";
	getline(cin, name);
	cout << "\t\t\tEnter Criminal ID: ";
	getline(cin, criminalId);
	cout << "\t\t\tEnter Crime: ";
	getline(cin, crime);
	cout << "\t\t\tEnter Date: ";
	getline(cin, date);
	cout << "\t\t\tEnter Status: ";
	getline(cin, status);

	write << id << endl;
	write << name << endl;
	write << criminalId << endl;
	write << crime << endl;
	write << date << endl;
	write << status << endl;

	write.close();
	cin.ignore();
	cout << endl;
	cout << "\t\t\t\tTHE FILE SUCCESSFULLY SAVED" << endl;
	cout << endl;
	cout << "Press Any Key To Continue...";
	cin.ignore();
	cin.get();
}

void FIR::viewRecord() {
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

	while (getline(read, id)) {
		getline(read, name);
		getline(read, criminalId);
		getline(read, crime);
		getline(read, date);
		getline(read, status);

		cout << "\t\t\tFIR ID: " << id << endl;
		cout << "\t\t\tComplainant Name: " << name << endl;
		cout << "\t\t\tCriminal ID: " << criminalId << endl;
		cout << "\t\t\tCrime: " << crime << endl;
		cout << "\t\t\tDate: " << date << endl;
		cout << "\t\t\tStatus: " << status << endl;
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

void FIR::modifyRecord() {
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

	while (getline(read, id)) {
		getline(read, name);
		getline(read, criminalId);
		getline(read, crime);
		getline(read, date);
		getline(read, status);

		if (id == idNo) {
			cout << "\t\t\tChange Complainant Name: ";
			getline(cin, name);
			cout << "\t\t\tChange Criminal ID: ";
			getline(cin, criminalId);
			cout << "\t\t\tChange Crime: ";
			getline(cin, crime);
			cout << "\t\t\tChange Date: ";
			getline(cin, date);
			cout << "\t\t\tChange Status: ";
			getline(cin, status);
			cout << endl;

			check = false;
		}

		write << id << endl;
		write << name << endl;
		write << criminalId << endl;
		write << crime << endl;
		write << date << endl;
		write << status << endl;
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

void FIR::deleteRecord() {
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

	while (getline(read, id)) {
		getline(read, name);
		getline(read, criminalId);
		getline(read, crime);
		getline(read, date);
		getline(read, status);

		if (id == idNo) {
			continue;
		}
		else {
			check = false;
			write << id << endl;
			write << name << endl;
			write << criminalId << endl;
			write << crime << endl;
			write << date << endl;
			write << status << endl;
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

int main() {
	int choice;
	while (true) {
		system("cls");
	    cout<<"\t\t\t<============================================================>"<<endl<<endl;
	    cout<<"\t\t\t:\"IN THE NAME OF ALLAH THE MOST GRACIOUS AND THE MOST MERCIFUL:\"";
	    cout<<"\n\t\t\t<===========================================================>"<<endl<<endl;
		cout << "\n\n\n\t\t\t<=======POLICE STATION MANAGEMENT SYSTEM=========>\n\n\n";
		cout << "\t\t\t<========1. STAFF RECORD=========>\n";
		cout << "\t\t\t<========1. FIR RECORD=========>\n";
		cout << "\t\t\t<========2. CRIMINAL RECORD=========>\n";
		cout << "\t\t\t<========3. EXIT=========>\n";
		cout << "\t\t\tEnter Your Choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			system("cls");
			int ch1;
			Staff s;
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
					s.addRecord();
					break;
				case 2:
					system("cls");
					s.viewRecord();
					break;
				case 3:
					system("cls");
					s.modifyRecord();
					break;
				case 4:
					system("cls");
					s.deleteRecord();
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
			int ch3;
			FIR f;
			while (true) {
				cout << "\n\n";
				cout << "\t\t\t<========FIR RECORD=========>\n\n";
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
					f.addRecord();
					break;
				case 2:
					system("cls");
					f.viewRecord();
					break;
				case 3:
					system("cls");
					f.modifyRecord();
					break;
				case 4:
					system("cls");
					f.deleteRecord();
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
		case 3:
			{
			
				system("cls");
			int ch3;
			Criminal c;
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
					c.addRecord();
					break;
				case 2:
					system("cls");
					c.displayRecord();
					break;
				case 3:
					system("cls");
					c.modifyRecord();
					break;
				case 4:
					system("cls");
					c.deleteRecord();
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
	return 0;
}
