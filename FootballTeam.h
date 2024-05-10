#pragma once
#include <string>
using namespace std;

class FootballTeam //Dictionary //definitino of class Dictionary
{
  public:
   // string word; //data member word and meaning
   // string meaning;
    string team;
    float players_used;
    float avg_age;
    float possession;
    float games;
    float minutes;
    float goals;
    float assists;
    float goals_pens;
    float cards_yellow;
    float cards_red;
    float gk_saves;
    float gk_clean_sheets;
    float shots;
    float fouled;
    float offsides;
    float pens_won;
    float pens_conceded;
    float own_goals;
    float ball_recoveries;
    float aerials_won;
    float aerials_lost;


    FootballTeam() //default constructor
    {
      team.push_back('\0');
     

    }

    FootballTeam(string team, float players_used, float avg_age,float	possession,float games,float minutes,float goals, float assists,float	goals_pens,float	cards_yellow,float cards_red,float	gk_saves,float gk_clean_sheets,float shots,float	fouled, float offsides,float pens_won,float pens_conceded,float	own_goals,float ball_recoveries,float aerials_won,float aerials_lost) //parametrized constructor
    {
      this->team = team;
      this->players_used = players_used;
      this->avg_age= avg_age;
      this->possession= possession;
      this->games= games;
      this->minutes=minutes;
      this->goals=goals;
      this->assists=assists;
      this->goals_pens=goals_pens;
      this->cards_yellow=cards_yellow;
      this->cards_red=cards_red;
      this->gk_saves=gk_saves;
      this->gk_clean_sheets=gk_clean_sheets;
      this->shots=shots;
      this->fouled=fouled;
      this->offsides=offsides;
      this->pens_won=pens_won;
      this->pens_conceded=pens_conceded;
      this->own_goals=own_goals;
      this->ball_recoveries=ball_recoveries;
      this->aerials_won=aerials_won;
      this->aerials_lost=aerials_lost;
    }
    FootballTeam(string team, float goals) //parametrized constructor
    {
        this->team = team;
        this->goals = goals;
    }
    FootballTeam(float assists, string team) //parametrized constructor
    {
        this->team = team;
        this->assists = assists;
    }
    bool operator<(FootballTeam FT)
    {
        return goals < FT.goals;
    }

    bool operator>(FootballTeam FT)
    {
        return goals > FT.goals;
    }
    int getPlayers() {
        
        return players_used;
    }
    int getfouls() {

        return fouled;
    }

    // << was overloaded for prfloating and file writing purposes
    friend ostream &operator<<( ostream &output, const FootballTeam& FT)
    {
      output << FT.team << " :: " << FT.players_used<< " :: " << FT.avg_age << " :: " << FT.possession << " :: " << FT.games << " :: " << FT.minutes << " :: " << FT.goals << " :: " << FT.assists << " :: " << FT.goals_pens << " :: " << FT.cards_yellow << " :: " << FT.cards_red << " :: " << FT.gk_saves << " :: " << FT.gk_clean_sheets << " :: " << FT.shots << " :: " << FT.fouled << " :: " << FT.offsides << " :: " << FT.pens_won << " :: " << FT.pens_conceded << " :: " << FT.own_goals << " :: " << FT.ball_recoveries << " :: " << FT.aerials_won << " :: " << FT.aerials_lost<<endl;
      return output;
    };
};