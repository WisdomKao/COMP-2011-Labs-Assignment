#include <iostream>
#include <string.h>
#include "DataStructure.h"
using namespace std;

Bidder *newBidder(const char b_name[BIDDER_NAME_MAX_LENGTH + 1], const int b_artwork_num, const int b_price)
{
	// TODO 7:
	// create a node for a bidder
	Bidder *ptr = new Bidder;

	// set his/her name and the bidding information (the artwork number and bidding price) accordingly
	strcpy(ptr->name, b_name);
	ptr->artwork_num = b_artwork_num;
	ptr->price = b_price;

	// input validation is not needed
	// return the pointer of the new node
	return ptr;
}

void insertBidder(Bidder *b_array[], Bidder *b, const int pos)
{
	// TODO 8:
	// insert the bidder into the array of bidder list
	b_array[pos] = b;
}

void updateBiddingInfo(Bidder *bidder, const int b_artwork_num, const int b_price)
{
	// TODO 9:
	// during each round of auction, you need to update the bidding information (the artwork number and bidding price) of each bidder
	bidder->artwork_num = b_artwork_num;
	bidder->price = b_price;
}

void simulateAuction(Artwork *a_array[], Bidder *b_array[])
{
	// TODO 10:
	// during each round of auction, given the bidding information array of all bidders, you need to update the information winning bidder of each artwork in the artwork inventory
	// a valid bidding deal requires that the bidder's offer price is higher than both the starting price and the highest price provided by previous bidders
	for (int i = 0; i < BIDDER_TOTAL_NUM; i++)
	{
		int artnum = b_array[i]->artwork_num;
		int artprice = a_array[artnum - 1]->l_price;
		if (b_array[i]->price > artprice)
		{
			Bidder *winning_bidder = b_array[i];
			int l_price = b_array[i]->price;
			for (int j = i + 1; j < BIDDER_TOTAL_NUM; j++)
			{
				if (b_array[j]->artwork_num == artnum && b_array[j]->price > l_price)
				{
					winning_bidder = b_array[j];
					l_price = b_array[j]->price;
				}
			}
			a_array[artnum - 1]->winning_bidder = winning_bidder;
			a_array[artnum - 1]->l_price = l_price;
		}
		else if (b_array[i]->price == artprice && a_array[artnum - 1]->winning_bidder == nullptr)
		{
			a_array[artnum - 1]->winning_bidder = b_array[i];
			a_array[artnum - 1]->l_price = b_array[i]->price;
		}
	}
}

void releaseAllMemory(Artwork *a_array[], Bidder *b_array[])
{
	// TODO 11:
	// at the end of whole auction, release all the allocated memory of both artwork inventory and bidders
	// i.e., delete the allocated memory and set the pointer to null
	for (int i = 0; i < ARTWORK_TOTAL_NUM; i++)
	{
		if (a_array[i] != nullptr)
		{
			delete a_array[i];
			a_array[i] = nullptr;
		}
	}
	for (int i = 0; i < BIDDER_TOTAL_NUM; i++)
	{
		if (b_array[i] != nullptr)
		{
			delete b_array[i];
			b_array[i] = nullptr;
		}
	}
}
