#include <conio.h>
#include <iostream.h>
#include <stdlib.h>
#include <string.h>

void login();
void adminmenu();
void usermenu();
void adminproduct();
void searchA();
void searchU();
void userproduct();
void transact();
void reg();

int count = 3;
char admin[10] = "admin";
char adminpass[10] = "1234";
char username[10][50] = {"har","agco","cyrra"};
char password[10][30] = {"0891","0101","1112"};


int pCount = 5;
char pName[20][30] = {"Softdrinks","Junkfoods","Biscuits","Cigarettes","Essentials"};
int pPrice[20] = {18,9,7,50,100};
int pIN[50] = {17,280,150,100,100};
int pOUT[50] = {10,30,75,30,30};

typedef enum
{
false,true
} bool;

int option = 0;

void main(){

	clrscr();
	login();
	getch();

}
//login procedure
void login(){

	clrscr();
	char user[30], pass[30];

	cout<<"STORE INVENTORY\n";
	cout<<"---------------\n";
	cout<<"[1] - Login.\n";
	cout<<"[2] - Exit.\n";
	cout<<"---------------\n";
	cout<<"Option: ";
	cin>>option;

	switch(option){

	case 1:
	cout<<"---------------\n";
	cout<<"Enter Username: ";
	cin>>user;

	if(strcmp(admin,user)==0){

		cout<<"Enter Password: ";
		cin>>pass;

		if(strcmp(pass,adminpass)==0){

			cout<<"----------------------";
			cout<<"\nWelcome Administrator!";
			getch();
			adminmenu();
		}
		else {
				cout<<"\n----------------------";
			cout<<"\nIncorrect Password!";
			getch();
			login();
		}

	}
	for(int x=0; x<count; x++){

		if(strcmp(username[x],user)==0){

			cout<<"Enter Password: ";
			cin>>pass;

			if(strcmp(pass,password[x])==0){

				cout<<"----------------------";
				cout<<"\nWelcome '"<<username[x]<<"'!";
				getch();
				usermenu();
			}
			else {
				cout<<"\nIncorrect Password!";
				getch();
				login();
			}
		}

	}

	break;

	case 2:
	cout<<"\nPress enter to EXIT.";
	getch();
	exit(0);

	default:
	cout<<"\nInvalid.";
	getch();
	login();

	}


}

