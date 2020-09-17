/*
Programmer: Jeremy Ho     Date: 9/8/2017
Section : 1B              Instructor : Patrick Taylor
File: hivemind.cpp
Purpose: Create a 2D array based on user input and calculate
number of robots with "RAD" and how many times to repeat
*/

#include <iostream>

using namespace std;
const int RAD = 2;

int main()
{
	int rounds;
	int hsize;
	int wsize;
	double **data;
	int numIso = 0;
	int numRobot = 0;
	int signal;

	cout << "Number of Rounds: ";
	cin >> rounds;

	for (int i = 0; i < rounds; i++)
		{
			cout << "Height of Array: "; //Array Size User Input
			cin >> hsize;
			cout << "Width of Array: ";
			cin >> wsize;

			data = new double *[hsize]; // Sets up dynamic array
			for (int i=0; i<hsize; i++)
				{
					data[i] = new double [wsize];
				}

			cout << "Data: " << endl;   //Receives user data input
			for (int j=0; j<hsize; j++)
				{
					for (int k=0; k<wsize; k++)
						{
							cin >> data[j][k];
						}
				}

			for (int z=0; z<hsize; z++)  // Detects signal and surroundings
				{                           // for other robots within range
					for (int x=0; x<wsize; x++)
						{
							signal = data[z][x];
							if (signal != 0)
								{
									for (int c=1; c<=signal; c++)
										{
											if (z+c < hsize)
												{
													if(data[z+c][x] != 0)
														{
															numRobot++;
														}
													if (x-c >= 0)
														{
															if(data[z+c][x-c] != 0)
																{
																	numRobot++;
																}
														}
													if (x+c < wsize)
														{
															if(data[z+c][x+c] != 0)
																{
																	numRobot++;
																}
														}
												}

											if (z-c >= 0)
												{
													if(data[z-c][x] != 0)
														{
															numRobot++;
														}
													if (x-c >= 0)
														{
															if(data[z-c][x-c] != 0)
																{
																	numRobot++;
																}
														}
													if (x+c < wsize)
														{
															if(data[z-c][x+c] != 0)
																{
																	numRobot++;
																}
														}
												}


											if (x+c < wsize)
												{
													if(data[z][x+c] != 0)
														{
															numRobot++;
														}
												}

											if (x-c >= 0)
												{
													if(data[z][x-c] != 0)
														{
															numRobot++;
														}
												}
										}
									if (numRobot < RAD)
										{
											numIso++;
										}
									numRobot = 0;
								}
						}
				}

			cout << "Hivemind " << i+1 << " has " << numIso <<
			" isolated members." << endl; //Output Results

			delete data; //Resets results
			numIso = 0;
		}


	return 0;
}
