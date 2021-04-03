#include <iostream>
#include <vector>
#include <iomanip>
#include <string.h>
#include <sstream> 
#include <fstream>
#include "VideoList.h"
#include "CustomerParentList.h"
#include "CustomerRentChildList.h"

using namespace std;

// ----------------------------------- VIDEO LIST ------------------------------------------- //

char Menu() {
	cout << " << JubiLoop's Video Menu >> " << endl << endl;
	cout << "[1] New Video" << endl;
	cout << "[2] Rent a Video" << endl;
	cout << "[3] Return a Video" << endl;
	cout << "[4] Show Video Details" << endl;
	cout << "[5] Display all Videos" << endl;
	cout << "[6] Check Video Availability" << endl;
	cout << "[7] Customer Maintenance" << endl;
	cout << setw(5) << (char) 254 << " [1] Add New Customer" << endl;
	cout << setw(5) << (char) 254 << " [2] Show Customer Details" << endl;
	cout << setw(5) << (char) 254 << " [3] List of Videos Rented by a Customer" << endl;
	cout << "[8] Exit Program" << endl << endl;
	cout << "Enter Choice: ";
	char ch;
	cin >> ch;
	return ch;
}

void Prompt() {
	cout << endl << "Press <Enter> to continue... ";
	char temp;
	cin.get(temp);
}

void VideoList::addCopy(int id){
	VideoNode *node_pointer;
	node_pointer = head;
	
	while(node_pointer){
		if(node_pointer -> data.video_id == id){	
			node_pointer -> data.number_of_copies += 1;
			cout<<node_pointer -> data.number_of_copies;
			cout << node_pointer->data.video_id;
			break;
		}else{
			node_pointer = node_pointer -> next;
		}
	}	
}

void VideoList::subCopy(int id){
	VideoNode *node_pointer;
	node_pointer = head;
	while(node_pointer){
		if(node_pointer -> data.video_id == id){
			node_pointer -> data.number_of_copies -= 1;
			cout<<node_pointer -> data.number_of_copies;
			update();
			break;
		}else{
		node_pointer = node_pointer -> next;
		}
	}
}

void GetNumberOfElementsForVideo(int &num) {
	// this is the algorithm for getting the number of elements in the text file
	string temp;
	ifstream data_file("Videos.txt");
	while (getline(data_file, temp)) {
		num++;
	}
	data_file.close();
}

VideoList::VideoList() {
	head = NULL;
	// this is the algorithm for reading data from the text file
	int number_of_elements = 0;
	GetNumberOfElementsForVideo(number_of_elements);
	string *array;
	array = new string[number_of_elements + 1];
	string video_data;
	ifstream data_file("Videos.txt");
	int index = 1;
	while (getline(data_file, video_data)) {
		array[index] = video_data;
		index++;
	}
	for (int i = 1; i <= index; i++) {
		// this part used the concept of 'Modular Arithmetic'
		// for better understanding, 
		// visit this link: https://en.wikipedia.org/wiki/Modular_arithmetic
		if (i % 7 == 0) {
			stringstream convert_id(array[i - 6]);
			convert_id >> id;
			int temp = 0;
			stringstream convert_copies(array[i - 2]);
			convert_copies >> temp;
			NewVideo(array[i - 5], array[i - 4], array[i - 3], temp, array[i - 1]); 
		}
	}
	data_file.close();
}

VideoList::~VideoList() {
	// this is the algorithm for writing data into the text file
	ofstream print("Videos.txt");
	VideoNode *node_pointer;
	if (head == NULL) {
		cout << "The list is empty." << endl;
	} else {
		node_pointer = head;
		while (node_pointer != NULL) {
			print << node_pointer->data.video_id << endl;
			print << node_pointer->data.movie_title << endl;
			print << node_pointer->data.genre << endl;
			print << node_pointer->data.production << endl;
			print << node_pointer->data.number_of_copies << endl;
			print << node_pointer->data.movie_image_filename << endl << endl;
			node_pointer = node_pointer->next;
		}
	}
	print.close();
}

