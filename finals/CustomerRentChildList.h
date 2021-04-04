#ifndef CUSTOMERRENTCHILDLIST_H
#define CUSTOMERRENTCHILDLIST_H
#include <iostream>
#include "VideoList.h"
#include "CustomerParentList.h"
#pragma once

struct Rent
{
	int video_id;
	int customer_id;
};

class CustomerRentChildList : public CustomerParentList, public VideoList
{
private:
	struct RentNode
	{
		Rent data;
		RentNode *next = NULL;
	};

	int id1, id2;
	RentNode *head = NULL;

public:
	CustomerRentChildList();
	~CustomerRentChildList();
	void RentVideo();
	void DisplayRentList(int id_key);
	void ReturnVideo();
	void RetrieveRent();
	void UpdateRent();
};

#endif