// Copyright (c) 2017-2018 The Cryptathlos developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "CryptAthlosBasic.h"
#include "crypto/crypto.h"

namespace CryptAthlos {

KeyPair generateKeyPair() {
  KeyPair k;
  Crypto::generate_keys(k.publicKey, k.secretKey);
  return k;
}

}
