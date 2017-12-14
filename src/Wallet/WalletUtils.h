// Copyright (c) 2017-2018 The Cryptathlos developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <string>

#include "CryptAthlosCore/Currency.h"

namespace CryptAthlos {

bool validateAddress(const std::string& address, const CryptAthlos::Currency& currency);

}
