// Copyright (c) 2017-2018 The Cryptathlos developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

#include "CryptAthlosCore/Account.h"
#include "CryptAthlosCore/CryptAthlosBasic.h"
#include "CryptAthlosCore/CryptAthlosFormatUtils.h"

#include <Logging/LoggerGroup.h>

class single_tx_test_base
{
public:
  bool init()
  {
    using namespace CryptAthlos;

    Currency currency = CurrencyBuilder(m_nullLog).currency();
    m_bob.generate();

    if (!currency.constructMinerTx(0, 0, 0, 2, 0, m_bob.getAccountKeys().address, m_tx))
      return false;

    m_tx_pub_key = getTransactionPublicKeyFromExtra(m_tx.extra);
    return true;
  }

protected:

  Logging::LoggerGroup m_nullLog;
  CryptAthlos::AccountBase m_bob;
  CryptAthlos::Transaction m_tx;
  Crypto::PublicKey m_tx_pub_key;
};
