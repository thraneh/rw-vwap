/* Copyright (c) 2017-2022, Hans Erik Thrane */

#include "roq/api.hpp"

#include "rw/vwap/application.hpp"

using namespace std::literals;

namespace {
auto const DESCRIPTION = "RW VWAP"sv;
}  // namespace

int main(int argc, char **argv) {
  return rw::vwap::Application(
             argc,
             argv,
             {
                 .description = DESCRIPTION,
                 .package_name = ROQ_PACKAGE_NAME,
                 .build_version = ROQ_VERSION,
             })
      .run();
}
