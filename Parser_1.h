#include<fstream>
#include<iostream>
#include "FootballTeam.h"
#include "List.h"
#include "Stack.h"
#include "BST.h"
#include "Queue.h"
#include "Hash.h"
#include<algorithm>

using namespace std;

string filename; //stores filename
LinkedList<FootballTeam> list;
Stack S1;
BST Tree;
Queue Q;
HashMap HT;


//32 size can be changed by either asking the user to input the number of entries in file
//or by keeping a count of records in read function and then initializing the array
float GoalsArr[32];

// The first step we do is reading the data from file. All data read is saved in a linkedlist

void readFileData(ListNode<FootballTeam>* headNode) 
{
    
    int i = 0;
    FootballTeam* FT;
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
    fstream fin;
    cout << "Enter the filename that you want to read ";
    cin.ignore();
    cin >> filename;
    fin.open(filename);
    if (fin.is_open()) {
        cout << "File reading succesful. ";
    }
    else {
        cout << "Error opening file!";
    }
  while( fin >> team )  //write into file name
  {
      //cout << "while loop started";
    fin.ignore();
    fin>>players_used;
    fin.ignore();
    fin>>avg_age;
    fin.ignore();
    fin>>possession;
    fin.ignore();
    fin>>games;
    fin.ignore();
    fin>>minutes;
    fin.ignore();
    fin>>goals;
    GoalsArr[i++] = goals;
    fin.ignore();
    fin>>assists;
    Tree.insert(assists,team);
    fin.ignore();
    fin>>goals_pens;
    fin.ignore();
    fin>>cards_yellow;
   


    if (cards_yellow >= Q.getFront())
    {
        Q.insertAtFront(cards_yellow, team);

    }
    else
    {

        Q.insertAtRear(cards_yellow, team);
    }

    fin.ignore();
    fin>>cards_red;
    fin.ignore();
    fin>>gk_saves;
    HT.Insert(gk_saves, team);
    fin.ignore();
    fin>>gk_clean_sheets;
    fin.ignore();
    fin>>shots;
    fin.ignore();
    fin>>fouled;
    fin.ignore();
    fin>>offsides;
    fin.ignore();
    fin>>pens_won;
    fin.ignore();
    fin>>pens_conceded;
    fin.ignore();
    fin>>own_goals;
    fin.ignore();
    fin>>ball_recoveries;
    fin.ignore();
    fin>>aerials_won;
    fin.ignore();
    fin>>aerials_lost;
    //store data in footballteam object FT
    FT = new FootballTeam(team,players_used, avg_age, possession, games, minutes, goals, assists, goals_pens, cards_yellow, cards_red, gk_saves, gk_clean_sheets, shots, fouled, offsides, pens_won, pens_conceded, own_goals, ball_recoveries, aerials_won, aerials_lost);
    //insert FT to likedlist
    list.insert(*FT); 
    
  }
  //closing the files when all entries are added
	fin.close();
}


void readGoalsDatatoStack() //saves sorted goals data to stack
{   
    std::sort(std::begin(GoalsArr),std::end(GoalsArr));
    //cout << "size" << sizeof(GoalsArr);
    for (int i = 0; i < 32; i++) {
        S1.push(GoalsArr[i]);
    }
   
}



float HighestGoals(Stack S1) {
    
    return S1.stackTop(); //returns last entry of the stack

}
float LowestGoals(Stack S1) {

    return S1.stackBottom(); //returns last entry of the stack

}

