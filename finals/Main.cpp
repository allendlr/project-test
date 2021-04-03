#include <iostream>
#include <string.h>
#include <limits>
#include "VideoList.h"
#include "CustomerParentList.h"
#include "CustomerRentChildList.h"
#include "Implementation.cpp"

using namespace std;

int main() {
	VideoList video_list_object;
	CustomerParentList customer_parent_list_object;
	CustomerRentChildList customer_rent_child_list_object;
	// variables for the video
	int copies, input_id;
	string title, genre, production, file;
	// variables for the customer parent
	string name, address;
	while (true) {
		switch (Menu()) {
			case '1':
				cout << endl << " << Insert a Movie >> " << endl << endl;
				video_list_object.GetVideoData(&title, &genre, &production, &copies, &file);
				video_list_object.NewVideo(title, genre, production, copies, file);
				Prompt();
				break;
			case '2':
				cout << endl << " << Rent a Video >> " << endl << endl;
				customer_rent_child_list_object.RentVideo();
				Prompt();
				break;
			case '3':
				cout << endl << " << Return a Video >> " << endl << endl;
				customer_rent_child_list_object.ReturnVideo();
				Prompt();
				break;
			case '4':
				cout << endl << " << Show Video Details >> " << endl << endl;
				cout << "Video ID: ";
				cin >> input_id;
				video_list_object.ShowVideoDetails(input_id);
				Prompt();
				break;
			case '5':
				cout << endl << " << All Videos >> " << endl;
				video_list_object.DisplayVideos();
				Prompt();
				break;
			case '6':
				cout << endl << " << Check Video Availability >> " << endl << endl;
				// alaws pa
				cout << "alaws pa" << endl;
				Prompt();
				break;
			case '7':
				cout << endl << " << Customer Maintenance >> " << endl << endl;
				switch (SubMenu()) {
					case '1':
						cout << endl << " << Add New Customer >> " << endl << endl;
						customer_parent_list_object.GetCustomerData(&name, &address);
						customer_parent_list_object.AddCustomer(name, address);
						Prompt();
						break;
					case '2':
						cout << endl << " << Show Customer Details >> " << endl;
						customer_parent_list_object.ShowCustomerDetails();
						Prompt();
						break;
					case '3':
						cout << endl << " << List of Videos Rented by a Customer >> " << endl;
						// alaws pa
						cout << "alaws pa" << endl;
						break;
					default:
						cout << endl << "Invalid Input!" << endl;
						break;
				}
				break;
			case '8':
				cout << endl << "Thank you for using the program!" << endl;
				return 0;
			default:
				cout << endl << "Invalid Input!" << endl;
				Prompt();
				break;
		}
		while (true) {
			cin.ignore();
			cout << endl << "User JubiLoop's Video Menu Again? (Y/N): ";
			char choice;
			cin >> choice;
			if (choice == 'Y' || choice == 'y') {
				system("cls");
				break;
			} else if (choice == 'N' || choice == 'n') {
				cout << "Exiting..." << endl;
				return 0;
			} else {
				cout << "Please try again." << endl;
			}
		}
	}
	return 0;
}
