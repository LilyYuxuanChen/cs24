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

  std::string line;
  std::getline(std::cin, line);
  Board board;
while (cin) {
 try {
	
	  Move move(line);
	  //Board board;
	  board.makeMove(move);

	  if(board.isGameOver()){ 
		  
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
}
