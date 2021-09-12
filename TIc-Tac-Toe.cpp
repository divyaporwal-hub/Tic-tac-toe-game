#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;
 
 char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' ' };
 void show_board();
 void get_x();
 void get_o();
 void get_computer_choice();
 int count_board(char symbol);
 char check_winner();
 void computer_vs_player();
 void player_vs_player();

 int main()
 {
     int mode;
     cout<<"1. COMPUTER VS PLAYER !!!"<<endl;
     cout<<"2.PLAYER VS PLAYER !!!"<<endl;
     cout<<"Please Select One Game Mode (Enter 1 or 2 ): "<<endl;
     cin>>mode;
     if(mode==1)
     computer_vs_player();
     else if(mode==2)
     player_vs_player();
    else
    cout<<"PLEASE SELECT VALID MODE!!!!!";
     return 0;
 }

 void computer_vs_player()
 {
      string playername;
      cout<<" Enter Your Name : ";
      cin>>playername;
      while (true )
      {
          system("cls");
          show_board();
          if(count_board('X')==count_board('O'))
          {
              cout<<playername <<"'s Turn."<<endl;
              get_x();
          }
          else{
              get_computer_choice();
              char winner=check_winner();
              if(winner=='X')
              {
                  system("cls");
                  show_board();
                  cout<<playername<<" Won The Game."<<endl;
                  break;
              }
              else if(winner=='O')
              {
                  system("cls");
                  show_board();
                  cout<<"Computer Won The Game ."<<endl;
                  break;
              }
              else if(winner=='D')
              {
                  cout<<"Game is Draw ."<<endl;
                  break;
              }
          }
      }
      
      
 }

 void player_vs_player()
 {
     string x,o;
     cout<<"Enter X Player Name : ";
     cin>>x;
     cout<<"Enter O Player Name : ";
     cin>>o;
     while(true)
     {
         system("cls");
         show_board();
         if(count_board('X')==count_board('O')){
             cout<<x<<"'s turn ."<<endl;
             get_x();
         }
         else{
             cout<<o<<"'s turn."<<endl;
             get_o();
         }

         char winner = check_winner();
         if(winner== 'X')
         {
             system("cls");
             show_board();
             cout<<x<<" Won The Game ."<<endl;
             break;
         }
         else if ( winner=='O')
         {
             system("cls");
             show_board();
             cout<<o<<" Won The Game ."<<endl;
             break;
         }
         else if(winner=='D')
         {
             cout<<"Game is Draw .";
             break;
         }
     }
 }

 void get_computer_choice()
 {
     srand(time(0));
     int choice;
     do
     {
        choice = rand()%10;
     } while (board[choice]!=' ');
     board[choice] = 'O';
     
 }

 void get_x(){
     while ((true))
     {
         cout<<"Select Your Position(1-9):";
         int choice;
         cin>>choice;
         choice--;
         if(choice<0 or choice>8)
         cout<<"Please Select Your Choice From (1-9)"<<endl;
         else if(board[choice] != ' '){
             cout<<"Please Select The Empty Position."<<endl;
         }
         else
         {
             board[choice]='X';
             break;
         }
         /* code */
     }
     
 }

 int count_board(char symbol)
 {
     int total=0;
     for(int i=0;i<9;i++)
     {
         if(board[i]== symbol)
         total+=1;
     }
     return total;
 }

 char check_winner()
 {
     if(board[0]==board[1] and board[1]==board[2] && board[0]!= ' ')
     return board[0];
    if(board[3]==board[4] and board[4]==board[5] && board[3]!= ' ')
     return board[3];
     if(board[5]==board[6] and board[6]==board[7] && board[6]!= ' ')
     return board[6];

     if(board[0]==board[3] and board[3]==board[6] && board[0]!= ' ')
     return board[0];
     if(board[1]==board[4] and board[4]==board[7] && board[1]!= ' ')
     return board[1];
     if(board[2]==board[5] and board[5]==board[8] && board[2]!= ' ')
     return board[2];  

     if(board[0]==board[4] and board[4]==board[8] && board[0]!= ' ')
     return board[0];
     if(board[2]==board[4] and board[4]==board[6] && board[2]!= ' ')
     return board[2];
     if(count_board('X')+count_board('O') < 9 )
     return 'C';
     else
     return 'D';
     
 }

void get_o(){
     while ((true))
     {
         cout<<"Select Your Position(1-9):";
         int choice;
         cin>>choice;
         choice--;
         if(choice<0 or choice>8)
         cout<<"Please Select Your Choice From (1-9)"<<endl;
         else if(board[choice] != ' '){
             cout<<"Please Select The Empty Position."<<endl;
         }
         else
         {
             board[choice]='O';
             break;
         }
         /* code */
     }

}
 void show_board()
 {
     cout<<"   "<<"    |   "<<"    |   "<<endl;
     cout<<"   "<<board[0]<<"   |   "<<board[1]<<"   |   "<<board[2]<<endl;
      cout<<"   "<<"    |   "<<"    |   "<<endl;
     cout<<"----------------------"<<endl;
     cout<<"   "<<"    |   "<<"    |   "<<endl;
     cout<<"   "<<board[3]<<"   |   "<<board[4]<<"   |   "<<board[5]<<endl;
      cout<<"   "<<"    |   "<<"    |   "<<endl;
     cout<<"----------------------"<<endl;
     cout<<"   "<<"    |   "<<"    |   "<<endl;
     cout<<"   "<<board[6]<<"   |   "<<board[7]<<"   |   "<<board[8]<<endl;
      cout<<"   "<<"    |   "<<"    |   "<<endl;
     
 }