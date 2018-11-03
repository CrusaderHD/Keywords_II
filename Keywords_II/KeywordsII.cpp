//Creator Information
/*
 * Name: Hunter Derrick
 * Professor Name: Tony Hinton
 * Assignment: KeywordsII
 * Class: CSC215 @ UAT
 * Project Start date: 10/29/2018
 * Project Complete date: 11/02/2018
 */
//Task:
/*
 By hand, choose 10 single code words of your choice, make them cool spy words.
Create a new C++ project called Keywords2
Copy and paste the following comments in your main() function. This is the outline of psudeo code you will use to create the structure of this C++ application. 
The indentions in the comments are there for a purpose to help you. Put code under each line of comments. 
Do not put all the comments at the top and have your code start under the last line of comments. 
Add more comments as you code, explaining your code. The more comments you have the higher your score on this assinment will be.
This Code Breaker Training Simulation Program should give the user directions and tell them what it is and how to use it based of the background description above.
You will need to add more of an overview of what this program is and how to use it when the user starts it.
Then your Code Breaker Training Simulation Program should randomly select 3 of the 10 words that are coded in your program.
Unlike the first earlier version of Keywords I, you will not show the scrambled letters to the user.
The user gets no scrambled letters to look at.
The user gets no hints.
Your code breaker will dislplay to the user
You have X# incorrect guesses left and keep track of them.

You've used the following letters:

Now make the user try to solve each one of the three randomly picked coded words from your code list.
After the user trys to solve the 3 randomly picked coded words from your list, you ask if the user would like another simulation. Each simulation solves 3 words.
Each turn you should give your user feedback on if they got the guess correct or not.
After you have a project, publish your code to a new GitHub repository.
 */


#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

//10 Code Words and Meanings
/*

-Alpha - First letter of Military Phonetic Alphabet
-Eagle - Freedom Bird
-Duck - Code Debugger or Pond Swimmer
-Fox - What does it say? Does anyone know?
-Glasses - Tool to assist in eyesight
-Paper - Write on me, draw on me. I don't care. I am a useful tool.
-Window - People look out of me, but don't realize it is what's on the inside that matters.
-Door - I get slammed, I get shut, I get closed. But on some occasions, I get open. What am I?
-Television - You watch me.
-Keyboard - Odds are, you're using me right now. How dare you use me like that.

*/


//Function to greet the user.
void GreetUser()
{
	bool playAgain = false;  //Setting a bool to determine if Player wants to play more than once.
	
	string userName;
	string startGameWord;

	// Display Title of program to user
	//Let's welcome the player to our Game.
	cout << "\t\tWelcome to Word Scramble\n\n";
	cout << "Unscramble the letters and create the word.\n\n";
	cout << "Type the word 'HINT' for a hint.\n\n";
	cout << "You can quit at any time by typing the word 'QUIT'.\n\n";

	// Ask the recruit to login using their name
	cout << "Let's begin with your name shall we: ";
	cin >> userName;
	cout << "Hello, " << userName << endl;

	// Display an overview of what Keywords II is to the recruit 
	cout << "\n" << userName << " KeywordsII is a decoder game. \nYou will be given a word to Decode.\nIt will be your duty as a new recruit to decode the word.\n";
	cout << userName << " are you up for the challenge? Yes or No?" << endl;
	cin >> startGameWord;
	if (startGameWord == "Yes" || startGameWord == "yes")
	{
		cout << "\nGood Choice " << userName << " not like I would have given you one anyway.\n" << endl;
	}
	else
	{
		cout << "\nOops, you didn't type yes. That's fine though you are playing anyway. You're a recruit remember....\n\n";
	}


	// Display an directions to the recruit on how to use Keywords
	cout << "I guess I better tell you how to play." << endl;
	cout << userName << ", the concept is easy. Just re-read what I already told you to do earlier." << endl;
	cout << "Sometimes, I need to repeat this twice...you would be surprised the amount of people who don't read." << endl;
	cout << "\nSo again, I ask..." << endl;
	system("pause");
	cout << userName << " are you up for the challenge? Yes or No?" << endl;
	cin >> startGameWord;
	//Giving the user a chance to start the game....or so they think...
	if (startGameWord == "Yes" || startGameWord == "yes")
	{
		cout << "\nGood Choice " << userName << ", glad to see you are making good life choices...\n\n";
	}
	else
	{
		cout << "\nOops, you haven't learned yet. You don't have a choice. You're a recruit remember....\n\n";
	}

}

