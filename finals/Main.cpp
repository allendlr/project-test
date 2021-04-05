#include <iostream>
#include <string.h>
#include <limits>
#include "VideoList.h"
#include "CustomerParentList.h"
#include "CustomerRentChildList.h"
#include "Implementation.cpp"

using namespace std;

int main()
{
	VideoList video_list_object;
	CustomerParentList customer_parent_list_object;
	CustomerRentChildList customer_rent_child_list_object;
	// variables for the video
	int copies, video_id, customer_id;
	string title, genre, production, file;
	// variables for the customer parent
	string name, address;
	while (true)
	{
		switch (Menu())
		{
		case '1':
			cout << endl << " << Insert a Movie >> " << endl << endl;
			video_list_object.GetVideoData(&title, &genre, &production, &copies, &file);
			video_list_object.NewVideo(title, genre, production, copies, file);
			Prompt();
			break;
		case '2':
			cout << endl << " << Rent a Video >> " << endl << endl;
			cout<<"Enter Video ID: ";
			cin >> video_id;
			cout <<"Enter Customer_ID: ";
			cin >> customer_id;
			if (customer_parent_list_object.CheckCustomerId(customer_id)){
				if(video_list_object.isExist(video_id)){
					customer_rent_child_list_object.RentVideo(video_id, customer_id);
					if (customer_rent_child_list_object.getAddOrSub())
					{
						video_list_object.subCopy(video_id);
						customer_rent_child_list_object.setAddOrSub();
					}
				} else {
					cout << "\nVideo Doesn't Exist or No Copies Available";
				}
				
			} else{
				cout << "\nCustomer Doesn't Exist! Please Try Again.";
			}
		
			Prompt();
			break;
		case '3':
			cout << endl << " << Return a Video >> " << endl << endl;
			cout << "Enter Movie ID to Return: ";
			cin >> video_id;
			cout << "Enter Customer ID:";
			cin >> customer_id;
			if (customer_parent_list_object.CheckCustomerId(customer_id)){
				if (video_list_object.isExist(video_id)){
					customer_rent_child_list_object.ReturnVideo(video_id, customer_id);
					if (customer_rent_child_list_object.getAddOrSub())
					{
						video_list_object.addCopy(video_id);
						customer_rent_child_list_object.setAddOrSub();
					}
				} else{
					cout << "\nVideo Doesn't Exist!";
				}
			} else{
				cout << "\nCustomer Doesn't Exist! Please Try Again.";
			}
				
			Prompt();
			break;
		case '4':
			cout << endl
				 << " << Show Video Details >> " << endl
				 << endl;
			cout << "Video ID: ";
			cin >> video_id;
			video_list_object.ShowVideoDetails(video_id);
			Prompt();
			break;
		case '5':
			cout << endl
				 << " << All Videos >> " << endl;
			video_list_object.DisplayVideos();
			Prompt();
			break;
		case '6':
			cout << endl
				 << " << Check Video Availability >> " << endl
				 << endl;
			cout << "Video ID: ";
			cin >> video_id;
			video_list_object.CheckAvailability(video_id);
			Prompt();
			break;
		case '7':
			cout << endl
				 << " << Customer Maintenance >> " << endl
				 << endl;
			switch (SubMenu())
			{
			case '1':
				cout << endl << " << Add New Customer >> " << endl<< endl;
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
				cout << "Customer ID: ";
				cin>> customer_id;
				if (customer_parent_list_object.CheckCustomerId(customer_id))
				{
					int *id = customer_rent_child_list_object.DisplayRentList(customer_id);
					int index = customer_rent_child_list_object.GetIndex(customer_id);
					customer_parent_list_object.retrieveCustomerInfo(customer_id);
					if(index > 0)
						video_list_object.retrieveVideos(id, index);
				}
				else
					cout << "\nCustomer Doesn't Exist";

				break;
			default:
				cout << endl
					 << "Invalid Input!" << endl;
				break;
			}
			break;
		case '8':
			cout << endl
				 << "Thank you for using the program!" << endl;
			return 0;
		default:
			cout << endl
				 << "Invalid Input!" << endl;
			Prompt();
			break;
		}
		while (true)
		{
			cin.ignore();
			cout << endl
				 << "User JubiLoop's Video Menu Again? (Y/N): ";
			char choice;
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				system("cls");
				break;
			}
			else if (choice == 'N' || choice == 'n')
			{
				cout << "Exiting..." << endl;
				return 0;
			}
			else
			{
				cout << "Please try again." << endl;
			}
		}
	}
	return 0;
}
