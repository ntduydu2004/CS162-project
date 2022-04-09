#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>

#include "..\include\CustomTime.h"
#include "..\include\user.h"
#include "..\include\course.h"
#include "..\include\Linkedlist.h"

using namespace std;

Node<student> *Create_Schoolyear()
{
	/*
	 * This function reads the CSV file containing new classes followed by their student list. The
	 * file should be of the below format:
	 *
	 * Class, Student ID, First name, Last name, Gender, Date of Birth, Social ID
	 *
	 * Sample input:
	 * 21APCS1, 21125118, Bui Vu Bao Minh, m, 07/07/2003, ABCDEFGH
	 *
	 * Note:
	 * - Default input file for 1st Year students is "New_Classes.txt"
	 */
	ifstream fin;
	fin.open("../data/New_Classes.txt");

	Node<student> *Temp = new Node<student>; // Create a dummy Head for student list
	Node<student> *cur = Temp;
	string className;
	while (getline(fin, className, ','))
	{
		// New student read
		cur->next = new Node<student>;
		cur = cur->next;
		// Get Class
		cur->data.Class = className;
		// Get student ID
		fin.get();
		getline(fin, cur->data.ID, ',');
		// Get firstName
		fin.get();
		getline(fin, cur->data.fullname, ',');
		// Get gender
		fin.get();
		fin >> cur->data.gender;
		fin.get();
		fin.get();
		// Get Date of Birth
		string input_date;
		getline(fin, input_date, ',');
		cur->data.getDoB(input_date);
		// Get Social ID
		fin.get();
		getline(fin, cur->data.SocialID, '\n');
	}
	cur = Temp->next; // Set cur to the Head
	delete Temp;	  // delete dummy head Node
	return cur;
}