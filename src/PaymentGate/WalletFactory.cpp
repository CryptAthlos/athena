// Copyright (c) 2017-2018 The Cryptathlos developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "WalletFactory.h"

#include "NodeRpcProxy/NodeRpcProxy.h"
#include "Wallet/WalletGreen.h"
#include "CryptAthlosCore/Currency.h"

#include <stdlib.h>
#include <future>

namespace PaymentService {

WalletFactory WalletFactory::factory;

WalletFactory::WalletFactory() {
}

WalletFactory::~WalletFactory() {
}

CryptAthlos::IWallet* WalletFactory::createWallet(const CryptAthlos::Currency& currency, CryptAthlos::INode& node, System::Dispatcher& dispatcher) {
  CryptAthlos::IWallet* wallet = new CryptAthlos::WalletGreen(dispatcher, currency, node);
  return wallet;
}

}
