#include "Services/GenerateService.h"
#include "Utility/TaskQueue.h"
#include "Utility/Executor.h"
#include "Utility/Parser.h"
#include <iostream>

int main(int argc, char **argv) {

  TaskQueue queue;
  Executor ex1(queue);

  ex1.start();

  Parser cliParser;
  cliParser.addService<GenerateService>("generate");
  cliParser.parse(argc, argv);
  cliParser.run();

  ex1.stop();

}
