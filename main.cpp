#include "team.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // Для заміни пробілів на підкреслення

// Допоміжна функція для заміни пробілів на підкреслення
std::string formatInput(const std::string &input)
{
    std::string formattedInput = input;
    std::replace(formattedInput.begin(), formattedInput.end(), ' ', '_');
    return formattedInput;
}

int main()
{
    // Створюємо 5 команд, по 11 гравців у кожній
    std::vector<FootballTeam> teams;
    teams.push_back(FootballTeam("Team_A"));
    teams.push_back(FootballTeam("Team_B"));
    teams.push_back(FootballTeam("Team_C"));
    teams.push_back(FootballTeam("Team_D"));
    teams.push_back(FootballTeam("Team_E"));

    // Додаємо по 11 гравців у кожну команду
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 1; j <= 11; ++j)
        {
            teams[i].addPlayer(FootballPlayer("Player" + std::to_string(j) + "_Team" + std::to_string(i + 1), j, 5000.0 + j * 100));
        }
    }

    // Оновлюємо результати (наприклад, команда A виграла 3 матчі і програла 1)
    teams[0].updateResults(3, 1);
    teams[1].updateResults(2, 2);
    teams[2].updateResults(1, 3);
    teams[3].updateResults(4, 0);
    teams[4].updateResults(0, 4);

    // Виведення інформації про команди
    for (const auto &team : teams)
    {
        team.displayTeamInfo();
    }

    // Пошук гравця за іменем
    std::string playerName;
    std::cout << "\nEnter player name to search (e.g., Player1 Team1): ";
    std::getline(std::cin, playerName);

    playerName = formatInput(playerName); // Форматування введеного імені

    bool found = false;
    for (const auto &team : teams)
    {
        const FootballPlayer *player = team.findPlayerByName(playerName);
        if (player)
        {
            std::cout << "Found player in team " << team.getTeamName() << ":\n";
            player->displayStats();
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Player not found.\n";
    }

    // Пошук команди за назвою
    std::string teamName;
    std::cout << "\nEnter team name to search (e.g., Team A): ";
    std::getline(std::cin, teamName);

    teamName = formatInput(teamName); // Форматування введеної назви команди

    found = false;
    for (const auto &team : teams)
    {
        if (compareStringsIgnoreCase(team.getTeamName(), teamName))
        {
            std::cout << "Found team:\n";
            team.displayTeamInfo();
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "Team not found.\n";
    }

    // Запис результатів команд у файл
    std::ofstream outFile("results.txt");
    for (const auto &team : teams)
    {
        team.saveToFile(outFile);
    }
    outFile.close();

    std::cout << "Results saved to 'results.txt'.\n";

    return 0;
}