void writeToFile(ListNode<FootballTeam>* headNode) //write the linked list to a text file
{
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

    fstream dictFile; //create fstream object for the file
    cout << "Enter the filename to which you want to write the data ";
    cin.ignore();
    cin >> filename;
    dictFile.open(filename, std::ios::app); //create/open a text file in append mode. new information is always added to the end

    ListNode<FootballTeam>* iterator = headNode;

    while (iterator != NULL) { //iterate over the linked list
        team = iterator->data.team;
        players_used = iterator->data.players_used;
        avg_age = iterator->data.avg_age;
        possession = iterator->data.possession;
        games = iterator->data.games;
        minutes = iterator->data.minutes;
        goals = iterator->data.goals;
        assists = iterator->data.assists;
        goals_pens = iterator->data.goals_pens;
        cards_yellow = iterator->data.cards_yellow;
        cards_red = iterator->data.cards_red;
        gk_saves = iterator->data.gk_saves;
        gk_clean_sheets = iterator->data.gk_clean_sheets;
        shots = iterator->data.shots;
        fouled = iterator->data.fouled;
        offsides = iterator->data.offsides;
        pens_won = iterator->data.pens_won;
        pens_conceded = iterator->data.pens_conceded;
        own_goals = iterator->data.own_goals;
        ball_recoveries = iterator->data.ball_recoveries;
        aerials_won = iterator->data.aerials_won;
        aerials_lost = iterator->data.aerials_lost;

        dictFile << team;
        dictFile << " " << players_used;
        dictFile << " " << players_used;
        dictFile << " " << avg_age;
        dictFile << " " << possession;
        dictFile << " " << games;
        dictFile << " " << minutes;
        dictFile << " " << goals;
        dictFile << " " << assists;
        dictFile << " " << goals_pens;
        dictFile << " " << cards_yellow;
        dictFile << " " << cards_red;
        dictFile << " " << gk_saves;
        dictFile << " " << gk_clean_sheets;
        dictFile << " " << shots;
        dictFile << " " << fouled;
        dictFile << " " << offsides;
        dictFile << " " << pens_won;
        dictFile << " " << pens_conceded;
        dictFile << " " << own_goals;
        dictFile << " " << ball_recoveries;
        dictFile << " " << aerials_won;
        dictFile << " " << aerials_lost;
        dictFile << "\n"; //write to data file 
        iterator = iterator->next;   //advance to next node
    }
    dictFile.close();
    cout << "Entries added.";
}

void printRecursion(ListNode<FootballTeam>* headNode)
{

    if (headNode == NULL)
        return;
    cout << headNode->data << endl;

    // A recursive function that iterates till the end of list
    //prints the first element then goes back to the previous function call, prints that element and so on
    printRecursion(headNode->next);

    // After everything else is printed, prfloat head
    
}

ListNode<FootballTeam>* TeamsWithHighestGoals(LinkedList<FootballTeam> list1)
{
    ListNode<FootballTeam>* headNode = list1.start;
    ListNode<FootballTeam>* max = list1.start;
    while (headNode != NULL) {
        if (max->data < headNode->data)
            max = headNode;
        headNode = headNode->next;
    }
    return max;
}
ListNode<FootballTeam>* EvenNumberofPlayers(ListNode<FootballTeam>* start) {


    if (start == NULL) {
        cout << ("Empty list \n");
    }
    ListNode<FootballTeam>* current = start;
    ListNode<FootballTeam>* previous = start;
    if (start == NULL) {
        return start;
    }
    while (current != NULL) {
        //see if the number of players is odd
        if ((current->data.getPlayers()) % 2 != 0) {

            previous->next = current->next; //unlink the current element from the list because its odd
            
        }
        
        else {
            previous = current;
            
        }
        current = current->next;  

    }
    return start;
}

ListNode<FootballTeam>* TeamsWithGreaterFouls(ListNode<FootballTeam>* start) {

    int count = 0;
    int sumofFouls = 0;
    int average;
    ListNode<FootballTeam>* current = start;
    ListNode<FootballTeam>* previous = start;
    if (start == NULL) {
        return 0;
        cout << "Empty list";
    }
    while (current != NULL) {
        count = count + 1;

        sumofFouls = sumofFouls + current->data.fouled;
        current = current->next;

    }
    average = round(sumofFouls / count);
    
    ListNode<FootballTeam>* curr = start;
    ListNode<FootballTeam>* prev = NULL;
    while (curr != NULL) {
        
        if ((curr->data.getfouls()) >average) {

            cout << curr->data.team << ":" << curr->data.fouled << endl;
            prev = curr;
        }

        else {
            prev->next = curr->next; //unlink the current element from the list

        }
        curr = curr->next;

    }
    return start;
}

