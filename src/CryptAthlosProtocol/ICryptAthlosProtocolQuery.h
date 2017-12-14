// Copyright (c) 2017-2018 The Cryptathlos developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstddef>
#include <cstdint>

namespace CryptAthlos {
class ICryptAthlosProtocolObserver;

class ICryptAthlosProtocolQuery {
public:
  virtual bool addObserver(ICryptAthlosProtocolObserver* observer) = 0;
  virtual bool removeObserver(ICryptAthlosProtocolObserver* observer) = 0;

  virtual uint32_t getObservedHeight() const = 0;
  virtual size_t getPeerCount() const = 0;
  virtual bool isSynchronized() const = 0;
};

} //namespace CryptAthlos