void VideoList::update(){
	ofstream print("Videos.txt");
	VideoNode *node_pointer;
	if (head == NULL)
	{
		cout << "The list is empty." << endl;
	}
	else
	{
		node_pointer = head;
		while (node_pointer != NULL)
		{
			print << node_pointer->data.video_id << endl;
			print << node_pointer->data.movie_title << endl;
			print << node_pointer->data.genre << endl;
			print << node_pointer->data.production << endl;
			print << node_pointer->data.number_of_copies << endl;
			print << node_pointer->data.movie_image_filename << endl
				  << endl;
			node_pointer = node_pointer->next;
		}
	}
	print.close();
}
void VideoList::retrieve(){
	head = NULL;
	// this is the algorithm for reading data from the text file
	int number_of_elements = 0;
	GetNumberOfElementsForVideo(number_of_elements);
	string *array;
	array = new string[number_of_elements + 1];
	string video_data;
	ifstream data_file("Videos.txt");
	int index = 1;
	while (getline(data_file, video_data))
	{
		array[index] = video_data;
		index++;
	}
	for (int i = 1; i <= index; i++)
	{
		// this part used the concept of 'Modular Arithmetic'
		// for better understanding,
		// visit this link: https://en.wikipedia.org/wiki/Modular_arithmetic
		if (i % 7 == 0)
		{
			stringstream convert_id(array[i - 6]);
			convert_id >> id;
			int temp = 0;
			stringstream convert_copies(array[i - 2]);
			convert_copies >> temp;
			NewVideo(array[i - 5], array[i - 4], array[i - 3], temp, array[i - 1]);
		}
	}
	data_file.close();
}
void VideoList::GetVideoData(string *title, string *genre, string *production, int *copies, string *file) {
	// this the algorithm for getting the input from the user
	cin.ignore();
	cout << "Video ID: " << id << endl;
	cout << "Movie Title: ";
	getline(cin, *title);
	cout << "Genre: ";
	getline(cin, *genre);
	cout << "Production: ";
	getline(cin, *production);
	cout << "Number of copies: ";
	cin >> *copies;
	cout << "Movie Image Filename: ";
	cin >> *file;
}

void VideoList::NewVideo(string title, string genre, string production, int copies, string file) {
	// this is the algorithm for adding a new video in the list
	VideoNode *new_node, *node_pointer;
	new_node = new VideoNode();
	new_node->data.video_id = id;
	new_node->data.movie_title = title;
	new_node->data.genre = genre;
	new_node->data.production = production;
	new_node->data.number_of_copies = copies;
	new_node->data.movie_image_filename = file;
	new_node->next = NULL;
	if (!head) {
		head = new_node;
	} else {
		node_pointer = head;
		while (node_pointer->next) {
			node_pointer = node_pointer->next;
		}
		node_pointer->next = new_node;
	}
	// increment the id for every new video added
	id++;
}

void VideoList::ShowVideoDetails(int input_id) {
	// this is the algorithm for finding a video using the input provided by the user
	//retrieve();
	VideoNode *node_pointer;
	bool checker = false;
	if (head == NULL) {
		cout << "The list is empty." << endl;
	} else {
		node_pointer = head;
		while (node_pointer != NULL) {
			if (node_pointer->data.video_id == input_id) {
				cout << "Movie Title: " << node_pointer->data.movie_title << endl;
				cout << "Genre: " << node_pointer->data.genre << endl;
				cout << "Production: " << node_pointer->data.production << endl;
				cout << "Number of Copies: " << node_pointer->data.number_of_copies << endl;
				cout << "Movie Image Filename: " << node_pointer->data.movie_image_filename << endl;
				checker = true;
				break;
			} 
			node_pointer = node_pointer->next;
		}
	}
	if (checker == false) {
		cout << "The video cannot be found." << endl;
	}
}

