#include "CustomTime.h"
#include "user.h"
#include "course.h"
#include "Linkedlist.h"

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

Node<Student>*	Create_Schoolyear()
{
	/*
	* This function reads the CSV file containing new classes followed by their student list. The
	* file should be of the below format:
	* 
	* Class, Student ID, First name, Last name, Gender, Date of Birth, Social ID
	* 
	* Sample input:
	* 21APCS1, 21125118, Minh, Bui Vu Bao, 1, 07/07/2003, ABCDEFGH
	*
	* Note: 
	* - Default input file for 1st Year students is "New_Classes.txt"
	*/
	ifstream fin;
	fin.open("New_Classes.txt");
	Node<Student>* Temp = new Node<Student>; // Create a dummy Head for student list
	Node<Student>* cur = Temp;
	string className;
	while (getline(fin, className, ','))
	{
		cur->next = new Node<Student>; // New student read
		cur = cur->next;
		cur->data.Class = className; // Get Class
		fin.ignore(2);
		getline(fin, cur->data.ID, ','); // Get student ID
		fin.ignore(2);
		getline(fin, cur->data.firstName, ','); // Get firstName
		fin.ignore(2);
		getline(fin, cur->data.lastName, ','); // Get lastName
		fin.ignore(2);
		fin >> cur->data.gender;// Get gender
		fin.ignore(2);
		getline(fin, cur->data.SocialID, '\n'); // Get Social ID
		fin.get();
	}
	cur = Temp->next; // Set cur to the Head
	delete Temp; // delete dummy head Node
	return cur;
}