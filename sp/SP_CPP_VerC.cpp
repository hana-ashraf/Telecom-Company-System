#include <iostream>
#include <string>
using namespace std;
struct date {
	int day;
	int month;
	int year;
	char a;
};
struct line {
	int mobile_number;
	int package_type;
	double balance;
	date start_date;
	date renwal_date;
};
struct user {
	line lines[3];
	int num_of_lines;
	long long ID;
	string e_mail;
	string name;
	string password;
	string address;
	string serial;
}user[100];

int num_of_lines, choice = 0, balance_of_card = 0, balance_transfer, i = 0; bool restart;
long long user_mobile, mobilenumber;

void input_data() {
	cout << " Please Enter your ID:";
	cin >> user[i].ID;
	cout << " Please Enter your e_mail:";
	cin >> user[i].e_mail;
	cout << " Please Enter your name:";
	cin >> user[i].name;
	cout << " Please Enter your password:";
	cin >> user[i].password;
	cout << " Please Enter your address:";
	cin >> user[i].address;
	cout << endl;
	cout << " How many lines do you have ? : ";
	cin >> num_of_lines;
	for (int j = 0; j < num_of_lines; j++) {
		cout << " Enter your mobile number :";
		cin >> user[i].lines->mobile_number;
		cout << " Enter your your package type :";
		cin >> user[i].lines[j].package_type;
		cout << " Enter your your balance :";
		cin >> user[i].lines[j].balance;
		cout << " Enter your start date :";
		while (true) {
			cin >> user[i].lines[j].start_date.day;
			cin >> user[i].lines[j].start_date.a;
			cin >> user[i].lines[j].start_date.month;
			cin >> user[i].lines[j].start_date.a;
			cin >> user[i].lines[j].start_date.year;
			if (1 <= user[i].lines[j].start_date.day && user[i].lines[j].start_date.day <= 31 && 1 <= user[i].lines[j].start_date.month && user[i].lines[j].start_date.month <= 12 && user[i].lines[j].start_date.year == 2020) {
				break;
			}
			else { cout << "your date is wrong please try again: "; }
		}
		cout << " Enter your renwal date :";
		while (true) {
			cin >> user[i].lines[j].renwal_date.day;
			cin >> user[i].lines[j].renwal_date.a;
			cin >> user[i].lines[j].renwal_date.month;
			cin >> user[i].lines[j].start_date.a;
			cin >> user[i].lines[j].renwal_date.year;
			if (1 <= user[i].lines[j].renwal_date.day && user[i].lines[j].renwal_date.day <= 31 && 1 <= user[i].lines[j].renwal_date.month && user[i].lines[j].renwal_date.month <= 12 && user[i].lines[j].renwal_date.year == 2020) {
				break;
			}
			else { cout << "Your date is wrong , please try again :"; }
		}
		cout << endl;
	}
}
void recharge_balance() {
	cout << " How much is the card balance:";
	cin >> balance_of_card;
	cout << " Enter a card serial number :";
	while (true) {
		cin >> user[i].serial;
		if (user[i].serial.size() == 14) {
			cout << " The record uploaded" << endl;
			user[i].lines->balance += balance_of_card;
			cout << "your credit is:" << user[i].lines->balance;
			break;
		}
		else {
			cout << "Re Enter it's not valid" << endl;
		}
	}
}
void renew_subscribtion() {

	cout << "1. renew from your balance " << endl << "2. recharge a card serial number" << endl;
	cout << " Enter your choice: ";
	cin >> choice;
	switch (choice) {
	case 1:
		if (user[i].lines->balance >= user[i].lines->package_type) {
			cout << " Done" << endl;
		}
		else {
			cout << " There is not enough credit" << endl;
			cout << "Do you want recharge a card serial number?" << endl;
			cout << " 1.Yes" << endl << "2.No" << endl;
			cout << "Enter your choice:";
			cin >> choice;
			switch (choice) {
			case 1:
				recharge_balance();
			}
			break;

	case 2:
		cout << " How much is the card balance:";
		cin >> balance_of_card;
		cout << " Enter a card serial number:" << endl;
		recharge_balance();
		cout << endl;
		break;
		}
	}

}
void callormessage() {
	cout << "Enter phone number which you want to call or message : ";
	cin >> user_mobile;
	user[i].lines->balance -= 0.25;
	cout << " your balance is :" << user[i].lines->balance << endl;
}
void transfer() {
	cout << " Enter your phone which you want transfer balance: ";
	cin >> user_mobile;
	cout << endl << " How much balance do you want transfer? :";
	cin >> balance_transfer;
	if (user[i].lines->balance>= balance_transfer) {
		user[i].lines->balance = user[i].lines->balance - balance_transfer;
		cout << "Done" << endl << " your balance is :" << user[i].lines->balance << endl;
		cout << " Your friend balance is :" << balance_transfer << endl;
	}
	else {
		cout << "There is no enough credit" << endl;
	}
}
void Return() {
	char b;
	cout << " Do you want to return to menu?(y/n) : ";
	cin >> b;
	if (b == 'y' || b == 'Y') {
		restart = true;
	}
	else {
		restart = false;
	}
}