void VideoList::DisplayVideos() {
	// this is the algorithm for displaying all the videos in the list
	retrieve();
	VideoNode *node_pointer;
	if (head == NULL) {
		cout << "The list is empty!" << endl;
	} else {
		node_pointer = head;
		while (node_pointer) {
			cout << endl << "Video ID: " << node_pointer->data.video_id << endl;
			cout << "Movie Title: " << node_pointer->data.movie_title << endl;
			cout << "Genre: " << node_pointer->data.genre << endl;
			cout << "Production: " << node_pointer->data.production << endl;
			cout << "Number of Copies: " << node_pointer->data.number_of_copies << endl;
			cout << "Movie Image Filename: " << node_pointer->data.movie_image_filename << endl;
			node_pointer = node_pointer->next;
		}
	}
}

// ------------------------------- CUSTOMER PARENT LIST ------------------------------------- //

char SubMenu() {
	cout << "[1] Add New Customer" << endl;
	cout << "[2] Show Customer Details" << endl;
	cout << "[3] List of Videos Rented by a Customer" << endl << endl;
	cout << "Enter Choice: ";
	char ch;
	cin >> ch;
	return ch;
}

void GetNumberOfElementsForCustomer(int &num) {
	// this is the algorithm for getting the number of elements in the text file
	string temp;
	ifstream data_file("Customer.txt");
	while (getline(data_file, temp)) {
		num++;
	}
	data_file.close();
}

CustomerParentList::CustomerParentList(void) {
	front = NULL;
	rear = NULL;
	human_id = 1;
	number_of_items = 0;
	// this is the algorithm for reading data from the text file
	int number_of_elements = 0;
	GetNumberOfElementsForCustomer(number_of_elements);
	string *array;
	array = new string[number_of_elements + 1];
	string customer_data;
	ifstream data_file("Customer.txt");
	int index = 1;
	while (getline(data_file, customer_data)) {
		array[index] = customer_data;
		index++;
	}
	for (int i = 1; i <= index; i++) {
		// this part used the concept of 'Modular Arithmetic'
		// for better understanding, 
		// visit this link: https://en.wikipedia.org/wiki/Modular_arithmetic
		if (i % 4 == 0) {
			stringstream convert_id(array[i - 3]);
			convert_id >> human_id;
			AddCustomer(array[i - 2], array[i - 1]);
			number_of_items++;
		}
	}
	data_file.close();
}

CustomerParentList::~CustomerParentList() {
	// this is the algorithm for writing data into the text file
	ofstream print("Customer.txt");
	CustomerParentNode *holder;
	int counter = 0;
	while (counter < number_of_items && holder != NULL) {
		print << reset->data.customer_id << endl;
		print << reset->data.customer_name << endl;
		print << reset->data.customer_address << endl << endl;
		holder = reset->next;
		reset = holder;
		counter++;
	}
	print.close();
}

void CustomerParentList::GetCustomerData(string *name, string *address) {
	// this the algorithm for getting the input from the user
	cin.ignore();
	cout << "Customer ID: " << human_id << endl;
	cout << "Name: ";
	getline(cin, *name);
	cout << "Address: ";
	getline(cin, *address);
}

void CustomerParentList::AddCustomer(string name, string address) {
	// this the algorithm for adding customers in the queue
	CustomerParentNode *new_node;
	new_node = new CustomerParentNode();
	new_node->data.customer_id = human_id;
	new_node->data.customer_name = name;
	new_node->data.customer_address = address;
	new_node->next = NULL;
	if (IsEmpty()) {
		front = new_node;
		rear = new_node;
		reset = new_node;
	} else {
		rear->next = new_node;
		rear = new_node;
	}
	number_of_items++;
	human_id++;
}

void CustomerParentList::ShowCustomerDetails() {
	// this is the algorithm for displaying customer details
	int person_id = 0;
	string name = "";
	string address = "";
	cout << endl << "Customer ID: ";
	cin >> person_id;
	DisplayCustomers(person_id, name, address);
	if (name != "" && address != "") {
		cout << "Name: " << name << endl;
		cout << "Address: " << address << endl;
	}
}

