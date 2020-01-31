//program 2: lomuto partition quicksort for Theory of Algorithms 2018
//by Josiah Manning

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int partition(int &counter, vector<int> &args, int l, int r) {
	int pivot = args[l]; //pivot is first element
	int i = l + 1; //what has been scanned

	cout << "Pass " << counter << ": ";
	counter++;

	for (int m = 0; m < args.size(); m++)
		cout << args[m] << " ";
	cout << endl;

	for (int k = l+1; k <= r; k++) { //scan vector
		if (args[k] < pivot) { //if member is smaller than pivot, swap with rightmost larger than pivot
			swap(args[k], args[i]);
			i++;
		}
	}
	swap(args[i-1], args[l]); //place pivot between smaller and larger members

	return i - 1; //return location of pivot
}

void quickSort(int &counter, vector<int> &args, int l, int r) {
	

	if (l < r) { //no point if improper size
		int pn = partition(counter, args, l, r); //first, initial partition and find pivot

		//recursive calls sort sections on either side of the pivot
		quickSort(counter, args, l, pn - 1); //further partition lower than the pivot
		quickSort(counter, args, pn + 1, r); //further partition higher than the pivot
	}
}

int main() {
	vector<int> args;
	int l, r, pivot, pushnum;
	fstream fin;
	char key;


	cout << "Program 2: Lomuto Partition Quicksort Algorithm" << endl
		<< "For CSCI 400: Theory of Algorithms 2018" << endl
		<< "by Josiah Manning" << endl << endl

		<< "Press any key and return to begin quicksort on lomutodata.txt: ";

	cin >> key;

	fin.open("lomutodata.txt");

	cout << "opening file..." << endl;

	while (fin >> pushnum) {
		args.push_back(pushnum);
	}

	fin.close();
	
	if (args.size() >= 1) {
		int counter = 0;
		l = 0;
		r = args.size()-1;
		quickSort(counter, args, l, r);
	}
	else
		cout << "Empty vector already sorted." << endl;

	cout << endl << endl
		<< "Sorted set: ";
	for (int m = 0; m < args.size(); m++)
		cout << args[m] << " ";

	cout << "Press any key and return to exit: ";
	cin >> key;
	return 0;
	
}