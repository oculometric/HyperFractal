#include <iostream>
#include <chrono>

/**
 * Naming Convention:
 * Classes & Structs - CapitalisedCamelCase
 * Variables - snake_case
 * Functions - uncapitalisedCamelCase
 * Constants - ALL_CAPS_SNAKE_CASE
 * 
 **/


#include "hyperfractal.hh"
#include "gui.hh"

int main (int argc, char *argv[]) {
    if (argc == 8) {
        HFractalMain hm;
        hm.resolution = std::stoi (argv[1]);
        hm.offset_x = std::stod (argv[2]);
        hm.offset_y = std::stod (argv[3]);
        hm.zoom = std::stod (argv[4]);
        hm.eq = std::string (argv[5]);
        hm.worker_threads = std::stoi (argv[6]);
        hm.eval_limit = std::stoi (argv[7]);
        hm.generateImage(true);
        return hm.write ("out.pgm");
    } else if (argc != 1) {
        std::cout << "Provide all the correct arguments please:" << std::endl;
        std::cout << "int resolution, long double offset_x, long double offset_y, long double zoom, string HFractalEquation, int worker_threads, int eval_limit" << std::endl;
        return 1;
    } else {
        return guiMain ();
    }
}

// int main(int argc, const char** argv) {
//     // For database module testing
//     return 0;
// }