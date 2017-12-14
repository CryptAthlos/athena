// Copyright (c) 2017-2018 The Cryptathlos developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <string>
#include <ostream>

namespace CryptAthlos {

void importLegacyKeys(const std::string& legacyKeysFilename, const std::string& password, std::ostream& destination);

} //namespace CryptAthlos
