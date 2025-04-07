#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<string.h>


void login();
void reg();
char usrnm[100], pass[100];

main(){

	int opt;

	clrscr();

	cout<<"**********MENU**********\n\n";
	cout<<"[1] - Register.\n";
	cout<<"[2] - Login.\n";
	cout<<"Option: ";
	cin>>opt;

	if(opt==1){
	 reg();
	}
	else if(opt==2) {
	 login();
	}else{

	cout<<"Not available.";
	main();

	}

 return 0;

}

void reg(){

	int un, pw, passCV = 0, stop = 0;
	int passCN = 0;
	int stop1 = 0;

	clrscr();

	cout<<"**********REGISTRATION**********\n\n";
	cout<<"Username: ";
	gets(usrnm);
	cout<<"Password: ";
	gets(pass);

	pw = strlen(pass);

	while(pw<=9||pw>=13){

		cout<<"\nPassword must be between 8 and 12 characters long.\n";
		cout<<"Enter a new password: ";
		gets(pass);

		int check1 = strlen(pass);

		if(check1>=8 && check1<12){

			break;

		}

	}

	do{

	int check2 = strlen(pass);

	for(int i=0; i<=check2; i++){

		if(pass[i]=='a'||pass[i]=='e'||pass[i]=='i'||pass[i]=='o'||pass[i]=='u'){

			passCV++;

		}

	}

	if(passCV<2){

		cout<<"\nPassword must have at least two vowels.\n";
		cout<<"Enter a new password: ";
		gets(pass);

		int check11 = strlen(pass);

		while(check11<8||check11>12){

		cout<<"\nPassword must be between 8 and 12 characters long.\n";
		cout<<"Enter a new password: ";
		gets(pass);

		int check12 = strlen(pass);

		if(check12>=8 && check12<=12){

			break;

		}

	}


	}else{

		stop = 1;

	}

	}while(stop==0);

	do{

	int check3 = strlen(pass);

	for(int x = 0; x<=check3; x++){

		if(pass[x]=='1'||pass[x]=='2'||pass[x]=='3'||pass[x]=='4'||pass[x]=='5'||pass[x]=='6'||pass[x]=='7'||pass[x]=='8'||pass[x]=='9'){

			passCN++;

		}

	}

		if(passCN<2){

			cout<<"\nPassword must have at least two numbers.\n";
			cout<<"Enter a new password: ";
			gets(pass);

			int checkL = strlen(pass);

			while(checkL<8||checkL>12){

			cout<<"\nPassword must be between 8 and 12 characters long.\n";
			cout<<"Enter a new password: ";
			gets(pass);

			int check122 = strlen(pass);

			if(check122>=8 && check122<=12){

				break;
		     }
		}





		}else{

			stop1 = 1;

		}

	}while(stop1==0);

	int lastcheck = strlen(pass);

	if(lastcheck>=8 && lastcheck<=12 && passCV>=2 && passCN>=2){

		cout<<"\nAccount Succesfully Registered!\n";
		getch();
		main();

	}



}

void login(){

	clrscr();

	char login_un[100], login_pass[100];
	int attempts = 0, stop2 = 0;

	cout<<"**********LOGIN**********\n\n";

	do{

	cout<<"\nUsername: ";
	gets(login_un);
	cout<<"Password: ";
	gets(login_pass);


	if(strcmp(usrnm,login_un)!=0){

		cout<<"Invalid username!\n";
		attempts++;

	}else if(strcmp(pass,login_pass)!=0){

		cout<<"Invalid password!\n";
		attempts++;

	}else{

		cout<<"\nLogin Successfuly!";
		stop2 = 1;

	}

	if(attempts>=3){

		cout<<"\nMaximum number of attempts exceeded. Program terminated!\n";

		break;


	}


	}while(stop2==0);


    getch();

}