int main() {
	for (i = 0; i < 100; i++) {
		input_data();
		cout << endl;

		do {
			cout << " 1. renew your subscribtion" << endl;
			cout << " 2. change your package type" << endl;
			cout << " 3. Make a call or message" << endl;
			cout << " 4. Recharge your balance by entering a card serial number" << endl;
			cout << " 5. transfer balance to another user on the network" << endl;
			cout << " 6. Quite" << endl;
			cout << " Enter your choice :";
			cin >> choice;

			switch (choice) {
			case 1:
				renew_subscribtion();
				Return();
				break;
			case 2:
				cout << "Enter your mobile number:";
				while (true) {
					cin >> mobilenumber;
					if (mobilenumber == user[i].lines->mobile_number) {
						break;
					}
					else {
						cout << "The mobile number is wrong please try again :";
					}
				}
				cout << endl << "Choose your suiatable package type" << endl;
				cout << "1.Hekaya 15 pounds" << endl << "2.Hekaya 30 pounds" << endl << "3.Hekaya 50 pounds" << endl << "4.Hekaya 100 pounds" << endl;
				cout << " Enter your choice : ";
				cin >> choice;
				cout << endl;
				switch (choice) {
				case 1:
					if (user[i].lines->balance >= 15) {
						user[i].lines->balance -= 15;
						cout << "your credit is :" << user[i].lines->balance << endl;
					}
					else { cout << " There is not enough credit" << endl; }

					break;
				case 2:
					if (user[i].lines->balance >= 30) {
						user[i].lines->balance -= 30;
						cout << "your credit is :" << user[i].lines->balance << endl;
					}
					else { cout << " There is not enough credit" << endl; }
					break;
				case 3:
					if (user[i].lines->balance >= 50) {
						user[i].lines->balance -= 50;
						cout << "your credit is :" << user[i].lines->balance << endl;
					}
					else { cout << " There is not enough credit" << endl; }
					break;
				case 4:
					if (user[i].lines->balance >= 100) {
						user[i].lines->balance -= 100;
						cout << "your credit is :" << user[i].lines->balance << endl;
					}
					else { cout << " There is not enough credit" << endl; }
					break;
				}
				Return();
				break;
			case 3:
				callormessage();
				Return();
				break;

			case 4:
				recharge_balance();
				cout << endl;
				Return();
				break;

			case 5:
				transfer();
				Return();
				break;
			case 6:
				return 0;
			}

		} while (restart);
		char b;
		cout << "Is there another user ?";
		cin >> b;
		if (b == 'Y' || b == 'y') {
			continue;
		}
		else {
			cout << "You're Welcome ";
			return 0;
		}
	}
	return 0;
}