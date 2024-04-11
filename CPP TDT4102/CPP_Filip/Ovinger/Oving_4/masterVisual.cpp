#include "masterVisual.h"
#include "mastermind.h"

void addGuess(MastermindWindow &mwin, const string code, const char startLetter)
{
	// implementer addGuess
}

void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter)
{
	// implementer addFeedback
}

void MastermindWindow::drawCodeHider()
{
	if (code_hidden) {
		draw_rectangle(Point{padX, 3 * padY}, winW - size * padX, padY, Color::black);
	}
}

MastermindWindow::MastermindWindow(int x, int y, int w, int h, int size, const string &title) 
: AnimationWindow(x, y, w, h, title),
guessBtn{{upperLeftCornerBtn.x, upperLeftCornerBtn.y}, btnW, btnH, "Add"},
guess{{upperLeftCornerInBox.x, upperLeftCornerInBox.y}, inBoxW, inBoxH, ""},
size(size)
{
	add(guess);
	add(guessBtn);
	guessBtn.setCallback(std::bind(&MastermindWindow::cb_guess, this));
};

void MastermindWindow::drawGuessesAndFeedbacks()
{
	std::map<int, Color> colorConverter{
		{1, Color::red},
		{2, Color::green},
		{3, Color::yellow},
		{4, Color::blue},
		{5, Color::blue_violet},
		{6, Color::dark_cyan}};

	for (int guessIndex = 0; guessIndex < static_cast<int>(guesses.size()); guessIndex++)
	{
		// Implementer funksjonalitet slik at det vises fargede rektangler i grafikkvinduet
		// Tegn gjettet som ligger på plassen guessIndex i vektoren guesses.
		for (int i = 0; i < size; i++)
		{
			// Tegn rektangler ved bruk av draw_rectangle(). Bruk: colorConverter.at() for å få riktig farge

		}
	}

	for (int feedbackIndex = 0; feedbackIndex < static_cast<int>(feedbacks.size()); feedbackIndex++)
	{
		// Implementer feedback

		for (int i = 0; i < size; i++)
		{
			// Tegn sirkler ved hjelp av draw_circle().

		}
	}
}

string MastermindWindow::wait_for_guess()
{

	while (!button_pressed && !should_close())
	{
		drawGuessesAndFeedbacks();
		// Burde tegnes sist siden den skal ligge på toppen
		drawCodeHider();

		next_frame();
	}
	button_pressed = false;

	string newGuess = guess.getText();
	guess.setText("");

	return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper)
{
	bool validInput = false;
	string guess;
	while (!validInput && !should_close())
	{
		guess.clear();
		string input = wait_for_guess();
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input.at(i);
				if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch))
				{
					guess += toupper(ch);
				}
				else
					break;
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input guess again" << endl;
		}
	}
	return guess;
}

void MastermindWindow::setCodeHidden(bool hidden) {
	code_hidden = hidden;
}


void playMastermindVisual() {

    

    constexpr int size = 4;
    constexpr int letters = 6;
    const string code = randomizeString(size, 'A', ('A' + (letters - 1)));
    cout << code << '\n';

    MastermindWindow mwin{900, 20, winW, winH, size, "Mastermind"};

    int numberOfCorrectCharacters = 0;
    string guess = "????";
    constexpr int max_attempts = 8;
    int attempts = 0;


    while (numberOfCorrectCharacters < size and attempts < max_attempts) {
        cout << "\nGjett koden, som er " << size << " bokstaver lang.\n";
        guess = mwin.getInput(size, 'A', ('A' + (letters - 1)));
        numberOfCorrectCharacters = checkCharactersAndPosition(code, guess);
        cout << "Du gjettet " << (checkCharacters(code, guess)) << " bokstaver riktig, \n";
        cout << numberOfCorrectCharacters << " var paa rett plass." << '\n';
        attempts += 1;
        cout << "Du har " << (max_attempts-attempts) << " forsok igjen.\n";
    }
    if(guess == code) {
        cout << "\nDu gjettet den riktige koden: " << code << endl;
    } else {
        cout << "\nDu tapte! Den riktige koden var: " << code << ". Prov igjen" << endl;
    }
}