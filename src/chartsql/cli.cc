/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2011-2014 Paul Asmuth, Google Inc.
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stx/exceptionhandler.h>
#include <stx/random.h>
#include <fnordmetric/environment.h>
#include <cli/cli.h>

using namespace stxmetric;

static const char kCrashErrorMsg[] =
    "FnordMetric crashed :( -- Please report a bug at "
    "github.com/paulasmuth/fnordmetric";

int main(int argc, const char** argv) {
  stx::Application::init();
  stx::Application::logToStderr();

  cli::CLI::parseArgs(env(), argc, argv);
  cli::CLI::executeSafely(env());
  return 0;
}