//Function for main game play.
void PlayKeywords()
{
	string userName;
	string startGameWord;
	bool playAgain = false;

	//Create a Do_While Loop. This will run the game until player decides they no longer wish to play. Player has to guess all three words 3 times prior to being prompt to play again.
	do
	{
		//For_Loop. This will run through 3 random words. Player guesses 3 words for each game before being asked to play again.
		for (int i = 0; i < 3; ++i)
		{
			bool playAgain = false;

			enum fields { WORDONE, HINTONE, NUM_FIELDS_0 };

			const int NUM_WORDS_0 = 10;  			//State how many words there are in the first iteration.
			const string WORDS_0[NUM_WORDS_0][NUM_FIELDS_0] =
			{
				{"alpha", "First letter of Military Phonetic Alphabet"},
				{"eagle", "Freedom Bird"},
				{"duck","Code Debugger or Pond Swimmer"},
				{"fox","What does it say? Does anyone know?"},
				{"glasses","Tool to assist in eyesight"},
				{"paper","Write on me, draw on me. I don't care. I am a useful tool."},
				{"window","People look out of me, but don't realize it is what's on the inside that matters."},
				{"door","I get slammed, I get shut, I get closed. But on some occasions, I get open. What am I?"},
				{"television","You watch me. "},
				{"keyboard","Odds are, you're using me right now. How dare you use me like that."}
			};
			//Picking a random word from the choices...
			srand(static_cast<unsigned int>(time(0)));
			int choice_0 = (rand() % NUM_WORDS_0);
			string theWord_0 = WORDS_0[choice_0][WORDONE]; //The word to Guess...
			string theHint = WORDS_0[choice_0][HINTONE]; //The hint to the word...
			//Now time to create a jumbled version of chosen word.
			string randWordChoice = theWord_0;
			int length = randWordChoice.size();
			for (int i = 0; i < length; ++i)
			{
				int index0 = (rand() % length);
				int index1 = (rand() % length);
				char temp0 = randWordChoice[index0];
				randWordChoice[index0] = randWordChoice[index1];
				randWordChoice[index1] = temp0;
			}

			//Create another enum for the second batch of words.
			enum { WORDTWO, HINTTWO, NUM_FIELDS_1};

			const int NUM_WORDS_1 = 10;  			//State how many words there are in the first iteration.
			const string WORDS_1[NUM_WORDS_1][NUM_FIELDS_1] =
			{
				{"star", "It shines brightly at night."},
				{"camera", "I take pictures or videos."},
				{"phone", "I can talk, text, record and many other things."},
				{"gold", "My nemesis is silver."},
				{"stairs", "Up, Down? Just walk, I can take you both ways."},
				{"brain", "You should use me when thinking. I am a useful tool."},
				{"desk", "I typically have a computer on top of me."},
				{"fan", "I spin in circles all day and help people be cool."},
				{"controller", "You use me to play most video games."},
				{"ground", "Odds are, you walk on me at least once a day."}
			};

			srand(static_cast<unsigned int>(time(0)));
			int choice_1 = (rand() % NUM_WORDS_1);
			string theWord_1 = WORDS_1[choice_1][WORDTWO];
			string theHint_1 = WORDS_1[choice_1][WORDTWO];

			string randWordChoice_1 = theWord_1;
			int length_1 = randWordChoice_1.size();
			for(int i = 0; i < length_1; ++i)
			{
				int index_2 = (rand() % length_1);
				int index_3 = (rand() % length_1);
				char temp_1 = randWordChoice_1[index_2];
				randWordChoice_1[index_2] = randWordChoice_1[index_3];
				randWordChoice_1[index_3] = temp_1;
			}


			//Create a third enum for the third batch of words.
			enum { WORDTHREE, HINTTHREE, NUM_FIELDS_2 };

			const int NUM_WORDS_2 = 10;  			//State how many words there are in the first iteration.
			const string WORDS_2[NUM_WORDS_2][NUM_FIELDS_2] =
			{
				{"mario", "Its'a me _______. Also  a Nintendo Icon."},
				{"luigi", "Green Brother. Also had a mansion where he hunted ghosts."},
				{"square", "A more evenly sided rectangle."},
				{"pokemon", "Gotta Catch'em all..."},
				{"yoshi", "Always willing to help Mario. Even if it means his own demise."},
				{"dragon", "I breathe hot fire."},
				{"blanket", "When you are cold, you will use me."},
				{"swimming", "I am something you do in a pool."},
				{"vehicle", "Vroom Vroom."},
				{"toilet", "Remember to flush..."}
			};

			srand(static_cast<unsigned int>(time(0)));
			int choice_2 = (rand() % NUM_WORDS_2);
			string theWord_2 = WORDS_2[choice_2][WORDTHREE];
			string theHint_2 = WORDS_2[choice_2][WORDTHREE];

			string randWordChoice_2 = theWord_2;
			int length_2 = randWordChoice_2.size();
			for (int i = 0; i < length_2; ++i)
			{
				int index_4 = (rand() % length_2);
				int index_5 = (rand() % length_2);
				char temp_2 = randWordChoice_2[index_4];
				randWordChoice_2[index_4] = randWordChoice_2[index_5];
				randWordChoice_2[index_5] = temp_2;
			}


			//Show player what the scrambled words are and take in their guesses. .
			cout << "\nWord One: " << randWordChoice;
			string guessOne;
			cout << "\n\nWhat is your first guess " << userName << "? ";
			cin >> guessOne;

			cout << "\nWord Two: " << randWordChoice_1;
			string guessTwo;
			cout << "\nWhat is your second guess " << userName << "? ";
			cin >> guessTwo;

			cout << "\nWord Three: " << randWordChoice_2;
			string guessThree;
			cout << "\nWhat is your third guess " << userName << "? ";
			cin >> guessThree;

			//Entering the Game Loop
			//While_Loop will run as long as the users guess does not equal 'The Word' or quit. Will also allow user to ask for a hint.
			while ((guessOne != theWord_0 || guessTwo != theWord_1 || guessThree !=  theWord_2) && (guessOne != "quit"))
			{
				//If user asks for a hint.
				if (guessOne == "hint")
				{
					cout << "\nThe Hint for word one is: " << theHint;
				}
				else if (guessTwo == "hint")
				{
					cout << "\nThe Hint for word two is: " << theHint_1;
				}
				else if (guessThree == "hint")
				{
					cout << "\nThe Hint for word three is: " << theHint_2;
				}
				else
				{
					cout << "\nSorry, that guess is not correct." << endl;
				}
				//After hint is displayed, ask user to guess.
				cout << "\n\nWhat is your guess: ";
				cin >> guessOne;
			}

			//If the user guesses the word.
			if (guessOne == theWord_0)
			{
				cout << "\nCONGRATULATIONS. You guessed word one correctly.\n" << endl;
			}
			else if (guessOne == "quit" || "Quit")
			{
				cout << "I am sad to see you leave. But I understand. :( " << endl;
				playAgain = false;
				break;
			}

			if (guessTwo == theWord_1)
			{
				cout << "\nCONGRATULATIONS. You guessed word two correctly.\n" << endl;
			}
			else if (guessOne == "quit" || "Quit")
			{
				cout << "I am sad to see you leave. But I understand. :( " << endl;
				playAgain = false;
				break;
			}

			if (guessThree == theWord_2)
			{
				cout << "\nCONGRATULATIONS. You guessed word three correctly.\n" << endl;
			}
			else if (guessOne == "quit" || "Quit")
			{
				cout << "I am sad to see you leave. But I understand. :( " << endl;
				playAgain = false;
				break;
			}

			system("pause");
		}

		char playerChoice;
		cout << "\nWould you like to play again 'y/n':  ";
		cin >> playerChoice;

		if (playerChoice == 'y' || playerChoice == 'Y')
		{
			playAgain = true;
		}
		else
		{
			playAgain = false;
		}
	} while (playAgain);

	cout << "\nThanks for playing. Have a nice day!\n" << endl;
}

int main()
{
	GreetUser();
	PlayKeywords();

	system("pause");
	return 0;
}