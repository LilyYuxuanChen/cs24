#include "Board.h"
#include "Errors.h"
#include "Move.h"
using namespace std;
int main(int argc, char** argv) {
  bool verbose = false;

  if(argc == 2 && std::string(argv[1]) == "-v") {
    verbose = true;
  }

  if(verbose) {
    std::cout << "> ";
  }

//  cout << "Game in progress: New game." << endl;
//Board board;
// while(cin){
  std::string line;
  //std::getline(std::cin, line);
  Board board;
  // while(std::getline(std::cin, line)) { ... }
while (getline(cin,line)) {
 try {
	// Board board;
	
	  Move move(line);
	  //Board board;
	  if (!board.isGameOver()) {
	  board.makeMove(move);
	  }
	  else {
		  throw InvalidMove("game already ended");
	  }
	  //cout << "finished move" << endl;

	  /*
	  if(board.isGameOver()){ 
		 //cout << "gameover" << endl; 
		  break;
	  }
	  if(move.player == 'X') {
	  	cout << "Game in progress: O's turn." << endl;
	  }
	  if(move.player == 'O') {
		cout << "Game in progress: X's turn." << endl;
	  }

	  getline(cin, line);
	  Move move2(line);
	  board.makeMove(move2);
	  //cout << "finished second move" << endl;
	  if(board.isGameOver()){
		  break;
	  }
	  if(move2.player == 'X') {
	            cout << "Game in progress: O's turn." << endl;
				          }
	  if(move2.player == 'O') {
	            cout << "Game in progress: X's turn." << endl;
					           } 
	  
	  getline(cin, line);
	  Move move3(line);
	  board.makeMove(move3);
	  if (board.isGameOver()) {
		  break;
	  }
	   if(move3.player == 'X') {
		                   cout << "Game in progress: O's turn." << endl;
				             }
	   if (move3.player == 'O') {
			                     cout << "Game in progress: X's turn." << endl;
					               }

	  getline(cin, line);
	  Move move4(line);
	  board.makeMove(move4);
	  if (board.isGameOver()) {
		  break;
	  }
	  //cout << "Game in progress: " << m_currentPlayer << "'s turn." << endl;
	   if(move4.player == 'X') {
		                   cout << "Game in progress: O's turn." << endl;
				             }
	             else {
			                     cout << "Game in progress: X's turn." << endl;
					               }

	  getline(cin, line);
	  Move move5(line);
	  board.makeMove(move5);
	  if (board.isGameOver()) {
		  break;
	  }
	  //cout << "Game in progress: " << m_currentPlayer << "'s turn." << endl;
	  if(move5.player == 'X') {
		                   cout << "Game in progress: O's turn." << endl;
				             }
	             else {
			                     cout << "Game in progress: X's turn." << endl;
					               }

	  getline(cin, line);
	  Move move6(line);
	  board.makeMove(move6);
	  if (board.isGameOver()) {
		  break;
	  }
	  //cout << "Game in progress: " << m_currentPlayer << "'s turn." << endl;
	   if(move6.player == 'X') {
		                   cout << "Game in progress: O's turn." << endl;
				             }
	             else {
			                     cout << "Game in progress: X's turn." << endl;
					               }
	  getline(cin, line);
	  Move move7(line);
	  board.makeMove(move7);
	  if (board.isGameOver()) {
		   break;
          }
	   if(move7.player == 'X') {
	             cout << "Game in progress: O's turn." << endl;
	   } else {
	              cout << "Game in progress: X's turn." << endl;
										                                                  }


	  getline(cin, line);
	  Move move8(line);
	  board.makeMove(move8);
	  if (board.isGameOver()) {
		  break;
	  }
	  if (move8.player == 'X') {
		  cout << "Game in progress: O's turn." << endl;
	  }
	  else{
		  cout << "Game in progress: X's turn." << endl;
	  
	  }

	  getline(cin, line);
	  Move move9(line);
	  board.makeMove(move9);
	  if(board.isGameOver()) {
		  break;
	  }

		  

		  
    
    return 0;
    */
  }
  catch(const ParseError& e) {
	  if(verbose) {
		  std::cout << "Parse error: " <<e.what() << '\n';
	  
	  }
	  else {
		  std::cout << "Parse error.\n";
	  
	  }
	  return 1;
  }
  catch(const InvalidMove& e) {
    if(verbose) {
      std::cout << "Invalid move: " << e.what() << '\n';
    }
    else {
      std::cout << "Invalid move.\n";
    }

    return 2;
  }

}
/*
if (hasPlayerWon('X')){
	cout << "Game over: X wins." << endl;
}
else if (hasPlayerWon('O')){
	cout << "Game over: O wins." << endl;
}
else if (move.number == 9) {
	cout << "Game over: Draw." << endl;
}
else if (move.player == 'X') {
	cout << "Game in progress: O's turn." << endl;
}
else if (move.player == 'O') {
	cout << "Game in progress: X's turn." << endl;
}
else {
	cout << "Game in progress: New game." << endl;
}
*/

board.PrintGameResult();

return 0;
}
