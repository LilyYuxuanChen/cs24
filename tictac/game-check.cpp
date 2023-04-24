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

  cout << "Game in progress: New game." << endl;
//Board board;
// while(cin){
  std::string line;
  std::getline(std::cin, line);
  Board board;
while (cin) {
 try {
	
	  Move move(line);
	  //Board board;
	  board.makeMove(move);
	  //cout << "finished move" << endl;

	  if(board.isGameOver()){ 
		 //cout << "gameover" << endl; 
		  break;
	  }

	  getline(cin, line);
	  Move move2(line);
	  board.makeMove(move2);
	  //cout << "finished second move" << endl;
	  if(board.isGameOver()){
		  break;
	  }
	  
	  getline(cin, line);
	  Move move3(line);
	  board.makeMove(move3);
	  if (board.isGameOver()) {
		  break;
	  }

	  getline(cin, line);
	  Move move4(line);
	  board.makeMove(move4);
	  if (board.isGameOver()) {
		  break;
	  }

	  getline(cin, line);
	  Move move5(line);
	  board.makeMove(move5);
	  if (board.isGameOver()) {
		  break;
	  }

	  getline(cin, line);
	  Move move6(line);
	  board.makeMove(move6);
	  if (board.isGameOver()) {
		  break;
	  }



		  

		  
    
    return 0;
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
return 0;
}
