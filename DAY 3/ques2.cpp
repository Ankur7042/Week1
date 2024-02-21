#include<bits/stdc++.h>
using namespace std;
//Time complexity of code-O(1) -- 32 moves for queen, 16 for elephant and camel and 8 for horse so it is approximaytely 
//constant
//space complexity-O(1) - constant as we are not taking any chess board here

int king_x,king_y,horse_x,horse_y,queen_x,queen_y,camel_x,camel_y,elephant_x,elephant_y;

// Function to check whether king is safe from horse or not
bool isSafeFromHorse(int horse_x, int horse_y){

    if(horse_x-2>=0 && horse_y-1>=0 && horse_x==king_x && horse_y==king_y) return false;
    if(horse_x-2>=0 && horse_y+1<8 && horse_x==king_x && horse_y==king_y) return false;
    if(horse_x-1>=0 && horse_y-2>=0 && horse_x==king_x && horse_y==king_y) return false;
    if(horse_x+1<8 && horse_y-2>=0 && horse_x==king_x && horse_y==king_y) return false;
    if(horse_x-1>=0 && horse_y+2<8 && horse_x==king_x && horse_y==king_y) return false;
    if(horse_x+1<8 && horse_y+2>=0 && horse_x==king_x && horse_y==king_y) return false;
    if(horse_x+2<8 && horse_y-1>=0 && horse_x==king_x && horse_y==king_y) return false;
    if(horse_x+2<8 && horse_y+1<8 && horse_x==king_x && horse_y==king_y) return  false;

    return true;
}

// Function to check whether king is safe from camel or not
bool isSafeFromCamel(int camel_x , int camel_y){

    // for upward and left diagonal moves
    int start_x=camel_x-1 , start_y=camel_y-1;
    while(start_x>=0 && start_y>=0){
        if(start_x==king_x && start_y==king_y) return false;
        if(start_x==queen_x && start_y==queen_y) break;
        if(start_x==elephant_x && start_y==elephant_y) break;
        if(start_x==horse_x && start_y==horse_y) break;

        start_x--,start_y--;
    }

    // for upward right diagonal moves
    start_x=camel_x-1 , start_y=camel_y+1;
        while(start_x>=0 && start_y<8){
        if(start_x==king_x && start_y==king_y) return false;
        if(start_x==queen_x && start_y==queen_y) break;
        if(start_x==elephant_x && start_y==elephant_y) break;
        if(start_x==horse_x && start_y==horse_y) break;

        start_x--,start_y++;
    }

    //for downward left diagonal
     start_x=camel_x+1 , start_y=camel_y-1;
        while(start_x<8 && start_y>=0){
        if(start_x==king_x && start_y==king_y) return false;
        if(start_x==queen_x && start_y==queen_y) break;
        if(start_x==elephant_x && start_y==elephant_y) break;
        if(start_x==horse_x && start_y==horse_y) break;

        start_x++,start_y--;
    }

   // for downward right diagonal
        start_x=camel_x+1 , start_y=camel_y+1;
        while(start_x<8 && start_y<8){
        if(start_x==king_x && start_y==king_y) return false;
        if(start_x==queen_x && start_y==queen_y) break;
        if(start_x==elephant_x && start_y==elephant_y) break;
        if(start_x==horse_x && start_y==horse_y) break;

        start_x++,start_y++;
    }
    return true;
}

bool isSafeFromElephant(int elephant_x ,int elephant_y){


    int start_x=elephant_x-1,start_y=elephant_y-1;
    // for upward direction
    while(start_x>=0){
       if(start_x==king_x && start_y==king_y) return false;
       if(start_x==queen_x && start_y==queen_y) break;
       if(start_x==elephant_x && start_y==elephant_y) break;
       if(start_x==horse_x && start_y==horse_y) break; 

       start_x--;
    }

    //for downward direction
    start_x=elephant_x+1;
    while(start_x<8){
       if(start_x==king_x && start_y==king_y) return false;
       if(start_x==queen_x && start_y==queen_y) break;
       if(start_x==elephant_x && start_y==elephant_y) break;
       if(start_x==horse_x && start_y==horse_y) break; 

       start_x++;
    }

    //for left direction
    start_x=elephant_x,start_y=elephant_y-1;
    while(start_y>=0){
       if(start_x==king_x && start_y==king_y) return false;
       if(start_x==queen_x && start_y==queen_y) break;
       if(start_x==elephant_x && start_y==elephant_y) break;
       if(start_x==horse_x && start_y==horse_y) break; 

       start_y--;
    }

    // for right direction
    start_y=elephant_y+1;
        while(start_y<8){
       if(start_x==king_x && start_y==king_y) return false;
       if(start_x==queen_x && start_y==queen_y) break;
       if(start_x==elephant_x && start_y==elephant_y) break;
       if(start_x==horse_x && start_y==horse_y) break; 

       start_y++;
    }

    return true;
}

int main(){
    
    cout<<"Enter position of king"<<endl;
    cin>> king_x >> king_y;
    
     cout<<"Enter position of horse"<<endl;
     cin>> horse_x >> horse_y;

     cout<<"Enter position of queen"<<endl;
     cin>> queen_x >> queen_y;

     cout<<"Enter position of camel"<<endl;
     cin>> camel_x >> camel_y;

     cout<<"Enter position of elephant"<<endl;
     cin>> elephant_x >>elephant_y;

     // checking whether elephant is initially at invalid position or not
     if(elephant_x<0 || elephant_x>=8 || elephant_y<0 || elephant_y>=8) {
     cout<<"Invalid position of Elephant"<<endl;
    }
    else{
        // if position is valid then we will check whether king is safe from elephant or not
        if(isSafeFromElephant(elephant_x ,elephant_y))  cout<<"King is safe from Elephant"<<endl;
     else  cout<<"King is not safe from Elephant"<<endl;
    }

    

// checking whether horse is initially at invalid position or not
    if(horse_x<0 || horse_x>=8 || horse_y<0 || horse_y>=8) {
    cout<<"Invalid position of Horse"<<endl;
}else{
    //if position is valid then we will check whether king is safe from horse or not
     if(isSafeFromHorse(horse_x,horse_y))  cout<<"King is safe from horse"<<endl;
     else  cout<<"King is not safe from horse"<<endl;
}



// checking whether camel is initially at invalid position or not
    if(camel_x<0 || camel_x>=8 || camel_y<0 || camel_y>=8) {
    cout<<"Invalid position of Camel"<<endl;
}
else{
    // if position is valid then we will check whether king is safe from camel or not.
     if(isSafeFromCamel(camel_x ,camel_y))  cout<<"King is safe from Camel"<<endl;
     else cout<<"King is not safe from Camel"<<endl;
}

     


// checking whether queen is initially at invalid position or not.
    if(queen_x<0 || queen_x>=8 || queen_y<0 || queen_y>=8) {
    cout<<"Invalid position of Camel"<<endl;
  }
 else{
  /* in order to check whether  king is safe from the queen or not we have to consider following points
   1.queen take moves of both elephant and camel 
   2. we will pass the coordinates of queen in the isSafeFromElephant() and sSafeFromCamel.
   3. if both functions gives true that means it queen is safe from king otherwise not.*/
     if(isSafeFromElephant(queen_x,queen_y) && isSafeFromCamel(queen_x,queen_y)) cout<<"king is safe from queen"<<endl;
     else cout<<"King is not safe from queen"<<endl;
 }
  
}