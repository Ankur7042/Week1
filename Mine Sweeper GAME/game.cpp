#include<bits/stdc++.h>
using namespace std;

//MARK:-  Function to check whether input is a number or not
bool isNumber(string s){
 for(int i=0;i<s.size();i++){
        if(isdigit(s[i]) == false) return false; 
    }
    return true;
}

//MARK:-  Function for printing the Game Board
void printingOutput(vector<vector<char>> &gameBoard, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << gameBoard[i][j] << " ";
        }
        cout << endl;
    }
}

//MARK:-  Function for bounds checking
bool isValid(int currRow, int currCol, int rowLast, int colLast) {
    return currRow >= 0 && currCol >= 0 && currRow <= rowLast && currCol <= colLast;
} 



// MARK:- Function to randomly Place the Bombs in the gameboard
void placingBombs(int bombs, int size, vector<vector<char>> &gameBoard) {
    cout<<" All Bombs are Placed"<<endl;
    int bombNumber=1;        // variable to count the current BOmb Number
    while (bombs > 0) {

        int row = rand() % size;
        int col = rand() % size;

        cout << "Position of " <<bombNumber << " bomb = "<< row << " " << col << endl;

//DESCRIPTION:-  if the current position have no Bomb then place a bomb there ,Otherwise choose different position.
        if (gameBoard[row][col] != 'B') {
            gameBoard[row][col] = 'B';
            bombs--;
            bombNumber++;
        }
    }
    cout<<"Game-Board is here"<<endl;
    printingOutput(gameBoard, size);
}




// MARK:- Function for mines input
int minesMethod(int emptySpace) {
     
    int minesGivenByUser; // Variable to store the input of user  i.e number of mines user want to place
    cout << "Please enter the number of mines you have to place: "<<endl;
    cin >> minesGivenByUser;

//  DESCRIPTION :- if the number of  mines that user wants to place is greater than the empty spaces in the gameboard then
// user have to give input again and again
    while(minesGivenByUser > emptySpace){
        cout<<"Not enough Vacant Spaces! Please Enter again "<<endl; 
        cin >> minesGivenByUser;

    }
    return minesGivenByUser;
}



// MARK:- Check whether user will win or not
//DESCRIPTION :- if all the mines are placed on the safe places then user will win otherwise user will lose.
void winOrLose(vector<vector<char>> &gameBoard, int minesGivenByUser, int size) {
    while (minesGivenByUser > 0) {
        cout << "Enter the row index where you have to place the mine: ";
        string Row, Col;
        cin >> Row;

        cout << "Enter the column index where you have to place the mine: ";
        cin >> Col;

//DESCRIPTION:- Checking whether the input row and cols are Number or not . if they are not number then we will 
//take input again
      if(!(isNumber(Row) && isNumber(Col))){
        cout<<"Invalid Input , choose again!"<<endl;
        continue;
      } 

  // stoi converts string into the Number
       int row=stoi(Row),col=stoi(Col);
       
        if (isValid(row, col, size - 1, size - 1)) {   // checking whether the current coordinates is valid or not

        // DESCRIPTION :- if the current index have no bomb then we will place the mine there and then take the 
        // next coordinate from the user again 
             if (gameBoard[row][col] != 'B') {
                gameBoard[row][col] = 'M';
                minesGivenByUser--;
            } else {

        // Mine is placed on bomb , means user lost.
                cout << "OOPS!, You put mine above bomb." << endl;
                printingOutput(gameBoard, size);
                cout<<"YOU LOST! Better Luck Next Time";
                return ;
            }
        }
        else{
            cout<<"Invalid Position , Choose again"<<endl;
        }
    }

    cout << "All mines are placed in safe places. YOU WON!" << endl;
     printingOutput(gameBoard, size); 
}


int main(){
    string boardsize;
    cout<<"Enter the size of the (size*size) game board"<<endl;
    cin>>boardsize;

//  MARK:- checking whether boardsize is a number or not , if it is not a number then game will end.
    if( !isNumber(boardsize)){
        cout<<"Invalid Input ,Game Ended !"<<endl;
        return 0;
    }
    
    // converting string to integer 
    int boardSize=stoi(boardsize);

// MARK :- checking for Memory leak 
    if((boardSize<0 || boardSize>1000)){
        cout<<"Not Enough space to create a gameBoard ,Game Ended !"<<endl;
        return 0;
    }
    
    vector<vector<char>> gameBoard(boardSize,vector<char>(boardSize,'.'));

    int bombs= boardSize;  // Number of bombs that will place on gameBoard
    int emptySpace = (boardSize*boardSize)- bombs;  // Empty space to put mines

     placingBombs(bombs, boardSize, gameBoard); // Randomly placing bombs on the gameBoard

    int minesGivenByUser = minesMethod(emptySpace); // number of mines user wants to Place

    winOrLose(gameBoard, minesGivenByUser, boardSize); // Check if the user placed mines on safe places

    return 0;

}