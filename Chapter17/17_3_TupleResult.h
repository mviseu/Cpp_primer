#pragma once

#include "17_3_StrBlob.h"
#include <memory>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <tuple>


using Result = std::tuple<std::string, StrBlob, std::shared_ptr<std::set<size_t>>>;
using SetIter = std::set<size_t>::iterator;

std::ostream &print(std::ostream &os, const Result &qr);


SetIter begin(const Result &res);

SetIter end(const Result &res);

std::shared_ptr<StrBlob> get_file(const Result &res);