ListNode<FootballTeam>* TeamsWithHighestMatches(ListNode<FootballTeam>* start) {

    ListNode<FootballTeam>* headNode = start;
    int maxGames = start->data.games;
    while (headNode != NULL) {
        if (maxGames < headNode->data.games)
            maxGames = headNode->data.games;
        headNode = headNode->next;
    }
    if (start == NULL) {
        return 0;
        cout << "Empty list";
    }
    cout << "Following is the list of teams who have played the maximum number of games" << endl;
    ListNode<FootballTeam>* curr = start;
    ListNode<FootballTeam>* prev = start;
    while (curr != NULL) {

        if ((curr->data.games) == maxGames) {

            cout << curr->data.team << ":" << curr->data.games << endl;
            prev = curr;
        }

        else {
            prev->next = curr->next; //unlink the current element from the list

        }
        curr = curr->next;

    }
    return start;
}

ListNode<FootballTeam>* TeamsWithLeastAssists(ListNode<FootballTeam>* start) {

    ListNode<FootballTeam>* headNode = start;
    int minAssists = start->data.assists;
    while (headNode != NULL) {
        if (minAssists > headNode->data.assists)
            minAssists = headNode->data.assists;
        headNode = headNode->next;
    }
    if (start == NULL) {
        return 0;
        cout << "Empty list";
    }
    cout << "Following is the list of teams with least number of assists" << endl;
    ListNode<FootballTeam>* curr = start;
    ListNode<FootballTeam>* prev = start;
    while (curr != NULL) {

        if ((curr->data.assists) == minAssists) {

            cout << curr->data.team << ":" << curr->data.assists << endl;
            prev = curr;
        }

        else {
            prev->next = curr->next; //unlink the current element from the list

        }
        curr = curr->next;

    }
    return start;
}

ListNode<FootballTeam>* TeamsWithAllPenaltyGoals(ListNode<FootballTeam>* start) {

    ListNode<FootballTeam>* headNode = start;
    if (start == NULL) {
        return 0;
        cout << "Empty list";
    }
    cout << "Following is the list of teams whose all goals were penalty goals" << endl;
    ListNode<FootballTeam>* curr = start;
    ListNode<FootballTeam>* prev = start;
    while (curr != NULL) {

        if ((curr->data.goals) == (curr->data.goals_pens)) {

            cout << curr->data.team << ":" << curr->data.goals <<" : "<< curr->data.goals_pens <<endl;
            prev = curr;
        }

        else {
            prev->next = curr->next; //unlink the current element from the list
            

        }
        curr = curr->next;

    }
    return start;
}

