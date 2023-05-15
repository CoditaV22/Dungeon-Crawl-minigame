#include <iostream>
#include <stdlib.h>
#include <ctime>

int main()
{
    std::cout<<"Board creating...."<<std::endl;
    srand((int)time(0));

    char Board[7][10];
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<10; j++)
            Board[i][j]='.';
    }


    int player_i,player_j;
    player_i=rand() % 7;
    player_j=rand() % 10;
    int trap_i,trap_j;
    Board[player_i][player_j]='P';
    Board[6][9]='X';
    int nr_traps;
    int enemy_i,enemy_j;
    nr_traps= rand() %4 +1;
    for(int i=0; i<nr_traps; i++)
    {
        int key=1;
        do
        {
            trap_i=rand() % 7;
            trap_j=rand() % 10;
            if(Board[trap_i][trap_j]=='.')
            {
                Board[trap_i][trap_j]='T';
                key=0;
            }
        }
        while(key);
    }

    int key2=1;

    do
    {
        enemy_i=rand() % 7;
        enemy_j=rand() % 10;
        if(Board[enemy_i][enemy_j]=='.')
        {
            Board[enemy_i][enemy_j]='E';
            key2=0;
        }
    }
    while(key2);



    std::cout<<std::endl<<"Board created: "<< std::endl;
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<10; j++)
            std::cout<<Board[i][j]<<" ";
        std::cout<<std::endl;
    }







    char k;
    int winner=0;
    do
    {
        char move_player;
start:
        std::cin>>move_player;
        if(move_player=='d' && player_j==9)
        {
            std::cout<<"You cannot move out of bounds!!!!!"<<std::endl;
            std::cout<<"Please enter a new command"<<std::endl;
            goto start;
        }
        if(move_player=='s' && player_j==0)
        {
            std::cout<<"You cannot move out of bounds!!!!!"<<std::endl;
            std::cout<<"Please enter a new command"<<std::endl;
            goto start;
        }
        if(move_player=='u' && player_i==0)
        {
            std::cout<<"You cannot move out of bounds!!!!!"<<std::endl;
            std::cout<<"Please enter a new command"<<std::endl;
            goto start;
        }

        if(move_player=='v' && player_i==6)
        {
            std::cout<<"You cannot move out of bounds!!!!!"<<std::endl;
            std::cout<<"Please enter a new command"<<std::endl;
            goto start;
        }

        if(move_player=='d')
        {
            Board[player_i][player_j]='.';
            k=Board[player_i][player_j+1];
            Board[player_i][player_j+1]='P';
            if(k=='X')
            {
                winner=1;
                break;
            }
            if(k=='T' || k=='E')
            {
                winner=2;
                break;
            }
            player_j++;
        }
        if(move_player=='s')
        {
            Board[player_i][player_j]='.';
            k=Board[player_i][player_j];
            if(k=='X')
            {
                winner=1;
                break;
            }
            if(k=='T' || k=='E')
            {
                winner=2;
                break;
            }
            Board[player_i][player_j-1]='P';
            player_j--;
        }
        if(move_player=='u')
        {
            Board[player_i][player_j]='.';
            k=Board[player_i-1][player_j];
            if(k=='X')
            {
                winner=1;
                break;
            }
            if(k=='T' || k=='E')
            {
                winner=2;
                break;
            }
            Board[player_i-1][player_j]='P';
            player_i--;
        }
        if(move_player=='v')
        {
            Board[player_i][player_j]='.';
            char k=Board[player_i+1][player_j];
            if(k=='X')
            {
                winner=1;
                break;
            }
            if(k=='T' || k=='E')
            {
                winner=2;
                break;
            }
            Board[player_i+1][player_j]='P';
            player_i++;
        }
        int move_enemy;
kill:
        move_enemy=rand() % 4;
        if(move_enemy==0 && player_j==9)
        {
            goto kill;
        }
        if(move_enemy==1 && player_j==0)
        {
            goto kill;
        }
        if(move_enemy==2 && player_i==0)
        {
            goto kill;
        }

        if(move_enemy==3 && player_i==6)
        {
            goto kill;
        }

        if(move_enemy==0)
        {
            Board[enemy_i][enemy_j]='.';
            k=Board[enemy_i][enemy_j+1];
            Board[enemy_i][enemy_j+1]='E';
            if(k=='X')
            {
                winner=2;
                break;
            }
            if(k=='P')
            {
                winner=2;
                break;
            }
            enemy_j++;
        }
        if(move_enemy==1)
        {
            Board[enemy_i][enemy_j]='.';
            k=Board[enemy_i][enemy_j-1];
            Board[enemy_i][enemy_j-1]='E';

            if(k=='X')
            {
                winner=2;
                break;
            }
            if(k=='P')
            {
                winner=2;
                break;
            }
            enemy_j--;
        }
        if(move_enemy==2)
        {
            Board[enemy_i][enemy_j]='.';
            k=Board[enemy_i-1][enemy_j];
            Board[enemy_i-1][enemy_j]='E';
            if(k=='X')
            {
                winner=2;
                break;
            }
            if(k=='P')
            {
                winner=2;
                break;
            }
            enemy_i--;
        }
        if(move_enemy==3)
        {
            Board[enemy_i][enemy_j]='.';
            k=Board[enemy_i+1][enemy_j];
            Board[enemy_i+1][enemy_j]='E';
            if(k=='X')
            {
                winner=2;
                break;
            }
            if(k=='P')
            {
                winner=2;
                break;
            }
            enemy_i++;
        }


        for(int i=0; i<7; i++)
        {
            for(int j=0; j<10; j++)
                std::cout<<Board[i][j]<<" ";
            std::cout<<std::endl;
        }
    }
    while(winner==0);









//Rezultat
    if(winner==1)
        std::cout<<"Felicitari, ai castigat!!"<<std::endl;
    if(winner==2)
        std::cout<<"Ai pierdut!"<<std::endl;




//Afisare Placa
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<10; j++)
            std::cout<<Board[i][j]<<" ";
        std::cout<<std::endl;
    }
    return 0;
}
