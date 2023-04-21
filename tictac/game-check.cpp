#include "Board.h"
#include "Errors.h"
#include "Move.h"

int main(int argc, char** argv) {
  bool verbose = false;

  if(argc == 2 && std::string(argv[1]) == "-v") {
    verbose = true;
  }

  if(verbose) {
    std::cout << "> ";
  }

  std::string line;
  std::getline(std::cin, line);

  try {
    //Move move(line);
   // std::cout << move << '\n';
    return 0;
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
