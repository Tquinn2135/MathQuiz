
// Math Quiz
// Tom Quinn

#include <iostream>
#include <conio.h>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//strings to hold a filepath
	string questionsPath = "C:\\tempdeleteme\\Questions.txt";
	string anwsersPath = "C:\\tempdeleteme\\QuizResults.txt";
	//vectors one to store questions from the Questions.txt
	//and one that creates a vector from the users anwsers
	vector<string> questions;
	vector<string> results;

	//strings for each line from the questions vector
	string question;
	string anwser;

	//file that the program reads
	ifstream ifs(questionsPath);

	//loops through ifs file and adds each line to the questions vector 
		while (getline(ifs, question)) {
			questions.push_back(question);
		}
		ifs.close();
		//initilize random number generator
		srand(time(NULL));

		cout << "Welcome to the Math Quiz!" << "\n";
		//loops through the questions vector and randomly grabs 3 elements from it
		for (int i = 0; i < 3; i++)
		{
			//I added size so that the txt file was not limited to 10 elements
			int randomNumber = rand() % questions.size();//10 + 1;
			cout << "\n" << "Question " << i + 1 << "." << "\n" << "\n" <<
				questions[randomNumber]/*the randomNumber is the index tof each element grabbed*/
				<< " = " << "\n" << "Enter your anwser: ";
			cin >> anwser;
			// adds an element based on the question that was selected and the anwser the user inputs into the vector
			results.push_back(questions[randomNumber] + " = " + anwser);					
		}
		//the file that the anwsers vector elements are written
		ofstream ofs(anwsersPath);
		//iterates through the elements vector and saves to the QuizResults.txt 
		for (string& i : results)
		{
			ofs << i << "\n";
		}
		ofs.close();
		//Done!
		cout << "Done!";		

	(void)_getch();
	return 0;
}

