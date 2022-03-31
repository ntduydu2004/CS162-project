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

Node<student>*	Create_Schoolyear()
{
	/*
	* This function reads the CSV file containing new classes followed by their student list. The
	* file should be of the below format:
	* 
	* Class, Student ID, First name, Last name, Gender, Date of Birth, Social ID
	* 
	* Sample input:
	* 21APCS1, 21125118, Minh, Bui Vu Bao, m, 07/07/2003, ABCDEFGH
	*
	* Note: 
	* - Default input file for 1st Year students is "New_Classes.txt"
	*/
	ifstream fin;
	fin.open("New_Classes.txt");
	Node<student>* Temp = new Node<student>; // Create a dummy Head for student list
	Node<student>* cur = Temp;
	string className;
	while (getline(fin, className, ','))
	{
		// New student read
		cur->next = new Node<student>; 
		cur = cur->next;
		// Get Class
		cur->data.Class = className; 
		fin.ignore(2);
		// Get student ID
		getline(fin, cur->data.student.ID, ','); 
		fin.ignore(2);
		// Get firstName
		getline(fin, cur->data.student.firstName, ','); 
		fin.ignore(2);
		// Get lastName
		getline(fin, cur->data.student.lastName, ','); 
		fin.ignore(2);
		// Get gender
		fin >> cur->data.student.gender;
		fin.ignore(2);
		// Get Date of Birth
		string input_date;
		getline(fin, input_date, ',');
		cur->data.student.getDoB(input_date);
		// Get Social ID
		getline(fin, cur->data.student.SocialID, '\n');
		fin.get();
	}
	cur = Temp->next; // Set cur to the Head
	delete Temp; // delete dummy head Node
	return cur;
}