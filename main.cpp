#include "Services/GenerateService.h"
#include "Tasks/TaskQueue.h"
#include "Tasks/Executor.h"
#include "Utility/Parser.h"
#include <iostream>

int main(int argc, char **argv) {

  Parser cliParser;
  cliParser.addService<GenerateService>("generate");
  cliParser.parse(argc, argv);
  cliParser.run();
}
