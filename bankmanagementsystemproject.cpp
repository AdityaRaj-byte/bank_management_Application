#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<conio.h>
#include<cstdio>
#include<string.h>
#include<cstdlib>
#include<ctime>
using namespace std;
static int p=0;
class bank{
	private:
		string name,address;
		long long account_number;
		char account_type;
		int balance;
	public:
		void open_account();
		void deposite_money();
		void withdraw_money();
		void check_balance();
		void display_account_details();
	}accounts[20];
	void bank::open_account(){
		cout<<"\n\nEnter your full Name: ";
		cin.ignore();
		getline(cin,accounts[p].name);
		cout<<"\nEnter your address: ";
		getline(cin,accounts[p].address);
		cout<<"\nWhat type of account do you want to open: current(c) or saving(s): ";
		cin>>accounts[p].account_type;
		cout<<"\nEnter the balance you want to deposit: ";
		cin.ignore();
		cin>>accounts[p].balance;
		srand(time(0));
		accounts[p].account_number=(10000000000+rand())%100000000000;
		cout<<"\nyour account is created\n";
		cout<<"\nNote carefully, your 11-digits generated account number is: "<<accounts[p].account_number;
		p++;
	}
	void bank::deposite_money(){
		long long user_input;
		bool flag=false;
		int amount;
		cout<<"Enter your 11-digits account_number: ";
		do{
			cin.ignore();
			cin>>user_input;
			for(int i=0;i<p;i++){
			    if(accounts[i].account_number==user_input){
			    	cout<<"Hello, "<<accounts[i].name<<"\nEnter the amount you want to deposit: ";
			    	cin>>amount;
			    	accounts[i].balance+=amount;
			    	cout<<"Your amount is deposited";
				    flag=true;
				    break;
			    }
		    }
			if(!flag) cout<<"Invalid account_number, enter again: /n";
		}while(!flag);
	}
	void bank::withdraw_money(){
		string user_name;
		long long user_account;
		bool flag=false;
		int amount;
		do{
			cin.ignore();
			cout<<"Enter your name: ";
			getline(cin,user_name);
			cout<<"Enter your account number: ";
			cin>>user_account;
			for(int i=0;i<p;i++){
				if(accounts[i].account_number==user_account && accounts[i].name == user_name){
					cout<<"Enter the amount you want to withdraw: ";
					cin>>amount;
					if(accounts[i].balance<amount)
						cout<<"Transcation can't be completed, that much amount is unavailable in your account";
					else{
						accounts[i].balance-=amount;
						cout<<"Transcation completed successfully";
					}
					flag=true;
					break;
				}
				if(!flag) cout<<"Invalid account number or name,try again: /n";
			}
		}while(!flag);
	}
	void bank::check_balance(){
		string user_name;
		long long user_account;
		bool flag=false;
		do{
			cin.ignore();
			cout<<"Enter your name: ";
			getline(cin,user_name);
			cout<<"Enter your account number: ";
			cin>>user_account;
			for(int i=0;i<p;i++){
				if(accounts[i].account_number==user_account && accounts[i].name == user_name){
					cout<<"your current available balance is: "<<accounts[i].balance;
					flag=true;
					break;
				}
			}
			if(!flag) cout<<"Invalid account number or name,try again: /n";	
		}while(!flag);
	}
	void bank::display_account_details(){
		string user_name;
		long long user_account;
		bool flag=false;
		do{
			cin.ignore();
			cout<<"Enter your name: ";
			getline(cin,user_name);
			cout<<"Enter your account number: ";
			cin>>user_account;
			for(int i=0;i<p;i++){
				if(accounts[i].account_number==user_account && accounts[i].name == user_name){
					cout<<"                         Account details";
					cout<<"\n-----------------------------------------------------------------------------------------------";
					cout<<"\n\n\n";
					cout<<"\nName: "<<accounts[i].name;
					cout<<"\nAccount Number: "<<accounts[i].account_number;
					cout<<"\nAddress: "<<accounts[i].address;
					if(account_type=='c') cout<<"\nAccount type: current";
					if(account_type=='s') cout<<"\nAccount type: saving";
					cout<<"\nbalance: "<<accounts[i].balance;
					flag=true;
					break;
				}
			}
			if(!flag) cout<<"Invalid account number or name,try again: /n";	
		}while(!flag);
	}
int main(){
	system("cls");
	while(1){
		int opt;
		cout<<"\n\n1. open new account\n";
		cout<<"2. deposite money\n";
		cout<<"3. withdraw money\n";
		cout<<"4. check balance\n";
		cout<<"5. display account details\n";
		cout<<"6. exit\n\n";
		cout<<"Select the options, from above: ";
		cin>>opt;
		switch (opt){
			case 1:
				accounts[p].open_account();
				break;
			case 2:
				accounts[0].deposite_money();
				break;
			case 3:
				accounts[0].withdraw_money();
				break;
			case 4:
				accounts[0].check_balance();
				break;
			case 5:
				accounts[0].display_account_details();
				break;
			case 6:
				exit(1);
			default:
				cout<<"Invalid option, please select some other option\n";	 			
		}
	}
	return 0;
};
