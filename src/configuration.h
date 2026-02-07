#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <filesystem>
#include <string>
#include <vector>

namespace io {

class Configuration {
public:
  Configuration(int argc, char *argv[]);

  void cleanup();

private:
  // input file and contents
  std::string input_file_string;

  std::filesystem::path input_path_abs;
  std::filesystem::path input_path_rel;

  std::string case_name;

  std::vector<std::string> input_rows;
  std::vector<std::string> input_flat;
  std::vector<int> input_line_nos;

  // run parameters
  bool verbose = 0;
  bool silent = 0;

  // input data LATER

  void parse_args(int argc, char *argv[]);
};

} // namespace io

#endif