ListNode<FootballTeam>* TeamsWithMoreAerialWins(ListNode<FootballTeam>* start) {

    ListNode<FootballTeam>* headNode = start;
    if (start == NULL) {
        return 0;
        cout << "Empty list";
    }
    cout << "Following is the list of teams whose aerial wins are more than aerial loses" << endl;
    ListNode<FootballTeam>* curr = start;
    ListNode<FootballTeam>* prev = start;
    while (curr != NULL) {

        if ((curr->data.aerials_won) > (curr->data.aerials_lost)) {

            cout << curr->data.team << ":" << curr->data.aerials_won << " : " << curr->data.aerials_lost << endl;
            prev = curr;
        }

        else {
            prev->next = curr->next; //unlink the current element from the list

        }
        curr = curr->next;

    }
    return start;
}
int AverageYellowCards(ListNode<FootballTeam>* start) {


    if (start == NULL) {
        cout << ("Empty list \n");
    }
    ListNode<FootballTeam>* current = start;
    ListNode<FootballTeam>* previous = start;
    int count = 0;
    int sumofYellowCards = 0;
    int average;
    if (start == NULL) {
        return 0;
    }
    while (current != NULL) {
        count = count + 1;
        
        sumofYellowCards = sumofYellowCards + current->data.cards_yellow;
        current = current->next;

    }
    average = round( sumofYellowCards / count);
    return average;
}



   
void mainMenu() //menu function
{
  
  char choice='1';  //stores user choice for the actions

  cout << "Input 's' to terminate the program anytime." << endl;
  while (choice != 's') //while loop until 's' is entered
  {
    cout << "\nPlease select an action: " << endl << endl;
    cout << "\ta. Read file data and store data in linkedlist" << endl;
    cout << "\tb. To print elements stored in linked list" << endl;
    cout << "\tc. To return first team in list which got highest number of goals" << endl;
    cout << "\td. To write team details with even number of players to a file" << endl;
    cout << "\te. To get average number of yellow cards given to the teams" << endl;
    cout << "\tf. To get teams with fouls greater than the average number of fouls. "<<endl<<"\tTeam names and number of fouls will be printed on screens as well as be written to a text file." << endl;
    cout << "\tg. To get teams with highest number of matches played" << endl;
    cout << "\th. To get teams with least number of assists" << endl;
    cout << "\ti. To get teams whose all goals were penalty goals" << endl;
    cout << "\tj. To get teams with aerial wins greater than aerial losses" << endl;
    cout << "\tk. To get highest and lowest number of goals in the fifa dataset" << endl;
    cout << "\tl. To get all assists in the fifa dataset in ascending order" << endl;
    cout << "\tx. To get the teams with the most yellow cards" << endl;
    cout << "\tt. Enter the no. of Goal Keeper saves and I will tell you the team" << endl;



    cout << "\x1b[0m"; cin >> choice; cout << endl;
    switch(choice)  //switch statement to check user input and calling respective functions
    {
      case('a'):
      {
        readFileData( list.start);
        readGoalsDatatoStack();//calling this function to sort goals data and save to stack
      }; break;
     
      case('b'):
      {
          printRecursion(list.start);
      }; break;
      case('c'):
      {
          ListNode<FootballTeam>* n = TeamsWithHighestGoals(list);
          cout << n->data;
          
      }; break;
      case('d'):
      {
          ListNode<FootballTeam>* nd = EvenNumberofPlayers(list.start);
          writeToFile(nd);
      }; break;
      case('e'):
      {
         cout << "Average Yellow Cards = "<< AverageYellowCards(list.start) <<endl;
          
      }; break;
      case('f'):
      {
          ListNode<FootballTeam>* node1 = TeamsWithGreaterFouls(list.start);
          writeToFile(node1);

      }; break;
      case('g'):
      {
          ListNode<FootballTeam>* node2 = TeamsWithHighestMatches(list.start);
          //node2 can be passed to write function for writing to a file

      }; break;
      case('h'):
      {
          ListNode<FootballTeam>* node3 = TeamsWithLeastAssists(list.start);
          //node3 can be passed to write function for writing to a file

      }; break;
      case('i'):
      {
          ListNode<FootballTeam>* node4 = TeamsWithAllPenaltyGoals(list.start);
          //node4 can be passed to write function for writing to a file

      }; break;
      case('k'):
          //I have used stack that already conatins sorted data. It means that in order to get
          //2nd highest or third highest number of goals, we wont have to sort data again and 
          //again and we can simply pop data from the stack. For example, to get 3rd highest entry
          //I will pop the original stack 3 times


      {   cout << endl << "Highest and Lowest number of goals in the data are: " << endl;
          cout << HighestGoals(S1)<<endl;
          cout << LowestGoals(S1) << endl;
         

      }; break;
      case('j'):
      {
          ListNode<FootballTeam>* node5 = TeamsWithMoreAerialWins(list.start);
          //node6 can be passed to write function for writing to a file

      }; break;
      case('l'):
      {
          cout << "Folowing is the data for assists in ascending order. You can use this to find the mod in the data";
          Tree.inOrder();
      }; break;

      case('x'):
      {
          cout << "Folowing is the team with highest number of yellow cards : ";
          Q.displayFront();
     
      }; break;
      case('t'):
      {   int x;
          cout << "Enter the no. of GoalKeeper saves and I will tell you the team  : ";
          cin >> x;
          cout << "Following is the team with "<<x<< " no.of goalkeeper saves"<<endl;
          cout<<HT.Search(x)<<endl;
          
      }; break;
      case('s'):
      {
          cout << "Program terminated." << endl;
      }; break;
      default:
        cout << "Invalid action selected!" << endl;
    } 
  }
}
