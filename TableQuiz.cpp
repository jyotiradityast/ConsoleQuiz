#include<iostream>
#include<ctime>

#define RESET "\033[0m"
#define CYAN "\033[36m"
#define RED "\033[31m"
#define GREEN "\033[32m"

using namespace std;

int diff, x, y, d, ans, response, count_c, count_w, feedback, z, total;
float result;
char choice;

void delay(unsigned int milliseconds) //Delay Function
{
  clock_t start_time = clock();
  while (clock() < start_time + milliseconds);
}

void message(int m) {
  z = (rand() % 4) + 1; //Assigns z with a random value within the range

  if (m == 1) {
    switch (z) {
    case 1:
      cout << "Very Good!";
      break;
    case 2:
      cout << "Excellent!";
      break;
    case 3:
      cout << "Nice Work!";
      break;
    case 4:
      cout << "Keep Up The Good Work!";
      break;
    }
  } else if (m == 0) {
    switch (z) {
    case 1:
      cout << "Please Try Again...";
      break;
    case 2:
      cout << "Try Once More...";
      break;
    case 3:
      cout << "Don't Give Up!...";
      break;
    case 4:
      cout << "Not Yet... Keep Trying...";
      break;
    }
  }
}

void ques(int i) //Function for questions.
{
  x = (rand() % d) + 1;
  y = (rand() % d) + 1;
  ans = x * y;
  do {
    system("clear");
    cout << "\n>>Question " << i << " of 10-----\n\n";
    cout << "How much is " << CYAN << x << RESET << " times " << CYAN << y << "?\n" << RESET;
    cout << "Your Answer: ";
    cin >> response;
    if (response == ans) {

      count_c++;
      cout << endl << GREEN << "You're Correct!" << RESET;
      message(1);
      feedback = 1;
    } else if (response != ans) {
      count_w++;
      cout << endl << RED << "\aWrong Answer..." << RESET;
      message(0);
      feedback = 0;
    }
    cin.get();
    delay(1700000);
  } while (feedback == 0);
}

void start_screen() //Start Screen
{
  cout << RESET << "Welcome\nFor Difficulty Level 1, Enter 1\nFor Difficulty Level 2, Enter 2\n";
  cin >> diff;
  if (diff == 1) {
    d = 9;
  } else if (diff == 2) {
    d = 99;
  } else {
    cout << "\aInvalid Option. Try Again\n";
    delay(1700000);
    system("clear");
    start_screen();
  }
}

void print_report() {
  system("clear");
  total = count_c + count_w;
  result = ((float) count_c / (float) total) * 100;
  cout << "Total Attempts= " << total << endl;
  cout << "Correct Attempts= " << count_c << endl;
  cout << "Your Percentage= " << result << endl;

  if (result < 75) {
    cout << CYAN << "\nNot Yet.";
  } else if (result >= 75) {
    cout << GREEN << "\nCongratulations! You're ready to go to the next level.";
  }
}

int main() {
  do {

    system("clear"); //Necessary Cleanup
    srand(time(0)); //Seeding Random Function
    count_c = 0;
    count_w = 0;
    start_screen();

    for (int i = 1; i <= 10; i++) {
      ques(i);
    }

    print_report();

    cout << "Test Again?(Y/N)\n";
    cin >> choice;
  } while (choice == 'Y' || choice == 'y');
  system("clear");
}