void CustomerParentList::DisplayCustomers(int person_id, string &name, string &address) {
	// this is the algorithm for searching the customer in the queue (if it exists)
	CustomerParentNode *holder;
	bool checker = false;
	if (IsEmpty()) {
		cout << "The queue is empty." << endl;
	} else {
		int counter = 0;
		while (counter < number_of_items && checker == false && holder != NULL) {
			if (front->data.customer_id == person_id) {
				checker = true;
				name = front->data.customer_name;
				address = front->data.customer_address;
				break;
			}
			holder = front->next;
			front = holder;
			counter++;
		}
		front = reset;
	}
	if (checker == false) {
		cout << "Customer cannot be found." << endl;
	}
}

bool CustomerParentList::IsEmpty() {
	bool status;
	if (number_of_items > 0) {
		status = false;
	} else {
		status = true;
	}
	return status;
}

// ------------------------------- Customer Rent Child LIST ------------------------------------- //

CustomerRentChildList::CustomerRentChildList(){
	ofstream print("Rent.txt");
	RentNode *node_pointer;
	if (head == NULL) {
		cout << "The list is empty." << endl;
	} else {
		node_pointer = head;
		while (node_pointer != NULL) {
			print << node_pointer->data.video_id << endl;
			print << node_pointer->data.customer_id<< endl << endl;
			node_pointer = node_pointer->next;
		}
	}
	print.close();
}

CustomerRentChildList::~CustomerRentChildList() {
	// this is the algorithm for writing data into the text file
	ofstream print("Rent.txt");
	RentNode *node_pointer;
	node_pointer = head;
	
	while (node_pointer != NULL) {
			print << node_pointer->data.video_id << endl;
			print << node_pointer->data.customer_id << endl;
			node_pointer = node_pointer->next;
		}
	print.close();
}



void CustomerRentChildList::DisplayRentList(){
		RentNode *node_pointer;
	if (head == NULL) {
		cout<<"List is Empty!";
	} else {
		node_pointer = head;
		while (node_pointer) {
			cout<<"Video ID: " << node_pointer -> data.video_id<<endl;
			cout<<"Rented by: " <<node_pointer -> data.customer_id<<endl<<endl;;
			node_pointer = node_pointer->next;
		}
	}
}



void CustomerRentChildList::RentVideo(){
	int id, id2;

	cout << "Enter Video ID to rent: ";
	cin >> id;
	cout<< "Enter Customer ID:";
	cin >> id2;

	RentNode *new_node, *node_pointer;
	new_node = new RentNode();
	new_node->data.video_id = id;
	new_node->data.customer_id = id2;
	new_node->next = NULL;
	
	if (!head) {
		head = new_node;
	} else {
		node_pointer = head;
		while (node_pointer ->next != NULL) {
			node_pointer = node_pointer->next;
		}
		node_pointer->next = new_node;
	}
	subCopy(id);
}

void CustomerRentChildList::ReturnVideo(){
	int id, id2;
	bool run = 0;
	
	RentNode *node_pointer = head, *prev_node = NULL;
	
	if(!head){
		cout<<"Nothing was Rented!" << endl;
	}else{
		run = 1;
		cout << "Enter Movie ID to Return: ";
		cin >> id;
		cout<< "Enter Customer ID:";
		cin >> id2;
	}
		
	if(run){
		if (head != NULL && (head->data.video_id == id && head->data.customer_id == id2)) {
			head = node_pointer -> next;
			delete node_pointer;
			addCopy(id);
		} else {
			while (node_pointer != NULL) {
				if(node_pointer -> data.video_id == id && node_pointer -> data.customer_id == id2){				
					prev_node -> next = node_pointer -> next;	
					delete node_pointer;
					addCopy(id);
				}else{
				prev_node = node_pointer;
				node_pointer = node_pointer->next;	
				}	
			}		
		}
	}
}
