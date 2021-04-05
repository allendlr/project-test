#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H
#include <iostream>
#include "VideoList.h"
#pragma once

using namespace std;

struct CustomerParent {
	int customer_id;
	string customer_name;
	string customer_address;
};

class CustomerParentList {
	private:
		struct CustomerParentNode {
			CustomerParent data;
			CustomerParentNode *next;
		};
		int human_id;
		CustomerParentNode *front;
		CustomerParentNode *rear;
		CustomerParentNode *reset;
		int number_of_items;
	public:
		CustomerParentList();
		~CustomerParentList();
		void GetCustomerData(string *name, string *address);
		void AddCustomer(string name, string address);
		void ShowCustomerDetails();
		void DisplayCustomers(int person_id, string &name, string &address);
		bool CheckCustomerId(int id_key);
		void retrieveCustomerInfo(int id_key);
		bool IsEmpty();
};

#endif
