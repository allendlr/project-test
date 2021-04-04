#ifndef VIDEOLIST_H
#define VIDEOLIST_H
#include <iostream>
#pragma once

using namespace std;

struct Video
{
	int video_id;
	string movie_title;
	string genre;
	string production;
	int number_of_copies;
	string movie_image_filename;
};

class VideoList
{
private:
	struct VideoNode
	{
		Video data;
		VideoNode *next;
	};
	int id;
	VideoNode *head;

public:
	VideoList();
	void GetVideoData(string *title, string *genre, string *production, int *copies, string *file);
	void NewVideo(string title, string genre, string production, int copies, string file);
	void ShowVideoDetails(int input_id);
	void CheckAvailability(int input_id);
	void DisplayVideos();
	void retrieveVideos(int id_key);
	void addCopy(int);
	void subCopy(int);
	void update();
	void retrieve();
	~VideoList();
};

#endif