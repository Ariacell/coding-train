#include <fstream>
#include <raylib.h>
#include <string>
#include <vector>
#include <iosfwd>
#include <iostream>
#include <filesystem>
#include <algorithm>
/*
Tracking tool for checking which areas I visit in PoE using fstream as a learning experience
*/

static int last_position=0;
int find_new_text(std::ifstream &infile, std::vector<std::string>& initialLines) {

   infile.seekg(0,std::ios::end);
   int filesize = infile.tellg();

   // check if the new file started
   if(filesize < last_position){
      last_position=0;
   }  
   // read file from last position  untill new line is found 

   for(int n=last_position;n<filesize;n++) {

      infile.seekg( last_position,std::ios::beg);
      char  test[256]; 
      infile.getline(test, 256);
      last_position = infile.tellg();
      std::cout << "Char: "  << test <<"Last position " << last_position<<  std::endl;
      std::rotate(initialLines.begin(), initialLines.begin() + 1, initialLines.end());
      initialLines[initialLines.size()-1] = test;
      // end of file 
      if(filesize == last_position){
        return filesize;
      } 

  }

  return 0;
}

std::vector<std::string> TailN(int numLinesToTail, std::ifstream& fileHandle, std::string recoveryPath) {
    std::vector<std::string> trackedLines = {};

    // if (!std::filesystem::exists(recoveryPath)) {
    //     return trackedLines; // file temporarily missing
    // }


    // if (!fileHandle.is_open()) {
    //     fileHandle.close();
    //     fileHandle.open(recoveryPath);

    //     if (!fileHandle.is_open()) {
    //         std::cerr << "Failed to reopen file\n";
    //         return trackedLines;
    //     }
    // }

    fileHandle.seekg(-1, std::ios::end);
    if (fileHandle.fail()) {
        std::cout << "File failed to open" << std::endl;
    }
    std::string curLine = "";
    int filepos = fileHandle.tellg();
    last_position = filepos;
    for (int i = filepos - 1; i >= 0 && trackedLines.size() < numLinesToTail; --i) {
        fileHandle.seekg(i);
        char c;
        fileHandle.get(c);

        if (c == '\n') {
            if (!curLine.empty()) {
                trackedLines.push_back(curLine);
                curLine.clear();
            }
        } else {
            curLine.insert(curLine.begin(), c);
        }

        if (i == 0) break;
    }

    if (!curLine.empty() && trackedLines.size() < numLinesToTail) {
        trackedLines.push_back(curLine);
    }
    return trackedLines;
} 

int main() {

    std::string path = "/mnt/s/Grinding Gear Games/Path of Exile/logs/Client.txt";
    std::ifstream file(path);
    auto initialLines = TailN(10,file, path);
    file.close();

    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        std::string path = "/mnt/s/Grinding Gear Games/Path of Exile/logs/Client.txt";
        std::ifstream file(path);
        initialLines = TailN(10, file, path);
        file.close();
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            int index = 0;
            for (auto line : initialLines) {
                DrawText(line.c_str(), 10, 200+10*index, 10, LIGHTGRAY);
                index++;
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

