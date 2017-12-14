// Copyright (c) 2017-2018 The Cryptathlos developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "IWallet.h"
#include "INode.h"
#include <System/Dispatcher.h>

#include <string>
#include <memory>

namespace CryptAthlos {
class Currency;
}

namespace PaymentService {

class WalletFactory {
public:
  static CryptAthlos::IWallet* createWallet(const CryptAthlos::Currency& currency, CryptAthlos::INode& node, System::Dispatcher& dispatcher);
private:
  WalletFactory();
  ~WalletFactory();

  static WalletFactory factory;
};

} //namespace PaymentService
