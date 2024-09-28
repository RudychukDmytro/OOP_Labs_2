#include "team.h"
#include <fstream>
#include <cctype> // для роботи з регістром

// Допоміжна функція для порівняння строк без врахування регістру
bool compareStringsIgnoreCase(const std::string &str1, const std::string &str2)
{
    if (str1.size() != str2.size())
        return false;
    for (size_t i = 0; i < str1.size(); ++i)
    {
        if (std::tolower(str1[i]) != std::tolower(str2[i]))
        {
            return false;
        }
    }
    return true;
}

// Реалізація класу FootballPlayer
FootballPlayer::FootballPlayer(std::string n, int num, double sal)
    : name(n), number(num), goals(0), yellowCards(0), salary(sal) {}

std::string FootballPlayer::getName() const
{
    return name;
}

void FootballPlayer::increaseGoals(int g)
{
    goals += g;
}

void FootballPlayer::addYellowCard()
{
    yellowCards++;
}

double FootballPlayer::getSalary() const
{
    return salary;
}

void FootballPlayer::displayStats() const
{
    std::cout << "Player: " << name << ", Number: " << number
              << ", Goals: " << goals << ", Yellow Cards: " << yellowCards << ", Salary: " << salary << std::endl;
}

void FootballPlayer::calculateSalary(int matchesPlayed)
{
    salary += matchesPlayed * 1000;
}

void FootballPlayer::calculateSalary(int matchesPlayed, int goalsScored)
{
    salary += matchesPlayed * 1000 + goalsScored * 500;
}

void FootballPlayer::saveToFile(std::ostream &os) const
{
    os << name << " " << number << " " << goals << " " << yellowCards << " " << salary << std::endl;
}

void FootballPlayer::loadFromFile(std::istream &is)
{
    is >> name >> number >> goals >> yellowCards >> salary;
}

// Реалізація класу FootballTeam
FootballTeam::FootballTeam(std::string name) : teamName(name), wins(0), losses(0), rating(0) {}

std::string FootballTeam::getTeamName() const
{
    return teamName;
}

void FootballTeam::addPlayer(const FootballPlayer &player)
{
    players.push_back(player);
}

void FootballTeam::updateResults(int w, int l)
{
    wins += w;
    losses += l;
    rating = wins * 3 - losses;
}

int FootballTeam::getRating() const
{
    return rating;
}

void FootballTeam::displayTeamInfo() const
{
    std::cout << "Team: " << teamName << ", Wins: " << wins << ", Losses: " << losses << ", Rating: " << rating << std::endl;
}

const FootballPlayer *FootballTeam::findPlayerByName(const std::string &playerName) const
{
    for (const auto &player : players)
    {
        if (compareStringsIgnoreCase(player.getName(), playerName))
        {
            return &player;
        }
    }
    return nullptr;
}

void FootballTeam::saveToFile(std::ostream &os) const
{
    os << teamName << " " << wins << " " << losses << " " << rating << std::endl;
    for (const auto &player : players)
    {
        player.saveToFile(os);
    }
}

void FootballTeam::loadFromFile(std::istream &is)
{
    is >> teamName >> wins >> losses >> rating;
    for (auto &player : players)
    {
        player.loadFromFile(is);
    }
}
