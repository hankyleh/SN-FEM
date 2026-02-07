#ifndef CONFIGURATION_H
#define CONFIGURATION_H
namespace io {

class Configuration {
public:
  Configuration(int argc, char* argv[]);

  void cleanup();

private:
};

} // namespace io

#endif