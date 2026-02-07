#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

#include <configuration.h>
#include <warnings.h>

namespace fs = std::filesystem;

io::Configuration::Configuration(int argc, char *argv[]) {

  // parse cmdline args.
  parse_args(argc, argv);

  // create casename, paths from argv
  fs::path input_path_rel(input_file_string);
  input_path_abs = fs::absolute(input_path_rel);
  case_name = input_path_abs.stem().string();

  // unpack contents of input vector
  std::ifstream input_file(input_path_rel.string());
  if (!input_file.is_open()) {
    throw std::runtime_error("Could not find input file at " +
                             input_path_abs.string());
  }
  std::string line;
  std::string word;
  int line_no = -1;
  while (std::getline(input_file, line)) {
    line_no++;
    input_rows.push_back(line);
    std::stringstream line_stream(line);

    // TODO: trim after # and before :
    while (line_stream >> word) {
      input_flat.push_back(word);
      input_line_nos.push_back(line_no);
    }
  }

  // DEBUG
  for (auto i : input_flat) {
    std::cout << i << std::endl;
  }
  debug_msg("Config. object constructed");
}

void io::Configuration::parse_args(int argc, char *argv[]) {

  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];

    if (arg == "-v" || arg == "--verbose") {
      verbose = 1;
      debug_msg("Verbose execution mode");
    } else if (arg == "-s" || arg == "--silent") {
      silent = 1;
    } else if (arg == "-i" || arg == "--input") {
      if (i + 1 >= argc) {
        throw std::runtime_error("Missing filename after -i/--input");
      }
      input_file_string = argv[++i]; // advance and capture next argument
    } else {
      throw std::runtime_error("Unknown argument " + arg);
    }
  }
}

void io::Configuration::cleanup() {}
