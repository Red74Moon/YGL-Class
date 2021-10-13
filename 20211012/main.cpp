//»ó¼Ó

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Engine.h"
#include "Player.h"
#include "Floor.h"
#include "Wall.h"
#include "Goal.h"

using namespace std;

int main()
{
    string filename("map01.txt");
    vector<string> lines;
    string line;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (getline(input_file, line)) {
        lines.push_back(line);
    }

    for (const auto& i : lines)
        cout << i << endl;

    input_file.close();
    return EXIT_SUCCESS;
}