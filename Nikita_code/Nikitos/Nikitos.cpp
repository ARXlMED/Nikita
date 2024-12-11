#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int intermediate_value = {0};

int getRandomNumber(int i, int min, int max, int old_time_random)
{
    int time_random;
    if (i == 0)
    {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        time_random = 1 + ltm->tm_sec;
        time_random = ((time_random + 354) * 64 - 74) / 8;
    }
    else
    {
        time_random = ((old_time_random + 354) * 64 - 74) / 8 + 34;
    }
    return time_random % 132;
}

void alpha_zapolnenie(char massive_alphabet[])
{
    int counter = 192;
    for (unsigned i{}; i < 132; i++) 
    {
        if (counter == 197) 
        {
            massive_alphabet[i] = counter;
            massive_alphabet[i + 1] = 'Ё';
            i++;
            counter++;
        }
        else if (counter == 223) 
        {
            massive_alphabet[i] = counter;
            counter = 192;
        }
        else 
        {
            massive_alphabet[i] = counter;
            counter++;
        }
    }
}

void game(int amount_players)
{
    char massive_alphabet[132];
    alpha_zapolnenie(massive_alphabet);
    char player_1_chars[10];
    int old_time_random = 0;
    for (int i{}; i < 10; i++)
    {
        intermediate_value = getRandomNumber(i ,0, 132, old_time_random);
        old_time_random = intermediate_value;
        if (massive_alphabet[intermediate_value] != 0)
        {
            player_1_chars[i] = massive_alphabet[intermediate_value];
            massive_alphabet[intermediate_value] = 0;
            cout << i + 1 << " буква в букваре 1 игрока это " << player_1_chars[i] << endl;
        }
        else
        {
            i--;
        }
    }
    if (amount_players >= 2)
    {
        char player_2_chars[10];
        for (int i{}; i < 10; i++)
        {
            intermediate_value = getRandomNumber(i, 0, 132, old_time_random);
            old_time_random = intermediate_value;
            if (massive_alphabet[intermediate_value] != 0)
            {
                player_2_chars[i] = massive_alphabet[intermediate_value];
                massive_alphabet[intermediate_value] = 0;
                cout << i + 1 << " буква в букваре 2 игрока это " << player_2_chars[i] << endl;
            }
            else
            {
                i--;
            }

        }
        if (amount_players >= 3)
        {
            char player_3_chars[10];
            for (int i{}; i < 10; i++)
            {
                intermediate_value = getRandomNumber(i, 0, 132, old_time_random);
                old_time_random = intermediate_value;
                if (massive_alphabet[intermediate_value] != 0)
                {
                    player_3_chars[i] = massive_alphabet[intermediate_value];
                    massive_alphabet[intermediate_value] = 0;
                    cout << i + 1 << " буква в букваре 3 игрока это " << player_3_chars[i] << endl;
                }
                else
                {
                    i--;
                }
            }
            if (amount_players == 4)
            {
                char player_4_chars[10];
                for (int i{}; i < 10; i++)
                {
                    intermediate_value = getRandomNumber(i, 0, 132, old_time_random);
                    old_time_random = intermediate_value;
                    if (massive_alphabet[intermediate_value] != 0)
                    {
                        player_4_chars[i] = massive_alphabet[intermediate_value];
                        massive_alphabet[intermediate_value] = 0;
                        cout << i + 1 << " буква в букваре 4 игрока это " << player_4_chars[i] << endl;
                    }
                    else
                    {
                        i--;
                    }
                }
            }
        }
    }

}

int main()
{
    setlocale(LC_ALL, "RU");
    game(2);

}
