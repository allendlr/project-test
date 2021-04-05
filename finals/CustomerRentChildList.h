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
		RentNode *next;
	};

	int id1, id2;
	bool isRented = false;
	RentNode *head;

public:
	CustomerRentChildList();
	~CustomerRentChildList();
	void RentVideo(int, int);
	int *DisplayRentList(int id_key);
	int GetIndex(int id_key);
	void ReturnVideo(int, int);
	bool getAddOrSub();
	void setAddOrSub();

};

#endif