//administrator overview
void adminmenu(){

	clrscr();

	int pNum = 0, add = 0, remove=0;

	cout<<"Welcome Administrator.\n";
	cout<<"----------------------\n";
	cout<<"[1] - View Inventory.\n";
	cout<<"[2] - Search Product.\n";
	cout<<"[3] - Add Product.\n";
	cout<<"[4] - Modify Product.\n";
	cout<<"[5] - Remove Product.\n";
	cout<<"[6] - Registration.\n";
	cout<<"[7] - Logout.\n";
	cout<<"----------------------\n";
	cout<<"Option: ";
	cin>>option;

	switch(option){

	case 1:
	cout<<"\nPress enter to PROCEED.";
	getch();
	adminproduct();
	break;

	case 2:
	cout<<"\nPress enter to PROCEED.";
	getch();
	searchA();
	break;

	case 3:
	clrscr();
	cout<<"ADD PRODUCT\n";
	cout<<"-----------------------------------\n";
	cout<<"Product: ";
	cin>>pName[pCount];
	cout<<"Price: ";
	cin>>pPrice[pCount];
	cout<<"Stock: ";
	cin>>pIN[pCount];
	cout<<"Out Stock: ";
	cin>>pOUT[pCount];
	cout<<"-----------------------------------\n";
	cout<<"Done adding.";
	pCount++;
	getch();
	adminproduct();
	break;

	case 4:
	clrscr();
	cout<<"MODIFY PRODUCT\n";
	cout<<"---------------------------\n";
	cout<<"Select Product# to Modify: ";
	cin>>pNum;
	cout<<"---------------------------\n";
	cout<<"Select Field to Modidfy\n";
	cout<<"[1] - Name.\n[2] - Price.\n[3] - Add Stock.\n[4] - Remove Stock.\n[5] - Add Remove Stock.\n[6] - Back.\nOption: ";
	cin>>option;
	cout<<"---------------------------\n";
	switch(option){
		case 1:
		cout<<"Enter New Product: ";
		cin>>pName[pNum];
		break;

		case 2:
		cout<<"Enter New Price: ";
		cin>>pPrice[pNum];
		break;

		case 3:
		cout<<"Enter Additional Stock: ";
		cin>>add;
		pIN[pNum]+=add;
		break;

		case 4:
		cout<<"Enter Removed Stock: ";
		cin>>remove;
		pOUT[pNum]-=remove;
		break;

		case 5:
		cout<<"Enter Add Removed Stock: ";
		cin>>remove;
		pOUT[pNum]+=remove;
		pIN[pNum]-=remove;
		break;

		case 6:
		cout<<"\nPress enter to go BACK.";
		getch();
		adminmenu();
		break;

		default:
		cout<<"\nInvalid Input.";
		getch();
		adminmenu();
	}
	cout<<"\nDone modifying.";
	getch();
	adminproduct();
	break;

	case 5:
	clrscr();
	int prod = 0;
	cout<<"REMOVE ITEM\n";
	cout<<"---------------------------\n";
	cout<<"Select Product# to Remove: ";
	cin>>prod;

	cout<<"Type Removed [Product] to procced: ";
	cin>>pName[prod];
	cout<<"Type 0 to procced: ";
	cin>>pPrice[prod];
	pIN[prod] = 0;
	pOUT[prod] = 0;
	cout<<"---------------------------\n";
	cout<<"Done Deleting.";

	getch();
	adminproduct();
	break;

	case 6:
	cout<<"\nPress enter to go PROCEED.";
	getch();
	reg();
	break;

	case 7:
	cout<<"\nPress enter to go PROCEED.";
	getch();
	login();
	break;

	default:
	cout<<"\nInvalid.";
	getch();
	adminmenu();

		}
	}

//displaying products using table for admins
void adminproduct(){

   clrscr();

   int value=0, sales = 0, remaining = 0;

   cout<<"PRODUCTS\n";
   cout<<"----------------------------------------------------------------------\n";
   cout<<"No.\t\tPrice\tIN\tOUT\tValue\tSales\tRemaining\n";

	for(int x=0; x<pCount; x++){
	cout<<"\n";
	cout<<"["<<x<<"]-"<<pName[x]<<"\t";
	cout<<pPrice[x]<<"\t";
	cout<<pIN[x]<<"\t";
	cout<<pOUT[x]<<"\t";
	value = pIN[x]*pPrice[x];
	sales = pOUT[x]*pPrice[x];
	remaining = pIN[x]-pOUT[x];
	cout<<value<<"\t";
	cout<<sales<<"\t";
	cout<<remaining<<"\t";

	if(strcmp(pName[x], "Removed")==1){
		//displaying low count and out stock products.
	   if(remaining <20) {
	 cout<<"\n WARNING: Product: "<<pName[x]<<" is below 20. Please Replenish soon.";
      }
      }
   }

	cout<<"\n----------------------------------------------------------------------\n";
	cout<<"[1] - Search Product.\n";
	cout<<"[2] - Back.\n";
	cout<<"Option: ";
	cin>>option;

	switch(option){

		case 1:
		cout<<"\nPress enter to PROCEED.";
		getch();
		searchA();
		break;

		case 2:
		cout<<"\nPress enter to go BACK.";
		getch();
		adminmenu();
		break;

		default:
		cout<<"\nInvalid.";
		getch();
		adminmenu();

	}


}

