/* Copyright (c) 2017-2022, Hans Erik Thrane */

#pragma once

#include <absl/container/node_hash_map.h>

#include <memory>

#include "roq/cache/market_by_price.hpp"
#include "roq/client/event_log_reader.hpp"

namespace rw {
namespace vwap {

struct Processor final : public roq::client::EventLogReader::Handler {
  static void dispatch(std::string_view const &path);

 protected:
  Processor() = default;

  void operator()(roq::Event<roq::GatewaySettings> const &) override {}
  void operator()(roq::Event<roq::StreamStatus> const &) override {}
  void operator()(roq::Event<roq::ExternalLatency> const &) override {}
  void operator()(roq::Event<roq::RateLimitTrigger> const &) override {}
  void operator()(roq::Event<roq::GatewayStatus> const &) override {}
  void operator()(roq::Event<roq::ReferenceData> const &) override {}
  void operator()(roq::Event<roq::MarketStatus> const &) override {}
  void operator()(roq::Event<roq::TopOfBook> const &) override {}
  void operator()(roq::Event<roq::MarketByPriceUpdate> const &) override;
  void operator()(roq::Event<roq::MarketByOrderUpdate> const &) override {}
  void operator()(roq::Event<roq::TradeSummary> const &) override {}
  void operator()(roq::Event<roq::StatisticsUpdate> const &) override {}
  void operator()(roq::Event<roq::CreateOrder> const &) override {}
  void operator()(roq::Event<roq::ModifyOrder> const &) override {}
  void operator()(roq::Event<roq::CancelOrder> const &) override {}
  void operator()(roq::Event<roq::CancelAllOrders> const &) override {}
  void operator()(roq::Event<roq::OrderAck> const &) override {}
  void operator()(roq::Event<roq::OrderUpdate> const &) override {}
  void operator()(roq::Event<roq::TradeUpdate> const &) override {}
  void operator()(roq::Event<roq::PositionUpdate> const &) override {}
  void operator()(roq::Event<roq::FundsUpdate> const &) override {}
  void operator()(roq::Event<roq::CustomMetricsUpdate> const &) override {}
  void operator()(roq::Event<roq::ParameterUpdate> const &) override {}

  template <typename T>
  roq::cache::MarketByPrice &get_market_by_price(const T &);

 private:
  absl::node_hash_map<roq::Symbol, std::unique_ptr<roq::cache::MarketByPrice>> market_by_price_;
};

}  // namespace vwap
}  // namespace rw
