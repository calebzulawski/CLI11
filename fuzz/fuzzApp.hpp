// Copyright (c) 2017-2023, University of Cincinnati, developed by Henry Schreiner
// under NSF AWARD 1414736 and by the respective contributors.
// All rights reserved.
//
// SPDX-License-Identifier: BSD-3-Clause
#pragma once

#ifdef CLI11_SINGLE_FILE
#include "CLI11.hpp"
#else
#include "CLI/CLI.hpp"
#endif

#include <atomic>
#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace CLI {

class intWrapper64 {
  public:
    intWrapper64() = default;
    explicit intWrapper64(int64_t v) : val(v){};
    CLI11_NODISCARD int64_t value() const { return val; }

  private:
    int64_t val{0};
};

class doubleWrapper {
  public:
    doubleWrapper() = default;
    explicit doubleWrapper(double v) : val(v){};
    CLI11_NODISCARD double value() const { return val; }

  private:
    double val{0.0};
};

class FuzzApp {
  public:
    FuzzApp() = default;

    std::shared_ptr<CLI::App> generateApp();

    int32_t val32{0};
    int16_t val16{0};
    int8_t val8{0};
    int64_t val64{0};

    uint32_t uval32{0};
    uint16_t uval16{0};
    uint8_t uval8{0};
    uint64_t uval64{0};

    std::atomic<int64_t> atomicval64{0};
    std::atomic<uint64_t> atomicuval64{0};

    double v1{0};
    float v2{0};

    std::vector<double> vv1{};
    std::vector<std::string> vstr{};
    std::vector<std::vector<double>> vecvecd{};
    std::vector<std::vector<std::string>> vvs{};
    std::optional<double> od1{};
    std::optional<std::string> ods{};
    std::pair<double, std::string> p1{};
    std::pair<std::vector<double>, std::string> p2{};
    std::tuple<int64_t, uint16_t, std::optional<double>> t1{};
    std::tuple<std::tuple<std::tuple<std::string, double, std::vector<int>>, std::string, double>,
               std::vector<int>,
               std::optional<std::string>>
        tcomplex{};
    std::tuple<std::tuple<std::tuple<std::string, double, std::vector<int>>, std::string, double>,
               std::vector<int>,
               std::optional<std::string>>
        tcomplex2{};
    std::string_view vstrv = "";

    bool flag1{false};
    int flagCnt{0};
    std::atomic<bool> flagAtomic{false};

    intWrapper64 iwrap{0};
    doubleWrapper dwrap{0.0};
};
}  // namespace CLI
