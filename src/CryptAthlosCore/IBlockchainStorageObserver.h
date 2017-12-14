// Copyright (c) 2017-2018 The Cryptathlos developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#pragma once

namespace CryptAthlos {
  class IBlockchainStorageObserver {
  public:
    virtual ~IBlockchainStorageObserver() {
    }

    virtual void blockchainUpdated() = 0;
  };
}
