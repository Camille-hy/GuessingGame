#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

void main_screen()
{
    std::cout << "\t\t" << "Welcome to the Alpahbet Guessing Game!" << "\t\t\n\n";
    std::cout <<  "You are given 5 chances to guess the correct alphabet! Good Luck! \n"; 
}

void play_game()
{
    char choice;
    do
    {
        char alphabet = 'a' + rand() % 26;
        srand(time(NULL));
        int guess_count = 5;
        std::cout << "Guess the alphabet!: ";
        std::string guess;
        std::getline(std::cin, guess);
        std::cin.clear();
        
        while(true)
        { 
            if(!(guess.size() == 1))
            {
                std::cout << "Invalid Input. Please enter an alphabet: " << std::endl;
                std::getline(std::cin, guess);
            }
            else 
            {
                if((guess[0] <= 'z' && guess[0] >= 'a') || (guess[0] <= 'Z' && guess[0] >= 'A'))
                {
                    guess_count--;
                    if (guess_count == 0 && guess[0] != alphabet)
                    {
                        std::cout << "Sorry, the correct alphabet is " << alphabet << std::endl;
                        break;
                    }
                    else if(guess[0] == alphabet)
                    {
                        std::cout << "You win!" << std::endl;
                        break;
                    }
                    else
                    {
                        std::cout << "Uh oh this is not correct...You have " << guess_count << " chances left.\n";
                        std::cout << "\nGuess the alphabet!: ";
                        std::getline(std::cin, guess);
                    }
                }else 
                {
                    std::cout << "\nInvalid Input. Please enter an alphabet: " << std::endl;
                    std::getline(std::cin, guess);
                }
            }
        }

        while(true)
        {
            std::cout << "Do you want to play again?(y/n): ";
            std::cin >> choice;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            if ((choice != 'y') && (choice != 'Y') && (choice != 'N') && (choice != 'n'))
                {
                    std::cout << "Please enter 'y' or 'n' only. \n";
                    
                }
            else if(choice == 'n' || choice == 'N')
            {
                std::cout << "Thank you for playing. " << std::endl;
                break;
            }
            else
            {
                system("cls");
                break;
            }
        }
    
    }while(choice == 'y' || choice == 'Y');
}

int main()
{
    main_screen();
    char start;
    std::cout << "You ready to play the game?(y/n): ";
    std::cin >> start;
    std::cin.clear();
    std::cin.ignore(1000, '\n');

    while(true)
    {
        if ((start != 'y') && (start != 'Y') && (start != 'N') && (start != 'n'))
        {
            std::cout << "Please enter 'y' or 'n' only. \n";
            std::cin >> start;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        else if(start == 'n' || start == 'N')
        {
            std::cout << "See ya. " << std::endl;
            break;
        }else
        {
            std::cout << "Let's Go!\n";
            play_game();
            break;
        }
    }
    
}