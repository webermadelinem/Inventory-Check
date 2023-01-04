//  Program: Chapter 6
//  Author: Madeline Weber
//  Date: October 2, 2022
//  Description: This program displays the status of an order by calling two functions: the first, to ask for 
//  the user to input data, and the second to receivew any values needed to compute and display the information.

#include <iostream>
#include <iomanip>

using namespace std;

// Prototype of functions
void userData(int &numOrdered, int &numStock, double &specialCharges );
void calculateData(int x, int y, double z);

int main(){
	// Declare variables
	int numOrdered, numStock;
	double specialCharges;
	
	userData( numOrdered, numStock, specialCharges );
	
	calculateData( numOrdered, numStock, specialCharges );
	return 0;
}
//***********************************************************//
//  Function Name: userData
//  Parameters: int &numOrdered, int &numStock, double &specialCharges
//  Returns: none
//  Description: this function receives three reference parameters in order 
//  to get user input. 
//
void userData( int &numOrdered, int &numStock, double &specialCharges ) {
	// Ask user for input data
	cout << "Please enter the numer of spools ordered: \n";
	cin >> numOrdered;

	cout << "Please enter the number of spools there are in stock: ";
	cin >> numStock;
	
	cout << "Please enter any special charges (above the regular $10 rate): \n";
	cin >> specialCharges;
	specialCharges += 10;
}

//***********************************************************//
//  Function Name: calculateData
//  Parameters: int &numOrdered, int &numStock, double &specialCharges
//  Returns: none
//  Description: this function receives three reference parameters in order 
//  to calculate and display the values. It displays the number of ordered spools
//  ready to ship, total shipping and handling charges, number of ordered spools on 
//  backorder, and the total of the order ready to ship. 
//
void calculateData( int numOrdered, int numStock, double specialCharges ){
	// Declare local variables
	int spoolsReady, spoolsBackorder;
	double spoolsPrice, totalShipping, total;
	
	// Compute the number of ordered spools ready to ship from current stock
	if ( numStock < numOrdered )
	{
		spoolsReady = numStock;
		spoolsBackorder = ( numOrdered - numStock ); // Compute the number of ordered spools on backorder
	}	
	else {
		spoolsReady = numOrdered;
		spoolsBackorder = 0;
	}
		
	// Compute the selling price of the portion ready to ship
	spoolsPrice = ( 100 * spoolsReady );
	
	// Compute the total shipping charges
	totalShipping = ( specialCharges * spoolsReady );
	
	// Compute the total of the order ready to ship
	total = ( spoolsPrice + totalShipping );
	
	// Display 
	cout << "The number of spools ready to ship: " << spoolsReady << endl;
	cout << "The number of spools on backorder: " << spoolsBackorder << endl;
	cout << fixed << showpoint;
	cout << setprecision(2);
	cout << "The total selling price of the spools ready to ship: $" << spoolsPrice << endl;
	cout << "The total shipping and handling charges of the spools ready to ship: $" << totalShipping << endl;
	cout << "The total of the order ready to ship: $" << total << endl;
}
