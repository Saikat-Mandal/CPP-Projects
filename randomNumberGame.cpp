#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void play()
{
    int random;
    srand(time(0));
    random = 1 + (rand() % 100);
    int count = 0;
while(true){
    int guess;
    cout<<"Guess a number between 1 to 100 .. "<<endl;
    cin>>guess;

    if(guess > random){
        cout<<"too high !!"<<endl;
        count++;
    }
    else if(guess < random){
        cout<<"too low !!"<<endl;
        count++;
    }
    else{
        cout<<"wow you found the number !! "<<random<<" == "<<guess<<endl;
        cout<<"you have guessed the number in : "<<count<<" attempts .";
        break;
    }
    
}

    
}
int main()
{   
    play();
    return 0;
}