// Copyright (c) 2017-2018 The Cryptathlos developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include <cstdint>

#include "CryptAthlosProtocol/ICryptAthlosProtocolObserver.h"
#include "CryptAthlosProtocol/ICryptAthlosProtocolQuery.h"

class ICryptAthlosProtocolQueryStub: public CryptAthlos::ICryptAthlosProtocolQuery {
public:
  ICryptAthlosProtocolQueryStub() : peers(0), observedHeight(0), synchronized(false) {}

  virtual bool addObserver(CryptAthlos::ICryptAthlosProtocolObserver* observer) override;
  virtual bool removeObserver(CryptAthlos::ICryptAthlosProtocolObserver* observer) override;
  virtual uint32_t getObservedHeight() const override;
  virtual size_t getPeerCount() const override;
  virtual bool isSynchronized() const override;

  void setPeerCount(uint32_t count);
  void setObservedHeight(uint32_t height);

  void setSynchronizedStatus(bool status);

private:
  size_t peers;
  uint32_t observedHeight;

  bool synchronized;
};
