// #include <vector>
// #include <string>
#include <iostream>
// #include <chrono>

#include <configuration.h>
#include <parameters.h>
#include <sn.h>
#include <warnings.h>



int main(int argc, char* argv[]){

    io::Configuration rundata(argc, argv);


    // debug_msg("rundata initialized in main()");

    transport::Parameters problem_data(rundata);
    transport::solve(rundata, problem_data);

    rundata.cleanup();

}