//product searching for amdmins
void searchA()
{

	clrscr();
	int s=0;

	cout<<"SEARCH PRODUCT"<<endl;
	cout<<"------------------------------------\n";
	cout<<"[1] - Enter Product [#].\n";
	cout<<"[2] - Back.\n";
	cout<<"------------------------------------\n";
	cout<<"Option: ";
	cin>>option;

	switch(option){

	case 1:
	cout<<"\nEnter Product #: ";
	cin>>s;
	cout<<"\n------------------------------------\n";
	cout<<"No. Product\tPrice\tIN\tOUT\n";
	cout<<"\n["<<s<<"]"<<pName[s]<<"\t";
	cout<<pPrice[s]<<"\t";
	cout<<pIN[s]<<"\t";
	cout<<pOUT[s]<<"\t\n";
	cout<<"------------------------------------\n";
	cout<<"\nPress enter to go BACK.";
	getch();
	searchA();
	break;

	case 2:
	cout<<"\nPress enter to go BACK.";
	getch();
	adminmenu();
	break;

	default:
	cout<<"\nInvalid.";
	getch();
	adminmenu();

	}

}
//searching products for users
void searchU()
{

	clrscr();
	int s=0;

	cout<<"SEARCH PRODUCT"<<endl;
	cout<<"------------------------------------\n";
	cout<<"[1] - Enter Product [#].\n";
	cout<<"[2] - Back.\n";
	cout<<"------------------------------------\n";
	cout<<"Option: ";
	cin>>option;

	switch(option){

	case 1:
	cout<<"\nEnter Product #: ";
	cin>>s;
	cout<<"\n------------------------------------\n";
	cout<<"No. Product\tPrice\tIN\tOUT\n";
	cout<<"\n["<<s<<"]"<<pName[s]<<"\t";
	cout<<pPrice[s]<<"\t";
	cout<<pIN[s]<<"\t";
	cout<<pOUT[s]<<"\t\n";
	cout<<"------------------------------------\n";
	cout<<"\nPress enter to go BACK.";
	getch();
	searchU();
	break;

	case 2:
	cout<<"\nPress enter to go BACK.";
	getch();
	usermenu();
	break;

	default:
	cout<<"\nInvalid.";
	getch();
	usermenu();

	}

}

//transactions(like cashier)
void transact(){
	int productNum, quantity;
    float totalPrice, discount, pay, change;
    bool addAnotherProduct = true;

    clrscr();
    cout<<"Please Select Product\n";
    cout<<"----------------------------------------------------------------------\n";
    cout<<"No.\t\tPrice\tIN\tOUT\tRemaining\n";

    for(int x=0; x<pCount; x++){
	cout<<"\n";
	cout<<"["<<x<<"]-"<<pName[x]<<"\t";
	cout<<pPrice[x]<<"\t";
	cout<<pIN[x]<<"\t";
	cout<<pOUT[x]<<"\t";
	cout<<pIN[x]-pOUT[x]<<"\t";
    }

    while(addAnotherProduct) {
	cout<<"\n\nEnter product# to purchase: ";
	cin>>productNum;
		cout<<"Enter QTY to purchase: ";
	cin>>quantity;
	if (pIN[productNum]-pOUT[productNum]>=quantity) {
	    totalPrice = pPrice[productNum] * quantity;
	    cout<<"Total Price: "<< totalPrice <<endl;
	    cout<<"Apply Discount? (1-Yes / 2-No): ";
	    cin>>discount;
	    //appying 12% of discount if "yes"
	   if (discount == 1) {
		totalPrice = totalPrice - (totalPrice * 0.12);
		cout<<"\nTotal Price after Discount : " <<totalPrice;
	    }
	    do{

		cout<<"\nPlease Enter Amount: ";
		cin>>pay;
		if(pay<totalPrice){
		cout<<"Insufficient Amount."<<endl;

		}
			}while(pay<totalPrice);
			change = pay - totalPrice;
			cout<<"\nYour Change is: "<< change <<endl;
			pIN[productNum]-=quantity;
			pOUT[productNum] += quantity;
			cout<<"\nTransaction Successful!"<<endl;
			getch();
			usermenu();

	} else {
	    cout<<"Not enough stock!"<<endl;
	    getch();
	    clrscr();
	    transact();
	}
    }
   usermenu();

}

