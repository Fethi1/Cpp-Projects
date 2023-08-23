#include<iostream>

int main(void)
{
    std:: string p1,p2;
    std::cout<<"WELCOME TO ROCK-PAPER-SCISSORS GAME !!"<<std::endl;
    std::cout<<"* ---------------------------------------------------------- * \n";
    std:: cout<<"Pick your Choice !!"<<"\n";
    std::cin >> p1;
    system("cls");
    std:: cout<<"Pick your Choice!!"<<"\n";
    std::cin >> p2;
    system("cls");
if(p1 == p2)
      std::cout<< "Draw!";
    if( ( p1[0] == 's' && p2[0] == 'p' )||
        ( p1[0] == 'p' && p2[0] == 'r' )||
        ( p1[0] == 'r' && p2[0] == 's' ) )
        std::cout << "Player 1 won!";
     else std::cout << "Player 2 won!";
    std::cout<<"\n \n \n";

}
