#include "Game.h"

int main(int argc, char* argv[]){

    srand(time(NULL));

    int iterations = 0;
    bool verbosity = false;

     // Loop through command line arguments
    for (int i = 1; i < argc; i++) {
        // Check if the argument starts with '-'
        if (argv[i][0] == '-') {
            // Parse the option and get the corresponding value
            switch (argv[i][1]) {
                case 'i':
                    // Check if the next argument exists and is a valid integer
                    if (i + 1 < argc) {
                        iterations = std::atoi(argv[i + 1]);
                        i++; // Skip the next argument, as it is the value for '-i'
                    } else {
                        std::cerr << "Error: Missing value for '-i' option." << std::endl;
                        return 1; // Return error code
                    }
                    break;
                case 'v':
                    // Set verbosity true
                    verbosity = true;
                    break;
                default:
                    std::cerr << "Error: Unknown option '" << argv[i] << "'." << std::endl;
                    return 1;
            }
        } else {
            std::cerr << "Error: Invalid argument '" << argv[i] << "'." << std::endl;
            return 1;
        }
    }

    std::cout << "Iterations: " << iterations << std::endl;
    std::cout << "Verbosity: " << (verbosity ? "True" : "False") << std::endl;

    Game rouletteSim;

    if (iterations) {
        rouletteSim.setIterations(iterations);
    }

    if (verbosity) {
        rouletteSim.setVerbosity(verbosity);
    }

    rouletteSim.start();

    return 0;
}