//user overeview
void usermenu(){

	clrscr();
	cout<<"Welcome User.\n";
	cout<<"----------------------\n";
	cout<<"[1] - Transact.\n";
	cout<<"[2] - View Inventory.\n";
	cout<<"[3] - Search Product.\n";
	cout<<"[4] - Add Product.\n";
	cout<<"[5] - Remove Stocks.\n";
	cout<<"[6] - Logout.\n";
	cout<<"----------------------\n";
	cout<<"Option: ";
	cin>>option;

	switch(option){

	case 1:
	cout<<"\nPress enter to PROCEED.";
	getch();
	transact();
	break;


	case 2:
	cout<<"\nPress enter to PROCEED.";
	getch();
	userproduct();
	break;

	case 3:
	cout<<"\nPress enter to PROCEED.";
	getch();
	searchU();
	break;

	case 4:
	clrscr();
	cout<<"ADD PRODUCT\n";
	cout<<"-----------------------------------\n";
	cout<<"Product: ";
	cin>>pName[pCount];
	cout<<"Price: ";
	cin>>pPrice[pCount];
	cout<<"Stock: ";
	cin>>pIN[pCount];
	cout<<"Out Stock: ";
	cin>>pOUT[pCount];
	cout<<"-----------------------------------\n";
	cout<<"Done adding.";
	pCount++;
	getch();
	userproduct();
	break;

	case 5:
	clrscr();
	int pNum = 0, remove = 0;
	cout<<"REMOVE STOCKS\n";
	cout<<"---------------------------\n";
	cout<<"Select Product# to Modify: ";
	cin>>pNum;

	cout<<"---------------------------\n";
	cout<<"Select Field to Modidfy\n";
	cout<<"[1] - Remove Stock.\n[2] - Add Remove Stock.\n[3] - Back.\nOption: ";
	cin>>option;
	cout<<"---------------------------\n";
	switch(option){

		case 1:
		cout<<"Enter Removed Stock: ";
		cin>>remove;
		pOUT[pNum]-=remove;
		break;

		case 2:
		cout<<"Enter Add Removed Stock: ";
		cin>>remove;
		pOUT[pNum]+=remove;
		pIN[pNum]-=remove;
		break;

		case 3:
		cout<<"\nPress enter to go BACK.";
		getch();
		usermenu();
		break;

		default:
		cout<<"\nInvalid.";
		getch();
		usermenu();


	}
	cout<<"\nDone modifying.";
	getch();
	userproduct();
	break;

	case 6:
	cout<<"\nPress enter to PROCEED.";
	getch();
	login();
	break;

	default:
	cout<<"\nInvalid.";
	getch();
	usermenu();



	}



}
//viewing products for user only
void userproduct(){

	clrscr();
	int remaining = 0;

	cout<<"PRODUCTS\n";
	cout<<"----------------------------------------------------------------------\n";
	cout<<"No.\t\tPrice\tIN\tOUT\tRemaining\n";

	for(int x=0; x<pCount; x++){
	cout<<"\n";
	cout<<"["<<x<<"]-"<<pName[x]<<"\t";
	cout<<pPrice[x]<<"\t";
	cout<<pIN[x]<<"\t";
	cout<<pOUT[x]<<"\t";
	remaining = pIN[x]-pOUT[x];
	cout<<remaining<<"\t";

	if(strcmp(pName[x], "Removed")==1){
		//displaying low count and out stock products.
	   if(remaining <20) {
	 cout<<"\n WARNING: Product: "<<pName[x]<<" is below 20. Please Replenish soon.";
      }
      }

	}

	cout<<"\n----------------------------------------------------------------------\n";
	cout<<"[1] - Search Product.\n";
	cout<<"[2] - Back.\n";
	cout<<"Option: ";
	cin>>option;

	switch(option){

		case 1:
		cout<<"\nPress enter to PROCEED.";
		getch();
		searchU();
		break;

		case 2:
		cout<<"\nPress enter to go BACK.";
		getch();
		usermenu();
		break;

		default:
		cout<<"\nInvalid.";
		getch();
		usermenu();

	}


}

void reg(){

	clrscr();

	cout<<"EMPLOYEE REGISTRATION\n";
	cout<<"----------------------\n";
	cout<<"Enter username: ";
	cin>>username[count];

	for(int h=0; h<count; h++){

		if(strcmp(username[h],username[count])==0){
		cout<<"Used username.";
		getch();
		reg();

		}
	}


	cout<<"Enter password: ";
	cin>>password[count];

	cout<<"\nRegistration complete!";
	count++;
	getch();
	adminmenu();

}